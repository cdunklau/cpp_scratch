#ifndef __HTTPCLIENT_HPP__
#define __HTTPCLIENT_HPP__

#include <istream>
#include <stdexcept>

extern "C" {
#include <curl/curl.h>
}


class HTTPClient {
    public:
        HTTPClient();
        ~HTTPClient();
        void retrieve(std::string urlString);
    private:
        CURL *curl;
};

class RequestFailed : public std::runtime_error {};
class CurlGlobalInitFailed : public std::exception {};
class CurlHandleInitFailed : public std::exception {};

#endif
