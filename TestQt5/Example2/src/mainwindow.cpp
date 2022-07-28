#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle("Example 2 - MainWindow");
    setMinimumSize(400, 400);
    resize(600, 600);

    m_label = new QLabel("Cool text");
    setCentralWidget(m_label);
    m_label->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete m_label;
}