#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct node {
    T data;
    node<T> *next;
    node<T> *prev;
};

template <typename T>
class queue {
    public:
        void display() {
            node<T>* current = queueStart;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->prev;
            } cout << endl;
        }

        void push(T val) {
            node<T> *temp = new node<T>;
            temp->data = val;
            temp->prev = nullptr;
            if (queueStart == nullptr) {
                temp->next = nullptr;
                queueStart = temp;
                queueTop = temp;
            } else {
                temp->next = queueTop;
                queueTop->prev = temp;
                queueTop = temp;
            }
            size++;
        }

        void pop() {
            if (queueStart == nullptr) {
                cout << "Queue is empty!" << endl;
                return;
            }
            node<T> *temp = queueStart;
            queueStart = queueStart->prev;
            if (queueStart != nullptr) {
                queueStart->next = nullptr;
            }
            size--;
            delete temp;
        }
        
        T front() {
            assert(queueStart != nullptr);
            return queueStart->data;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0 ? true : false;
        }

        queue<T> &operator= (queue<T> otherQueue) {
            node<T> *current, *last;
            if (queueStart != nullptr) {
                queueStart = nullptr;
                queueTop = nullptr;
            }
            if (otherQueue == nullptr) {
                queueStart = nullptr;
                queueTop = nullptr;
            } else {
                node<T> *current = otherQueue.queueStart;
                queueStart = new node<T>;
                queueStart->data = current->data;
                queueStart->next = nullptr;
                last = queueStart;
                current = current->next;
                while (current != nullptr) {
                    node<T> *newNode = new node<T>;
                    newNode->data = current->data;
                    newNode->next = last;
                    newNode->prev = nullptr;
                    last->prev = newNode;
                    last = newNode;
                }
                queueTop = new node<T>;
                queueTop->data = last->data;
                queueTop->next = last->next;
                queueTop->prev = last->prev;
            }
            return *this;
        }

        queue() {
            queueStart = nullptr;
            queueTop = nullptr;
            size = 0;
        }
        

    private:
        node<T> *queueStart;
        node<T> *queueTop;
        int size;
};

#endif