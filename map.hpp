/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 09:20:55 by hmiso             #+#    #+#             */
/*   Updated: 2021/04/23 09:44:13 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Allocator.hpp"

#include "iostream"

namespace ft{
	
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = allocator<std::pair<const Key,T> > > class map{
	public:
		typedef Key													key_type;
		typedef T													mapped_type;
		typedef std::pair<const key_type,mapped_type>				value_type;
		typedef std::less<key_type>									key_compare;
		template <class Key, class T, class Compare, class Alloc>
		class map<Key,T,Compare,Alloc>::value_compare
		{  
			protected:
			Compare comp;
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
			public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
		}
		typedef Alloc												allocator_type;
		typedef T&													reference;
		typedef const T&											const_reference;
		typedef T*													pointer;
		typedef const T*											const_pointer;
		

	};
}