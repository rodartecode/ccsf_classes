import java.util.Random;
import java.util.Scanner;

// 02/02/2019
// Jesse E Rodarte
// CS111B
// Assignment 2: Blackjack

public class Blackjack
{
    public static void main (String[] args){
        int cards, first, second, next;
        char goAgain = 'y';
        char newCard;
        Random rand = new Random();
        Scanner input = new Scanner(System.in);

        System.out.println("Welcome to Blackjack!");
        System.out.println();

        while (goAgain != 'n')
        {
            System.out.println("Here is your opening hand: ");
            first = rand.nextInt(10) + 1;
            second = rand.nextInt(10) + 1;
            cards = first + second;
            System.out.println(first + ", " + second);
            System.out.println("Total: " + cards);

            System.out.print("Would you like another card(y/n)?:  ");
            newCard = input.next().charAt(0);

            while (newCard != 'n')
            {
                next = rand.nextInt(10) + 1;
                cards += next;
                System.out.println("You've been dealt a " + next);
                System.out.println("Your new total is " + cards);
                if (cards <= 21)
                {
                    System.out.print("Would you like another card(y/n)?:  ");
                    newCard = input.next().charAt(0);
                }
                else
                {
                    System.out.println("Bust!");
                    newCard = 'n';
                }
            }
            if (cards <= 21)
            {
                System.out.println("Nice job not busting there friendo");
            }
            System.out.print("Would you like to play again(y/n): ");
            goAgain = input.next().charAt(0);
            System.out.println();
        }
        System.out.println("Thanks for playing!");
    }
}
