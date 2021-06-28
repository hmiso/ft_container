#include <queue>
#include <iostream>
#include "queue.hpp"

template <class _Queue>
void queue_print(_Queue copy, const std::string& prefix = "Queue") {
    std::cout << prefix << ":";
    while (!copy.empty()) {
        std::cout << " " << copy.front();
        copy.pop();
    }
    std::cout << std::endl;
}

void test_ft_constructor()
{
    ft::queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    queue_print(s, "s contains");

    ft::queue<int> s1(s);
    queue_print(s1, "s1 contains");

    ft::queue<int> s2;
    s2 = s1;
    queue_print(s2, "s2 contains");
    std::cout << std::endl;
}

void test_std_constructor()
{
    std::queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    queue_print(s, "s contains");

    std::queue<int> s1(s);
    queue_print(s1, "s1 contains");

    std::queue<int> s2;
    s2 = s1;
    queue_print(s2, "s2 contains");
    std::cout << std::endl;
}

void test_ft_back_front_empty_size()
{
    ft::queue<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "s FRONT(): " << s.front() << std::endl;
    std::cout << "s BACK(): " << s.back() << std::endl;
    std::cout << "s EMPTY(): " << s.empty() << std::endl;
    std::cout << "s SIZE(): " << s.size() << std::endl;

    ft::queue<int> s1;

    // Calling back on an empty container causes undefined behavior.
    // std::cout << "s1 BACK(): " << s1.back() << std::endl;
    std::cout << "s1 EMPTY()" << s1.empty() << std::endl;
    std::cout << "s1 SIZE(): " << s1.size() << std::endl;
    std::cout << std::endl;
}

void test_std_back_front_empty_size()
{
    std::queue<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "s FRONT(): " << s.front() << std::endl;
    std::cout << "BACK(): " << s.back() << std::endl;
    std::cout << "EMPTY(): " << s.empty() << std::endl;
    std::cout << "SIZE(): " << s.size() << std::endl;

    std::queue<int> s1;
    // Calling back on an empty container causes undefined behavior.
    // std::cout << "s1 BACK(): " << s1.back() << std::endl;
    std::cout << "s1 EMPTY(): " << s1.empty() << std::endl;
    std::cout << "s1 SIZE(): " << s1.size() << std::endl;
    std::cout << std::endl;
}

void test_ft_push_pop()
{
    std::queue<std::string> s;
    s.push("a");
    s.push("b");
    s.push("v");
    s.push("v");
    s.push("p");
    queue_print(s, "s contains");
    s.pop();
    s.pop();
    queue_print(s, "after pop");
}

void test_std_push_pop()
{
    std::queue<std::string> s;
    s.push("a");
    s.push("b");
    s.push("v");
    s.push("v");
    s.push("p");
    queue_print(s, "s contains");
    s.pop();
    s.pop();
    queue_print(s, "after pop");
}

void test_ft_operators()
{
    ft::queue<int> s;
    for (int i = 1; i < 6; ++i)
        s.push(i);
    ft::queue<int> s1(s);
    ft::queue<int> s2;
    for (int i = 10; i < 16; ++i)
        s2.push(i);
    queue_print(s, "s contains");
    queue_print(s1, "s1 contains");
    queue_print(s2, "s2 contains");

    std::cout << "Compare non equal containers" << std::endl;
    std::cout << "s == s2 returns " << (s == s2) << std::endl;
    std::cout << "s != s2 returns " << (s != s2) << std::endl;
    std::cout << "s <  s2 returns " << (s < s2) << std::endl;
    std::cout << "s <= s2 returns " << (s <= s2) << std::endl;
    std::cout << "s >  s2 returns " << (s > s2) << std::endl;
    std::cout << "s >= s2 returns " << (s >= s2) << std::endl;

    std::cout << "Compare equal containers" << std::endl;
    std::cout << "s == s1 returns " << (s == s1) << std::endl;
    std::cout << "s != s1 returns " << (s != s1) << std::endl;
    std::cout << "s <  s1 returns " << (s < s1) << std::endl;
    std::cout << "s <= s1 returns " << (s <= s1) << std::endl;
    std::cout << "s >  s1 returns " << (s > s1) << std::endl;
    std::cout << "s >= s1 returns " << (s >= s1) << std::endl;
}

void test_std_operators()
{
    std::queue<int> s;
    for (int i = 1; i < 6; ++i)
        s.push(i);
    std::queue<int> s1(s);
    std::queue<int> s2;
    for (int i = 10; i < 16; ++i)
        s2.push(i);
    queue_print(s, "s contains");
    queue_print(s1, "s1 contains");
    queue_print(s2, "s2 contains");

    std::cout << "Compare non equal containers" << std::endl;
    std::cout << "s == s2 returns " << (s == s2) << std::endl;
    std::cout << "s != s2 returns " << (s != s2) << std::endl;
    std::cout << "s <  s2 returns " << (s < s2) << std::endl;
    std::cout << "s <= s2 returns " << (s <= s2) << std::endl;
    std::cout << "s >  s2 returns " << (s > s2) << std::endl;
    std::cout << "s >= s2 returns " << (s >= s2) << std::endl;

    std::cout << "Compare equal containers" << std::endl;
    std::cout << "s == s1 returns " << (s == s1) << std::endl;
    std::cout << "s != s1 returns " << (s != s1) << std::endl;
    std::cout << "s <  s1 returns " << (s < s1) << std::endl;
    std::cout << "s <= s1 returns " << (s <= s1) << std::endl;
    std::cout << "s >  s1 returns " << (s > s1) << std::endl;
    std::cout << "s >= s1 returns " << (s >= s1) << std::endl;
}

int main()
{
    test_ft_constructor();
    test_std_constructor();
    test_ft_back_front_empty_size();
    test_std_back_front_empty_size();
    test_ft_push_pop();
    test_std_push_pop();
    test_ft_operators();
    test_std_operators();
}