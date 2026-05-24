#pragma once

#include "DynamicArray.h"

#include <stdexcept>
#include <cmath>

template <class T>
class SquareMatrix {
private:

    DynamicArray<DynamicArray<T>*> data;

    int size;

public:

    SquareMatrix(int matrixSize)
        : data(matrixSize) {

        if (matrixSize <= 0) {
            throw std::out_of_range("Wrong matrix size");
        }

        size = matrixSize;

        for (int i = 0; i < size; i++) {
            data.Set(i, new DynamicArray<T>(size));
        }
    }

    SquareMatrix(const SquareMatrix<T>& other)
        : data(other.size) {

        size = other.size;

        for (int i = 0; i < size; i++) {

            data.Set(i, new DynamicArray<T>(size));

            for (int j = 0; j < size; j++) {
                data.Get(i)->Set(j, other.Get(i, j));
            }
        }
    }

    ~SquareMatrix() {

        for (int i = 0; i < size; i++) {
            delete data.Get(i);
        }
    }

    int GetSize() const {
        return size;
    }

    T Get(int row, int col) const {

        if (row < 0 || row >= size ||
            col < 0 || col >= size) {

            throw std::out_of_range("Wrong indexes");
        }

        return data.Get(row)->Get(col);
    }

    void Set(int row, int col, const T& value) {

        if (row < 0 || row >= size ||
            col < 0 || col >= size) {

            throw std::out_of_range("Wrong indexes");
        }

        data.Get(row)->Set(col, value);
    }

    SquareMatrix<T> operator+(const SquareMatrix<T>& other) const {

        if (size != other.size) {
            throw std::out_of_range("Different matrix sizes");
        }

        SquareMatrix<T> result(size);

        for (int i = 0; i < size; i++) {

            for (int j = 0; j < size; j++) {
                result.Set(i, j,
                    Get(i, j) + other.Get(i, j));
            }
        }

        return result;
    }

    SquareMatrix<T> MultiplyByScalar(const T& scalar) const {

        SquareMatrix<T> result(size);

        for (int i = 0; i < size; i++) {

            for (int j = 0; j < size; j++) {
                result.Set(i, j,
                    Get(i, j) * scalar);
            }
        }

        return result;
    }

    double Norm() const {

        double result = 0;

        for (int i = 0; i < size; i++) {

            for (int j = 0; j < size; j++) {
                result += std::abs(Get(i, j));
            }
        }

        return result;
    }

    void SwapRows(int firstRow, int secondRow) {

        if (firstRow < 0 || firstRow >= size ||
            secondRow < 0 || secondRow >= size) {

            throw std::out_of_range("Wrong row indexes");
        }

        for (int j = 0; j < size; j++) {

            T temp = Get(firstRow, j);

            Set(firstRow, j,Get(secondRow, j));

            Set(secondRow, j, temp);
        }
    }

    void SwapColumns(int firstCol, int secondCol) {

        if (firstCol < 0 || firstCol >= size ||
            secondCol < 0 || secondCol >= size) {

            throw std::out_of_range("Wrong column indexes");
        }

        for (int i = 0; i < size; i++) {

            T temp = Get(i, firstCol);

            Set(i, firstCol,Get(i, secondCol));

            Set(i, secondCol, temp);
        }
    }
};