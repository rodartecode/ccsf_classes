import java.text.DecimalFormat;

// 02/24/2019
// Jesse E Rodarte
// CS111B
// Assignment 8: Improved Circle Class


public class Circle {
    private double radius;
    private Point center;

    Circle(Point p, double r) {
        center = p;
        radius = r;
    }

    Circle(double xValue, double yValue, double r) {
        center = new Point(xValue, yValue);
        radius = r;
    }

    Circle() {
        center = new Point(0, 0);
        radius = 1;
    }

    Circle(Circle c) {
        center = c.getCenter();
        radius = c.getRadius();
    }

    public Point getCenter() {
        return center;
    }

    public void setCenter(Point p) {
        center = p;
    }

    public double getX() {
        return center.getX();
    }

    public void setX(double value) {
        center.setX(value);
    }

    public double getY() {
        return center.getY();
    }

    public void setY(double value) {
        center.setY(value);
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double r) {
        radius = r;
    }

    public double getArea() {
        DecimalFormat df = new DecimalFormat("###.##");
        double area = Double.parseDouble(df.format((Math.PI * radius * radius)));
        return area;
    }

    public String toString() {
        return "Radius is " + this.getRadius() + ", Center is " + center.toString();
    }

    boolean equals(Circle c) {
        return this.radius == c.getRadius() && this.center.equals(c.getCenter());
    }

    boolean doesOverlap(Circle c) {
        double distance = center.distance(c.getCenter());
        return (radius + c.getRadius()) > distance;
    }
}
