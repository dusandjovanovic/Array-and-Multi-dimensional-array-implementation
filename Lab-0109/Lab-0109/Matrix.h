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

	double getIndex(long index) {
		return data[index];
	}

	long getDimension() {
		return dimension;
	}
};

class Matrix {
protected:
	long noRows;
	long noColumns;
	double* data;
public:
	Matrix(long rows, long columns) {
		noRows = rows;
		noColumns = columns;
		data = new double[noRows*noColumns];
		for (long i = 0; i < noRows*noColumns; i++)
			data[i] = NULL;
	}

	~Matrix() {
		delete[] data;
	}

	double getAt(long i, long j) {
		long offset = noColumns * i + j;
		return data[offset];
	}

	void setAt(long i, long j, double object) {
		long offset = noColumns * i + j;
		data[offset] = object;
	}

	void showAll() {
		for (long i = 0; i < noRows; i++) {
			for (long j = 0; j < noColumns; j++)
				cout << getAt(i, j) << " ";
			cout << endl;
		}
		cout << endl;
	}

	void addRow(double* args, int length) {
		if (length != noColumns)
			return;
		long position;
		for (position = 0; position < length; position++)
			if (getAt(position, 0) == NULL)
				break;
		if (position < noRows) {
			for (long j = 0; j < length; j++)
				setAt(position, j, args[j]);
		}
	}

	void addRowDecreasing(double* args, int length) {
		if (length != noColumns)
			return;
		long position;
		for (position = 0; position < length; position++)
			if (getAt(position, 0) == NULL)
				break;
		if (position < noRows) {
			for (long j = noColumns - 1, i = 0; j >= 0; j--, i++)
				setAt(position, j, args[i]);
		}
	}

	void addRowWhole(double* args, int length) {
		long position;
		for (position = 0; position < noRows; position++)
			if (getAt(position, 0) == NULL)
				break;
		if (position < noRows) {
			for (long j = 0, k = 0; j < length; j++, k++)
				if(k < noColumns)
					setAt(position, k, args[j]);
				else {
					k = 0;
					++position;
					setAt(position, k, args[j]);
				}
		}
	}

	void addColumn(double* args, int length) {
		if (length != noRows)
			return;
		long position;
		for (position = 0; position < length; position++)
			if (getAt(0, position) == NULL)
				break;
		if (position < noColumns) {
			for (long j = 0; j < length; j++)
				setAt(j, position, args[j]);
		}
	}

	Matrix multiplyVector(multiDim vector) {
		if (noRows != vector.getDimension())
			throw new exception();
		Matrix* tmp = new Matrix(vector.getDimension(), 1);
		for (unsigned long i = 0; i < noRows; i++) {
			double multiplication = 0;
			for (unsigned long j = 0; j < noColumns; j++)
				multiplication += vector.getIndex(i)*getAt(i, j);
			tmp->setAt(i, 0, multiplication);
		}
		return *tmp;
	}
};