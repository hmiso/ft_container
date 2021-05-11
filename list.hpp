/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmiso <hmiso@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:31:05 by hmiso             #+#    #+#             */
/*   Updated: 2021/05/11 23:11:43 by hmiso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <memory>

#include "Allocator.hpp"
#include "iterator/listIterator.hpp"
#include "iterator/node.hpp"


namespace ft{
	template < typename T, typename Alloc = allocator<T> > class list{

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

		private:
		node<T> *current;
		allocator_type alloc;
		node<T> *start;
		public:
// конструкторы
		explicit list (const allocator_type& alloc = allocator_type()){
			this->start = NULL;
			this->current = NULL;
			this->alloc = alloc; 
		} // нужно для неявного преобразования если мы передадим не то значение 
		// хз вообще что это Создает пустой контейнер без элементов. https://www.cplusplus.com/reference/list/list/empty/
		explicit list (size_type n, const value_type& val = value_type(), const  allocator_type& alloc = allocator_type()){}
		// Создает контейнер из n элементов. Каждый элемент является копией val .
		template <class InputIterator>
		list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
		// Создает контейнер с таким количеством элементов, как диапазон [первый, последний) , причем каждый элемент создается из соответствующего ему элемента в этом диапазоне в том же порядке.
		list (const list& x){}
// конструкторы
	
		~list(){}

		iterator begin(){
			node<T> *temp = this->current;
			while(temp->ptrPrevie != NULL){
				temp = temp->ptrPrevie;
			}
			return(iterator(temp));
		}
		const_iterator begin() const{
			node<T> *temp = this->current;
			while(temp->ptrPrevie != NULL){
				temp = temp->ptrPrevie;
			}
			return(const_iterator(temp));
		}
		iterator end(){
			iterator temp = iterator(current);
			++temp;
			return(temp);
		}
		const_iterator end() const{
			const_iterator temp = const_iterator(current);
			++temp;
			return(temp);
		}
    	reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;		
		
		bool empty() const{
			if (this->current == NULL){
				return true;
			} else {
				return false;
			}
		}
		// Значение true, если размер контейнера равен 0 , в противном случае - значение false .
		size_type size() const{
			if (this->current == NULL){
				return 0;
			} else {
				size_type count = 1;
				node<T> *temp = this->current;
				while (temp->ptrPrevie != NULL)
				{
					temp = temp->ptrPrevie;
					count++;
				}
				return count;
			}
		}
		// Возвращает количество элементов в контейнере списка .
		size_type max_size() const {
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		}
		// Возвращает максимальное количество элементов, которое может содержать контейнер списка .
		reference front(){
			// node<T> *temp = this->current;
			// while (temp->ptrPrevie != NULL)
			// {
			// 	temp = temp->ptrPrevie;
			// }
			return this->start->data;
		}
		// Возвращает ссылку на первый элемент в контейнере списка . Для пустого контейнера не определенное поведение
		const_reference front() const{
			node<T> *temp = this->current;
			while (temp->ptrPrevie != NULL)
			{
				temp = temp->ptrPrevie;
			}
			return this->start->data;
		}
		// Возвращает ссылку на первый элемент в контейнере списка . 
		reference back(){
			return (this->current->data);
		}
		const_reference back() const{
			return (this->current->data);
		}
		// Возвращает ссылку на последний элемент в контейнере списка .
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last){
			this->clear();
			while(first != last){
				this->push_back(first);
				++first;
			}
		}
		// В версии диапазона (1) новое содержимое - это элементы, составленные из каждого из элементов в диапазоне от первого до последнего в том же порядке.
		void assign (size_type n, const value_type& val){
			size_type count;
			while(count < n){
				this->push_back(val);
			}
		}
		// В версии заполнения (2) новое содержимое - это n элементов, каждый из которых инициализирован копией val .
		void push_front (const value_type& val){
			node<T> *ptr = new node<value_type>(val);
			if (!current){
				this->current = ptr;
				this->start = ptr;
			} else {
				node<T> *tmp = this->current;
				while (tmp->ptrPrevie)
				{
					tmp = tmp->ptrPrevie;
				}
				ptr->ptrNext = tmp;
				tmp->ptrPrevie = ptr;
				this->start = ptr;
			}
		}
		// Вставляет новый элемент в начало списка, прямо перед его текущим первым элементом. Содержимое val копируется (или перемещается) во вставленный элемент. Это эффективно увеличивает размер контейнера на единицу.
		void pop_front(){
			if (this->current){
				node<T> *temp = this->current;
				while (temp)
				{
					temp = temp->ptrPrevie;
				}
				delete temp;
			}			
		}
		// Удаляет первый элемент в контейнере списка, эффективно уменьшая его размер на единицу. Это разрушает удаленный элемент.
		void push_back (const value_type& val){

			if (this->current == NULL){
				node<T> *ptr = new node<value_type>(val);
				this->current = ptr;
				this->start = ptr;
			}
			else{
				node<T> *ptr = new node<value_type>(val, this->current);
				this->current = ptr;
				this->current->ptrPrevie->ptrNext = this->current;
			}
		}
		// Добавляет новый элемент в конец контейнера списка после его текущего последнего элемента. Содержимое val копируется (или перемещается) в новый элемент.
		void pop_back(){
			if (this->current){
				node<T> *temp = this->current->ptrPrevie;
				temp->ptrNext = NULL;
				delete this->current;
				this->current = temp;
			}
		}
		// Удаляет последний элемент в контейнере списка, эффективно уменьшая размер контейнера на единицу. Это разрушает удаленный элемент
		
		iterator insert (iterator position, const value_type& val){
			node<T> *temp = new node<T>(val);
			temp->ptrNext = position.ptr;
			temp->ptrPrevie = position.ptr->ptrPrevie;
			temp->ptrPrevie->ptrNext = temp;
			temp->ptrNext->ptrPrevie = temp;
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
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last){
			while (first != last){
				insert(position, *first);
				++first;
			}
		}
		// Контейнер расширяется путем вставки новых элементов перед элементом в указанной позиции. 

		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		// Удаляет из контейнера списка либо один элемент (позицию), либо диапазон элементов ([первый, последний))

		void swap (list& x);
		// Заменяет содержимое контейнера содержимым x, который является другим списком того же типа. Размеры могут отличаться.
		
		void resize (size_type n, value_type val = value_type());
		// Изменяет размер контейнера, чтобы он содержал n элементов. Если n меньше текущего размера контейнера, содержимое сокращается до первых n элементов, удаляя все остальные (и уничтожая их). Если n больше текущего размера контейнера, содержимое расширяется путем вставки в конце столько элементов, сколько необходимо для достижения размера n. Если указан val, новые элементы инициализируются как копии val, в противном случае они инициализируются значением.
		
		void clear(){
			while(current){
				this->pop_back();
			}
		}
		// даляет все элементы из контейнера списка (которые уничтожаются) и оставляет контейнер с размером 0.
		
		// Переносит элементы из x в контейнер, вставляя их в позицию. Это эффективно вставляет эти элементы в контейнер и удаляет их из x, изменяя размеры обоих контейнеров. Операция не предполагает строительства или разрушения какого-либо элемента. Они передаются независимо от того, является ли x значением lvalue или rvalue, или поддерживает ли value_type конструкцию перемещения или нет
		void splice (iterator position, list& x);
		// Первая версия (1) переносит все элементы x в контейнер
		void splice (iterator position, list& x, iterator i);
		// Вторая версия (2) переносит в контейнер только элемент, на который указывает i из x.
		void splice (iterator position, list& x, iterator first, iterator last);
		// Третья версия (3) передает диапазон [первый, последний) из x в контейнер.

		void remove (const value_type& val);
		// Удалить элементы с определенным значением Удаляет из контейнера все элементы, которые сравниваются с val. Это вызывает деструктор этих объектов и уменьшает размер контейнера на количество удаленных элементов
		
		template <class Predicate> // Унарный предикат, который, принимая значение того же типа, что и те, которые содержатся в объекте forward_list, возвращает true для тех значений, которые должны быть удалены из контейнера, и false для оставшихся. Это может быть указатель на функцию или объект функции.
		void remove_if (Predicate pred);
		//Удаляет из контейнера все элементы, для которых предикат предиката возвращает истину. Это вызывает деструктор этих объектов и уменьшает размер контейнера на количество удаленных элементов.
		
		void unique();
		// Версия без параметров (1) удаляет все элементы, кроме первого, из каждой последующей группы одинаковых элементов в контейнере. Обратите внимание, что элемент удаляется из контейнера списка только в том случае, если он сравнивается с элементом, непосредственно предшествующим ему. Таким образом, эта функция особенно полезна для отсортированных списков.
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred);
		// Вторая версия (2) принимает в качестве аргумента конкретную функцию сравнения, которая определяет «уникальность» элемента. Фактически, может быть реализовано любое поведение (и не только сравнение равенства), но обратите внимание, что функция вызовет binary_pred (* i, * (i-1)) для всех пар элементов (где i - итератор элемента , начиная со второго) и удалите i из списка, если предикат вернет истину.
		void merge (list& x);
		template <class Compare>
		void merge (list& x, Compare comp);
		// не понял описание работает только с отсортированнаым списком в чем смысл?
		void sort();
		template <class Compare>
		void sort (Compare comp);
		void reverse();
		// Изменяет порядок элементов в контейнере списка.
	};
};


template <class T, class Alloc>
  bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator<  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator>  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs);

template <class T, class Alloc>
  bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs);

template <class T, class Alloc>
void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y);