#include <openssl/aes.h>
#include <openssl/evp.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include<map>
#include <openssl/err.h>

using namespace std;
const char *Hex = "0123456789ABCDEF";

int hex2number(unsigned char x) {
    //把一个hex字符转成数字
    if (x >= '0' && x <= '9') {
        x -= '0';
    } else {
        x -= 'A' - 10;
    }
    return x;
}

string bytes2hex(const unsigned char *s, size_t len) {
    //把一个无符号byte数组转成hex string
    stringstream o;
    for (auto i = 0; i < len; i++) {
        o << Hex[(s[i] >> 4) & 15];
        o << Hex[(s[i] & 15)];
    }
    return o.str();
}

string string2hex(const string &s) {
    //把一个字符串转成hex数组
    return bytes2hex(reinterpret_cast<const unsigned char *>(s.c_str()), s.size());
}

void hex2bytes(const string &s, unsigned char *a) {
    //把一个hex字符串转成byte数组
    size_t sz = s.size() / 2;
    for (auto i = 0; i < sz; i++) {
        a[i] = hex2number(s[i * 2]) << 4 | hex2number(s[i * 2 + 1]);
    }
}

string hex2string(const string &hexString) {
    //把一个hex字符串转成string
    auto o = new unsigned char[hexString.size() / 2]{0};
    hex2bytes(hexString, o);
    string ans((char *) o, hexString.size() / 2);
    delete o;
    return ans;
}

string base64encode(const unsigned char *a, int n) {
    //把一个byte数组进行base64编码
    auto out = new unsigned char[lround(n * 1.5 + 0.5)]{0};
    auto sz = EVP_EncodeBlock(out, a, n);
    string ans((char *) out, sz);
    delete[]out;
    return ans;
}

int base64decode(const string &input, unsigned char *output) {
    //把一个base64字符串进行解码，output需要保证长度够用，返回实际使用了的长度
    int cnt = EVP_DecodeBlock(output, (unsigned char *) input.c_str(), (int) input.size());
    return cnt;
}

string base64encodeString(const string &s) {
    //把一个string进行base64编码
    return base64encode((unsigned char *) s.c_str(), s.size());
}

string base64decodeString(const string &s) {
    //把一个base64字符串进行解码，解码结果一定是一个以\0结尾的字符串
    int targetSize = int(s.size() * 1.5);
    auto a = new unsigned char[targetSize]{0};
    int cnt = base64decode(s, a);
    cnt = min(cnt, (int) strlen((char *) a));
    string ans((char *) a, cnt);
    delete[]a;
    return ans;
}

bool AesEncrypt(const unsigned char k[16], const unsigned char *data, size_t len, unsigned char *out) {
    //对字节数组data（长度为len）进行aes编码，编码结果存储在out里面，out需要保证长度不小于len
    if (len % AES_BLOCK_SIZE != 0) {
        //长度必须是blockSize的整数倍
        return false;
    }
    AES_KEY aes_key;
    auto res = AES_set_encrypt_key(k, 128, &aes_key);
    if (res != 0) {
        return false;
    }
    for (auto i = 0; i < len; i += AES_BLOCK_SIZE) {
        AES_encrypt(data + i, out + i, &aes_key);
    }
    return true;
}

