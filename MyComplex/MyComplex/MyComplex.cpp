#include <iostream>
#include "pch.h"
#include "MyComplex.h"
using namespace std;
MyComplex::MyComplex(){
	Re = 0;
	Im = 0;
}
MyComplex::MyComplex(const double& InitRe,const double& InitIm) {
	Re = InitRe;
	Im = InitIm;
}
MyComplex::~MyComplex() {
	cout << "Destructor"<<endl;
}
double MyComplex::GetRe() {
	return Re;
}
double MyComplex::GetIm() {
	return Im;
}
int MyComplex::SetRe(const double& newVal) {
	Re = newVal;
	return 1;
}
int MyComplex::SetIm(const double& newVal) {
	Im = newVal;
	return 1;
}
bool MyComplex::operator==(const MyComplex& A) {
	if ((Re == A.Re) && (Im == A.Im))
		return true;
	else return false;
}
bool MyComplex::operator!=(const MyComplex& A) {
	if ((Re != A.Re) || (Im != A.Im))
		return true;
	else return false;
}
MyComplex MyComplex::operator=(const MyComplex& a) {
	Re = a.Re;
	Im = a.Im;
	return *this;
}
MyComplex operator+(const MyComplex& a,const MyComplex& b) {
	MyComplex c;
	c.Re = a.Re + b.Re;
	c.Im = a.Im + b.Im;
	return c;
}
MyComplex operator+(const MyComplex& a,const double& b) {
	MyComplex c;
	c.Re=a.Re + b;
	c.Im=a.Im;
	return c;
}
MyComplex operator+(const double& b,const MyComplex& a) {
	return (a + b);
}
MyComplex operator-(const MyComplex& a,const MyComplex& b) {
	MyComplex c;
	c.Re = a.Re - b.Re;
	c.Im = a.Im - b.Im;
	return c;
}
MyComplex operator-(const MyComplex& a,const double& b) {
	MyComplex c;
	c.Re = a.Re - b;
	c.Im = a.Im;
	return c;
}
MyComplex operator-(const double& b, const MyComplex& a) {
	MyComplex c;c.Re = b-a.Re;
	c.Im = a.Im;
	return c;
}
MyComplex operator*(const MyComplex& a, const MyComplex& b) {
	MyComplex c;
	c.Re = a.Re*b.Re-a.Im*b.Im;
	c.Im = a.Re*b.Im+a.Im*b.Re;
	return c;
}
MyComplex operator*(const MyComplex& a, const double& b) {
	MyComplex c;
	c.Re=a.Re*b;
	c.Im=a.Im*b;
	return c; 
}
MyComplex operator*(const double& b,const MyComplex& a) {
	return (a*b);
}
MyComplex operator/(const MyComplex& a, const MyComplex& b) {
	double znam = b.Re*b.Re + b.Im*b.Im;
	if (znam != 0) {
		MyComplex c;
		c.Re = a.Re*b.Re+a.Im*b.Im;
		c.Im = b.Re*a.Im-a.Re*b.Im;
		return c;
	}
	else {
		cout << "Попытка деления на ноль";
		return a;
	}
}
MyComplex operator/(const MyComplex& a, const double& b) {
	if (b != 0) {
		double d = 1.0 / b;
		return (a*d);
	}
	else {
		cout << "Попытка деления на ноль";
		return a;
	}
}
ostream& operator<<(ostream& o, const MyComplex& b) {
	double buf = b.Im;
	o << b.Re;
	if (buf != 0) {
		if (buf > 0) o << '+';
		if (buf != 1.0)o << buf;
		o << 'i';
	}
	return o;
}
istream& operator>>(istream& o, MyComplex& b) {
	double r, i;
	cout << "Введите Re" << endl;
	o >> r;
	cout << "Введите Im" << endl;
	o >> i;
	b.SetRe(r);
	b.SetIm(i);
	/*b.Re=r;
	b.Im=i;*/
	return o;
}