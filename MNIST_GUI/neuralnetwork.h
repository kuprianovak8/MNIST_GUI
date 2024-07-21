#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <QObject>
#include <QVector>
#include <QRandomGenerator>
#include <QDebug>

class NeuralNetwork : public QObject
{
    Q_OBJECT
public:
    NeuralNetwork(int inp_num, int hidden_num, int out_num); // входные нейроны, скрытые и выходные
private:
    int m_inp_size; // количество входных нейронов
    int m_hidden_size; // количество скрытых нейронов
    int m_out_size; // количество выходных нейронов

    // хранение нейронов
//    QVector<double> m_input_neuron; // входные
    QVector<double> m_hidden_neuron; // скрытые
    QVector<double> m_out_neuron; // выходные

    // веса, относятся сразу к двум слоям
    QVector<QVector<double>> m_inp_hidden_weight; // между вх и скрытым слоями
    QVector<QVector<double>> m_hidden_out_weight; // между скр и вых слоями

    // смещения
    QVector<double> m_hidden_biases; // смещения скрытых нейронов
    QVector<double> m_out_biases; // смещения выходных нейронов

    // функция активации – функция релу
    double Relu (double x);

    QRandomGenerator m_random_generator;

    // функция прямого распространения
    void feedForward(QVector<double> input);

};

#endif // NEURALNETWORK_H
