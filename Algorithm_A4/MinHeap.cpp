#include "MinHeap.h"

MinHeap::MinHeap(int max_size) : max_size(max_size), FRONT(1) 
{
    this->size = 0;
    this->internalTime = 0l;
}

int MinHeap::parent(int index) 
{
    return index / 2;
}

int MinHeap::leftChild(int index) 
{
    return (2 * index);
}

int MinHeap::rightChild(int index)
{
    return (2 * index) + 1;
}

bool MinHeap::isLeaf(int index) const 
{
    return index >= (size / 2) && index <= size;
}

void MinHeap::swap(int findex, int sindex) 
{
    Process tmp;
    tmp = heap[findex];
    heap[findex] = heap[sindex];
    heap[sindex] = tmp;
}

void MinHeap::minHeapify(int index) 
{
    if (!isLeaf(index)) {
        if (heap[index] > heap[leftChild(index)] || heap[index] > heap[rightChild(index)]) 
        {

            if (heap[leftChild(index)] < heap[rightChild(index)]) 
            {
                swap(index, leftChild(index));
                minHeapify(leftChild(index));
            } else {
                swap(index, rightChild(index));
                minHeapify(rightChild(index));
            }
        }
    }
}

void MinHeap::insert(Process element) 
{
    if (size >= this->max_size) 
    {
        return;
    }

    heap[++size] = element;
    int current = size;

    while (heap[current] < heap[parent(current)]) 
    {
        swap(current, parent(current));
        current = parent(current);
    }
}

void MinHeap::print() 
{
    std::cout << endl;
    for (int i = 1; i <= size / 2; i++) 
    {
        std::cout << " PARENT:" << heap[i] << " LEFT CHILD:" << heap[2 * i] << " RIGHT CHILD:" << heap[2 * i + 1]
                  << endl;
    }
}

void MinHeap::minHeapify() 
{
    for (int index = (size / 2); index >= 1; index--) 
    {
        minHeapify(index);
    }
}

Process MinHeap::remove() 
{
    if (size > 0) 
    {
        Process popped = heap[FRONT];
        heap[FRONT] = heap[size--];
        if (size != 0)
            minHeapify(FRONT);
        return popped;
    }
    Process p("\0", INT_MIN, INT_MIN);
    return p;
}

MinHeap::~MinHeap()
{

}