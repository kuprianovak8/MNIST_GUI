#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "neuralnetwork.h"
#include <QMainWindow>
#include <QLabel>

// создаем элементы главного окна
// 1 - Текст

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    NeuralNetwork *m_neural_network;

    //  элементы интерфейса
    QLabel m_result_label; // решение нейросети

};
#endif // MAINWINDOW_H
