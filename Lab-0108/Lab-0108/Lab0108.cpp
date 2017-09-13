// Lab0108.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

int main()
{
	Matrix matrix(2, 3);
	Matrix matrix2(3, 4);

	matrix.setAt(0, 0, 1);
	matrix.setAt(0, 1, 2);
	matrix.setAt(0, 2, 3);
	matrix.setAt(1, 0, 4);
	matrix.setAt(1, 1, 5);
	matrix.setAt(1, 2, 6);

	matrix.showAll();

	matrix2.setAt(0, 0, 1);
	matrix2.setAt(0, 1, 2);
	matrix2.setAt(0, 2, 3);
	matrix2.setAt(0, 3, 1);
	matrix2.setAt(1, 0, 1);
	matrix2.setAt(1, 1, 2);
	matrix2.setAt(1, 2, 3);
	matrix2.setAt(1, 3, 1);
	matrix2.setAt(2, 0, 1);
	matrix2.setAt(2, 1, 2);
	matrix2.setAt(2, 2, 3);
	matrix2.setAt(2, 3, 1);

	matrix2.showAll();

	Matrix matrix3 = matrix.multiplyTwo(matrix2);
	matrix3.showAll();

	system("pause");
	return 0;
}

