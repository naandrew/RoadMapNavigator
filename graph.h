#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <list>
#include <queue>
#include "minHeap.h"
using namespace std;

class edge{
    friend class graph;
    private:
    int neighbor;
    int wt;
    public:
    edge(int u, int w) {neighbor = u; wt = w;};
};

class graph{
    private:
    list<edge*>* ver_ar;
    int num_ver;
    int nextUnvisitedNode(int* num, int start, int s);
    void DFT_Helper(int v, int& i, int* num, queue<string>& edges);
    public:
    graph(int v);
    ~graph();
    void addEdge(int v, int u, int w = 1);
    void DFT(int start);
    void BFT(int start);
    void DijkstraShortestPath(int* curDist, int* predecessor, int start);
};

graph:: graph(int v){
    num_ver = v;
    ver_ar = new list<edge*>[num_ver];
}

graph:: ~graph(){
    for(int i = 0; i < num_ver; i++){
        for(list<edge*>:: iterator u = ver_ar[i].begin(); u != ver_ar[i].end(); u++){
            delete (*u);
        }
    }
    delete[] ver_ar;
}

void graph:: addEdge(int v, int u, int w){
    ver_ar[v].push_back(new edge(u,w));
}

int graph:: nextUnvisitedNode(int* num, int start, int s){
    for(int i = s; i < num_ver; i++){
        if(num[i] == 0){return i;}
    }
    for(int i = start; i < s - 1; i++){
        if(num[i] == 0){return i;}
    }
    return -1;
}

template <class T>
void displayQueue(queue<T>& q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void graph:: DFT(int start){
    int* num = new int[num_ver];
    for(int i = 0; i < num_ver; i++){num[i] = 0;}

    queue<string> edges;
    int v = start;
    int i = 1;

    do{
        DFT_Helper(v,i,num,edges);
        v = nextUnvisitedNode(num,start,v+1);
    }while(v != -1);
    displayQueue(edges);
    delete[] num;
}

void graph:: DFT_Helper(int v, int& i, int* num, queue<string>& edges){
    num[v] = i++;
    cout << v << " ";
    for(list<edge*>:: iterator u = ver_ar[v].begin(); u != ver_ar[v].end(); u++){
        if(num[(*u)->neighbor] == 0){
            edges.push(to_string(v) + "-->" + to_string((*u)->neighbor));
            DFT_Helper((*u)->neighbor,i,num,edges);
        }
    }
}

void graph:: BFT(int start){
    int* num = new int[num_ver];
    for(int i = 0; i < num_ver; i++){num[i] = 0;}

    queue<string> edges;
    queue<int> q;
    int v = start;
    int i = 1;

    do{
        q.push(v);
        num[v] = i++;
        while(!q.empty()){
            v = q.front();
            q.pop();
            cout << v << " ";
            for(list<edge*>:: iterator u = ver_ar[v].begin(); u != ver_ar[v].end(); u++){
                if(num[(*u)->neighbor] == 0){
                    edges.push(to_string(v) + "-->" + to_string((*u)->neighbor));
                    q.push((*u)->neighbor);
                    num[v] = i++;
                }
            }
        }
        v = nextUnvisitedNode(num,start,v+1);
    }while(v != -1);
    displayQueue(edges);
    delete[] num;
}

void graph:: DijkstraShortestPath(int* curDist, int* predecessor, int start){
    int* locator = new int[num_ver];
    minHeap check(num_ver);

    for(int i = 0; i < num_ver; i++){
        curDist[i] = 999;
        predecessor[i] = -1;
        locator[i] = i;
        check.insert(i);
    }

    int v;
    curDist[start] = 0;
    check.fixHeap(curDist,locator,start);

    while(!check.empty()){
        v = check.getMin(curDist,locator);
        for(list<edge*>:: iterator u = ver_ar[v].begin(); u != ver_ar[v].end(); u++){
            if(locator[(*u)->neighbor] < check.size() && curDist[(*u)->neighbor] > curDist[v] + (*u)->wt){
                curDist[(*u)->neighbor] = curDist[v] + (*u)->wt;
                check.fixHeap(curDist,locator,locator[(*u)->neighbor]);
                predecessor[(*u)->neighbor] = v;
            }
        }
    }
    delete[] locator;
}

#endif
