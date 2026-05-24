#pragma once

#include "Sequence.h"
#include "ListSequence.h"

#include <stdexcept>

template <class T>
class Queue {
private:

    ListSequence<T>* data;

public:

    Queue() {
        data = new ListSequence<T>();
    }

    Queue(const Queue<T>& other) {

        data = new ListSequence<T>();

        for (auto it = other.data->Begin();
             it != other.data->End();
             ++it) {

            data->Append(*it);
        }
    }

    ~Queue() {
        delete data;
    }

    int GetSize() const {
        return data->GetSize();
    }

    bool IsEmpty() const {
        return GetSize() == 0;
    }

    void Enqueue(const T& item) {
        data->Append(item);
    }

    T Front() const {

        if (IsEmpty()) {
            throw std::out_of_range(
                "Queue is empty"
            );
        }

        return data->Get(0);
    }

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

    Queue<T> Concat(
        const Queue<T>& other
    ) const {

        Queue<T> result;

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

    Queue<T> operator+(
        const Queue<T>& other
    ) const {

        return Concat(other);
    }

    Queue<T> Map(
        T (*func)(const T&)
    ) const {

        Queue<T> result;

        for (auto it = data->Begin();
             it != data->End();
             ++it) {

            result.data->Append(
                func(*it)
            );
        }

        return result;
    }

    Queue<T> Where(
        bool (*predicate)(const T&)
    ) const {

        Queue<T> result;

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

    Queue<T> GetSubsequence(
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

        Queue<T> result;

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
        const Queue<T>& subsequence
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