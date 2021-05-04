/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 07:13:59 by hmiso             #+#    #+#             */
/*   Updated: 2021/04/26 15:24:20 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <limits>

template <class T> class allocator{
public:	
	typedef T 					value_type;
	typedef T* 					pointer;
	typedef T& 					reference;
	typedef const T*			const_pointer;
	typedef const T&			const_reference;
	typedef std::size_t 		size_type;
	typedef std::ptrdiff_t 		difference_type; // разница между двумя указателями в модели распределениея - хз зачем, в методах не используется же

	allocator() throw(){} // зачем тут throw если указано что констуркторы ни чего не делают https://www.cplusplus.com/reference/memory/allocator/allocator/
	allocator (const allocator& alloc) throw(){} // указаны два констурктроа коипирования, один с шаблоном другой без, если я правильно понимаю alloc это функция
	// для выделния памяти исходя из этого вообще не могу понять как это работает
	template <class U>
	allocator (const allocator<U>& alloc) throw(){}
	~allocator () throw(){}

	pointer address (reference x) const{
		return (&x); //  нужно вернуть указатель на объект получив ссылку на объект
	}
	const_pointer address (const_reference x) const{
		return (&x); // выглядит как дикий бред, сомневаюсь что понял что я делаю
	}

	pointer allocate (size_type n){
		return reinterpret_cast<pointer>(::operator new (sizeof(this->T) * n)); // если памяыть не выделиться должно ли быть выбрашено исключение
	}
	void deallocate (pointer p, size_type n){
		::operator delete (p); // зачем мы сюда пердаем n в прототипе?
	}
	size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof(value_type);
	}
	void construct ( pointer p, const_reference val ){
		new(p) value_type(val); // тоже проблема с пониманием что тут происходит
	}
	void destroy (pointer p){
		p->~value_tupe(); // единственное что я понял :-)
	}
};