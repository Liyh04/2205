## 第五组NOGO大作业report_1

> 本报告由第五组成员于佳鑫主要编写，李屹桦，杨东录同学辅助编写。

### 小组分工

* 于佳鑫同学实现了棋盘设置, 页面初步美化以及下棋逻辑的实现

* 李屹桦同学实现了判断落子合法判断，计时器的实现和棋盘页面美化

* 杨东录同学实现了计时器的实现，页面美化

### 具体实现
#### 代码框架

![image-20230402155138507](C:\Users\86130\AppData\Roaming\Typora\typora-user-images\image-20230402155138507.png)

> 简洁美丽o(*￣▽￣*)ブ



#### 代码简介

* ##### 棋盘&棋子

  * 棋盘和棋子均采用了image图片，这样比较美观

   ![image-20230402163659098](C:\Users\86130\AppData\Roaming\Typora\typora-user-images\image-20230402163659098.png)

  * 在chess.h中，我们定义了棋子的成员，其中位置采用了Qpoint；在widget中，我们采用vector容器来记录已下的棋子

  > 符合***低耦合***的要求

  * 下棋的逻辑就是判断是否vector中已经有棋子，没有就下在最近的坐标点上，有则return

* ##### 落子合法判断

  * 计算即将下的棋子的气以及周围棋子的气，采用递归的方法，非常👌

* ##### 计时器

  ![image-20230402162742409](C:\Users\86130\AppData\Roaming\Typora\typora-user-images\image-20230402162742409.png)

  > 将时间限制设置为一个可以调节的参数：）

  ![image-20230402164039806](C:\Users\86130\AppData\Roaming\Typora\typora-user-images\image-20230402164039806.png)

  * 采用艺术化的字体，让玩家体会到数字之美

* ##### 其他巧思

  * 如果下了不合法的位置

    ![image-20230402163824757](C:\Users\86130\AppData\Roaming\Typora\typora-user-images\image-20230402163824757.png)

  * 计算了下棋步数

    ![image-20230402163932617](C:\Users\86130\AppData\Roaming\Typora\typora-user-images\image-20230402163932617.png)


### 感谢

* 感谢孙亚辉老师，潘俊达助教，王卓然助教在学习和生活上的关心和指导
* 感谢由于佳鑫，李屹桦，杨东录组成的team5
* 感谢中国人民大学信息学院提供的教学平台





