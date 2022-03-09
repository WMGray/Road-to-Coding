# 第4章 操作列表

magicians = ["Alice", "David", "carolina"]
# 循环输出
for magician in magicians:
  print(f"{magician} 是个好魔术师！") 
  print(f"我期待你的下一次表演 {magician}\n")
print("感谢各位，这是一场精彩的表演！")

# 创建数字列表  
numbers = list(range(1,10,2))
print(numbers)

# 创建一个1~10的平方的列表
numbers = []
for i in range(11):
  numbers.append(i**2)
print(numbers)

# 简单统计计算
digits = [1,2,5,3,6,4,5,2,22,0,13,556,10,-25]
print(f"min = {min(digits)}")
print(f"max = {max(digits)}")
print(f"sum = {sum(digits)}")

# 列表解析 求立方
squares = [value**3  for value in range(11)]
print(f"立方解析： {squares}")

print(f"输出第2到第5个元素： {squares[1:6:2]}")

# 遍历切片
for num in numbers[-5:]:
  print(num)

# 列表复制
A = [1,2,3,4,5,6]
B = A[:]
C = A
A.append(7)
B.append(8)
C.append(9)
print(f"A  {A}")
print(f"B = A[:] {B}")
print(f"C = A {C}")