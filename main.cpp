#include <iostream>
#include "test.hpp"
#include <vector>

class test{
    public:
    ~test(){
        std::cout << "fak" << std::endl;
    }
};

int main()
{
    std::vector<int> ptr;
    ptr.push_back(1);
    ptr.push_back(1);
    ptr.push_back(1);
    ptr.push_back(1);
    ptr.push_back(1);
    ptr.clear();
    std::cout << ptr.size() << std::endl;
    std::cout << ptr.capacity() << std::endl;
}