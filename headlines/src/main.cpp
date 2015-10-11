#include <string>
#include <iostream>
#include <istream>
#include <cstdlib>

#include <HTTPClient.hpp>


int main() {
    /**
    HTTPClient client;
    try {
        client = HTTPClient();
    } catch (CurlInitializationFailed &failure) {
        std::cerr
            << "ERROR: Initialization failed: " << failure.what() << std::endl;
        return EXIT_FAILURE;
    }
    std::string feedURL = "http://feeds.bbci.co.uk/news/world/rss.xml";
    std::iostream feedStream;
    try {
        feedStream = client.retrieve(feedURL);
    } catch (RequestFailed& failure) {
        std::cerr << "ERROR: Request failed: " << failure.what() << std::endl;
        return EXIT_FAILURE;
    }
    */
    return EXIT_SUCCESS;
}
