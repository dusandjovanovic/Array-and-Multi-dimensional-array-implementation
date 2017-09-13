#pragma once
#include <iostream>
using namespace std;

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

	Matrix multiplyTwo(Matrix& matrix) {
		if (noColumns != matrix.noRows)
			throw std::exception();

		Matrix* tmp = new Matrix(this->noRows, matrix.noColumns);

		for (long i = 0; i < noRows; i++) {
			long j = 0;
			long k = 0;
			double multiplier;
			for (j = 0; j < matrix.noColumns; j++) {
				multiplier = 0;
				for (k = 0; k < matrix.noRows; k++)
					multiplier += getAt(i, k)*matrix.getAt(k, j);
				tmp->setAt(i, j, multiplier);
			}
		}

		return *tmp;
	}
};