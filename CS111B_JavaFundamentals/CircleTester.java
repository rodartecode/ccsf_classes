// 02/24/2019
// Jesse E Rodarte
// CS111B
// Assignment 8: Improved Circle Class

public class CircleTester {
    public static void main(String args[]) {
        Circle circle1, circle2, circle3, circle4, circle5,  circle6;
        Point point1 = new Point(12, 2);

        circle1 = new Circle();
        circle2 = new Circle(point1, 10);
        circle3 = new Circle(10, 10, 10);
        circle4 = new Circle(circle1);
        circle5 = new Circle(100, 100, 1);
        circle6 = new Circle(point1, 1);

        String string1 = circle1.toString();
        String string2 = circle3.toString();
        String string3 = circle5.toString();

        System.out.println("1: " + string1);
        System.out.println("3: " + string2);
        System.out.println("5: " + string3);
        System.out.println();


        boolean bool1 = circle1.equals(circle4);
        boolean bool2 = circle2.equals(circle6);

        System.out.println("Circle 1 equals circle 4? (Should be true)   " + bool1);
        System.out.println("Circle 2 equals circle 6? (Should be false)   " + bool2);

        boolean overlap1 = circle1.doesOverlap(circle2);
        boolean overlap2 = circle1.doesOverlap(circle3);
        boolean overlap3 = circle2.doesOverlap(circle3);

        System.out.println();
        System.out.println("Circle 1 overlaps circle 2? (Should be false)    " + overlap1);
        System.out.println("Circle 1 overlaps circle 3? (Should be false)    " + overlap2);
        System.out.println("Circle 2 overlaps circle 3? (Should be true)    " + overlap3);
        System.out.println();

        circle1.setRadius(999);
        System.out.println("Changed circle1's radius");
        System.out.println("1: " + circle1.toString());
        System.out.println("Circle1 overlaps circle2? (Should be true now)    " + circle1.doesOverlap(circle2));
        System.out.println();
    }
}
