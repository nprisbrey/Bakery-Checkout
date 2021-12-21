package Main;

import java.util.*;

public class BakeryCheckout {
    public static void PrintMenu() {
        System.out.println("""
                ******** MENU ********
                Below are the different options that you can enter as a sub-order (all quantities are integers):
                Layer-cake [flavor] [frosting] [number of layers] [quantity]
                Cupcake [flavor] [frosting] [sprinkles] [quantity]
                Bread [variety] [quantity]
                """);
    }

    public static String MakeLowercase(String original) {
        return original.toLowerCase();
    }

    public static void main(String[] args) {
        Scanner reader = new Scanner(System.in);
        String suborder = "";
        int cartQuantity = 0;
        ArrayList<BakedGood> allGoods = new ArrayList<>();
        Map<String, Integer> uniqueGoods = new HashMap<>();
        double cartPrice = 0;

        System.out.println("**Bread and Cakes Bakery**\n");

        PrintMenu();

        System.out.println("Enter sub-order (enter \"done\" to finish)");
        while(!MakeLowercase(suborder).equalsIgnoreCase("done")) {
            System.out.println("Sub-order:");
            suborder = reader.nextLine();

            String[] suborderWords = suborder.split(" ");
            if(suborderWords[0].equalsIgnoreCase("bread")) {
                for(int i = 0; i < Integer.parseInt(suborderWords[2]); i++) {
                    allGoods.add(new Bread(suborderWords[1]));
                }
            } else if(suborderWords[0].equalsIgnoreCase("cupcake")) {
                for(int i = 0; i < Integer.parseInt(suborderWords[4]); i++) {
                    allGoods.add(new CupCake(suborderWords[1], suborderWords[2], suborderWords[3]));
                }
            } else if(suborderWords[0].equalsIgnoreCase("layer-cake")) {
                for(int i = 0; i < Integer.parseInt(suborderWords[4]); i++) {
                    allGoods.add(new LayerCake(suborderWords[1], suborderWords[2], Integer.parseInt(suborderWords[3])));
                }
            } else if(!suborderWords[0].equalsIgnoreCase("done")) {
                System.out.println("\nThe product \"" + suborderWords[0] + "\" is not recognized. Please enter a suborder according to the menu. See below:");
                PrintMenu();
            }
        }

        System.out.println("\nOrder Confirmations:");
        for (BakedGood allGood : allGoods) {
            System.out.println(allGood.ToString());
        }

        //Populate uniqueGoods
        for (BakedGood allGood : allGoods) {
            String key = allGood.ToString();
            if (uniqueGoods.containsKey(key)) {
                uniqueGoods.put(key, uniqueGoods.get(key) + 1);
            } else {
                uniqueGoods.put(key, 1);
            }
        }

        System.out.println("""
                
                Invoice:
                Baked Good Quantity Total($)""");
        for(BakedGood Good : allGoods) {
            String key = Good.ToString();
            if(uniqueGoods.get(key) != 0) {
                System.out.println(key + " " + uniqueGoods.get(key) + " " + String.format("%.2f",Good.DiscountedPrice(uniqueGoods.get(key))));
                cartQuantity += uniqueGoods.get(key);
                cartPrice += Good.DiscountedPrice(uniqueGoods.get(key));
                uniqueGoods.put(key, 0);
            }
        }

        System.out.println("Totals: " + cartQuantity + " " + cartPrice);

        System.out.println("\nThank you for your order! Good Bye!");

        reader.close();
    }
}
