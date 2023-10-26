#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UIClass.h"
#include "Maze.h"
#include <QPushButton>
#include <QTimer>

class UIClass : public QMainWindow
{
    Q_OBJECT

public:
    UIClass(QWidget* parent = nullptr);
    ~UIClass();

protected:
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);

private slots:
    void drawPathRectangle();
    void toggleColoringProcess();

private:
    Ui::UIClassClass ui;
    std::vector<std::vector<Node*>> mazeComponents;
    std::vector<Node*> path;
    uint32_t mazeComponentsPerLine;
    uint32_t mazeComponentsPerColumn;
    QTimer* drawTimer;
    int32_t currentPathIndex;
    QPushButton* startButton;
    bool coloringInProgress;
};