#include <iostream>
#include "graph.h"
int main()
{
    graph g;
    std::string cityName;
    int source, destinaion, weight;
    int option;
    bool check;

    do
    {
        std::cout << "What operation do you want to perform? "
                  << " Select Option number. Enter 0 to exit." << std::endl;
        std::cout << "1. Add Vertex" << std::endl;
        std::cout << "2. Update Vertex" << std::endl;
        std::cout << "3. Delete Vertex" << std::endl;
        std::cout << "4. Add Edge" << std::endl;
        std::cout << "5. Update Edge" << std::endl;
        std::cout << "6. Delete Edge" << std::endl;
        std::cout << "7. Check if 2 Vertices are Neigbors" << std::endl;
        std::cout << "8. Print Graph" << std::endl;
        std::cout << "9. Clear Screen" << std::endl;
        std::cout << "0. Exit Program" << std::endl;

        std::cin >> option;
        vertex v1;

        switch (option)
        {
        case 0:

            break;

        case 1:
            std::cout << "Add Vertex Operation -" << std::endl;
            std::cout << "Enter City ID :";
            std::cin >> source;
            std::cout << "Enter City Name :";
            std::cin >> cityName;
            v1.setCityID(source);
            v1.setCityName(cityName);
            g.addVertex(v1);

            break;

        case 2:
            std::cout << "Update Vertex Operation -" << std::endl;
            std::cout << "Enter City ID of Vertex(City) to update :";
            std::cin >> source;
            std::cout << "Enter City Name :";
            std::cin >> cityName;
            g.updateVertex(source, cityName);

            break;

        case 3:
            std::cout << "Delete Vertex Operation -" << std::endl;
            std::cout << "Enter ID of Vertex(City) to Delete : ";
            std::cin >> source;
            g.deleteVertexByID(source);

            break;

        case 4:
            std::cout << "Add Edge Operation -" << std::endl;
            std::cout << "Enter ID of Source Vertex(City): ";
            std::cin >> source;
            std::cout << "Enter ID of Destination Vertex(City): ";
            std::cin >> destinaion;
            std::cout << "Enter Weight of Edge: ";
            std::cin >> weight;
            g.addEdgeByID(source, destinaion, weight);

            break;

        case 5:
            std::cout << "Update Edge Operation -" << std::endl;
            std::cout << "Enter ID of Source Vertex(City): ";
            std::cin >> source;
            std::cout << "Enter ID of Destination Vertex(City): ";
            std::cin >> destinaion;
            std::cout << "Enter UPDATED Weight of Edge: ";
            std::cin >> weight;
            g.updateEdgeByID(source, destinaion, weight);

            break;

        case 6:
            std::cout << "Delete Edge Operation -" << std::endl;
            std::cout << "Enter ID of Source Vertex(City): ";
            std::cin >> source;
            std::cout << "Enter ID of Destination Vertex(City): ";
            std::cin >> destinaion;
            g.deleteEdgeByID(source, destinaion);

            break;

        case 7:
            std::cout << "Check if 2 Vertices are Neigbors -" << std::endl;
            std::cout << "Enter ID of Source Vertex(City): ";
            std::cin >> source;
            std::cout << "Enter ID of Destination Vertex(City): ";
            std::cin >> destinaion;
            check = g.checkIfEdgeExistByID(source, destinaion);
            if (check == true)
            {
                std::cout << "Vertices are Neigbors (Edge exist)";
            }
            else
            {
                std::cout << "Vertices are NOT Neigbors (Edge does NOT exist)";
            }

            break;

        case 8:
            std::cout << "Print Graph Operation -" << std::endl;
            g.printGraph();

            break;

        case 9:
            system("cls");
            break;

        default:
            std::cout << "Select Valid Option!" << std::endl;
        }
        std::cout << std::endl;

    } while (option != 0);
    std::cout << std::endl;

    return 0;
}