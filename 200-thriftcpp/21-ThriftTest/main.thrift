//namespace c one
namespace cpp two
struct User{
    1: string name;
    2: i32 age;
}
struct Food{
    1: string name;
}
service Mine{
   User Get(1:User user);
   void Get2(1:User user);
   User Get3();
}