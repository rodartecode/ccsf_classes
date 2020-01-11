import java.util.Scanner;

// 02/02/2019
// Jesse E Rodarte
// CS111B
// Assignment 3: NumberGuesser

public class OldNumberGuesser {
    public static void main(String[] args) {
        do {
            playOneGame();
        } while (shouldPlayAgain());
    }

    public static void playOneGame() {
        int low = 1;
        int high = 100;
        int guess;
        char response = 'a';
        boolean again = true;
        System.out.println("Guess a number between 1 and 100.");
        while (response != 'c') {
            guess = getMidpoint(low, high);
            System.out.print("Is your number " + guess + "? (h/l/c):  ");
            response = getUserResponseToGuess();
            if (response == 'h') {
                low = guess;
                if (low == 99)
                    low++;
            } else if (response == 'l') {
                high = guess;
            }
        }
        System.out.println("Hah! I got it!");
    }

    public static boolean shouldPlayAgain() {
        char response;
        Scanner input = new Scanner(System.in);
        System.out.print("Do you want to play again? (y/n): ");
        response = input.next().charAt(0);
        return (response == 'y');
    }

    public static char getUserResponseToGuess() {
        char response;
        Scanner input = new Scanner(System.in);
        response = input.next().charAt(0);
        if (response != 'h' && response != 'l' && response != 'c') {
            System.out.println("Wrong answer! Now give me a valid response!");
            System.out.print("(h/l/c)?  ");
            response = getUserResponseToGuess();
        }

        return response;
    }

    public static int getMidpoint(int low, int high) {
        return (high + low) / 2;
    }
}
