/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#ifndef NODO_H_
#define NODO_H_

template<class T>
class Node {
private:
	T data;
	Node<T>* left;
	Node<T>* right;
public:
	Node(T data);
	Node(T data, Node<T>, Node<T>);
	~Node();
	T getData();
	Node<T>* getLeft();
	Node<T>* getRight();
	void setData(T);
	void setLeft(Node<T>*);
	void setRight(Node<T>*);
};

#include "Nodo.cpp"

#endif /* NODO_H_ */
