#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

class url
{
private:
    std::string protocol;
    std::string resource;
public:

    url(const std::string& protocol, const std::string& resource) : protocol{protocol}, resource{resource} {}

    std::string get_url() const
    {
        return protocol + "://" + resource;
    }

    void print_url() const
    {        
        std::cout << "The URL is: " << get_url() << std::endl;
    }

    bool operator==(const url& other) const {
        return protocol == other.protocol && resource == other.resource;
    }

    bool operator!=(const url& other) const {
       return !(*this == other);
    }
};

class Collect
{
private:
    std::deque<url> dq;
public:
    Collect() = default;
    ~Collect() = default;

    int get_size() const { return dq.size(); };

    std::deque<url> get_queue() const { return dq; };

    void insert(const url& u){
        auto it = std::find(cbegin(dq), cend(dq), u);
        if (it != cend(dq)) {
            dq.erase(it);
        }
        dq.push_front(u);
    }

    void erase(const url& u){
        auto it = std::find(cbegin(dq), cend(dq), u);
        if (it != cend(dq)) {
            dq.erase(it);
        }        
    }

    void pop(){ dq.pop_front(); }
};

int main() {
    Collect url_queue;
    url_queue.insert({"http", "www.example1.com/index.html"});
    url_queue.insert({"http", "www.example2.com/index.html"});
    url_queue.insert({"http", "www.example3.com/index.html"});
    url_queue.insert({"http", "www.example4.com/index.html"});    
    url_queue.insert({"http", "www.example2.com/index.html"});

    for (auto elem : url_queue.get_queue()) {
        elem.print_url();
    }
}
