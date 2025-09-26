#include "../include/CSVFeed.h"
#include "../include/StrategyFactory.h"
#include "../include/BacktestEngine.h"
#include <memory>

int main() {
    {
    auto portfolio = std::make_unique<Portfolio>(100000.0);
    auto feed = std::make_unique<CSVFeed>("data/bitcoin_data.csv");
    auto strategy = StrategyFactory::create("MovingAverage");

    BacktestEngine engine(std::move(feed), std::move(strategy), std::move(portfolio), "BTC-USD");
    engine.run();
    }

    {
    auto feed = std::make_unique<CSVFeed>("data/bitcoin_data.csv");
    auto strategy = StrategyFactory::create("DoubleMovingAverage");
    auto portfolio = std::make_unique<Portfolio>(100000.0);

    BacktestEngine engine(std::move(feed), std::move(strategy), std::move(portfolio), "BTC-USD");
    engine.run();
    }
    return 0;
}
