#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <libxml++/libxml++.h>


int test_curlpp() {
    try {
        std::string feedAddress = "http://feeds.bbci.co.uk/news/world/rss.xml";
        std::stringstream xmlStream;

        curlpp::Cleanup cleanup;
        curlpp::Easy request;

        xmlpp::DomParser parser;

        curlpp::options::Url feedUrl(feedAddress);
        curlpp::options::WriteStream writeStream(&xmlStream);

        request.setOpt(feedUrl);
        request.setOpt(writeStream);
        request.perform();

        parser.parse_stream(xmlStream);

    } catch (curlpp::RuntimeError &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (curlpp::LogicError &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}


int main() {
    if (test_curlpp() != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
