//
// Created by chenww on 17/5/5.
//
#include <android/log.h>
#include <jni.h>
#include <string.h>
#include "./linearList/SqList.h"

#define LOG "provider-jni"
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__) // 定义LOGE类型

jclass Provider; //c代码所要调用的方法所在的类名
jobject mProvider; //类的实力对象
jmethodID showWithAndroid; //c代码要调用的方法id
jmethodID sayHello;
jmethodID showWithTextView;

//调用非静态方法需要得到类的实例对象，其实整个逻辑就像java里面的反射
//在这声明下因为方法实现是在InitProvider后面，而在InitProvider又用到了该方法，所以可以这么写防止编译出错
int GetProviderInstance(JNIEnv *env, jclass obj_class);

//初始化 类、对象、方法
int InitProvider(JNIEnv *env)
{
    LOGE("InitProvider Begin");
    if(env == NULL)
    {
    LOGE("InitProvider null");
        return 0;
    }

    if(Provider == NULL)
    {
        Provider = (*env)->FindClass(env, "yuiaragaki/microfun/com/dsaa/jni/Provider");
        if(Provider == NULL)
        {
            return -1;
        }
    }
    LOGE("InitProvider Begin--->findclass OK");

    if(mProvider == NULL)
    {
        if(GetProviderInstance(env, Provider) != 1)
        {
            (*env)->DeleteLocalRef(env, Provider);
            return -1;
        }
    }
    LOGE("InitProvider Begin--->getinstance OK");

    if(showWithAndroid == NULL)
    {
        showWithAndroid = (*env)->GetStaticMethodID(env, Provider, "ShowWithAndroid", "(Ljava/lang/String;)V");
        if(showWithAndroid == NULL)
        {
            (*env)->DeleteLocalRef(env, Provider);
            (*env)->DeleteLocalRef(env, mProvider);
            return -2;
        }
    }
    LOGE("InitProvider Begin--->getmethod ShowWithAndroid OK");

    if(showWithTextView == NULL)
        {
            showWithTextView = (*env)->GetStaticMethodID(env, Provider, "showWithTextView", "([BI)V");
            if(showWithAndroid == NULL)
            {
                (*env)->DeleteLocalRef(env, Provider);
                (*env)->DeleteLocalRef(env, mProvider);
                return -2;
            }
        }
        LOGE("InitProvider Begin--->getmethod showWithTextView OK");
/**
    if(sayHello == NULL)
    {
        sayHello == (*env)->GetMethodID(env, Provider, "testDemo", "(Ljava/lang/String;)V");
        if(sayHello == NULL)
        {
        LOGE("InitProvider Begin--->getmethod testDemo null");
            (*env)->DeleteLocalRef(env, Provider);
            (*env)->DeleteLocalRef(env, mProvider);
            return -3;
        }
    }
    LOGE("InitProvider Begin--->getmethod sayHello OK");
    LOGE("InitProvider End");
*/

    return 1;
}

int GetProviderInstance(JNIEnv *env, jclass obj_class)
{
    LOGE("GetProviderInstance Begin");

    if(obj_class == NULL)
    {
        return 0;
    }

    jmethodID construction_id = (*env)->GetMethodID(env, obj_class, "<init>", "()V");

    if(construction_id == 0)
    {
        return -1;
    }
    LOGE("GetProviderInstance Begin--->getinit OK");

    mProvider = (*env)->NewObject(env, obj_class, construction_id);

    if(mProvider == NULL)
    {
        return -2;
    }
    LOGE("GetProviderInstance Begin--->newobject OK");
    LOGE("GetProviderInstance End");

    return 1;
}

void SayHello(JNIEnv *env)
{
    if(Provider == NULL || mProvider == NULL || sayHello == NULL)
    {
        int result = InitProvider(env);
        if(result != 1)
        {
            return;
        }
    }

    jstring jstrMSG = NULL;
    jstrMSG = (*env)->NewStringUTF(env, "Hi,I'm From C");

/**
    LOGE("SayHello Begin");
    (*env)->CallVoidMethod(env, mProvider, sayHello, jstrMSG);
    LOGE("SayHello End");
*/

    (*env)->CallStaticVoidMethod(env, Provider, showWithAndroid, jstrMSG);

    (*env)->DeleteLocalRef(env, jstrMSG);
}

void ShowWithTextView(JNIEnv *env, SqList L, int id)
{
    if(Provider == NULL || mProvider == NULL || showWithTextView == NULL)
    {
        int result = InitProvider(env);
        if(result != 1)
        {
            return;
        }
    }
    unsigned char buffer[L.length];
    for(int i=0; i<L.length; i++)
    {
        buffer[i] = L.elem[i];
        LOGE("Show L.elem[%d]:%d", i, L.elem[i]);
    }
    jbyteArray array = (*env)->NewByteArray(env, L.length);
    (*env)->SetByteArrayRegion(env, array, 0, L.length, buffer);
    (*env)->CallStaticVoidMethod(env, Provider, showWithTextView, array, id);
}

