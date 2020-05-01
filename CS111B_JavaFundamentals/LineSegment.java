import java.util.Scanner;

public class LineSegment {
    private Point point1;
    private Point point2;

    public LineSegment(Point p1, Point p2)
    {
        point1 = p1;
        point2 = p2;
    }
    public LineSegment(LineSegment segment)
    {
        point1 = segment.getP1();
        point2 = segment.getP2();
    }

    public Point getP1() { return point1; }
    public Point getP2() { return point2; }

    public double length()
    {
        return point1.distance(point2);
    }

    public boolean isLongerThan(LineSegment segment)
    {
        return this.length() > segment.length();
    }

    public static LineSegment longestLine(LineSegment[] lines)
    {
        if (lines.length == 0){
            return null;
        }

        LineSegment longest = lines[0];
        int len = lines.length;

        for (int i = 0; i < len - 1; i++)
        {
            if (lines[i].length() < lines[i + 1].length())
            {
                longest = lines[i + 1];
            }
        }
        return longest;
    }


    public static void main(String[] args) {

        int[] intArr = {2, 2, 2, 2, 3};
        System.out.println("here ya go " + allEqual(intArr));
    }
    public static boolean allEqual(int[] a) {
        int size = a.length;

        for (int i = 0; i < size - 1; i++) {
            if (a[i] != a[i + 1]) {
                return false;
            }
        }
        return true;
    }

}