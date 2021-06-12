#pragma once

#include <memory>


#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> > class stack{
		public:
		typedef T						value_type;
		typedef	Container				container_type;
		typedef	size_t					size_type;

		Container container;

		explicit stack (const container_type& ctnr = container_type()){
			this->container = ctnr;
		}
		bool empty() const{
			return this->container.empty();
		}
		size_type size() const{
			return this->container.size();
		}
		value_type& top(){
			return this->container.back();
		}
		const value_type& top() const{
			return this->container.back();
		}
		void push (const value_type& val){
			this->container.push_back(val);
		}
		void pop(){
			this->container.pop_back();
		}
	};

template <class T, class Container>
  bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	  return lhs.container == rhs.container;
  }

template <class T, class Container>
  bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	  return lhs.container != rhs.container;
  }

template <class T, class Container>
  bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	  return lhs.container < rhs.container;
  }

template <class T, class Container>
  bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	  return lhs.container <= rhs.container;
  }

template <class T, class Container>
  bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	  return lhs.container > rhs.container;
  }

template <class T, class Container>
  bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs){
	  return lhs.container >= rhs.container;
  }
}