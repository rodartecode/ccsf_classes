import java.util.Random;
import java.util.Scanner;

// 02/03/2019
// Jesse E Rodarte
// CS111B
// Assignment 7: OOP Number Guesser

public class GuessingProgram {
    public static void main(String[] args) {
        testGuess();
        do {
            playOneGame();
        } while (shouldPlayAgain());
    }

    public static void testGuess() {
        final int GAME_COUNT = 20000;
        final int MIN = 1;
        final int MAX = 100;


        Random random = new Random();
        NumberGuesser guesser = new NumberGuesser(MIN, MAX);
        int totalGuessCount = 0;

        // Make the guesser look for a random number, GAME_COUNT times
        for (int i = 0; i < GAME_COUNT; i++) {
            // There is always the initial guess
            int guessCount = 1;
            // Generate a random value to look for, from MIN to MAX, inclusive.
            int targetValue = MIN + random.nextInt(MAX - MIN + 1);
            // Keep looping until the guesser gets it right
            while (targetValue != guesser.getCurrentGuess()) {
                // Adjust the guesser, as needed...
                if (targetValue > guesser.getCurrentGuess()) {
                    guesser.higher();
                } else {
                    guesser.lower();
                }
                // That's one more guess, bump up the count
                guessCount++;
                System.out.println("target/guess:  " + targetValue + " " + guesser.getCurrentGuess());
            }
            System.out.println("Hah! I got it!");
            // Keep track of the total number of guesses in all the simulated games
            totalGuessCount += guessCount;
            // Return the guesser is in its initial state
            guesser.reset();
        }
        // Calculate and display the average
        double averageGuessCount = totalGuessCount / (double) GAME_COUNT;
        System.out.println("Average number of guesses: " + averageGuessCount);
    }

    public static void playOneGame() {
        int low = 1;
        int high = 100;
        int guess;
        char response = 'a';
        boolean again = true;
        RandomNumberGuesser guesser = new RandomNumberGuesser(low, high);
        System.out.println("Guess a number between 1 and 100.");
        while (response != 'c') {
            guess = guesser.getCurrentGuess();
            System.out.print("Is your number " + guess + "? (h/l/c):  ");
            response = getUserResponseToGuess();
            try {
                if (response == 'h') {
                    guesser.higher();
                } else if (response == 'l') {
                    guesser.lower();
                }
            }
            catch(IllegalStateException e) {
                System.out.println(e.getMessage());
                System.exit(666);
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
}
