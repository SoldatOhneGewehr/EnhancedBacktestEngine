// Portfolio.h
#pragma once
#include "Execution.h"
#include "Order.h"
#include <unordered_map>
#include <string>

class Portfolio {
    double cash;
    std::unordered_map<std::string, int> positions; // symbol -> quantity

public:
    Portfolio(double initialCash);
    void applyExecution(const Execution& exec, Side side, const std::string& symbol);
    double getValue(const std::string& symbol, double currentPrice) const;
    double getCash() const { return cash; }
    bool canBuy(double price, int quantity) const;
    bool canSell(const std::string& symbol, int quantity) const;
};
