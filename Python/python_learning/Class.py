# 类

# 创建Dog类
from re import M


class Dog:
  '''一个简单的Dog类'''
  def __init__(self, name, age):
    '''初始化属性 name、age'''
    self.name = name
    self.age = age
    
  def sit(self):
    '''模拟小狗收到命令时蹲下'''
    print(f'{self.name} is now sitting!')

  def roll_over(self):
    '''模拟小狗收到命令时打滚'''
    print(f'{self.name} rolled over!')

# 根据创建实例
my_dog = Dog('Kitty', 5)
your_dog = Dog('Lucy', 6)
print(f"My dog's name is {my_dog.name}.")
print(f"Your dog's name is {your_dog.name}.")
print(f"My dog's age is {my_dog.age}. ")
print(f"Your dog's age is {your_dog.age}. ")

my_dog.sit()
my_dog.roll_over()

# Car类
class Car:
  '''一次模拟汽车的简单尝试'''
  def __init__(self, make, model, year):
    '''初始化汽车的属性'''
    self.make = make 
    self.model = model
    self.year = year
    self.odometer = 800
  
  def get_description(self):
    '''返回汽车的描述'''
    name = f'{self.year}, {self.make}, {self.model}\n\
The car has {self.odometer} miles on it'
    return name

  def update_odometer(self,new):
    self.odometer = new 
    
my_new_car = Car('AE','Auto',2018)
print(my_new_car.get_description())

# 修改属性值
my_new_car.year = 2020  # 直接修改
my_new_car.update_odometer(100)   # 通过方法修改
print(my_new_car.get_description())

# 类的继承
class ElectricCar(Car):
  '''电动汽车的特殊之处'''
  def __init__(self, make, model, year):
    '''初始化父类的属性'''
    super().__init__(make, model, year)
    self.battery_size = 75
  
  def describe_battery_size(self):
    print(f"The car's battery size is {self.battery_size}")

  def get_description(self): #重写
    print("This is an electriccar")
    super().get_description()

my_tesla = ElectricCar('tesla','model s',2020)
my_tesla.get_description()
my_tesla.describe_battery_size() 

