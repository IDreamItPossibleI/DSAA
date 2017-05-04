//
// Created by chenww on 17/4/21.
//
//栈的顺序存储实现
#define STACK_INIT_SIZE 100; //存储空间初始分配量
#define STACKINCREMENT 10; //存储空间分配增量

typedef struct {

    int *base;
    int *top; //栈顶指针
    int stacksize; //当前已分配的存储空间，以元素为单位

}SqStack;

bool