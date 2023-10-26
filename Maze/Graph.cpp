#include "Graph.h"

Graph::Graph()
{
}

void Graph::constructGraph(const std::vector<std::vector<Node*>>& matrix)
{
	uint32_t indexIMax = matrix.size() - 1;
	uint32_t indexJMax = matrix[0].size() - 1;
	for (uint32_t indexI = 0; indexI < matrix.size(); indexI++)
		for (uint32_t indexJ = 0; indexJ < matrix[indexI].size(); indexJ++)
			if (matrix[indexI][indexJ] != nullptr)
			{
				if (indexI != 0)
				{
					if (matrix[indexI - 1][indexJ] != nullptr)
						if (edgeAlreadyExists(matrix[indexI][indexJ], matrix[indexI - 1][indexJ]) != nullptr)
							m_graph[matrix[indexI][indexJ]].push_back(edgeAlreadyExists(matrix[indexI][indexJ], matrix[indexI - 1][indexJ]));
						else
							m_graph[matrix[indexI][indexJ]].emplace_back(new Edge(matrix[indexI][indexJ], matrix[indexI - 1][indexJ], 0));
				}
				if (indexJ < indexJMax)
				{
					if (matrix[indexI][indexJ + 1] != nullptr)
						if (edgeAlreadyExists(matrix[indexI][indexJ], matrix[indexI][indexJ + 1]) != nullptr)
							m_graph[matrix[indexI][indexJ]].push_back(edgeAlreadyExists(matrix[indexI][indexJ], matrix[indexI][indexJ + 1]));
						else
							m_graph[matrix[indexI][indexJ]].emplace_back(new Edge(matrix[indexI][indexJ], matrix[indexI][indexJ + 1], 0));
				}
				if (indexI < indexIMax)
				{
					if (matrix[indexI + 1][indexJ] != nullptr)
						if (edgeAlreadyExists(matrix[indexI][indexJ], matrix[indexI + 1][indexJ]) != nullptr)
							m_graph[matrix[indexI][indexJ]].push_back(edgeAlreadyExists(matrix[indexI][indexJ], matrix[indexI + 1][indexJ]));
						else
							m_graph[matrix[indexI][indexJ]].emplace_back(new Edge(matrix[indexI][indexJ], matrix[indexI + 1][indexJ], 0));
				}
				if (indexJ != 0)
				{
					if (matrix[indexI][indexJ - 1] != nullptr)
						if (edgeAlreadyExists(matrix[indexI][indexJ], matrix[indexI][indexJ - 1]) != nullptr)
							m_graph[matrix[indexI][indexJ]].push_back(edgeAlreadyExists(matrix[indexI][indexJ], matrix[indexI][indexJ - 1]));
						else
							m_graph[matrix[indexI][indexJ]].emplace_back(new Edge(matrix[indexI][indexJ], matrix[indexI][indexJ - 1], 0));
				}
			}
}

std::unordered_map<Node*, std::vector<Edge*>> Graph::getGraph()
{
	return m_graph;
}

Edge* Graph::minimumWeightEdge(Node* node)
{
	Edge* minimumWeightEdge = nullptr;
	uint32_t minWeight = 0;
	for (Edge* edge : m_graph[node])
	{
		if (edge->getWeight() < minWeight || minWeight == 0)
		{
			minWeight = edge->getWeight();
			minimumWeightEdge = edge;
		}
	}
	return minimumWeightEdge;
}

Edge* Graph::edgeAlreadyExists(Node* firstNode, Node* secondNode)
{
	for (Edge* edge : m_graph[secondNode])
		if (edge->getSecondNode() == firstNode)
			return edge;
	return nullptr;
}
