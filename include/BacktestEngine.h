// BacktestEngine.h
#pragma once
#include "MarketDataFeed.h"
#include "Strategy.h"
#include "Portfolio.h"
#include "Instrument.h"
#include <memory>
#include <string>

class BacktestEngine {
    std::unique_ptr<MarketDataFeed> feed;
    std::unique_ptr<Strategy> strategy;
    std::unique_ptr<Portfolio> portfolio;
    std::string symbol;
public:
    BacktestEngine(std::unique_ptr<MarketDataFeed> f,
                   std::unique_ptr<Strategy> s,
                   std::unique_ptr<Portfolio> p,
                   std::string symbol);
    void run();
};
