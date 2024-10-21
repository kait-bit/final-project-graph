/*********************
Name: Kaitlin Spell
Final Project
Purpose: This program creates an unweighted and undirected graph.
**********************/

#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"
#include <iostream>
#include <iomanip>
#include <vector>

class Graph {

public:

    Graph();
    ~Graph();

    bool isEmpty();
    int getVertexCount();
    int getEdgeCount();
    void displayGraph();
    bool addVertex(int, const string*);
    bool addEdge(int, int);
    bool removeVertex(int);
    bool removeEdge(int, int);
    bool getVertex(Data*, int);
    bool getEdge(int, int);
    bool clear();
    bool dfs(int);

private:

    int vertexCount;
    int edgeCount;

    std::vector<std::vector<int>> matrix;
    std::vector<Data*> vertices;
    std::vector<bool> visited;

    bool verifyVertex(int);
    int findIndex(int);
    bool dfsHelper(int, std::vector<bool>&);
};

#endif /* GRAPH_H */
