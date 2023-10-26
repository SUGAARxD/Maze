#include "Node.h"

Node::Node() {}

Node::Node(std::string label, QColor color, uint32_t x, uint32_t y) : m_label(label), m_color(color), m_coordinates(QPoint(x, y)) {}

void Node::setLabel(std::string label)
{
	m_label = label;
}

std::string Node::getLabel() const
{
	return m_label;
}

void Node::setCoordinates(uint32_t x, uint32_t y)
{
	m_coordinates.setX(x);
	m_coordinates.setY(y);
}

const uint32_t Node::getX()
{
	return m_coordinates.x();
}
const uint32_t Node::getY()
{
	return m_coordinates.y();
}

void Node::setColor(QColor color)
{
	m_color = color;
}

const QColor Node::getColor()
{
	return m_color;
}
