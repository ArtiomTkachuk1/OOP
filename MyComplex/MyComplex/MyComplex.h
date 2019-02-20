#include<iostream>
using namespace std;
#pragma once
#ifndef MyComplex_h
#define MyComplex_h
	class MyComplex {
	private:
		double Re, Im;
	public:
		MyComplex();
		MyComplex(const double&,const double&);
		~MyComplex();
		double GetRe();
		int SetRe(const double&);
		double GetIm();
		int SetIm(const double &);
		bool operator==(const MyComplex&);
		bool operator!=(const MyComplex&);
		MyComplex operator=(const MyComplex&);
		friend MyComplex operator+(const MyComplex&,const MyComplex&);
		friend MyComplex operator+(const MyComplex&,const double&);
		friend MyComplex operator+(const double&,const MyComplex&);
		friend MyComplex operator-(const MyComplex&,const MyComplex&);
		friend MyComplex operator-(const MyComplex&,const double&);
		friend MyComplex operator-(const double&,const MyComplex&);
		friend MyComplex operator*(const MyComplex&,const MyComplex&);
		friend MyComplex operator*(const MyComplex&,const double&);
		friend MyComplex operator*(const double&,const MyComplex&);
		friend MyComplex operator/(const MyComplex&,const MyComplex&);
		friend MyComplex operator/(const MyComplex&,const double&);
		friend ostream&operator<<(ostream&,const MyComplex&);
		friend istream&operator>>(istream&,MyComplex&);
};
#endif