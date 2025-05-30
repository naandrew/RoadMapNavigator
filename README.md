#CityRoutePlanner

A C++ console application that calculates the shortest route between cities using Dijkstra's algortithm 

#Features
-Calculates the shortest path between two cities using Dijkstra's algorithm
- Supports both Depth-First and Breadth-First traversals
- Reads city and road data from external files
- Displays route, distance, population, and elevation of selected cities
- Custom implementation of a min-heap priority queue for pathfinding

#File Structure
-main.cpp          # Main program logic and user interface
-graph.h           # Graph class with Dijkstra, DFS, and BFS
-minHeap.h         # Custom min-heap used for Dijkstra's algorithm
-city.txt          # Input file containing city data
-road.txt          # Input file containing road (edge) data
-README.md         # File that explains project

#Input File Format

-City.txt
   -Each line contains data for a city: <ID> <Code> <Name> <Population> <Elevation>
   -Example:
       0 LA LosAngeles 3970000 305
       1 SF SanFrancisco 884000 52
       2 LV LasVegas 641000 2001
-Road.txt
  -Each line contains an edge between two cities: <Start_City_ID> <End_City_ID> <Distance>
  -Example:
      0 1 381
      0 2 270
      1 2 570

  #How To Compile and Run

  -Requirements:
    -C++ Compiler
    -C++11 or higher

  -Compile:
    g++ main.cpp -o CityRoutePlanner

  -Run:
    ./CityRoutePlanner

#Sample Usage

=============================================================================================== 
******Welcome to the GPS Program******
=============================================================================================== 
Enter your starting point: Anaheim
Enter your destination: Bakersfield
=============================================================================================== 
ANAHEIM, population: 1273000 people, elevation: 310 ft.
BAKERSFIELD, population: 31100 people, elevation: 390 ft.
The shortest trip from ANAHEIM to BAKERSFIELD is 225 miles.
Through the route: ANAHEIM-->VICTORVILLE-->CHINO-->GROVE-->ISABELLA-->BAKERSFIELD
=============================================================================================== 
Enter (Y/y) for a new trip or (N/n) to quit: n
=============================================================================================== 
Thank you for using the GPS Program
===============================================================================================

#Algorithms Used
  -Dijkstra's Algorithm for shortest path calculation
  -Custom MinHeap for Dijkstra's priority queue

#Potential Improvements
  -Add GUI or visual route display
  -Use real-world data 
  -Support for bidirectional roads or one-way traffic rules

#License 
This project is for educational purposes and is open for extension and modification.

#Author
Created by Andrew Nazarov

