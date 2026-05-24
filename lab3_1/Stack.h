#pragma once

#include "Sequence.h"
#include "ListSequence.h"

#include <stdexcept>

template <class T>
class Stack {
private:

    ListSequence<T>* data;

public:

    Stack() {
        data = new ListSequence<T>();
    }

    Stack(const Stack<T>& other) {

        data = new ListSequence<T>();

        for (auto it = other.data->Begin();
             it != other.data->End();
             ++it) {

            data->Append(*it);
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
        data->Append(item);
    }

    T Top() const {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Stack is empty"
            );
        }

        return data->Get(
            GetSize() - 1
        );
    }

    T Pop() {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Stack is empty"
            );
        }

        T value = Top();

        data->RemoveAt(
            GetSize() - 1
        );

        return value;
    }

    Stack<T> Concat(
        const Stack<T>& other
    ) const {

        Stack<T> result;

        for (auto it = data->Begin();
             it != data->End();
             ++it) {

            result.data->Append(*it);
        }

        for (auto it = other.data->Begin();
             it != other.data->End();
             ++it) {

            result.data->Append(*it);
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

        for (auto it = data->Begin();
             it != data->End();
             ++it) {

            result.data->Append(
                func(*it)
            );
        }

        return result;
    }

    Stack<T> Where(
        bool (*predicate)(const T&)
    ) const {

        Stack<T> result;

        for (auto it = data->Begin();
             it != data->End();
             ++it) {

            if (predicate(*it)) {

                result.data->Append(*it);
            }
        }

        return result;
    }

    T Reduce(
        T (*func)(const T&, const T&),
        const T& startValue
    ) const {

        T result = startValue;

        for (auto it = data->Begin();
             it != data->End();
             ++it) {

            result = func(
                result,
                *it
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

        int index = 0;

        for (auto it = data->Begin();
             it != data->End();
             ++it) {

            if (index >= startIndex &&
                index <= endIndex) {

                result.data->Append(*it);
            }

            index++;
        }

        return result;
    }

    bool FindSubsequence(
        const Stack<T>& subsequence
    ) const {

        for (auto it = data->Begin();
             it != data->End();
             ++it) {

            auto mainIt = it;

            auto subIt =
                subsequence.data->Begin();

            bool found = true;

            while (subIt !=
                   subsequence.data->End()) {

                if (mainIt ==
                    data->End()) {

                    found = false;
                    break;
                }

                if (*mainIt != *subIt) {

                    found = false;
                    break;
                }

                ++mainIt;
                ++subIt;
            }

            if (found) {
                return true;
            }
        }

        return false;
    }
};