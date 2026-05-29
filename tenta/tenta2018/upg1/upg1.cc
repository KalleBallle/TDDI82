#include <vector>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;   


template <typename Container>
auto reverse(Container c)
{
   std::reverse(c.begin(),c.end());
    return c;
}


int main()
{
    vector<int> values1   {1,2,3,4,5};
    vector<int> reversed1 {5,4,3,2,1};
    auto res1 { reverse(values1) };
    if(std::equal(begin(reversed1), end(reversed1), begin(res1)))
    {
        std::cout << "test 1 funka" << std::endl;
    }


    list<char> values2   {'a','b','c','d'};
    list<char> reversed2 {'d','c','b','a'};
    auto res2 { reverse(values2) };
    if(std::equal(begin(reversed2), end(reversed2), begin(res2)))
    {
        std::cout << "test 2 funka"<< std::endl;

    }

    string values3   {"abcdef"};
    string reversed3 {"fedcba"};
    auto res3 { reverse(values3) };
    if(std::equal(begin(reversed3), end(reversed3), begin(res3)))
    {
        std::cout << "test 3 funka" << std::endl;
    }
}

