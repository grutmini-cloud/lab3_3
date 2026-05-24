#pragma once

#include <iostream>
#include <cassert>

#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "SquareMatrix.h"

using namespace std;

int DoubleValue(const int& x) {
    return x * 2;
}

bool IsEven(const int& x) {
    return x % 2 == 0;
}

int Sum(const int& a, const int& b) {
    return a + b;
}

//
// STACK
//

void TestStackPush() {

    Stack<int> stack;

    stack.Push(10);
    stack.Push(20);

    assert(stack.GetSize() == 2);
    assert(stack.Top() == 20);

    cout << "TestStackPush passed" << endl;
}

void TestStackPop() {

    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    int value = stack.Pop();

    assert(value == 3);
    assert(stack.Top() == 2);

    cout << "TestStackPop passed" << endl;
}

void TestStackConcat() {

    Stack<int> a;
    Stack<int> b;

    a.Push(1);
    a.Push(2);

    b.Push(3);
    b.Push(4);

    Stack<int> result = a + b;

    assert(result.Pop() == 4);
    assert(result.Pop() == 3);
    assert(result.Pop() == 2);
    assert(result.Pop() == 1);

    cout << "TestStackConcat passed" << endl;
}

void TestStackMap() {

    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    Stack<int> result =
        stack.Map(DoubleValue);

    assert(result.Pop() == 6);
    assert(result.Pop() == 4);
    assert(result.Pop() == 2);

    cout << "TestStackMap passed" << endl;
}

void TestStackWhere() {

    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    Stack<int> result =
        stack.Where(IsEven);

    assert(result.Pop() == 4);
    assert(result.Pop() == 2);

    cout << "TestStackWhere passed" << endl;
}

void TestStackReduce() {

    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    int result =
        stack.Reduce(Sum, 0);

    assert(result == 6);

    cout << "TestStackReduce passed" << endl;
}

void TestStackGetSubsequence() {

    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    Stack<int> result =
        stack.GetSubsequence(1, 2);

    assert(result.Pop() == 3);
    assert(result.Pop() == 2);

    cout << "TestStackGetSubsequence passed"
         << endl;
}

void TestStackFindSubsequence() {

    Stack<int> stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);

    Stack<int> sub;

    sub.Push(2);
    sub.Push(3);

    assert(
        stack.FindSubsequence(sub)
    );

    cout << "TestStackFindSubsequence passed"
         << endl;
}

//
// QUEUE
//

void TestQueueEnqueue() {

    Queue<int> queue;

    queue.Enqueue(10);
    queue.Enqueue(20);

    assert(queue.GetSize() == 2);
    assert(queue.Front() == 10);

    cout << "TestQueueEnqueue passed"
         << endl;
}

void TestQueueDequeue() {

    Queue<int> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    int value = queue.Dequeue();

    assert(value == 1);
    assert(queue.Front() == 2);

    cout << "TestQueueDequeue passed"
         << endl;
}

void TestQueueConcat() {

    Queue<int> a;
    Queue<int> b;

    a.Enqueue(1);
    a.Enqueue(2);

    b.Enqueue(3);
    b.Enqueue(4);

    Queue<int> result = a + b;

    assert(result.Dequeue() == 1);
    assert(result.Dequeue() == 2);
    assert(result.Dequeue() == 3);
    assert(result.Dequeue() == 4);

    cout << "TestQueueConcat passed"
         << endl;
}

void TestQueueMap() {

    Queue<int> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    Queue<int> result =
        queue.Map(DoubleValue);

    assert(result.Dequeue() == 2);
    assert(result.Dequeue() == 4);
    assert(result.Dequeue() == 6);

    cout << "TestQueueMap passed"
         << endl;
}

void TestQueueWhere() {

    Queue<int> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);

    Queue<int> result =
        queue.Where(IsEven);

    assert(result.Dequeue() == 2);
    assert(result.Dequeue() == 4);

    cout << "TestQueueWhere passed"
         << endl;
}

void TestQueueReduce() {

    Queue<int> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    int result =
        queue.Reduce(Sum, 0);

    assert(result == 6);

    cout << "TestQueueReduce passed"
         << endl;
}

void TestQueueGetSubsequence() {

    Queue<int> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);

    Queue<int> result =
        queue.GetSubsequence(1, 2);

    assert(result.Dequeue() == 2);
    assert(result.Dequeue() == 3);

    cout << "TestQueueGetSubsequence passed"
         << endl;
}

void TestQueueFindSubsequence() {

    Queue<int> queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);

    Queue<int> sub;

    sub.Enqueue(2);
    sub.Enqueue(3);

    assert(
        queue.FindSubsequence(sub)
    );

    cout << "TestQueueFindSubsequence passed"
         << endl;
}

//
// DEQUE
//

void TestDequePushFront() {

    Deque<int> deque;

    deque.PushFront(10);
    deque.PushFront(20);

    assert(deque.Front() == 20);
    assert(deque.Back() == 10);

    cout << "TestDequePushFront passed"
         << endl;
}

void TestDequePushBack() {

    Deque<int> deque;

    deque.PushBack(10);
    deque.PushBack(20);

    assert(deque.Front() == 10);
    assert(deque.Back() == 20);

    cout << "TestDequePushBack passed"
         << endl;
}

