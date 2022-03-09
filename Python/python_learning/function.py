# 第8章 函数

from importlib.util import find_spec
from re import A, L
from sys import getfilesystemencodeerrors
from this import d


def get_users(username):
  '''显示简单的问候语'''
  print(f"Hello,{username}!")

get_users("John") 

# 实参 
def describe_pet(animal_name, animal_type):
  print(f'动物种类： {animal_type}')
  print(f"宠物名称： {animal_name}")

describe_pet("帕奇", "Dog")
describe_pet(animal_type= "Mix" , animal_name= "Addy")

# 返回值
def get_fotmatted_name(first_name, last_name):
  # 返回完整的姓名
  return (first_name +" " + last_name).title()

musician = get_fotmatted_name("jimi", last_name= "hendrix")
print(musician) 

# 返回字典
def build_person(first_name, last_name, age):
  full_name = f"{first_name} {last_name}"
  person = {'name': full_name, 'age': age}
  return person

musician = build_person("jimi", "hendrix", age = 25)
print(f"musician类型：{type(musician)},  {musician}")

# 结合循环
while True: # 无限循环
  print("请输入姓名：（输入q停止）")
  f_name = input("请输入姓： ")
  if f_name == 'q':
    break
  l_name = input("请输入名： ")
  if l_name == 'q':
    break
  full_name = get_fotmatted_name(f_name,l_name)
  print(f"Hello, {full_name}! \n")

# 传递列表
def greet_users(names):
  '''向列表中的每位用户发送问候'''
  for name in names:
    print(f"Hi, {name}!")

names = ['Ammy','Bercer','Candy']
greet_users(names)

# 修改列表
digits = [2,4,6,8,10]
print(f"修改列表前： {digits}")

def revise_List(L1):
  for num in range(1,10,2):
    digits.append(num)

revise_List(digits)
print(f"修改列表后： {digits}")

# 结合使用位置实参和任意数量实参
def f1(first,last,*languages):
  full_name = first + last
  for language in languages:
    print(f'{full_name}喜欢用{language}')

f1("W",'AS',"java",'py','c')

# 结合使用关键字实参和任意数量实参
def f2(first, last, **Dict):
  full_name = first + last 
  Dict['name'] = full_name
  return Dict

Person = f2(first='A',last="bc",age=21, xp='bs')
print(Person)