#include "test.hpp"

#include <stack>
#include "queue.hpp"
#include "avl_tree.hpp"
#include "map.hpp"
#include "map"
int main()
{

    // test_vector();
    // std::cout << "\n";
    // test_list();

    // std::cout << "\n";
    // test_queue();
    // std::cout << "\n";    
    // test_stack();
    // std::cout << "\n";
    // test_map();
    // std::cout << "\n";

    ft::map<int, int> f;
    ft::map<int, int>::iterator it;
    ft::map<int, int>::iterator it2;

    f.insert(std::pair<int, int>(1, 1));
    f.insert(std::pair<int, int>(2, 2));
    f.insert(std::pair<int, int>(3, 3));
    f.insert(std::pair<int, int>(5, 5));
    f.insert(std::pair<int, int>(4, 4));
    f.insert(std::pair<int, int>(7, 7));
    f.insert(std::pair<int, int>(-1, -1));
    f.insert(std::pair<int, int>(10, 10));
    f.insert(std::pair<int, int>(-5, -5));    
    it = f.begin();
    it2 = f.end();
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;                            
}