#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>

class MinHeap
{
    public:
        MinHeap();
        std::vector<int> heap;
        void showHeap();
        void deleteElem(int);
        int findElementIndex(int);
        int insertToHeap(int);
        int getMin();
    private:
        int getParent(int);
        int getParentIndex(int);
        void heapifyUp(int, int);
        void heapifyDown(int, int);
};
#endif