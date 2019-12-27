#include <jni.h>
#include <iostream>
#include "api_request.h"


#ifndef _Included_NativeLib
#define _Included_NativeLib
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_NativeLib_getInfoCurr(JNIEnv *, jobject, jstring);

#ifdef __cplusplus
}
#endif
#endif