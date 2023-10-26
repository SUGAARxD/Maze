#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_UIClass.h"
#include "Maze.h"

class UIClass : public QMainWindow
{
    Q_OBJECT

public:
    UIClass(QWidget* parent = nullptr);
    ~UIClass();

protected:
    void paintEvent(QPaintEvent* event);

private:
    Ui::UIClassClass ui;
};
