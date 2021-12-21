package Main;

public class LayerCake extends Cake {
    private final int numLayers;

    public LayerCake(String flavor, String frosting, int numLayers) {
        super((9.00 + ((numLayers-1) * 3) + (frosting.equalsIgnoreCase("cream-cheese") ? numLayers : 0)), flavor, frosting);
        this.numLayers = numLayers;
    }

    @Override
    public String ToString() {
        return numLayers + "-layer " + super.getFlavor() + " cake with " + super.getFrosting() + " frosting " + super.ToString();
    }

    @Override
    public double DiscountedPrice(int quantity) {
        return (quantity >= 3 ? super.getBasePrice() - 2.00 : super.getBasePrice()) * quantity;
    }
}
