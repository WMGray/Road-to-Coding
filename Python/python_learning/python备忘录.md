# python备忘录

## 一、字符串函数
  1. `title()`  每个单词的首字母大写
  2. `upper()`  小写转大写
  3. `lower()`  大写转小写
  4. f" {变量}  "
  5. `rstrip()` 去掉结尾空格(并不保存)
  6. `lstrip()` 去掉开头空格(并不保存)
  7. `strip()` 去掉两头空格(并不保存)
  8. `split()` 以空格为分隔符将字符串拆成多个部分，并存到列表中
  9. `in` 判断是否有子串

## 二、列表操作
  1. 改---直接赋值
  2. 增---`append()`函数 添加至列表尾部
             `insert()`函数 可选择添加位置
  3. 删---`del`语句 指定下标
             `pop()`函数 弹出元素值 并返回(默认列表尾部，可指定下标)
             `remove()`函数 删除`第一个`给定值  若不存在报错
  4. 排序---`sort()`函数 永久排序  `reverse = True` 可逆序
                 `sorted()`函数 临时排序 不影响原排列  `reverse = True` 可逆序
  5. 反转---`reverse()`函数 永久排列
  6. 获取长度---`len()`函数

## 三、操作列表
  1. `range()`函数  前闭后开  若只有一个参数A 则为[0,A)
  2. `list(range())` 创建数字列表 参数`a,b,c` a、c可省略  c---步长
  3. `min()`、`max()`、`sum()`
  4. 切片 到后一个下标前的一个元素
                 没有第一个--默认从头开始
                 没有第二个--默认到尾结束
                 也可指定第3个值 为步长 且都为`:`隔开
  5. 复制列表   A = B[:] (如果仅A = B，则只得到一个列表)  
                 若B = A,则A、B为同一个列表 对A/B的任意操作都会同时改变A、B的值    
                 若B = A[:],则A、B为两个列表 对A、B的操作不会影响另一个列表

## 元组
  1. 不可修改的列表
  2. 定义只包含一个元素的元组 在元素后加逗号 `eg A = (3, )`

## if语句
  1. `and` 和 `or`
  2. `in` 判断关键字是否在`列表`中
  3. `not in` 判断关键字不在`列表`中

## 字典
  1. `键值对`之间用`,`隔开
  2. 添加`键值对`直接赋值
  3. 修改字典中的值直接赋值
  4. 删除键值对 -- `del`语句
  5. 输入多行键值对时：在`{`后按回车 下一行缩进`Tab`/`四个空格`
  6. 访问值:按索引 `eg Dict['A']` 但当不存在`A`的键的会报错
                       `get(a,b)`函数  a--要查找的键  b--键a不存在时返回的内容 默认b为`None`
  7. 遍历  
        - 键值对 `for key, value in Dict.items()` 用`items()`获取键值对`列表`
        - 键 `for key in Dict.keys()`  用`keys()`获取键`列表`
             `for key in Dict`
        - 值 `for value in DIct.values` 用`values()`获取值`列表`

## 用户输入和while循环
  1. `input()` 用户输入 可编写提示
              当提示过长时，可以将提示赋值给一个变量，再将变量传递给函数`input()`
              用户输入的数字为`字符串`类型,可用`int()`函数转化为`int`型变量
  2. `break`跳出整个循环
  3. `continue`结束当次循环 返回循环开头进行条件判断

## 函数
  1. 函数定义-->形参
     - 可提供默认值 可省略实参
  2. 函数调用-->实参
     - `位置实参` -- 实参形参位置相对应
     - `关键字实参` -- 在函数调用时将名称和值关联起来 `eg get_users(user_name = 'A')`
    
  3. 在函数中修改列表是永久的 直接传递列表
  4. 若不想在函数中修改列表 传递列表的副本，即`List[:]`
  5. 传递任意数量的实参
     - 在函数定义中形参表示为`*A` ，创建一个名为`A`的空元组用来接收
     值
     - 在函数定义中形参表示为`**A`，创建一个名为`A`的空字典
  6. `import`导入多个函数/类时，用`逗号`隔开
## 类
  1. `__init__()`是一个特殊方法，每次创建新实例时都会自动运行(前后各两个下划线)  
     以`self`为前缀的变量可供类中的所有方法使用，可以通过类的任何实例来访问
  2. 给属性指定默认值可在`__init__()`方法中为其指定默认值
  3. 修改属性的值
     - 直接修改属性的值--通过实例直接访问
     - 通过方法修改属性的值--在类中添加方法
  4. `继承`：一个类继承另一个类时，自动获得另一个类的所有属性和方法
     - `super()` 调用父类
     - 对于父类的方法，可以进行重写--在子类中定义一个与要重写的父类方法同名方
  5. 类名应采用`驼峰命名法`

## 文件
  1. `open()`函数 名称包含后缀 可相对路径、绝对路径(双反斜杠或斜杠)
     - vscode为避免在工作路径下查找文件，应在`launch.json`下添加`cwd": "${fileDirname}`
     - 模式实参：`w`-写入模式   `r`-读取模式    `a`-附加模式   `r+`-读写模式  
                 若省略模式实参，默认以只读模式打开 
  2. 关键字`with`在不再需要访问文件后将文件关闭
  3. 读取  
     - `read()`函数读取全文档内容并返回一个`字符串`(会多一个空行 可用`rstrip()`删去)
     - 逐行读取 `for line in file :` 每行末尾一个换行符 + `print()`换行符 -->多余空白行
     - `readlines()`读取文件的每一行，并存在一个列表中
     - 读取文本文件时，python将其中的所有文本都解读为字符串，若要用到数字，需`int()`
  4. 写入
     - `write()` python只能将字符串写入文本文件，若存储数值数据，可使用`str()`
     - `write()` 不会在写入的文本末尾添加换行符，若写入多行，须在`write()`中包含换行符
     - `'a'`附加模式，在文本末尾写入，若文件不存在，则新建文件

## 异常
  1. `try-except`代码块 && `try-except-else`代码块
     - `else`代码块依赖`try`代码块的成功执行
     - `ZeroDivisionError`--除`0`     `FileNotFoundError`--找不到文件
  2. `pass`语句 什么也不做 程序继续执行
  3. 存储数据 `json`
     - `json.dump()`存数据 两个实参：要存储的数据 + 可用于存储数据的文件对象
     - `json.load()`取数据 一个实参：文件名
  
## 代码测试
  1. `unittest`模块 测试类必须继承`unittest.TestCase`类，类中所有以`test_`开头的方法都将自动运行
  2. 断言方法：
     - `assertEqual(a,b)` 核实`a == b`
     - `assertNotEqual(a,b)` 核实`a != b`
     - `assertTrue(x)` 核实`x`为`True`
     - `assertFalse(x)` 核实`x`为`False`
     - `assertIn(item,list)` 核实`item`在`list`中
     - `assertNotIn(item,list)` 核实`item`不在`list`中 
   3. `setUp()` 方法 在此方法中创建的变量可在类中使用


   __name__ 是当前模块名，当模块被直接运行时模块名为 __main__ 。  
  这句话的意思就是，当模块被直接运行时，以下代码块将被运行，当模块是被导入时，代码块不被运行。



  
       
