import BakedGood

class Cake(BakedGood):
    def __init__(self, basePrice, flavor, frosting):
        super().__init__(basePrice)
        self._flavor = flavor
        self._frosting = frosting

    def getFlavor(self):
        return self._flavor

    def getFrosting(self):
        return self._frosting
