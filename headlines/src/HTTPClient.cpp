#include <HTTPClient.hpp>

#include <string>
#include <istream>
#include <stdexcept>

extern "C" {
#include <curl/curl.h>
}


HTTPClient::HTTPClient() {
    int res = curl_global_init(CURL_GLOBAL_ALL);
    if (res != 0) {
        throw CurlInitializationFailed("curl_global_init returned nonzero");
    }
    curl = curl_easy_init();
    if (!curl) {
        throw CurlInitializationFailed("curl_easy_init failed");
    }
    curl_global_cleanup();
}

HTTPClient::~HTTPClient() {
    curl_easy_cleanup(curl);
}


std::iostream HTTPClient::retrieve(std::string urlString) {
    CURLcode res;
    char errorBuffer[CURL_ERROR_SIZE];
    errorBuffer[0] = 0;
    curl_easy_setopt(curl, CURLOPT_URL, urlString);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        string errorString(errorBuffer);
        throw RequestFailed(errorString);
    }
}
