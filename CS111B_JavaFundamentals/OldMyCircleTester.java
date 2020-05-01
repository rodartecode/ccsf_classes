// 02/03/2019
// Jesse E Rodarte
// CS111B
// Assignment 6: Circle Class

public class OldMyCircleTester {
    public static void main(String[] args) {
        OldMyCircle circle1 = new OldMyCircle();
        OldMyCircle circle2 = new OldMyCircle();
        OldMyCircle circle3 = new OldMyCircle();

        circle1.setRad(1);
        circle1.setX(25);
        circle1.setY(25);

        circle2.setRad(12);
        circle2.setX(1);
        circle2.setY(1);

        circle3.setRad(13);
        circle3.setX(2);
        circle3.setY(2);

        boolean notOverlap = circle1.doesOverlap(circle2);
        boolean notOverlap2 = circle1.doesOverlap(circle3);
        boolean overlap = circle2.doesOverlap(circle3);

        System.out.println("Circle 1 area: " + circle1.getArea());
        System.out.println("Circle 2 area: " + circle2.getArea());
        System.out.println("Circle 3 area: " + circle3.getArea());

        System.out.println("Circle 1 overlaps circle 2?:   " + notOverlap);
        System.out.println("Circle 2 overlaps circle 3?:   " + overlap);
        System.out.println("Circle 3 overlaps circle 1?:   " + notOverlap2);
    }
}
