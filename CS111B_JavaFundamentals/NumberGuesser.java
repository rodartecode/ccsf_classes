// 02/03/2019
// Jesse E Rodarte
// CS111B
// Assignment 7: OOP Number Guesser

public class NumberGuesser {
    protected int lowerBound;
    protected int startingLowerBound;
    protected int upperBound;
    protected int startingUpperBound;
    protected int currentGuess;

    protected NumberGuesser(int lower, int upper) {
        lowerBound = lower;
        startingLowerBound = lower;
        upperBound = upper;
        startingUpperBound = upper;
        currentGuess = ((lower + upper) / 2);
    }

    protected NumberGuesser() {
        lowerBound = 1;
        startingLowerBound = 1;
        upperBound = 100;
        startingUpperBound = 100;
        currentGuess = 50;
    }

    protected void higher() {
        if (lowerBound == upperBound || lowerBound > upperBound) {
            throw new IllegalStateException("You've reached an illegal game state, please restart your computer.");
        }
        lowerBound = currentGuess + 1;
        currentGuess = getCurrentGuess();
    }

    protected void lower() {
        if (lowerBound == upperBound || lowerBound > upperBound) {
            throw new IllegalStateException("You've reached an illegal game state, please restart your computer.");
        }
        upperBound = currentGuess - 1;
        currentGuess = getCurrentGuess();
    }

    protected int getCurrentGuess() {
        return ((lowerBound + upperBound) / 2);
    }

    protected void reset() {
        lowerBound = startingLowerBound;
        upperBound = startingUpperBound;
        currentGuess = ((lowerBound + upperBound) / 2);
    }
}
