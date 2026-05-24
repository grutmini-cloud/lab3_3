#pragma once

#include "Sequence.h"
#include "ListSequence.h"

#include <stdexcept>

template <class T>
class Stack {
private:

    Sequence<T>* data;

public:

    Stack() {
        data = new ListSequence<T>();
    }

    Stack(const Stack<T>& other) {

        data = new ListSequence<T>();

        for (int i = 0; i < other.GetSize(); i++) {
            data->Append(other.data->Get(i));
        }
    }

    ~Stack() {
        delete data;
    }

    int GetSize() const {
        return data->GetSize();
    }

    bool IsEmpty() const {
        return GetSize() == 0;
    }

    void Push(const T& item) {

        data->Prepend(item);
    }

    T Top() const {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Stack is empty"
            );
        }

        return data->Get(0);
    }

    T Pop() {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Stack is empty"
            );
        }

        T value = Top();

        data->RemoveAt(0);

        return value;
    }

    Stack<T> Concat(const Stack<T>& other) const {

        Stack<T> result;

        for (int i = GetSize() - 1; i >= 0; i--) {
            result.data->Prepend(
                data->Get(i)
            );
        }

        for (int i = other.GetSize() - 1;
             i >= 0;
             i--) {

            result.data->Prepend(
                other.data->Get(i)
            );
        }

        return result;
    }

    Stack<T> operator+(
        const Stack<T>& other
    ) const {

        return Concat(other);
    }

    Stack<T> Map(
        T (*func)(const T&)
    ) const {

        Stack<T> result;

        for (int i = GetSize() - 1;
             i >= 0;
             i--) {

            result.data->Prepend(
                func(data->Get(i))
            );
        }

        return result;
    }

    Stack<T> Where(
        bool (*predicate)(const T&)
    ) const {

        Stack<T> result;

        for (int i = GetSize() - 1;
             i >= 0;
             i--) {

            if (predicate(data->Get(i))) {

                result.data->Prepend(
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

    Stack<T> GetSubsequence(
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

        Stack<T> result;

        for (int i = endIndex;
             i >= startIndex;
             i--) {

            result.data->Prepend(
                data->Get(i)
            );
        }

        return result;
    }

    bool FindSubsequence(
        const Stack<T>& subsequence
    ) const {

        if (subsequence.GetSize() >
            GetSize()) {

            return false;
        }

        for (int i = 0;
             i <= GetSize() -
             subsequence.GetSize();
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
};