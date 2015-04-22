/*
 * Created by Johan Oakes on 4/21/15.
 *
 *
*/

#ifndef FBDATA_UNDIRECTED_GRAPH_H
#define FBDATA_UNDIRECTED_GRAPH_H

#include <iostream>


class Graph {

private:
    bool** adjacencyMatrix; // Multidimensional matrix holding values 1 or 0
    int vertexCount;

public:

    /* Initialize adjacency matrix to all 0s */
    Graph(int vertexCount) {
        this -> vertexCount = vertexCount;
        for (int i = 0;i < vertexCount; i++) {
            adjacencyMatrix = new bool *[vertexCount];
            for (int j = 0; j < vertexCount; j++)
                adjacencyMatrix[i][j] = false;
        }
    }

    /*
     * Mark a 1 in the adjacency matrix if an edge exists between two nodes
     * - Idea: mark each vertex read with an int so that we can send it to addEdge
     */
    void addEdge(int i, int j) {
        if (i >=0 && i < vertexCount && j > 0 && j < vertexCount) {
            adjacencyMatrix[i][j] = true;
            adjacencyMatrix[j][i] = true;
        }
    }

    void removeEdge (int i, int j) {
        if (i >=0 && i < vertexCount && j > 0 && j < vertexCount) {
            adjacencyMatrix[i][j] = false;
            adjacencyMatrix[j][i] = false;
        }
    }

    bool isEdge (int i, int j) {
        if (i >=0 && i < vertexCount && j > 0 && j < vertexCount)
            return adjacencyMatrix[i][j];
        else
            return false;
    }

    /* Destructor */
    ~Graph() {
        for (int i = 0; i < vertexCount; i++)
            delete[] adjacencyMatrix[i];
        delete[] adjacencyMatrix;
    }

};


#endif //FBDATA_UNDIRECTED_GRAPH_H
