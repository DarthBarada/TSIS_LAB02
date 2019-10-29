#include <iostream>
#include <iomanip>

#include "Addon.hpp"

void Addon::print()
  {
    ///---------------------------
    std::cout<<std::left<<std::showpos<<std::fixed<<std::endl
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
            std::cout<<std::left<<std::setprecision(4)<<std::setw(8)<<matrix.at(joy).at(index).second<<"|";
          }
          std::cout<<std::endl;
      }
  std::cout<<"+-------+"<<"+--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+"<<"--------+\n";
  }

std::vector <std::vector<std::pair<double,double>>>* Addon::get_matrix()
    {
      return &matrix;
    }

const size_t Addon::size()
  {
    return matrix.size();
  }
