#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
using namespace std;

class minHeap{
    private:
    int* ar;
    int cap;
    int num;
    public:
    minHeap(int c);
    ~minHeap() {if(ar)delete[] ar;};
    int size() const {return num;}
    bool empty() const {return num == 0 ? true : false;}
    void insert(int e);
    void minHeapify(int* curDist, int* locator, int i);
    void bubbleUp(int* curDist, int* locator, int i);
    void remove(int* curDist, int* locator, int i);
    int getMin(int* curDist, int* locator);
    void fixHeap(int* curDist, int* locator, int i);
    class Overflow{};
    class BadIndex{};
};

minHeap:: minHeap(int c){
    cap = c;
    ar = new int[cap];
    num = 0;
}

void minHeap:: insert(int e){
    if(num >= cap){throw Overflow();}
    ar[num++] = e;
}

void minHeap:: minHeapify(int* curDist, int* locator, int i){
    int l = (i * 2) + 1;
    int r = (i * 2 ) + 2;
    int smallest = i;

    if(l < num && curDist[ar[l]] < curDist[ar[smallest]]){
        smallest = l;
    }
    if(r < num && curDist[ar[r]] < curDist[ar[smallest]]){
        smallest = r;
    }
    if(smallest != i){
        swap(ar[i],ar[smallest]);
        swap(locator[ar[i]],locator[ar[smallest]]);
        minHeapify(curDist,locator,smallest);
    }
}

void minHeap:: bubbleUp(int* curDist, int* locator, int i){
    int cur = i;
    int parent = (cur - 1)/2;

    while(cur > 0 && curDist[ar[cur]] < curDist[ar[parent]]){
        swap(ar[cur],ar[parent]);
        swap(locator[ar[cur]],locator[ar[parent]]);
        cur = parent;
        parent = (cur - 1)/2;
    }
}

void minHeap:: remove(int* curDist, int* locator, int i){
    if(i < 0 || i >= num){throw BadIndex();}
    swap(ar[i],ar[num-1]);
    swap(locator[ar[i]],locator[ar[num-1]]);
    num--;
    fixHeap(curDist,locator,i);
}

int minHeap:: getMin(int* curDist, int* locator){
    int min = ar[0];
    remove(curDist,locator,0);
    return min;
}

void minHeap:: fixHeap(int* curDist, int* locator, int i){
    if(curDist[ar[i]] < curDist[ar[(i-1)/2]]){bubbleUp(curDist,locator,i);}
    else{minHeapify(curDist,locator,i);}
}

#endif
