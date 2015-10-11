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
        std::string headlinesXpath = "/channel/item/title/text()";
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

        xmlpp::Document* document = parser.get_document();
        xmlpp::Element* rootElement = document.get_root_node();
        xmlpp::NodeSet headlines = rootElement.find(headlinesXpath);

        for (xmlpp::NodeSet::iterator i=headlines.begin();
                i != headlines.end();
                i++) {
            xmlpp::TextNode *headline = dynamic_cast<xmlpp::TextNode*>(*i);
            std::cout << "Title: " << headline << std::endl;
        }

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
