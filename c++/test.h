#pragma once
//函数重载的原理　编译器在底层会将函数名字做两次修饰，方便内部访问函数

//在ｃ＋＋中链接ｃ语言
#ifdef __cplusplus
extern "C"{
#endif

#include <stdio.h>
    void show();

#ifdef __cplusplus
}
#endif

