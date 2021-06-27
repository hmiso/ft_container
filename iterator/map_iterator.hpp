#pragma once

# include "../map.hpp"
# include "../avl_tree.hpp"

template <class Key, class T,  class Comp>
class Mapiterator
{
	public:

	map_node<Key, T> *func;

	map_node<Key, T> * findmini(map_node<Key, T> * p) const {
	return p->left ? findmini(p->left) : p;
	}
	map_node<Key, T> * findmaxi(map_node<Key, T> *p) const { 
	return p->right ? findmaxi(p->right) : p; 
	}

	Mapiterator(map_node<Key, T> *ptr){
		this->func = ptr;
	}
	Mapiterator(avl_tree<Key, T, Comp> *ptr){
		this->func = ptr->root;
	}	
	Mapiterator(const Mapiterator &copy){
		this->func = copy.func;
	}		
	Mapiterator(){
		this->func = NULL;
	}

	Mapiterator& operator=(const Mapiterator &ptr){
		this->func = ptr.func;
		return (*this);
	}
	std::pair<Key, T> *operator->(){
		return (&this->func->pair);
	}
	std::pair<Key, T> &operator*() const {
		return this->func->pair;
	}
	Mapiterator &operator++(){
	if (this->func->right)
		this->func = this->findmini(this->func->right);
	else {
			while (this->func->parrent && this->func->parrent->right == this->func){
				this->func = this->func->parrent;
			}
			this->func = this->func->parrent;
		}
		return (*this);
	}
	Mapiterator &operator--(){
	if (this->func->left)
		this->func = this->findmaxi(this->func->left);
	else {
			while (this->func->parrent && this->func->parrent->left == this->func){
				this->func = this->func->parrent;
			}
			this->func = this->func->parrent;
		}
		return (*this);
	}
	Mapiterator operator++(int) {
		Mapiterator temp(*this);
		++(*this);
		return temp;
	}
	Mapiterator operator--(int) {
		Mapiterator temp(*this);
		--(*this);
		return temp;
	}

	friend bool operator==(const Mapiterator &ptr, const Mapiterator &ptr1){
		return ptr.func == ptr1.func;
	}
	friend bool operator !=(const Mapiterator &ptr, const Mapiterator &ptr1){
		return ptr.func != ptr1.func;
	}
	friend bool operator >(const Mapiterator &ptr, const Mapiterator &ptr1){
		return ptr.func > ptr1.func;
	}
	friend bool operator <(const Mapiterator &ptr, const Mapiterator &ptr1){
		return ptr.func > ptr1.func;
	}
	~Mapiterator(){

	}
};

template <class Key, class T, class Comp>
class RevMapiterator
{
	public:

	map_node<Key, T> *func;

	map_node<Key, T> * findmini(map_node<Key, T> * p) const {
		return p->left ? findmini(p->left) : p;
	}
	map_node<Key, T> * findmaxi(map_node<Key, T> *p) const { 
		return p->right ? findmaxi(p->right) : p; 
	}



	RevMapiterator(map_node<Key, T> *ptr){
		this->func = ptr;
	}
	RevMapiterator(avl_tree<Key, T, Comp> *ptr){
		this->func = ptr->root;
	}	
	RevMapiterator(const RevMapiterator &copy){
		this->func = copy.func;
	}		
	RevMapiterator(){
		this->func = NULL;
	}

	RevMapiterator& operator=(const RevMapiterator &ptr){
		this->func = ptr.func;
		return (*this);
	}
	std::pair<Key, T> *operator->(){
		return (&this->func->pair);
	}
	std::pair<Key, T> &operator*() const {
		return this->func->pair;
	}	
	RevMapiterator &operator++(){
		if (this->func->left)
			this->func = this->findmaxi(this->func->left);
		else {
				while (this->func->parrent && this->func->parrent->left == this->func){
					this->func = this->func->parrent;
				}
				this->func = this->func->parrent;
			}
			return (*this);
		}

	RevMapiterator &operator--(){
		if (this->func->right)
			this->func = this->findmini(this->func->right);
		else {
				while (this->func->parrent && this->func->parrent->right == this->func){
					this->func = this->func->parrent;
				}
				this->func = this->func->parrent;
			}
			return (*this);
	}
	RevMapiterator operator++(int) {
		RevMapiterator temp(*this);
		--(*this);
		return temp;
	}
	RevMapiterator operator--(int) {
		RevMapiterator temp(*this);
		++(*this);
		return temp;
	}

	friend bool operator==(const RevMapiterator &ptr, const RevMapiterator &ptr1){
		return ptr.func == ptr1.func;
	}
	friend bool operator !=(const RevMapiterator &ptr, const RevMapiterator &ptr1){
		return ptr.func != ptr1.func;
	}
	friend bool operator >(const RevMapiterator &ptr, const RevMapiterator &ptr1){
		return ptr.func > ptr1.func;
	}
	friend bool operator <(const RevMapiterator &ptr, const RevMapiterator &ptr1){
		return ptr.func > ptr1.func;
	}
};
