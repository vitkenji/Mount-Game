#pragma once
#include "std.h"
#include "elemento.h"
//creditos: https://www.youtube.com/channel/UCrNDrGwDXmBErjp0BGqqOUw

using namespace std;

template <class T>

class Lista {
private:
	Elemento<T>* pfirst;
	Elemento<T>* plast;
	int size;

public:
	int getSize() { return size; }

	Elemento <T>* getPfirst() { return pfirst; }

	Elemento <T>* getPlast() { return plast; }

	Lista() {
		pfirst = nullptr;
		plast = nullptr;
		size = 0;

	}

	~Lista() {
		Elemento<T>* patual = pfirst;
		Elemento<T>* pnext = pfirst->pnext;
		while (patual != NULL) {
			delete(patual);
			patual = pnext;
			pnext = patual->pnext;

		}
	}

	void clear() {
		Elemento<T>* paux1 = pfirst;
		Elemento<T>* paux2 = paux1;
		int i = 0;

		while ((paux1 != nullptr) && (i < size)) {
			delete(paux1->getData());
			paux2 = paux1->getNext();
			delete(paux1);
			paux1 = paux2;
			i++;

		}

		pfirst = NULL;
		plast = NULL;
		size = 0;

	}

	void setNode(Elemento<T>* pnode) {
		if (pnode != NULL) {
			if (pfirst == NULL) {
				pfirst = pnode;
				plast = pnode;

			}
			else {
				plast->setNext(pnode);
				plast = pnode;

			}
			size++;

		}
		else {
			cout << "Erro" << endl;

		}
	}

	T* operator [] (int index) {
		if (index >= size || index < 0) {
			cout << "Erro" << endl;

		}

		Elemento<T>* paux = pfirst;
		for (int i = 0; i < index; i++) {
			paux = paux->getNext();

		}

		if (paux == NULL) {
			cout << "Erro" << endl;
			exit(1);

		}
		return paux->getData();

	}

	void push(T* pdata) {
		Elemento<T>* ptr = new Elemento<T>;
		ptr->setData(pdata);

		if (ptr == nullptr)
			return;

		size++;

		if (pfirst == nullptr) {

			pfirst = ptr;
			plast = ptr;
		}

		else {
			plast->pnext = ptr;
			plast = ptr;
		}
	}

	void push(Elemento<T>* pdata) {

		if (pdata == nullptr) { return; }
		size++;
		if (pfirst == nullptr) {
			pfirst = pdata;
			plast = pdata;

		}
		else {

			plast->pnext = pdata;
			plast = pdata;
		}
	}

	T* pop(T* pdata) {
		Elemento<T>* paux = pfirst;
		Elemento<T>* pprev = NULL;

		while (paux != NULL) {
			if (paux->getData() == pdata) {
				if (paux == pfirst) {
					pfirst = paux->getNext();
				}

				else if (paux == plast) {
					plast = pprev;
					pprev->setNext(NULL);
				}
				else {
					pprev->setNext(paux->getNext());
				}
				delete(paux);
				size--;
				return pdata;

			}
			pprev = paux;
			paux = paux->getNext();

		}
		return nullptr;

	}

	T* pop(int index) {
		if ((index >= size) || (index < 0)) {
			cout << "Erro" << endl;
			exit(1);

		}

		Elemento<T>* paux = pfirst;
		Elemento<T>* pprev = NULL;

		for (int i = 0; i < index; i++) {
			pprev = paux;
			paux = paux->getNext();
		}

		if (paux == pfirst) {
			pfirst = paux->getNext();
		}

		else if (paux == plast) {
			plast = pprev;
			pprev->setNext(nullptr);
		}

		else {
			pprev->setNext(paux->getNext());
		}

		T* pdata = paux->getData();

		delete (paux);
		size--;

		return pdata;

	}

};