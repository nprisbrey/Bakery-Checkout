cmake_minimum_required(VERSION 3.21)
project(Bakery_Checkout)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bakery_Checkout main.cpp BakedGood.cpp BakedGood.h Bread.cpp Bread.h Cake.cpp Cake.h LayerCake.cpp LayerCake.h CupCake.cpp CupCake.h)
