线性表

抽象ADT描述：

数据对象：

数据关系：

基本操作｛
    1.初始化 InitList(&L)
        操作结果：将L初始化为空表
    2.销毁表 DestoryList(&L)
        操作前提：线性表L已存在
        操作结果：将L销毁
    3.清空表 ClearList（&L）
        操作前提：线性表L已存在
        操作结果：将L置为空表
    4.表是否为空 EmptyList(L)
        操作前提：线性表L已存在
        操作结果：如果L为空表则返回真，否则返回假
    5.获取表的长度 ListLength(L)
        操作前提：线性表L已存在
        操作结果：如果L为空表则返回0，否则返回表中的元素个数
    6.获取表中指定位置元素
｝