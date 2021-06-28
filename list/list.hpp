/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:31:05 by hmiso             #+#    #+#             */
/*   Updated: 2021/06/27 21:12:00 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <memory>

# include <typeinfo>
# include <sstream>
#include "listIterator.hpp"
#include "node.hpp"

template<typename T>
bool Compare(const T &a, const T &b) {
	return (a < b);
}

namespace ft{
	template < typename T, typename Alloc = std::allocator<T> > class list{

	public:
		typedef T															value_type;
		typedef Alloc               										allocator_type; 
		typedef T&															reference;
		typedef const T&													const_reference;
		typedef T*															pointer;
		typedef const T*													const_pointer;
		typedef listIterator<T>												iterator;
		typedef ConstlistIterator<T>										const_iterator;
		typedef RevlistIterator<T>											reverse_iterator;
		typedef RevlistIterator<T>											const_reverse_iterator;
		typedef ptrdiff_t 													difference_type;
		typedef size_t														size_type;
		typedef typename allocator_type::template rebind<node<T> >::other   node_alloc;

		private:
		node<T> *current;
		allocator_type alloc;
		node<T> *start;
		size_t size_list;
		node_alloc		_nodalc;
		public:
					void					swap(list& x);
// конструкторы
		explicit list (const allocator_type& alloc = allocator_type()){
			this->alloc = alloc;
			this->size_list = 0;
			this->start = new node<T>;
			this->current = new node<T>;
			this->start->ptrNext = this->current;
			this->current->ptrPrevie = this->start;
		} // нужно для неявного преобразования если мы передадим не то значение 
		// хз вообще что это Создает пустой контейнер без элементов. https://www.cplusplus.com/reference/list/list/empty/
		explicit list (size_type n, const value_type& val, const  allocator_type& alloc = allocator_type()){
			this->alloc = alloc;
			this->size_list = 0;
			this->start = new node<T>;
			this->current = new node<T>;
			this->start->ptrNext = this->current;
			this->current->ptrPrevie = this->start;
			this->assign(n, val);					
		}
		// Создает контейнер из n элементов. Каждый элемент является копией val .

		list (iterator first, iterator last, const allocator_type& alloc = allocator_type()){
			this->alloc = alloc;
			this->size_list = 0;
			this->start = new node<T>;
			this->current = new node<T>;
			this->start->ptrNext = this->current;
			this->current->ptrPrevie = this->start;
			this->assign(first, last);				
		}
		// Создает контейнер с таким количеством элементов, как диапазон [первый, последний) , причем каждый элемент создается из соответствующего ему элемента в этом диапазоне в том же порядке.
		list (const list& x){
			this->alloc = alloc;
			this->size_list = 0;
			this->start = new node<T>;
			this->current = new node<T>;
			this->start->ptrNext = this->current;
			this->current->ptrPrevie = this->start;
			this->assign(x.begin(), x.end());						
		}
// конструкторы
	
		~list(){
				this->clear();
				delete this->start;
				delete this->current;
		}

list &operator=(const list<T, Alloc> &other)
{
			this->clear();
			this->start->ptrNext = this->current;
			this->current->ptrPrevie = this->start;
			this->size_list = 0;
			this->assign(other.begin(), other.end());
			return (*this);
}

		iterator begin(){
			return(iterator(this->start->ptrNext));
		}
		const_iterator begin() const{

			return(const_iterator(this->start->ptrNext));
		}
		iterator end(){
			iterator temp = iterator(this->current);
			return(temp);
		}
		const_iterator end() const{
			const_iterator temp = const_iterator(this->current);
			return(temp);
		}
    	reverse_iterator rbegin(){
			reverse_iterator temp = this->current->ptrPrevie;
			return temp;
		}
		const_reverse_iterator rbegin() const{
			const_reverse_iterator temp = this->current->ptrPrevie;
			return temp;
		}
    	reverse_iterator rend(){
			reverse_iterator temp = this->start;
			return temp;
		}
		const_reverse_iterator rend() const{
			const_reverse_iterator temp = this->start;
			return temp;
		}		
		bool empty() const{
			if (this->size_list == 0){
				return true;
			} else {
				return false;
			}
		}
		// Значение true, если размер контейнера равен 0 , в противном случае - значение false .
		size_type size() const{
			return this->size_list;
		}
		// Возвращает количество элементов в контейнере списка .
		size_type max_size() const {
			return (_nodalc.max_size());
		}
		// Возвращает максимальное количество элементов, которое может содержать контейнер списка .
		reference front(){
			return this->start->ptrNext->data;
		}
		// Возвращает ссылку на первый элемент в контейнере списка . Для пустого контейнера не определенное поведение
		const_reference front() const{
			return this->start->ptrNext->data;
		}
		// Возвращает ссылку на первый элемент в контейнере списка . 
		reference back(){
			return (this->current->ptrPrevie->data);
		}
		const_reference back() const{
			return (this->current->ptrPrevie->data);
		}
		// Возвращает ссылку на последний элемент в контейнере списка .
  		void assign (iterator first, iterator last){
			this->clear();
			while(first != last){
				this->push_back(*first);
				++first;
			}
		}
  		void assign (const_iterator first, const_iterator last){
			this->clear();
			while(first != last){
				this->push_back(*first);
				++first;
			}
		}		
		// В версии диапазона (1) новое содержимое - это элементы, составленные из каждого из элементов в диапазоне от первого до последнего в том же порядке.
		void assign (size_type n, const value_type& val){
			this->clear();
			size_type count = 0;
			while(count < n){
				this->push_back(val);
				count++;
			}
		}
		// В версии заполнения (2) новое содержимое - это n элементов, каждый из которых инициализирован копией val .
		void push_front (const value_type& val){
			node<T> *temp = new node<value_type>(val);
			temp->ptrPrevie = this->start;
			temp->ptrNext = this->start->ptrNext;
			this->start->ptrNext->ptrPrevie = temp;
			this->start->ptrNext = temp;
			this->size_list++;
		}
		// Вставляет новый элемент в начало списка, прямо перед его текущим первым элементом. Содержимое val копируется (или перемещается) во вставленный элемент. Это эффективно увеличивает размер контейнера на единицу.
		void pop_front(){
			if (this->start->ptrNext){
				node <T> *temp = this->start->ptrNext->ptrNext;
				temp->ptrPrevie = this->start;
				delete start->ptrNext;
				this->start->ptrNext = temp;
				this->size_list--;
			}			
		}
		// Удаляет первый элемент в контейнере списка, эффективно уменьшая его размер на единицу. Это разрушает удаленный элемент.
		void push_back (const value_type& val){
			node<T> *temp = new node<value_type>(val);
			temp->ptrNext = this->current;
			temp->ptrPrevie = this->current->ptrPrevie;
			this->current->ptrPrevie->ptrNext = temp;
			this->current->ptrPrevie = temp;
			this->size_list++;
		}
		// Добавляет новый элемент в конец контейнера списка после его текущего последнего элемента. Содержимое val копируется (или перемещается) в новый элемент.
		void pop_back(){
			if (this->size_list){
				node<T> *temp = this->current->ptrPrevie->ptrPrevie;
				temp->ptrNext = this->current;
				delete this->current->ptrPrevie;
				this->current->ptrPrevie = temp;
				this->size_list--;		
			}
		}
		// Удаляет последний элемент в контейнере списка, эффективно уменьшая размер контейнера на единицу. Это разрушает удаленный элемент
		
		iterator insert (iterator position, const value_type& val){
			node<T> *temp = new node<value_type>(val);
			temp->ptrNext = position.ptr;
			temp->ptrPrevie = position.ptr->ptrPrevie;
			temp->ptrPrevie->ptrNext = temp;
			temp->ptrNext->ptrPrevie = temp;
			this->size_list++;
			return(iterator(temp));
		}
		void insert (iterator position, size_type n, const value_type& val){
			size_t count = 0;
			while (count < n)
			{
				this->insert(position, val);
				count++;
			}
			
		}
		void insert (iterator position, iterator first, iterator last){
			while (first != last){
				insert(position, *first);
				++first;
			}
		}
		// Контейнер расширяется путем вставки новых элементов перед элементом в указанной позиции. 

		iterator erase (iterator position){
			node<T> *temp = position.ptr;
			temp->ptrPrevie->ptrNext = temp->ptrNext;
			temp->ptrNext->ptrPrevie = temp->ptrPrevie;
			position++;
			delete temp;
			this->size_list--;
			return position;
		}
		iterator erase (iterator first, iterator last){
			while (first != last){
				first = this->erase(first);
			}
			return (first);
		}
		// Удаляет из контейнера списка либо один элемент (позицию), либо диапазон элементов ([первый, последний))

		// Заменяет содержимое контейнера содержимым x, который является другим списком того же типа. Размеры могут отличаться.
		
		void resize (size_type n, value_type val = value_type()){
			if (this->size() < n){
				while (this->size() < n){
					this->push_back(val);
				}
			} else {
				while (this->size() > n){
					this->pop_back();
				}
			}
		}
		// Изменяет размер контейнера, чтобы он содержал n элементов. Если n меньше текущего размера контейнера, содержимое сокращается до первых n элементов, удаляя все остальные (и уничтожая их). Если n больше текущего размера контейнера, содержимое расширяется путем вставки в конце столько элементов, сколько необходимо для достижения размера n. Если указан val, новые элементы инициализируются как копии val, в противном случае они инициализируются значением.
		
		void clear(){

			while(this->size_list){
				this->pop_back();
			}
		}
		// даляет все элементы из контейнера списка (которые уничтожаются) и оставляет контейнер с размером 0.
		
		// Переносит элементы из x в контейнер, вставляя их в позицию. Это эффективно вставляет эти элементы в контейнер и удаляет их из x, изменяя размеры обоих контейнеров. Операция не предполагает строительства или разрушения какого-либо элемента. Они передаются независимо от того, является ли x значением lvalue или rvalue, или поддерживает ли value_type конструкцию перемещения или нет
		void splice (iterator position, list& x){
			splice(position, x, x.begin(), x.end());
		}
		// Первая версия (1) переносит все элементы x в контейнер
		void splice (iterator position, list& x, iterator i){
			iterator temp = i;
			splice(position, x, i, ++temp);
		}
		// Вторая версия (2) переносит в контейнер только элемент, на который указывает i из x.
		void splice (iterator position, list& x, iterator first, iterator last){
			node<T> *pos = position.ptr;
			node<T> *first_x = first.ptr;
			node<T> *last_x = last.ptr;
			node<T> *last_elem_x = last_x->ptrPrevie;
			size_t count = 0;
			while (first != last){
				count++;
				++first;
			}
			
			x.size_list -= count;
			this->size_list += count;

			first_x->ptrPrevie->ptrNext = last_x;
			last_x->ptrPrevie = first_x->ptrPrevie;
			pos->ptrPrevie->ptrNext = first_x;
			first_x->ptrPrevie = pos->ptrPrevie;
			pos->ptrPrevie = last_elem_x;
			last_elem_x->ptrNext = pos;			
		}
		// Третья версия (3) передает диапазон [первый, последний) из x в контейнер.

		void remove (const value_type& val){
			iterator start_it = this->begin();
			iterator end_it = this->end();

			while (start_it != end_it){
				if (*start_it == val) {
					start_it = this->erase(start_it);
				} else {
					++start_it;
				}
			}
		}
		// Удалить элементы с определенным значением Удаляет из контейнера все элементы, которые сравниваются с val. Это вызывает деструктор этих объектов и уменьшает размер контейнера на количество удаленных элементов
		
		template <class Predicate> // Унарный предикат, который, принимая значение того же типа, что и те, которые содержатся в объекте forward_list, возвращает true для тех значений, которые должны быть удалены из контейнера, и false для оставшихся. Это может быть указатель на функцию или объект функции.
		void remove_if (Predicate pred){
			iterator start_it = this->begin();
			iterator end_it = this->end();

			while (start_it != end_it){
				if (pred(*start_it)) {
					start_it = this->erase(start_it);
				} else {
					++start_it;
				}
			}			
		}
		//Удаляет из контейнера все элементы, для которых предикат предиката возвращает истину. Это вызывает деструктор этих объектов и уменьшает размер контейнера на количество удаленных элементов.
		
		void unique(){
			iterator start_it = this->begin();
			iterator end_it = this->end();

			++start_it;
			while ( start_it != end_it){
				if (*start_it == start_it.ptr->ptrPrevie->data){
					start_it = erase(start_it);
				} else {
					++start_it;
				}
			}
		}
		// Версия без параметров (1) удаляет все элементы, кроме первого, из каждой последующей группы одинаковых элементов в контейнере. Обратите внимание, что элемент удаляется из контейнера списка только в том случае, если он сравнивается с элементом, непосредственно предшествующим ему. Таким образом, эта функция особенно полезна для отсортированных списков.
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred){
			iterator start_it = this->begin();
			iterator end_it = this->end();

			++start_it;
			while ( start_it != end_it){
				if (binary_pred(*start_it, start_it.ptr->ptrPrevie->data)){
					start_it = erase(start_it);
				} else {
					++start_it;
				}
			}
		}
		// Вторая версия (2) принимает в качестве аргумента конкретную функцию сравнения, которая определяет «уникальность» элемента. Фактически, может быть реализовано любое поведение (и не только сравнение равенства), но обратите внимание, что функция вызовет binary_pred (* i, * (i-1)) для всех пар элементов (где i - итератор элемента , начиная со второго) и удалите i из списка, если предикат вернет истину.
		void merge (list& x){
			this->merge(x, Compare<T>);
		}
		template <class Compare>
		void merge (list& x, Compare comp){
			iterator begin_this = begin();
			iterator end_this = end();
			iterator begin_x = x.begin();
			iterator end_x = x.end();

			if (x == *this){
				return ;
			}
			while (begin_this != end_this && begin_x != end_x)
			{
				while (begin_this != end_this && !comp(*begin_x, *begin_this)){
					++begin_this;
				}
				++begin_x;
				this->splice(begin_this, x, begin_x.ptr->ptrPrevie);
			}
			if (begin_x != end_x){
				this->splice(begin_this, x, begin_x, end_x);
			}
		}
		// не понял описание работает только с отсортированнаым списком в чем смысл?
		void sort(){
			this->sort(Compare<T>);		
		}
		template <class Compare>
		void sort (Compare comp){
			iterator begin_1 = this->begin();
			iterator begin_2 = this->begin();
			iterator end = this->end();
			T temp;

			while (++begin_2 != end)
			{
				if (comp(*begin_2, *begin_1))
				{
					temp = *begin_1;
					*begin_1 = *begin_2;
					*begin_2 = temp;
					begin_1 = this->begin();
					begin_2 = this->begin();
				}
				else
					++begin_1;
			}			
		}
		void reverse(){
			list<T, Alloc> temp;
			iterator begin = this->begin();
			iterator end = this->end();

			while (begin != end)
			{
				temp.push_front(*begin);
				++begin;
			}
			*this = temp;			
		}
		// Изменяет порядок элементов в контейнере списка.
	};

template <class T, class Alloc>
  bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	typename ft::list<T, Alloc>::const_iterator starLhs = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator endLhs = lhs.end();
	typename ft::list<T, Alloc>::const_iterator startRhs = rhs.begin();
	typename ft::list<T, Alloc>::const_iterator endRhs = rhs.end();

	while ((starLhs != endLhs) && (startRhs != endRhs)){
		if (*startRhs != *starLhs)
			return (false);
		++starLhs;
		++startRhs;
	}
	if ((starLhs != endLhs) || (startRhs != endRhs)){
		return (false);
	}
	return (true);
  };

template <class T, class Alloc>
  bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	  	if (lhs == rhs){
			return (false);
		}
		return (true);
};

template <class T, class Alloc>
  bool operator<  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
  	typename ft::list<T, Alloc>::const_iterator first_1 = lhs.begin();
	typename ft::list<T, Alloc>::const_iterator last_1 = lhs.end();
	typename ft::list<T, Alloc>::const_iterator first_2 = rhs.begin();
	typename ft::list<T, Alloc>::const_iterator last_2 = rhs.end();

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
  bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	  	return !(rhs < lhs);
  }

template <class T, class Alloc>
  bool operator>  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	  	return (rhs < lhs);
  }

template <class T, class Alloc>
  bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs){
	  return !(lhs < rhs);
  }

template <class T, class Alloc>
void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y){
	ft::list<T,Alloc> temp = x;
	x = y;
	y = temp;
}
template<typename T, typename Alloc >
void ft::list<T, Alloc>::swap(list<T, Alloc> &other)
{
	list<T, Alloc> temp = *this;
	*this = other;
	other = temp;
}
}