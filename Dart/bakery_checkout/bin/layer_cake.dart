import 'cake.dart';

class LayerCake extends Cake {
  final int _numLayers;

  LayerCake(String flavor, String frosting, this._numLayers)
      : super(
            (9.00 +
                ((_numLayers - 1) * 3) +
                (frosting == "cream-cheese" ? _numLayers : 0)),
            flavor,
            frosting);

  @override
  String toString() {
    return "$_numLayers-layer ${super.flavor} cake with ${super.frosting} frosting " +
        super.toString();
  }

  @override
  double discountedPrice(int quantity) {
    return (quantity >= 3 ? super.basePrice - 2.00 : super.basePrice) *
        quantity;
  }
}
