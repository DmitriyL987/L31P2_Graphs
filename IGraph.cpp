#include "IGraph.h"
//----------------- MatrixGraph -------------

MatrixGraph& MatrixGraph::operator=(const MatrixGraph& oth){
    if(this == &oth) return *this;
    matrix.clear();
    matrix.resize(oth.matrix.size());
    for(int i = 0; i < oth.matrix.size(); ++i){
        matrix[i].resize(oth.matrix[i].size());
        for (int j = 0; j < oth.matrix.size(); ++j){
            matrix[i][j] = oth.matrix[i][j];
        }
    }
    return *this;
}
MatrixGraph& MatrixGraph::operator=(const ListGraph& oth){
    int a = oth.list.size();
    matrix.clear();
    matrix.resize(a);
    for(int i = 0; i < matrix.size(); ++i){
        matrix[i].resize(a);
        for (int j = 0; j < oth.list[i].size(); ++j) {
            matrix[i][oth.list[i][j]] = true;
        }
    }
    return  *this;
}

MatrixGraph::MatrixGraph(IGraph *oth) {
    if(auto *ms = dynamic_cast<MatrixGraph*>(oth); ms != nullptr){
        *this = *ms;
    } else if (auto ls = dynamic_cast<ListGraph*>(oth); ls != nullptr){
        *this = *ls;
    }
}

void MatrixGraph::AddEdge(int from, int to) {
    if(from == to) {
        std::cerr << "Error. Edge not created" << std::endl;
        return;
    }
    int a = std::max(from, to) + 1;

    if (a > matrix.size()) {
        matrix.resize(a);
        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i].resize(a);
        }
    }
    matrix[from][to] = true;
}

int MatrixGraph::VerticesCount() {
    int countVertices = matrix.size();
    for(int i = 0; i < matrix.size(); ++i){
        int v = 0 , h = 0;
        for(int j = 0; j < matrix.size(); ++j) {
            if (matrix[i][j]) {++h; break;}
            if (matrix[j][i]) {++v; break;}
        }
        if (h == 0 && v == 0) --countVertices;
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

MatrixGraph* MatrixGraph::operator=(IGraph *oth) {
    if(auto *ms = dynamic_cast<MatrixGraph*>(oth); ms != nullptr){
        matrix.clear();
        matrix.resize(ms->matrix.size());
        for(int i = 0; i < matrix.size(); ++i){
            matrix[i].resize(ms->matrix[i].size());
            for (int j = 0; j < ms->matrix.size(); ++j){
                matrix[i][j] = ms->matrix[i][j];
            }
        }
    } else if (auto ls = dynamic_cast<ListGraph*>(oth); ls != nullptr){
        int a = ls->list.size();
        matrix.clear();
        matrix.resize(a);
        for(int i = 0; i < matrix.size(); ++i){
            matrix[i].resize(a);
            for (int j = 0; j < ls->list[i].size(); ++j) {
                matrix[i][ls->list[i][j]] = true;
            }
        }
    }
    return this;
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
        *this = *ms;
    } else if (auto ls = dynamic_cast<ListGraph*>(oth); ls != nullptr){
        *this = *ls;
    }
}

void ListGraph::AddEdge(int from, int to) {
    if(from == to) {
        std::cerr << "Error. Edge not created" << std::endl;
        return;
    }
    int a = std::max(from, to) + 1;
    if(a > list.size()) {
        list.resize(a);
    }
    list[from].push_back(to);
}

int ListGraph::VerticesCount(){
    return list.size();
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

ListGraph *ListGraph::operator=(IGraph* oth) {
    if(auto * ms = dynamic_cast<MatrixGraph*>(oth); ms != nullptr){
        list.clear();
        list.resize(ms->matrix.size());
        for (int i = 0; i < list.size(); ++i) {
            for (int j = 0; j < ms->matrix[i].size(); ++j){
                if (ms->matrix[i][j]) list[i].push_back(j);
            }
        }
    }else if(auto * ls = dynamic_cast<ListGraph*>(oth); ls != nullptr){
        list.clear();
        list.resize(ls->list.size());
        for (int i = 0; i < list.size(); ++i) {
            list[i].resize(ls->list[i].size());
            for (int j = 0; j < ls->list[i].size(); ++j){
                list[i][j]=ls->list[i][j];
            }
        }
    }
    return this;
}