#pragma once

#include <stdexcept>

template <class T>
class LinkedList {
private:

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

    class Iterator {
    private:

        Node* current;

    public:

        Iterator(Node* node) {
            current = node;
        }

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {

            current = current->next;

            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
    };

    LinkedList() {

        head = nullptr;

        size = 0;
    }

    LinkedList(const LinkedList<T>& other) {

        head = nullptr;

        size = 0;

        Node* current = other.head;

        while (current != nullptr) {

            Append(current->data);

            current = current->next;
        }
    }

    ~LinkedList() {
        Clear();
    }

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

    int GetSize() const {
        return size;
    }

    T Get(int index) const {

        if (index < 0 || index >= size) {
            throw std::out_of_range(
                "Index out of range"
            );
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    void Set(int index, T value) {

        if (index < 0 || index >= size) {
            throw std::out_of_range(
                "Index out of range"
            );
        }

        Node* current = head;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->data = value;
    }

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

    void Prepend(T item) {

        Node* newNode = new Node(item);

        newNode->next = head;

        head = newNode;

        size++;
    }

    void InsertAt(int index, T item) {

        if (index < 0 || index > size) {
            throw std::out_of_range(
                "Index out of range"
            );
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

    void RemoveAt(int index) {

        if (index < 0 || index >= size) {
            throw std::out_of_range(
                "Index out of range"
            );
        }

        Node* toDelete;

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

    Iterator Begin() {
        return Iterator(head);
    }

    Iterator End() {
        return Iterator(nullptr);
    }
};