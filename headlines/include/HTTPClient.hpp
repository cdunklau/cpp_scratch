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
        std::iostream retrieve(std::string urlString);
    private:
        CURL *curl;
};

class RequestFailed : public std::runtime_error {};
class CurlInitializationFailed : public std::runtime_error {};

#endif
