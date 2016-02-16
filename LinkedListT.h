#ifndef __LinkeListT__LinkedListT__
#define __LinkeListT__LinkedListT__

#include <iostream>
#include <string>
using namespace std;

template <typename T> class LinkedListT;
template <typename T> std::ostream& operator <<(std::ostream&, LinkedListT<T> const &);

template <typename T>
class LinkedListT {
public:
	LinkedListT(size_t size) : _size(0), _head(nullptr)  {}
	LinkedListT(LinkedListT<T> const& other);
	LinkedListT<T>& operator=(LinkedListT<T> const& other);
	~LinkedListT();
    
	struct Node{
		Node(T val) : _val(val), _next(nullptr) {}
		T _val;
		Node* _next;
	};
    
	void push_front(T val);
	void push_back(T val);
    
	T pop_front();
	T pop_back();
    
	void insert(T val, Node* before);
	void deleteNode(Node* node);
	bool empty() const;
	const Node* front() const;
	const Node* back() const;
    
	friend ostream& operator << <T> (ostream& os, LinkedListT<T> const& list);
    
private:
	void copy(LinkedListT<T> const& other);
	void deleteRest(Node* from);
	Node* back();
    
private:
	size_t _size;
	Node* _head;
};
//#include "LinkedListT.cpp"


template <class T>
LinkedListT<T>::LinkedListT(LinkedListT<T> const& other) : _head(nullptr) { copy(other); }


template <class T>
LinkedListT<T>& LinkedListT<T>::operator=(LinkedListT<T> const& other) {
	if (this != &other){ copy(other); }
	return *this;
}


template <class T>
LinkedListT<T>::~LinkedListT() { deleteRest(_head); }

template <class T>
void LinkedListT<T>::push_front(T val) {
	LinkedListT<T>::Node *p = new Node(val);
	p->_next = _head;
	_head = p;
	_size++;
}

template <class T>
void LinkedListT<T>::push_back(T val){
	if (_head == nullptr) { _head = new Node(val); ++_size; return; }        //not wrong, just not necessary
	typename LinkedListT<T>::Node *p = _head;
	while (p->_next != nullptr)  { p = p->_next; }
	p->_next = new Node(val);
	++_size;
}

template <class T>
T LinkedListT<T>::pop_front(){
	if (empty()) {
		throw std::out_of_range("out of range in LinkedListT<T>::pop_front()");
	}
	if (_head == nullptr){ throw std::out_of_range("..."); }
	if (_size == 1){ _head->_next = new Node; ++_size; return; }
    
	T result = _head->_val;
	typename ::LinkedListT<T>::Node *pNext = _head->_next;
	delete _head;
	_head = pNext;
	return result;
}

template <class T>
T LinkedListT<T>::pop_back(){
	if (empty()) {
		throw std::out_of_range("out of range in LinkedList<T>::pop_back()");
	}
	if (_size == 1){
		T result = _head->_val;
		_head = nullptr;
		delete _head;
		--_size;
		return result;
	}
	LinkedListT<T>::Node *p = _head, *pPrev = _head;
	while (p->_next != nullptr) {
		pPrev = p;
		p = p->_next;
	}
	T result = p->_val;
	delete p;
	pPrev->_next = nullptr;
	--_size;
	return result;
}

template <class T>
void LinkedListT<T>::insert(T val, Node* before){
    LinkedListT<T>::Node *p = _head, *pPrev = _head;
	p = new Node(val);
	before->_next = p;
	p->_next = before;
}

template <class T>
void LinkedListT<T>::deleteNode(Node* node){
	LinkedListT<T>::Node *p = _head, *pPrev = _head;
	while (p->next != nullptr && p->_next != node){
		pPrev = p;
		p = p->_next;
	}
	if (p->_next == nullptr) { return; }            //node not found
	pPrev->_next = p->_next;
	delete p;
	_size--;
}

template <class T>
bool LinkedListT<T>::empty() const { return _head == nullptr; }

template <class T>
void  LinkedListT<T>::copy(const LinkedListT<T>& other){
	deleteRest(_head);
	if (other._head == nullptr)  { _head = nullptr;  return; }
	_head = new Node(other._head->_val);
	LinkedListT<T>::Node *p = _head, *pPrev = _head, *q = other._head;
	while (q->_next != nullptr)  {
		p = new Node(q->_next->_val);
		pPrev->_next = p;
		pPrev = p;
	}
	p->_next = nullptr;
}

template <class T>
void LinkedListT<T>::deleteRest(Node* from) {
	typename LinkedListT<T>::Node *p = _head, /**pPrev = _head,*/ *pNext;
    
	if (_head == nullptr || from == nullptr) { return; }
	while (p->_next != nullptr){
		pNext = p->_next;
		delete p;
		p = pNext;
	}
	delete p;
}

template <class T>
const typename LinkedListT<T>::Node* LinkedListT<T>::front() const { return _head; }

template <class T>
const typename LinkedListT<T>::Node* LinkedListT<T>::back() const{
    LinkedListT<T>::Node *p = _head, *pNext = _head;
	if (empty()) { return; }
	if (_size == 1) { return _head; }
	while (pNext != nullptr){ return p; }
}

template <class T>
std::ostream& operator<<(std::ostream& os, LinkedListT<T> const& list) {
	os << "LinkedListT<T>[";
	if (list.empty()) { return os << "(empty)]" << std::endl; }
	os << "(";
	typename LinkedListT<T>::Node*  p = list._head;
	while (p != nullptr) {
		os << p->_val;
		os << " ";
		p = p->_next;
	}
	//while the pointer is not equal to pval
	return  os << "]";
}


#endif

