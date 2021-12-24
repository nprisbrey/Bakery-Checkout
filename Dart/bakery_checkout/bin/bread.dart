import 'baked_good.dart';

class Bread extends BakedGood {
  final String _variety;

  Bread(this._variety) : super(4.50);

  @override
  String toString() {
    return "$_variety bread " + super.toString();
  }

  @override
  double discountedPrice(int quantity) {
    return (quantity - quantity ~/ 3) * super.basePrice;
  }
}
