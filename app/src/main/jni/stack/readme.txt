栈

抽象ADT描述：

ADT Stack {

    数据对象：D={a}
    数据关系：
    基本操作：
        1.InitStack(&S)
            操作结果：构造一个空栈S
        2.DestoryStack(&S)
            操作前提：栈S已存在
            操作结果：栈S被销毁
        3.ClearStack(&S)
            操作前提：栈S已存在
            操作结果：将S清为空栈
        4.StackEmpty(S)
            操作前提：栈S已存在
            操作结果：若栈S为空栈，则返回tru，否则返回false
        5.StackLength(S)
            操作前提：栈S已存在
            操作结果：返回S的元素个数，即栈的长度
        6.GetTop(S， &e)
            操作前提：栈S已存在且非空
            操作结果：用e返回S的栈顶元素
        7.Push(&S, e)
            操作前提：栈S已存在
            操作结果：插入元素e为新的栈顶元素
        8.Pop(&S, &e)
            操作前提：栈S已存在且非空
            操作结果：删除S的栈顶元素，并用e返回其值
        9.StackTraverse(S, visit())
            操作前提：栈S已存在且非空
            操作结果：从栈底到栈顶依次对S的每个数据元素调用函数visit()，一旦visit()失败，则操作失败

} ADT Stack