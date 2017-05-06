//
// Created by kevinchen on 2017/5/6.
//

#ifndef DSAA_SQLIST_H
#define DSAA_SQLIST_H

#endif //DSAA_SQLIST_H

typedef int ElemType; //数据类型
typedef struct {
    ElemType *elem; //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
}SqList;
