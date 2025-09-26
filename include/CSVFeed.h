#pragma once
#include "MarketDataFeed.h"
#include <vector>
#include <string>

class CSVFeed : public MarketDataFeed {
    std::vector<Bar> data;
    size_t currentIndex;
public:
    CSVFeed(const std::string& filename);
    bool hasNext() const override;
    Bar getNextBar() override;
};
