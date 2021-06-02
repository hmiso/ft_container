/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:31:11 by hmiso             #+#    #+#             */
/*   Updated: 2021/06/02 18:56:29 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <memory>
#include "Allocator.hpp"
#include "iterator/vectorIterator.hpp"

namespace ft{

		template < class T, typename Alloc = std::allocator<T> >  class vector{
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
			size_t	size;
			size_t	capacity;
			allocator_type	allocator;

			explicit vector (const allocator_type& alloc = allocator_type()){
				this->allocator = alloc;
				this->size = 0;
				this->capacity = 0;
				this->ptr = 0;
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
				size_t count = 0;
				this->allocator = alloc;
				this->size = n;
				this->capacity = n;
				this->ptr = new value_type[n];
				while (count < n){
					this->ptr[count] = val;
					count++;
				}
				
			}

			vector (iterator first, iterator last, const allocator_type& alloc = allocator_type()){
				this->allocator = alloc;
				this->size = last - first;
				this->capacity = this->size;
				this->ptr = new value_type[this->capacity];
				this->assign(first, last);
			}
			vector (const vector& x);

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
				this->ptr = new T[x.capacity];
				this->size = x.size;
				this->capacity = x.capacity;
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
				return iterator(this->ptr + this->size);
			}
			const_iterator end() const{
				return const_iterator(this->ptr + this->size);
			}
			reverse_iterator rbegin(){
				return reverse_iterator(this->ptr + this->size - 1);
			}
			const_reverse_iterator rbegin() const{
				return const_reverse_iterator(this->ptr + this->size - 1);
			}
			reverse_iterator rend(){
				return reverse_iterator(this->ptr - 1);
			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(this->ptr - 1);
			}
			size_type size() const{
				return this->size;
			}
			size_type max_size() const{
				return std::numeric_limits<T>::max() / sizeof(T);
			}
			void resize (size_type n, value_type val = value_type()){
				
			}
			size_type capacity() const{
				return this->capacity;
			}
			bool empty() const{
				if (this->size == 0){
					return true;
				} else {
					return false;
				}
			}
			void reserve (size_type n){
				if (this->capacity >= n){
					return ;
				}
				T *temp = new value_type[n];
				size_t count = 0;
				while (this->size > count){
					temp[count] = this->ptr[count];
					count++;
				}
				if (this->ptr) {
					delete[] this->ptr;
					this->ptr = NULL;
				}
				this->ptr = temp;
				this->capacity = n;
			}

			reference operator[] (size_type n){
				return this->ptr[n];
			}
			const_reference operator[] (size_type n) const{
				return this->ptr[n];
			}

			reference at (size_type n){
				if (n > this->size){
					throw (std::out_of_range('vector::_M_range_check: __n (which is' + std::to_string(n) + ') >= this->size() (which is' + std::to_string(this->size) +')'));
				} else {
					return this->ptr[n];
				}
			}
			const_reference at (size_type n) const{
				if (n > this->size){
					throw (std::out_of_range('vector::_M_range_check: __n (which is' + std::to_string(n) + ') >= this->size() (which is' + std::to_string(this->size) +')'));
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
				return this->ptr[this->size - 1];
			}
			const_reference back() const{
				return this->ptr[this->size - 1];
			}

			void assign (iterator first, iterator last){
				this->clear();
				while (first != last) {
					this->push_back(*first);
					++first;
				}	
			}
			void assign (const_iterator first, const_iterator last){
				this->clear();
				while (first != last) {
					this->push_back(*first);
					++first;
				}
			}			
			void assign (size_type n, const value_type& val){
				size_t count = 0;
				this->clear();
				while (count < n){
					this->push_back(val);
					count++;
				}
			}

			void push_back (const value_type& val){
				if (this->capacity == 0){
					this->ptr = new value_type[1];
					this->size = 1;
					this->capacity = 1;
					this->ptr[0] = val;
				} else if (this->capacity = 1){
					T *temp = new value_type[2];
					temp[0] = ptr[0];
					temp[1] = val;
					this->size = 2;
					this->capacity = 2;
					delete[] this->ptr;
					this->ptr = temp;
				} else {
					if (this->size < this->capacity){
						this->ptr[this->size - 1] = val;
						this->size++;
					} else {
						size_t count = 0;
						if (this->capacity * 2 < this->max_size() / 2){
							count = this->capacity * 2;
						} else {
							count = this->capacity + 1000;
						}
						T *temp = new value_type[count];
						count = 0;
						this->capacity = count;
						while (count < this->size)
						{
							temp[count] = ptr[count];
							count++;
						}
						temp[count] = val;
						this->size++;
						delete[] this->ptr;
						this->ptr = temp;
					}
				}
			}
			void pop_back(){
				this->size--;
				this->allocator.destroy(ptr[this->size]);
			}
			
			iterator insert (iterator position, const value_type& val){
				size_t count = position - this->begin();
				insert(position, 1, val);
				return (iterator(&this->ptr[count]));
			}
			void insert (iterator position, size_type n, const value_type& val){
				T *temp
			}
			void insert (iterator position, iterator first, iterator last){
				
			}

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);
			void clear(){
				while (this->size){
					this->pop_back();
				}
			}
		};

template <class T, class Alloc>
  bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);


template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


// ????????
template < class T, class Alloc = allocator<T> > class vector; // generic template
template <class Alloc> class vector<bool,Alloc>;               // bool specialization		
};


