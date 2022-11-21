#pragma once
#include "std.h"

template <class T>
class Node {
private:
	T* pdata;

public:
	Node<T>* pnext;

	Node() {
		pnext = nullptr;
		pdata = nullptr;

	}

	Node(Node* pn, T* pd) {
		pnext = pn;
		pdata = pd;

	}

	~Node() {
		pnext = nullptr;
		pdata = nullptr;

	}

	const void setNext(Node* pn) const {
		pnext = pn;

	}

	Node* getNext() const {
		return pnext;

	}

	const void setData(T* pd) {
		pdata = pd;

	}

	T* getData() const {
		return pdata;

	}
};