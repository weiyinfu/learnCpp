#include <iostream>
#include<string>

using namespace std;
enum DataType {
    DataType_Null = 0,
    DataType_String = 1,
    DataType_Int = 2,
    DataType_Float = 3,
};

class Json {
public:
    DataType type;
    string s;
    int x;
    float y;

    Json(int x) {
        this->x = x;
        this->type = DataType_Int;
    }

    void operator=(int x) {
        this->x = x;
        this->type = DataType_Int;
    }

    void operator=(string x) {
        this->s = x;
        this->type = DataType_String;
    }

    void operator=(float x) {
        this->y = x;
        this->type = DataType_Float;
    }

    friend ostream &operator<<(ostream &o, Json &x) {
        if (x.type == DataType_Float) {
            o << x.x;
        } else if (x.type == DataType_String) {
            o << x.s;
        } else if (x.type == DataType_Int) {
            o << x.x;
        } else {
            o << "null";
        }
        return o;
    }
};

int main() {
    Json x = 1;//此处会触发赋值构造函数
    cout << x << endl;
    x = "s";//此处会触发赋值运算符
    cout << x << endl;
    return 0;
}