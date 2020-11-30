// MinHeap.h
// Declarartion of Heap class

#ifndef MINHEAP_H
#define MINHEAP_H

#include <vector>
#include <string>

using namespace std;

struct record {
     int rank;
     char name[20];
     char nationality[20];
     int score;
     char opponent[15];
     int year;
};

class MinHeap{
    private:
        vector <record> elements;
                
    public:
        // Constructor
        MinHeap(){ elements.resize(1); }

        // Deconstructor
        ~MinHeap();

        void addMinHeap(int, string, string, int, string, int);
        void minHeapify(unsigned int);
        void deleteMinHeapVal(int);
        void removeMinRoot();
        string displayHeap();
        string sortMinHeap();                
};
#endif