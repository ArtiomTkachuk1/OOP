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
		friend ostream&operator<<(ostream&, const Vector<T>&);*/
		friend Vector<T> operator+(const Vector<T>& a, const Vector<T>&b) {
			if (a.cnt != b.cnt)
				throw("Операция невозможна");
			Vector c(a.cnt);
			for (int i = 0; i < c.cnt; i++)
				c.ptr[i] = a.ptr[i] + b.ptr[i];
			return c;
		};
		friend Vector<T> operator+(const Vector<T>& a, const T& b) {
			Vector<T> c;
			c.cnt = a.cnt;
			c.ptr = new T[c.cnt];
			if (c.ptr == NULL) throw ("Не удалось выделить память");
			for (int i = 0; i < a.cnt; i++)
				c.ptr[i] = a.ptr[i] + b;
			return c;
		};
		friend Vector<T> operator+(const T& b, const Vector<T>& a) {
			return(a + b);
		}
		friend Vector<T> operator-(const Vector<T>& a, const Vector<T>& b) {
			if (a.cnt != b.cnt)
				throw("Операция невозможна");
			Vector<T> c(a.cnt);
			for (int i = 0; i < c.cnt; i++)
				c.ptr[i] = a.ptr[i] - b.ptr[i];
			return c;
		};
		friend Vector<T> operator-(const Vector<T>& a, const T& b) {
			Vector<T> c;
			c.cnt = a.cnt;
			c.ptr = new T[c.cnt];
			if (c.ptr == NULL) throw ("Не удалось выделить память");
			for (int i = 0; i < a.cnt; i++)
				c.ptr[i] = a.ptr[i] - b;
			return c;
		};
		friend Vector<T> operator-(const T& b, const Vector<T>& a) {
			return((-1)*(a - b));
		};
		friend Vector<T> operator*(const Vector<T>& a, const Vector<T>& b) {
			if (a.cnt != b.cnt)
				throw("Операция невозможна");
			Vector<T> c(a.cnt);
			for (int i = 0; i < c.cnt; i++)
				c.ptr[i] = a.ptr[i] * b.ptr[i];
			return c;
		};
		friend Vector<T> operator*(const Vector<T>& a, const T& b) {
			Vector<T> c;
			c.cnt = a.cnt;
			c.ptr = new T[c.cnt];
			if (c.ptr == NULL)
				throw ("Не удалось выделить память");
			for (int i = 0; i < a.cnt; i++)
				c.ptr[i] = a.ptr[i] * b;
			return c;
		};
		friend Vector<T> operator*(const T& b, const Vector<T>& a) {
			return(a*b);
		};
		friend Vector<T> operator/(const Vector<T>& a, const Vector<T>& b) {
			if (a.cnt != b.cnt)
				throw("Операция невозможна");
			for (int i = 0; i < b.cnt; i++)
				if (b.ptr[i] == 0)
					throw("Деление на ноль невозможно");
			Vector<T> c(a.cnt);
			for (int i = 0; i < c.cnt; i++)
				c.ptr[i] = a.ptr[i] / b.ptr[i];
			return c;
		};
		friend Vector<T> operator/(const Vector<T>& a, const T& b) {
			if (b == 0)throw("Деление на ноль невозможно");
			Vector<T> c;
			c.cnt = a.cnt;
			c.ptr = new T[c.cnt];
			if (c.ptr == NULL)
				throw ("Не удалось выделить память");
			for (int i = 0; i < a.cnt; i++)
				c.ptr[i] = a.ptr[i] / b;
			return c;
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
				cout << "Введите сnt:";
				o >> tmp;
				if (tmp < 0)cout << "cnt должна быть больше нуля. Повторите ввод" << endl;
			}
			a.cnt = tmp;
			delete[] a.ptr;
			a.ptr = new T[a.cnt];
			if (a.ptr == NULL)
				throw ("Не удалось выделить память");
			for (int i = 0; i < a.cnt; i++) {
				cout << "ptr[" << i << "]=";
				o >> a.ptr[i];
				cout << endl;
			}
			return o;
		};
};

#endif