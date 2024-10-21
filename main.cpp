/*********************
Name: Kaitlin Spell
Final Project
Purpose: This program creates an unweighted and undirected graph.
**********************/

#include "main.h"

int main(int argc, char** argv) {
    srand(time(NULL));

// Create test data (includes invalid data for id and string)
    int tempId1, tempId2;
    Data tempData;

    int ids[TESTDATA] = {-1, 1, 7, 8, 14, 23, 45, 55, 89, 99, 99};
    string strings[TESTDATA] = {" ", "One", "Seven", "Eight", "Fourteen", "Twenty three", "Fourty five", "Fifty five", "Eighty nine", "Ninety nine", "Ninety nine"};

// Create graph
    Graph myGraph;

    std::cout << "Graph created..." << std::endl << std::endl;

// *****************************
// Test methods on empty graph
// *****************************
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Testing methods on empty graph:" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

// isEmpty
    if (myGraph.isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
    } else {
        std::cout << "The graph is NOT empty." << std::endl;
    }

// getVertexCount
    std::cout << "Vertex count: " << myGraph.getVertexCount() << std::endl;

// getEdgeCount
    std::cout << "Edge count: " << myGraph.getEdgeCount() << std::endl << std::endl;

// displayGraph
    std::cout << "Displaying graph:" << std::endl;
    myGraph.displayGraph();

// removeVertex
    tempId1 = 1+(rand()%100);
    if (myGraph.removeVertex(tempId1)) {
        std::cout << "Successfully removed " << std::endl;
    } else {
        std::cout << "Remove vertex failed." << std::endl;
    }

// removeEdge
    tempId1 = 1+(rand()%100);
    tempId2 = 1+(rand()%100);
    if (myGraph.removeEdge(tempId1,tempId2)) {
        std::cout << "Successfully removed " << std::endl;
    } else {
        std::cout << "Remove edge failed." << std::endl;
    }

// getVertex
    tempId1 = 1+(rand()%100);
    if (myGraph.getVertex(&tempData, tempId1)) {
        std::cout << "Successfully found " << std::endl;
    } else {
        std::cout << "Failed to get vertex." << std::endl;
    }

// getEdge
    for (int i = 1; i < TESTDATA; i++) {
        std::cout << "Searching for an edge between " << ids[i] << " & " << ids[i-1] << "... ";
        if (myGraph.getEdge(ids[i], ids[i-1])) {
            std::cout << "Edge found successfully." << std::endl;
        } else {
            std::cout << "Failed to get edge." << std::endl;
        }
    }

        std::cout << std::endl << std::endl;

// *****************************
// Test filling graph with data
// *****************************
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Filling graph:" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

// addVertex
    for (int i = 0; i < TESTDATA; i++) {
        std::cout << "Adding " << ids[i] << "... ";
        if (myGraph.addVertex(ids[i], &strings[i])) {
            std::cout << "Added successfully." << std::endl;
        } else {
            std::cout << "Not added." << std::endl;
        }
    }

// addEdge
    for (int i = 1; i < TESTDATA; i++) {
        std::cout << "Adding edge between " << ids[i] << " & " << ids[i-1] << "... ";
        if (myGraph.addEdge(ids[i], ids[i-1])) {
            std::cout << "Added successfully." << std::endl;
        } else {
            std::cout << "Not added." << std::endl;
        }
    }

    for (int i = 1; i < TESTEDGES; i++) {
        std::cout << "Adding edge between " << ids[i] << " & " << ids[i+3] << "... ";
        if (myGraph.addEdge(ids[i], ids[i+3])) {
            std::cout << "Added successfully." << std::endl;
        } else {
            std::cout << "Not added." << std::endl;
        }
    }

    std::cout << std::endl;

// isEmpty
    if (myGraph.isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
    } else {
        std::cout << "The graph is NOT empty." << std::endl;
    }

// getVertexCount
    std::cout << "Vertex count: " << myGraph.getVertexCount() << std::endl;

// getEdgeCount
    std::cout << "Edge count: " << myGraph.getEdgeCount() << std::endl << std::endl;

// displayGraph
    std::cout << "Displaying graph:" << std::endl;
    myGraph.displayGraph();
    std::cout << std::endl;

// getVertex
    for (int i = 1; i < TESTDATA; i++) {
        tempId1 = (rand()%TESTDATA);

        std::cout << "Searching for " << tempId1 << std::endl;

        if (myGraph.getVertex(&tempData, tempId1)) {
            std::cout << "Successfully found " << std::endl;
        } else {
            std::cout << "Failed to get vertex." << std::endl;
        }
    }

// getEdge
    for (int i = 1; i < TESTDATA; i++) {
        std::cout << "Searching for an edge between " << ids[i] << " & " << ids[i-1] << "... ";
        if (myGraph.getEdge(ids[i], ids[i-1])) {
            std::cout << "Edge found successfully." << std::endl;
        } else {
            std::cout << "Failed to get edge." << std::endl;
        }
    }

        std::cout << std::endl << std::endl;

// *****************************
// Test removing data from graph
// *****************************
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Emptying graph:" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

// removeEdge
    std::cout << std::endl;
    std::cout << "Removing edges..." << std::endl;

    for (int i = 1; i < TESTDATA; i++) {
        std::cout << "Removing edge between " << ids[i] << " & " << ids[i-1] << "... ";
        if (myGraph.removeEdge(ids[i], ids[i-1])) {
            std::cout << "Removed successfully." << std::endl;
        } else {
            std::cout << "Not removed." << std::endl;
        }
    }

    for (int i = 1; i < TESTEDGES; i++) {
        std::cout << "Removing edge between " << ids[i] << " & " << ids[i+3] << "... ";
        if (myGraph.removeEdge(ids[i], ids[i+3])) {
            std::cout << "Removed successfully." << std::endl;
        } else {
            std::cout << "Not removed." << std::endl;
        }
    }

    std::cout << std::endl;

// removeVertex
    std::cout << "Removing vertices..." << std::endl;

    for (int i = 0; i < TESTDATA; i++) {
        std::cout << "Removing " << ids[i] << "... ";
        if (myGraph.removeVertex(ids[i])) {
            std::cout << "Removed successfully." << std::endl;
        } else {
            std::cout << "Not removed." << std::endl;
        }
    }

    std::cout << std::endl;

// isEmpty
    if (myGraph.isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
    } else {
        std::cout << "The graph is NOT empty." << std::endl;
    }

// getVertexCount
    std::cout << "Vertex count: " << myGraph.getVertexCount() << std::endl;

// getEdgeCount
    std::cout << "Edge count: " << myGraph.getEdgeCount() << std::endl << std::endl;

// displayGraph
    std::cout << "Displaying graph:" << std::endl;
    myGraph.displayGraph();
    std::cout << std::endl;

// *****************************
// Test filling graph with data and using DFS and clear method
// *****************************
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Filling graph to test DFS and clear methods:" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

// addVertex
    for (int i = 0; i < TESTDATA; i++) {
        std::cout << "Adding " << ids[i] << "... ";
        if (myGraph.addVertex(ids[i], &strings[i])) {
            std::cout << "Added successfully." << std::endl;
        } else {
            std::cout << "Not added." << std::endl;
        }
    }

// addEdge
    for (int i = 1; i < TESTDATA; i++) {
        std::cout << "Adding edge between " << ids[i] << " & " << ids[i-1] << "... ";
        if (myGraph.addEdge(ids[i], ids[i-1])) {
            std::cout << "Added successfully." << std::endl;
        } else {
            std::cout << "Not added." << std::endl;
        }
    }

    for (int i = 1; i < TESTEDGES; i++) {
        std::cout << "Adding edge between " << ids[i] << " & " << ids[i+3] << "... ";
        if (myGraph.addEdge(ids[i], ids[i+3])) {
            std::cout << "Added successfully." << std::endl;
        } else {
            std::cout << "Not added." << std::endl;
        }
    }

    std::cout << std::endl;

// displayGraph
    std::cout << "Displaying graph:" << std::endl;
    myGraph.displayGraph();
    std::cout << std::endl;

// dfs
    std::cout << "Beginning depth first search..." << std::endl;
    std::cout << "DFS starting at index 0: " << myGraph.dfs(0) << std::endl;
    std::cout << "DFS starting at index 1: " << myGraph.dfs(1) << std::endl;
    std::cout << std::endl;

// isEmpty
    if (myGraph.isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
    } else {
        std::cout << "The graph is NOT empty." << std::endl;
    }

// getVertexCount
    std::cout << "Vertex count: " << myGraph.getVertexCount() << std::endl;

// getEdgeCount
    std::cout << "Edge count: " << myGraph.getEdgeCount() << std::endl << std::endl;

// clear
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Clearing graph:" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    myGraph.clear();

// displayGraph
    std::cout << "Displaying graph:" << std::endl;
    myGraph.displayGraph();
    std::cout << std::endl;

// isEmpty
    if (myGraph.isEmpty()) {
        std::cout << "The graph is empty." << std::endl;
    } else {
        std::cout << "The graph is NOT empty." << std::endl;
    }

// getVertexCount
    std::cout << "Vertex count: " << myGraph.getVertexCount() << std::endl;

// getEdgeCount
    std::cout << "Edge count: " << myGraph.getEdgeCount() << std::endl << std::endl;

    return 0;
}
