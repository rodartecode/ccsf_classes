import java.util.ArrayList;
import java.util.Scanner;

// 02/03/2019
// Jesse E Rodarte
// CS111B
// Assignment 5: High Scores

public class OldHighScores {
    public static void main(String[] args) {
        do {
            ArrayList<String> names = new ArrayList<>();
            ArrayList<Integer> scores = new ArrayList<>();

            initialize(names, scores);
            sort(names, scores);
            display(names, scores);
        } while (shouldPlayAgain());
    }



    public static void initialize(ArrayList<String> names, ArrayList<Integer> scores) {
        Scanner input = new Scanner(System.in);
        String tempName;
        Integer tempScore;

        for (int i = 0; i < 5; i++) {
            System.out.print("Enter the name for score #" + (i + 1) + ": ");
            tempName = input.nextLine();
            System.out.print("Enter the score for score #" + (i + 1) + ": ");
            if (input.hasNextInt()) {
                tempScore = input.nextInt();
                scores.add(tempScore);
                names.add(tempName);
                input.nextLine();
            } else {
                System.out.println("Invalid input. Please try again.  ");
                input.nextLine();
                System.out.println();
                i--;
            }
        }
    }

    public static void sort(ArrayList<String> names, ArrayList<Integer> scores) {
        boolean sorted = false;
        int passes = 1;
        int size = names.size();
        while (!sorted && passes < size)
        {
            sorted = true;
            for (int i = 0; i < (size - 1); i++)
            {
                int nextI = i + 1;
                if (scores.get(i) < scores.get(nextI))
                {
                    swap(names, scores, i, nextI);
                    sorted = false;
                }
            }
            passes++;
        }
    }

    public static void display(ArrayList<String> names, ArrayList<Integer> scores) {
        System.out.println();
        System.out.println("Top Scorers: ");
        for (int i = 0; i < names.size(); i++) {
            System.out.println(names.get(i) + ": " + scores.get(i));
        }
    }

    public static void swap(ArrayList<String> names, ArrayList<Integer> scores, int i, int nextI) {
        String tempName = names.get(i);
        Integer tempScore = scores.get(i);

        names.set(i, names.get(nextI));
        scores.set(i, scores.get(nextI));

        names.set(nextI, tempName);
        scores.set(nextI, tempScore);
    }

    public static boolean shouldPlayAgain() {
        char response;
        Scanner input = new Scanner(System.in);
        System.out.print("Do you want to try again? (y/n): ");
        response = input.next().charAt(0);
        return (response == 'y');
    }
}
