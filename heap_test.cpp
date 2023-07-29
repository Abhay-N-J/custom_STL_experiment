#include "Heap.h"

int main(int argc, char const *argv[])
{
    custom::Heap<int> heap = {123,11,3,45,6,77,8};
    std::cout << heap;
    heap.make_heap();
    std::cout << heap;
    heap.push_heap(10000);
    std::cout << heap;
    heap.sort_heap();
    std::cout << heap;

    return 0;
}
