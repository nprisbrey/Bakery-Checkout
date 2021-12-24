import 'cake.dart';

class CupCake extends Cake {
  final String _sprinkleColor;

  CupCake(String flavor, String frosting, this._sprinkleColor) : super((frosting == "cream-cheese" ? 2.15 : 1.95), flavor, frosting);

  @override
  String toString() {
    return "${super.flavor} cupcake with ${super.frosting} frosting and $_sprinkleColor sprinkles " + super.toString();
  }

  @override
  double discountedPrice(int quantity) {
    if(quantity >= 4) {
      return quantity * (super.basePrice - 0.40);
    } else if(quantity >= 2) {
      return quantity * (super.basePrice - 0.30);
    } else {
      return quantity * super.basePrice;
    }
  }
}
