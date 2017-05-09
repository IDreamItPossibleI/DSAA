//
// Created by chenww on 17/4/21.
//
//栈的顺序存储实现
#include <jni.h>
#include <string.h>
#include <android/log.h>

#define STACK_INIT_SIZE 100 //存储空间初始分配量
#define STACKINCREMENT 10 //存储空间分配增量
typedef int ElemType; //数据类型

#define LOG "Sqlist-jni"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__) // 定义LOGE类型

/* 数据结构定义部分 start */

typedef struct {
    ElemType *base;
    ElemType *top; //栈顶指针
    int stacksize; //当前已分配的存储空间，以元素为单位
}SqStack;

int InitStack(SqStack *S)
{
    (*S).base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if((*S).base == NULL)
    {
        LOGE("分配存储空间失败");
        return 0;
    }
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
    return 1;
}

int GetTop(SqStack S, ElemType *e)
{
    if(S.top == S.base)
    {
        LOGE("栈为空");
        return 0;
    }
    e = S.top-1;
    return 1;
}

int Push(SqStack *S, ElemType e)
{
    if(S.top-S.base>=S.stacksize)
    {
        (*S).base = (ElemType *)realloc((*S).base, ((*S).stacksize+STACKINCREMENT)*sizeof(ElemType));
        if((*S).base == NULL)
        {
            LOGE("分配存储空间失败");
            return 0;
        }
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    ((*S).top)++ = e;
    return 1;
}

int Pop(SqStack *S, ElemType *e)
{
    if(S.top == S.base)
    {
        LOGE("栈为空");
        return 0;
    }
    e = --((*S).top);
    return 1;
}

/* 数据结构定义部分 end */