//
// Created by NandM2 on 12/10/2021.
//

#include "BakedGood.h"
#include <string>

#ifndef CHP9STUFF_CAKE_H
#define CHP9STUFF_CAKE_H


class Cake: public BakedGood {
public:
    Cake(double basePrice, std::string flavor, std::string frosting);

    const std::string &getFlavor() const;

    const std::string &getFrosting() const;

private:
    std::string flavor, frosting;
};


#endif //CHP9STUFF_CAKE_H
