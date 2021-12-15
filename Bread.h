//
// Created by NandM2 on 12/10/2021.
//

#include "BakedGood.h"
#include <string>

#ifndef CHP9STUFF_BREAD_H
#define CHP9STUFF_BREAD_H


class Bread : public BakedGood {
public:
    Bread(std::string variety);

    std::string ToString() const override;

    double DiscountedPrice(int quantity) override;

private:
    std::string variety;
};


#endif //CHP9STUFF_BREAD_H
