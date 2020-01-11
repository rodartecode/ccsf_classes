import java.util.Arrays;
import java.util.Scanner;

// 02/02/2019
// Jesse E Rodarte
// CS111B
// Assignment 4: PokerHands

public class PokerHands {
    public static final int HANDSIZE = 5;

    public static void main(String[] args) {
        do {
            judgeHand();
        } while (shouldPlayAgain());
    }

    public static void judgeHand() {
        int[] hand;
        hand = getHand();

        if (containsFourOfaKind(hand)) {
            System.out.println("Four of a kind!");
        }
        else if (containsFullHouse(hand)) {
            System.out.println("Full house!");
        }
        else if (containsStraight(hand)) {
            System.out.println("A straight!");
        }
        else if (containsThreeOfaKind(hand)) {
            System.out.println("Three of a kind!");
        }
        else if (containsTwoPair(hand)) {
            System.out.println("Two pair!");
        }
        else if (containsPair(hand)) {
            System.out.println("A Pair!");
        }
        else {
            System.out.println("High card!");
        }
    }

    public static int[] getHand() {
        int[] hand = new int[HANDSIZE];
        int card;

        System.out.println("Enter five numeric cards, no face cards. Use 2 - 9 only.");
        for (int i = 0; i < HANDSIZE; i++) {
            System.out.print("Card " + (i + 1) + ": ");
            card = getCard();
            hand[i] = card;
        }
        Arrays.sort(hand);
        return hand;
    }

    public static int getCard() {
        int card;
        Scanner input = new Scanner(System.in);
        card = input.nextInt();
        while (card < 2 || card > 9) {
            System.out.println("That's not a valid number!!!");
            System.out.print("Try again. Use 2 - 9 only: ");
            card = input.nextInt();
        }
        return card;
    }

    public static boolean shouldPlayAgain() {
        char response;
        Scanner input = new Scanner(System.in);
        System.out.print("Do you want to try another hand? (y/n): ");
        response = input.next().charAt(0);
        return (response == 'y');
    }

    public static boolean containsFourOfaKind(int[] hand) {
        for (int i = 0; i < HANDSIZE; i++) {
            for (int j = i + 1; j < HANDSIZE; j++) {
                if (hand[i] == hand[j]) {
                    for (int k = j + 1;k < HANDSIZE; k++) {
                        if (hand[j] == hand[k]) {
                            if (k < HANDSIZE - 1) {
                                return (hand[k] == hand[k + 1]);
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    public static boolean containsFullHouse(int[] hand) {
        int pairs = 0;
        for (int i = 0; i < HANDSIZE; i++) {
            for (int j = i + 1; j < HANDSIZE; j++) {
                if (hand[i] == hand[j]) {
                    pairs++;
                }
            }
        }
        return (pairs == 4);
    }

    public static boolean containsStraight(int[] hand) {
        for (int i = 0; i < HANDSIZE; i++) {
            if (i < HANDSIZE - 1) {
                if (hand[i] != (hand[i + 1] - 1)) {
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean containsThreeOfaKind(int[] hand) {
        for (int i = 0; i < HANDSIZE; i++) {
            for (int j = i + 1; j < HANDSIZE; j++) {
                if (hand[i] == hand[j]) {
                    for (int k = j + 1;k < HANDSIZE; k++) {
                        if (hand[j] == hand[k]) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    public static boolean containsTwoPair(int[] hand) {
        int pairs = 0;
        for (int i = 0; i < HANDSIZE; i++) {
            for (int j = i + 1; j < HANDSIZE; j++) {
                if (hand[i] == hand[j]) {
                    pairs++;
                }
            }
        }
        return (pairs == 2);
    }

    public static boolean containsPair(int[] hand) {
        for (int i = 0; i < HANDSIZE; i++) {
            for (int j = i + 1; j < HANDSIZE; j++) {
                if (hand[i] == hand[j]) {
                     return true;
                }
            }
        }
        return false;
    }
}
