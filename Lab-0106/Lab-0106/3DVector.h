#pragma once
#include <iostream>
using namespace std;

class multiDim {
protected:
	double* data;
	long dimension;
public:
	multiDim() {
		dimension = 3;
		data = new double[dimension];
	}

	multiDim(double x, double y, double z) {
		dimension = 3;
		data = new double[dimension];
		data[0] = x;
		data[1] = y;
		data[2] = z;
	}

	double dot(multiDim& vector) {
		double result = 0;
		for (long i = 0; i < dimension; i++)
			result += data[i] * vector.data[i];
		return result;
	}

	multiDim cross(multiDim& vector) {
		multiDim result(0, 0, 0);
		result.data[0] = data[1] * vector.data[2] - data[2] * vector.data[1];
		result.data[1] = data[2] * vector.data[0] - data[0] * vector.data[2];
		result.data[2] = data[0] * vector.data[1] - data[1] * vector.data[0];
		return result;
	}

	void showAll() {
		for (long i = 0; i < dimension; i++)
			cout << data[i] << " | ";
		cout << endl;
	}

	void reinitialize() {
		data[0] = data[1] = data[2] = 0;
	}
};