#pragma once
#pragma once
#include <iostream>
//creditos: https://www.youtube.com/channel/UCrNDrGwDXmBErjp0BGqqOUw

namespace Math {

	template <typename T>

	class Coordenada {
	public:
		T x;
		T y;

		Coordenada(T x, T y);
		~Coordenada();

		//sobrecarga de operadores
		void operator = (Coordenada <T> atributo);
		void operator += (Coordenada <T> soma);
		void operator -= (Coordenada <T> subtracao);
		void operator /= (double divisor);
		void operator *= (double multiplicador);

		Coordenada<T> operator + (Coordenada <T> soma);
		Coordenada<T> operator - (Coordenada <T> subtracao);
		Coordenada<T> operator * (Coordenada <T> multiplicacao);
		Coordenada<T> operator * (double multiplicador);
		Coordenada<T> operator / (Coordenada <T> divisao);
		Coordenada<T> operator / (double divisor);

	};

	typedef Coordenada<int> Coordenadai;
	typedef Coordenada<float> Coordenadaf;
	typedef Coordenada<double> Coordenadad;
	typedef Coordenada<unsigned int> Coordenadau;



	template <typename T>
	Coordenada<T>::Coordenada(T x, T y) {
		this->x = x;
		this->y = y;
	}

	template <typename T>
	Coordenada<T>::~Coordenada() {

	}

	template <typename T>
	void Coordenada<T>::operator = (Coordenada<T> atributo) {
		this->x = atributo.x;
		this->y = atributo.y;

	}

	template <typename T>
	void Coordenada<T>::operator += (Coordenada<T> soma) {
		this->x += soma.x;
		this->y += soma.y;

	}

	template <typename T>
	void Coordenada<T>::operator -= (Coordenada<T> subtracao) {
		this->x -= subtracao.x;
		this->y -= subtracao.y;

	}

	template <typename T>
	void Coordenada<T>::operator *= (double multiplicador) {
		this->x = this->x * multiplicador;
		this->y = this->y * multiplicador;

	}

	template <typename T>
	void Coordenada<T>::operator /= (double divisor) {
		this->x = this->x / divisor;
		this->y = this->y / divisor;

	}

	template <typename T>
	Coordenada<T> Coordenada<T>::operator + (Coordenada<T> adicao) {
		return Coordenada<T>(this->x + adicao.x, this->y + adicao.y);

	}

	template <typename T>
	Coordenada<T> Coordenada<T>::operator - (Coordenada<T> subtracao) {
		return Coordenada<T>(this->x - subtracao.x, this->y - subtracao.y);

	}

	template <typename T>
	Coordenada<T> Coordenada<T>::operator * (Coordenada<T> multiplicacao) {
		return Coordenada<T>(this->x * multiplicacao.x, this->y * multiplicacao.y);

	}

	template <typename T>
	Coordenada<T> Coordenada<T>::operator / (Coordenada<T> divisao) {
		return Coordenada<T>(this->x / divisao.x, this->y / divisao.y);

	}

	template <typename T>
	Coordenada<T> Coordenada<T>::operator  * (double multiplicador) {
		return Coordenada<T>(this->x * multiplicador, this->y * multiplicador);

	}

	template <typename T>
	Coordenada<T> Coordenada<T>::operator  / (double divisor) {
		return Coordenada<T>(this->x / divisor, this->y / divisor);

	}
}