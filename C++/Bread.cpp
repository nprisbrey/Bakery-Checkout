//
// Created by NandM2 on 12/10/2021.
//

#include "Bread.h"

#include <utility>

Bread::Bread(std::string variety) : BakedGood(4.50), variety(std::move(variety)) {}

std::string Bread::ToString() const {
    return variety + " bread " + BakedGood::ToString();
}

double Bread::DiscountedPrice(int quantity) {
    return (quantity - quantity/3) * BakedGood::getBasePrice();
}
