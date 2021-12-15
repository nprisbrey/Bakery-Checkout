//
// Created by NandM2 on 12/10/2021.
//

#include "BakedGood.h"

BakedGood::BakedGood(double basePrice) : basePrice(basePrice) {}

double BakedGood::getBasePrice() const {
    return basePrice;
}

std::string BakedGood::ToString() const {
    std::string price = std::to_string(basePrice);
    return "($" + price.substr(0,price.find('.')+3) + ")";
}
