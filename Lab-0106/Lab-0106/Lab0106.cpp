// Lab0106.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "3DVector.h"

int main()
{
	multiDim vector1(1, 8, 22);
	multiDim vector2(11, 9, 33);

	vector1.showAll();
	vector2.showAll();

	multiDim vector = vector1.cross(vector2);
	vector.showAll();
	vector.reinitialize();
	
	double dot = vector1.dot(vector2);
	cout << endl << dot << endl;

	system("pause");
    return 0;
}

