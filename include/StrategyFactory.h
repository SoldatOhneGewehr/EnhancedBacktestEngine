#pragma once
#include "Strategy.h"
#include "Portfolio.h"
#include <memory>
#include <string>

class StrategyFactory {
public:
    static std::unique_ptr<Strategy> create(const std::string& type);
};
