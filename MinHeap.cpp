// MinHeap.cpp
// Implementation of the Heap class

#include "MinHeap.h"
#include <stdio.h>
#include <cstring>

void MinHeap::addMaxHeap(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum){
    record addRec;
    addRec.rank = rnum;
    strcpy(addRec.name, nstr.c_str());
    strcpy(addRec.nationality, natstr.c_str());
    addRec.score = snum;
    strcpy(addRec.opponent, oppstr.c_str());
    addRec.year = yrnum;
    elements.push_back(addRec);
    // maxHeapify(elements.size() - 1);
}

void MinHeap::addMinHeap(int rnum, string nstr, string natstr, int snum, string oppstr, int yrnum){
    record addRec;
    addRec.rank = rnum;
    strcpy(addRec.name, nstr.c_str());
    strcpy(addRec.nationality, natstr.c_str());
    addRec.score = snum;
    strcpy(addRec.opponent, oppstr.c_str());
    addRec.year = yrnum;
    elements.push_back(addRec);
    // minHeapify(elements.size() - 1);
}

void MinHeap::maxHeapify(unsigned int index){
    unsigned int left, right, maxx;
    left = 2*index;
    right = 2*index + 1;

    // Base case
    if (index == 0)
        return;

    // Check the children, if they exist and pick the larger for swapping
    if (left < elements.size() && elements[left].rank > elements[index].rank)
        maxx = left;
    else
        maxx = index;

    if (right < elements.size() && elements[right].rank > elements[maxx].rank)
        maxx = right;

    if (maxx != index)
        {
            record temp = elements[maxx];
            elements[maxx] = elements[index];
            elements[index] = temp;
            maxHeapify(maxx);
        }

    // Now check the parent, if it exists
    maxHeapify(index/2);
}

void MinHeap::minHeapify(unsigned int index){
    unsigned int left, right, minn;
    left = 2*index;
    right = 2*index + 1;

    // Base case
    if (index == 0)
        return;

    // Check the children, if they exist and pick the larger for swapping
    if (left < elements.size() && elements[left].rank < elements[index].rank)
        minn = left;
    else
        minn = index;

    if (right < elements.size() && elements[right].rank < elements[minn].rank)
        minn = right;

    if (minn != index)
        {
            record temp = elements[minn];
            elements[minn] = elements[index];
            elements[index] = temp;
            minHeapify(minn);
        }

    // Now check the parent, if it exists
    minHeapify(index/2);
}

void MinHeap::deleteMinHeapVal(int value){
    int x = 0;
    while (x <= elements.size()){
        if (value == elements[x].rank){
            elements[x] = elements[ (elements.size() - 1) ];
            elements.pop_back();
            minHeapify(x);
            minHeapify((2 * x) +1);
            minHeapify((2 * x) +2 );
            break;
        }
        x++;
    }
}

void MinHeap::deleteMaxHeapVal(int value){
    
    int x = 0;
    while (x <= elements.size()){
        if (value == elements[x].rank){
            elements[x] = elements[ (elements.size() - 1) ];
            elements.pop_back();
            maxHeapify(x);
            maxHeapify((2 * x) +1);
            maxHeapify((2 * x) +2 );
            break;
        }
        x++;
    }
}

void MinHeap::removeMaxRoot(){
    if (elements.size() < 2)
        return;
    else {
        elements[1] = elements[elements.size() - 1];
        elements.resize(elements.size() - 1);
        maxHeapify(1);
    }
}

void MinHeap::removeMinRoot(){
    if (elements.size() < 2)
        return;
    else {
        elements[1] = elements[elements.size() - 1];
        elements.resize(elements.size() - 1);
        minHeapify(1);
    }
}

string MinHeap::displayHeap(){
    string str = "";
    for (int x = 1; x < elements.size(); x++){
        str = to_string(elements[x].rank);
        str.append("\t\t");
        str.append(elements[x].name);
        str.append("\t\t");
        str.append(elements[x].nationality);
        str.append("\t\t");
        str.append(to_string(elements[x].score));
        str.append("\t\t\t");
        str.append(elements[x].opponent);
        str.append("\t\t");
        str.append(to_string(elements[x].year));
        str.append("\n");
    }
    str.append("\n");
    return str;
}

string MinHeap::sortMaxHeap(){
    string str ="";
    while (elements.size() > 1){
        str = to_string(elements[1].rank);
        str.append("\t\t");
        str.append(elements[1].name);
        str.append("\t\t");
        str.append(elements[1].nationality);
        str.append("\t\t");
        str.append(to_string(elements[1].score));
        str.append("\t\t\t");
        str.append(elements[1].opponent);
        str.append("\t\t");
        str.append(to_string(elements[1].year));
        str.append("\n");
        removeMaxRoot();
    }
    str.append("\n");
    return str;
}

string MinHeap::sortMinHeap(){
    string str ="";
    while (elements.size() > 1){
        str = to_string(elements[1].rank);
        str.append("\t\t");
        str.append(elements[1].name);
        str.append("\t\t");
        str.append(elements[1].nationality);
        str.append("\t\t");
        str.append(to_string(elements[1].score));
        str.append("\t\t\t");
        str.append(elements[1].opponent);
        str.append("\t\t");
        str.append(to_string(elements[1].year));
        str.append("\n");
        removeMinRoot();
    }
    str.append("\n");
    return str;
}