#pragma once

#include <iostream>
#include <iomanip>
#include <vector>

// Вектор P - вероятностей того, что найденная точка минимума находится в интервале неопределённости
const std::vector <double> P {0.90,0.91,0.92,0.93,0.94,0.95,0.96,0.97,0.98,0.99};
// Вектор q - вероятностей попадания в интервал неопределённости для отдельно взятой точки
const std::vector <double> q {0.005,0.01,0.015,0.02,0.025,0.03,0.035,0.04,0.045,0.05,0.055,0.06,0.065,0.07,0.075,0.08,0.085,0.09,0.095,0.1};

class Addon         // Класс для результата
  {
      // Матрица результатов, столбцы - P, строки - q
    std::vector <std::vector<std::pair<double,double>>> matrix;

    public:
      virtual ~Addon() = default;

      std::vector <std::vector<std::pair<double,double>>>* get_matrix();

      void print(bool);
      const size_t size();
  };
