def get_fotmatted_name(first_name, last_name, middle=''):
  # 返回完整的姓名
  if middle:
    return (first_name +" " + middle + " " + last_name).title()
  else:
    return (first_name +" " + last_name).title()

username = get_fotmatted_name('RC','Jn')
if __name__ == '__main__':
  print(username)
  