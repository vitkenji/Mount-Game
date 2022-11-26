#pragma once
#include "std.h"
// creditos: https://www.youtube.com/channel/UCrNDrGwDXmBErjp0BGqqOUw

template <class T>
class Elemento {
private:
	T* pdata;

public:
	Elemento<T>* pnext;

	Elemento() {
		pnext = nullptr;
		pdata = nullptr;

	}

	Elemento(Elemento* pn, T* pd) {
		pnext = pn;
		pdata = pd;

	}

	~Elemento() {
		pnext = nullptr;
		pdata = nullptr;

	}

	const void setNext(Elemento* pn) const {
		pnext = pn;

	}

	Elemento* getNext() const {
		return pnext;

	}

	const void setData(T* pd) {
		pdata = pd;

	}

	T* getData() const {
		return pdata;

	}
};