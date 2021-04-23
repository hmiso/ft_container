/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:31:11 by hmiso             #+#    #+#             */
/*   Updated: 2021/04/06 21:36:11 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <memory>


namespace ft{
		template<class T, class Alloc = std::allocator<T> > class vector{
			typedef T 							value_type;
			typedef Alloc						allocator_type;
			typedef T&							reference;
			typedef const T&					const_reference;
			typedef T*							pointer;
			typedef const T*					const_pointer;
			
		};
};