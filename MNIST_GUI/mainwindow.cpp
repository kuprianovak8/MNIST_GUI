#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_neural_network = new NeuralNetwork(784, 100, 10);

    m_result_label = *new QLabel("-", this);

}

MainWindow::~MainWindow()
{
}

