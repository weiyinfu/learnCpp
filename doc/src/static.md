# 一、实现单例
```cpp
class UserManager {
public:
    static UserManager manager;

    static UserManager *getInstance() {
        static UserManager manager;
        return &manager;
    }

    string name;
};
```
# 二、静态成员变量
修饰函数或者变量。  
# 二、实现局部作用域
static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
```cpp
static int x=3;
```