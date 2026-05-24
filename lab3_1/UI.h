#include <iostream>

#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "SquareMatrix.h"
#include "Tests.h"

using namespace std;

void StackMenu() {

    Stack<int> stack;

    int choice;

    do {

        cout << endl;
        cout << "===== STACK MENU ====="
             << endl;

        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Size" << endl;
        cout << "5. IsEmpty" << endl;
        cout << "0. Back" << endl;

        cout << "Choose: ";
        cin >> choice;

        try {

            switch (choice) {

                case 1: {

                    int value;

                    cout << "Enter value: ";
                    cin >> value;

                    stack.Push(value);

                    cout << "Added" << endl;

                    break;
                }

                case 2: {

                    cout << "Removed: "
                         << stack.Pop()
                         << endl;

                    break;
                }

                case 3: {

                    cout << "Top: "
                         << stack.Top()
                         << endl;

                    break;
                }

                case 4: {

                    cout << "Size: "
                         << stack.GetSize()
                         << endl;

                    break;
                }

                case 5: {

                    if (stack.IsEmpty()) {
                        cout << "Stack is empty"
                             << endl;
                    }
                    else {
                        cout << "Stack is not empty"
                             << endl;
                    }

                    break;
                }
            }

        }
        catch (const exception& e) {

            cout << "Error: "
                 << e.what()
                 << endl;
        }

    } while (choice != 0);
}

void QueueMenu() {

    Queue<int> queue;

    int choice;

    do {

        cout << endl;
        cout << "===== QUEUE MENU ====="
             << endl;

        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Size" << endl;
        cout << "5. IsEmpty" << endl;
        cout << "0. Back" << endl;

        cout << "Choose: ";
        cin >> choice;

        try {

            switch (choice) {

                case 1: {

                    int value;

                    cout << "Enter value: ";
                    cin >> value;

                    queue.Enqueue(value);

                    cout << "Added" << endl;

                    break;
                }

                case 2: {

                    cout << "Removed: "
                         << queue.Dequeue()
                         << endl;

                    break;
                }

                case 3: {

                    cout << "Front: "
                         << queue.Front()
                         << endl;

                    break;
                }

                case 4: {

                    cout << "Size: "
                         << queue.GetSize()
                         << endl;

                    break;
                }

                case 5: {

                    if (queue.IsEmpty()) {
                        cout << "Queue is empty"
                             << endl;
                    }
                    else {
                        cout << "Queue is not empty"
                             << endl;
                    }

                    break;
                }
            }

        }
        catch (const exception& e) {

            cout << "Error: "
                 << e.what()
                 << endl;
        }

    } while (choice != 0);
}

void DequeMenu() {

    Deque<int> deque;

    int choice;

    do {

        cout << endl;
        cout << "===== DEQUE MENU ====="
             << endl;

        cout << "1. PushFront" << endl;
        cout << "2. PushBack" << endl;
        cout << "3. PopFront" << endl;
        cout << "4. PopBack" << endl;
        cout << "5. Front" << endl;
        cout << "6. Back" << endl;
        cout << "0. Back" << endl;

        cout << "Choose: ";
        cin >> choice;

        try {

            switch (choice) {

                case 1: {

                    int value;

                    cout << "Enter value: ";
                    cin >> value;

                    deque.PushFront(value);

                    cout << "Added" << endl;

                    break;
                }

                case 2: {

                    int value;

                    cout << "Enter value: ";
                    cin >> value;

                    deque.PushBack(value);

                    cout << "Added" << endl;

                    break;
                }

                case 3: {

                    cout << "Removed: "
                         << deque.PopFront()
                         << endl;

                    break;
                }

                case 4: {

                    cout << "Removed: "
                         << deque.PopBack()
                         << endl;

                    break;
                }

                case 5: {

                    cout << "Front: "
                         << deque.Front()
                         << endl;

                    break;
                }

                case 6: {

                    cout << "Back: "
                         << deque.Back()
                         << endl;

                    break;
                }
            }

        }
        catch (const exception& e) {

            cout << "Error: "
                 << e.what()
                 << endl;
        }

    } while (choice != 0);
}

void MatrixMenu() {

    int size;

    cout << "Matrix size: ";
    cin >> size;

    SquareMatrix<int> matrix(size);

    int choice;

    do {

        cout << endl;
        cout << "===== MATRIX MENU ====="
             << endl;

        cout << "1. Set element" << endl;
        cout << "2. Get element" << endl;
        cout << "3. Norm" << endl;
        cout << "4. Swap rows" << endl;
        cout << "5. Swap columns" << endl;
        cout << "0. Back" << endl;

        cout << "Choose: ";
        cin >> choice;

        try {

            switch (choice) {

                case 1: {

                    int row;
                    int col;
                    int value;

                    cout << "Row: ";
                    cin >> row;

                    cout << "Column: ";
                    cin >> col;

                    cout << "Value: ";
                    cin >> value;

                    matrix.Set(row, col, value);

                    cout << "Updated" << endl;

                    break;
                }

                case 2: {

                    int row;
                    int col;

                    cout << "Row: ";
                    cin >> row;

                    cout << "Column: ";
                    cin >> col;

                    cout << "Value: "
                         << matrix.Get(row, col)
                         << endl;

                    break;
                }

                case 3: {

                    cout << "Norm: "
                         << matrix.Norm()
                         << endl;

                    break;
                }

                case 4: {

                    int a;
                    int b;

                    cout << "First row: ";
                    cin >> a;

                    cout << "Second row: ";
                    cin >> b;

                    matrix.SwapRows(a, b);

                    cout << "Rows swapped"
                         << endl;

                    break;
                }

                case 5: {

                    int a;
                    int b;

                    cout << "First column: ";
                    cin >> a;

                    cout << "Second column: ";
                    cin >> b;

                    matrix.SwapColumns(a, b);

                    cout << "Columns swapped"
                         << endl;

                    break;
                }
            }

        }
        catch (const exception& e) {

            cout << "Error: "
                 << e.what()
                 << endl;
        }

    } while (choice != 0);
}

