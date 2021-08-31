#!/bin/bash

export JAVA_HOME=/Library/Java/JavaVirtualMachines/adoptopenjdk-11.jdk/Contents/Home
echo $JAVA_HOME

clang++ -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin" -shared -o libhello.jnilib JNIDemo.cpp