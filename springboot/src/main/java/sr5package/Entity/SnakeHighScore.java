package sr5package.Entity;

import sr5package.Service.SnakeHighScoreService;

import java.util.Date;

public class SnakeHighScore {
    private int id;
    private int Score;
    private Date Score_date;

    public SnakeHighScore(int id, int Score, Date Score_date) {
        this.id = id;
        this.Score = Score;
        this.Score_date = Score_date;
    }

    public SnakeHighScore(){}

    public int getSnakeHighScoreId(){
        return id;
    }
    public void setSnakeHighScoreId(int id){
        this.id = id;
    }
    public int getSnakeHighScoreScore(){
        return Score;
    }
    public void setSnakeHighScoreScore(int Score){
        this.Score = Score;
    }
    public Date getSnakeHighScoreDate(){
        return Score_date;
    }
    public void setSnakeHighScoreDate(Date Score_date){
        this.Score_date = Score_date;
    }
}