#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include "edge.h"

class vertex
{
public:
    vertex();
    vertex(int32_t _cityID, std::string _cityName);

    void setCityID(int32_t);
    void setCityName(std::string);
    int32_t getCityID();
    std::string getCityName();
    std::list<edge> getEdgeList();
    void printEdgeList();

    std::list<edge> edgeList;

private:
    int32_t cityID;
    std::string cityName;
};