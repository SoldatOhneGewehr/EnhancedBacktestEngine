#pragma once

enum class Side {BUY, SELL, HOLD};

class Order
{
  Side side;
  int quantity = 0;
  double price;

public:
  Order(Side s, int q, double p);
  Side getSide() const;
  int getQuantity() const;
  double getPrice() const;
};