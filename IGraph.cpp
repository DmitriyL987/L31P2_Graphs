#include "IGraph.h"
//----------------- MatrixGraph -------------

MatrixGraph::MatrixGraph(IGraph *oth) { //  можно попробовать через =
    if(auto *ms = dynamic_cast<MatrixGraph*>(oth); ms != nullptr){
        matrix.resize(ms->matrix.size());
        for(int i = 0; i < matrix.size(); ++i){
            matrix[i].resize(ms->matrix[i].size());
            for (int j = 0; j < ms->matrix.size(); ++j){
                matrix[i][j] = ms->matrix[i][j];
            }
        }
    } else if (auto ls = dynamic_cast<ListGraph*>(oth); ls != nullptr){
        matrix.resize((ls->list.size()));
        for(int i = 0; i < matrix.size(); ++i){
            matrix[i].resize(ls->list.size());
            for (int j = 0; j < ls->list.size(); ++j){
                matrix[i][ls->list[i][j]] = true;
            }
        }
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    if(from == to) {
        std::cerr << "Error. Edge not created" << std::endl;
        return;
    }
    int a = std::max(from,to);
    if (a > matrix.size()) {
        matrix.resize(a);
        for (int i = 0; i < a; ++i) matrix[i].resize(a);
    }
    matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() {
    int countVertices = 0;
    int matrixsize = matrix.size();
    for (int i = 0; i < matrixsize; ++i){
        for(int j = 0; j < matrixsize; ++j){
            if(i == j) continue;
            if (matrix[i][j]) ++countVertices;
        }
    }
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

ListGraph::ListGraph(IGraph* oth) {
    if(auto *ms = dynamic_cast<MatrixGraph*>(oth); ms != nullptr){

    } else if (auto ls = dynamic_cast<ListGraph*>(oth); ls != nullptr){

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
    for(int i = 0; i < list.size(); ++i) countVertices += list[i].size();
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




