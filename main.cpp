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

    f.insert(std::pair<int, int>(0, 1));
    f.insert(std::pair<int, int>(1, 2));
    f.insert(std::pair<int, int>(2, 3));

    it = f.begin();
    std::cout << it->second << std::endl;
    ++it;
    std::cout << it->second << std::endl;
}