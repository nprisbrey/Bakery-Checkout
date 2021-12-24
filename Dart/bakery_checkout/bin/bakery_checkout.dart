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
  print('Hello world!');
}
