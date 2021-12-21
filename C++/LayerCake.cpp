//
// Created by NandM2 on 12/10/2021.
//

#include "LayerCake.h"

#include <utility>

LayerCake::LayerCake(std::string flavor, std::string frosting, int numLayers) : Cake((9.00 + ((numLayers-1) * 3) + (frosting == "cream-cheese" ? numLayers : 0)), std::move(flavor), frosting), numLayers(numLayers) {}

std::string LayerCake::ToString() const {
    return std::to_string(numLayers) + "-layer " + Cake::getFlavor() + " cake with " + Cake::getFrosting() + " frosting " + BakedGood::ToString();
}

double LayerCake::DiscountedPrice(int quantity) {
    return (quantity >= 3 ? BakedGood::getBasePrice() - 2.00 : BakedGood::getBasePrice()) * quantity;
}
