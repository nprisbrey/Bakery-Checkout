//
// Created by NandM2 on 12/10/2021.
//

#include "Cake.h"

#include <utility>

Cake::Cake(double basePrice, std::string flavor, std::string frosting) : BakedGood(basePrice), flavor(std::move(flavor)), frosting(std::move(frosting)) {}

const std::string &Cake::getFlavor() const {
    return flavor;
}

const std::string &Cake::getFrosting() const {
    return frosting;
}
