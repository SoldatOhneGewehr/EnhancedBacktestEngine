// Portfolio.cpp
#include "../include/Portfolio.h"

Portfolio::Portfolio(double initialCash) : cash(initialCash) {}

void Portfolio::applyExecution(const Execution& exec, Side side, const std::string& symbol) {
    double qty = exec.getFillQuantity();
    double cost = exec.getFillPrice() * qty;

    if (side == Side::BUY) {
        cash -= cost;
        positions[symbol] += qty;
    } else { // SELL
        cash += cost;
        positions[symbol] -= qty;
    }
}


double Portfolio::getValue(const std::string& symbol, double currentPrice) const {
    auto it = positions.find(symbol);
    if (it == positions.end()) return cash;
    return cash + (it->second * currentPrice);
}

bool Portfolio::canBuy(double price, int quantity) const {
    return cash >= price * quantity;
}
bool Portfolio::canSell(const std::string& symbol, int quantity) const {
    auto it = positions.find(symbol);
    if (it == positions.end()) return false;
    return it->second >= quantity;
}
