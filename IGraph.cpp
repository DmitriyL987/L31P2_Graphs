#include "IGraph.h"
//----------------- MatrixGraph -------------

MatrixGraph& MatrixGraph:: operator=(const MatrixGraph& oth){
    std::cout << "MatrixGraph& MatrixGraph:: operator=(const MatrixGraph& oth)" << std::endl;
    matrix.clear();
    matrix.resize(oth.matrix.size());
    for(int i = 0; i < matrix.size(); ++i){
        matrix[i].resize(oth.matrix[i].size());
        for (int j = 0; j < oth.matrix.size(); ++j){
            matrix[i][j] = oth.matrix[i][j];
        }
    }
    return *this;
}
MatrixGraph& MatrixGraph::operator=(const ListGraph& oth){
    std::cout << "MatrixGraph& MatrixGraph::operator=(const ListGraph& oth)" << std::endl;
    int a = oth.list.size();
    matrix.resize(a);
    for(int i = 0; i < matrix.size(); ++i){
        matrix[i].resize(a);
        for (int j = 0; j < oth.list[i].size(); ++j) {
            matrix[i].emplace((matrix[i].begin()+oth.list[i][j]), true);
        }
    }
    return  *this;
}

MatrixGraph::MatrixGraph(IGraph *oth) {
    std::cout << "MatrixGraph::MatrixGraph(IGraph *oth)" ;
    if(auto *ms = dynamic_cast<MatrixGraph*>(oth); ms != nullptr){
        std::cout << " IGraph *oth определен как матрица" << std::endl;
        *this = *ms;
    } else if (auto ls = dynamic_cast<ListGraph*>(oth); ls != nullptr){
        std::cout << " IGraph *oth определен как список" << std::endl;
        *this = *ls;
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    if(from == to) {
        std::cerr << "Error. Edge not created" << std::endl;
        return;
    }
    int a = std::max(from,to);
    ++a;
    if (a > matrix.size()) {
        matrix.resize(a);
        for (int i = 0; i < a; ++i) matrix[i].resize(a);
    }
    matrix[from].emplace(matrix[from].begin()+ to, true);
}

int MatrixGraph::VerticesCount() {
    int countVertices = 0;
    int matrixsize = matrix.size();
    for (int i = 0; i < matrixsize; ++i){
        for(int j = 0; j < matrixsize; ++j){
            if(i == j) continue; // проверка на петлю
            if (matrix[i][j] != matrix[j][i]) { // проверка на ориентированность
                if(matrix[i][j]) {
                    if(countVertices != 0) countVertices += 1;
                    else countVertices += 2;
                    break; // выходим из вложенного цикла сразу как найдём ребро - значит вершина не висячая
                }
            }
        }
    }
    std::cout << "int MatrixGraph::VerticesCount()" << std::endl;
    return countVertices;
}

void MatrixGraph::GetNextVertices(int vertex, std::vector<int> &vertices) {
    int matrixsize = matrix.size();
    for (int i = 0; i < matrixsize; ++i){
        if(matrix[vertex][i]){
            vertices.push_back(i);
        }
    }
    std::cout << std::endl;
}

void MatrixGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) {
    int matrixsize = matrix.size();
    for (int i = 0; i < matrixsize; ++i){
        if(matrix[i][vertex]){
            vertices.push_back(i);
        }
    }
    std::cout << std::endl;
}

//-------------------------- ListGraph --------------

ListGraph& ListGraph::operator=(const ListGraph &oth) {
    std::cout << "ListGraph& ListGraph::operator=(const ListGraph &oth)" << std::endl;
    list.clear();
    list.resize(oth.list.size());
    for (int i = 0; i < list.size(); ++i) {
        list[i].resize(oth.list[i].size());
        for (int j = 0; j < oth.list[i].size(); ++j){
            list[i][j]=oth.list[i][j];
        }
    }
    return *this;
}

ListGraph& ListGraph::operator=(const MatrixGraph &oth) {
    std::cout << "ListGraph& ListGraph::operator=(const MatrixGraph &oth)" << std::endl;
    list.clear();
    list.resize(oth.matrix.size());
    for (int i = 0; i < list.size(); ++i) {
        for (int j = 0; j < oth.matrix[i].size(); ++j){
            if (oth.matrix[i][j]) list[i].emplace_back(j);
        }
    }
    return *this;
}

ListGraph::ListGraph(IGraph* oth) {
    std::cout << "ListGraph::ListGraph(IGraph* oth)" ;
    if(auto *ms = dynamic_cast<MatrixGraph*>(oth); ms != nullptr){
        std::cout << " IGraph *oth определен как матрица" << std::endl;
        *this = *ms;
    } else if (auto ls = dynamic_cast<ListGraph*>(oth); ls != nullptr){
        std::cout << " IGraph *oth определен как список" << std::endl;
        *this = *ls;
    }
}

void ListGraph::AddEdge(int from, int to) {
    if(from == to) {
        std::cerr << "Error. Edge not created" << std::endl;
        return;
    }
    if(from > list.size()) {
        list.resize(from);
    }
    list[from].push_back(to);
}

int ListGraph::VerticesCount() {
    int countVertices = 0;
    for(int i = 0; i < list.size(); ++i) {
        for(int j = 0; j < list[i].size(); ++j){
            if( list[i][j] != i ) {
                for (int s = 0; s < list[list[i][j]].size(); ++s) {
                    if (list[list[i][j]][s] != i) countVertices += list[i].size();
                }
            }
        }
    }
    std::cout << "int ListGraph::VerticesCount()" << std::endl;
    return countVertices;
}

void ListGraph::GetNextVertices(int vertex, std::vector<int> &vertices) {
    int sz = list[vertex].size();
    for(int i = 0; i < sz; ++i){
        vertices.push_back(list[vertex][i]);
    }
}

void ListGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) {
    int sz = list.size();
    for(int i = 0; i < sz; ++i){
        for (int j = 0; j < list[i].size(); ++j){
            if(list[i][j] == vertex) vertices.push_back(i);
        }
    }
}








