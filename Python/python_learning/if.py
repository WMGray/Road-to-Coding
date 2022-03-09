# 第5章 if语句

cars = ["audi", "bmw", 'sybaru', 'toyora']
for car in cars :
  if car != "bmw":
    print(car.title())
  else :
    print(car.upper())

L1 = [1,2,3,4,5,6,7,8]
if 10 in L1 :
  if_10 = True
else :
  if_10 = False
if 1 in L1 :
  if_1 = True
else :
  if_1 = False
print(f"if_10: {if_10}")
print(f"if_1 : {if_1}")


# if-elif-else 结构
age = 10
if age < 4 :
  print("4岁一下免费！")
elif age < 18 :
  print("4~18岁收费25美元！")
else :
  print("18岁(含以上)收费40美元！")

L2 = L1[:] # 复制L1
if L2 :
  print("L2非空")
else :
  print("L2为空")    