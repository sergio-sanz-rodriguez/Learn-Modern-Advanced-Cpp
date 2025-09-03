#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <list>
#include <deque>
#include <random>
#include <algorithm>
#include <numeric>
#include <ranges>
#include <iterator>

//Fill a vector with 10 random integers between 0 and 1000

using namespace std;

template <typename Container>
void print_container(const string& str, const Container& cont)
{
    cout << str;
    for (auto v: cont)
    {
        cout << v << " ";
    }
    cout << endl;    
}


int main() {
    
    //1
    int max_val = 1000;
    int vec_size = 10;
    mt19937 mt; //(std::random_device{}());
    uniform_int_distribution idist(0, max_val);
    vector<int> vec(vec_size);
    generate(vec.begin(), vec.end(), [&]() { return idist(mt);});
    print_container("Generated vector: ", vec);
        
    //2
    auto max_elem = max_element(cbegin(vec), cend(vec));
    cout << "Maximum element: " << *max_elem << endl;

    //3
    auto index = distance(cbegin(vec), max_elem);
    cout << "Maximum element: " << index << endl;

    //4
    auto sum_red = reduce(cbegin(vec), cend(vec));
    cout << "Sum with reduce: " << sum_red << endl;

    //5
    auto sum_acc = accumulate(cbegin(vec), cend(vec), 0);
    cout << "Sum with accumulate: " << sum_acc << endl;

    //6
    auto num_odd = count_if(cbegin(vec), cend(vec), [](int n) { return n%2==1;});
    cout << "Number of odd numbers: " << num_odd << endl;

    //7
    vector<double> vec2;
    transform(begin(vec), end(vec), back_inserter(vec2), [&](int n) { return static_cast<double>(n) / *max_elem;});
    print_container("Normalized vector: ", vec2);
    
    //8
    vector<int> vec3;
    copy(cbegin(vec), cend(vec), back_inserter(vec3));
    sort(begin(vec3), end(vec3));
    auto it_l = lower_bound(cbegin(vec3), cend(vec3), 455);
    cout << "First element greater than 455: " << *it_l << endl;

    //9
    vector<double> vec4;
    copy_if(cbegin(vec), cend(vec), back_inserter(vec4), [](int n) {return n%2==1;});
    print_container("Odd numbers: ", vec4);

    //10
    sort(begin(vec), end(vec), [](double m, double n){return m > n;});

    print_container("Vector sorted in descending order: ", vec);
    
    //11
    mt19937 mt2(random_device{}());
    auto begin_it = next(begin(vec), 1);
    auto end_it = prev(end(vec), 1);
    shuffle(begin_it, end_it, mt2);
    print_container("Shuffled vector: ", vec);

    //12
    auto defunct = remove_if(begin(vec), end(vec), [](int n){ return n%2==1;});
    vec.erase(defunct, end(vec));
    print_container("Vector without odd numbers: ", vec);

    //13
    ofstream ofile{"result.txt"};
    if(ofile)
    {
        for (size_t i=0; i < vec.size(); ++i)
        {
            ofile << vec[i];
            if (i != (vec.size() - 1))
            {
                ofile << ", ";
            }            
        }        
    }
    
    //14
    ifstream ifile("words.txt");
    
    // read the file into one string
    string content{std::istreambuf_iterator<char>(ifile), std::istreambuf_iterator<char>()};
    string content_orig;
    copy(begin(content), end(content), back_inserter(content_orig));

    // transform the string
    transform(begin(content), end(content), begin(content), [](unsigned char c){ return tolower(c); });
    transform(begin(content), end(content), begin(content), [](unsigned char c){ return isalpha(c)? c : ' '; });

    // remove duplications using set
    istringstream iss(content);
    set<string> distinct_words{istream_iterator<string>(iss), istream_iterator<string>()};
    ostream_iterator<string> out_it(cout, ", ");
    copy(distinct_words.begin(), distinct_words.end(), out_it);
    cout << '\n';

    //15
    istringstream iss_(content);
    vector<string> total_words{istream_iterator<string>(iss_), istream_iterator<string>()};
    cout << "Number of words: " << total_words.size() << endl;

    //16
    auto num_lines = count(cbegin(content_orig), cend(content_orig), '\n');
    cout << "Number of lines: " << num_lines << endl;
    //17
    cout << "Number of characters: " << content.size() + 1 << endl;

    //18
    ifstream ifile2("words2.txt");
    string content2{std::istreambuf_iterator<char>(ifile2), std::istreambuf_iterator<char>()};
    //string content2_orig;
    //copy(begin(content2), end(content2), back_inserter(content2_orig));
    transform(begin(content2), end(content2), begin(content2), [](unsigned char c){ return tolower(c); });
    transform(begin(content2), end(content2), begin(content2), [](unsigned char c){ return isalpha(c)? c : ' '; });
    istringstream iss2(content2);
    vector<string> total_words2{istream_iterator<string>(iss2), istream_iterator<string>()};
    sort(total_words.begin(), total_words.end());
    sort(total_words2.begin(), total_words2.end());
    vector<string> tmp;
    set_intersection(total_words.begin(), total_words.end(), total_words2.begin(), total_words2.end(), back_inserter(tmp));
    set<string> common_words;
    common_words.insert(tmp.begin(), tmp.end());
    print_container("Common words: ", common_words);
    cout << "Number of common words: " << common_words.size() << endl;

    //19
    vector<int> range_vec(6);
    iota(begin(range_vec), end(range_vec), 1);
    int factorial = accumulate(range_vec.begin(), range_vec.end(), 1, multiplies<int>());
    cout << "Factorial of " << range_vec.size() << " is: " << factorial << endl;

    return 0;
}