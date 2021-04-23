/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:31:11 by hmiso             #+#    #+#             */
/*   Updated: 2021/04/23 08:36:56 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <memory>
#include "Allocator.hpp"
#include "iterator/RamdomIT.hpp"

namespace ft{

		template < class T, typename ALLoc = allocator<T> >  class vector{
			typedef T 															value_type;
			typedef Alloc														allocator_type;
			typedef T&															reference;
			typedef const T&													const_reference;
			typedef T*															pointer;
			typedef const T*													const_pointer;
			typedef RamdomIT<value_type, pointer, reference>					iterator;
			typedef RamdomIT<value_type, const_pointer, const_reference>		const_iterator;
			typedef RevRamdomIT<value_type, pointer, reference>					reverse_iterator;
			typedef RevRamdomIT<value_type, const_pointer, const_reference>		const_reverse_iterator;
			typedef ptrdiff_t 													difference_type;
			typedef size_t														size_type;

			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class iterator>
			vector (iterator first, iterator last, const allocator_type& alloc = allocator_type());
			vector (const vector& x);

			~vector();
			
			vector& operator= (const vector& x);
			
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			size_type size() const;
			size_type max_size() const;
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve (size_type n);

			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;

			reference at (size_type n);
			const_reference at (size_type n) const;

			reference front();
			const_reference front() const;

			reference back();
			const_reference back() const;


			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);
			void assign (size_type n, const value_type& val);

			void push_back (const value_type& val);
			void pop_back();
			
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);

			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			void swap (vector& x);
			void clear();
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


