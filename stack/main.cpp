#include <stack>
#include <iostream>
#include "stack.hpp"

template <class _Stack>
void stack_print(_Stack copy, const std::string& prefix = "STACK") {
    std::cout << prefix << ":";
    while (!copy.empty()) {
        std::cout << " " << copy.top();
        copy.pop();
    }
    std::cout << std::endl;
}

void test_ft_constructor()
{
    ft::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    stack_print(s, "s contains");

    ft::stack<int> s1(s);
    stack_print(s1, "s1 contains");

    ft::stack<int> s2;
    s2 = s1;
    stack_print(s2, "s2 contains");
    std::cout << std::endl;
}

void test_std_constructor()
{
    std::stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    stack_print(s, "s contains");

    std::stack<int> s1(s);
    stack_print(s1, "s1 contains");

    std::stack<int> s2;
    s2 = s1;
    stack_print(s2, "s2 contains");
    std::cout << std::endl;
}

void test_ft_top_empty_size()
{
    ft::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "s TOP(): " << s.top() << std::endl;
    std::cout << "s EMPTY()" << s.empty() << std::endl;
    std::cout << "s SIZE(): " << s.size() << std::endl;

    ft::stack<int> s1;

    // Calling back on an empty container causes undefined behavior.
    // std::cout << "s1 TOP(): " << s1.top() << std::endl;
    std::cout << "s1 EMPTY()" << s1.empty() << std::endl;
    std::cout << "s1 SIZE(): " << s1.size() << std::endl;
    std::cout << std::endl;
}

void test_std_top_empty_size()
{
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "TOP(): " << s.top() << std::endl;
    std::cout << "EMPTY(): " << s.empty() << std::endl;
    std::cout << "SIZE(): " << s.size() << std::endl;

    std::stack<int> s1;
    // Calling back on an empty container causes undefined behavior.
    // std::cout << "s1 TOP(): " << s1.top() << std::endl;
    std::cout << "s1 EMPTY(): " << s1.empty() << std::endl;
    std::cout << "s1 SIZE(): " << s1.size() << std::endl;
    std::cout << std::endl;
}

void test_ft_push_pop()
{
    ft::stack<char> s;
    s.push('a');
    s.push('b');
    s.push('v');
    s.push('v');
    s.push('p');
    stack_print(s, "s contains");
    s.pop();
    s.pop();
    stack_print(s, "after pop");
}

void test_std_push_pop()
{
    std::stack<std::string> s;
    s.push("a");
    s.push("b");
    s.push("v");
    s.push("v");
    s.push("p");
    stack_print(s, "s contains");
    s.pop();
    s.pop();
    stack_print(s, "after pop");
}

void test_ft_operators()
{
    ft::stack<int> s;
    for (int i = 1; i < 6; ++i)
        s.push(i);
    ft::stack<int> s1(s);
    ft::stack<int> s2;
    for (int i = 10; i < 16; ++i)
        s2.push(i);
    stack_print(s, "s contains");
    stack_print(s1, "s1 contains");
    stack_print(s2, "s2 contains");

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
    std::stack<int> s;
    for (int i = 1; i < 6; ++i)
        s.push(i);
    std::stack<int> s1(s);
    std::stack<int> s2;
    for (int i = 10; i < 16; ++i)
        s2.push(i);
    stack_print(s, "s contains");
    stack_print(s1, "s1 contains");
    stack_print(s2, "s2 contains");

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
    test_ft_top_empty_size();
    test_std_top_empty_size();
    test_ft_push_pop();
    test_std_push_pop();
    test_ft_operators();
    test_std_operators();
}