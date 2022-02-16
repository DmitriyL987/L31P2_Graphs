#include "IGraph.h"
#include "Service.h"

int main() {
    std::cout << "*** IGraph ***" << std::endl;
    std::vector<IGraph*> igraph;

    helper();
    bool loop = true;
    while(loop)
    {// generals loop
        int sel;
        std::cout << "select: ";
        std::cin >> sel;
        switch (sel)
        {
            case 0:
                loop = false;
                break;
            case 1:
                CreateGraph(igraph);
                break;
            case 2:
                CreateCopy(igraph);
                break;
            case 3:
                addEdges(igraph);
                break;
            case 4:
                ShowGraph(igraph);
                break;
            case 5:
                CountV(igraph);
                break;
            case 6:
                Prev(igraph);
                break;
            case 7:
                Next(igraph);
                break;
            case 8:
                CopyGraph(igraph);
                break;
            case 9:
                helper();
                break;
            default:
                std::cout << "instruction not selected" << std::endl;
                break;
        }

    }// end generals loop
}