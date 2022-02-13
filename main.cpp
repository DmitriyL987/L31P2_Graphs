#include "IGraph.h"

int main() {

    setlocale (LC_ALL, "Russian");
    std::cout << "*** IGraph ***" << std::endl;
    IGraph *a = new MatrixGraph();

    int n;
    std::cout << "«аполнение матрицы смежности введите количество граней: \n";
    std::cin >> n ;
    int from = 0;
    for (int i = 0; i < n; ++i){
        std::cout <<"-> ";
        int to;
        std::cin >> from >> to;
        a->AddEdge(from, to);
    }

    IGraph *c = new ListGraph(a);
    IGraph *b = new MatrixGraph(c);

    int x,y,z;
    x = a->VerticesCount();
    y = c->VerticesCount();
    z = b->VerticesCount();

    std::cout << " оличество вершин в списке до копировани€ = " << x << std::endl;
    std::cout << " оличество вершин в списке после копировани€ матрицы в список = " << y << std::endl;

    std::cout << " оличество вершин в списке после копировани€ списка в матрицу = " << z << std::endl;
    auto s = dynamic_cast<MatrixGraph*>(a);
    auto k = dynamic_cast<MatrixGraph*>(a);
    auto l = dynamic_cast<ListGraph*>(c);
    for (int i =0; i < s->matrix.size(); ++i) {
        //  матрица а
        for (int j = 0; j < s->matrix[i].size(); ++j) {
            std::cout << s->matrix[i][j] << "  ";
        }
        std::cout << "\t";
        //  матрица b
        for (int j = 0; j < k->matrix[i].size(); ++j) {
            std::cout << k->matrix[i][j] << "  ";
        }
        std::cout << "\t";
        //  список c
        for (int j = 0; j < l->list[i].size(); ++j)
                std::cout << l->list[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
