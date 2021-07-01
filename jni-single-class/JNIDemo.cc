#include <jni.h>
#include <iostream>
#include "JNIDemo.h"

JNIEXPORT void JNICALL Java_JNIDemo_HelloWorld(JNIEnv *env, jobject thisObj) {
    std::cout << "Hello, world!" << std::endl;
    return;
}