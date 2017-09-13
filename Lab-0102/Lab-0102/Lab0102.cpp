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

	int expArray[3] = { 0, 1, 2 };
	double coefArray[3] = { 12, 7, 4 };

	/*poly2.addCoefficent(0, 11);
	poly2.addCoefficent(1, 4);
	poly2.addCoefficent(2, 18);
	poly2.addCoefficent(3, 0);
	poly2.addCoefficent(4, 1);*/
	poly2.addArray(expArray, coefArray, 3);

	poly1.showAll();
	poly2.showAll();

	Polynom poly3 = poly1.Multiply(poly1, poly2);
	poly3.showAll();

	system("pause");
	return 0;
}

