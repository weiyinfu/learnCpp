#include <setjmp.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
jmp_buf eat_jump, sleep_jump, study_jump;

void eat() {
    int value = setjmp(eat_jump);
    if (value == 0)
        return;
    cout << "新的一天开始了，吃饭、学习、睡觉" << endl;
    system("@pause");
    cout << "eat" << endl;
    longjmp(study_jump, 1);
}

void sleep() {
    int value = setjmp(sleep_jump);
    if (value == 0)
        return; //如果是第一次创建，那就不要执行了
    cout << "sleep" << endl;
    longjmp(eat_jump, 1);
}

void study() {
    int value = setjmp(study_jump);
    if (value == 0)
        return;
    cout << "study" << endl;
    longjmp(sleep_jump, 1);
}

int main() {
    sleep();
    study();
    eat();
    longjmp(eat_jump, 1);
}