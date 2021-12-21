package Main;

public class Bread extends BakedGood {
    private final String variety;

    public Bread(String variety) {
        super(4.50);
        this.variety = variety;
    }

    @Override
    public String ToString() {
        return variety + " bread " + super.ToString();
    }

    @Override
    public double DiscountedPrice(int quantity) {
        return (quantity - quantity/3) * super.getBasePrice();
    }
}
