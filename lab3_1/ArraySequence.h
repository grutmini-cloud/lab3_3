#pragma once

#include "Sequence.h"
#include "DynamicArray.h"

template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T> data;

public:

    // Конструктор
    ArraySequence() : data(0) {}

    // Конструктор копирования
    ArraySequence(const ArraySequence<T>& other)
        : data(other.data) {}
    // Конструктор с размером
    ArraySequence(int size) : data(size) {}

    // Получение элемента
    T Get(int index) const override {
        return data.Get(index);
    }

    // Изменение элемента
    void Set(int index, T value) override {
        data.Set(index, value);
    }

    // Размер
    int GetSize() const override {
        return data.GetSize();
    }

    // Добавление в конец
    void Append(T item) override {
        data.Append(item);
    }

    // Добавление в начало
    void Prepend(T item) override {

        int oldSize = data.GetSize();

        data.Resize(oldSize + 1);

        for (int i = oldSize; i > 0; i--) {
            data.Set(i, data.Get(i - 1));
        }

        data.Set(0, item);
    }

    // Вставка по индексу
    void InsertAt(int index, T item) override {

        if (index < 0 || index > data.GetSize()) {
            throw std::out_of_range("Index out of range");
        }

        int oldSize = data.GetSize();

        data.Resize(oldSize + 1);

        for (int i = oldSize; i > index; i--) {
            data.Set(i, data.Get(i - 1));
        }

        data.Set(index, item);
    }

    void RemoveAt(int index) override {
        data.RemoveAt(index);
    }
};