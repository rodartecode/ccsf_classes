import java.util.Scanner;

// 02/24/2019
// Jesse E Rodarte
// CS111B
// Assignment 9: High Scores with OOP

public class HighScoreProgram {
    public static final int SIZE = 5;

    public static void main(String[] args) {
        HighScore[] scores = new HighScore[SIZE];

        initialize(scores);
        sort(scores);
        display(scores);
    }



    public static void initialize(HighScore[] s) {
        Scanner input = new Scanner(System.in);
        String tempName;
        Integer tempScore;

        for (int i = 0; i < SIZE; i++) {
            System.out.print("Enter the name for score #" + (i + 1) + ": ");
            tempName = input.nextLine();
            System.out.print("Enter the score for score #" + (i + 1) + ": ");
            if (input.hasNextInt()) {
                tempScore = input.nextInt();
                HighScore newScore = new HighScore(tempName, tempScore);
                s[i] = newScore;
                input.nextLine();
            } else {
                System.out.println("Invalid input. Please try again.  ");
                input.nextLine();
                System.out.println();
                i--;
            }
        }
    }

    public static void sort(HighScore[] s) {
        boolean sorted = false;
        int passes = 1;
        int size = s.length;
        while (!sorted && passes < size)
        {
            sorted = true;
            for (int i = 0; i < (size - 1); i++)
            {
                int nextI = i + 1;
                if (s[i].getScore() < s[nextI].getScore())
                {
                    swap(s, i, nextI);
                    sorted = false;
                }
            }
            passes++;
        }

    }

    public static void display(HighScore[] s) {
        System.out.println();
        System.out.println("Top Scorers: ");
        for (int i = 0; i < s.length; i++) {
            System.out.println(s[i].getName() + ": " + s[i].getScore());
        }
    }

    public static void swap(HighScore[] s, int i, int nextI) {
        HighScore temp = new HighScore(s[i].getName(), s[i].getScore());
        s[i] = s[nextI];
        s[nextI] = temp;
    }
}
