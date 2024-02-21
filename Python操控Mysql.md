Python操控Mysql

pymysql第三方库创建MySQL的数据库链接(还需安装cry包)

```python
from pymysql import Connection
#获取MySQL数据库的链接对象
conn=Connection(
host='localhost',#主机名/ip地址
port=3306,#端口，默认3306
user='root',#账户名
password='20050906'#密码
)
#打印MySQl数据库软件信息
print(conn.get_server_info())
#关闭数据库链接
conn.close()
```

执行非查询类的MySQL语句

```python
#获取游标对象
cursor=conn.cursor()
conn.select_db("选择的数据库名称")
#使用游标对象，执行MySQL语句
cursor.execute("非查询数据SQL语句")
```

执行查询类的MySQL语句

```python
#获取查询结果
results:tuple=cursor.fetchall()
for r in results:
    print(r)
```

执行数据插入——pymysql包默认数据修改需要经过确认后才能执行

链接对象.commit（）——确认更改行为

+ 

```python
conn.commit()
```

+ 设置自动commit

	```python
	conn=Connect(
	……
	autocommit=True)
	```

	