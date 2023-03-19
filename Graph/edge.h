#pragma once
#include <iostream>
#include <iterator>

class edge
{
public:
    edge(int32_t, int32_t);
    void setEdges(int32_t, int32_t);
    void setWeight(int32_t);
    int32_t getDestination();
    int32_t getWeight();

private:
    int32_t destinationVertexID;
    int32_t weight;
};
