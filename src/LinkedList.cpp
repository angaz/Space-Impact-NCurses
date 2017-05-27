#include "LinkedList.hpp"

LinkedList::LinkedList() :
	_data(nullptr),
	_next(nullptr),
	_previous(nullptr) {}

template<class T>
LinkedList<T>::LinkedList(const T &data) :
	_data(&data),
	_next(nullptr),
	_previous(nullptr) {}

template<class T>
LinkedList<T>::LinkedList(const T &data, LinkedList<T> &previous) :
	_data(&data),
	_next(nullptr),
	_previous(&previous) {}

/*template<class T>
LinkedList<class T>::LinkedList(const T &data, LinkedList<T> &next, LinkedList<T> &previous) :
	_data(&data),
	_next(&next),
	_previous(&previous) {}*/

LinkedList::~LinkedList() {
	if (this->_previous != nullptr)
		this->_previous->setNext(*this->_next);
	if (this->_next != nullptr)
		this->_next->setPrevious(*this->_previous);

	delete this->_data;
}

template<class T>
T &LinkedList<T>::getData() {
	return *this->_data;
}

template<class T>
void LinkedList<T>::add(const T &data) {
	LinkedList<T>	*newNode = new LinkedList(data);

	if (this->_next == nullptr) {
		this->_next = newNode;
		newNode->setPrevious(*this);
	} else {
		LinkedList<T> *node = this->_next;

		while(node->next() != nullptr) {
			node = node->next();
		}

		node->setNext(*newNode);
		newNode->setPrevious(*node);
	}
}

template<class T>
LinkedList<T> *LinkedList<T>::next() {
	return this->_next;
}

template <class T>
LinkedList<T> *LinkedList<T>::previous() {
	return this->_previous;
}

template <class T>
void LinkedList<T>::setNext(LinkedList<T> &next) {
	this->_next = &next;
}

template <class T>
void LinkedList<T>::setPrevious(LinkedList<T> &previous) {
	this->_previous = &previous;
}

