#pragma once
#include "Graph.h"
#include <fstream>
#include <unordered_set>

class Maze
{
public:
	Maze();
	~Maze();
	std::vector<Node*> mazeSolutionPath();
	std::vector<std::vector<Node*>> getMaze();

private:
	std::vector<std::vector<Node*>> m_matrix;
	Node* m_start = nullptr, * m_finish = nullptr;
	void DFS(Node* node, std::unordered_set<Node*>& verified, std::unordered_map<Node*, std::vector<Edge*>>& graphComponents, uint32_t distance);
};

