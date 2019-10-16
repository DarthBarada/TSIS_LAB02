#pragma once
#include "Addon.hpp"

class RandomSearch
  {
    std::pair <double,double> interval;

    double e;
    double amount_N;

    Addon unimodal;
    Addon multimodal;

    std::vector <std::vector<double>> N;
public:
    RandomSearch(const double,const double);
    double Value_N(double,double);

    // Функция инициализации N (как в практической части методички)
    void initialize_N();

    void initialize_N(double,double);

    void test();
    void pass(double(*)(double));
  };
