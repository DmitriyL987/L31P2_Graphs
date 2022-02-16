#include "Service.h"

void helper(){
    system("clear");
    std::cout << "******** Command  list ********\n" << std::endl;
    std::cout << "Create a Graph               - 1" << std::endl;
    std::cout << "Create a graph with copying  - 2" << std::endl;
    std::cout << "Add Edges                    - 3" << std::endl;
    std::cout << "Show Graph as matrix or list - 4" << std::endl;
    std::cout << "Count vertices               - 5" << std::endl;
    std::cout << "Previous vertices            - 6" << std::endl;
    std::cout << "Next vertices                - 7" << std::endl;
    std::cout << "Copy graph                   - 8" << std::endl;
    std::cout << "Help                         - 9" << std::endl;
    std::cout << "Exit                         - 0" << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

void CreateGraph(std::vector <IGraph*> &igraph){
    int ans;
    std::cout << "Create List - 1 or Matrix - 2" <<std::endl;
    std::cin >> ans;
    if (ans == 1) {
        IGraph* a = new ListGraph();
        igraph.push_back(a);
        std::cout << "The graph № " << igraph.size()-1
                  << " is created as an adjacency list" << std::endl;
    } else if (ans == 2) {
        IGraph* a = new MatrixGraph();
        igraph.push_back(a);
        std::cout << "The graph № " << igraph.size()-1
                  << " is created as an adjacency matrix" << std::endl;
    }
}

void CreateCopy(std::vector <IGraph*> &igraph){
    std::cout << "Enter the number of the source graph: ";
    int n;
    std::cin >> n;
    if (n >= 0 && n < igraph.size()){
        IGraph* a(igraph[n]);
        igraph.push_back(a);
        std::cout << "create complete IGraph № " << igraph.size() << std::endl;
    } else std::cout << "The graph has not been created,"
                     <<" the number does not exist" << std::endl;
}

void addEdges(std::vector <IGraph*> &igraph){
    std::cout << "Enter the graph number and the desired number of edges: ";
    int n, m;
    std::cin >> n >> m;
    if (n >= 0 && n < igraph.size()){
        std::cout << "Enter vertices - from - to:" << std::endl;
        auto tmpM = dynamic_cast<MatrixGraph*>(igraph[n]);
        auto tmpL = dynamic_cast<ListGraph*>(igraph[n]);
        for(int i = 0; i < m; ++i){
            std::cout << "> ";
            int from, to;
            std::cin >> from >> to;
            if (tmpM){
                tmpM->AddEdge(from, to);
            } else if (tmpL) {
                tmpL->AddEdge(from, to);
            }
        }
    } else std::cout << "Out of range" << std::endl;
}

void ShowGraph(std::vector <IGraph*> &igraph){
    std::cout << "Enter number graph for show: ";
    int n;
    std::cin >> n;
    if(n >=0 && n < igraph.size())
    {
        if (auto s = dynamic_cast<MatrixGraph*>(igraph[n]); s ){
            for (int i =0; i < s->matrix.size(); ++i) {
                //  matrix a
                for (int j = 0; j < s->matrix[i].size(); ++j) {
                    std::cout << s->matrix[i][j] << "  ";
                }
                std::cout << std::endl;
            }
        }else if (auto s = dynamic_cast<ListGraph*>(igraph[n]); s )
        {
            for (int i =0; i < s->list.size(); ++i) {
                //  list c
                for (int j = 0; j < s->list[i].size(); ++j)
                    std::cout << s->list[i][j] << " ";
                std::cout << std::endl;
            }
        }
    } else std::cout << "Out of range" << std::endl;
}

void CountV(std::vector <IGraph*> &igraph){
    std::cout << "Enter number graph for show count vertices: ";
    int n;
    std::cin >> n;
    if(n >=0 && n < igraph.size()){
        std::cout << igraph[n]->VerticesCount() << std::endl;
    } else std::cout << "Out of range" << std::endl;
}

void Prev(std::vector <IGraph*> &igraph){
    std::vector<int> result;
    std::cout << "Enter number graph and number vertices for show: ";
    int n, v;
    std::cin >> n>> v;
    if((n >=0 && n < igraph.size()) && v >= 0 && v < igraph[n]->VerticesCount()){
        igraph[n]->GetPrevVertices(v, result);

        std::cout << "All preceding " << n << " vertices:" << std::endl;
        for (int i = 0; i < result.size(); ++i){
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    }
}

void Next(std::vector <IGraph*> &igraph){
    std::vector<int> result;
    std::cout << "Enter number graph and number vertices for show: ";
    int n, v;
    std::cin >> n >> v;
    if((n >=0 && n < igraph.size()) && v >= 0 && v < igraph[n]->VerticesCount()){
        igraph[n]->GetNextVertices(v, result);

        std::cout << "all subsequent " << n << " vertices:" << std::endl;
        for (int i = 0; i < result.size(); ++i){
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    }
}

void CopyGraph(std::vector<IGraph*>&igraph){
    int a,b;
    std::cout << "Enter number graph source: ";
    std::cin >> a;
    std::cout << "Enter number graph target: ";
    std::cin >> b;
    if (a !=b && a >= 0 && a < igraph.size() && b >= 0 && b < igraph.size()){
        if(auto bb = dynamic_cast<MatrixGraph*>(igraph[b])) {
            *bb = igraph[a];
        } else if(auto bb = dynamic_cast<ListGraph*>(igraph[b])){
            *bb = igraph[a];
        }
    } else std::cout << "Out of range" << std::endl;
}