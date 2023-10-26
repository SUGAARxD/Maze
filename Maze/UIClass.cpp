#include "UIClass.h"

UIClass::UIClass(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    Maze maze;
    mazeComponents = maze.getMaze();
    mazeComponentsPerLine = mazeComponents[0].size();
    mazeComponentsPerColumn = mazeComponents.size();
    path = maze.mazeSolutionPath();
    currentPathIndex = path.size() - 1;
    coloringInProgress = false; 

    drawTimer = new QTimer(this);
    drawTimer->setInterval(800);

    connect(drawTimer, &QTimer::timeout, this, &UIClass::drawPathRectangle);

    startButton = new QPushButton("Solve", this);
    startButton->setFixedSize(this->rect().width() / mazeComponentsPerLine, this->rect().height() * 0.07 + 1);
    startButton->move((mazeComponentsPerLine - 1) * this->rect().width() / mazeComponentsPerLine, 0);

    connect(startButton, &QPushButton::clicked, this, &UIClass::toggleColoringProcess);

}

UIClass::~UIClass()
{}

void UIClass::drawPathRectangle()
{
    if (currentPathIndex >= 0)
    {
        path[currentPathIndex]->setColor(QColor("#b5e5ec"));
    }
    if (currentPathIndex < 0)
    {
        drawTimer->stop();
        startButton->setText("Solved!");
        startButton->setText("Solved!");
        for (int32_t index = path.size() - 1; index >= 0; --index)
            path[index]->setColor(QColor("#01ff71"));
    }
    --currentPathIndex;
    update();
}

void UIClass::toggleColoringProcess()
{
    if (!coloringInProgress)
    {
        drawTimer->start();
        coloringInProgress = true;
        startButton->setText("Solving");
    }
}

void UIClass::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    QPen pen(Qt::black, 5);

    QRect widgetRect = this->rect();
    uint32_t widgetWidth = widgetRect.width();
    uint32_t widgetHeight = widgetRect.height() * 0.93;

    uint32_t rectangleWidth = widgetWidth / mazeComponentsPerLine;
    uint32_t rectangleHeight = widgetHeight / mazeComponentsPerColumn;

    uint32_t rectangleX = 0;
    uint32_t rectangleY = widgetRect.height() * 0.07;

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
}

void UIClass::resizeEvent(QResizeEvent* event)
{
    startButton->setFixedSize(this->rect().width() / mazeComponentsPerLine, this->rect().height() * 0.07 + 1);
    startButton->move((mazeComponentsPerLine - 1) * this->rect().width() / mazeComponentsPerLine, 0);
    QMainWindow::resizeEvent(event);
}