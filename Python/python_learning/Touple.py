# 第4章 元组（不可修改的列表）
circle = (1,5)
print(f"元组circle: {circle}")


# 4-13
foods = ("rice", "meat", "bitter", "fish", 'egg')
for food in foods :
  print(food)
# foods[0] = "Ham"  报错
foods = ("Ham", "carrot", "bitter", "fish", 'egg')
for food in foods :
  print(food)
