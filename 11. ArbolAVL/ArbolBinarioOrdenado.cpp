/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#ifndef ARBOLBINARIOORDENADO_CPP
#define ARBOLBINARIOORDENADO_CPP

#include "ArbolBinarioOrdenado.h"
#include <iostream>

using namespace std;

///Inicializa el arbol de busqueda binaria con la raiz en null
///y el comparador que entra por parametro
template<class T>
BinarySearchTree<T>::BinarySearchTree(int (*ptr)(T, T)) {
	this->root = null;
	this->ptr = ptr;
}

///Destructor del arbol
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
}

///Añade un objeto al arbol
template<class T>
void BinarySearchTree<T>::add(T data) {
	this->root = this->insert(data, this->root);
}

///Inserta un objeto en determinado nodo
template<class T>
Node<T>* BinarySearchTree<T>::insert(T data, Node<T>* node) {
	if (node == null) {
		node = new Node<T>(data);
	} else if (ptr(node->getData(), data) > 0) {
		node->setLeft(this->insert(data, node->getLeft()));
	} else if (ptr(node->getData(), data) < 0) {
		node->setRight(this->insert(data, node->getRight()));
	}
	return node;
}

///Borra un objeto del arbol
template<class T>
void BinarySearchTree<T>::remove(T data) {
	this->root = this->remove(data, this->root);
}


///Borra un objeto de un nodo
template<class T>
Node<T>* BinarySearchTree<T>::remove(T data, Node<T>* node) {
	Node<T>* aux;
	if (node == null)
		return null;
	else if (ptr(node->getData(), data) > 0) {
		node->setLeft(this->remove(data, node->getLeft()));
	} else if (ptr(node->getData(), data) < 0) {
		node->setRight(this->remove(data, node->getRight()));
	} else if (node->getLeft() && node->getRight()) {
		aux = this->findMin(node->getRight());
		node->setData(aux->getData());
		node->setRight(this->remove(node->getData(), node->getRight()));
	} else {
		aux = node;
		if (node->getRight() == null) {
			node = node->getLeft();
		}else if (node->getLeft() == null) {
			node = node->getRight();
		}
		delete aux;
	}
	return node;
}

///Busca un objeto en determinado nodo
template<class T>
Node<T>* BinarySearchTree<T>::find(T data, Node<T>* node) {
	if (node == null)
		return NULL;
	else if (ptr(node->getData(), data) > 0)
		return find(data, node->getLeft());
	else if (ptr(node->getData(), data) < 0)
		return find(data, node->getRight());
	else
		return node;
}

///Busca un objeto en el arbol
template<class T>
Node<T>* BinarySearchTree<T>::search(T data) {
	return this->find(data, this->root);
}

///Busca el valor minimo un nodo
template<class T>
Node<T>* BinarySearchTree<T>::findMin(Node<T>* node) {
	if (node == null) {
		return null;
	} else if (node->getLeft()==null) {
		return node;
	} else {
		return this->findMin(node->getLeft());
	}
}

///Busca el valor maximo un nodo
template<class T>
Node<T>* BinarySearchTree<T>::findMax(Node<T>* node) {
	if (node == null) {
		return null;
	} else if (node->getRight()==null) {
		return node;
	} else {
		return this->findMax(node->getRight());
	}
}

///Imprime los datos del arbol en orden
template<class T>
void BinarySearchTree<T>::inOrder(Node<T>* node) {
	if (node != null) {
		this->inOrder(node->getLeft());
		cout << node->getData() << " ";
		this->inOrder(node->getRight());
	}

}

///Imprime el arbol en preorden
template<class T>
void BinarySearchTree<T>::preOrder(Node<T> * node) {
	if (node != null) {
		cout << node->getData() << " ";
		this->preOrder(node->getLeft());
		this->preOrder(node->getRight());
	}
}

///Imprime el arbol en posorden
template<class T>
void BinarySearchTree<T>::postOrder(Node<T> * node) {
	if (node != null) {
		this->postOrder(node->getLeft());
		this->postOrder(node->getRight());
		cout << node->getData() << " ";
	}
}

///Imprime las ramas de un nodo
template<class T>
void BinarySearchTree<T>::printArms(Node<T> * node) {
	if (node->getLeft() != null)
		cout << node->getLeft()->getData()<<" ";
	if (node->getRight() != null)
		cout << node->getRight()->getData()<<" ";
}

///Imprime las ramas y subramas de un nodo, no el dato raiz
template<class T>
void BinarySearchTree<T>::perLevel(Node<T> * node) {
	if (node != null) {
		this->printArms(node);
		this->perLevel(node->getLeft());
		this->perLevel(node->getRight());
	}
}

///Muestra los datos del arbol en orden
template<class T>
void BinarySearchTree<T>::showInOrder() {
	this->inOrder(this->root);
	cout << endl;
}

///Muestra los datos del arbol en preorden
template<class T>
void BinarySearchTree<T>::showPreOrder() {
	this->preOrder(this->root);
	cout << endl;
}

///Muestra los datos del arbol en posorden
template<class T>
void BinarySearchTree<T>::showPostOrder() {
	this->postOrder(this->root);
	cout << endl;
}

///Muestra los datos del arbol por niveles
template<class T>
void BinarySearchTree<T>::showPerLevel() {
	cout << this->root->getData()<<" ";
	this->perLevel(this->root);
	cout << endl;
}

///Obtiene el dato raiz del arbol
template<class T>
Node<T>* BinarySearchTree<T>::getRoot() {
	return this->root;
}

#endif /*ARBOLBINARIOORDENADO_CPP*/
