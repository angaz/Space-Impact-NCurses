#ifndef RUSH00_LINKEDLIST_HPP
#define RUSH00_LINKEDLIST_HPP

template <class T> class LinkedList {
public:
	LinkedList();
	LinkedList(const T &data);
	LinkedList(const T &data, LinkedList<T> &previous);
//	LinkedList(const T &data, LinkedList<T> &next, LinkedList<T> &previous);
	~LinkedList();

	T 				&getData();
	void 			add(T &data);
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
