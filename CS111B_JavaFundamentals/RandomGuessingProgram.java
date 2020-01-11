import java.util.Random;

public class RandomGuessingProgram {
    public static void main(String[] args) {
        testGuess();
    }

    public static void testGuess() {
        final int GAME_COUNT = 20000;
        final int MIN = 1;
        final int MAX = 300;

        Random random = new Random();
        RandomNumberGuesser guesser = new RandomNumberGuesser(MIN, MAX);
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

        System.out.println();

        System.out.println("Test repeat getCurrentGuess() without guessing: (Should return the same number 4 times)");
        System.out.println(guesser.getCurrentGuess());
        System.out.println(guesser.getCurrentGuess());
        System.out.println(guesser.getCurrentGuess());
        System.out.println(guesser.getCurrentGuess());
    }
}
