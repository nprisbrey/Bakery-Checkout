#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include "Bread.h"
#include "CupCake.h"
#include "LayerCake.h"

void PrintMenu() {
    std::cout << "******** MENU ********" << std::endl
        << "Below are the different options that you can enter as a sub-order (all quantities are integers):" << std::endl
        << "Layer-cake [flavor] [frosting] [number of layers] [quantity]" << std::endl
        << "Cupcake [flavor] [frosting] [sprinkles] [quantity]" << std::endl
        << "Bread [variety] [quantity]" << std::endl << std::endl;
}

std::string MakeLowercase(std::string original) {
    std::for_each(original.begin(), original.end(), [](char& c) {
        c = std::tolower(c);
    });
    return original;
}

int main() {
    std::string suborder, good, variety, flavor, frosting, sprinkles;
    int quantity, numLayers, cartQuantity = 0;
    std::vector<BakedGood *> allGoods;
    std::map<std::string,int> uniqueGoods;
    double cartPrice = 0;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << "**Bread and Cakes Bakery**" << std::endl << std::endl;

    PrintMenu();

    std::cout << "Enter sub-order (enter \"done\" to finish)" << std::endl;
    while(MakeLowercase(suborder) != "done") {
        std::cout << "Sub-order:" << std::endl;
        getline(std::cin, suborder);

        std::istringstream userInput(MakeLowercase(suborder));
        userInput >> good;
        if(good == "bread") {
            userInput >> variety;
            userInput >> quantity;
            for(int i = 0; i < quantity; i++) {
                allGoods.push_back(new Bread(variety));
            }
        } else if(good == "cupcake") {
            userInput >> flavor;
            userInput >> frosting;
            userInput >> sprinkles;
            userInput >> quantity;
            for(int i = 0; i < quantity; i++) {
                allGoods.push_back(new CupCake(flavor, frosting, sprinkles));
            }
        } else if(good == "layer-cake") {
            userInput >> flavor;
            userInput >> frosting;
            userInput >> numLayers;
            userInput >> quantity;
            for(int i = 0; i < quantity; i++) {
                allGoods.push_back(new LayerCake(flavor, frosting, numLayers));
            }
        } else if (good != "done") {
            std::cout << std::endl << "The product \"" << suborder.substr(0,suborder.find(' ')) << "\" is not recognized. Please enter a suborder according to the menu. See below:" << std::endl;
            PrintMenu();
        }
    }

    std::cout << std::endl;

    std::cout << "Order Confirmations:" << std::endl;
    for(int i = 0; i < allGoods.size(); i++) {
        std::cout << allGoods.at(i)->ToString() << std::endl;
    }

    std::cout << std::endl;

    //Populate uniqueGoods
    for(int i = 0; i < allGoods.size(); i++) {
        auto location = uniqueGoods.find(allGoods.at(i)->ToString());
        if(location != uniqueGoods.end()) {
            location->second++;
        } else {
            uniqueGoods.insert({allGoods.at(i)->ToString(),1});
        }
    }

    std::cout << "Invoice:" << std::endl
        << std::left << std::setw(75) << "Baked Good" << std::right << std::setw(9) << "Quantity" << std::setw(9) << "Total($)" << std::endl;
    for(auto Good : allGoods) {
        std::string key = Good->ToString();
        if(uniqueGoods.at(key) != 0) {
            std::cout << std::left << std::setw(75) << key << std::right << std::setw(9) << uniqueGoods.at(key) << std::setw(9) << Good->DiscountedPrice(uniqueGoods.at(key)) << std::endl;
            cartQuantity += uniqueGoods.at(key);
            cartPrice += Good->DiscountedPrice(uniqueGoods.at(key));
            uniqueGoods.at(key) = 0;
        }
    }

    std::cout << std::left << std::setw(75) << "Totals:" << std::right << std::setw(9) << cartQuantity << std::setw(9) << cartPrice << std::endl;

    std::cout << std::endl << "Thank you for your order! Good Bye!" << std::endl;

    return 0;
}
