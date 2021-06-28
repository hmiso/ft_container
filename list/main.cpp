#include <iostream>
#include <list>

#include "list.hpp"


template <typename Container>
void print(Container& c, const std::string& prefix = "LIST")
{
    typename Container::iterator first = c.begin();
    typename Container::iterator second = c.end();

    std::cout << prefix << ": ";
    std::cout << "sz = " << c.size() << ", ";
    std::cout << "data = [ ";
    while (first != second)
	{
        std::cout << *first << " ";
		first++;
	}
    std::cout << "]" << std::endl;
}

bool compare(const int& value)
{
    return value > 1;
}

template<typename T>
struct pred
{
    bool operator()(const T& a, const T& b) {return a == b;}
};

void test_ft_constructors()
{
    std::cout << std::endl;
    std::cout << "*** DEFAULT FT CONSTRUCTOR ***" << std::endl;

    ft::list<int> l;
    std::cout << "empty(): " << l.empty() << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << std::endl;

    std::cout << "*** FILL FT CONSTRUCTOR ***" << std::endl;

    ft::list<int> l1(5, 10);
    print(l1);
    std::cout << std::endl;

    std::cout << "*** COPY FT CONSTRUCTOR ***" << std::endl;
    ft::list<int> l2(l1);
    print(l2);
    std::cout << std::endl;

    std::cout << "*** RANGE FT CONSTRUCTOR ***" << std::endl;
    ft::list<int> l3(l2.begin(), l2.end());
    print(l3);
}

void test_std_constructors()
{
    std::cout << std::endl;
    std::cout << "*** DEFAULT STD CONSTRUCTOR ***" << std::endl;

    std::list<int> l;
    std::cout << "empty(): " << l.empty() << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << std::endl;

    std::cout << "*** FILL STD CONSTRUCTOR ***" << std::endl;

    std::list<int> l1(5, 10);
    print(l1);
    std::cout << std::endl;

    std::cout << "*** COPY STD CONSTRUCTOR ***" << std::endl;
    std::list<int> l2(l1);
    print(l2);
    std::cout << std::endl;

    std::cout << "*** RANGE STD CONSTRUCTOR ***" << std::endl;
    std::list<int> l3(l2.begin(), l2.end());
    print(l3);
}

void test_ft_assignment_operator()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<std::string> l;
    l.push_back("HELLO");
    print(l);
    ft::list<std::string> l1 = l;
    print(l1);

    ft::list<int> l2(3, 10);
    ft::list<int> l3;
    l3 = l2;
    print(l2, "l2");
    print(l3, "l3");
}

void test_std_assignment_operator()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<std::string> l;
    l.push_back("HELLO");
    print(l, "l");
    std::list<std::string> l1 = l;
    print(l1, "l1");

    std::list<int> l2(3, 10);
    std::list<int> l3(4, 2);
    l3 = l2;
    print(l2, "l2");
    print(l3, "l3");
}

void test_ft_assign()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<std::string>   l(10, "a");
    print(l, "before");
    l.assign(5, "b");
    print(l, "after");
    std::cout << std::endl;

    ft::list<std::string>   l1(6, "hru hru");
    print(l1, "l1");
    ft::list<std::string>::iterator first = l1.begin();
    ft::list<std::string>::iterator  last = l1.end();
    l.assign(first, ----last);
    print(l, "l");
}

void test_std_assign()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<std::string>   l(10, "a");
    print(l, "before");
    l.assign(5, "b");
    print(l, "after");
    std::cout << std::endl;

    std::list<std::string>   l1(6, "hru hru");
    print(l1, "l1");
    std::list<std::string>::iterator first = l1.begin();
    std::list<std::string>::iterator  last = l1.end();
    l.assign(first, ----last);
    print(l, "l");
}

void test_ft_front_back()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<char> letters;
    letters.push_back('o');
    letters.push_back('k');
    if (!letters.empty())
    {
        std::cout << "The first character is '" << letters.front() << "'" << std::endl;
        std::cout << "The last character is '" << letters.back() << "'" << std::endl;
    }
    std::cout << std::endl;
}

void test_std_front_back()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<char> letters;
    letters.push_back('o');
    letters.push_back('k');
    if (!letters.empty())
    {
        std::cout << "The first character is '" << letters.front() << "'" << std::endl;
        std::cout << "The last character is '" << letters.back() << "'" << std::endl;
    }
    std::cout << std::endl;
}

