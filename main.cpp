#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <map>
#include "graph.h"
using namespace std;


class city{
    private:
    int ID;
    string Code;
    string Name;
    int population;
    int elevation;
    public:
    city(int id, string c, string n, int pop, int elev){ID = id; Code = c; Name = n; population = pop; elevation = elev;};
    int getID() const {return ID;}
    string code() const {return Code;}
    string name() const {return Name;}
    int pop() const {return population;}
    int elev() const {return elevation;}
};

void format();
void collectCities();
void collectRoads(graph& g);
int getID(string name);
void convert(string& name);
int checkID();
char checkC();
void printCity(int id);
void printRoute(int* predecessor, int start, int dest);


map<string, city> cityMap;
vector<string> getNameVec;

int main(){
    collectCities();

    int size = cityMap.size();

    graph roads(size);
    collectRoads(roads);

    int* curDist = new int[size];
    int* predecessor = new int[size];

    int startID, destID;
    char choice;

    format();
    cout << "******Welcome to the GPS Program******" << endl;
    format();

    do{
    
        cout << "Enter your starting point: ";
        startID = checkID();
        
        cout << "Enter your destination: ";
        destID = checkID();
    
        format();
        printCity(startID);
        printCity(destID);

        roads.DijkstraShortestPath(curDist,predecessor,startID);

    if(curDist[destID] == 999){
        cout << "No valid route from " << getNameVec[startID] << " to " << getNameVec[destID] << "." << endl;
    }
    else{
        cout << "The shortest trip from " << getNameVec[startID] << " to " << getNameVec[destID] << " is " << curDist[destID] << " miles." << endl;
        cout << "Through the route: ";
        printRoute(predecessor,startID,destID);
    }

    format();
    cout << "Enter (Y/y) for a new trip or (N/n) to quit: ";
    choice = checkC();
    format();

    }while(choice == 'Y' || choice == 'y');

    cout << "Thank you for using the GPS Program" << endl;
    format();

 
    delete[] curDist;
    delete[] predecessor;

    return 0;
}

void format(){
    cout << setfill('=') << setw(96) << " " << endl;
    cout << setfill(' ');
}



void collectCities(){
    ifstream fin;
    fin.open("city.txt");
    if(!fin.is_open()){cout << "City file did not open properly." << endl; exit(1);}

    int id, pop, elev;
    string c, n;

    while(fin >> id){
        fin >> c >> n >> pop >> elev;
        cityMap.emplace(n, city(id,c,n,pop,elev));
        getNameVec.push_back(n);
    }
    fin.close();
}

void collectRoads(graph& g){
    ifstream fin;
    fin.open("road.txt");
    if(!fin.is_open()){cout << "Road file did not open properly." << endl; exit(1);}

    int v, u, w;
    while(fin >> v){
        fin >> u; 
        fin >> w;
        g.addEdge(v,u,w);
    }
    fin.close();
}

int getID(string name){
   int id;
   auto i = cityMap.find(name);
   if(i != cityMap.end()){
    city c = i->second;
    id = c.getID();
   }
   else{id = -1;}
   return id;
}

void convert(string& name){
    for(int i = 0; i < name.length(); i++){
        if(name[i] > 96 && name[i] < 123){name[i] -= 32;}
    }
}

int checkID(){
    string name;
    int id;
    cin >> name;
    convert(name);
    id = getID(name);
    while(id == -1){
        cout << "Error: City not found, please enter an existing city: ";
        cin >> name;
        convert(name);
        id = getID(name);
    }
    return id;
}
 

char checkC(){
    char c;
    cin >> c;
    while(c != 'Y' && c != 'y' && c != 'n' && c != 'N'){
        cout << "Error: Invalid choice, please enter (Y/y) to find a new destination or (N/n) to quit: ";
        cin >> c;
    }
    return c;
}

void printCity(int id){
    string name = getNameVec[id];
    city c = cityMap.at(name);
    
    cout << c.name() << ", population: " << c.pop() << " people, elevation: " << c.elev() << " ft." << endl;
}

void printRoute(int* predecessor, int start, int dest){
    stack<string> s;
    int i = dest;

    while(i != start){
        s.push(getNameVec[i]);
        i = predecessor[i];
    }
    s.push(getNameVec[start]);

    while(!s.empty()){
        cout << s.top();
        s.pop();
        if(!s.empty()){cout << "-->";}
    }
    cout << endl;
}
