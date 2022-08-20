#include <cjson/cJSON.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void testJSON() {
  char a[1000] = "{\"name\":\"weiyinfu\",\"age\":18}";

  cJSON *res = cJSON_Parse(a);
  const char nameKey[10] = "name";
  const char ageKey[10] = "age";
  using namespace std;
  cout << res->child[0].valuestring << endl;
  char *name = cJSON_GetObjectItem(res, "name")->valuestring;
  int age = cJSON_GetObjectItem(res, ageKey)->valueint;
  printf("username=%s,age=%d", name, age);
  cJSON_Delete(res);
}
void test2() {
  char b[1000] = "[\"one\",1]";
  using namespace std;
  cJSON *res = cJSON_Parse(b);
  cout << res->next << endl;                  // 0
  cout << res->prev << endl;                  // 0
  cout << res->child->valuestring << endl;    // one
  cout << res->child->next->valueint << endl; // 1
  char *s = cJSON_Print(res);
  cout << s << endl;
  free(s);
  cJSON_Delete(res);
}
int main() {
  test2();
  testJSON();
  return 0;
}
