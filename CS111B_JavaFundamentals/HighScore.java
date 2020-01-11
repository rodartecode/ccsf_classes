// 02/24/2019
// Jesse E Rodarte
// CS111B
// Assignment 9: High Scores with OOP

public class HighScore {
    private String name;
    private int score;

    HighScore(String n, int s) {
        name = n;
        score = s;
    }

    public void setName(String n) { name = n; }
    public String getName() { return name; }

    public void setScore(int s) { score = s; }
    public int getScore() { return score; }
}
