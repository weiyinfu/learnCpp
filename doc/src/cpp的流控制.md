# setiosflags
setiosflags(ios::fixed) 固定的浮点显示
setiosflags(ios::scientific) 指数表示
setiosflags(ios::left) 左对齐
setiosflags(ios::right) 右对齐
setiosflags(ios::skipws 忽略前导空白
setiosflags(ios::uppercase) 16进制数大写输出
setiosflags(ios::lowercase) 16进制小写输出
setiosflags(ios::showpoint) 强制显示小数点
setiosflags(ios::showpos) 强制显示符号 

# cout.setf 常见的标志：

标志	功能
boolalpha	可以使用单词”true”和”false”进行输入/输出的布尔值.
oct	用八进制格式显示数值.
dec	用十进制格式显示数值.
hex	用十六进制格式显示数值.
left	输出调整为左对齐.
right	输出调整为右对齐.
scientific	用科学记数法显示浮点数.
fixed	用正常的记数方法显示浮点数(与科学计数法相对应).
showbase	输出时显示所有数值的基数.
showpoint	显示小数点和额外的零，即使不需要.
showpos	在非负数值前面显示”＋（正号）”.
skipws	当从一个流进行读取时，跳过空白字符(spaces, tabs, newlines).
unitbuf	在每次插入以后，清空缓冲区.
internal	将填充字符回到符号和数值之间.
uppercase	以大写的形式显示科学记数法中的”e”和十六进制格式的”x”.