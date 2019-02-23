#include "pch.h"
#include "MyArray.h"
template<class T>
MyArray<T>::MyArray(){
	ptr= new T*[5];
	if (*ptr == NULL)
		throw "Не удалось выделить память";
	for (int i = 0; i < 5; i++) {
		ptr[i] = new T[5];
		if (ptr[i] == NULL)
			throw "Не удалось выделить память";
	}
	CountRow = 5;
	CountCols = 5;
}
template<class T>
MyArray<T>::MyArray(const int&NewCountRow, const int&NewCountCols) {
	if ((NewCountRow <= 0) || (NewCountCols <= 0))
		throw "Недопустимые значения индексов";
	ptr = new T*[NewCountRow];
	if (*ptr == NULL)
		throw "Не удалось выделить память";
	for (int i = 0; i < NewCountRow; i++) {
		ptr[i] = new T[NewCountCols];
		if (ptr[i] == NULL)
			throw "Не удалось выделить память";
	}
	CountRow = NewCountRow;
	CountCols = NewCountCols;
}
template<class T>
MyArray<T>::MyArray(const MyArray<T>& a){
	ptr = new T*[a.CountRow];
	if (*ptr == NULL)
		throw "Не удалось выделить память";
	for (int i = 0; i < a.CountRow; i++) {
		ptr[i] = new T[a.CountCols];
		if (ptr[i] == NULL)
			throw "Не удалось выделить память";
	}
	CountRow = a.CountRow;
	CountCols = a.CountCols;
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCols; j++)
			ptr[i][j] = a.ptr[i][j];
}
template<class T>
MyArray<T>::~MyArray() {
	for (int i = 0; i < CountRow; i++)
		delete[] ptr[i];
	delete[] ptr;
	CountRow = 0;
	CountCols = 0;
}
template<class T>
T** MyArray<T>::Getptr() {
	T** tmp = new T*[CountRow];
	if (*tmp == NULL)
		throw("Не удалось выделить память");
	for (int i = 0; i < CountRow; i++) {
		tmp[i] = new T[CountCols];
		if (tmp[i] == NULL)
			throw ("Не удалось выделить память");
	}
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCols; j++)
			tmp[i][j] = ptr[i][j];
	return tmp;
}
template<class T>
int MyArray<T>::GetCountRow() {
	return CountRow;
}
template<class T>
int MyArray<T>::GetCountCols() {
	return CountCols;
}
template<class T>
bool MyArray<T>::Setptr(T** newptr) {
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCols; j++)
			ptr[i][j] = newptr[i][j];
	return true;
}
template<class T>
bool MyArray<T>::SetCountRow(const int& newCountRow) {//дописать!!!!!
	if (newCountRow <= 0)
		throw("Количество строк должно быть больше нуля");
	T** tmp = new T*[newCountRow];
	if (*tmp == NULL)
		throw("Не удалось выделить память");
	for (int i = 0; i < newCountRow; i++) {
		tmp[i] = new T[CountCols];
		if (tmp[i] == NULL)
			throw ("Не удалось выделить память");
	}
	CountRow = newCountRow;
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCols; j++)
			tmp[i][j] = ptr[i][j];
	for (int i = 0; i < CountRow; i++)
		delete[] ptr[i];
	delete[] ptr;
	ptr = tmp;
	return true;
}
template<class T>
bool MyArray<T>::SetCountCols(const int& newCountCols){//дописать!!!!!
	if (newCountCols <= 0)
		throw("Количество столбцов должно быть больше нуля");
	T** tmp = new T*[CountRow];
	if (*tmp == NULL)
		throw("Не удалось выделить память");
	for (int i = 0; i < CountRow; i++) {  
		tmp[i] = new T[newCountCols];
		if (tmp[i] == NULL)
			throw ("Не удалось выделить память");
	}
	CountCols = newCountCols;
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCols; j++)
			tmp[i][j] = ptr[i][j];
	for (int i = 0; i < CountRow; i++)
		delete[] ptr[i];
	delete[] ptr;
	ptr = tmp;
	return true;
}
template<class T>
T MyArray<T>::GetElement(const int& i, const int& j){
	if ((i < 0) || (j < 0) || (i >= CountCols) || (j >= CountRow))
		throw("Некорректный индекс");
	return ptr[i][j];
}
template<class T>
MyArray<T> MyArray<T>::operator=(const MyArray<T>& a){
	for (int i = 0; i < CountRow; i++)
		delete[] ptr[i];
	delete[] ptr;
	ptr = new T*[a.CountRow];
	if (*ptr == NULL)
		throw "Не удалось выделить память";
	for (int i = 0; i < a.CountRow; i++) {
		ptr[i] = new T[a.CountCols];
		if (ptr[i] == NULL)
			throw "Не удалось выделить память";
	}
	CountRow = a.CountRow;
	CountCols = a.CountCols;
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCols; j++)
			ptr[i][j] = a.ptr[i][j];
	return *this;
}
template<class T>
bool MyArray<T>::operator==(const MyArray<T>& a){
	if ((CountRow != a.CountRow) || (CountCols != a.CountCols))
		return false;
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCols; j++)
			if (a.ptr[i][j] != ptr[i][j])return false;
	return true;
}
template<class T>
bool MyArray<T>::operator!=(const MyArray<T>& a){
	if ((CountRow != a.CountRow) || (CountCols != a.CountCols))
		return true;
	for (int i = 0; i < CountRow; i++)
		for (int j = 0; j < CountCols; j++)
			if (a.ptr[i][j] != ptr[i][j])return true;
	return false;
}
template class MyArray<double>;
template class MyArray<int>;