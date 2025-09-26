#pragma once
#include "Strategy.h"
#include "Bar.h"
#include "Portfolio.h"
#include <deque>

class MovingAverageStrategy : public Strategy {
    std::deque<double> window_;
    size_t period_;
    Portfolio* portfolio_;

public:
    MovingAverageStrategy(size_t period);
    void setPortfolio(Portfolio* portfolio) override;
    std::unique_ptr<Order> generateSignal(const Bar& bar) override;
};

