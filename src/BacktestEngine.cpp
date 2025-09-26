// BacktestEngine.cpp
#include "../include/BacktestEngine.h"
#include "../include/Execution.h"
#include <iostream>

BacktestEngine::BacktestEngine(std::unique_ptr<MarketDataFeed> f,
                               std::unique_ptr<Strategy> s,
                               std::unique_ptr<Portfolio> p,
                               std::string sym)
  : feed(std::move(f)), strategy(std::move(s)), portfolio(std::move(p)), symbol(sym)
  { }
double lastPrice = 0;
void BacktestEngine::run() {
    strategy->setPortfolio(portfolio.get());
    while (feed->hasNext()) {
        Bar bar = feed->getNextBar();
        auto order = strategy->generateSignal(bar);
        lastPrice = bar.close;

        if (order) {
            if (order->getSide() == Side::BUY && !portfolio->canBuy(bar.close, order->getQuantity())) {
                /*std::cout << bar.date << " : Not enough cash to buy " 
                        << order->getQuantity() << " shares of " << symbol << " at " 
                        << bar.close << "\n";*/
                continue; // skip this order if not enough cash
            }

            if (order->getSide() == Side::SELL && !portfolio->canSell(symbol, order->getQuantity())) {
                /*std::cout << bar.date << " : Not enough shares to sell "
                        << order->getQuantity() << " shares of " << symbol << " at "
                        << bar.close << "\n";*/
                continue; // skip this order if not enough shares
            }
            Execution exec(bar.close, order->getQuantity()); // fill at close price
            portfolio->applyExecution(exec, order->getSide(), symbol);
        }
    }
    std::cout << "Final Portfolio Value: " << portfolio->getValue(symbol, lastPrice) << std::endl;
}
