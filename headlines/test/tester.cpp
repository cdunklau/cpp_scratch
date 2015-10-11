#include <istream>
#include <iostream>

extern "C" {
#include <curl/curl.h>
}

#include <HTTPClient.hpp>


void test_httpclient() {
    curl_global_init(CURL_GLOBAL_ALL);
    CURL *curl = curl_easy_init();
    if (curl) {
        std::string url = "http://httpbin.org/headers";
        HTTPClient client(curl);
        std::iostream body = client.retrieve(url);
    } else {
        std::cerr << "Failed to initialize curl!";
    }
    curl_global_cleanup();
}


int main() {
    return 0;
}
