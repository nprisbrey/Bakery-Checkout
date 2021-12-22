from abc import ABC, abstractmethod

class BakedGood():
    def __init__(self, basePrice):
        self._basePrice = basePrice

    def __str__(self):
        return "(${:.2f})".format(self._basePrice)

    def getBasePrice(self):
        return self._basePrice

    @abstractmethod
    def DiscountedPrice(self, quantity):
        pass
