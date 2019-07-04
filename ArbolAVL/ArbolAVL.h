/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/

#ifndef ARBOLAVL_H_
#define ARBOLAVL_H_

#include "Nodo.h"
#include "ArborBinarioOrdenado.h"

template<class T>
class AVLTree: public BinarySearchTree<T> {
private:
	Node<T>* insert(T, Node<T>*);
	Node<T>* remove(T, Node<T>*);
	Node<T>* balance(Node<T>*);
	Node<T>* leftLeftRotation(Node<T>*);
	Node<T>* rightRightRotation(Node<T>*);
	Node<T>* leftRightRotation(Node<T>*);
	Node<T>* rightLeftRotation(Node<T>*);
	int height(Node<T>*);
	int heightDifference(Node<T>*);
public:
	AVLTree(int (*ptr)(T, T));
	~AVLTree();
	void add(T);
	void remove(T);
};
#include "ArbolAVL.cpp"

#endif /* ARBOLAVL_H_ */
