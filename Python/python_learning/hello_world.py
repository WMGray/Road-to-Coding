print("hello world")

print("hello python!") 

message  = "123四五六"
print(message)

message = "456七八九"
print(message)

message = 'she says:"I love python!"'
print(message)
print("每个单词首字母大写(title()函数): " + message.title())
print("小写转大写(upper()函数): " + message.upper())
print("大写转小写(lower()函数): " + message.lower())


# f" {变量}  "
A = "许思毅"
B = "大傻逼"
message = f"hello, {B}{A}!"
print(message)
print(f"{A} {B}!")
print(f"hello, {B}{A}!")

message = "hello\t\n {}{}!".format(A,B)
print(message)

message = "   许思毅傻逼 \n    "
print(f"不去掉空格长度: {len(message)}")
print(f"去掉结尾空格长度: {len(message.rstrip())}")
print(f"去掉开头空格长度: {len(message.lstrip())}")
print(f"去掉两头空格长度: {len(message.strip())}")


A = "xusiyi"
print(f"{A},大傻逼！")
print(f"{A.upper()},大傻逼！")
print(f"{A.lower()},大傻逼！")
print(f"{A.title()},大傻逼！")