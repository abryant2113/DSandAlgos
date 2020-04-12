#include <iostream>
#include <MinHeap.h>

int main() {
    MinHeap myHeap;

    myHeap.insertToHeap(4);
    myHeap.insertToHeap(2);
    myHeap.insertToHeap(3);
    myHeap.insertToHeap(5);
    myHeap.insertToHeap(1);
    myHeap.insertToHeap(0);

    myHeap.deleteElem(0);
    myHeap.showHeap();

    return 0;
}