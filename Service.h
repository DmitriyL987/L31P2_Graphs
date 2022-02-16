#pragma once
#include <iostream>
#include "IGraph.h"

void helper();
void CreateGraph(std::vector <IGraph*> &igraph);
void CreateCopy(std::vector <IGraph*> &igraph);
void addEdges(std::vector <IGraph*> &igraph);
void ShowGraph(std::vector <IGraph*> &igraph);
void CountV(std::vector <IGraph*> &igraph);
void Prev(std::vector <IGraph*> &igraph);
void Next(std::vector <IGraph*> &igraph);
void CopyGraph(std::vector<IGraph*>&igraph);