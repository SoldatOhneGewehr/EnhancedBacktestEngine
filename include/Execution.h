#pragma once

class Execution
{
  double fillPrice_;
  int fillQuantity_;

public:
  Execution(double fillPrice, int FillQuantity);
  double getFillPrice() const;
  int getFillQuantity() const;
};