#include "String.h"
#include <iostream>
// #include "custom.h"
using namespace custom;
int main(int argc, char const *argv[])
{
    String s;
    std::cout << s;
    String s1("ALALA");
    std::cout << s1;
    String s2(s1);
    std::cout << s2;
    String s3 = s1;
    std::cout << s3;
    s.push_back('a');
    s.push_back('b');
    std::cout << s;
    s.pop_back();
    s.pop_back();
    std::cout << s;
    char *a = s3.substr(1, 4) ;
    std::cout << a << '\n';
    delete[] a;
    std::cout << s3[2] << '\n';
    s3 = s3 + s2;
    std::cout << s3;
    String s4("Const char");
    s3.append(s4);
    std::cout << s3;
    s3.append("Non const");
    std::cout << s3;
    s3.insert('P', 10);
    // std::cout << s3.find('P');
    s3.erase(10);
    std::cout << s3;
    // std::cout << s3.At(10);
    std::cout << (s3 < s4);
    s3.clear();
    
    std::cout << s3;
    custom::String inputStr;
    std::cin >> inputStr;
    std::cout << inputStr;

    return 0;
}