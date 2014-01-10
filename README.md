data_struct_impl
================

自己实现《大话数据结构》中所有数据结构，从简单到复杂，Whatever！

＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
相关说明：

1.代码使用GNU C(C99 ＋ GNU的扩展）标准

2.开发平台：Ubuntu 13.10

3.gcc版本：4.8.1

＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

按照书中的讲解，分为以下几个模块进行代码实现（以目录形式表示，每一个都有对应的c文件实现）：

1.线性表（目录：linear_list ）

  1.1 顺序存储结构

  1.2 链式存储结构

    1.2.1 单链表

    1.2.2 静态链表

    1.2.3 循环单项链表

    1.2.4 双向链表

    1.2.5 循环双向链表
    
    循环双向链表书中未描述，但我在读Linux Kernel Development 一书时，对内核
    实现的这个基本的数据结构有很深的印象，因此也想要自己实现一下。

2.栈与队列（目录：stack_queue）

  2.1 栈的顺序存储结构

  2.2 栈的链式存储结构

  2.3 栈的应用--实现四则运算表达式
  
  2.4 循环队列

3.串（目录：string）

  3.1 朴素的模式匹配算法

  3.2 KMP

4.树（目录：tree）

  4.1 树的存储结构

    4.1.1 双亲表示法

    4.1.2 孩子表示法

    4.1.3 孩子兄弟表示法

  4.2 二叉树

    4.2.1 前序遍历
    
    4.2.2 中序遍历

    4.2.3 后序遍历

    4.2.4 线索二叉树
    
    4.2.5 赫夫曼树
 
5.图（目录：graph）

  5.1 图的存储结构

    5.1.1 邻接矩阵

    5.1.2 邻接表

    5.1.3 十字链表

    5.1.4 邻接多重表

    5.1.5 边集数组

  5.2 图的遍历
  
    5.2.1 深度优先遍历

    5.2.2 广度优先遍历

  5.3 最小生成树

    5.3.1 普里姆（Prim）算法

    5.3.2 克鲁斯卡尔（Kruskal）算法

  5.4 最短路径

    5.4.1 迪杰斯特拉（Dijkstra）算法

    5.4.2 弗洛伊德（Floyd）算法

  5.5 拓扑排序

  5.6 关键路径

6.查找（Search）

  6.1 顺序表查找

  6.2 有序表查找

    6.2.1 折半查找

    6.2.2 插值查找

    6.2.3 斐波那契查找

  6.3 线性索引查找

    6.3.1 稠密索引
    
    6.3.2 分块索引

    6.3.3 倒排索引

  6.4 二叉排序树

  6.5 平衡二叉树（AVL树）

  6.6 多路查找树（B树）

  6.7 散列表查找（哈希表）

7.排序（sort）

  7.1 冒泡排序

  7.2 简单选择排序

  7.3 直接插入排序

  7.4 希尔排序

  7.5 堆排序

  7.6 归并排序

  7.7 快速排序

暂列以上这些，逐个实现。
