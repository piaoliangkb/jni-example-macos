#include "include/com_piaoliangkb_jnitest_HelloJNI.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

JNIEXPORT void JNICALL Java_com_piaoliangkb_jnitest_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
    std::string s = "Hello, world from Java Package!";
    std::list<std::string> lst = {s, "other string"};
    for (auto s: lst) {
        std::cout << s << std::endl;
    }
}