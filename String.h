#include "custom.h"

class custom::String {
    char *_str;
    size_t _len;

    public:
        String() : _str(nullptr), _len(0) {};
        String(const char *a) : _len(strlen(a)) {
            _str = (char*) calloc(_len + 1, sizeof(char));
            strcpy(_str, a);
        }
        String(String &a) : _len(a.length()){
            _str = (char*) calloc(_len + 1, sizeof(char));
            strcpy(_str, a.begin());
        }
        ~String() {
            if (_str)
                free(_str);
        }
        String& operator=(String &a) {
            if (_str)
                free(_str);
            _len = a.length();
            _str = (char*) calloc(_len + 1, sizeof(char));
            strcpy(_str, a.begin());
            return *this;
        }
        char& operator[](int index) {
            if (index >= _len || index < 0)
                std::cout << "Error", exit(1);
            return _str[index];
        }
        size_t length() {
            return _len;
        } 
        char* substr(int start, int end) {
            if (start < 0 || start >= _len || end < start) {
                std::cout << "Error", exit(1);
            }
            char *temp = new char[end - start + 1];
            end = _len > end ? end : _len;
            for (int i = start; i < end; i++)
                temp[i - start] = _str[i];
            temp[end - start] = '\0';
            return temp;
        }
        String& operator+(String &a) {
            static String s(_str);
            s.append(a);
            return s;
            // this->append(a);
            // return *this;
        }
        void append(String &a) {
            int l = a.length();
            // if(!_str || strlen(_str) <= _len + 1)
            _str = (char*) realloc(_str, sizeof(char) * (_len + l + 1));
            for (int i = 0; i < l; i++)
                _str[i + _len] = a.begin()[i];
            _len += l;
            _str[_len] = '\0';
        }
        void append(const char *a) {
            int l = strlen(a);
            // if(!_str || strlen(_str) <= _len + 1)
                _str = (char*) realloc(_str, sizeof(char) * _len + l + 1);
            for (int i = 0; i < l; i++)
                _str[i + _len] = a[i];
            _len += l;
            _str[_len] = '\0';
        }
        void insert(char a, int index) {
            if (index >= _len || index < 0)
                std::cout << "Error", exit(1);
            // if(!_str || strlen(_str) <= _len + 1)
            _str = (char*) realloc(_str, sizeof(char) * _len + 2);
            for (int i = _len; i >= index; i--) 
                _str[i + 1] = _str[i];
            _str[index] = a;
            _len++;
        }
        void erase(int index) {
            if ((index >= _len || index < 0) || (_len < 1) )
                std::cout << "Error", exit(1);
            for (int i = index; i < _len - 1; i++) 
                _str[i] = _str[i + 1];
            _str[--_len] = '\0';
        }
        void push_back(char a) {
            if (!_len)
                _str = (char*) realloc(_str, sizeof(char) * 2), _len = 1;
            else 
                _str = (char*) realloc(_str, sizeof(char) * _len + 2), _len += 1;
            _str[_len - 1] = a;
            _str[_len] = '\0';
        }
        void pop_back() {
            if (_len < 0)
                std::cout << "Error", exit(1);
            _len--;
        }
        int find(char a) {
            for(int i = 0; i < _len; i++)
                if(_str[i] == a)
                    return i;
            return -1; 
        }
        void clear() {
            _len = 0;
            if (_str)
                free(_str);
            _str = nullptr;
        }
        char At(int index) {
            if (index >= _len || index < 0)
                std::cout << "Error", exit(1);
            return _str[index];
        }
        char* begin() {
            return _str;
        }
        char* end() {
            return _str + _len + 1;
        }
        bool operator<(String &b) {
            return strcmp(this->begin(), b.begin()) == -1;
        }
        bool operator>(String &b) {
            return strcmp(this->begin(), b.begin()) == 1;
        }
        bool operator==(String &b) {
            return strcmp(this->begin(), b.begin()) == 0;
        }

        friend std::istream& operator>>(std::istream &i, String &s) {
            int c;
            while((c = getchar()) != '\n' && c != EOF) 
                s.push_back((char) c);
            return i;
        }
        friend std::ostream& operator<<(std::ostream &o, String &s) {
            if (!s.length())
                o << "Empty String\n";
            else
                o << s.begin() << std::endl;
            return o;
        }
};

