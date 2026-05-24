#pragma once

#include "Sequence.h"
#include "ListSequence.h"

#include <stdexcept>

template <class T>
class Deque {
private:

    Sequence<T>* data;

public:

    Deque() {
        data = new ListSequence<T>();
    }

    Deque(const Deque<T>& other) {

        data = new ListSequence<T>();

        for (int i = 0; i < other.GetSize(); i++) {
            data->Append(other.data->Get(i));
        }
    }

    ~Deque() {
        delete data;
    }

    int GetSize() const {
        return data->GetSize();
    }

    bool IsEmpty() const {
        return GetSize() == 0;
    }

    void PushFront(const T& item) {
        data->Prepend(item);
    }

    void PushBack(const T& item) {
        data->Append(item);
    }

    T Front() const {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Deque is empty"
            );
        }

        return data->Get(0);
    }

    T Back() const {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Deque is empty"
            );
        }

        return data->Get(GetSize() - 1);
    }

    T PopFront() {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Deque is empty"
            );
        }

        T value = Front();

        data->RemoveAt(0);

        return value;
    }

    T PopBack() {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Deque is empty"
            );
        }

        T value = Back();

        data->RemoveAt(GetSize() - 1);

        return value;
    }

    Deque<T> Concat(const Deque<T>& other) const {

        Deque<T> result;

        for (int i = 0; i < GetSize(); i++) {
            result.PushBack(data->Get(i));
        }

        for (int i = 0; i < other.GetSize(); i++) {
            result.PushBack(other.data->Get(i));
        }

        return result;
    }

    Deque<T> operator+(const Deque<T>& other) const {
        return Concat(other);
    }

    Deque<T> Map(T (*func)(const T&)) const {

        Deque<T> result;

        for (int i = 0; i < GetSize(); i++) {
            result.PushBack(
                func(data->Get(i))
            );
        }

        return result;
    }

    Deque<T> Where(bool (*predicate)(const T&)) const {

        Deque<T> result;

        for (int i = 0; i < GetSize(); i++) {

            if (predicate(data->Get(i))) {
                result.PushBack(
                    data->Get(i)
                );
            }
        }

        return result;
    }

    T Reduce(
        T (*func)(const T&, const T&),
        const T& startValue
    ) const {

        T result = startValue;

        for (int i = 0; i < GetSize(); i++) {
            result = func(
                result,
                data->Get(i)
            );
        }

        return result;
    }

    Deque<T> GetSubsequence(
        int startIndex,
        int endIndex
    ) const {

        if (startIndex < 0 ||
            endIndex >= GetSize() ||
            startIndex > endIndex) {

            throw std::out_of_range(
                "Wrong indexes"
            );
        }

        Deque<T> result;

        for (int i = startIndex; i <= endIndex; i++) {
            result.PushBack(
                data->Get(i)
            );
        }

        return result;
    }

    bool FindSubsequence(
        const Deque<T>& subsequence
    ) const {

        if (subsequence.GetSize() > GetSize()) {
            return false;
        }

        for (int i = 0;
             i <= GetSize() - subsequence.GetSize();
             i++) {

            bool found = true;

            for (int j = 0;
                 j < subsequence.GetSize();
                 j++) {

                if (data->Get(i + j) !=
                    subsequence.data->Get(j)) {

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

    void Sort() {

        for (int i = 0; i < GetSize() - 1; i++) {

            for (int j = 0;
                 j < GetSize() - i - 1;
                 j++) {

                if (data->Get(j) >
                    data->Get(j + 1)) {

                    T temp = data->Get(j);

                    data->Set(
                        j,
                        data->Get(j + 1)
                    );

                    data->Set(
                        j + 1,
                        temp
                    );
                }
            }
        }
    }

    Deque<T> Merge(
        const Deque<T>& other
    ) const {

        Deque<T> result;

        for (int i = 0; i < GetSize(); i++) {
            result.PushBack(data->Get(i));
        }

        for (int i = 0; i < other.GetSize(); i++) {
            result.PushBack(
                other.data->Get(i)
            );
        }

        result.Sort();

        return result;
    }
};