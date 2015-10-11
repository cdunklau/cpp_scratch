#include <istream>
#include <iostream>
#include <cstdlib>

extern "C" {
#include <curl/curl.h>
}

#include <HTTPClient.hpp>


int test_httpclient() {
    HTTPClient client;
    try {
        client = HTTPClient();
    } catch (CurlInitializationFailed &failure) {
        std::cerr
            << "ERROR: Initialization failed: " << failure.what() << std::endl;
        return 1;
    }
    std::string feedURL = "http://feeds.bbci.co.uk/news/world/rss.xml";
    try {
        client.retrieve(feedURL);
    } catch (RequestFailed& failure) {
        std::cerr << "ERROR: Request failed: " << failure.what() << std::endl;
        return 1;
    }
    return 0;
}


int main() {
    if (test_httpclient() != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
