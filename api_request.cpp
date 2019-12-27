//
// Created by anton on 8/2/19.
//

#include "api_request.h"
#include "logs.h"

std::size_t write_func(void* ptr, size_t size, size_t nmemb, std::string* s) {
    size_t newLength = size*nmemb;
    try {
        s->append((char*) ptr, newLength);
    } catch (std::bad_alloc &e) {
        std::cerr << "Bad allocation!!! write_func()" << std::endl;
        write_logs("Bad allocation!!! write_func()");
        return 0;
    }
    return newLength;
}

std::string get_markets()  {
    std::string data;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, C_GET_MARKETS.c_str());

    if (getenv("SET_PROXY")) {
        curl_easy_setopt(curl, CURLOPT_PROXY, getenv("SET_PROXY"));
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    CURLcode res;
    res = curl_easy_perform(curl);
    if (res == CURLE_COULDNT_CONNECT) {
        write_logs("get_markets() " + C_CONN_PROBLEM);
        return C_CONN_PROBLEM;
    } else if (res != 0) {
        write_logs("get_markets() " + C_ANY_PROBLEM);
        return C_ANY_PROBLEM;
    }
    curl_easy_cleanup(curl);

    return data;
}

std::string execute_request (const char* req) {
    std::string data;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, req);

    if (getenv("SET_PROXY")) {
        curl_easy_setopt(curl, CURLOPT_PROXY, getenv("SET_PROXY"));
    }

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_func);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    CURLcode res;
    res = curl_easy_perform(curl);
    if (res == CURLE_COULDNT_CONNECT) {
        write_logs("execute_request() " + C_CONN_PROBLEM);
        return C_CONN_PROBLEM;
    } else if (res != 0) {
        write_logs("execute_request() " + C_ANY_PROBLEM);
        return C_ANY_PROBLEM;
    }
    curl_easy_cleanup(curl);

    return data;
}