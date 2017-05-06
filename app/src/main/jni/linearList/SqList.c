//
// Created by chenww on 17/5/3.
//
//线性表的顺序实现
#include <jni.h>
#include <stdbool.h>
#include <string.h>
#include <android/log.h>

#define LIST_INIT_SIZE 100 //存储空间初始分配量
#define LISTINCREMENT 10 //存储空间分配增量
typedef int ElemType; //数据类型

#define LOG "Sqlist-jni"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__) // 定义LOGE类型

//jstring:返回值类型
//Java_所要实现的方法名所在java类用下划线替代点的引用地址_方法名(JNI环境变量 env,JNI环境对象 jobj)
//yuiaragaki.microfun.com.dsaa.jni
jint Java_yuiaragaki_microfun_com_dsaa_jni_LinearListJni_test(JNIEnv *env, jobject thiz)
{
    return test(env);
}

JNIEXPORT void JNICALL Java_yuiaragaki_microfun_com_dsaa_jni_LinearListJni_deletexall(JNIEnv *env, jobject thiz, jbyteArray buffer, jint len, jint x, jint id)
{
    LOGE("len:%d;x:%d;id:%d", len, x, id);
    deletexall(env, buffer, len, x, id);
}

typedef struct {
    ElemType *elem; //存储空间基址
    int length;     //当前长度
    int listsize;   //当前分配的存储容量
}SqList;

//我想骂人，使用&编译一直出错，c语言明明木有引用这个概念，但是在数据结构的c语言版的伪代码却使用了&，改成*
//初始化顺序表
int InitList(SqList *L)
{
    (*L).elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!(*L).elem)
    {
        return false;
    }
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return true;
}

int InsertList(SqList *L, int i, ElemType e)
{
    //先判断插入位置
    if(i<1 || i>(*L).length+1)
    {
        return false;
    }
    //判断是否有空间
    if((*L).length>=(*L).listsize)
    {
        ElemType *newbase = (ElemType *)realloc((*L).elem, ((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
        {
            return false;
        }
        (*L).elem = newbase;
        (*L).listsize += LISTINCREMENT;
    }
    //添加新数据
    for(int q = (*L).length-1; q>=i; q--)
    {
        (*L).elem[q+1] = (*L).elem[q];
    }
    (*L).elem[i-1] = e;
    ++(*L).length;
    return true;
}

int DeleteXAllList(SqList *L, ElemType x)
{
    if(L == NULL)
    {
        return 0;
    }
    int i = 0;
    int k = 0;
    for(i; i<(*L).length; i++)
    {
        if((*L).elem[i] != x)
        {
            if(i != k)
            {
                (*L).elem[k] = (*L).elem[i];
            }
            k++;
        }
    }
    (*L).length = k+1;
    return 1;
}

//将顺序表清空
int ClearList(SqList *L)
{

}

SqList L;

//c语言木有bool类型 参看http://www.cnblogs.com/pharen/archive/2012/02/06/2340257.html
int test(JNIEnv *env)
{
    bool status = InitList(&L);
    L.elem[0] = 10;
    L.elem[1] = 12;
    L.length = 2;
    LOGE("测试jni log信息");
    LOGE("elem[0]:%d", L.elem[0]);
    int sum = L.elem[0] + L.elem[1];
    LOGE("sum:%d", sum);

    InsertList(&L, 3, 8);
    InsertList(&L, 4, 6);
//    SayHello(env);
    ShowWithTextView(env, L);
    return sum;
}

int deletexall(JNIEnv *env, jbyteArray buffer, jint len, jint x, jint id)
{
    unsigned char array[len];
    (*env)->GetByteArrayRegion(env, buffer, 0, len, array);
    SqList List;
    InitList(&List);
    for(int i =0; i<len; i++)
    {
        InsertList(&List, i, array[i]);
    }
    DeleteXAllList(&List, x);
    LOGE("L.elem[0]:%d", List.elem[0]);
    ShowWithTextView(env, List, id);
}
