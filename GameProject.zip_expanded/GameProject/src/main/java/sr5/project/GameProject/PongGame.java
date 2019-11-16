package sr5.project.GameProject;

import javax.persistence.*;

@Entity
@Table(name = "pong_game")
public class PongGame {
    private int id;
    private int leftPaddleY;
    private int rightPaddleY;
    private int ballX;
    private int ballY;
    private int leftScore;
    private int rightScore;
    private boolean leftWinner;
    private boolean rightWinner;
    private int leftUserId;
    private int rightUserId;
    private String leftUsername;
    private String rightUsername;


    public PongGame() {
    }

    public PongGame(int id,
                    int leftPaddleY, int rightPaddleY,
                    int ballX, int ballY,
                    int leftScore, int rightScore,
                    boolean leftWinner, boolean rightWinner,
                    int leftUserId, int rightUserId,
                    String leftUsername, String rightUsername) {

        this.id = id;
        this.leftPaddleY = leftPaddleY;
        this.rightPaddleY = rightPaddleY;
        this.ballX = ballX;
        this.ballY = ballY;
        this.leftScore = leftScore;
        this.rightScore = rightScore;
        this.leftWinner = leftWinner;
        this.rightWinner = rightWinner;
        this.leftUserId = leftUserId;
        this.rightUserId = rightUserId;
        this.leftUsername = leftUsername;
        this.rightUsername = rightUsername;

    }

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getLeftPaddleY() {
        return leftPaddleY;
    }

    public void setLeftPaddleY(int leftPaddleY) {
        this.leftPaddleY = leftPaddleY;
    }

    public int getRightPaddleY() {
        return rightPaddleY;
    }

    public void setRightPaddleY(int rightPaddleY) {
        this.rightPaddleY = rightPaddleY;
    }

    public int getBallX() {
        return ballX;
    }

    public void setBallX(int ballX) {
        this.ballX = ballX;
    }

    public int getBallY() {
        return ballY;
    }

    public void setBallY(int ballY) {
        this.ballY = ballY;
    }

    public int getLeftScore() {
        return leftScore;
    }

    public void setLeftScore(int leftScore) {
        this.leftScore = leftScore;
    }

    public int getRightScore() {
        return rightScore;
    }

    public void setRightScore(int rightScore) {
        this.rightScore = rightScore;
    }

    public boolean isLeftWinner() {
        return leftWinner;
    }

    public void setLeftWinner(boolean leftWinner) {
        this.leftWinner = leftWinner;
    }

    public boolean isRightWinner() {
        return rightWinner;
    }

    public void setRightWinner(boolean rightWinner) {
        this.rightWinner = rightWinner;
    }

    public int getLeftUserId() {
        return leftUserId;
    }

    public void setLeftUserId(int leftUserId) {
        this.leftUserId = leftUserId;
    }

    public int getRightUserId() {
        return rightUserId;
    }

    public void setRightUserId(int rightUserId) {
        this.rightUserId = rightUserId;
    }

    public String getLeftUsername(){
        return leftUsername;
    }

    public void setLeftUsername(String leftUsername) {
        this.leftUsername = leftUsername;
    }

    public String getRightUsername(){
        return rightUsername;
    }

    public void setRightUsername(String rightUsername) {
        this.rightUsername = rightUsername;
    }
}








