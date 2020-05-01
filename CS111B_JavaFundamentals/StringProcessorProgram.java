import java.util.Scanner;

public class StringProcessorProgram {
    public static void main(String args[]) {
        do {
            stringFacts();
        } while (getResponse());
    }

    public static void stringFacts() {
        StringProcessor pro = new StringProcessor(getString());
        pro.getFacts();
    }

    public static String getString() {
        String s;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a string to get some facts: ");

        s = input.nextLine();

        return s;
    }

    public static boolean getResponse() {
        char response;
        Scanner input = new Scanner(System.in);
        System.out.print("Do you want to try another string? (y/n): ");
        response = input.next().charAt(0);
        return (response == 'y');
    }
}

/*********************************
 * EXPECTED OUTPUT:
 * *******************************
 *
 * Enter a string to get some facts:
 * I wanT fIve SStrings     345634
 * The string you entered is I wanT fIve SStrings     345634
 * Words: 5
 * Uppercase: 5
 * Digits: 6
 * Digit words: 1
 * Line with whitespace removed: "IwanTfIveSStrings345634"
 * Line with vowels replaced: "- w-nT f-v- SStr-ngs     345634"
 * Line with digit words replaced: "IwanT5SStrings345634"
 *
 * Do you want to try another string? (y/n): y
 * Enter a string to get some facts:
 * thaNKS for the facts
 * The string you entered is thaNKS for the facts
 * Words: 4
 * Uppercase: 3
 * Digits: 0
 * Digit words: 0
 * Line with whitespace removed: "thaNKSforthefacts"
 * Line with vowels replaced: "th-NKS f-r th- f-cts"
 * Line with digit words replaced: "thaNKSforthefacts"
 *
 * Do you want to try another string? (y/n): n*
 * ********************************************************/
