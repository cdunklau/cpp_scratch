#include <string>
#include <iostream>
#include <istream>
#include <cstdlib>
#include <vector>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <libxml++/libxml++.h>


struct FeedInfo {
    // Name of the feed to display to the user
    std::string name;
    // URL to retrieve the feed
    std::string url;
    // XPath to retrieve the title text nodes
    std::string titleXPath;
};


const std::string BBC_XPATH = "/rss/channel/item/title/text()";


std::vector<FeedInfo> feeds = {
    {
        "BBC Top Stories",
        "http://feeds.bbci.co.uk/news/rss.xml",
        BBC_XPATH
    },
    {
        "BBC World News",
        "http://feeds.bbci.co.uk/news/world/rss.xml",
        BBC_XPATH
    }
};

// Put the body of the URL into the stream
void
retrieveURLBody(std::string url, std::stringstream& bodyStream) {
    curlpp::Cleanup cleanup;
    curlpp::Easy request;

    std::stringstream body;
    curlpp::options::WriteStream writeStream(&bodyStream);

    request.setOpt(curlpp::options::Url(url));
    request.setOpt(writeStream);
    request.perform();
}

// Parse the XML in `xmlStream` and return the nodes found by the xpath
xmlpp::NodeSet
findHeadlines(std::stringstream& xmlStream, std::string xpath) {
    xmlpp::DomParser parser;
    parser.parse_stream(xmlStream);
    xmlpp::Document* document = parser.get_document();
    xmlpp::Element* rootElement = document->get_root_node();
    return rootElement->find(xpath);
}


int main() {
    std::cout << "Starting up " << std::endl;
    for (FeedInfo feed : feeds) {
        std::cout << "Downloading feed " << feed.name << "..." << std::endl;

        std::stringstream xmlStream;
        retrieveURLBody(feed.url, xmlStream);

        std::cout << "Parsing feed " << feed.name << "..." << std::endl;

        xmlpp::NodeSet titleNodes = findHeadlines(xmlStream, feed.titleXPath);

        std::cout << "Titles for feed " << feed.name << ":" << std::endl;

        for (xmlpp::Node* node : titleNodes) {
            std::cerr << "trying to cast " << node << std::endl;
            xmlpp::TextNode* headline = dynamic_cast<xmlpp::TextNode*>(node);
            std::cerr << "headline is " << headline << std::endl;
            if (headline != NULL) {
                std::cout << "Title: " << headline->get_content() << std::endl;
            } else {
                std::cerr << "Couldn't cast to xmlpp::TextNode" << std::endl;
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}
