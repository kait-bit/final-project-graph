/*********************
Name: Kaitlin Spell
Final Project
Purpose: This program creates an unweighted and undirected graph.
**********************/

#include "graph.h"

Graph::Graph() {
    vertexCount = 0;
    edgeCount = 0;
}

Graph::~Graph() {
    clear();
}

bool Graph::isEmpty() {
    return (vertexCount == 0 && edgeCount == 0);
}

int Graph::getVertexCount() {
    return vertexCount;
}

int Graph::getEdgeCount() {
    return edgeCount;
}

void Graph::displayGraph() {
    std::cout << std::setw(3) << " ";
    for (int i = 0; i < vertexCount; i++) {
        std::cout << std::setw(3) << vertices[i]->id;
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < vertexCount; i++) {
        std::cout << std::setw(3) << vertices[i]->id << "  ";
        for (int j = 0; j < vertexCount; j++) {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

bool Graph::addVertex(int id, const string* str) {
    bool status = false;

    if (!verifyVertex(id) && id > 0 && *str != "") {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i].push_back(0);
        }
        std::vector<int> newRow(matrix.size() + 1, 0);
        matrix.push_back(newRow);

        Data* data = new Data;
        data->id = id;
        data->information = *str;
        vertices.push_back(data);

        vertexCount++;
        status = true;
    }

    return status;
}

bool Graph::addEdge(int idA, int idB) {
    bool status = false;

    if (verifyVertex(idA) && verifyVertex(idB) && !(idA == idB)) {
        int indexA = findIndex(idA);
        int indexB = findIndex(idB);

        if (!(matrix[indexA][indexB] == 1)) {
            matrix[indexA][indexB] = 1;
            matrix[indexB][indexA] = 1;
        
            edgeCount++;
            status = true;
        }
    }

    return status;
}

bool Graph::removeVertex(int id) {
    bool status = false;

    if (verifyVertex(id)) {
        int index = findIndex(id);

        for (int i = 0; i < vertexCount; i++) {
            matrix[i].erase(matrix[i].begin() + index);
        }
        matrix.erase(matrix.begin() + index);
        vertices.erase(vertices.begin() + index);

        vertexCount--;
        status = true;
    }

    return status;
}

bool Graph::removeEdge(int idA, int idB) {
    bool status = false;

    if (verifyVertex(idA) && verifyVertex(idB) && !(idA == idB)) {
        int indexA = findIndex(idA);
        int indexB = findIndex(idB);
        
        if (!(matrix[indexA][indexB] == 0)) {
            matrix[indexA][indexB] = 0;
            matrix[indexB][indexA] = 0;
        
            edgeCount--;
            status = true;
        }
    }

    return status;
}

bool Graph::getVertex(Data* data, int dataId) {
    bool status = false;

    if (dataId > 0) {
        for (int i = 0; i < vertexCount; i++) {
            if (vertices[i]->id == dataId) {
                data->id = dataId;
                data->information = vertices[i]->information;
                status = true;
            }
        }
    }

    return status;
}

bool Graph::getEdge(int idA, int idB) {
    bool status = false;

    if (verifyVertex(idA) && verifyVertex(idB) && !(idA == idB)) {
        int indexA = findIndex(idA);
        int indexB = findIndex(idB);

        if ((matrix[indexA][indexB] == 1)) {
            status = true;
        }
    }

    return status;
}

bool Graph::clear() {
    bool status = false;

    for (int i = 0; i < vertexCount; i++) {
        matrix[i].erase(matrix[i].begin() + i);
    }
    matrix.erase(matrix.begin());
    vertices.erase(vertices.begin());

    vertexCount = 0;
    edgeCount = 0;
    status = true;

    return status;
}

bool Graph::verifyVertex(int dataId) {
    bool status = false;

    for (int i = 0; i < vertexCount; i++) {
        if (vertices[i]->id == dataId) {
            status = true;
        }
    }

    return status;
}

int Graph::findIndex(int dataId) {
    int index = -1;

    for (int i = 0; i < vertexCount; i++) {
        if (vertices[i]->id == dataId) {
            index = i;
        } 
    }

    return index;
}

bool Graph::dfs(int index) {
    bool status = false;
    std::vector<bool> visited(vertices.size(), false);

    status = dfsHelper(index, visited);
    
    return status;
}

bool Graph::dfsHelper(int index, std::vector<bool>& visited) {
    bool status = false;
    visited[index] = true;

    if (status == false) {
        std::cout << vertices[index]->id << " " << "->" << " ";
    }
    
    for (int i = 0; i < vertexCount; i++) {
        if (matrix[index][i] && !visited[i]) {
            status = dfsHelper(i, visited);
        } else {
            status = true;
        }
    }

    return status;
}
