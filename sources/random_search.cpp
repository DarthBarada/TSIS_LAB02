#include "random_search.hpp"
#include <random>

void print_V(std::vector <std::vector<double>> vec);

RandomSearch::RandomSearch(const double a,const double b)
  {
    interval.first = a; interval.second = b;

    initialize_N();
    print_V(N);
  }

double RandomSearch::Value_N(double Value_P,double Value_q)
  {
    return double(log(1.0 - Value_P)/log(1.0 - Value_q));
  }

void RandomSearch::initialize_N()
  {
    std::vector<double> temp;

    for(size_t index = 0   ;index < P.size()  ;index++)
      {
        for(size_t jump = 0;jump < q.size();jump++)
          {
            temp.push_back(round(Value_N(P.at(index),q.at(jump))));
          }
        N.push_back(temp);

        temp.clear();
      }
  }

  void RandomSearch::initialize_N(double delta, double Value_P)
    {
      amount_N = (log(1-Value_P)/log(1.0-(2*delta)/(interval.second-interval.first)));
    }


void RandomSearch::pass()
  {
    /// ---------- Инициализация генератора случайных цифр с плавающей точкой в промежутке ----------
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(interval.first,interval.second);
    ///----------------------------------------------------------------------------------------------

    std::pair <double,double> best_point{0.0,9223372036854755807.0}; // 9 223 372 036 854 755 807.0 <- максимальное значение double
    std::vector<std::pair<double,double>> temp_vector;
    std::pair <double,double> temp_point;

    std::cout<<"\n";
    // Мы уже высчитали N, но если говрить о полноценной программе, то там N считается во время цикла (наверное)
    for(size_t index = 0;index < P.size();index++)
      {
        for(size_t jump = 0;jump < q.size();jump++)
          {
            for (size_t count = 0;count < round(Value_N(P.at(index),q.at(jump)));count++) // Пока count < N мы генерируем новое
              {                                                                                             // рандомное число
                temp_point.first = dis(gen);
                temp_point.second = F(temp_point.first);
                if (temp_point.second < best_point.second)
                  {
                    best_point = temp_point;
                  }
              }
              temp_vector.push_back(best_point);
          }
          unimodal.get_matrix()->push_back(temp_vector);
          temp_vector.clear();
      }
      unimodal.print();
  }

void print_V(std::vector <std::vector<double>> vec)
  {
    ///---------------------------
    std::cout<<std::endl
    <<"+-------+"<<"+--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+\n";
    std::cout<<std::left<<"|"<<std::setw(7)<<"  q\\P"<<"||";
    for (auto index = P.begin();index!=P.end();index++)
      {
          std::cout<<std::left<<std::setprecision(2)<<"  "<<std::setw(6)<<*(index)<<"|";
      }
    std::cout<<std::endl
    <<"+-------+"<<"+--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+\n";
    ///-------------------------

    for (size_t index = 0;index < q.size();index++)
      {
        std::cout<<std::left<<std::setprecision(4)<<"|"<<std::setw(7)<<q.at(index)<<"||";
        for (size_t joy = 0;joy<P.size();joy++)
          {
            std::cout<<std::left<<std::setprecision(6)<<" "<<std::setw(7)<<vec.at(joy).at(index)<<"|";
          }
          std::cout<<std::endl;
      }
    std::cout<<"+-------+"<<"+--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+\n";
  }