string AesEncryptString(const string &k, const string &data) {
    //把一个字符串编码为一个AES+base64编码之后的字符串，返回一个加密base64字符串
    auto len = (int) ceil((double) data.size() / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    auto input = new unsigned char[len]{0};
    auto o = new unsigned char[len]{0};
    memcpy(input, data.c_str(), data.size());
    unsigned char kk[16] = {0};
    memcpy(kk, k.c_str(), min((int) k.size(), 16));
    AesEncrypt(kk, input, len, o);
    string ans = base64encode(o, len);
    delete[]o;
    delete[] input;
    return ans;
}

bool AesDecrypt(const unsigned char k[16], const unsigned char *data, size_t len, unsigned char *out) {
    //把加密数据data解密到out数组
    if (len % 16 != 0) {
        //长度必须是16的整数倍
        return false;
    }
    AES_KEY aes_key;
    auto res = AES_set_decrypt_key(k, 128, &aes_key);
    if (res != 0) {
        return false;
    }
    for (auto i = 0; i < len; i += AES_BLOCK_SIZE) {
        AES_decrypt(data + i, out + i, &aes_key);
    }
    return true;
}

string AesDecryptString(const string &k, const string &data) {
    //把一个base64加密串解密为一个原始的string
    auto len = (int) ceil((double) data.size() * 3 / 4 / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    auto input = new unsigned char[len]{0};
    //cnt表示解码之后byte数组的长度，需要把这个长度向下取整，因为base64会在末尾追加几个字节
    int paddedSize = base64decode(data, input);
    len = paddedSize / AES_BLOCK_SIZE * AES_BLOCK_SIZE;
    auto output = new unsigned char[len]{0};
    unsigned char kk[16] = {0};
    memcpy(kk, k.c_str(), min((int) k.size(), 16));
    if (!AesDecrypt(kk, input, len, output)) {
        delete[] input;
        delete[]output;
        return "";
    }
    size_t realSize = len;
    if (output[len - 1] == 0) {
        realSize = strlen((char *) output);
    }
    string ans((char *) output, realSize);
    delete[] input;
    delete[]output;
    return ans;
}

void test_hex() {
    string k = "xysdfTYUIH1234z";
    for (auto i: k) {
        cout << int(i) << " ";
    }
    auto one = string2hex(k);
    cout << one << endl;
    cout << hex2string(one) << endl;
}

void test_encrypt() {
    string k = "57jkasdxzk34khHTDFJ3091k";
    string data = "001619cdddd9e93d300c49e5ad4NAB/RwcEig9gYqorYGIBADEDADEyMwUAAACqK2BiAQCqK2BiAgCqK2BiAwCqK2BiBACqK2BiIACPG4nQj/lot4s1aQR6Q/gj+owGW+qXkhaU1hQt+Zo02Q==";

    cout << "original data:" << data << " " << data.size() << endl;
    string v = AesEncryptString(k, data);
    cout << "encrypted data:" << v << " " << v.size() << endl;
    string vv = AesDecryptString(k, v);
    if (vv != data) {
        cout << "wrong" << endl;
    }
    cout << "decrypted data:" << vv << endl;
}

void test_encrypt_many() {
    map<string, string> kv = {
            {"abcdefghabcdefgh",                   "1928349weidiaohahahahaha343"},
            {"abcdefghabcdefgh",                   ""},
            {"one",                                "two"},
            {"threee",                             "four"},
            {"asfdlkas;djfkl;asdfa;sldkfasdfadsf", "576a8sidoulfjkasdfnasld;iojrilk2q3r;afsenfklasdf"}
    };
    for (auto i: kv) {
        auto k = i.first;
        auto data = i.second;
        string v = AesEncryptString(k, data);
        cout << "encrypted data:" << v << " " << v.size() << endl;
        string vv = AesDecryptString(k, v);
        if (vv != data) {
            cout << "wrong" << endl;
        } else {
            cout << "right" << endl;
        }
    }
}

void test_hex2() {
    string s = "41CFBCE192AE90D865F04789477131E24294F878658B2CDE22CCBEE8F85DFEE9";
    cout << hex2string(s) << endl;
}

void test_string() {
    const char *a = "abcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcdabcd";
    string ans(a);
    cout << strlen(a) << ";" << ans.size() << endl;
}

void test_base64() {
    const char *a = "wei";
    auto ans = base64encode((const unsigned char *) a, strlen(a));
    cout << ans << endl;
    string s = "haha";
    cout << base64encodeString(s) << endl;
    cout << base64decodeString(base64encodeString(s)) << endl;
    cout << base64decodeString(ans) << endl;
}

void handleOpenSSLErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void test_decrypt() {
    string a = "gasdf";
    string key = "asdfdfas";
    auto ans = AesDecryptString(key, a);
    cout << ans << endl;
}

int main() {
//    test_string();
//    test_hex();
//    test_base64();
//    test_encrypt();
    test_decrypt();
//    test_encrypt_many();
    return 0;
}
