#include <iostream>
#include <string>

class url
{
private:
    std::string protocol;
    std::string resource;
public:
    url(const std::string& protocol, const std::string& resource) : protocol{protocol}, resource{resource}
    {

    }
    void print_url() const
    {
        std::string complete_url = protocol + "://" + resource;
        std::cout << "The URL is: " << complete_url << std::endl;
    }
};

int main() {
	url my_url{"http", "www.example.com/index.html"};
    my_url.print_url();	
}
