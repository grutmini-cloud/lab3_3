#pragma once

template <class T>
class Sequence {
public:

    // Деструктор
    virtual ~Sequence() {}

    // Получение элемента
    virtual T Get(int index) const = 0;

    // Изменение элемента
    virtual void Set(int index, T value) = 0;

    // Размер последовательности
    virtual int GetSize() const = 0;

    // Добавление в конец
    virtual void Append(T item) = 0;

    // Добавление в начало
    virtual void Prepend(T item) = 0;

    // Вставка по индексу
    virtual void InsertAt(int index, T item) = 0;

    virtual void RemoveAt(int index) = 0;
};