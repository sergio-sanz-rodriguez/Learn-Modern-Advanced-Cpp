#include <iostream>
#include <fstream>
#include <vector>

//#include "assignment3.h"

using namespace std;

class Language {
public:
    Language(string lang, string designer, string date);
    void Print();
private:
    string mLang;
    string mDesigner;
    string mDate;
};

Language::Language(string lang, string designer, string date){
    mLang = lang;
    mDesigner = designer;
    mDate = date;
}

void Language::Print(){
    cout << mLang << ", " << mLang << ", " << mDate << endl;
}

void assignment3(void){
    string file_name{"../languages.txt"};
    string lang;
    string designer;
    string date;
    vector<Language> languages;

    ifstream file{file_name};

    while(file >> lang >> designer >> date){
        Language language{lang, designer, date};
        
        languages.push_back(language);
    }

    file.close();

    for(auto l: languages){
        l.Print();
    }
}

int main() {
    assignment3();
}
