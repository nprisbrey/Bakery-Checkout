# Bakery-Checkout

A program that simulates the electronic payment system of a bakery. Prices and discounts are automatically applied.

The program was originally written in C++ and then later translated to Java, Python3, and Dart. Most of the translated code was written as the most direct translation of the original C++ code, even if such translated code wasn't the most efficient in the translated language. Some minor exceptions were made, one of which can be seen by Java, Python3, and Dart retaining the capitalization of the user's input while C++ makes all strings lowercase. The code for all four versions can be found in the corresponding directory and be compared.

An example of the system is shown below. User input is bolded.

## Example:
<pre>
**Bread and Cakes Bakery**

******** MENU ********
Below are the different options that you can enter as a sub-order (all quantities are integers):
Layer-cake [flavor] [frosting] [number of layers] [quantity]
Cupcake [flavor] [frosting] [sprinkles] [quantity]
Bread [variety] [quantity]

Enter sub-order (enter "done" to finish)
Sub-order:
<b>Bread Wheat 4</b>
Sub-order:
<b>Cupcake Funfetti lemon pink 1</b>
Sub-order:
<b>Bread White 1</b>
Sub-order:
<b>Layer-cake Chocolate vanilla 2 3</b>
Sub-order:
<b>Layer-cake Spice cream-cheese 3 2</b>
Sub-order:
<b>Cupcake Yellow cream-cheese red 3</b>
Sub-order:
<b>Cupcake Chocolate vanilla blue 4</b>
Sub-order:
<b>Bread White 1</b>
Sub-order:
<b>Cupcake Chocolate vanilla blue 1</b>
Sub-order:
<b>done</b>

Order Confirmations:
wheat bread ($4.50)
wheat bread ($4.50)
wheat bread ($4.50)
wheat bread ($4.50)
funfetti cupcake with lemon frosting and pink sprinkles ($1.95)
white bread ($4.50)
2-layer chocolate cake with vanilla frosting ($12.00)
2-layer chocolate cake with vanilla frosting ($12.00)
2-layer chocolate cake with vanilla frosting ($12.00)
3-layer spice cake with cream-cheese frosting ($18.00)
3-layer spice cake with cream-cheese frosting ($18.00)
yellow cupcake with cream-cheese frosting and red sprinkles ($2.15)
yellow cupcake with cream-cheese frosting and red sprinkles ($2.15)
yellow cupcake with cream-cheese frosting and red sprinkles ($2.15)
chocolate cupcake with vanilla frosting and blue sprinkles ($1.95)
chocolate cupcake with vanilla frosting and blue sprinkles ($1.95)
chocolate cupcake with vanilla frosting and blue sprinkles ($1.95)
chocolate cupcake with vanilla frosting and blue sprinkles ($1.95)
white bread ($4.50)
chocolate cupcake with vanilla frosting and blue sprinkles ($1.95)

Invoice:
Baked Good                                                                  Quantity Total($)
wheat bread ($4.50)                                                                4    13.50
funfetti cupcake with lemon frosting and pink sprinkles ($1.95)                    1     1.95
white bread ($4.50)                                                                2     9.00
2-layer chocolate cake with vanilla frosting ($12.00)                              3    30.00
3-layer spice cake with cream-cheese frosting ($18.00)                             2    36.00
yellow cupcake with cream-cheese frosting and red sprinkles ($2.15)                3     5.55
chocolate cupcake with vanilla frosting and blue sprinkles ($1.95)                 5     7.75
Totals:                                                                           20   103.75

Thank you for your order! Good Bye!

</pre>
