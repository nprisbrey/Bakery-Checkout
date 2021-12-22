package Main;

public abstract class Cake extends BakedGood {
    private final String flavor, frosting;

    public Cake(double basePrice, String flavor, String frosting) {
        super(basePrice);
        this.flavor = flavor;
        this.frosting = frosting;
    }

    public String getFlavor() {
        return flavor;
    }

    public String getFrosting() {
        return frosting;
    }
}
