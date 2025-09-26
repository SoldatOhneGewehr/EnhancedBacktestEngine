#pragma once

#include <string>
#include <vector>
#include "Bar.h"

class Instrument
{
public:
  Instrument(const std::string& symbol);
  void LoadPrices(const std::string& filename);
  double getPriceAt(size_t index) const;
private:
  std::string symbol_;
  std::vector<Bar> Bars_;
};