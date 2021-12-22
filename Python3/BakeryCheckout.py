from LayerCake import LayerCake
from CupCake import CupCake
from Bread import Bread

def PrintMenu():
    print('''******** MENU ********
Below are the different options that you can enter as a sub-order (all quantities are integers):
Layer-cake [flavor] [frosting] [number of layers] [quantity]
Cupcake [flavor] [frosting] [sprinkles] [quantity]
Bread [variety] [quantity]
    ''')

def MakeLowercase(original):
    return original.lower()

suborder = ""
cartQuantity = 0
allGoods = []
uniqueGoods = {}
cartPrice = 0

print("**Bread and Cakes Bakery**\n")

PrintMenu()

print("Enter sub-order (enter \"done\" to finish)")
while(MakeLowercase(suborder) != "done"):
    print("Sub-order:")
    suborder = input()

    suborderWords = suborder.split()
    if(suborderWords[0].lower() == "bread"):
        for i in range(int(suborderWords[2])):
            allGoods.append(Bread(suborderWords[1]))
    elif(suborderWords[0].lower() == "cupcake"):
        for i in range(int(suborderWords[4])):
            allGoods.append(CupCake(suborderWords[1], suborderWords[2], suborderWords[3]))
    elif(suborderWords[0].lower() == "layer-cake"):
        for i in range(int(suborderWords[4])):
            allGoods.append(LayerCake(suborderWords[1], suborderWords[2], int(suborderWords[3])))
    elif(suborderWords[0].lower() != "done"):
        print("\nThe product \"" + suborderWords[0] + "\" is not recognized. Please enter a suborder according to the menu. See below:")
        PrintMenu()

print("\nOrder Confirmations:")
for allGood in allGoods:
    print(str(allGood))

#Populate uniqueGoods
for allGood in allGoods:
    key = str(allGood)
    if(key in uniqueGoods):
        uniqueGoods[key] += 1
    else:
        uniqueGoods[key] = 1

print("\nInvoice:")
print("{:<75}{:>9}{:>9}".format("Baked Good", "Quantity", "Total($)"))
for Good in allGoods:
    key = str(Good)
    if(uniqueGoods[key] != 0):
        print("{:<75}{:>9}{:>9.2f}".format(key, uniqueGoods[key], Good.DiscountedPrice(uniqueGoods[key])))
        cartQuantity += uniqueGoods[key]
        cartPrice += Good.DiscountedPrice(uniqueGoods[key])
        uniqueGoods[key] = 0

print("{:<75}{:>9}{:>9.2f}".format("Totals:", cartQuantity, cartPrice))

print("\nThank you for your order! Good Bye!")
