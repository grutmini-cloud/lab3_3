#pragma once

#include "Sequence.h"
#include "LinkedList.h"

template <class T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> data;

public:

    // Конструктор
    ListSequence() {}

    // Конструктор копирования
    ListSequence(const ListSequence<T>& other) {
        data = other.data;
    }

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
        data.Prepend(item);
    }

    // Вставка по индексу
    void InsertAt(int index, T item) override {
        data.InsertAt(index, item);
    }

    void RemoveAt(int index) override {
        data.RemoveAt(index);
    }

    typename LinkedList<T>::Iterator Begin() {
        return data.Begin();
    }

    typename LinkedList<T>::Iterator End() {
        return data.End();
    }
};