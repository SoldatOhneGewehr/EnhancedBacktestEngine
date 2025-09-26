// CSVFeed.cpp
#include "../include/CSVFeed.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

CSVFeed::CSVFeed(const std::string& filename) : currentIndex(0) {
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Cannot open feed file: " + filename);

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::istringstream ss(line);
        std::string token;
        Bar bar;

        // date
        std::getline(ss, bar.date, ',');
        // numeric fields
        std::getline(ss, token, ','); bar.open   = std::stod(token);
        std::getline(ss, token, ','); bar.high   = std::stod(token);
        std::getline(ss, token, ','); bar.low    = std::stod(token);
        std::getline(ss, token, ','); bar.close  = std::stod(token);
        std::getline(ss, token, ','); bar.volume = std::stod(token);

        data.push_back(bar);
    }
}

bool CSVFeed::hasNext() const {
    return currentIndex < data.size();
}

Bar CSVFeed::getNextBar() {
    if (!hasNext()) throw std::out_of_range("No more bars in feed");
    return data[currentIndex++];
}
