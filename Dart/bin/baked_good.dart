abstract class BakedGood {
  final double _basePrice;

  BakedGood(this._basePrice);

  @override
  String toString() {
    return "(\$" + _basePrice.toStringAsFixed(2) + ")";
  }

  double get basePrice => _basePrice;

  double discountedPrice(int quantity);
}
