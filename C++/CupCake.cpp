//
// Created by NandM2 on 12/10/2021.
//

#include "CupCake.h"

#include <utility>

CupCake::CupCake(std::string flavor, std::string frosting, std::string sprinkleColor) : Cake((frosting == "cream-cheese" ? 2.15 : 1.95), std::move(flavor), frosting), sprinkleColor(std::move(sprinkleColor)) {}

std::string CupCake::ToString() const {
    return Cake::getFlavor() + " cupcake with " + Cake::getFrosting() + " frosting and " + sprinkleColor + " sprinkles " + BakedGood::ToString();
}

double CupCake::DiscountedPrice(int quantity) {
    if(quantity >= 4) {
        return quantity * (BakedGood::getBasePrice() - 0.40);
    } else if(quantity >= 2) {
        return quantity * (BakedGood::getBasePrice() - 0.30);
    } else {
        return quantity * BakedGood::getBasePrice();
    }
}
