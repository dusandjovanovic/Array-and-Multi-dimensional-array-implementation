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
		if (coefficent > 0)
			cout << " + " << coefficent << "x^" << exponent << " ";
		else
			cout << " - " << fabs(coefficent) << "x^" << exponent << " ";
	}

	bool isZero() {
		return exponent == 0;
	}

	double returnCoefficent() {
		return coefficent;
	}

	void enlarge(double coef, int exp) {
		coefficent += coef;
		exponent = exp;
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
		for (unsigned long i = 0; i < length; i++)
			data[i].show();
		cout << endl;
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

	void addArray(int* exp, double* coef, int no) {
		if (no != length)
			return;
		for (unsigned long i = 0; i < length; i++)
			this->addCoefficent(exp[i], coef[i]);
	}

	Polynom Divide(Polynom poly1, Polynom poly2) {
		long resultingLength = poly1.length + poly2.length - 1;
		Polynom result(resultingLength);
		for (long i = poly1.length - 1; i >= 0; i--) {
			int exponent = i;
			for (long j = poly2.length - 1; j >= 0; j--) {
				int resultExponent = exponent + j;
				double resultCoefficent = poly1.data[i].returnCoefficent() * poly2.data[j].returnCoefficent();
				result.data[resultExponent].enlarge(resultCoefficent, resultExponent);
			}
		}
		return result;
	}
};

