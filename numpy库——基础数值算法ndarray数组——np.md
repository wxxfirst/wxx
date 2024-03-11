

- 部分学习时并未把笔记补充完整，将在复习时补充

- # numpy库——基础数值算法

- ndarray数组——np.ndarray类的对象表示n维数组，存储同一类型的数据（方便以行或者以列的形式进行数据处理）,不允许存储类对象，可以将类属性包装成一个元组，不同的类对象组成列表

  - 元数据

  	- 对目标数据的描述信息

  - 实际数据

  	- 完整的数据信息，确定数组数据类型

  - 分开存储：提高内存空间使用效率，减少对实际数据的访问，提高性能

  - 定义

  	- ary=numpy.array(列表数据)——多维数组构建，多个列表数据组成
  	- ary=numpy.arange(x,y,z)——int类型数据
  		- x——起始值，默认0
  		- y——终止值，不包含自身
  		- z——步长，默认1
  	- ary=numpy.zeros/ones(x,dtype=‘数据类型’)
  		- x——数组元素个数或数组维度
  		- 数据类型为int元素为0
  		- 数据类型为float元素为1.0
  	- ary=numpy.zeros/ones_like(a数组，dtype=‘’)
  		- 创建一个维度跟a数组一致的数组
  	- 对象特点
  		- 数组数据类型一致
  		- 下标从0开始
  
  - 对象属性的基本操作——列表的许多操作可以使用

  	- 维度显示及修改
  		- ary.shape——表示查询数组维度，返回值为元组
  		- arr.shape[n]——n表示页数、行数……
  	- 视图变维（数据共享）——数据不变，维度变，改变前后的两个数组变化具有同步性
  		- b=arr.reshape（）
  		- b=arr.ravel（）——将arr数组变成扁平数组，即一维数组
  			- ()内说明维度，无参数默认一维数组
  	- 复制变维（数据独立）——两组数组变化互不影响
  		- c=arr.flatten（）——扁平数组
  		- c=arr.copy()
  	- 就地变维——无返回值，直接对数组进行改变
  		- arr.resize()——参数为元组
  	- 数组切片操作
  		- 数组对象[起始位置：终止位置：步长]
  			- 步长+：默认从头到尾
  			- 步长-：默认从尾到头
  			- 步长默认为1
  		- 一维数组：数组[::]
  		- 二维数组：数组[: ：,:： ]——逗号第一个前是切行的情况，后是切列的情况
  	- 数组掩码操作
  		- 基于bool类型
  			- 数组[另一个数组/数组进行运算的表达式]
  		- 基于索引的掩码
  			- 数组[需要的下标的顺序]
  
  	```python
  	import numpy as np
  	a=np.arange(1,11)
  	mask=[True,False,True,False,True,False,True,False,True,False]
  	print(a[mask])
  	#数组维度一致，a[mask]返回相应为True的数值，得到一个新数组
  	```
  
  	- 数组元素数据类型

  		- 查询

  			- ary.dtype

  		- 转化

  			- ary_new=ary.astype(数据类型)——ary数组本身元素的数据类型不发生改变
  			- ary.dtype=‘数据类型’——数据类型修改易错误，且ary数组本身元素数据类型发生改变
  	
  		- 个数
  
  			- number=ary.size

  		- 行数

  			- number=len（ary）

  		- 维度

  			- arr.shape——返回元组
  			- arr.ndim
  	
  		- 元素字节数
  
  			- arr.itemsize

  		- 总字节数

  			- arr.nbytes——size*itemsize

  		- 复数数组实部

  			- arr.real

  		- 复数数组虚部

  			- arr.imag

  		- 数组转置

  			- arr.T

  		- 扁平迭代器

  			- flat——将数组变成一维数组并一个一个元素进行处理

  		- 下标索引

  			- 数组对象[……，页号，行号，列号]——均从0开始算起
  			- 获取元素
  	
  			```
  			for i in range(a.shape[]):
  			```
  	
  		- 内部基本数据类型
  
  | 数据类型     | 类型表示符                        |
  | ------------ | --------------------------------- |
  | 布尔型       | bool_                             |
  | 有符号整数型 | int8(-128-127)/int16/int32/int64  |
  | 无符号整数型 | uint8(0-255)/uint16/uint32/uint64 |
  | 浮点型       | float16/float32/float64           |
  | 复数型       | complex64/complex128              |
  | 字符串型     | str(Unicode32位)                  |
  |              |                                   |
  
  - 自定义复合类型数组
  	- 列表的形式存储，元素的每个数据类型必须一一说明,字符串为U+字符串个数，其他数据类型为数字+数据类型，可对数据类型设置别名
  
  ```python
  import numpy as np
  data=[
  ('zs',[90,80,85],15),
  ('ls',[92,81,83],16),
  ('ww',[95,85,95],15)
  ]
  a=np.array(data,dtype='U2,3int32,int32')
  b=np.array(data,dtype=[('name','str_',2)，('score','int32',3),('ages','int32',1)])
  #字段别名，字段数据类型，字段个数，可使用别名访问，例：b[2]['age']——相当于字典
  c=np.array(data,dtype={'name':['name','score','age'],'formats':['U2','3int32','int32']})
  #name表示别名，formats表示数据类型
  d=np.array(data,dtype={'name':('U3',0),'scores':('3int32',16),'ages':('int32',28)})#列表名。数据类型，内存空间所占的字节数，对象.itemsize——查询的字节数
  ```
  
  M8[时间（如s等）]——对数据进行对齐、补齐处理（对时间书写格式有固定形式），时间还可以进行四则运算，返回的结果与设置的时间最小单位有关
  
  ![](../../Pictures/Screenshots/屏幕截图 2024-01-24 233512.png)

  对数据类型进行定义

  | 类型                                                         | 字符码                    |
  | ------------------------------------------------------------ | ------------------------- |
  | numpy.bool                                                   | ?                         |
  | numpy.int8/16/32/64                                          | i1/i2/i4/i8               |
  | numpy.uint8/16/32/64                                         | u1/u2/u3/u4               |
  | numpy.float/16/32/64                                         | f2/f4/f8                  |
  | numpy.complex64/128                                          | c8/c16                    |
  | numpy.str                                                    | U<字符串>                 |
  | numpy.datatime64（四则运算返回的数值的单位为数据定义的单位，即M8[]内的单位） | M8[Y]/[M]/[D]/[h]/[m]/[s] |
  
  
  
  - 数组运算

    - 矩阵运算

      - 矩阵——numpy.matrix类类型的对象，继承numpy.ndnarray

      - 创建

        - ```python
        	numpy.matrix(
        	ary,   #任何可以被解释为矩阵的二维容器
        	copy=  #是否复制数据，默认为True，两份数据互相独立
        	)
        	```
  
        - ```python
        	ary=numpy.mat(任何可以被解释为矩阵的二维容器)
        	#创建的矩阵对象与数据源容器共享数据
        	```
  
        - ```python
        	ary=numpy.mat(拼块规则)
        	#接受字符串形式的矩阵描述，数据项通过空格分隔，数据行通过分号分隔
        	```
  
        	- ```python
        		m3=np.mat('1. 2 3;4 5 6')
        		```
  
      - 逆矩阵——非奇异矩阵
  
        - ```python
        	e=np.mat()
        	print(e.I)
        	```
      
      - 案例演示——斐波那契数列
      
        - ```python
        	n=
        	F=np.mat('1 1; 1 0')
        	for i in range(1,n):
        	    print((F**i)[0,0])
        	```
      
        	![](../../Pictures/Screenshots/屏幕截图 2024-01-30 161612.png)
      
      - 通用函数
      
        - 数组的裁剪——小于max，大于min的值组成新数组，维数保持不变，小于min的值修改为min值，大于max的值修改为max'值，源数组保持不变
  
          - ```python
          	ndarray.clip(min=,max=)
          	```
  
        - 数组的压缩——满足条件的值组成数组或掩码形式

          - ```python
          	ndarray.comress(条件)
          	#多条件写法用掩码写法
          	mask=np.all([a>3,a<7],axis=)
          	#all方法表示当两个条件均为ture时，返回数值
          	print(a.compress(mask))
          	print(a[mask])
          	```
      
        - 数组的累乘
      
          ```python
          ndarray.prod()
          ndarray.cumprod()
          ```
      
        - 加法通用函数
      
          - ```python
          	np.add.(a,a)    #数组之和
          	np.add.reduce(a) #a数组元素累加
          	np.add.accumulate(a)  #累加和过程
          	mp.add.outer([10,20,30],a)  #外和
          	np.outer([10,20,30],a)   #外积
          	```
      
        - 除法通用函数
      
          - ```python
          	np.true_divide(a,b)
          	np.divide(a,b)#a真除b，对应位置相除
          	np.floor(a,b)#a真除b，适用于小数
          	np.floor_divide(a,b)#a地板除b（真除结果向下取整）
          	np.ceil(a/b)#a天花板除b（真除的结果向上取整）
          	np.trunc(a/b)#a截断除b（真除的结果直接删除小数点部分）
          	np.around(a/b)#除去正负号，四舍五入
          	```
      
        - 位运算通用函数
      
          - 按位异或——判断两个数据是否同号(同号)
      
          - ```python
          	c=a^b
          	c=a.__xor__(b)
          	c=np.bitwise_xor(a,b)
          	a=np.where(条件)#满足条件的下标
          	```
      
          - 按位与——计算某个数字是否是2的幂
      
          	- n&（n-1)==0
      
          - ```python
          	c=a&b
          	c=a.__and__(b)
          	c=np.bitwise_and(a,b)
          	```
  
          - 按位反
      
          	- ```python
          		c=a~b
          		c=a.__not__(b)
          		c=np.bitwise_not(a,b)
          		```
  
          - 按位或
      
          	- ```python
          		c=a|b
          		c=a.__or__(b)
          		c=np.bitwise_or(a,b)
          		```
  
          - 移位
      
          	- ```python
          		c=a>>b
          		c=a.__rshift__(b)
          		c=np.right_shift(a,b)  
          		#右移1位除2
          		c=a<<b
          		c=a.__lshift__(b)
          		c=np.left_shift(a,b)   
          		#左移1位乘2
          		```
        
        - 三角函数通用函数
        
          - ```python
            np.sin()
            np.cos()
            ```
        
          - 合成方波——超多条曲线相加 
        
          - ```python
          	n=1000
          	x=np.arange(1,)
          	y=np.zeros(n)
          	for i in range(1,n+1)
          	    y+=4/(2*i-1)*np.pi*np.sin((2*i-1)*x)
          	```
      
          - ![](../../Pictures/Screenshots/屏幕截图 2024-01-30 215417.png)
        
          - 特征值与特征向量——方阵
        
          - ```python
          	eigvals,eigvecs=np.linalg.eig(A)
          	#求方阵的特征值数组，特征向量数组
          	s=np.mat(eigvecs)*np.mat(np.diag(eigvals))
          	np.mat(eigvecs逆)
          	s=eigvecs*np.diag(eigvals)*eigvecs.I
          	#已知特征值与特征向量，求方阵
          	```
      
          - 奇异值分解——非方阵，M=U*S*V——M为普通矩阵，S为对角阵，U，V为正交阵，S对角线的值称为奇异值
        
          - 特征提取方案更优
        
          - ```python
          	U,S,V=np.linalg.svd(M,full_matrices=False)
          	#U,V是正交阵，V是一维数组，
          	```
        
          - 傅里叶变换
        
          - ```python
          	import numpy.fft as nf
          	freqs=np.fft.fftfreq(采样数量，采样周期)
          	#频率序列
          	powers=np.abs(复数数组)
          	#复数得模
          	np.fft.fft(原函数值序列)
          	#目标函数值序列（复数）
          	#通过原函数值得序列经过快速傅里叶变换得到一个复数数组，复数得模代表振幅，辐角（坐标轴上复数表示得直线与x轴得夹角）代表初相位
          	np.fft.ifft(目标函数值序列（复数）)
          	#原函数序列
          	#通过一个复数数组经过逆向傅里叶变换得到合成的函数值数组
          	```
      
          - 随机数模块
        
          	- 二项分布——伯努利试验，只有两种结果，出现结果得概率相互对立，每次实验出现得结果概率独立——离散数据 
        
          		- ```python
          			np.random.binomal(n,p,size)
          			#产生size个随机数作为实验次数，每个随机数来自n次尝试中的成功次数比，每次成功次数的概率为p
          			```
        
          	- 超几何分布
        
          		- ```python
          			np.random.hypergeometric(ngood,nbad,nsample,size)
          			#产生size个随机数，每个随机数t为在总样本中随机抽取nsample个样本后好样本个数，总样本由ngood个好样本和nbad个坏样本组成，size为抽取的次数
          			```
        
          	- 正态分布——连续数据
        
          		- ```
          			np.random.normal(size)
          			#产生size个随机数，服从标准正态分布（期望值为0，标准差为1）
          			np.random.normal(loc=,scale=,size)
          			#产生size个随机数，服从正态分布（期望值为loc，标准差为scale
          			```
      
          - 杂项功能
  
          	- 排序
        
          		- 联合间接排序——若待排序列值相同，利用参考序列作为参考继续排序
        
          		- ```python
          			np.msort()#顺序排序
          			np.msort()[::-1]#逆序排序
          			indices=np.lexsort((次排序序列，主排序序列))
          			```
        
          		- 复数数组排序
        
          		- ```python
          			np.sort_complex(复数数组)
          			#复数数组排列，按实部升序排列，实部相同时以虚部作为排列参考
          			```
        
          		- 插入排序
        
          		- ```python
          			indices=np.searchsorted(有序序列，待插序列)
          			#查询并返回能够按序插入新元素的位置
          			np.insert(被插序列，位置序列，待插序列)
          			#按照指定位置插入元素
          			```
      
    - 数组与数字进行四则运算  
  
    - 数组与数字进行大小比较——数组的每个元素与数字进行比较，只有所有元素与数字比较结果一致才会返回True 
  
    - 数组乘法——对应位置相乘
  
    - 提供数学公式
  
      - ```python
      	y=np.cos(数组)
      	```
    
  - 数学运算
  
    - 非空观测数量
  
    - ```python
    	np.count()
    	```
  
    - 值和
  
    - ```python
    	np.sum()
    	```
  
    - 绝对值
  
    - ```python
    	np.abs()
    	```
  
    - 累计总和
  
    - ```python
    	np.cumsum()
    	```
  
    - 算术平均值——对真值的无偏估计
  
    - ```python
      s=[s1,s2……sn]
      m=(s1+s2+……)/n#方法1
      np.mean(array)#方法2
      array.mean()#方法3
      ```
  
    - 加权平均值
  
    - ```python
      S=[s1,s2……]#样本
      W=[w1,w2……]#权重
      a=(s1*w1+s2*w2+……)/(w1+w2+……)#加权平均值
      np.average(数据，weights=volumes)
      #参数：样本数组，权重数组 
      ```
  
    - 最值
  
    - ```python
      np.max(array)#数组中最大值
      np.min(array)#数组中最小值
      np.argmax(array)#数组中最大值的下标
      np.argmin(array)#数组中最小值的下标
      np.maximum(array1,array2)
      #将两个数组中对应的较大值组成一个新数组
      np.minimum(array1,array2)
      #将两个数组中对应的最小值组成一个新数组
      np.ptp()#极差
      ```
      
    - 中位数
  
    - ```python
      median=np.median(array)
      ```
  
    - 排序
  
    - ```python
      array1=np.msort(array)
      array1=sorted(array)
      array.sort()
      ```
      
    - 标准差
  
    - ```python
      S0=[s1,s2……]
      #样本
      m=(s1+s2+……)/n
      #平均值
      D=[d1,d2……]
      #离差
      di=si-m
      Q=[q1,q2……]
      #离差方
      qi=di**2
      V=(q1+q2+……)/n
      #总体方差
      S=sqrt(v)
      #总体标准差
      v=(q1+q2……)/(n-1)
      #样本方差
      s=sqrt(v)
      #样本标准差
      ```
  
      ```python
      np.sum(array)
      np.sqrt(array)
      np.std(array)#总体标准差
      np.std(array,ddof=1)#样本标准差
      ```
  
    - 数组的轴向汇总
  
    - 沿着数组中所指定的轴向，调用处理函数，并将每次调用的返回值重新组织成数组返回
  
    - ```python
      def func(data):
          pass
      np.apply_along_axis(func,axis,array)
      #func   处理函数
      #axis   轴向[0,1]——0表示列向，1表示行向
      #data=array  数组
      ```
  
    - 移动均线 ——平均值
  
    - k线图
  
      ```python
      #实体
      mp.bar(x,'高度'，'宽度'，'终止位置',color=,edgecolor=)
      #绘制影线
      mp.vlines(x,y-min,y-max)
      ```
  
    - 一维数组卷积——两组数组，一组为源数组，另一组为卷积核数组（奇数个元素），先将卷积核数组倒置，其最后一个元素与源数组第一个元素对齐，源数组其余位补0，一对一的相乘并相加就得到卷积，然后将卷积核数组一位一位往后移，直至运算至源数组最后一个元素与卷积核数组第一个元素一致，源数组其余位补0
  
      - 适用场景
      	- 提取图片特征
      	- 某一数据与周围数据存在紧密关系
  
    - 有效卷积（valid）
  
      - 卷积核数组元素均参与生成得卷积列表
  
    - 同维卷积（same）
  
      - 卷积核数组核心元素开始参与直至结束的卷积列表
  
    - 完全卷积（full）
  
      - 存在卷积核数组元素参与
  
    - ```python
      c=np.convolve(array1,array2,卷积类型)
      #array1为源数组，array2为卷积核数组
      ```
  
    - 一维数组加权卷积
  
    	- 卷积核数组做权重数组且卷积核数组元素之和为1
  
    - 三维、二维数组卷积——核心元素开始，一行一行进行，元素一一对应
  
    - 布林带
  
    - 线性模型——一组数据符合某个线性模型，可以预测未来会出现的数据
  
      -  线性预测
  
      - 矩阵相乘
  
      - ```python
      	x=np.linalg.lstsq(A,B)[0]#最小二乘法拟合
      	B.dot(x)#点乘，两数组对应位置相乘再相加 
      	```
  
      - ![](../../Pictures/Screenshots/屏幕截图 2024-01-29 145220.png)
  
      	
  
      - #A数组，B数组
  
      - 线性拟合——寻求与一组散点走向趋势规律相适应的线性模型
  
      - 协方差——通过两组统计数据计算而得的协方差可以评估两组数据的相似程度，正值为正相关，负值为负相关，其绝对值越大，相关性越强
  
      	- 平均值——>离差——>离差之积
  
      - 相关矩阵
  
      - 相关系数 
  
      - 符号数组——正号为1，负号为-1，0为0
  
      	- ```python
      		array1=np.sign(源数组)
      		```
  
      - 数组处理函数——对应条件取对应值
  
        - ```python
        	array1=np.piecewise(源数组，条件序列，取值序列)
        	#取值序列执行的操作与条件序列一一对应
        	```
  
      - 矢量化——用数组代替标量来操作数组里的每个元素
  
      	- ```python
      		array=np.vectorize(矢量化函数（自定义函数）——参数为数组，返回值为数组)
      		print(array)
      		print(np.vectorize(foo)(x,y))
      		fun=np.frompyfunc(foo,矢量化函数参数个数，矢量化函数返回值个数)
      		fun(参数)
      		#foo函数是表量化计算
      		```
  
      	- ```
      		import math as m#引用的数学方法是标量计算
      		import numpy as np#引用的数学方法矢量化计算
      		```
  
      		
  
  - 多维数组的组合与拆分
  
    - 垂直方向组合与拆分（v)——同列操作，列不变
  
    ```python
    arr=np.arange(1,21).reshape(2,2,5)
    a=np.arange(1,7).reshape(2,3)
    b=np.arange(7,13).reshape(2,3)
    c=np.vstack((a,b))#组合，生成新数组，需要组合的数组组成元组
    d,e=np.vsplit(c,2)#拆分，生成两个数组d与e，以’,’表示数组的多少，split（）参数中一个为待拆分的数组，另一个为拆分后的数组个数
    
    ```
  
    - 水平方向组合（h）——同行操作，行不变
  
    ```
    import numpy as np
    a=np.arange(1,7).reshape(2,3)
    b=np.arange(7,13).reshape(2,3)
    c=np.hstack((a,b))
    d,e=np.hsplt(c,2)
    ```
  
    
  
    - 深度方向组合（d）——三维空间（元素个数确定，但页数、行数、列数未确定
  
    ```
    import numpy as np
    a=np.arange(1,7).reshape(2,3)
    b=np.arange(7,13).reshape(2,3)
    i=np.dstack((a,b))
    k,l=np.dsplit(i,2)
    ```
  
    - 长度不等的数组组合
    	- 原理：填充小数组，填充只可由程序员自主设定
  
    ```python
    import numpy as np
    a=np.array([1,2,3,4])
    b=np.array([1,2,3])
    b=np.pad(b,pad_width=(0,1),mode='constant',constant_values=1)
    #pad填充方法，参数：填充的数组，起始位置填充数目，终止位置填充的数目，mode选择常数，values自定义填充数值
    print(b)
    #数组组合操作
    ```
  
    - 多维数组组合与拆分的相关函数
  
    - ```python
    	np.concatenate((a,b),axis=)
    	np.split(,,axis=)
    	```
  
    	通过axis作为关键字参数指定组合方向
  
    	- 二维数组
    		- 0：垂直方向
    		- 1：水平方向
    	- 三维数组
    		- 0：垂直方向
    		- 1：水平方向
    		- 2：深度方向
  
    - 一维数组
  
    - ```python
    	a=np.row_stack((数组1，数组2))
    	b=np.column_stack((数组1，数组2))
    	```
  
    	- row_stack——水平方向组合
    	- column_stack——垂直方向组合

