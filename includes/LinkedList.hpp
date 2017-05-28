#ifndef RUSH00_LINKEDLIST_HPP
#define RUSH00_LINKEDLIST_HPP

#include <cstddef>

template <class T> class LinkedList {
public:
	LinkedList();
	LinkedList(const T &data);
	LinkedList(const LinkedList<T> &list);
//	LinkedList(const T &data, LinkedList<T> &previous);
//	LinkedList(const T &data, LinkedList<T> &next, LinkedList<T> &previous);
	~LinkedList();

	LinkedList	&operator=(const LinkedList<T> &src);

	T 				&getData();
	void 			add(const T &data);
	LinkedList<T>	*next();
	void 			setNext(LinkedList<T> &next);
	LinkedList<T>	*previous();
	void 			setPrevious(LinkedList<T> &previous);

private:
	T			*_data;
	LinkedList	*_next;
	LinkedList	*_previous;
};

#endif //RUSH00_LINKEDLIST_HPP
