#include "Edge.h"

Edge::Edge() {}

Edge::Edge(Node* firstNode, Node* secondNode, uint32_t weight) : m_firstNode(firstNode), m_secondNode(secondNode), m_weight(weight) {}

void Edge::setWeight(uint32_t weight)
{
	m_weight = weight;
}

uint32_t Edge::getWeight()
{
	return m_weight;
}

void Edge::setEdge(Node* firstNode, Node* secondNode)
{
	m_firstNode = firstNode;
	m_secondNode = secondNode;
}

Node* Edge::getFirstNode()
{
	return m_firstNode;
}

Node* Edge::getSecondNode()
{
	return m_secondNode;
}

Node* Edge::getNeighbor(Node* node)
{
	if (m_firstNode == node)
		return m_secondNode;
	return m_firstNode;
}