演示案例：

```python
import numpy as np
a=np.arange(1,11)
b=np.arange(11,21)
c=mp.row_stack((a,b))
d=np.column_stack((a,b))
```

- numpy加载文件——解译为二维数组文件（默认转化成float）

	- ```python
		np.loadtxt(
		'../aapl.csv',#文件路径
		delimiter='',#分隔符
		usecols=    #读取数据位置（元组形式）
		unpack=,    #是否按列拆包
		dtype=,     #指定返回每列数组中元素的类型
		converters={1：dmy2ymd} )  
		#转化器转化列函数字典，values是一个函数,keys表示列数
		```

```python
#日期转化处理
def dmy2ymd(day):
    day=str(day,encoding='utf-8')
    time=dt.datetime.strptime(day,'%d-%m-%Y').date()
    t=time.strftime('%Y-%m-%d')
    return t
```

- # scipy库——科学计算

  - 

  ```python
  import scipy.io.wavfile as wf
  sample_rate,noised_sigs=wf.read('音频路径')
  #读取音频文件（参数：采样率，采样位移）
  ```

  ```
  wf.write('音频路径',采样率，采样数据.astype(np.int16))
  ```

  - 插值——插值器函数按插值算法插入新元素。传递散点x坐标，返回y坐标（根据插值算法预测）

    - 未知数据预测，离散数据连续化

    - ```
    	import scipy.interpolate as si
    	func=si.interp1d(
    	离散水平坐标，
    	离散垂直坐标，
    	kind=插值算法（缺省为线性插值）
    	#linear线性函数
    	#cubic三次样条（更为平滑）
    	)
    	```

  - 积分

    - 微元法求定积分(代码实现梯形面积求和)

    - ```
    	import scipy.integrate as si
    	area=si.quad(f,a,b)[0]
    	print(area)
    	#f为函数，a为下限，b为上限
    	```

  - ```python
    import scipy.ndimage as sn
    median=sn.median_filter(文件对象，模糊程度)
    #高斯模糊，模糊程度数据前加’.'表示边缘不模糊
    rotate=sn.rotate(文件对象，旋转角度)
    #角度旋转
    prewitt=sn.prewitt(文件对象)
    #边缘识别
    ```

    

