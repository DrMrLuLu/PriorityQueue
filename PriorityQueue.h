#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityQueue {
    private:
        int capacity = 13;
        T *backingArray;
        int size;
        void upHeap();
        void downHeap(int);
        void swap(T*, T*);

    public:
        PriorityQueue();
        PriorityQueue(std::vector<int>);
        void add(T);
        T remove();
        T getMax();
        void clear();
        bool isEmpty();
        int getSize();
        T* getArray();

};

#endif