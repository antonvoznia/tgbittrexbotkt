#include "hello.h"

JNIEXPORT jstring JNICALL Java_NativeLib_getInfoCurr(JNIEnv *env, jobject obj, jstring currency_type) {
    std::string type(env->GetStringUTFChars(currency_type, NULL));
    std::string res;
    if (type == "btc") {
        res = execute_request((C_MARKETS + C_BTC_USD.c_str() +"/" + C_SUMMARY).c_str());
    } else if(type == "eth") {
        res = execute_request((C_MARKETS + C_ETH_USD.c_str() +"/" + C_SUMMARY).c_str());
    } else {
        res = execute_request((C_MARKETS + C_LTC_USD.c_str() +"/" + C_SUMMARY).c_str());
    }
//    std::cout << res_btc << std::endl;
    return env->NewStringUTF(res.c_str());
}