void test_ft_sizes()
{
    std::cout << std::endl;
    std::cout << "*** FT ***" << std::endl << std::endl;

    ft::list<int> l;
    std::cout << "empty(): " << l.empty() << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "max_size(): " << l.max_size() << std::endl << std::endl;
}

void test_std_sizes()
{
    std::cout << std::endl;
    std::cout << "*** STD ***" << std::endl << std::endl;

    std::list<int> l;
    std::cout << "empty(): " << l.empty() << std::endl;
    std::cout << "size(): " << l.size() << std::endl;
    std::cout << "max_size(): " << l.max_size() << std::endl << std::endl;
}

void test_ft_clear()
{
    std::cout << std::endl;
    std::cout << "*** FT ***" << std::endl << std::endl;

    ft::list<std::string> l(5, "s");
    print(l, "before clear");
    l.clear();
    print(l, "after clear");
}

void test_std_clear()
{
    std::cout << std::endl;
    std::cout << "*** STD ***" << std::endl << std::endl;

    std::list<std::string> l(5, "s");
    print(l, "before clear");
    l.clear();
    print(l, "after clear");
}

void test_ft_insert()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l;
    for (int i = 1; i < 11; ++i)
        l.push_back(i);
    ft::list<int>::iterator l_first = l.begin();
    print(l, "before");
    l.insert(++++++++l_first, 100);
    print(l, "after first insert");
    std::cout << std::endl;

    ft::list<int> l1(3, 50);
    l_first = l.begin();
    l.insert(l_first, l1.begin(), --l1.end());
    print(l, "after second insert");
    std::cout << std::endl;

    l.insert(l.end(), 3, 11);
    print(l, "after third insert");
    std::cout << std::endl;

}

void test_std_insert()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l;
    for (int i = 1; i < 11; ++i)
        l.push_back(i);
    std::list<int>::iterator l_first = l.begin();
    print(l, "before");
    l.insert(++++++++l_first, 100);
    print(l, "after first insert");
    std::cout << std::endl;

    std::list<int> l1(3, 50);
    l_first = l.begin();
    l.insert(l_first, l1.begin(), --l1.end());
    print(l, "after second insert");
    std::cout << std::endl;

    l.insert(l.end(), 3, 11);
    print(l, "after third insert");
    std::cout << std::endl;
}

void test_ft_erase()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l;
    for (int i = 1; i < 11; ++i)
        l.push_back(i);
    print(l, "before");
    ft::list<int>::iterator it = l.begin();
    it = l.erase(++it);
    print(l, "erase 2nd elem");
    std::cout << std::endl;

    l.erase(++it, l.end());
    print(l, "erase from 2nd elem till end");
}

void test_std_erase()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l;
    for (int i = 1; i < 11; ++i)
        l.push_back(i);
    print(l, "before");
    std::list<int>::iterator it = l.begin();
    it = l.erase(++it);
    print(l, "erase 2nd elem");
    std::cout << std::endl;

    l.erase(++it, l.end());
    print(l, "erase from 2nd elem till end");
}

void test_ft_push_pop_back()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l;
    for (int i = 1; i < 30; ++i)
        l.push_back(i);
    print(l, "before");

    ft::list<int>::iterator it = l.begin();
    ft::list<int>::iterator it1 = l.end();
    while (l.size())
        l.pop_back();
    print(l, "after pop_back()");
}

void test_std_push_pop_back()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l;
    for (int i = 1; i < 30; ++i)
        l.push_back(i);
    print(l, "before");



    while (l.size())
        l.pop_back();
    print(l, "after pop_front()");
}

void test_ft_push_pop_front()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l;
    for (int i = 1; i < 30; ++i)
        l.push_front(i);
    print(l, "before");

    ft::list<int>::iterator it = l.begin();
    while (it++ != --l.end())
        l.pop_front();
    print(l, "after pop_front()");
}

void test_std_push_pop_front()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l;
    for (int i = 1; i < 30; ++i)
        l.push_front(i);
    print(l, "before");

    std::list<int>::iterator it = l.begin();
    while (it++ != --l.end())
        l.pop_front();
    print(l, "after pop_front()");
}

void test_ft_splice()
{
    std::cout << "*** FT SPLICE ***" << std::endl;
    ft::list<int> l(6, 100);
    ft::list<int> l1;
    for (int i = 1; i < 7; ++i)
        l1.push_back(i);
    print(l, "l ");
    print(l1, "l1");
    l.splice((l.end()), l1);
    print(l, "l ");
    print(l1, "l1");
    std::cout << std::endl;
}

