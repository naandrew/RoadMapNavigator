# RoadMapNavigator

A C++ console application that calculates the shortest route between cities using Dijkstra's algortithm 

#Features
-Calculates the shortest path between two cities using Dijkstra's algorithm
- Supports both Depth-First and Breadth-First traversals
- Reads city and road data from external files
- Displays route, distance, population, and elevation of selected cities
- Custom implementation of a min-heap priority queue for pathfinding

#File Structure
├── main.cpp          # Main program logic and user interface
├── graph.h           # Graph class with Dijkstra, DFS, and BFS
├── minHeap.h         # Custom min-heap used for Dijkstra's algorithm
├── city.txt          # Input file containing city data
├── road.txt          # Input file containing road (edge) data
└── README.md         # File that explains project
