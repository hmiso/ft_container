/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:31:11 by hmiso             #+#    #+#             */
/*   Updated: 2021/06/05 15:53:19 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
# include <typeinfo>
# include <sstream>
#include <memory>
#include "Allocator.hpp"
#include "iterator/vectorIterator.hpp"

namespace ft{

		template < class T, class Alloc = std::allocator<T> >  class vector{
			public:
			typedef T 															value_type;
			typedef Alloc														allocator_type;
			typedef T&															reference;
			typedef const T&													const_reference;
			typedef T*															pointer;
			typedef const T*													const_pointer;
			typedef vectorIterator<T>											iterator;
			typedef vectorIterator<T>											const_iterator;
			typedef RevvectorIterator<T>										reverse_iterator;
			typedef RevvectorIterator<T>										const_reverse_iterator;
			typedef ptrdiff_t 													difference_type;
			typedef size_t														size_type;
			private:
			T		*ptr;
			size_t	size_vecror;
			size_t	capacity_vector;
			allocator_type	alloc;
			public:
			explicit vector (const allocator_type& alloc = allocator_type()){
				this->alloc = alloc;
				this->size_vecror = 0;
				this->capacity_vector = 0;
				this->ptr = 0;
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				size_t count = 0;
				this->alloc = alloc;
				this->size_vecror = n;
				this->capacity_vector = n;
				this->ptr = new value_type[n];
				while (count < n){
					this->ptr[count] = val;
					count++;
				}
				
			}

			vector (iterator first, iterator last, const allocator_type& alloc = allocator_type()){
				this->alloc = alloc;
				this->size_vecror = last - first;
				this->capacity_vector = last - first;
				this->ptr = new value_type[this->capacity_vector];
				this->assign(first, last);
			}
			vector (const vector& x){
				this->alloc = alloc;
				this->size_vecror = x.size();
				this->capacity_vector = x.capacity();
				this->ptr = new value_type[x.capacity()];
				this->assign(x.begin(), x.end());
			}

			~vector(){
				if (this->ptr){
					delete[] this->ptr;
					this->ptr = NULL;
				}
			}
			
			vector& operator= (const vector& x){
				if (this->ptr){
					delete[] this->ptr;
					this->ptr = NULL;
				}
				this->ptr = new T[x.capacity_vector];
				this->size_vecror = x.size_vecror;
				this->capacity_vector = x.capacity_vector;
				this->assign(x.begin(), x.end());
				return *this;
			}
			
			iterator begin(){
				return iterator(this->ptr);
			}
			const_iterator begin() const{
				return const_iterator(this->ptr);
			}
			iterator end(){
				return iterator(this->ptr + this->size_vecror);
			}
			const_iterator end() const{
				return const_iterator(this->ptr + this->size_vecror);
			}
			reverse_iterator rbegin(){
				return reverse_iterator(this->ptr + this->size_vecror - 1);
			}
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(this->ptr + this->size_vecror - 1);
			}
			reverse_iterator rend(){
				return reverse_iterator(this->ptr - 1);
			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(this->ptr - 1);
			}
			size_type size() const{
				return this->size_vecror;
			}
			size_type max_size() const{
				return (allocator_type().max_size());
			}
			void resize (size_type n, value_type val = value_type()){
				while (n < this->size_vecror)
					this->pop_back();
				if (n > this->capacity_vector)
				{
					this->reserve(n);
				}
				while (n > this->size_vecror)
					this->push_back(val);				
			}
			size_type capacity() const{
				return this->capacity_vector;
			}
			bool empty() const{
				if (this->size_vecror == 0){
					return true;
				} else {
					return false;
				}
			}
			void reserve (size_type n){
				if (this->capacity_vector >= n){
					return ;
				}
				T *temp = new value_type[n];
				size_t count = 0;
				while (this->size_vecror > count){
					temp[count] = this->ptr[count];
					count++;
				}
				if (this->ptr) {
					delete[] this->ptr;
					this->ptr = NULL;
				}
				this->ptr = temp;
				this->capacity_vector = n;
			}

			reference operator[] (size_type n){
				return this->ptr[n];
			}
			const_reference operator[] (size_type n) const{
				return this->ptr[n];
			}

			reference at (size_type n){
				if (n > this->size_vecror){
					throw (std::out_of_range("error"));
				} else {
					return this->ptr[n];
				}
			}
			const_reference at (size_type n) const{
				if (n > this->size_vecror){
					throw (std::out_of_range("error"));
				} else {
					return this->ptr[n];
				}
			}

			reference front(){
				return this->ptr[0];
			}
			const_reference front() const{
				return this->ptr[0];
			}

			reference back(){
				return this->ptr[this->size_vecror - 1];
			}
			const_reference back() const{
				return this->ptr[this->size_vecror - 1];
			}

			void assign (iterator first, iterator last){
				if (this->capacity_vector < last - first){
					delete[] this->ptr;
					this->ptr = NULL;
					this->ptr = new value_type[size_t(last - first)];
					this->capacity_vector = last - first;
					this->size_vecror = 0;
				} else {
					this->clear();
				}
				while (first != last) {
					this->push_back(*first);
					++first;
				}	
			}	
			void assign (size_type n, const value_type& val){
				size_t count = 0;
				if (this->capacity_vector < n) {
					delete[] this->ptr;
					this->ptr = NULL;
					this->ptr = new value_type[n];
					this->capacity_vector = n;
					this->size_vecror = 0;
				} else {
					this->clear();
				}
				while (count < n){
					this->push_back(val);
					count++;
				}
			}

			void push_back (const value_type& val){
				if (this->size_vecror == this->capacity_vector) 
				{
					if (this->size_vecror == 0)
						this->reserve(1);
					else
					{
						this->reserve(this->size_vecror * 2);
					}
				}
				this->ptr[this->size_vecror] = val;
				this->size_vecror++;
			}
			void pop_back(){
				if (this->size_vecror){
					this->size_vecror--;
				}
			}
			
			iterator insert (iterator position, const value_type& val){
				size_type n = (position - this->begin());
				vector temp(position, this->end());
				this->size_vecror = this->end() - position -1;
				this->push_back(val);
				iterator start = temp.begin();
				iterator end = temp.end();
				while (start != end){
					this->push_back(*start);
					++start;
				}
				return (iterator(&this->ptr[n]));
			}
			void insert (iterator position, size_type n, const value_type& val){
				vector temp(position, this->end());
				vector temp_to(this->begin(), position);
				size_t new_sise = this->end() - position;
				size_t count = position - this->begin();
				if (this->capacity_vector < this->size_vecror + n){
					delete[] this->ptr;
					this->ptr = NULL;
					this->ptr = new value_type[this->size_vecror + n];
					this->capacity_vector = this->size_vecror + n;
					this->size_vecror = 0;
					for(size_type q = 0; q < count; q++){
						this->push_back(temp_to[q]);
					}
				}
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
				iterator it_begin = temp.begin();
				iterator it_end = temp.end();
				while (it_begin != it_end)
				{
					this->push_back(*it_begin);
					++it_begin;
				}
			}
			void insert (iterator position, iterator first, iterator last){
				vector temp(position, this->end());
				vector temp_to(this->begin(), position);
				this->size_vecror -= (this->end() - position);
				size_t count = position - this->begin();
				if (this->capacity_vector < (this->size_vecror + size_t(last - first))){
					delete[] this->ptr;
					this->ptr = NULL;
					this->ptr = new value_type[(this->size_vecror + size_t(last - first))];
					this->capacity_vector = this->size_vecror + size_t(last - first);
					this->size_vecror = 0;
					for(size_type q = 0; q < count; q++){
						this->push_back(temp_to[q]);
					}				
				}
				while (first != last) 
				{
					push_back(*first);
					++first;
				}
				iterator it_begin = temp.begin();
				iterator it_end = temp.end();
				while (it_begin != it_end)
				{
					this->push_back(*it_begin);
					++it_begin;
				}				
			}

			iterator erase (iterator position){
				iterator temp(position);
				iterator end = this->end() - 1;
				while (position != end)
				{
					*position = *(position + 1);
					++position;
				}
				this->size_vecror--;
				return (temp);				
			}
			iterator erase (iterator first, iterator last){
				iterator temp(last);
				iterator it_end = this->end();
				while (last != it_end)
				{
					*first = *last;
					++first;
					++last;
				}
				this->size_vecror -= (last - first);
				return (temp);
			}

			void swap (vector& x){
				vector<T> temp = *this;
				*this = x;
				x = temp;
			}
			void clear(){
				while (this->size_vecror){
					this->pop_back();
				}
				
			}
		};

template <class T, class Alloc>
  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	if (lhs.size() - rhs.size())
			return false;
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return false;
	return true;
  }

template <class T, class Alloc>
  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (!(lhs == rhs))
			return true;
		return false;	  
  }

template <class T, class Alloc>
  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	typename ft::vector<T, Alloc>::const_iterator first_1 = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator last_1 = lhs.end();
	typename ft::vector<T, Alloc>::const_iterator first_2 = rhs.begin();
	typename ft::vector<T, Alloc>::const_iterator last_2 = rhs.end();

	while (first_1 != last_1)
	{
		if (first_2 == last_2 || *first_2 < *first_1)
			return (false);
		else if (*first_1 < *first_2)
			return (true);
		++first_1;
		++first_2;
	}
	return (first_2 != last_2);
  }

template <class T, class Alloc>
  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	  	if (!(rhs < lhs))
			return (true);
		return (false);

  }

template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
	if (rhs < lhs)
		return (true);
	return (false);
  }

template <class T, class Alloc>
  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (!(lhs < rhs))
			return (true);
		return (false);	  
  }


template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
	vector<T,Alloc> temp = x;
	x = y;
	y = temp;
}


// // ????????
// template < class T, class Alloc = allocator<T> > class vector; // generic template
// template <class Alloc> class vector<bool,Alloc>;               // bool specialization		
};


