#include "../include/Order.h"

Order::Order(Side s, int q, double p)
  : side(s), quantity(q), price(p)
  { }
Side Order::getSide() const { return side; }
int Order::getQuantity() const { return quantity; }
double Order::getPrice() const { return price; }
