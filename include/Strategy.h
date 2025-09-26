#pragma once

#include <memory>
#include "Order.h"
#include "Bar.h"
#include "Portfolio.h"

class Strategy
{
public:
  virtual ~Strategy() = default;
  virtual std::unique_ptr<Order> generateSignal(const Bar& bar) = 0;
  virtual void setPortfolio(Portfolio* portfolio) = 0;
};