/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 07:17:12 by hmiso             #+#    #+#             */
/*   Updated: 2021/04/23 07:33:53 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <memory>
#include "iterator"

template <typename T, typename Pointer, typename Reference>
class BidirectIt
{
public:
	typedef ptrdiff_t 		difference_type;
	typedef T		 		value_type;
	typedef T*				pointer;
	typedef T&				reference;
};


template <typename T, typename Pointer, typename Reference>
class RevBidirectIt
{
public:
	typedef ptrdiff_t 		difference_type;
	typedef T		 		value_type;
	typedef T*				pointer;
	typedef T&				reference;
};
