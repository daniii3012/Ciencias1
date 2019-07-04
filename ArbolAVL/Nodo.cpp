/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/

#ifndef NODO_CPP
#define NODO_CPP
#define null 0

#include "Nodo.h"

///Inicializa la clase con el dato a guardar y las ramas en null
//@param data Dato que guardará este nudo
template<class T>
Node<T>::Node(T data) {
	this->data = data;
	this->left = null;
	this->right = null;
}

///Inicializa la clase con el dato a guardar y las ramas
///@param data Dato que guardará este nudo
///@param left Nodo que guardara en el lado izquierdo
///@param right Nodo que guardara en el lado derecho

template<class T>
Node<T>::Node(T data, Node<T> left, Node<T> right) {
	this->data = data;
	this->left = left;
	this->right = right;
}
///Destructor del objeto Node
template<class T>
Node<T>::~Node() {
}

///Obtiene el dato alojado en este nodo
template<class T>
T Node<T>::getData() {
	return this->data;
}

///Obtiene el nodo izquierdo de este nodo
template<class T>
Node<T>* Node<T>::getLeft() {
	return this->left;
}

///Obtiene el nodo derecho de este nodo
template<class T>
Node<T>* Node<T>::getRight() {
	return this->right;
}

///Establece el dato alojado en este nodo
template<class T>
void Node<T>::setData(T data) {
	this->data = data;
}

///Establece el nodo izquiedo en este nodo
template<class T>
void Node<T>::setLeft(Node<T>* left) {
	this->left = left;
}

///Establece el nodo derecho en este nodo
template<class T>
void Node<T>::setRight(Node<T>* right) {
	this->right = right;
}

#endif /* NODO_CPP */

