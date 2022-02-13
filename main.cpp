#include "IGraph.h"

int main() {

    setlocale (LC_ALL, "Russian");
    std::cout << "*** IGraph ***" << std::endl;
    IGraph *a = new MatrixGraph();

    int n;
    std::cout << "���������� ������� ��������� ������� ���������� ������: \n";
    std::cin >> n ;
    int from = 0;
    for (int i = 0; i < n; ++i){
        std::cout <<"-> ";
        int to;
        std::cin >> from >> to;
        a->AddEdge(from, to);
    }
    IGraph *c = new ListGraph(a);
    IGraph *b = new MatrixGraph;
    *b = *c;
    int x,y,z;
    x = a->VerticesCount();
    y = c->VerticesCount();
    z = b->VerticesCount();
    std::cout << "���������� ������ � ������ �� ����������� = " << x << std::endl;
    std::cout << "���������� ������ � ������ ����� ����������� ������� � ������ = " << y << std::endl;

    std::cout << "���������� ������ � ������ ����� ����������� ������ � ������� = " << z << std::endl;
    return 0;
}
