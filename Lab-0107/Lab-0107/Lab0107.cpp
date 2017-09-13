// Lab0107.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

int main()
{
	Matrix matrix(5, 5);

	double argsToAdd[5] = { 0, 1, 2, 3, 4 };
	matrix.addRowDecreasing(argsToAdd, 5);
	double argsToAdd2[5] = { 1, 2, 2, 2, 2 };
	matrix.addRowDecreasing(argsToAdd2, 5);
	double argsToAdd3[5] = { 0, 0, 5, 9, 6 };
	matrix.addRowDecreasing(argsToAdd3, 5);
	double argsToAdd4[5] = { 0, 3, 3, 3, 3 };
	matrix.addRowDecreasing(argsToAdd4, 5);
	double argsToAdd5[5] = { 8, 0, 0, 0, 1 };
	matrix.addRowDecreasing(argsToAdd5, 5);

	matrix.showAll();

	matrix.changeRows(0, 1);

	matrix.showAll();

	matrix.sortMatrix();
	matrix.showAll();

	system("pause");
    return 0;
}

