Json语言

- 轻量级数据交互格式，本质是一个带有特定格式的字符串
- 负责不同编程语言中的数据传递和交互
- 格式：{}||[{}\{}]——字典或嵌套元素为字典的列表、
- Python语言与Json语言的转化
	- 导入json模块——import json
	- data=[{}]——准备符合格式json的要求的Python数据
	- 使用转化语法
		- json转化为Python——json.dumps(data，en……)
		- Python转化为json——json.loads(data，en……)
			- 如果数据中有中文可以带上ensure_ascii=False参数确保中文正常转化

pyecharts——可进入官网进行更多的可视化学习

+ 基础折线图

```python
from pyecharts.charts import Line #导包，构建折线图对象
from pyecharts.options import TitleOpts,LegendOpts,VisualMapOpts,ToolboxOpts  #导包，进行全局配置
line=Line()#折线图对象
line.add_xaxis(['中国','美国','英国'])#x轴数据，参数只有一个
line.add_yaxis("GDP",[30,20,10])#y轴名称，y轴数据
line.set_global_opts(
title_opts=TitleOpts(title="测试",pos_left="center",pos_bottom="1%"),#标题配置，标题名，标题位置，标题距离底部位置
legend_opts=LegendOpts(is_show=True),#图例配置项
visualmap_opts=VisualMapOpts(is_show=True),#视觉映射配置项
toolbox_opts=ToolboxOpts(is_show=True),#工具箱配置项
)#选择全局配置方法
line.render()#生成折线图
```

![](../../OneDrive/图片/屏幕截图 2024-01-23 173814.png)

![](../../Pictures/Screenshots/屏幕截图 2024-01-24 124328.png)

![](../../Pictures/Screenshots/屏幕截图 2024-01-24 125818.png)

###### 

+ 基础地图

```python
from pyecharts.charts imporrt Map
from pyecharts.options import VisualMapopts
map=Map()
data=[]
map.add("标题",data,"地图名称")
map.render()
```

```python
from pyecharts.charts import Map
from pyecharts.options import VisualMapOpts
map=Map()
data=[("北京",99),("上海",199),("湖南",299),("台湾",199),("安徽",299),("广州",399),("湖北",599)]
map.add("地图",data,'China')
map.render()
```

全局配置——视觉映射配置

```python
map.set_global_opts(
visualmap_opts=VisualMapOpts
(is_show=True, #展示颜色
 is_piecewise=True,#开启手动设置颜色范围
 piece=[{"min":,"max":,"label":,"color":}]))#she'z
```

颜色代码获取——ab173，前端——颜色对照表

基础柱状图

```
from pyecharts.charts import Bar
from pyecharts.Options import LabelOpts
bar=Bar()
bar.add_xaxis([])
bar.add_yaxis('名称',[]，label_opts=LabelOpts(position='')#设置数值标签位置)
bar.render()
#反转x、y轴
bar.reversal_axis()
```

基础时间线柱状图

```
from pyecharts.charts import Timeline
from pyecharts.options import *
#主题设置默认为红色
from pyecharts.globals import ThemeType
timeline=Timeline({"theme":ThemeType.LIGHT}#设置主题，'.'后面为主题)
timeline.add(bar1,"说明")
timeline.add(bar2,'说明')
#设置自动播放
timeline.add_schema(
play_interval=,#自动播放的时间间隔，单位为毫秒
is_timeline_show=True,#是否显示时间线
is_auto_play=True,#是否自动播放
is_loop_play=True#是否循环自动播放
)
timeline.render("图表说明")
```

 

![](../../Pictures/Screenshots/屏幕截图 2024-02-01 210418.png)
