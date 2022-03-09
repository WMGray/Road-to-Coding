# 第7章 用户输入和while循环

# 用户输入
from re import M


name = input("输入一个名字: " )
print(f'name = {name}')

# while循环
active = True
while active :
  message = input("输入要打印的字符串（quit结束）： ")
  if message != 'quit' :
    print(message)
  else :
    active = False
    