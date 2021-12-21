package Main;

public abstract class BakedGood {
    private double basePrice;

    public BakedGood(double basePrice) {
        this.basePrice = basePrice;
    }

    public String ToString() {
        return "($" + String.format("%.2f", basePrice) + ")";
    }

    public double getBasePrice() {
        return basePrice;
    }

    public abstract double DiscountedPrice(int quantity);
}
