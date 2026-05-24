#pragma once

#include <stdexcept>

template <class T>
class LinkedList {
private:

    // Узел списка
    struct Node {
        T data;
        Node* next;

        Node(T value) {
            data = value;
            next = nullptr;
        }
    };

    Node* head;
    int size;

public:

    // Конструктор
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    // Конструктор копирования
    LinkedList(const LinkedList<T>& other) {
        head = nullptr;
        size = 0;

        Node* current = other.head;

        while (current != nullptr) {
            Append(current->data);
            current = current->next;
        }
    }

    // Деструктор
    ~LinkedList() {
        Clear();
    }

    // Очистка памяти
    void Clear() {
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;

            delete current;

            current = next;
        }

        head = nullptr;
        size = 0;
    }

    // Размер списка
    int GetSize() const {
        return size;
    }

    // Получение элемента
    T Get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    // Изменение элемента
    void Set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->data = value;
    }

    // Добавление в конец
    void Append(T item) {
        Node* newNode = new Node(item);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newNode;
        }

        size++;
    }

    // Добавление в начало
    void Prepend(T item) {
        Node* newNode = new Node(item);

        newNode->next = head;

        head = newNode;

        size++;
    }

    // Вставка по индексу
    void InsertAt(int index, T item) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0) {
            Prepend(item);
            return;
        }

        Node* newNode = new Node(item);

        Node* current = head;

        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;

        current->next = newNode;

        size++;
    }

    // Удаление элемента
void RemoveAt(int index) {

    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }

    Node* toDelete;

    // Удаление первого элемента
    if (index == 0) {
        toDelete = head;
        head = head->next;
        delete toDelete;
        size--;
        return;
    }

    Node* current = head;

    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    toDelete = current->next;

    current->next = toDelete->next;

    delete toDelete;

    size--;
}
};