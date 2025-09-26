#include "../include/MovingAverageStrategy.h"
#include <iostream>

MovingAverageStrategy::MovingAverageStrategy(size_t period)
: period_(period)
, portfolio_(nullptr)
{ }

void MovingAverageStrategy::setPortfolio(Portfolio* portfolio) {
    portfolio_ = portfolio;
}

std::unique_ptr<Order> MovingAverageStrategy::generateSignal(const Bar& bar) {

    if (!portfolio_) return nullptr; // Portfolio not set
    
    double price = bar.close; // using closing price for now

    window_.push_back(price);
    if (window_.size() > period_) window_.pop_front();

    if (window_.size() < period_) return nullptr;

    double sum = 0.0;
    for (double p : window_) sum += p;
    double avg = sum / period_;

    double portfolioValue = portfolio_->getValue("BTC-USD", price);
    //printf("Portfolio Value: %.2f, Cash: %.2f, Price: %.2f, MA: %.2f, Date: %s\n", portfolioValue, portfolio_->getCash(), price, avg, bar.date.c_str());
    double fraction = 1;
    int qty = static_cast<int>((portfolioValue * fraction) / price);
    if (qty == 0) return nullptr;

    if (price > avg) return std::make_unique<Order>(Side::BUY, qty, price);
    if (price < avg) return std::make_unique<Order>(Side::SELL, qty, price);

    return nullptr;
}
