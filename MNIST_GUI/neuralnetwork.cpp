#include "neuralnetwork.h"

// задача: заполнить рандомными значениями массивы весов и смещений

NeuralNetwork::NeuralNetwork(int inp_num, int hidden_num, int out_num)
{
    m_inp_size = inp_num;
    m_hidden_size = hidden_num;
    m_out_size = out_num;

    m_hidden_neuron.resize(hidden_num);
    m_out_neuron.resize(out_num);

    // заполнение весов между входным и скрытым слоем

    // устанавливаем размер вектора смещений
    m_inp_hidden_weight.resize(m_inp_size); // хранит столько векторов сколько входных нейронов
    for(int i = 0; i < m_inp_size; i++) // добраться по этому вектору до весов
    {
        m_inp_hidden_weight[i].resize(m_hidden_size); // устанавливаем размер по количеству скрытых нейронов
        for(int j = 0; j < m_hidden_size; j++) // цикл для каждого элемента вектора с числами
        {
            m_inp_hidden_weight[i][j] = 0.005 * (m_random_generator.generateDouble() * 2 - 1); // * 2 - 1 для отриц чисел
        }
    }

    // заполнение весов между скрытым и выходным слоем
    m_hidden_out_weight.resize(m_hidden_size);
    for(int i = 0; i < m_hidden_size; i++)
    {
        m_hidden_out_weight[i].resize(m_out_size);
        for(int j = 0; j < m_out_size; j++)
        {
            m_hidden_out_weight[i][j] = 0.005 * (m_random_generator.generateDouble() * 2 - 1);
        }
    }

    // заполнение смещений скрытого слоя
    m_hidden_biases.resize(m_hidden_size);
    for(int i = 0; i < m_hidden_size; i++)
    {
        m_hidden_biases[i] = 0.005 * (m_random_generator.generateDouble() * 2 - 1);
    }

    // заполнение смещений выходного слоя
    m_out_biases.resize(m_out_size);
    for(int i = 0; i < m_out_size; i++)
    {
        m_out_biases[i] = 0.005 * (m_random_generator.generateDouble() * 2 - 1);
        qDebug() << m_out_biases[i];
    }

}

double NeuralNetwork::Relu(double x)
{
    if(x > 0)
        return x;
    else
        return 0;
}

void NeuralNetwork::feedForward(QVector<double> input)
{
    // рассчитать значения скрытых нейронов
    for(int i = 0; i < m_hidden_size; i++)
    {
        double activation = m_hidden_biases[i];
        for(int j = 0; j < m_inp_size; i++) // считаем взвешенную сумму
        {
            activation += input[j] * m_inp_hidden_weight[i][j]; // произведение входного нейрона на вес
        }
        // рассчитываем выходные значения с помощью функции релу
        m_hidden_neuron[i] = Relu(activation); // полученные значения взвешенной суммы передаем в функцию активации
    }

    // рассчитать значения выходных нейронов
    for(int i = 0; i < m_out_size; i++)
    {
        double activation = m_out_biases[i];
        for(int j = 0; j < m_hidden_size; i++)
        {
            activation += input[j] * m_hidden_out_weight[i][j];
        }
        m_out_neuron[i] = Relu(activation);
    }

}












