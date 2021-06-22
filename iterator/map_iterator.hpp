#pragma once

# include "../map.hpp"
# include "../avl_tree.hpp"

template <class Key, class T,  class Comp>
class Mapiterator
{
	public:

	avl_tree<Key, T, Comp> func;


	Mapiterator(map_node<Key, T> *ptr){
		this->func.root = ptr;
	}
	Mapiterator(avl_tree<Key, T, Comp> *ptr){
		this->func = ptr;
	}	
	Mapiterator(const Mapiterator &copy){
		this->func = copy.func;
	}		
	Mapiterator(){
		this->func.root = NULL;
	}

	Mapiterator& operator=(const Mapiterator &ptr){
		this->func = ptr.func;
		return (*this);
	}
	std::pair<Key, T> *operator->(){
		return (&this->func.root->pair);
	}
	std::pair<Key, T> &operator*() const {
		return this->func.root->pair;
	}
	Mapiterator &operator++(){
	if (this->func.root->right)
		this->func.root = func.findmin(this->func.root->right);
	else {
			while (this->func.root->parrent && this->func.root->parrent->right == this->func.root){
				this->func.root = this->func.root->parrent;
			}
			this->func.root = this->func.root->parrent;
		}
		return (*this);
	}
	Mapiterator &operator--(){
	if (this->func.root->left)
		this->func.root = func.findmax(this->func.root->left);
	else {
			while (this->func.root->parrent && this->func.root->parrent->left == this->func.root){
				this->func.root = this->func.root->parrent;
			}
			this->func.root = this->func.root->parrent;
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

	bool operator==(const Mapiterator &ptr){
		return this->func.root == ptr.func.root;
	}
	bool operator !=(const Mapiterator &ptr){
		return this->func.root != ptr.func.root;
	}
	bool operator >(const Mapiterator &ptr){
		return this->func.root > ptr.func.root;
	}
	bool operator <(const Mapiterator &ptr){
		return this->func.root < ptr.func.root;
	}
};

template <class Key, class T, class Comp>
class RevMapiterator
{
	public:

	avl_tree<Key, T, Comp> func;


	RevMapiterator(map_node<Key, T> *ptr){
		this->func.root = ptr;
	}
	RevMapiterator(avl_tree<Key, T, Comp> *ptr){
		this->func = ptr;
	}	
	RevMapiterator(const RevMapiterator &copy){
		this->func = copy.func;
	}		
	RevMapiterator(){
		this->func.root = NULL;
	}

	RevMapiterator& operator=(const RevMapiterator &ptr){
		this->func = ptr.func;
		return (*this);
	}
	std::pair<Key, T> *operator->(){
		return (&this->func.root->pair);
	}
	std::pair<Key, T> &operator*() const {
		return this->func.root->pair;
	}	
	RevMapiterator &operator++(){
		return --this->func;
	}
	RevMapiterator &operator--(){
		return ++this->func;
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

	bool operator==(const RevMapiterator &ptr){
		return this->func.root == ptr.func.root;
	}
	bool operator !=(const RevMapiterator &ptr){
		return this->func.root != ptr.func.root;
	}
	bool operator >(const RevMapiterator &ptr){
		return this->func.root > ptr.func.root;
	}
	bool operator <(const RevMapiterator &ptr){
		return this->func.root < ptr.func.root;
	}
};
