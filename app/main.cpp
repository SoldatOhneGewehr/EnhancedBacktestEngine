#include "../include/CSVFeed.h"
#include "../include/StrategyFactory.h"
#include "../include/BacktestEngine.h"
#include <memory>
#include <iostream>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <csv_file>" << std::endl;
        return 1;
    }
    
    {
    auto portfolio = std::make_unique<Portfolio>(100000.0);
    auto feed = std::make_unique<CSVFeed>(argv[1]);
    auto strategy = StrategyFactory::create("MovingAverage");

    BacktestEngine engine(std::move(feed), std::move(strategy), std::move(portfolio), "BTC-USD");
    engine.run();
    }

    {
    auto feed = std::make_unique<CSVFeed>(argv[1]);
    auto strategy = StrategyFactory::create("DoubleMovingAverage");
    auto portfolio = std::make_unique<Portfolio>(100000.0);

    BacktestEngine engine(std::move(feed), std::move(strategy), std::move(portfolio), "BTC-USD");
    engine.run();
    }
    return 0;
}
