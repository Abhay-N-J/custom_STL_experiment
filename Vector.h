// #include<iostream>
// #include<cstdlib>
#include "custom.h"

template <typename T> 
class custom::Vector {
    T *_v;
    size_t _size;
    size_t _capacity;
    double _factor;
    public:
        Vector() : _v(nullptr), _capacity(0), _size(0), _factor(0.75) {}
        Vector(int n, int i = 0) {
            _v = (T*) calloc(n, sizeof(T));
            if (!_v)
                std::cout<< "Error", exit(1);
            std::fill_n(_v, sizeof(_v), i);
            _capacity = n;
            _size = n;
            _factor = 0.75;
        }

        Vector(Vector &other) : _v(nullptr), _capacity(0), _size(0), _factor(0.75) {
            _v = (T*) calloc(other.size(), sizeof(T));
            if (!_v) 
                std::cout<< "Error", exit(1);
            std::copy(other.begin(), other.end(), _v);
            _capacity = other.size();
            _size = other.size();
            _factor = 0.75;
        }

        Vector(std::initializer_list<T> other) :_v(nullptr), _capacity(0), _size(0), _factor(0.75) {
            _size = other.size();
            _v = (T*) calloc(_size, sizeof(T));
            if (!_v) 
                std::cout<< "Error", exit(1);
            size_t t = 0;
            for (const auto& i: other) 
                _v[t++] = i;
            _capacity = _size;
            _factor = 0.75;
        }


        ~Vector() {
            if (_v)
                free(_v);
        }

        Vector& operator=(std::initializer_list<T> other) {
            if (_v) 
                free(_v);
            // _size = sizeof(other);
            _size = other.size();
            _v = (T*) calloc(_size, sizeof(T));
            if (!_v) 
                std::cout<< "Error", exit(1);
            size_t i = 0;
            for (const auto &j: other) 
                _v[i++] = j;
            _capacity = _size;
            _factor = 0.75;
            return *this;
        }

        Vector& operator=(Vector &other) {
            if(this == &other)
                return *this;
            if (_v != nullptr) {
                free(_v);
            }
                // std::cout << "HELLO" ;

            _capacity = other.size();
            _size = other.size();
            _factor = 0.75;
            _v = (T*) calloc(other.size(), sizeof(T));
            if (!_v) 
                std::cout<< "Error", exit(1);
            std::copy(other.begin(), other.end(), _v);
            
            return *this;
        }

        Vector& operator=(Vector&& other) noexcept {
            if (this == &other) {
                return *this; // Self-assignment check
            }
            if(_v)
                free(_v); // Deallocate existing resources

            _v = other._v;
            _size = other._size;
            _capacity = other._capacity;
            _factor = other._factor;

            // Reset the other object so that its destructor won't deallocate the memory
            other._v = nullptr;
            other._size = 0;
            other._capacity = 0;

            return *this;
        }

        void resize(size_t n) {
            _v = (T*) realloc(_v, sizeof(T) * n);
            _size = _capacity = n;
        }

        void insert(int index, T ele) {
            if (index >= _size || index < 0)
                std::cout << "Error", std::cout<< "Error", exit(1);
            size_t t = _capacity && ((double)(_size / _capacity) < _factor)? 0 : 1;
            if (t) {
                _v = (T*) realloc(_v, (_capacity * 2 + 1) * sizeof(T));
                if (!_v)
                    std::cout<< "Error", exit(1);
                _capacity *= 2; 
                _capacity++;
            }
            for (int i = _size - 1; i >= index; i--) 
                _v[i + 1] = _v[i];
            _v[index] = ele;
            _size++;
        }

        void erase(int index) {
            if (index >= _size || index < 0)
                std::cout<< "Error", exit(1);
            for (int i = index; i < _size - 1; i++) 
                _v[i] = _v[i + 1];
            _size--;
        }

        void clear() {
            _capacity = 0;
            _size = 0;
            if (_v) free(_v);
            _v = nullptr;
        }

        void push_back(const T &a) {
            size_t t = _capacity && ((double)(_size / _capacity) < _factor)? 0 : 1;
            if (t) {
                _v = (T*) realloc(_v, (_capacity * 2 + 1) * sizeof(T));
                if (!_v)
                    std::cout<< "Error", exit(1);
                _capacity *= 2; 
                _capacity++;
            }
            _v[_size++] = a;
        }

        void pop_back() {
            if (!_v || _size < 1)
                std::cout<< "Error", exit(1);
            _size--;            
        }
       
        T& operator[](int index) {
            if (index >= _size || index < 0)
                std::cout<< "Error", exit(1);
            return _v[index];
        }
        T back() {
            if (!_size) 
                std::cout<< "Error", exit(1);
            return _v[_size - 1];
        }
        size_t size() {
            return _size;
        }
        T* begin() {
            return _v;
        }
        T* end() {
            return _v + _size;
        }
        T* data() {
            return _v;
        }
        friend std::ostream& operator<<(std::ostream &o, Vector<T> &v) {
            for (auto i: v) 
                o << i << "\t";
            o << '\n';
            return o;
        }
};

// template <typename T>
// std::ostream& operator<<(std::ostream &o, T *a) {
//     o << *a;
//     return o;
// }

// template <typename T>
// std::ostream& operator<<(std::ostream &o, Vector<T> &v) {
//     for (auto i: v) 
//             o << i << '\t';
//     o << std::endl;
//     return o;
// }


