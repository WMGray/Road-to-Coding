# 第11章 文件和异常

# 打开文件
from errno import ENOEXEC
from multiprocessing.connection import answer_challenge
import numbers


with open('test.txt') as f :
  contents = f.read()
print(contents)

# 逐行读取
with open('test.txt') as f:
  for line in f:
    print(line.rstrip())

# 按行存在列表中
with open('test.txt') as f:
  lines = f.readlines()
print(lines)


# 写入文件
with open('QAQ.txt',"w") as f:
  f.write('这是写入的文件。')

# 写入多行(附加)
with open('QAQ.txt','a') as f:
  f.write('\n开始喽！\n')
  f.write('1-->2-->3 \n')
  f.write('结束喽！')


# 处理ZeroDivisionError
try:
  print(5/0)
except ZeroDivisionError:
  print("You can't divide by 0.")

try:
  answer = 5 / 1
except ZeroDivisionError:
  print("You can't divide by 0.")
else :
  print(f"未发生错误，答案是{answer}")

# 处理FileNotFoundError + pass
try:
  with open('1,txt') as f:
    contents = f.read()
    print("打开了")
except FileNotFoundError:
  pass
# 分析文本
print(contents.split())

# 存储数据
import json

numbers = [1,3,5,7,9]
filename = "numbers.json"
with open(filename,'w') as f:
  json.dump(numbers,f)

with open(filename) as f:
  nbs = json.load(f)
print(nbs)


'''如果以前存储了用户名-->加载它'''
'''否则，输入并存储'''
filename = 'username.json'
try:
  with open(filename) as f:
    username = json.load(f)
except:
  '''输入并存储'''
  with open(filename,'w') as f:
    username = input("输入用户名: ")
    json.dump(username,f)




