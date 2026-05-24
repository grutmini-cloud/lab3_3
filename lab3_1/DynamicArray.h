#pragma once

#include <stdexcept>

template <class T>
class DynamicArray {
private:
    T* data;
    int size;

public:

    // Конструктор
    DynamicArray(int size) {
        if (size < 0) {
            throw std::invalid_argument("Size cannot be negative");
        }

        this->size = size;
        data = new T[size];
    }

    // Конструктор копирования
    DynamicArray(const DynamicArray<T>& other) {
        size = other.size;

        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Деструктор
    ~DynamicArray() {
        delete[] data;
    }

    // Получение элемента
    T Get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        return data[index];
    }

    // Изменение элемента
    void Set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        data[index] = value;
    }

    // Размер массива
    int GetSize() const {
        return size;
    }

    // Изменение размера
    void Resize(int newSize) {
        if (newSize < 0) {
            throw std::invalid_argument("Size cannot be negative");
        }

        T* newData = new T[newSize];

        int limit;

        if (newSize < size) {
            limit = newSize;
        } else {
            limit = size;
        }

        for (int i = 0; i < limit; i++) {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        size = newSize;
    }

    // Добавление
    void Append(T item) {
        Resize(size + 1);

        data[size - 1] = item;
    }

    // Удаление элемента
    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        Resize(size - 1);
    }
};