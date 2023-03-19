#pragma once
#include <iostream>
#include <vector>
#include "vertex.h"

class graph
{
public:
    void addVertex(vertex);
    void updateVertex(int32_t, std::string);
    bool checkIfVertexAlreadyExist(int32_t);
    void addEdgeByID(int32_t, int32_t, int32_t);
    void updateEdgeByID(int32_t, int32_t, int32_t);
    void deleteEdgeByID(int32_t, int32_t);
    void deleteVertexByID(int32_t);
    bool checkIfEdgeExistByID(int32_t, int32_t);
    vertex getVertexByID(int32_t);

    void printGraph();

private:
    std::vector<vertex> vertices;
};