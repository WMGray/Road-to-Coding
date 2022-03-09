# 字典

# 外星人
alien_0 = {'color': 'green', 'points': 5 }
alien_0_color = alien_0['color']
alien_0_point = alien_0['points']
print(f"alien_0 color: {alien_0['color']}")
print(f"alien_0 point: {alien_0['points']}")

# 添加x，y坐标
alien_0['x_position'] = 0
alien_0["y_position"] = 25
print(alien_0)

# 修改字典中的值
print(f"The alien is {alien_0['color']}")

alien_0['color'] = "red"
print(f"The alien is now {alien_0['color']}")

# 删除键值对
del alien_0['points']
print(alien_0)

# 多行键值对
favorite_languages = {
  'yjm': 'C++',
  'cl': 'C',
  'xsy': "C",
  'wmh': 'python',
  'lfd': 'java',
  'gwc': 'java',
  }
print(favorite_languages)


# get()访问
print(favorite_languages.get('Xsy'))
print(favorite_languages.get('xsy'))
print(favorite_languages.get('Wmh',"找不到Wmh"))

# 遍历键值对
for key, value in favorite_languages.items():
  print(f"key--{key}  value--{value}")

# 遍历键值
print("打印键值信息")
for key in favorite_languages:
  print(f"key--{key.title()}")

if 'wmh' in favorite_languages.keys() :
  print("wmh在字典中")

# 遍历值
for value in favorite_languages.values():
  print(f"value--{value}")

print("用集合去除重复元素")
for value in set(favorite_languages.values()):
  print(f"value--{value}")


# 字典列表
alien_0 = {'color': 'red', 'points':  5}
alien_1 = {'color': 'green', 'points': 3}
alien_2 = {'color': 'yellow', 'points': 1}
alien = [alien_0,alien_1,alien_2]
print(alien)