import java.lang.Math;
import java.text.DecimalFormat;

// 02/03/2019
// Jesse E Rodarte
// CS111B
// Assignment 6: Circle Class

public class OldMyCircle {
    private double radius;
    private double x;
    private double y;

    public void setRad(double newRad) {
        radius = newRad;
    }
    public double getRad(){
        return radius;
    }

    public void setX(double newX) {
        x = newX;
    }
    public double getX() {
        return x;
    }

    public void setY(double newY) {
        y = newY;
    }
    public double getY() {
        return y;
    }


    public double getArea() {
        DecimalFormat df = new DecimalFormat("###.##");
        double area = Double.parseDouble(df.format((Math.PI * radius * radius)));
        return area;
    }

    public boolean doesOverlap(OldMyCircle otherCircle) {
        double distance = Math.sqrt(
                (otherCircle.getY() - y) * (otherCircle.getY() - y) +
                (otherCircle.getX() - x) * (otherCircle.getX() - x));

        return ((radius + otherCircle.getRad()) > distance);
    }
}
