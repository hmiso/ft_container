#pragma once

#include <memory>

#include "Allocator.hpp"
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> > class stack{
		typedef T						value_type;
		typedef	Container				container_type;
		typedef	size_t					size_type;

		container_type container;

		explicit stack (const container_type& ctnr = container_type()){}
		bool empty() const{}
		size_type size() const{}
		value_type& top(){}
		const value_type& top() const{}
		void push (const value_type& val){}
		void pop();
	};

template <class T, class Container>
  bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template <class T, class Container>
  bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template <class T, class Container>
  bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template <class T, class Container>
  bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template <class T, class Container>
  bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template <class T, class Container>
  bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);
}