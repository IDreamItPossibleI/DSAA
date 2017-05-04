//
// Created by chenww on 17/4/20.
//
#include <string.h>
#include <jni.h>

//jstring:返回值类型
//Java_所要实现的方法名所在java类用下划线替代点的引用地址_方法名(JNI环境变量 env,JNI环境对象 jobj)
//yuiaragaki.microfun.com.dsaa
jstring Java_yuiaragaki_microfun_com_dsaa_MainActivity_sayHello(JNIEnv *env, jobject thiz)
{
    return (*env)->NewStringUTF(env, "Hello from JNI!");
}