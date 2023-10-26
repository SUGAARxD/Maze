#pragma once
#include <QPainter>
#include <string>

class Node
{
public:
	Node();
	Node(std::string label, QColor color, uint32_t x, uint32_t y);
	void setLabel(std::string label);
	std::string getLabel() const;
	void setCoordinates(uint32_t x, uint32_t y);
	const uint32_t getX();
	const uint32_t getY();
	void setColor(QColor color);
	const QColor getColor();

private:
	std::string m_label;
	QPoint m_coordinates;
	QColor m_color;
};

