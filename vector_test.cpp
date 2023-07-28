#include "Vector.h"
#include "Heap.h"

int main(int argc, char const *argv[])
{
    custom::Vector<int> arr(10, 1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr[2] = 9;
    std::cout << arr;
    std::cout << arr.back() << std::endl;
    custom::Vector<int> *arr2 = new custom::Vector<int>{1,2,3};
    std::cout << *arr2;
    custom::Vector<int> *arr3 = new custom::Vector<int>();
    *arr3 = {10,20,30};
    std::cout << *arr3;
    custom::Vector<int> arr4(*arr3);
    delete arr3;
    std::cout << arr4;
    custom::Vector<int> arr5;
    arr5 = arr4;
    std::cout << arr5;
    delete arr2;

    custom::Vector<int*> a;
    int b = 1;
    int c = 1;
    int d = 1;
    a.push_back(&b);
    a.push_back(&c);
    a.push_back(&d);
    std::cout<< a;

    arr.resize(5);
    std::cout << arr;
    arr.insert(2, 999);
    arr.erase(2);
    arr.pop_back(); 
    arr.pop_back(); 
    arr.pop_back(); 
    // arr.pop_back(); 
    // arr.pop_back(); 
    // arr.pop_back(); 
    // std::cout << arr;
    // arr.clear();
    // std::cout << arr;
    custom::Vector<int> array = {123,11,3,45,6,77,8};
    std::cout<< array;
    custom::make_heap(array.begin(), array.end());
    custom::sort_heap(array.begin(), array.end());
    std::cout<< array;
    return 0;
}