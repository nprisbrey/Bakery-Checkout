//
// Created by NandM2 on 12/10/2021.
//

#include "Cake.h"

#ifndef CHP9STUFF_CUPCAKE_H
#define CHP9STUFF_CUPCAKE_H


class CupCake : public Cake {
public:
    CupCake(std::string flavor, std::string frosting, std::string sprinkleColor);

    std::string ToString() const override;

    double DiscountedPrice(int quantity) override;

private:
    std::string sprinkleColor;
};


#endif //CHP9STUFF_CUPCAKE_H
