#include <iostream>
#include <vector>
#include "PriorityQueue.h"
using namespace std;

template <typename T>
PriorityQueue<T>::PriorityQueue() {
    backingArray = new T[capacity];
    size = 0;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(vector<int> data) {
    if(data.empty()) {
        throw "Vector null condition";
    }
    backingArray = new T[2 * data.size() * + 1];
    size = 0;
    for(int i = 0; i < data.size(); i++) {
        backingArray[i + 1] = data.at(i);
        size++;
    }
    for(int i = size/2; i > 0; i--) {
        downHeap(i);
    }
}

template <typename T>
void PriorityQueue<T>::add(T data) {
    if (size + 1 == capacity) {
        T temp[capacity * 2];
        // copy data over to the new 4size
        for (int i = 1; i < capacity; i++) {
            temp[i] = backingArray[i];
        }
        backingArray = temp;
        capacity *= 2;
    }
    size++;
    backingArray[size] = data;
    upHeap();
}

template <typename T>
T PriorityQueue<T>::remove() {
    if (size == 0) {
        throw "Zero size condition.";
    } else {
        T temp = backingArray[1];
        backingArray[1] = backingArray[size];
        size--; // right after final child removed, decrement the size
        // downHeap from the root (!)
        downHeap(1);
        return temp;
    }
}

template <typename T>
void PriorityQueue<T>::upHeap() {
    int index = size;
    while (index > 1 && backingArray[index] > backingArray[index / 2]) {
        swap(&backingArray[index], &backingArray[index/2]);
        index = index / 2;
    }
}

template <typename T>
void PriorityQueue<T>::downHeap(int index) {
    int lchild = index*2;
    int rchild = index*2 + 1;
    int largest = index;
    if(lchild <= size && backingArray[index] < backingArray[lchild]) {
        largest = lchild;
    }
    if(rchild <= size && backingArray[largest] < backingArray[rchild]) {
        largest = rchild;
    }
    if(largest != index) {
        swap(&backingArray[index], &backingArray[largest]);
        downHeap(largest);
    }
}

template <typename T>
T PriorityQueue<T>::getMax() {
    if (size == 0) {
        throw "Zero size condition.";
    }
    return backingArray[1];
}

template <typename T>
bool PriorityQueue<T>::isEmpty() {
    return (size == 0);
}

template <typename T>
int PriorityQueue<T>::getSize() {
    return size;
}

template <typename T>
void PriorityQueue<T>::clear() {
    backingArray = new T[capacity];
    size = 0;
}

template <typename T>
void PriorityQueue<T>::swap(T *a, T *b) {
    T temp = *b;
    *b = *a;
    *a = temp;
}
/*
// Method for testing purposes
template <typename T>
T* PriorityQueue<T>::getArray() {
    return backingArray;
}
*/