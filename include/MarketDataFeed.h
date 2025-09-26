#pragma once
#include "Bar.h"

class MarketDataFeed 
{
public:
  virtual ~MarketDataFeed() = default;
  virtual bool hasNext() const = 0;
  virtual Bar getNextBar() = 0;
};