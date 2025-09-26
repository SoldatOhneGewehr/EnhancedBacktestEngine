#pragma once
#include "Strategy.h"
#include "Bar.h"
#include <deque>

class DoubleMovingAverageStrategy : public Strategy {
    std::deque<double> shortWindow_;
    std::deque<double> longWindow_;
    size_t shortPeriod_;
    size_t longPeriod_;
    Portfolio* portfolio_;

public:
    DoubleMovingAverageStrategy(size_t shortPeriod, size_t longPeriod);

    std::unique_ptr<Order> generateSignal(const Bar& bar) override;
    void setPortfolio(Portfolio* portfolio) override;

private:
  double CalculateSMA(const std::deque<double>& window, size_t period_);
};
