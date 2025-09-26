#include <stdexcept>
#include "../include/Instrument.h"

Instrument::Instrument(const std::string& symbol)
  : symbol_(symbol)
  { }

void Instrument::LoadPrices(const std::string& filename)
{
  // Placeholder for loading prices from a file
  // In a real implementation, you would read the file and populate Bars_
  //Bars_.emplace_back(Bar{1.0, 1.5, 0.5, 1.2}); // Example Bar
}

double Instrument::getPriceAt(size_t index) const
{
  if (index < Bars_.size())
    return Bars_[index].close;
  throw std::out_of_range("Index out of range");
}
