import 'baked_good.dart';

abstract class Cake extends BakedGood {
  final String _flavor, _frosting;

  Cake(double basePrice, this._flavor, this._frosting) : super(basePrice);

  String get flavor => _flavor;

  String get frosting => _frosting;
}
