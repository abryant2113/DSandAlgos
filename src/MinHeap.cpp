#include <iostream>
#include <MinHeap.h>

using namespace std;

MinHeap::MinHeap(){};

int MinHeap::getParent(int index) {
    return heap[(index - 1) / 2];
}

int MinHeap::getParentIndex(int index) {
    return  (index - 1) / 2;
}

int MinHeap::findElementIndex(int elem) {
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == elem)
            return i;
    }
    return -1;
}

void MinHeap::deleteElem(int elem) {
    int rightmostElem;
    int elemIndex = findElementIndex(elem);

    if (elemIndex == -1) {
        cout << "Element was not found in heap." << "\n";
        return;
    }

    rightmostElem = heap[heap.size() - 1];

    heap[elemIndex] = rightmostElem;
    
    // removes the last element of the heap
    heap.pop_back();

    heapifyUp(rightmostElem, elemIndex);

    heapifyDown(rightmostElem, elemIndex);
}

void MinHeap::heapifyDown(int elem, int index) {
    int leftChildIndex;
    int rightChildIndex;
    int lastIndex;

    leftChildIndex = (2 * index) + 1;
    rightChildIndex = (2 * index) + 2;
    lastIndex = heap.size() - 1;

    if (leftChildIndex > lastIndex || rightChildIndex > lastIndex) {
        return;
    }

    if (heap[leftChildIndex] <= heap[rightChildIndex] && elem > heap[leftChildIndex]) {
        heap[index] = heap[leftChildIndex];
        heap[leftChildIndex] = elem;
        heapifyDown(elem, leftChildIndex);
    } else if(heap[leftChildIndex] > heap[rightChildIndex] && elem > heap[rightChildIndex]) {
        heap[index] = heap[rightChildIndex];
        heap[rightChildIndex] = elem;
        heapifyDown(elem, rightChildIndex);
    }
}

void MinHeap::heapifyUp(int elem, int index) {
    int parentVal;
    int parentIndex;

    // First element in the heap -- no parent
    if (index == 0)
        return;
    
    parentVal = getParent(index);
    parentIndex = getParentIndex(index);

    if(elem > parentVal)
        return;

    heap[parentIndex] = elem;
    heap[index] = parentVal;

    heapifyUp(elem, parentIndex);
}

int MinHeap::insertToHeap(int elem) {
    heap.push_back(elem);
    heapifyUp(elem, heap.size()-1);
}

int MinHeap::getMin() {
    return heap[0];
}

void MinHeap::showHeap() {
    for(vector<int>::iterator it = heap.begin(); it != heap.end(); it++)
        cout << *it << "\n";
}