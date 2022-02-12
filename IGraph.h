#pragma once
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

// по условию задачи граф ориентированный
class MatrixGraph;
class ListGraph;

class IGraph {
  public:
    virtual ~IGraph() {}

    IGraph() {};

    IGraph(IGraph *oth);;
    // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual void AddEdge(int from, int to) = 0;
    // Метод должен считать текущее количество вершин
    virtual int VerticesCount() = 0;
    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) = 0;
    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) = 0;
};

class MatrixGraph: public IGraph{


  public:
    MatrixGraph(IGraph *oth);
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() override;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) override;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) override;

    std::vector<std::vector<bool>> matrix;
};

class ListGraph : public  IGraph{
  public:
    ListGraph(IGraph *oth);
    virtual void AddEdge(int from, int to) override;
    virtual int VerticesCount() override;
    virtual void GetNextVertices(int vertex, std::vector<int> &vertices) override;
    virtual void GetPrevVertices(int vertex, std::vector<int> &vertices) override;

    std::vector<std::vector<int>> list;
};