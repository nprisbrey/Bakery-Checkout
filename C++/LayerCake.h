//
// Created by NandM2 on 12/10/2021.
//

#include "Cake.h"

#ifndef CHP9STUFF_LAYERCAKE_H
#define CHP9STUFF_LAYERCAKE_H


class LayerCake : public Cake {
public:
    LayerCake(std::string flavor, std::string frosting, int numLayers);

    std::string ToString() const override;

    double DiscountedPrice(int quantity) override;

private:
    int numLayers;
};


#endif //CHP9STUFF_LAYERCAKE_H
