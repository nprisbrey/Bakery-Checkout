import Cake

class LayerCake(Cake):
    def __init__(self, flavor, frosting, numLayers):
        super().__init__((9.00 + ((numLayers-1) * 3) + (numLayers if frosting.lower() == "cream-cheese" else 0)), flavor, frosting)
        self.numLayers = numLayers

    def __str__(self):
        return self.numLayers + "-layer " + super().getFlavor() + " cake with " + super().getFrosting() + " frosting " + super

    #Overriding abstract DiscountedPrice(quantity) from BakedGood
    def DiscountedPrice(self, quantity):
        return ((super().getBasePrice() - 2.00) if quantity >= 3 else (super().getBasePrice())) * quantity