void test_std_splice()
{
    std::cout << "*** STD SPLICE ***" << std::endl;
    std::list<int> l(6, 100);
    std::list<int> l1;
    for (int i = 1; i < 7; ++i)
        l1.push_back(i);
    print(l, "l ");
    print(l1, "l1");
    l.splice((l.end()), l1);
    print(l, "l ");
    print(l1, "l1");
    std::cout << std::endl;
}

void test_ft_resize()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l(2, 6);
    print(l, "The list holds");
    l.resize(5);
    print(l, "After resize up to 5");
    l.resize(2);
    print(l, "After resize down to 2");
    std::cout << std::endl;
}

void test_std_resize()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l(2, 6);
    print(l, "The list holds");
    l.resize(5);
    print(l, "After resize up to 5");
    l.resize(2);
    print(l, "After resize down to 2");
    std::cout << std::endl;
}

void test_ft_merge()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> list1;
    list1.push_back(5);
    list1.push_back(9);
    list1.push_back(0);
    list1.push_back(1);
    list1.push_back(3);
    ft::list<int> list2;
    list2.push_back(8);
    list2.push_back(7);
    list2.push_back(2);
    list2.push_back(6);
    list2.push_back(4);
 
    list1.sort();
    list2.sort();
    print(list1, "list1 sorted");
    print(list2, "list2 sorted");
    list1.merge(list2);
    print(list1, "merged");
}

void test_std_merge()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> list1;
    list1.push_back(5);
    list1.push_back(9);
    list1.push_back(0);
    list1.push_back(1);
    list1.push_back(3);
    std::list<int> list2;
    list2.push_back(8);
    list2.push_back(7);
    list2.push_back(2);
    list2.push_back(6);
    list2.push_back(4);
 
    list1.sort();
    list2.sort();
    print(list1, "list1 sorted");
    print(list2, "list2 sorted");
    list1.merge(list2);
    print(list1, "merged");
}

void test_ft_remove()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l;
    for (int i = 1; i < 6; ++i)
        l.push_back(i);
    print(l, "list contains");
    l.remove(4);
    print(l, "remove 4");
    ft::list<int> l1;
    print(l1, "empty list");
    l1.remove(1);
    print(l1);

    l.remove_if(compare);
}

void test_std_remove()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l;
    for (int i = 1; i < 6; ++i)
        l.push_back(i);
    print(l, "list contains");
    l.remove(4);
    print(l, "remove 4");
    ft::list<int> l1;
    print(l1, "empty list");
    l1.remove(1);
    print(l1);
    l.remove_if(compare);
}

void test_ft_reverse()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l1;
    for (int i = 1; i < 11; ++i)
        l1.push_back(i);
    print(l1, "list contains");
    l1.reverse();
    print(l1, "reversed");

}

void test_std_reverse()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l1;
    for (int i = 1; i < 11; ++i)
        l1.push_back(i);
    print(l1, "list contains");
    l1.reverse();
    print(l1, "reversed");
}

void test_ft_swap()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l(5, 30);
    ft::list<int> l1(2, 10);
    print(l, "list l contains");
    print(l1, "list l1 contains");
    l.swap(l1);
    print(l, "after swap l contains");
    print(l1, "after swap l1 contains");
}

void test_std_swap()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l(5, 30);
    std::list<int> l1(2, 10);
    print(l, "list l contains");
    print(l1, "list l1 contains");
    l.swap(l1);
    print(l, "after swap l contains");
    print(l1, "after swap l1 contains");
}

void test_ft_unique()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int>   l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(2);
    print(l, "list contains");
    l.unique();
    print(l, "contains after unique");

    l.unique(pred<int>());
    print(l, "predicate");
}

void test_std_unique()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int>   l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(2);
    print(l, "list contains");
    l.unique();
    print(l, "contains after unique");

    l.unique(pred<int>());
    print(l, "predicate");
}

void test_ft_sort()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> l;
    l.push_back(10);
    l.push_back(7);
    l.push_back(3);
    l.push_back(5);
    l.push_back(8);
    l.push_back(9);
    l.push_back(1);
    l.push_back(4);
    l.push_back(6);
    l.push_back(2);
    print(l, "list contains");
    l.sort();
    print(l, "after sort");

    ft::list<std::string> l1;
    l1.push_back("o");
    l1.push_back("a");
    l1.push_back("i");
    print(l1, "l1 contains");
    l1.sort(std::less<std::string>());
    print(l1, "after sort");

}