void TestDequePopFront() {

    Deque<int> deque;

    deque.PushBack(1);
    deque.PushBack(2);

    int value = deque.PopFront();

    assert(value == 1);
    assert(deque.Front() == 2);

    cout << "TestDequePopFront passed"
         << endl;
}

void TestDequePopBack() {

    Deque<int> deque;

    deque.PushBack(1);
    deque.PushBack(2);

    int value = deque.PopBack();

    assert(value == 2);
    assert(deque.Back() == 1);

    cout << "TestDequePopBack passed"
         << endl;
}

void TestDequeSort() {

    Deque<int> deque;

    deque.PushBack(4);
    deque.PushBack(1);
    deque.PushBack(3);
    deque.PushBack(2);

    deque.Sort();

    assert(deque.PopFront() == 1);
    assert(deque.PopFront() == 2);
    assert(deque.PopFront() == 3);
    assert(deque.PopFront() == 4);

    cout << "TestDequeSort passed"
         << endl;
}

void TestDequeMerge() {

    Deque<int> a;
    Deque<int> b;

    a.PushBack(3);
    a.PushBack(1);

    b.PushBack(4);
    b.PushBack(2);

    Deque<int> result =
        a.Merge(b);

    assert(result.PopFront() == 1);
    assert(result.PopFront() == 2);
    assert(result.PopFront() == 3);
    assert(result.PopFront() == 4);

    cout << "TestDequeMerge passed"
         << endl;
}

//
// MATRIX
//

void TestMatrixSetGet() {

    SquareMatrix<int> matrix(2);

    matrix.Set(0, 0, 1);
    matrix.Set(0, 1, 2);

    matrix.Set(1, 0, 3);
    matrix.Set(1, 1, 4);

    assert(matrix.Get(0, 0) == 1);
    assert(matrix.Get(1, 1) == 4);

    cout << "TestMatrixSetGet passed"
         << endl;
}

void TestMatrixAddition() {

    SquareMatrix<int> a(2);
    SquareMatrix<int> b(2);

    a.Set(0,0,1);
    a.Set(0,1,2);
    a.Set(1,0,3);
    a.Set(1,1,4);

    b.Set(0,0,5);
    b.Set(0,1,6);
    b.Set(1,0,7);
    b.Set(1,1,8);

    SquareMatrix<int> result = a + b;

    assert(result.Get(0,0) == 6);
    assert(result.Get(1,1) == 12);

    cout << "TestMatrixAddition passed"
         << endl;
}

void TestMatrixScalar() {

    SquareMatrix<int> matrix(2);

    matrix.Set(0,0,1);
    matrix.Set(0,1,2);

    matrix.Set(1,0,3);
    matrix.Set(1,1,4);

    SquareMatrix<int> result =
        matrix.MultiplyByScalar(2);

    assert(result.Get(0,0) == 2);
    assert(result.Get(1,1) == 8);

    cout << "TestMatrixScalar passed"
         << endl;
}

void TestMatrixNorm() {

    SquareMatrix<int> matrix(2);

    matrix.Set(0,0,1);
    matrix.Set(0,1,-2);

    matrix.Set(1,0,3);
    matrix.Set(1,1,4);

    assert(matrix.Norm() == 10);

    cout << "TestMatrixNorm passed"
         << endl;
}

void TestMatrixSwapRows() {

    SquareMatrix<int> matrix(2);

    matrix.Set(0,0,1);
    matrix.Set(0,1,2);

    matrix.Set(1,0,3);
    matrix.Set(1,1,4);

    matrix.SwapRows(0,1);

    assert(matrix.Get(0,0) == 3);
    assert(matrix.Get(1,0) == 1);

    cout << "TestMatrixSwapRows passed"
         << endl;
}

void TestMatrixSwapColumns() {

    SquareMatrix<int> matrix(2);

    matrix.Set(0,0,1);
    matrix.Set(0,1,2);

    matrix.Set(1,0,3);
    matrix.Set(1,1,4);

    matrix.SwapColumns(0,1);

    assert(matrix.Get(0,0) == 2);
    assert(matrix.Get(0,1) == 1);

    cout << "TestMatrixSwapColumns passed"
         << endl;
}

void RunTests() {

    TestStackPush();
    TestStackPop();
    TestStackConcat();
    TestStackMap();
    TestStackWhere();
    TestStackReduce();
    TestStackGetSubsequence();
    TestStackFindSubsequence();

    TestQueueEnqueue();
    TestQueueDequeue();
    TestQueueConcat();
    TestQueueMap();
    TestQueueWhere();
    TestQueueReduce();
    TestQueueGetSubsequence();
    TestQueueFindSubsequence();

    TestDequePushFront();
    TestDequePushBack();
    TestDequePopFront();
    TestDequePopBack();
    TestDequeSort();
    TestDequeMerge();

    TestMatrixSetGet();
    TestMatrixAddition();
    TestMatrixScalar();
    TestMatrixNorm();
    TestMatrixSwapRows();
    TestMatrixSwapColumns();

    cout << endl;
    cout << "ALL TESTS PASSED!"
         << endl;
}