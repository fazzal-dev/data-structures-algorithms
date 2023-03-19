#include <iostream>
#include "graph.h"
#include "vertex.h"
#include "edge.h"

// Constructors
edge::edge(int32_t _destination, int32_t _weight) : destinationVertexID(_destination), weight(_weight) {}

vertex::vertex() : cityID(0), cityName(" ") {}
vertex::vertex(int32_t _cityID, std::string _cityName) : cityID(_cityID), cityName(_cityName) {}

// edge class getter&setters
void edge::setEdges(int32_t _dest, int32_t _weight)
{
    this->destinationVertexID = _dest;
    this->weight = _weight;
}

void edge::setWeight(int32_t _weight)
{
    this->weight = _weight;
}

int32_t edge::getDestination()
{
    return destinationVertexID;
}

int32_t edge::getWeight()
{
    return weight;
}

// vertex class getter&setters
void vertex::setCityID(int32_t _cityID)
{
    this->cityID = _cityID;
}

void vertex::setCityName(std::string _cityName)
{
    this->cityName = _cityName;
}

int32_t vertex::getCityID()
{
    return cityID;
}

std::string vertex::getCityName()
{
    return cityName;
}

std::list<edge> vertex::getEdgeList()
{
    return edgeList;
}

void graph::addVertex(vertex _vertex)
{

    bool check{checkIfVertexAlreadyExist(_vertex.getCityID())};
    if (check == true)
        std::cerr << "vertex already exist\n";
    else
        vertices.push_back(_vertex);
}

bool graph::checkIfVertexAlreadyExist(int32_t _cityID)
{

    for (int32_t i = 0; i < vertices.size(); i++)
    {
        if (vertices.at(i).getCityID() == _cityID)
        {
            return true;
        }
    }
    return false;
}

bool graph::checkIfEdgeExistByID(int32_t _source, int32_t _destination)
{
    vertex v = getVertexByID(_source);
    std::list<edge> e;
    e = v.getEdgeList();
    for (auto i = e.begin(); i not_eq e.end(); i++)
    {
        if (i->getDestination() == _destination)
        {
            return true;
        }
    }
    return false;
}

vertex graph::getVertexByID(int32_t _cityID)
{
    vertex temp;
    for (int32_t i = 0; i < vertices.size(); i++)
    {
        temp = vertices.at(i);
        if (temp.getCityID() == _cityID)
            return temp;
    }
    return temp;
}

void graph::addEdgeByID(int32_t _source, int32_t _destination, int32_t _weight)
{
    bool checkSourceVertex{checkIfVertexAlreadyExist(_source)};
    bool checkDestVertex{checkIfVertexAlreadyExist(_destination)};
    if (checkSourceVertex and checkDestVertex == true)
    {
        bool checkEdge = checkIfEdgeExistByID(_source, _destination);
        if (checkEdge == true)
            std::cout << "Edge Already Exist!\n";
        else
        {
            for (int32_t i = 0; i < vertices.size(); i++)
            {
                if (vertices.at(i).getCityID() == _source)
                {
                    edge e(_destination, _weight);
                    vertices.at(i).edgeList.push_back(e);
                }
                else if (vertices.at(i).getCityID() == _destination)
                {
                    edge e(_source, _weight);
                    vertices.at(i).edgeList.push_back(e);
                }
            }
            std::cout << "Edge Added Successfully!" << std::endl;
        }
    }
    else
        std::cout << "Invalid Vertex ID!\n";
}

void graph::updateEdgeByID(int32_t _source, int32_t _destination, int32_t _weight)
{
    bool checkEdge{checkIfEdgeExistByID(_source, _destination)};
    if (checkEdge == true)
    {
        for (size_t i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getCityID() == _source)
            {
                for (auto it = vertices.at(i).edgeList.begin(); it not_eq vertices.at(i).edgeList.end(); it++)
                {
                    if (it->getDestination() == _destination)
                    {
                        it->setWeight(_weight);
                        break;
                    }
                }
            }
            else if (vertices.at(i).getCityID() == _destination)
            {
                for (auto it = vertices.at(i).edgeList.begin(); it not_eq vertices.at(i).edgeList.end(); i++)
                {
                    if (it->getDestination() == _source)
                    {
                        it->setWeight(_weight);
                        break;
                    }
                }
            }
        }
        std::cout << "Edge weight Updated successfully!" << std::endl;
    }
    else
    {
        std::cout << "Edge Does not Exist!" << std::endl;
    }
}

void graph::deleteEdgeByID(int32_t _source, int32_t _destination)
{
    bool checkEdge{checkIfEdgeExistByID(_source, _destination)};
    if (checkEdge == true)
    {
        for (size_t i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getCityID() == _source)
            {
                for (auto it = vertices.at(i).edgeList.begin(); it not_eq vertices.at(i).edgeList.end(); it++)
                {
                    if (it->getDestination() == _destination)
                    {
                        vertices.at(i).edgeList.erase(it);
                        break;
                    }
                }
            }
            else if (vertices.at(i).getCityID() == _destination)
            {
                for (auto it = vertices.at(i).edgeList.begin(); it not_eq vertices.at(i).edgeList.end(); i++)
                {
                    if (it->getDestination() == _source)
                    {
                        vertices.at(i).edgeList.erase(it);
                        break;
                    }
                }
            }
        }
        std::cout << "Edge Deleted successfully!" << std::endl;
    }
    else
    {
        std::cout << "Edge Does not Exist!" << std::endl;
    }
}

void graph::deleteVertexByID(int32_t _vertexID)
{
    int32_t vertexIndex{};
    for (size_t i = 0; i < vertices.size(); i++)
    {
        if (vertices.at(i).getCityID() == _vertexID)
            vertexIndex = i;
    }
    for (auto it = vertices.at(vertexIndex).edgeList.begin(); it not_eq vertices.at(vertexIndex).edgeList.end(); it++)
    {
        deleteEdgeByID(it->getDestination(), _vertexID);
    }
    vertices.erase(vertices.begin() + vertexIndex);
    std::cout << "Vertex Deleted Succesfully!" << std::endl;
}

void graph::updateVertex(int32_t _vertexID, std::string _cityName)
{
    bool checkVertexExist = checkIfVertexAlreadyExist(_vertexID);
    if (checkVertexExist)
    {
        for (size_t i = 0; i < vertices.size(); i++)
        {
            if (vertices.at(i).getCityID() == _vertexID)
            {
                vertices.at(i).setCityName(_cityName);
                break;
            }
        }
        std::cout << "Updated Vertex Successfully!" << std::endl;
    }
}

void graph::printGraph()
{

    for (int32_t i = 0; i < vertices.size(); i++)
    {
        vertex temp;
        temp = vertices.at(i);
        std::cout << temp.getCityName() << " (" << temp.getCityID() << ") --> ";
        temp.printEdgeList();
    }
}

void vertex::printEdgeList()
{
    std::cout << "[";
    for (auto it = edgeList.begin(); it not_eq edgeList.end(); it++)
    {
        std::cout << it->getDestination() << "(" << it->getWeight() << ") --> ";
    }
    std::cout << "]";
    std::cout << std::endl;
}