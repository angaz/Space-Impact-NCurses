#include "LinkedList.hpp"

template <class T>
LinkedList<T>::LinkedList() :
	_data(NULL),
	_next(NULL),
	_previous(NULL) {}


template<class T>
LinkedList<T>::LinkedList(const T &data) :
	_data(&data),
	_next(NULL),
	_previous(NULL) {}


/*template<class T>
LinkedList<T>::LinkedList(const T &data, LinkedList<T> &previous) :
	_data(&data),
<<<<<<< HEAD
	_next(NULL),
=======
	_next(nullptr),
>>>>>>> 9084363e55ddbebf476e4b39a848b33137f7180a
	_previous(&previous) {}*/

/*template<class T>
LinkedList<class T>::LinkedList(const T &data, LinkedList<T> &next, LinkedList<T> &previous) :
	_data(&data),
	_next(&next),
	_previous(&previous) {}*/

template <class T>
LinkedList<T>::~LinkedList() {
	if (this->_previous != NULL)
		this->_previous->setNext(*this->_next);
	if (this->_next != NULL)
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

	LinkedList<T> *node = this;

	while(node->next() != NULL) {
		node = node->next();
	}

	node->setNext(*newNode);
	newNode->setPrevious(*node);
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

template <class T>
LinkedList<T>	&LinkedList<T>::operator=(const LinkedList<T> &src) {
	this->_data = src._data;
	this->_next = src._next;
	this->_previous = src._previous;

	return *this;
}