- # matplotlib库——数据可视化

  - 绘制水平与垂直坐标序列

  - ```python
  	import numpy as np
  	import matplotlib.pyplot as mp
  	mp.plot(x,y)
  	#x——x轴坐标序列，y——y轴坐标序列
  	#x,y必须是同一维度的数组
  	mp.show()#展示图像
  	```

  	```python
  	#绘制余弦曲线
  	import numpy as np
  	import matplotlib.pyplot as mp
  	x=np.array([0,np.pi/2,np.pi])
  	y=np.cos(x)
  	mp.plot(x,y)
  	mp.show()
  	```

  - 线性拆分点

  	- ```python
  		x=np.linspace(num1,num2,num3)
  		```

  		num1——起始位置

  		num2——终止位置

  		num3——拆分的点shu

  - 绘制水平线与垂直线

  	- ```python
  		import numpy as np
  		import matplotlib.pyplot as mp
  		mp.vlines(x,y_min,y_max)#绘制垂直线
  		mp.hlines(y,x_min,x_max)#绘制水平线
  		#参数均为数字,多条时以列表作为参数，且三个参数的数据是一一对应的
  		mp.show()
  		```

  - 线型，线宽，颜色

  	- ```python
  		mp.plot(x,y,linestyle='',linwidth=num,color=''，alpha=num)
  		```

  		linestyle——线型

  		- —    直线型
  		- ——虚线型
  		- —.   点线型
  		- ：  点型

  		linewidth——线宽

  		color——颜色

  		- 颜色英文单词
  		- 英文首字母
  		- 其他类型不用便不做记录

  		![](../../OneDrive/图片/微信图片_20240126173609.jpg)

  		alpha——透明度——浮点数值

  - 设置坐标轴范围

  	- ```python
  		mp.xlim(x_limt_min,x_limt_max)
  		mp.ylim(y_limt_min,y_limt_max)
  		```

  - 设置坐标刻度

    - ```python
    	mp.xticks(x_val_list,x_text_list)
    	mp.yticks(y_val_list,y_text_list)
    	#val——刻度序列，text——刻度显示文本
    	mp.xticks([])
    	#刻度清空
    	```

    	LaTex排版语法字符串

    	语法：
    	
    	```python
    	r'$内容$'
    	r'$\frac{}{}$'#分数写法，前一部分为分子，后一部分为分母
    	```

    	![](../../Pictures/Screenshots/屏幕截图 2024-01-26 175159.png)

    	![](../../Pictures/Screenshots/屏幕截图 2024-01-26 175222.png)

    	![](../../Pictures/Screenshots/屏幕截图 2024-01-26 175234.png)

    	

    	![](../../Pictures/Screenshots/屏幕截图 2024-01-26 175246.png)

    	![](../../Pictures/Screenshots/屏幕截图 2024-01-26 175301.png)
    	
    	![](../../Pictures/Screenshots/屏幕截图 2024-01-26 175727.png)

  - 设置坐标轴

    - ```python
    	ax=mp.gca()
    	#获取当前坐标轴字典
    	axis=ax.spines['坐标轴名']
    	#获取其中某个坐标轴
    	axis.set_position((type,val))
    	axis.set_color(color)
    	#设置坐标轴的位置，参数为仅有两个元素的元组
    	#type——<str>以数据的值作为移动参照值，即参数为data
    	#outword,axes,data
    	#val——参照值
    	#color——<str>颜色值字符串
    	```
    	
    	坐标轴名：left , right ,bottom , top

  - 图例

  	- ```python
  		mp.plot(x,y……，label='',……)
  		#<关键字参数str>支持LaTex排版语法字符串
  		mp.legend(loc='')
  		#图例显示位置
  		```

  		| loc string    | loc code |
  		| ------------- | -------- |
  		| best          | 0        |
  		| upper right   | 1        |
  		| upper left    | 2        |
  		| lower left    | 3        |
  		| lower right   | 4        |
  		| right         | 5        |
  		| center left   | 6        |
  		| center right  | 7        |
  		| lower  center | 8        |
  		| upper center  | 9        |
  		| center        | 10       |

  - 特殊点

  	- ```
  		mp.scatter(x,y#x,y坐标
  		marker='',#点型
  		s='',#大小
  		edgecolor='',#边缘色
  		facecolor='',#填充色
  		zorder=  #图层编号（编号越大，图层越靠上）
  		#点型可参考matplotlib point样式
  		)
  		```


  - 备注

  		mp.annotate(
  		文本，
  		#备注显示的内容
  		xycoords='data',
  		#备注目标点所使用的目标系
  		xy=(x,y),
  		#坐标
  		textcoords='offset points'
  		#文本所使用的坐标系，offset points表示参照点的偏移坐标系
  		xytext=(x,y),
  		#文本坐标
  		fontsize=,
  		arrowprops=dict()
  		#箭头样式
  		)
  		arrowprops=dict(
  		arrowstyle='',
  		#样式
  		connectionstyle=''
  		#连接线样式)
  		```
  	
  		![](../../Pictures/Screenshots/屏幕截图 2024-02-05 171510.png)
  	
  		![屏幕截图 2024-02-05 171456](../../Pictures/Screenshots/屏幕截图 2024-02-05 171456.png)

  - 窗口对象

  		mp.figure( 
  		''，
  		#标题
  		figsize=(,)，
  		#比例
  		dpi=，
  		#像素
  		facecolor='',
  		#背景颜色
  		)
  		#当窗口已经存在时，对同名窗口的操作都是对已存在窗口进行的
  		mp.title(title,fontsize=)
  		#图表标题
  		mp.xlabel(x_label_str,fontsize=)
  		mp.ylabel(y_label_str,fontsize=)
  		mp.tick_params(labelsize=)
  		#设置刻度参数
  		mp.grid(linestyle='')
  		#设置图表网格线
  		#- or solid——粗线
  		#-- or dashed——虚线
  		#-. or dashdot——点虚线
  		#: or dotted 点线
  		mp.tight_layout()
  		#紧凑布局，把图表相关参数都显示在窗口中
  		```

  - 子图
   - 矩阵式布局——规则，size一致

  		mp.subplot(rows,cols,num)
  		#行，列，第几个
  		```
  	
  	- 网格式布局——支持单元格合并
  	
  	- ```
  		gs=mg.GridSpec(rows,columns)
  		mp.subplot(,,,)
  		#将各个单元格看成矩阵，进行切片合并
  		```
  	
  	- 自由式布局——各个单元格大小不一致
  	
  	- ```
  		mp.axes([left_bootom_x,left_bottom_y,width,height])
  		#单元格左下角x坐标，左下角y坐标，宽度，高度（单位是以比例计算的）
  		```

  - 文本设置

  		mp.text(
  		x,y,'',
  		#文本坐标，文本内容
  		ha='',
  		va='',
  		#水平线与垂直线的位置
  		size=,
  		#大小
  		alpha=,
  		withdash=False
  		)
  		```

  - 刻度定位器

  	- 


  		

  - 填充——填充两条曲线之间的闭合区域

  ```python
  mp.fill_between(
  x,#横坐标轴
  sin_x,#曲线1
  cos_x,#曲线2
  sin_x<cos_x,#填充实现的前提条件
  color='',#填充的颜色
  alpha=，#透明度
  )
  ```

  - 条形图（柱状图）

  - ```python
    mp.figure("",facecolor='')
    mp.bar(
    x,      #水平坐标，数组，当两组数据要分开显示时，可以设置偏移量
    y,       #高度，数组
    width,  #宽度，数字
    bottom,#基准位置值
    color='',
    label='',
    alpha=,
    align=’‘，#刻度位置
    )
    ```

  - 饼状图

  - ```python
    mp.axis("equal")#设置x与y轴等比例数据输出
    mp.pie(
    values,#值列表
    spaces,#扇形之间的间距列表
    labels,#标签列表
    colors,#颜色列表
    autopct='%d%%',#标签所占比例格式
    shadow=True,#是否显示阴影
    startangle=，#绘制饼状图的起始角度
    radius=#半径
    )
    ```

  - 等高线图——网格点坐标矩阵

  - ```python
    x,y=np.meshgrid(np.linspace(,,),np.linspace(,,))
    #网格化，将x与y坐标整理在一起
    z=(1-x/2+x**5+y**3)*np.exp(-x**2-y**2)#z是关于x，y的函数，是通过每个坐标的x，y计算而来的高度值（模拟海拔高度）
    cntr=mp.contour(
    x,
    y,
    z,#x,y,z都是二维数组
    8,#等高线绘制份数，密集程度
    colors='black',#等高线颜色
    linewidths=0.5
    )
    mp.concourf(x,y,z,8,cmap='jet')
    #jet颜色映射——数字小的偏蓝，数字大的偏红
    mp.clabel(cntr,inline_spacing=1,fmt='%.1f',fontsize=)
    #设置等高线标签=对象，间隙，数据呈现格式，字体大小
    ```

  - 3D图像绘制

  - ```python
    from mpl_toolkits.mplot3d import axes3d
    ax3d=mp.gca(projection='3d')
    #建立3d坐标系
    ax3d.scatter()
    #绘制三维点阵
    ax3d.plot_surface()
    #绘制三维曲面
    ax3d.plot_wireframe()
    #绘制三维线框图
    ax3d.set_xlabel('x')
    ax3d.set_ylabel('y')
    ax3d.set_zlabel('z')
    #显示x，y，z轴
    ```

    ```
    ax3d.scatter(
    x,#x轴坐标数组
    y,#y轴坐标数组
    z，#z轴坐标数组
    marker='',#点型
    s=10,#大小
    zorder='',#图层序号
    color='',#颜色
    edgecolor='',#边缘颜色
    facecolor='',#填充色
    c=v,#颜色值，根据jet选择
    cmap=''
    )
    """d=x**2+y**2+z**2,color=d,cmap='jet',表示color由距离远近决定"""
    ```

  - ```python
    ax3d.plot_surface(
        x,#网格坐标矩阵的x坐标（二维数组）
        y,#网格坐标矩阵的y坐标（二维数组）
        z,#网格坐标矩阵的z坐标（二维数组）
        rstride=,#行跨距
        cstride=,#列跨距
        cmap='jet'
    )
    ```

    ```python
    ax3d.plot_wireframe(
        x,
        y,
        zm
        cstride=,
        rstride=,
        linewidth=,
        color=''
    )
    ```

  - 极坐标系

  - ```python
    mp.gca(projection='polar')
    
    ```

    演示代码

    ```
    mp.figure()
    mp.gca(projection='polar')
    mp.title()
    mp.xlable()
    mp.ylabel()
    mp.tick_params(labelsize=)
    mp.grid(linestyle='')
    mp.show()
    ```

    ```python
    t=np.linespace(0,4*np.pi,1000)
    r=0.8*t
    mp.plot(t,r)
    mp.show()
    ```

  - 简单动画——一段时间内快速连续的重新绘制图像的过程

  - ```python
    import matplotlib.animation as ma
    def update(number):
        pass#变化操作
    #即时更新图像，每隔一段时间更新一次，作用与mp.gcf()当前窗口，调用一次，number加1
    mp.gcf()
    anim=ma.FuncAnimation(mp.gcf(),update,interval=)
    #参数：获取当前窗口，更新函数，间隔时间
    mp.show()
    ```

    ```python
    #演示案例
    import numpy as np
    import matplotlib.pyplot as mp
    import matplotlib.animation as ma
    #随机生成数据
    n=100
    balls=np.zeros(n,dtype=[('position',float,2),('size',float,1),('growth',float,1),('color',float,4)])
    #初始化
    balls['position']=np.random.uniform(x,y,z)
    #uniform——均匀分布，x——起始值，y——终止值，z——维数（元组）/个数
    balls['growth']=np.random.uniform(x,y,z)
    balls['color']=np.random.uniform(x,y,z)
    #画图
    mp.figure('Animation',facecolor=)
    mp.title('Animation',fontsize=)
    mp.xticks([])
    mp.yticks([])
    sc=mp.scatter(balls['position'][:,0],balls['position'][:,1],s=balls['size'],color=balls['color'])
    #动画
    def update(number):
        index=number%100
        #重新绘制点操作实现点消失效果（代码略）
        balls['size']+=balls['growth']
        sc.set_sizes(balls['size'])
    am=ma.FuncAnimation(mp.gcf(),update,interval=)
    ```

  - 绘制多边形

  - ```python

  	import matplotlib.patches as mc
  	for i in range(n):
  	    mp.gca().add_oatch(mc.Polygon(多边形的坐标点))
  	```


  	

- # pandas——序列高级函数，高效处理大型结构化数据

  - 加载文件

  	- ```
  		import pandas as pd
  		df=pd.read_csv(
  		filepath_or_buffer,
  		#文件路径
  		sep=',',
  		#分隔符，默认为，
  		header='infer',
  		#接受int或sequence，表示将某行数据作为列名，默认为infer——自动识别
  		names=None,
  		#接受数组，表示列名
  		index_col=None,
  		#表示索引列的位置，取值为sequence则表示多重索引
  		dtype=None,
  		#表示写入的数据类型（key为列名，values为数据）
  		#取值为object防止读取日期数据为小数
  		engine=None,
  		#接受c或python，代表数据解析引擎，默认为c
  		nrows=None
  		#接受int，表示读取前n行
  		#该方法读取文件类型为csv
  		
  		df=pd.read_table(
  		filepath_or_buffer,
  		sep='\t',
  		默认‘\t’
  		header=,
  		names=,
  		index_col=,
  		dtype=,
  		engine=,
  		nrows=)
  		pd.set_option('display.width',number)
  		#设置字符显示宽度
  		pd.set_option('display.max_rows',None)
  		#设置最大行
  		pd.set_option('display.max_columns',None)
  		#设置显示最大列
  		```

  - Series——一维数组，只是index名称可以自己改动，类似于定长有序字典，有index和value，相当于二维数组中的一列数据

    + ```python
    	import pandas as pd
    	s=pd.Series()
    	#创建一个空系列
    	s=pd.Series(array数组)
    	s=pd.Series(数组，index=)
    	#一维数组
    	s=pd.Series(字典)
    	s=pd.Series(数字，index=)
    	#标量法
    	```

    + ```python
    	#Series数据查询
    	s=pd.Series([1,2,3,4,5],index=['a','b','c','d','e'])
    	print(s[0],s[:3],s[-3:])
    	#索引检索元素
    	print(s['a'],s[['a','c','d']])
    	#标签检索数据
    	```

  - DateTimeIndex——通过指定周期和频率，使用date_range()函数就可以创建日期序列，默认情况下，范围的频率是天

    + ```
    	import pandas as pd
    	datelist=pd.date_range(日期数据，periods=number#数据生成数量)
    	#以天为频率
    	datelist=pd.date_range(日期数据，periods=，freq='M')
    	#以月为频率
    	#构建某个区间的时间序列
    	start=pd.dateime(#年,#月,#日)
    	end=pd.datetime(,,)
    	dates=pd.date_range(start,end)
    	#工作日
    	dates=pd.bdate_range(日期数据，periods=)
    	```

  - DateFrame——类似表格的数据类型，相当于一个二维数组，索引有两个维度，可以修改,列名称会自动排序

    + 潜在的列是不同类型

    + 大小可变

    + 标记轴（行和列）

    + 可以对行和列执行算术运算

    + ```python
    	import pandas as pd
    	#创建一个空DataFrame
    	df=pd.DataFrame()
    	#从列表创建DataFrame
    	data=[1,2,3,4,5]
    	df=pd.DataFrame(data)
    	
    	data=[['A',10],['B',12],['c',13]]
    	df=pd.DataFrame(data,columns=['name','age'],index=)
    	
    	data=[['a',10],['b',12],['c',13]]
    	df=pd.DataFrame(data,columns=['name','age'],dtype=float)
    	
    	data=[{'a':1,'b':2},{'a':5,'b':10,'c':20}]
    	df=pd.DataFrame(data)
    	#columns——列，index——行
    	#从字典来创建DataFrame
    	data={'name':['tom','jack','steve','ricky'],'age':[28,34,29,42]}
    	df=pd.DataFrame(data,index=[])
    	data={'one':pd.Series([1,2,3],index=[]),}
    	df=pd.DataFrame(data)
    	
    	#参数均为列表
    	```

    	+ 列访问
    	
    	  + ```python
    	  	df.[列名称]#两列及两列以上使用列表
    	  	```

    	+ 列添加——新建列索引，并赋值
    	
    	  + ```python
    	  	df[新列的名称]=pd.Series([],index=[])
    	  	#行索引默认与df一致
    	  	```

    	+ 列删除
    	
    	  + ```python
    	  	del(df[列名称])
    	  	df.pop(列名称)
    	  	#直接对原对象操作，无返回值
    	  	```

    	+ 行访问——数组选取方式，无下标越界问题
    	
    	  + ```python
    	  	df[:]#对行切片
    	  	df.loc[行名称]#两行及以上使用列表
    	  	df.iloc[数字索引]#两行及以上使用列表
    	  	df.iloc[num1,num2]#访问某个具体元素
    	  	```

    	+ 行添加——当插入的行名称不一致时会将插入数据插入列，并进行数据整理
    	
    	  + ```python
    	  	df=df._append(df2#插入的行数据)
    	  	```

    	+ 行删除
    	
    	  + ```python
    	  	df=df.drop(行索引)
    	  	```

    	+ 修改数据——先列后行索引

    	+ 返回行、列标签列表——axes

    	+ 返回对象的数据类型——dtype

    	+ 如果系列为空，则返回True——empty

    	+ 返回底层数据维数，默认定义为1——ndim

    	+ 返回基础数中的元素数——size

    	+ 将系列作为ndarray返回——values

    	+ 返回前n行——head（n）

    	+ 返回最后n行——tail（n）
    	
    	+ 数据查找——query（）
    	
    	+ 过滤清洗数据——isin（）——返回bool值
    	
    	+ 计算出现频数——value_counts()
    	
    	+ 数据中的众数——mode（）
    	
    	+ 除去无用信息——df.dropna()
    	
    	+ 求分位数
    	
    		+ ```
    			df.quantile(q=分位数)
    			df.describe().loc['分位数',]
    			```
    	
    + 描述性统计

      + numpy中的数据运算，默认情况下按照列求值，若要按行求值，则传参1

      + 例： 

      + ```python
      	df.mean(1)
      	```

      + pandas自备——默认情况下按照列求值，若要按行求值，则传参1

      + ```
      	df.describe()
      	df.describe(include=)
      	#include=['object']包含字符串统计，’number‘则包含数字统计
      	df.info()
      	```

    + pandas排序

      + 标签排序

      	+ 按行

      		+ ```python
      			df=df.sort_index(ascending=False)
      			#asending控制顺序，升序或降序
      			```

      	+ 按列

      		+ ```python
      			df=df.sort_index(asix=1)
      			```

      + 值排序

      	+ 按某列

      		+ ```python
      			df=df.sort_values(by='列名称')
      			#两列及以上，用列表，排序按列顺序
      			```

    + pandas分组

      + 聚合——计算汇总统计

      + 转换-执行一些特定组的操作

      + 过滤——在某些情况下丢弃数据

      	+ 分组

      	+ ```python
      		df=df.groupby('列名称')
      		df=df.groupby('列名称').groups
      		#具体分组结果
      		```

      	+ 迭代遍历分组

      	+ ```python
      		for 列名称,group in df:
      		    pass
      		```

      	+ 获得一个分组细节

      	+ ```python
      		df.groupby().groups.get_group(相应组合名称)
      		```

      	+ 分组聚合

      	+ ```
      		df。groupby()[相应求解列名称].agg(聚合函数[]，如np.sum)
      		#对每个组合进行分组求和等
      		df.groupby()[].value_counts()
      		#()分组，[]中各种情况求和
      		```

    + pandas数据表关联操作——连接的表数据会被全部保留

      + 合并两个数据表
    
      + ```
      	df=pd.merge(df1,df2,on='',how='')
      	#right——右连接，left——左连接，outer——使用键的联合，全连接，inner——使用键的交集，内连接，保留共性数据
      	#on字段是规定当两个表中有两个字段相同，则需指定一个字段去做表关联
      	```

      	

    + pandas透视表与交叉表

      + 透视表——各种电子表格程序和其他数据分析软件中一种常见的数据汇总工具，根据一个或多个键对数据进行分组聚合，并根据每个分组进行数据汇总，默认聚合统计所有列
    
      + ```
      	df=data.pivot_table(index=[],values=[],columns=[],margin=True,aggfunc='')
      	 #两列分类的列名称
      	#values=[]分组后的某结果查看
      	#columns=[]表示按列分
      	#margin=True表示在列和行末添加总体的均值
      	#aggfunc=''表示汇总进行的函数，默认求均值
      	```

      + 交叉表——用于计算分组频率的特殊透视表
    
      + ```
        df=pd.crosstab(data.class_id,data.gender,margins=True)
        #按照class_id分组，针对不同gender计算
        ```
    
        
