#pragma once
#include "Edge.h"
#include <vector>
#include <unordered_map>

class Graph
{
public:
	Graph();
	void constructGraph(const std::vector<std::vector<Node*>>& matrix); //constructs graph from matrix from file
	std::unordered_map<Node*, std::vector<Edge*>> getGraph();
	Edge* minimumWeightEdge(Node* node);

private:
	std::unordered_map<Node*, std::vector<Edge*>> m_graph;
	Edge* edgeAlreadyExists(Node* firstNode, Node* secondNode);
};

