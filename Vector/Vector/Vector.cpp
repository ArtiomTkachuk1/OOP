#include "pch.h"
#include"Vector.h"
#include <iostream>
using namespace std;
template <class T>
Vector<T>::Vector() {
	cnt = 6;
	ptr = new T[cnt];
	if (ptr == NULL)
		throw ("Не удалось выделить память");
}
template <class T>
Vector<T>::Vector(const int& CountElement) {
	if (CountElement <= 0)
		throw ("Количество элементов должно быть больше нуля");
	cnt = CountElement;
	ptr = new T[CountElement];
	if (ptr == NULL) 
		throw ("Не удалось выделить память");
}
template <class T>
Vector<T>::Vector(const int& CountElement, T* newptr) {
	if (CountElement <= 0)
		throw ("Количество элементов должно быть больше нуля");
	cnt = CountElement;
	ptr = new T[CountElement];
	if (ptr == NULL) 
		throw ("Не удалось выделить память");
	for (int i = 0; i < cnt; i++)
		ptr[i] = newptr[i];
}
template <class T>
Vector<T>::Vector(const Vector& a) {
	cnt = a.cnt;
	ptr = new T[cnt];
	if (ptr == NULL) 
		throw ("Не удалось выделить память");
	for (int i = 0; i < cnt; i++)
		ptr[i] = a.ptr[i];
}
template <class T>
Vector<T>::~Vector() {
	delete[] ptr;
}
template <class T>
int Vector<T>::Getcnt() {
	return cnt;
}
template <class T>
bool Vector<T>::Setcnt(const int& newcnt) {
	if (newcnt <= 0) {
		cout << "Некорректный индекс"<<endl;
		return false;
	}
	cnt = newcnt;
	return true;
}
template <class T>
T* Vector<T>::Getptr() {
	return ptr;
}
template <class T>
bool Vector<T>::Setptr(T* newptr) {
	for(int i=0;i<cnt;i++)
		ptr[i]=newptr[i];
	return true;
}
template <class T>
T Vector<T>::GetElement(const int& num) {
	if ((num < 0)||(num>=cnt))
		throw ("Некорректный индекс");
	return ptr[num];
}
template <class T>
Vector<T> Vector<T>::operator=(const Vector<T>& a) {
	cnt = a.cnt;
	for (int i = 0; i < cnt; i++)
		ptr[i] = a.ptr[i];
	return *this;
}
template <class T>
bool Vector<T>::operator==(const Vector& A) {
	if (cnt == A.cnt) {
		for (int i = 0; i < cnt; i++)
			if (ptr[i] != A.ptr[i])return false;
		return true;
	}
	return false;
}
template <class T>
bool Vector<T>::operator!=(const Vector& A) {
	if (cnt == A.cnt) {
		for (int i = 0; i < cnt; i++)
			if (ptr[i] != A.ptr[i])return true;
		return false;
	}
	return true;
}
template <class T>
bool Vector<T>::addElement(const T& newElement) {
	T* tmp = new T[cnt + 1];
	if (tmp == NULL) 
		throw ("Не удалось выделить память");
	for (int i = 0; i < cnt; i++)
		tmp[i] = ptr[i];
	tmp[cnt] = newElement;
	delete[] ptr;
	ptr = tmp;
	cnt++;
	return true;
}
template <class T>
bool Vector<T>::delElement(const int& indexElement) {
	if ((indexElement < 0) || (indexElement >= cnt))
		throw ("Некорректный индекс");
	T* tmp = new T[cnt - 1];
	if (tmp == NULL) 
		throw ("Не удалось выделить память");
	int j = 0;
	for (int i = 0; i < cnt; i++)
		if (i != indexElement) {
			tmp[j] = ptr[i];
			j++;
		}
	delete[] ptr;
	ptr = tmp;
	cnt--;
	return true;
}
/*template <class T>
Vector<T> operator+(const Vector<T>& a, const Vector<T>&b) {
	if (a.cnt != b.cnt)
		throw("Операция невозможна");
	Vector c(a.cnt);
	for (int i = 0; i < c.cnt; i++)
		c.ptr[i] = a.ptr[i] + b.ptr[i];
	return c;
}
template <class T>
Vector<T> operator+(const Vector<T>& a, const T& b){
	Vector<T> c;
	c.cnt = a.cnt;
	c.ptr = new T[c.cnt];
	if (c.ptr == NULL) throw ("Не удалось выделить память");
	for (int i = 0; i < a.cnt; i++)
		c.ptr[i] = a.ptr[i] + b;
	return c;
}
template <class T>
Vector<T> operator+(const T& b, const Vector<T>& a){
	return(a + b);
}
template <class T>
Vector<T> operator-(const Vector<T>& a, const Vector<T>& b){
	if (a.cnt != b.cnt)
		throw("Операция невозможна");
	Vector<T> c(a.cnt);
	for (int i = 0; i < c.cnt; i++)
		c.ptr[i] = a.ptr[i] - b.ptr[i];
	return c;
}
template <class T>
Vector<T> operator-(const Vector<T>& a, const T& b){
	Vector<T> c;
	c.cnt = a.cnt;
	c.ptr = new T[c.cnt];
	if (c.ptr == NULL) throw ("Не удалось выделить память");
	for (int i = 0; i < a.cnt; i++)
		c.ptr[i] = a.ptr[i] - b;
	return c;
}
template <class T>
Vector<T> operator-(const T& b,const Vector<T>& a){
	return((-1)*(a - b));
}
template <class T>
Vector<T> operator*(const Vector<T>& a,const Vector<T>& b){
	if (a.cnt != b.cnt)
		throw("Операция невозможна");
	Vector<T> c(a.cnt);
	for (int i = 0; i < c.cnt; i++)
		c.ptr[i] = a.ptr[i] * b.ptr[i];
	return c;
}
template <class T>
Vector<T> operator*(const Vector<T>& a, const T& b){
	Vector<T> c;
	c.cnt = a.cnt;
	c.ptr = new T[c.cnt];
	if (c.ptr == NULL) 
		throw ("Не удалось выделить память");
	for (int i = 0; i < a.cnt; i++)
		c.ptr[i] = a.ptr[i] * b;
	return c;
}
template <class T>
Vector<T> operator*(const T& b, const Vector<T>& a){
	return(a*b);
}
template <class T>
Vector<T> operator/(const Vector<T>& a, const Vector<T>& b){
	if (a.cnt != b.cnt)
		throw("Операция невозможна");
	for(int i=0;i<b.cnt;i++)
		if(b.ptr[i]==0)
			throw("Деление на ноль невозможно");
	Vector<T> c(a.cnt);
	for (int i = 0; i < c.cnt; i++)
		c.ptr[i] = a.ptr[i]/b.ptr[i];
	return c;
}
template <class T>
Vector<T> operator/(const Vector<T>& a, const T& b){
	if (b == 0)throw("Деление на ноль невозможно");
	return(a*T(1.0 / b));
}
template <class T>
ostream&operator<<(ostream& o, const Vector<T>& a){
	o << endl<<"cnt="<<a.cnt<<endl<<"ptr:";
	for (int i = 0; i < a.cnt; i++) {
		if (i % 6 == 0)o << endl;
		o << a.ptr[i];
		if (i != a.cnt - 1)o << ", ";
		else o << ".";
	}
	o << endl;
	return o;
}
template <class T>
istream&operator>>(istream& o, Vector<T>& a) {
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
		cout << "ptr[" << i<<"]=";
		o >> a.ptr[i];
		cout << endl;
	}
	return o;
}*/
template class Vector<double>;
template class Vector<int>;