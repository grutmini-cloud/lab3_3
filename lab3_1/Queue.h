#pragma once

#include "Sequence.h"
#include "ListSequence.h"

#include <stdexcept>

template <class T>
class Queue {
private:

    Sequence<T>* data;

public:

    // Конструктор
    Queue() {
        data = new ListSequence<T>();
    }

    // Деструктор
    ~Queue() {
        delete data;
    }

    // Размер
    int GetSize() const {
        return data->GetSize();
    }

    // Проверка пустоты
    bool IsEmpty() const {
        return GetSize() == 0;
    }

    // Добавление элемента
    void Enqueue(const T& item) {

        data->Append(item);
    }

    // Первый элемент
    T Front() const {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Queue is empty"
            );
        }
        return data->Get(0);
    }
    // Удаление первого элемента
    T Dequeue() {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Queue is empty"
            );
        }
        T value = Front();
        data->RemoveAt(0);
        return value;
    }
    // Конкатенация очередей
    Queue<T> Concat(const Queue<T>& other) const {
        Queue<T> result;
        for (int i = 0; i < GetSize(); i++) {
            result.Enqueue(
                data->Get(i));
        }
        for (int i = 0; i < other.GetSize(); i++) {

            result.Enqueue(
                other.data->Get(i));
        }
        return result;//коккатенацию без 2 переборов
    }

    // Перегрузка оператора +
    Queue<T> operator+(const Queue<T>& other) const {
        return Concat(other);
    }

    // Map
    Queue<T> Map(T (*func)(const T&)) const {

        Queue<T> result;

        for (int i = 0; i < GetSize(); i++) {

            result.Enqueue(func(data->Get(i)));
        }
        return result;
    }

    //Where
    Queue<T> Where(bool (*predicate)(const T&)) const {
        Queue<T> result;

        for (int i = 0; i < GetSize(); i++) {
            if (predicate(data->Get(i))) {
                result.Enqueue(data->Get(i));
            }
        }
        return result;
    }

    // Reduce
    T Reduce(T (*func)(const T&, const T&),const T& startValue) const {
        T result = startValue;
        for (int i = 0; i < GetSize();i++) {
            result = func(result,data->Get(i));
        }

        return result;
    }

    // Получение подпоследовательности
    Queue<T> GetSubsequence(int startIndex,int endIndex) const {

        if (startIndex < 0 ||endIndex >= GetSize() ||startIndex > endIndex) {
            throw std::out_of_range(
                "Wrong indexes"
            );
            }

        Queue<T> result;

        for (int i = startIndex;i <= endIndex;i++) {
            result.Enqueue(data->Get(i));
             }

        return result;//без квадратичных переборов
    }

    // Поиск подпоследовательности
    bool FindSubsequence(const Queue<T>& subsequence) const {
        if (subsequence.GetSize() > GetSize()) {
            return false;
            }

        for (int i = 0;i <= GetSize() - subsequence.GetSize();i++) {
            bool found = true;
            for (int j = 0; j < subsequence.GetSize(); j++) {

                if (data->Get(i + j) !=subsequence.data->Get(j)) {
                    found = false;
                    break;
                    }
                 }

            if (found) {
                return true;
            }
             }

        return false;
    }
};