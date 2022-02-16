#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <functional>
// по условию задачи граф ориентированный
class MatrixGraph;
class ListGraph;

class IGraph {
    std::string name;
  public:
    virtual  ~IGraph() {};


    IGraph() {name = "some_graph";}

    IGraph(IGraph *oth);

    virtual std::string& getName(){return name;}
    // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual void AddEdge(int from, int to) = 0;
    // Метод должен считать текущее количество вершин
    virtual int VerticesCount() = 0;
    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) = 0;
    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) = 0;
};
//-----------------------------------------------------
class MatrixGraph: public IGraph{
  public:
    MatrixGraph(){};
    MatrixGraph(IGraph *oth);
    void AddEdge(int from, int to) override;
    int VerticesCount() override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) override;
    MatrixGraph& operator=(const MatrixGraph& oth);
    MatrixGraph& operator=(const ListGraph& oth);
    MatrixGraph* operator=(IGraph* oth);

    std::vector<std::vector<bool>> matrix;
};
//-------------------------------------------------------
class ListGraph : public  IGraph{
  public:
    ListGraph(){};
    ListGraph(IGraph *oth);
    void AddEdge(int from, int to) override;
    int VerticesCount() override;
    void GetNextVertices(int vertex, std::vector<int> &vertices) override;
    void GetPrevVertices(int vertex, std::vector<int> &vertices) override;
    ListGraph& operator=(const MatrixGraph& oth);
    ListGraph& operator=(const ListGraph& oth);
    ListGraph* operator=(IGraph* oth);

    std::vector<std::vector<int>> list;
};