import 'dart:io';

import 'baked_good.dart';
import 'bread.dart';
import 'cupcake.dart';
import 'layer_cake.dart';

void printMenu() {
  print("""
******** MENU ********
Below are the different options that you can enter as a sub-order (all quantities are integers):
Layer-cake [flavor] [frosting] [number of layers] [quantity]
Cupcake [flavor] [frosting] [sprinkles] [quantity]
Bread [variety] [quantity]
""");
}

String makeLowercase(String original) => original.toLowerCase();

void main(List<String> arguments) {
  String suborder = "";
  int cartQuantity = 0;
  List<BakedGood> allGoods = [];
  Map<String, int> uniqueGoods = {};
  double cartPrice = 0;

  print("**Bread and Cakes Bakery**\n");

  printMenu();

  print("Enter sub-order (enter \"done\" to finish)");
  while(!(makeLowercase(suborder) == "done")) {
    print("Sub-order:");
    suborder = stdin.readLineSync().toString();

    var suborderWords = suborder.split(" ");
    suborderWords.removeWhere((word) => word == "");
    if(suborderWords[0].toLowerCase() == "bread") {
      for(int i = 0; i < int.parse(suborderWords[2]); i++) {
        allGoods.add(Bread(suborderWords[1]));
      }
    } else if(suborderWords[0].toLowerCase() == "cupcake") {
      for(int i = 0; i < int.parse(suborderWords[4]); i++) {
        allGoods.add(CupCake(suborderWords[1], suborderWords[2], suborderWords[3]));
      }
    } else if(suborderWords[0].toLowerCase() == "layer-cake") {
      for(int i = 0; i < int.parse(suborderWords[4]); i++) {
        allGoods.add(LayerCake(suborderWords[1], suborderWords[2], int.parse(suborderWords[3])));
      }
    } else if(suborderWords[0].toLowerCase() != "done") {
      print("\nThe product \"${suborderWords[0]}\" is not recognized. Please enter a suborder according to the menu. See below:");
      printMenu();
    }
  }

  print("\nOrder Confirmations:");
  for(final allGood in allGoods) {
    print(allGood.toString());
  }

  //Populate uniqueGoods
  for(final allGood in allGoods) {
    final String key = allGood.toString();
    uniqueGoods.update(
      key,
      (int quantity) => quantity + 1,
      ifAbsent: () => 1,
    );
  }

  print("\nInvoice:");
  print("Baked Good".padRight(75) + "Quantity".padLeft(9) + "Total(\$)".padLeft(9));
  for(final good in allGoods) {
    final String key = good.toString();
    if(uniqueGoods[key] != 0) {
      print(key.padRight(75) + uniqueGoods[key]!.toString().padLeft(9) + good.discountedPrice(uniqueGoods[key]!).toStringAsFixed(2).padLeft(9));
      cartQuantity += uniqueGoods[key]!;
      cartPrice += good.discountedPrice(uniqueGoods[key]!);
      uniqueGoods[key] = 0;
    }
  }

  print("Totals:".padRight(75) + cartQuantity.toString().padLeft(9) + cartPrice.toStringAsFixed(2).padLeft(9));

  print("\nThank you for your order! Good Bye!");
}
