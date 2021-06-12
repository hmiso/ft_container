#pragma once

#include <memory>


#include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> > class queue{
		public:
			typedef T						value_type;
			typedef	Container				container_type;
			typedef	size_t					size_type;

			Container container;

			explicit queue(const container_type& ctnr = container_type()){
				this->container = ctnr;
			}
			bool empty() const{
				return this->container.empty();
			}
			size_type size() const{
				return this->container.size();
			}
			value_type& front(){
				return this->container.front();
			}
			const value_type& front() const{
				return this->container.front();
			}
			value_type& back(){
				return this->container.back();
			}
			const value_type& back() const{
				return this->container.back();
			}
			void push (const value_type& val){
				this->container.push_back(val);
			}
			void pop(){
				this->container.pop_front();
			}	
	};

template <class T, class Container>
  bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	  return lhs.container == rhs.container;
  }

template <class T, class Container>
  bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	  	  return lhs.container != rhs.container;
  }

template <class T, class Container>
  bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	  	  return lhs.container < rhs.container;
  }

template <class T, class Container>
  bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	  	  return lhs.container <= rhs.container;
  }

template <class T, class Container>
  bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	  	  return lhs.container > rhs.container;
  }

template <class T, class Container>
  bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs){
	  	  return lhs.container >= rhs.container;
  }
}
