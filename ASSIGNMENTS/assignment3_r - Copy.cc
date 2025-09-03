#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

struct language {
    std::string lang;
    std::string designer;
    int date;
};

int main() {
    std::ifstream inputFile{"../languages.txt"};
    if ( !inputFile ) {
        std::cout << "Failed opening the file! Abort!" << std::endl;
        return -1;
    }

    std::vector<language> outVect;
    std::string line;
    while ( getline(inputFile,line) ) {
        std::istringstream is{line};
        //outVect.push_back({"","",0});
        //int elem = 0;
        //is >> outVect.back().lang;
        //is >> outVect.back().designer;
        //is >> outVect.back().date;
        
        language aux;        
        is >> aux.lang >> aux.designer >> aux.date;

        // Optional: skip lines that fail to parse
        if (is) {
            outVect.push_back(aux);
        }
    }

    for ( const auto & elem : outVect ) {
        std::cout << elem.lang << ", " << elem.designer << ", " << elem.date << std::endl;
    }
}