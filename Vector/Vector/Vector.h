#pragma once
#ifndef Vector_h
#define Vector_h
#include<iostream>
using namespace std;
template<class T>
class Vector{
	private:
		int cnt;
		T* ptr;
	public:
		Vector<T>();
		Vector<T>(const int& CountElement);
		Vector<T>(const int&, T*);
		Vector<T>(const Vector<T>&);
		~Vector<T>();
		int Getcnt();
		bool Setcnt(const int&);
		T* Getptr();
		bool Setptr(T*);
		T GetElement(const int&);
		Vector<T> operator=(const Vector<T>&);
		bool operator==(const Vector<T>&);
		bool operator!=(const Vector<T>&);
		bool addElement(const T&);
		bool delElement(const int&);
		/*friend Vector<T> operator+(const Vector<T>&,const Vector<T>&);
		friend Vector<T> operator+(const Vector<T>&, const T&);
		friend Vector<T> operator+(const T&, const Vector<T>&);
		friend Vector<T> operator-(const Vector<T>&, const Vector<T>&);
		friend Vector<T> operator-(const Vector<T>&, const T&);
		friend Vector<T> operator-(const T&, const Vector<T>&);
		friend Vector<T> operator*(const Vector<T>&, const Vector<T>&);
		friend Vector<T> operator*(const Vector<T>&, const T&);
		friend Vector<T> operator*(const T&, const Vector<T>&);
		friend Vector<T> operator/(const Vector<T>&, const Vector<T>&);
		friend Vector<T> operator/(const Vector<T>&, const T&);
		friend ostream&operator<<(ostream&, const Vector<T>&);
		friend istream&operator>>(istream&, const Vector<T>&);*/
		friend Vector<T> operator+(const Vector<T>& A, const Vector<T>&B) {
			if (A.cnt != B.cnt)
				throw("Операция невозможна");
			Vector C(A.cnt);
			for (int i = 0; i < C.cnt; i++)
				C.ptr[i] = A.ptr[i] + B.ptr[i];
			return C;
		};
		friend Vector<T> operator+(const Vector<T>& A, const T& b) {
			Vector<T> C(A.cnt);
			for (int i = 0; i < A.cnt; i++)
				C.ptr[i] = A.ptr[i] + b;
			return C;
		};
		friend Vector<T> operator+(const T& a, const Vector<T>& B) {
			return(B + a);
		}
		friend Vector<T> operator-(const Vector<T>& A, const Vector<T>& B) {
			return (A+((-1)*B));
		};
		friend Vector<T> operator-(const Vector<T>& A, const T& b) {
			return (A+(-1)*b);
		};
		friend Vector<T> operator-(const T& a, const Vector<T>& B) {
			return(a +((-1)*B));
		};
		friend Vector<T> operator*(const Vector<T>& A, const Vector<T>& B) {
			if (A.cnt != B.cnt)
				throw("Операция невозможна");
			Vector<T> C(A.cnt);
			for (int i = 0; i < C.cnt; i++)
				C.ptr[i] = A.ptr[i] * B.ptr[i];
			return C;
		};
		friend Vector<T> operator*(const Vector<T>& A, const T& b) {
			Vector<T> C(A.cnt);
			for (int i = 0; i < A.cnt; i++)
				C.ptr[i] = A.ptr[i] * b;
			return C;
		};
		friend Vector<T> operator*(const T& a, const Vector<T>& B) {
			return(B*a);
		};
		friend Vector<T> operator/(const Vector<T>& A, const Vector<T>& B) {
			if (A.cnt != B.cnt)
				throw("Операция невозможна");
			for (int i = 0; i < B.cnt; i++)
				if (B.ptr[i] == 0)
					throw("Деление на ноль невозможно");
			Vector<T> C(A.cnt);
			for (int i = 0; i < C.cnt; i++)
				C.ptr[i] = A.ptr[i] / B.ptr[i];
			return C;
		};
		friend Vector<T> operator/(const Vector<T>& A, const T& b) {
			if (b == 0)throw("Деление на ноль невозможно");
			Vector<T> C(A.cnt);
			for (int i = 0; i < A.cnt; i++)
				C.ptr[i] = A.ptr[i] / b;
			return C;
		};
		friend ostream&operator<<(ostream& o, const Vector<T>& a) {
			o << endl << "cnt=" << a.cnt << endl << "ptr:";
			for (int i = 0; i < a.cnt; i++) {
				if (i % 6 == 0)o << endl;
				o << a.ptr[i];
				if (i != a.cnt - 1)o << ", ";
				else o << ".";
			}
			o << endl;
			return o;
		};
		friend istream&operator>>(istream& o, Vector<T>& a) {
			int tmp = 0;
			while (tmp <= 0) {
				cout << "Введите количество элементов:";
				o >> tmp;
				if (tmp <= 0)cout << "Количество элементов должно быть больше нуля. Повторите ввод" << endl;
			}
			delete[] a.ptr;
			a.ptr = new T[a.cnt];
			if (a.ptr == NULL)
				throw ("Не удалось выделить память");
			a.cnt = tmp;
			for (int i = 0; i < a.cnt; i++) {
				cout << "ptr[" << i << "]=";
				o >> a.ptr[i];
				cout << endl;
			}
			return o;
		};
};
#endif