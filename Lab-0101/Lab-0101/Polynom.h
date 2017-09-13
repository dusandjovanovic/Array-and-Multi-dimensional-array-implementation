#pragma once
#include <iostream>
using namespace std;

class Poly {
protected:
	double coefficent;
	int exponent;
public:
	Poly() {
		coefficent = 0;
		exponent = 0;
	}

	Poly(double coef, int exp) {
		coefficent = coef;
		exponent = exp;
	}

	~Poly() {
		
	}

	void show() {
		if (coefficent == 0)
			return;
		cout << coefficent << "x^" << exponent << " + ";
	}

	void showLast() {
		if (coefficent == 0)
			return;
		cout << coefficent << "x^" << exponent << endl;
	}

	bool isZero() {
		return exponent == 0;
	}

	double returnCoefficent() {
		return coefficent;
	}
};

class Polynom
{
protected:
	Poly* data;
	unsigned long length;
	long base;
public:

	Polynom(long newBase, long newLength) {
		length = newLength;
		data = new Poly[length];
		base = newBase;
	}

	Polynom(long newLength) {	// newLength: Polynom order
		length = newLength;
		data = new Poly[length];
		base = 0;
	}

	~Polynom() {

	}

	void showAll() {
		for (unsigned long i = 0; i < length - 1; i++)
			data[i].show();
		data[length - 1].showLast();
	}

	Poly& operator[](int index) {
		unsigned long offset = index - base;
		if (offset >= length)
			throw new std::exception("Offset outside of bounds.");
		return data[offset];
	}

	Polynom& operator=(const Polynom& object) {
		if (&object != this) {
			if (length != object.length) {
				if (data != nullptr)
					delete[] data;
				length = object.length;
				base = object.base;
				data = new Poly[length];
				for (unsigned long i = 0; i < length; i++)
					data[i] = object.data[i];
			}
		}
	}

	void addCoefficent(int exp, double coefficent) {
		if (exp >= length)
			return;
		if (data[exp].isZero())
			data[exp] = Poly(coefficent, exp);
	}

	Polynom Add(Polynom poly1, Polynom poly2) {
		unsigned long biggerLength;
		if (poly1.length > poly2.length)
			biggerLength = poly1.length;
		else
			biggerLength = poly2.length;
		Polynom result(biggerLength);
		for (unsigned long i = 0; i < biggerLength; i++) {
			double first, second;
			if (i >= poly1.length)
				first = 0;
			else 
				first = poly1[i].returnCoefficent();
			if (i >= poly2.length)
				second = 0;
			else
				second = poly2[i].returnCoefficent();

			result.addCoefficent(i, first + second);
		}
			
		return result;
	}
};

