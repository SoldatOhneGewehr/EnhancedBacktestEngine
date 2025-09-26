
#include "../include/DoubleMovingAverageStrategy.h"

DoubleMovingAverageStrategy::DoubleMovingAverageStrategy(size_t shortPeriod, size_t longPeriod ) 
: shortPeriod_(shortPeriod)
, longPeriod_(longPeriod)
, portfolio_(nullptr)
{ }

void DoubleMovingAverageStrategy::setPortfolio(Portfolio* portfolio) {
    portfolio_ = portfolio;
}

std::unique_ptr<Order> DoubleMovingAverageStrategy::generateSignal(const Bar& bar) {
    double price = bar.close; // using closing price for now

    longWindow_.push_back(price);
    shortWindow_.push_back(price);

    if (longWindow_.size() > longPeriod_) longWindow_.pop_front();
    if (shortWindow_.size() > shortPeriod_) shortWindow_.pop_front();

    if (longWindow_.size() < longPeriod_) return nullptr;

    double portfolioValue = portfolio_->getValue("BTC-USD", price);
    double fraction = 1;
    int qty = static_cast<int>((portfolioValue * fraction) / price);
    if (qty == 0) return nullptr;

    if (CalculateSMA(shortWindow_, shortPeriod_) > CalculateSMA(longWindow_, longPeriod_)) return std::make_unique<Order>(Side::BUY, qty, price);
    if (CalculateSMA(shortWindow_, shortPeriod_) < CalculateSMA(longWindow_, longPeriod_)) return std::make_unique<Order>(Side::SELL, qty, price);

    return nullptr;
}


double DoubleMovingAverageStrategy::CalculateSMA(const std::deque<double>& window, size_t period_) {
  double sum = 0.0;
  for (double p : window) sum += p;
    double avg = sum / period_;
  return avg;
}