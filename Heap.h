// #include "custom.h"
#include "Vector.h"

template <typename T>
class custom::Heap : public custom::Vector<T> {
    void heapify(T* arr, int n, int root) {
        int largest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != root) {
            std::swap(arr[root], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    public:
        typedef custom::Vector<T> super;
        Heap() : super() {}
        Heap(int n, int i = 0) : super(n, i) {}
        Heap(custom::Vector<T> &other) : super(other) {}
        Heap(std::initializer_list<T> other) : super(other) {}
        
        void make_heap() {
            T* first = this->begin();
            T* last = this->end();
            const auto n = last - first;
            for (int i = n / 2 - 1; i >= 0; --i) {
                heapify(first, n, i);
            }
        }
        void push_heap(T ele) {
            super::push_back(ele);
            T* first = this->begin();
            T* last = this->end();
            int n = last - first;
            int child = n - 1;
            while (child > 0) {
                int parent = (child - 1) / 2;

                if (first[child] <= first[parent]) {
                    break;
                }

                std::swap(first[child], first[parent]);
                child = parent;
            }
        }
        void pop_heap(T *first, T *last) {
            int n = last - first;
            if (n <= 1) {
                return;
            }

            std::swap(first[0], first[n - 1]);
            heapify(first, n - 1, 0);
        }

        void sort_heap() {
            T* first = this->begin();
            T* last = this->end();
            while (last != first) {
                pop_heap(first, last--);
            }
        }

        friend std::ostream& operator<<(std::ostream &o, Heap<T> &v) {
            for (auto i: v) 
                o << i << "\t";
            o << '\n';
            return o;
        }
        

};

// namespace custom {
//     template <typename T>
//     void heapify(T arr, int n, int root) {
//         int largest = root;
//         int left = 2 * root + 1;
//         int right = 2 * root + 2;

//         if (left < n && arr[left] > arr[largest]) {
//             largest = left;
//         }

//         if (right < n && arr[right] > arr[largest]) {
//             largest = right;
//         }

//         if (largest != root) {
//             std::swap(arr[root], arr[largest]);
//             heapify(arr, n, largest);
//         }
//     }

//     template <typename T>
//     void make_heap(T first, T last) {
//         const auto n = last - first;
//         for (int i = n / 2 - 1; i >= 0; --i) {
//             heapify(first, n, i);
//         }
//     }

//     template <typename T>
//     void push_heap(T first, T last) {
//         int n = last - first;
//         int child = n - 1;

//         while (child > 0) {
//             int parent = (child - 1) / 2;

//             if (first[child] <= first[parent]) {
//                 break;
//             }

//             std::swap(first[child], first[parent]);
//             child = parent;
//         }
//     }
//     template <typename T>
//     void pop_heap(T first, T last) {
//         int n = last - first;
//         if (n <= 1) {
//             return;
//         }

//         std::swap(first[0], first[n - 1]);
//         heapify(first, n - 1, 0);
//     }

//     template <typename T>
//     void sort_heap(T first, T last) {
//         while (last != first) {
//             pop_heap(first, last--);
//         }
//     }

// }