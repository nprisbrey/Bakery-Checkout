package Main;

public class CupCake extends Cake {
    private final String sprinkleColor;

    public CupCake(String flavor, String frosting, String sprinkleColor) {
        super((frosting.equalsIgnoreCase("cream-cheese") ? 2.15 : 1.95), flavor, frosting);
        this.sprinkleColor = sprinkleColor;
    }

    @Override
    public String ToString() {
        return super.getFlavor() + " cupcake with " + super.getFrosting() + " frosting and " + sprinkleColor + " sprinkles " + super.ToString();
    }

    @Override
    public double DiscountedPrice(int quantity) {
        if(quantity >= 4) {
            return quantity * (super.getBasePrice() - 0.40);
        } else if(quantity >= 2) {
            return quantity * (super.getBasePrice() - 0.30);
        } else {
            return quantity * super.getBasePrice();
        }
    }
}
