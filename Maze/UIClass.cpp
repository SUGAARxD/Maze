#include "UIClass.h"

UIClass::UIClass(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

UIClass::~UIClass()
{}

void UIClass::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen pen(Qt::black, 5);

    QRect widgetRect = this->rect();
    uint32_t widgetWidth = widgetRect.width();
    uint32_t widgetHeight = widgetRect.height() * 0.95;


    Maze maze;
    std::vector<std::vector<Node*>> mazeComponents = maze.getMaze();

    uint32_t mazeComponentsPerLine = mazeComponents[0].size();
    uint32_t mazeComponentsPerColumn = mazeComponents.size();

    uint32_t rectangleWidth = widgetWidth / mazeComponentsPerLine;
    uint32_t rectangleHeight = widgetHeight / mazeComponentsPerColumn;

    uint32_t rectangleX = 0;
    uint32_t rectangleY = widgetRect.height() * 0.05;

    painter.setBrush(QBrush("#bdf2e8"));
    painter.drawRect(0, 0, rectangleWidth * mazeComponentsPerLine, rectangleY);

    for (uint32_t indexI = 0; indexI < mazeComponentsPerColumn; indexI++)
    {
        rectangleX = 0;
        for (uint32_t indexJ = 0; indexJ < mazeComponentsPerLine; indexJ++)
        {
            if (mazeComponents[indexI][indexJ] == nullptr)
            {
                painter.setBrush(QBrush("#959190"));
                painter.drawRect(rectangleX, rectangleY, rectangleWidth, rectangleHeight);
            }
            else
            {
                painter.setBrush(QBrush(mazeComponents[indexI][indexJ]->getColor()));
                painter.drawRect(rectangleX, rectangleY, rectangleWidth, rectangleHeight);
            }
            rectangleX += rectangleWidth;
        }
        rectangleY += rectangleHeight;
    }
    rectangleY = widgetRect.height() * 0.05;
    std::vector<Node*> path = maze.mazeSolutionPath();
    for (int32_t index = path.size() - 1; index >= 0; --index)
    {
        painter.setBrush(QBrush("#b5e5ec"));
        painter.drawRect(path[index]->getX() * rectangleWidth, path[index]->getY() * rectangleHeight + rectangleY, rectangleWidth, rectangleHeight);
    }
}