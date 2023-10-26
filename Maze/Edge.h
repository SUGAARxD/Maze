#pragma once
#include "Node.h"

class Edge
{
public:
	Edge();
	Edge(Node* firstNode, Node* secondNode, uint32_t weight);
	void setWeight(uint32_t weight);
	uint32_t getWeight();
	void setEdge(Node* firstNode, Node* secondNode);
	Node* getFirstNode();
	Node* getSecondNode();
	Node* getNeighbor(Node* node);

private:
	Node* m_firstNode, * m_secondNode;
	uint32_t m_weight;
};

