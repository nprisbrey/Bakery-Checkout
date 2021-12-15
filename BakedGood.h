//
// Created by NandM2 on 12/10/2021.
//

#include <iostream>

#ifndef CHP9STUFF_BAKEDGOOD_H
#define CHP9STUFF_BAKEDGOOD_H

class BakedGood {
public:
    BakedGood(double basePrice);

    virtual std::string ToString() const;

    double getBasePrice() const;

    virtual double DiscountedPrice(int quantity) = 0;

private:
    double basePrice;
};


#endif //CHP9STUFF_BAKEDGOOD_H
