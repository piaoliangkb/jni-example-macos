#include <jni.h>
#include "JNIDemo.h"
#include <iostream>
#include <memory>
#include <string>

class FooBar {
public:
    FooBar(int foo, std::string bar) {
        this->foo = foo;
        this->bar = bar;
    }

    std::string getStr() {
        return bar;
    }
private:
    int foo;
    std::string bar;
};

JNIEXPORT jlong JNICALL Java_JNIDemo_createNativeInstance(JNIEnv *, jobject thisObj) {
    return (jlong) new FooBar(20, "FOOBAR");
}

JNIEXPORT void JNICALL Java_JNIDemo_destroyNativeInstance(JNIEnv *, jobject thisObj, jlong native_ptr) {
    if (native_ptr) {
        delete (FooBar*)native_ptr;
    }
}

JNIEXPORT jstring JNICALL Java_JNIDemo_nativeMethod(JNIEnv* jenv, jobject thisObj, jlong native_ptr) {
    // Print int and string in FooBar instance
    FooBar* foobar = (FooBar*)native_ptr;
    std::cout << foobar->getStr() << std::endl;
    jstring javaRet = jenv->NewStringUTF(foobar->getStr().c_str());
    return javaRet;
}

JNIEXPORT void JNICALL Java_JNIDemo_HelloWorld(JNIEnv *, jobject thisObj) {
    std::cout << "Hello, world" << std::endl;
}