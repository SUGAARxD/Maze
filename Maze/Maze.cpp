#include "Maze.h"

Maze::Maze()
{
    std::ifstream fin("maze.in");
    std::string line;
    m_matrix.resize(1);
    for (uint32_t index = 0; std::getline(fin, line); /* EMPTY */)
    {
        for (char number : line)
        {
            if (number != ' ')
            {
                if (number != '0')
                {
                    m_matrix[index].emplace_back(new Node(std::to_string(number - '0'), Qt::white, m_matrix[index].size(), index));
                    if (m_matrix[index][m_matrix[index].size() - 1]->getLabel() == "2")
                    {
                        m_start = m_matrix[index][m_matrix[index].size() - 1];
                        m_start->setColor("#cf3609");
                    }
                    if (m_matrix[index][m_matrix[index].size() - 1]->getLabel() == "3")
                    {
                        m_finish = m_matrix[index][m_matrix[index].size() - 1];
                        m_finish->setColor("#0cb810");
                    }
                }
                else
                    m_matrix[index].push_back(nullptr);
            }
        }
        index++;
        m_matrix.resize(index + 1);
    }
    m_matrix.resize(m_matrix.size() - 1);
    fin.close();
}

Maze::~Maze()
{}

std::vector<Node*> Maze::mazeSolutionPath()
{
    std::vector<Node*> path;
    std::unordered_set<Node*> verified;

    Graph graph;
    graph.constructGraph(m_matrix);
    std::unordered_map<Node*, std::vector<Edge*>> graphComponents = graph.getGraph();
    DFS(m_start, verified, graphComponents, 1);
    Node* currentNode = m_finish;
    path.push_back(m_finish);
    while (currentNode != m_start && currentNode != nullptr)
    {
        currentNode = graph.minimumWeightEdge(currentNode)->getNeighbor(currentNode);
        path.push_back(currentNode);
    }
    return path;
}

std::vector<std::vector<Node*>> Maze::getMaze()
{
    return m_matrix;
}

void Maze::DFS(Node* node, std::unordered_set<Node*>& verified, std::unordered_map<Node*, std::vector<Edge*>>& graphComponents, uint32_t distance)
{
    if (verified.find(node) == verified.end())
    {
        verified.insert(node);
        for (Edge* edge : graphComponents[node])
            if (verified.find(edge->getNeighbor(node)) == verified.end())
            {
                edge->setWeight(distance);
                DFS(edge->getNeighbor(node), verified, graphComponents, distance + 1);
            }
    }
}
