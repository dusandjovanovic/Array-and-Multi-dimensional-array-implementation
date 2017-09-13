// Lab0109.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

int main()
{
	Matrix matrix(3, 3);
	Matrix matrix2(4, 5);

	matrix.setAt(0, 0, 1);
	matrix.setAt(0, 1, 2);
	matrix.setAt(0, 2, 3);
	matrix.setAt(1, 0, 4);
	matrix.setAt(1, 1, 5);
	matrix.setAt(1, 2, 6);
	matrix.setAt(2, 0, 4);
	matrix.setAt(2, 1, 5);
	matrix.setAt(2, 2, 6);

	matrix.showAll();

	multiDim vector1(1, 8, 22);

	vector1.showAll();

	Matrix result = matrix.multiplyVector(vector1);
	cout << endl;
	result.showAll();

	system("pause");
	return 0;
}

