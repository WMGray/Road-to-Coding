# 动手学深度学习

$$

$$

## 1. 前言

### 1.1

- `模型`：调整参数后的程序
- `模型族`：通过操作参数而生成的所有不同程序的集合
- `学习算法`：使用数据集来选择参数的元程序
- 训练过程通常包含一下步骤：
  1. 从一个随机初始化参数的模型开始，这个模型基本毫不“智能”。
  2. 获取一些数据样本（例如，音频片段以及对应的是否{是,否}标签）。
  3. 调整参数，使模型在这些样本中表现得更好。
  4. 重复第2步和第3步，直到模型在任务中的表现令你满意。

![../_images/ml-loop.svg](https://zh.d2l.ai/_images/ml-loop.svg)

### 1.2 关键组件

#### 1.2.1 数据

- 每一个数据集有一个个**样本**(example, sample)组成，大多时候，它们遵循独立同分布。样本有时也叫**数据点**或**数据实例**。
- 通常每个样本由一组称为***特征***（features，或***协变量***（covariates））的属性组成。 机器学习模型会根据这些属性进行预测。
- `标签(lable)/目标(target)`：监督学习中预测的特殊的**属性**。
- 数据的`维数（dimensionality）`：每个样本的特征列别数量相同，其特征向量长度固定。
- 数据的准确性、充分性和数据量大小影响着模型的性能。

#### 1.2.2 模型 

- 深度学习与经典方法的区别主要在于：前者关注的功能强大的模型，这些模型由神经网络错综复杂的交织在一起，包含层层数据转换，因此被称为*深度学习*（deep learning）。

#### 1.2.3 目标函数

- `目标函数`：objective function。模型的优劣程度的度量
- `损失函数`：loss function。用于优化目标函数
  1. 当任务在试图预测数值时，最常见的损失函数是**平方误差**(squared error)，即预测值与实际值之差的平方。
  2.  当试图解决分类问题时，最常见的目标函数是**最小化错误率**，即预测与实际情况不符的样本比例。
- 数据集分成两部分：训练数据集用于拟合模型参数，测试数据集用于评估拟合的模型。

> Loss Function 是定义在单个样本上的，算的是一个样本的误差。
>
> Cost Function 是定义在整个训练集上的，是所有样本误差的平均，也就是损失函数的平均。
>
> Object Function（目标函数 ）定义为：Cost Function + 正则化项。

#### 1.2.4 优化算法

- 在深度学习中， 大多优化算法通常基于一种基本方法-梯度下降(gradient descent)。
- 在每个步骤中，梯度下降法都会检查每个参数，在减少损失的方向上优化参数。

### 1.3 各种机器学习问题

#### 1.3.1 监督学习

- `样本`：特征-标签 对
- 监督学习过程

![../_images/supervised-learning.svg](https://zh.d2l.ai/_images/supervised-learning.svg)

##### 1.3.1.1 回归

- `回归`(regression)是最简单的监督学习任务之一，当标签取**任意数值**时，我们称之为**回归**问题。

##### 1.3.1.2 分类

- `分类`（classification）希望模型能够预测样本术语哪个**类别**(category, 正式称为**类**(class))
-  在回归中，我们训练一个回归函数来输出一个数值； 而在分类中，我们训练一个分类器，它的输出即为预测的类别。![img](https://pica.zhimg.com/80/v2-084e4d3cba8917ec5d6984cb5ea669a6_720w.jpg?source=1940ef5c)

- `层次分类`：hierarchical classification。用于寻找层次结构，层次结构假定在许多类之间存在某种关系。 因此，并不是所有的错误都是均等的。  我们宁愿错误地分入一个相关的类别，也不愿错误地分入一个遥远的类别，这通常被称为**层次分类**。

##### 1.3.1.3 标记问题

- `多标签分类`（multi-label classification）：学习预测不互相排斥的类别的问题

##### 1.3.1.4 搜索

- 有时，我们不仅仅希望输出为一个类别或一个实值，而是找到一个集合。比如，网络搜索。

##### 1.3.1.5 推荐系统

- `推荐系统`(recommender system)：目标是向特定用户尽心"个性化"推荐。

##### 1.3.1.6 序列学习

- 在**固定大小**的输入和输出的监督学习中，模型只会将输入作为生成输出的"原料"，并不会"记住"输入的具体内容。
- 当输入是连续的。模型可能需要拥有"**记忆**"功能。
- `序列学习`输入和输出都是可变长度的序列，例如文本和视频。

#### 1.3.2 监督学习

- `无监督学习`：数据中不含有"目标的机器学习问题"
- `聚类`：在没有标签的情况下，进行数据分类
- `主成分分析`：找到少量的参数来准确地捕捉数据的线性相关性
- `因果关系和概率图模型`：描述观察到的许多数据的根本原因
- `生成对抗网络`(generative adversarial networks)：提供一种合成数据的方法

#### 1.3.3 与环境互动

- `离线学习`：offline learning。预先获取大量数据，然后启动模型，不再与环境交互，学习是在算法与环境断开后进行的。![从环境中为监督学习收集数据](https://zh.d2l.ai/_images/data-collection.svg)

​             

#### 1.3.4 强化学习

- 在强化学习问题中，agent在一系列的时间步骤上与环境交互。 在每个特定时间点，agent从环境接收一些**观察**（observation），并且必须选择一个**动作**（action），然后通过某种机制（有时称为执行器）将其传输回环境，最后agent从环境中获得**奖励**（reward）。![../_images/rl-environment.svg](https://zh.d2l.ai/_images/rl-environment.svg)

### 1.4 起源

- `layers（层）`：线性和非线性处理单元的交替
- 使用**链式规则**(**反向传播**，backpropagation)一次性调整网络中的全部参数

### 1.5 深度学习之路

- `dropout`：通过在整个神经网络中应用噪声注入来实现，用随机变量来代替权重，有助于减轻过拟合的危险。
- `注意力机制`在不增加可学习参数的情况下增加系统的记忆和复杂性。
- `多阶段设计`
- `生成对抗网络`使用具有可微参数的任意算法来代替采样器，然后对这些数据进行调整，使得鉴别器（实际上是一个双样本测试）不能区分假数据和真实数据。
- **表示学习**作为机器学习的一类，其研究的重点是如何自动找到合适的数据表示方式。深度学习是通过学习多层次的转换来进行的多层次的表示学习。

## 2. 预备知识

### 2.1 数据操作

1. 获取数据
2. 将数据读入计算机后对其进行处理

- `张量(tensor)`：$$n$$维数组

- `张量类`：在MXNet中为**ndarray**，在Pytorch和Tensorflow中为**Tensor**
####  2.1.1 入门

 - 使用 `arange` 创建一个行向量 `x`，**默认为整数**

   ```python
   x = torch.arange(12)
   ```

 - `shape`属性访问张量(沿每个轴的长度)的形状，`numel`函数返回形状的元素乘积(大小)

   ```python
   x.shape
   x.numel()
   ```

 - `x.reshape（）`函数修改张量的形状而不改变元素数量和元素值，当其中一个参数为-1时，该参数会自动选择合适的参数

   ```python
   X = x.reshape(3, 4)# 需重新赋值，若只是x.reshape(),则不会改变x
   X = x.reshape(5,-1)
   ```

 - 全0—-torch.zeros() 全1—-torch.ones() 正态分布—-torch.randn()     

   ```python
   torch.ones((3,2,3))
   torch.zeros(5,1,5)
   torch.randn(3,4)   # 每一个值都从均值为0、标准差为1的的标准正态分布中随机采样
   ```

- 也可以通过嵌套列表对张量进行赋值

  ```python
  X = torch.tensor([[1,2,33,7],[0,0,0,0]])
  ```

#### 2.1.2 运算符

-  使用**,**表示一个具有5个元素的元组，每个元素都是按元素操作的结果      

  ```python
  x + y, x - y, x * y, x / y, x ** y  # **运算符是求幂运算
  ```

- 可以把多个张量连结（concatenate）在一起， 把它们端对端地叠起来形成一个更大的张量。 我们只需要提供张量列表，并给出沿哪个轴连结。

  ```python
  torch.concat((x, y), dim=0)   # 轴--0 沿行
  torch.concat((x, y), dim=1)   # 轴--1 沿列
  ```

- **X == Y** : 对于每个位置，如果X和Y在该位置相等，则新张量中相应项的值为1。

- 对张量中的所有元素进行求和，会产生一个单元素张量。

  ```python
  X.sum()
  ```

#### 2.1.3 广播机制
- `广播机制`（broadcasting mechanism）：可以对形状不同的两个张量执行按元素操作

  1. 首先通过适当复制元素来扩展一个或两个数组，使两个张量具有相同的形状

  2. 然后对生成的数组执行按元素操作
  
#### 2.1.4 索引和切片

- 张量中的元素可以通过索引访问

- 为多个元素赋值相同的值，我们只需要索引所有元素，然后为它们赋值

  ```python
  X[:2, :2] = 1000  # 前面是行， 后面是列
  X
  ```

#### 2.1.5 节省内存

- ``id()``函数：提供内存中引用对象的确切地址

- 用`Y = X + Y`，我们将取消引用`Y`指向的张量，而是指向新分配的内存处的张量，进而导致内存的浪费和引用的混淆

- 使用**切片表示法**将操作的结果分配给先前分配的数组

  - `zeros_like(Y)`函数分配一个全0的与Y形状相同的块

    ```python
    id(a) == before, id(a), before
    #%%
    a = torch.tensor([1,2,3])
    b = torch.arange(3).reshape(1,-1)  # (1, 3) -1 自动选择合适的参数
    c = torch.zeros_like(b)
    print('id(Z):', id(c))
    c[:] = a + b
    print('id(Z):', id(c))
    ```

  - 使用`X[:] = X + Y`或`X[:] = X + Y`也可以哦

    ```python
    a = torch.tensor([1,2,3])
    b = torch.arange(2,5)
    before = id(a)
    a += b
    id(a) == before
    ```

#### 2.1.6 转换为其他Python对象

  - torch张量和numpy数组将共享它们的底层内存，就地操作更改一个张量也会**同时更改**另一个张量。

    ```python
    A = X.numpy()
    B = torch.tensor(A)
    type(A), type(B)
    ```

  - 使用`item`函数或者Python的内置函数可以将**大小为1**的张量转换为Python标量

    ```python
    a = torch.tensor([1.2525])
    a, a.item(), int(a), float(a)
    ```

    

### 2.2 数据预处理

#### 2.2.1 读取数据集

- `pandas.read_csv(data_file)`读取`csv`文件

  ```python
  data = pd.read_csv(data_file)
  ```

#### 2.2.2 处理缺失值

- `NaN`项代表**缺失值**，有两种方法处理缺失值：

  1. **插值法**：用一个替代值去弥补缺失值
  2. **删除法**：忽略缺失值

- `iloc[]`：位置索引

  ```python
  inputs, outputs = data.iloc[:, :2], data.iloc[:,2]  # 每一行的前两列   每一行的第3列
  inputs = inputs.fillna(inputs.mean())  # 用inputs的 同一列 的平均值 填充
  ```

- 将`NaN`当作一个类别，第二列这个`Alley`按其值分为两列。一列为1，一列为0

  ```python
  inputs = pd.get_dummies(inputs, dummy_na=True)
  inputs
  ```

#### 2.2.3 转换为张量格式

- `torch.tensor()`函数，将列表转换为张量

  ```python
  x, y = torch.tensor(inputs.values), torch.tensor(outputs.values)  # values这个属性是将ndarray的每一列作为一个列表
  x, y
  ```

- `data.isna().sum()`：统计每一列的NaN的个数

- `data.idxmax() `：返回列最大值的行索引  当参数为1时返回列最大值的行索引   最小值为idxmin()

- `data.drop()`：axis 默认为0 删除行   为1时 删除列   inplace=True 修改原数据  False不改变源数据，而是新拷贝一个再修改

  - labels 就是要删除的行列的名字，用列表给定

  - axis 默认为0，指删除行，因此删除columns时要指定axis=1；

  - index 直接指定要删除的行

  - columns 直接指定要删除的列

  - inplace=False，默认该删除操作不改变原数据，而是返回一个执行删除操作后的新dataframe；

  - inplace=True，则会直接在原数据上进行删除操作，删除后无法返回。

    ```python
    # 删除缺失值最多的列
    num = inputs.isna().sum() # 统计每一列的NaN的个数 返回类型为pd,cores.series
    Max_nan = num.idxmax()  # 返回列最大值的行索引  当参数为1时返回列最大值的行索引   最小值为idxmin()
    inputs.drop(labels=Max_nan, axis=1, inplace=True)  # axis 默认为0 删除行   为1时 删除列   inplace=True 修改原数据  False不改变源数据，而是新拷贝一个再修改
    ```

### 2.3 线性代数

#### 2.3.1 标量

- `标量`：仅包含一个数值
- `变量`：未知的标量值，用小写字母表示：$x\in\mathbb{R}$表示$x$是一个实值标量

#### 2.3.2 向量

- `向量`：标量值组成的列表，用粗体、小写的符号表示：$\mathbf{x}$

- 列向量是向量的默认方向
  $$
  \begin{split}\mathbf{x} =\begin{bmatrix}x_{1}  \\x_{2}  \\ \vdots  \\x_{n}\end{bmatrix},\end{split}
  $$

  ```python
  x = torch.arange(5)
  x[2]
  ```

  

##### 2.3.2.1 长度、维度和形状

- `维度`(dimension)：向量的长度

  - `len()`函数

  - 当用张量表示一个向量（只有一个轴）时，我们也可以通过`.shape`属性访问向量的长度。

    ```python
    len(x), x.shape
    ```

- 张量的维度用来表示张量具有的轴数；张量的某个轴的维数就是这个轴的长度

#### 2.3.3 矩阵

- `矩阵`：将向量从一阶推广到二阶，通常用粗体、大写字母来表示：$\mathbf{X}$。使用$\mathbf{A} \in \mathbb{R}^{m \times n}$来表示矩阵$\mathbf A$，其由$m$行和$n$列的实值标量组成

- 矩阵元素可通过**下标索引**访问

- `转置`：矩阵的行列互换

  ```python
  B = torch.tensor([[1, 2, 3], [2, 0, 4], [3, 4, 5]])
  B, B.T , B == B.T
  ```

#### 2.3.4 张量

- 向量是一阶张量，矩阵是二阶张量

#### 2.3.5 张量算法的基本性质

- 任何**按元素**的**一元运算**都**不改变**其操作数的**形状**。 

- 给定具有**相同形状**的任意两个张量，任何**按元素二元运算**的结果都将是**相同形状**的张量。

- `Hadamard积`(Hadamard product)：两个矩阵的**按元素乘法**（数学符号**⊙**）

- 将张量乘以或加上一个**标量**不会改变张量的形状，其中张量的每个元素都将与标量相加或相乘。

  ```python
  A = torch.tensor([[1,2],[3,4]])
  B = 10
  A, B, A * B, A + B
  ```

#### 2.3.6 降维

- `求和`：$\sum$，`sum()`函数-----求张量所有元素和

  - 参数`axis=0`：按**行**元素降维，实质是求列元素的和

  - 参数`axis=1`：按**列**元素降维，实质求行元素的和

    ```python
    A, A.sum(), A.sum(axis=0), A.sum(axis=1)
    ```

- `平均值`：`mean()`函数、或者`A.sum()/A.numel()`

  ```python
  A.mean() 同样可以指定轴 axis=0--沿行元素 得列均值； axis=1--沿列元素 得行均值
  A, A.mean(axis=0), A.mean(axis=1)
  ```

##### 2.3.6.1 非降维求和

- `keepdims=True`，`sum()`函数中的参数，求和但保持**维度不变**

- 沿某个轴计算`A`元素的累积总和----`cunsum()`函数，不降低维度。该求和是求$A[i,j]$之前得元素和，例如$A[1,3] = A[1,0] + A[1,1] + A[1,2] + A[1,3]$

  ```python
  A = torch.tensor([[1,2],[3,4],[5,6],[7,8]])
  A, A.cumsum(axis=0)
  ```

#### 2.3.7 点积(Dot Product)

- `点积`($\mathbf{x}^\top\mathbf{y}$)：**相同位置**元素**乘积**的和：$\mathbf{x}^\top \mathbf{y} = \sum_{i=1}^{d} x_i y_i$

- 也可以通过**按元素乘**再**求和**求点积

  ```python
  #%%
  x = torch.tensor([1,2,3,4])
  y = torch.arange(4)
  x, y, torch.dot(x,y), torch.sum(x * y)
  ```

- 当权重为**非负数**且**和为1**，点积表示为**加权平均**

#### 2.3.8 矩阵-向量积

- `矩阵向量积`$\mathbf{A}\mathbf{x}$是一个长度为$m$的列向量，第$i$个元素是点积$\mathbf{a}^\top_i \mathbf{x}$

- `mv()`函数--矩阵向量积，$A$的列维数（沿轴1的长度--行元素个数）必须与$x$​的维数--其长度相同

  ```python
  x = torch.tensor([1,2])
  A, x, A.shape, x.shape, torch.mv(A,x)
  ```

#### 2.3.9 矩阵-矩阵乘法

- `矩阵积`：$\mathbf{C} = \mathbf{A}\mathbf{B}$
  $$
  \begin{split}\mathbf{C} = \mathbf{AB} = \begin{bmatrix}
  \mathbf{a}^\top_{1} \\
  \mathbf{a}^\top_{2} \\
  \vdots \\
  \mathbf{a}^\top_n \\
  \end{bmatrix}
  \begin{bmatrix}
   \mathbf{b}_{1} & \mathbf{b}_{2} & \cdots & \mathbf{b}_{m} \\
  \end{bmatrix}
  = \begin{bmatrix}
  \mathbf{a}^\top_{1} \mathbf{b}_1 & \mathbf{a}^\top_{1}\mathbf{b}_2& \cdots & \mathbf{a}^\top_{1} \mathbf{b}_m \\
   \mathbf{a}^\top_{2}\mathbf{b}_1 & \mathbf{a}^\top_{2} \mathbf{b}_2 & \cdots & \mathbf{a}^\top_{2} \mathbf{b}_m \\
   \vdots & \vdots & \ddots &\vdots\\
  \mathbf{a}^\top_{n} \mathbf{b}_1 & \mathbf{a}^\top_{n}\mathbf{b}_2& \cdots& \mathbf{a}^\top_{n} \mathbf{b}_m
  \end{bmatrix}.\end{split}
  $$
  

```python
A = torch.arange(12).reshape(3,-1)
B = torch.arange(10,130,10).reshape(4,-1)
A, B, torch.mm(A, B)
```

#### 2.3.10 范数

- `范数`(norm)：一个向量的大小，不涉及维度，而是分量的大小

- 线性代数中，如果我们按常数因子$α$​缩放向量的所有元素， 其范数也会按相同常数因子的**绝对值**缩放：
  $$
  f(\alpha \mathbf{x}) = |\alpha| f(\mathbf{x}).
  $$

- 三角不等式：
  $$
  f(\mathbf{x} + \mathbf{y}) \leq f(\mathbf{x}) + f(\mathbf{y}).
  $$

- 范数**非负**：
  $$
  f(\mathbf{x}) \geq 0.
  $$

- 范数**最小值为0**，当且仅当**向量值全为0**：
  $$
  \forall i, [\mathbf{x}]_i = 0 \Leftrightarrow f(\mathbf{x})=0.
  $$

- `欧几里得距离`是一个$L_2$​范数，$L_2$​范数是向量元素**平方和的平方根**：
  $$
  \|\mathbf{x}\|_2 = \sqrt{\sum_{i=1}^n x_i^2},
  $$

  ```python
  u = torch.tensor([3.0, -4.0])   # 浮点型
  torch.norm(u)
  ```

- \|\mathbf{x}\|_1 = \sum_{i=1}^n \left|x_i \right|.
  $$
  \|\mathbf{x}\|_1 = \sum_{i=1}^n \left|x_i \right|.
  $$

  ```python
  torch.abs(u).sum()
  ```

- $L_P$​**范数**：
  $$
  \|\mathbf{x}\|_p = \left(\sum_{i=1}^n \left|x_i \right|^p \right)^{1/p}.
  $$

- `Frobenius范数`：矩阵的范数。矩阵元素平方和的平方根：
  $$
  \|\mathbf{X}\|_F = \sqrt{\sum_{i=1}^m \sum_{j=1}^n x_{ij}^2}.
  $$

  ```python
  torch.ones((4, 9)), torch.norm(torch.ones((4, 9)))
  ```

  

### 2.4 微积分

