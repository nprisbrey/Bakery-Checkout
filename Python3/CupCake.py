import Cake

class CupCake(Cake):
    def __init__(self, flavor, frosting, sprinkleColor):
        super().__init__((2.15 if frosting.lower() == "cream-cheese" else 1.95), flavor, frosting)
        self._sprinkleColor = sprinkleColor

    def __str__(self):
        return super().getFlavor() + " cupcake with " + super().getFrosting() + " frosting and " + self.sprinkleColor + " sprinkles " + super()

    #Overriding abstract DiscountedPrice(quantity) from BakedGood
    def DiscountedPrice(self, quantity):
        if(quantity >= 4):
            return quantity * (super().getBasePrice() - 0.40)
        elif(quantity >= 2):
            return quantity * (super().getBasePrice() - 0.30)
        else:
            return quantity * super().getBasePrice()
