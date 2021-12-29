#include <csetjmp>
#include <cstdlib>
#include <iostream>

using namespace std;
jmp_buf eat_jump, sleep_jump, study_jump;
const int EAT = 1, SLEEP = 2, STUDY = 3;

void eat() {
    int value = setjmp(eat_jump);
    if (value == 0)
        return;
    cout << "新的一天开始了，吃饭、学习、睡觉" << endl;
    system("@pause");
    cout << "eat after " << (value == SLEEP ? "sleep" : "study") << endl;
    if (rand() % 2 == 0)
        longjmp(study_jump, EAT);
    else
        longjmp(sleep_jump, EAT);
}

void sleep() {
    int value = setjmp(sleep_jump);
    if (value == 0)
        return; //如果是第一次创建，那就不要执行了
    cout << "sleep after " << (value == EAT ? "eat" : "study") << endl;
    if (rand() % 2 == 0)
        longjmp(eat_jump, SLEEP);
    else
        longjmp(study_jump, SLEEP);
}

void study() {
    int value = setjmp(study_jump);
    if (value == 0)
        return;
    cout << "study after " << (value == EAT ? "eat" : "sleep") << endl;
    if (rand() % 2 == 0)
        longjmp(sleep_jump, STUDY);
    else
        longjmp(eat_jump, STUDY);
}

int main() {
    srand(0);
    sleep();
    study();
    eat();
    longjmp(eat_jump, 1);
}