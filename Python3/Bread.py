from BakedGood import BakedGood

class Bread(BakedGood):
    def __init__(self, variety):
        super().__init__(4.50)
        self._variety = variety

    def __str__(self):
        return self._variety + " bread " + super().__str__()

    #Overriding abstract DiscountedPrice(quantity) from BakedGood
    def DiscountedPrice(self, quantity):
        return (quantity - quantity//3) * super().getBasePrice()
