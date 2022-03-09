# 列表的练习
bicycle = ['Craft','Angle','Basker',"Dwer","Escer","Franker"]
print(bicycle)
print(bicycle[0].lower())

# 修改第一个列表值
bicycle[0] = "Anncer"
print(bicycle)

# 增加一个列表值
bicycle.append("Drasker")
bicycle.insert(1,"Qunen")
print(bicycle)

# 排序

print(f"原排序：{bicycle}")
print(f"临时排序: {sorted(bicycle,reverse = True)}")
print(f"原排列: {bicycle}")

bicycle.sort()
print(f"排序: {bicycle}")
print("\n\n\n\n")

# 删除一个列表值
del bicycle[1]
print(bicycle)

A = bicycle.pop(1)
print(A)
print(bicycle)

bicycle.remove("Dwer")
print(bicycle) 

bicycle.reverse()
print(f"反转列表: {bicycle}")

