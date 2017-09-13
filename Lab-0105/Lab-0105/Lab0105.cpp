// Lab0102.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Polynom.h"

int main()
{
	Polynom poly1(4);
	Polynom poly2(3);

	poly1.addCoefficent(0, 14);
	poly1.addCoefficent(1, 0);
	poly1.addCoefficent(2, 4);
	poly1.addCoefficent(3, 2);

	poly1.showAll();

	Polynom poly3 = poly1.Derivative(&poly1, 2);		// Recursive derivative returned
	poly3.showAll();

	system("pause");
	return 0;
}

