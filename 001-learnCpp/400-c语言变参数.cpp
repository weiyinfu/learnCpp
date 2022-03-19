#include <stdarg.h>
#include <stdio.h>

void parse_valist_by_num(int arg_cnt, ...);

int main(void) {
    parse_valist_by_num(4, 1, 2, 3, 4);
    parse_valist_by_num(4, 1, 2, 3);
    parse_valist_by_num(4, 1, 2, 3, 4, 5); //多余的变参被忽略
}


//第一个参数定义可变参数的个数
void parse_valist_by_num(int arg_cnt, ...) {

    va_list p_args;
    va_start(p_args, arg_cnt);

    int idx;
    int val;

    for (idx = 1; idx <= arg_cnt; ++idx) {
        val = va_arg(p_args, int);
        printf("第 %d 个参数: %d\n", idx, val);
    }
    printf("---------------\n");
    va_end(p_args);
}