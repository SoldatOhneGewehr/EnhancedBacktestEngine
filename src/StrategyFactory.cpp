#include "../include/StrategyFactory.h"
#include "../include/MovingAverageStrategy.h"
#include "../include/DoubleMovingAverageStrategy.h"


std::unique_ptr<Strategy> StrategyFactory::create(const std::string& type) {
    if (type == "MovingAverage") {
        return std::make_unique<MovingAverageStrategy>(8);
    }

    if (type == "DoubleMovingAverage") {
        return std::make_unique<DoubleMovingAverageStrategy>(50, 200);
    }
    return nullptr;
}
