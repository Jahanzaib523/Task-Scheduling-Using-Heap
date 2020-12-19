#ifndef HEAPPROCESS_MINHEAP_H
#define HEAPPROCESS_MINHEAP_H

#include "Process.h"
#include <limits> //Gives limit of whole data type.

class MinHeap 
{
private:
    Process heap[1000];
    int size;
    int max_size;
    int FRONT;

    int parent(int);

    int leftChild(int);

    int rightChild(int);

    bool isLeaf(int) const;

    void swap(int, int);

    void minHeapify(int);

    ~MinHeap();

public:
    long internalTime;

    MinHeap(int);

    void insert(Process);

    void print();

    void minHeapify();

    Process remove();
};

#endif