void test_std_sort()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> l;
    l.push_back(10);
    l.push_back(7);
    l.push_back(3);
    l.push_back(5);
    l.push_back(8);
    l.push_back(9);
    l.push_back(1);
    l.push_back(4);
    l.push_back(6);
    l.push_back(2);
    print(l, "list contains");
    l.sort();
    print(l, "after sort");

    std::list<std::string> l1;
    l1.push_back("o");
    l1.push_back("a");
    l1.push_back("i");
    print(l1, "l1 contains");
    l1.sort(std::less<std::string>());
    print(l1, "after sort");

}

void test_ft_operators()
{
	std::cout << "*** FT ***" << std::endl << std::endl;
    ft::list<int> lst;
    for (int i = 1; i < 4; ++i)
        lst.push_back(i);
    ft::list<int> lst2(4, 3);
    ft::list<int> lst3(lst);
    print(lst, "lst contains");
    print(lst2, "lst2 contains");
    print(lst3, "lst3 contains");

    std::cout << "Compare non equal containers" << std::endl;
    std::cout << "lst == lst2 returns " << (lst == lst2) << std::endl;
    std::cout << "lst != lst2 returns " << (lst != lst2) << std::endl;
    std::cout << "lst <  lst2 returns " << (lst < lst2) << std::endl;
    std::cout << "lst <= lst2 returns " << (lst <= lst2) << std::endl;
    std::cout << "lst >  lst2 returns " << (lst > lst2) << std::endl;
    std::cout << "lst >= lst2 returns " << (lst >= lst2) << std::endl;

    std::cout << "Compare equal containers" << std::endl;
    std::cout << "lst == lst3 returns " << (lst == lst3) << std::endl;
    std::cout << "lst != lst3 returns " << (lst != lst3) << std::endl;
    std::cout << "lst <  lst3 returns " << (lst < lst3) << std::endl;
    std::cout << "lst <= lst3 returns " << (lst <= lst3) << std::endl;
    std::cout << "lst >  lst3 returns " << (lst > lst3) << std::endl;
    std::cout << "lst >= lst3 returns " << (lst >= lst3) << std::endl;
}

void test_std_operators()
{
	 std::cout << "*** STD ***" << std::endl << std::endl;
    std::list<int> lst;
    for (int i = 1; i < 4; ++i)
        lst.push_back(i);
    std::list<int> lst2(4, 3);
    std::list<int> lst3(lst);
    print(lst, "lst contains");
    print(lst2, "lst2 contains");
    print(lst3, "lst3 contains");

    std::cout << "Compare non equal containers" << std::endl;
    std::cout << "lst == lst2 returns " << (lst == lst2) << std::endl;
    std::cout << "lst != lst2 returns " << (lst != lst2) << std::endl;
    std::cout << "lst <  lst2 returns " << (lst < lst2) << std::endl;
    std::cout << "lst <= lst2 returns " << (lst <= lst2) << std::endl;
    std::cout << "lst >  lst2 returns " << (lst > lst2) << std::endl;
    std::cout << "lst >= lst2 returns " << (lst >= lst2) << std::endl;

    std::cout << "Compare equal containers" << std::endl;
    std::cout << "lst == lst3 returns " << (lst == lst3) << std::endl;
    std::cout << "lst != lst3 returns " << (lst != lst3) << std::endl;
    std::cout << "lst <  lst3 returns " << (lst < lst3) << std::endl;
    std::cout << "lst <= lst3 returns " << (lst <= lst3) << std::endl;
    std::cout << "lst >  lst3 returns " << (lst > lst3) << std::endl;
    std::cout << "lst >= lst3 returns " << (lst >= lst3) << std::endl;
}

int main()
{
    test_ft_splice();
    test_std_splice();
    test_ft_sizes();
    test_std_sizes();
    test_ft_clear();
    test_std_clear();
    test_ft_constructors();
    test_std_constructors();
    test_ft_assignment_operator();
    test_std_assignment_operator();
    test_ft_assign();
    test_std_assign();
    test_ft_front_back();
    test_std_front_back();
    test_ft_insert();
    test_std_insert();
    test_ft_erase();
    test_std_erase();
    test_ft_push_pop_back();
    test_std_push_pop_back();
    test_ft_push_pop_front();
    test_std_push_pop_front();
    test_ft_resize();
    test_std_resize();
    test_ft_merge();
    test_std_merge();
    test_ft_remove();
    test_std_remove();
    test_ft_reverse();
    test_std_reverse();
    test_ft_swap();
    test_std_swap();
    test_ft_unique();
    test_std_unique();
    test_ft_sort();
    test_std_sort();
    test_ft_operators();
    test_std_operators();

}