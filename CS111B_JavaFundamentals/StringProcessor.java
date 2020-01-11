public class StringProcessor {
    private static String[] digWords = {
            "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
    };
    private String string;

    StringProcessor() {
        string = "";
    }

    StringProcessor(String s) {
        string = s;
    }

    public String getString() {
        return string;
    }

    public void setString(String s) {
        string = s;
    }

    public int wordCount() {
        int words = 0;
        String[] strArr = string.split(" ");
        for (String s : strArr) {
            if (!s.isEmpty())
                words++;
        }
        return words;
    }

    public int uppercaseCount() {
        char[] charArr;
        int upp = 0;

        charArr = string.toCharArray();

        for (char c : charArr) {
            if (Character.isUpperCase(c)) {
                upp++;
            }
        }

        return upp;
    }

    public int digitCount() {
        char[] charArr;
        int digits = 0;

        charArr = string.toCharArray();

        for (char c : charArr) {
            if (Character.isDigit(c)) {
                digits++;
            }
        }

        return digits;
    }

    public int digitWordCount() {
        String[] strArr = string.split(" ");
        int words = 0;
        for (String s : strArr) {
            for (String w : digWords) {
                if (s.equalsIgnoreCase(w)) {
                    words++;
                }
            }
        }

        return words;
    }

    public String getNoSpaceString() {
        String[] strArr = string.split(" ");
        StringBuilder builder = new StringBuilder();
        for (String s : strArr) {
            builder.append(s);
        }
        return builder.toString();
    }

    public String getNoVowelString() {
        return string.replaceAll("[aeiouAEIOU]", "-");
    }

    public String getNoDigitWordString() {
        String[] strArr = string.split(" ");
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < digWords.length; i++) {
            for (int j = 0; j < strArr.length; j++) {
                if (strArr[j].toUpperCase().equals(digWords[i].toUpperCase())) {
                    strArr[j] = Integer.toString(i+1);
                }
            }
        }

        for (String s : strArr) {
            builder.append(s);
        }
        return builder.toString();
    }

    public void getFacts() {
        System.out.println("The string you entered is " + string);
        System.out.println("Words: " + wordCount());
        System.out.println("Uppercase: " + uppercaseCount());
        System.out.println("Digits: " + digitCount());
        System.out.println("Digit words: " + digitWordCount());
        System.out.println("Line with whitespace removed: " + '"' + getNoSpaceString() + '"');
        System.out.println("Line with vowels replaced: " + '"' + getNoVowelString() + '"');
        System.out.println("Line with digit words replaced: " + '"' + getNoDigitWordString() + '"');
        System.out.println();
    }

}
