#include "../include/Execution.h"

Execution::Execution(double fillPrice, int fillQuantity)
  : fillPrice_(fillPrice), fillQuantity_(fillQuantity)
  { }

double Execution::getFillPrice() const
{
  return fillPrice_;
}

int Execution::getFillQuantity() const
{
  return fillQuantity_;
}