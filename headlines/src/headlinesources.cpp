#include <headlinesource.h>

#include <string>

#include <libxml++/libxml++.h>


class HeadlinesSourceInterface {
    public:
	static string name;
        static string feedURL;
        virtual string[] getHeadlines(xmlpp::Node rootElement);
}


class BBCWorldNewsSource: public HeadlinesSource {
    feedURL = "http://feeds.bbci.co.uk/news/world/rss.xml";
}
