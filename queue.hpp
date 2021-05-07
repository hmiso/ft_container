#pragma once

#include <memory>

#include "Allocator.hpp"
#include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> > class queue{
		public:
			typedef T						value_type;
			typedef	Container				container_type;
			typedef	size_t					size_type;

			container_type container;

			explicit queue(const container_type& ctnr = container_type()){
				this->container = ctnr;
			}
			bool empty() const{}
			size_type size() const{}
			value_type& front(){}
			const value_type& front() const{}
			value_type& back(){}
			const value_type& back() const{}
			void push (const value_type& val){}
			void pop(){}	
	};

template <class T, class Container>
  bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){}

template <class T, class Container>
  bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){}

template <class T, class Container>
  bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){}

template <class T, class Container>
  bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){}

template <class T, class Container>
  bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){}

template <class T, class Container>
  bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){}
}
