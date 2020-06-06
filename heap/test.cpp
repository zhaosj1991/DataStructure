#include <stdio.h>
#include "heap.h"

int main(int argc, char const *argv[])
{
    int data[] = {35, 65, 1, 35, 5, 468, 24, 898, 6, 45, 356, 1, 5};

    MinHeap<int> minHeap(2);
    for (int i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        minHeap.push(data[i]);
    }

    printf("MinHeap push over... size = %d, capacity = %d\n", minHeap.size(), minHeap.capacity());
    
    while (minHeap.size() > 0)
    {
        printf("%d ", minHeap.pop());
    }

    printf("\n\n");
    
    MaxHeap<int> maxHeap(2);
    for (int i = 0; i < sizeof(data)/sizeof(int); i++)
    {
        maxHeap.push(data[i]);
    }

    printf("MaxHeap push over... size = %d, capacity = %d\n", maxHeap.size(), maxHeap.capacity());
    
    while (maxHeap.size() > 0)
    {
        printf("%d ", maxHeap.pop());
    }
     
    return 0;
}
