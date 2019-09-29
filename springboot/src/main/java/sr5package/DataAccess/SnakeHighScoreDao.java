package sr5package.DataAccess;

import org.springframework.stereotype.Repository;
import sr5package.Entity.SnakeHighScore;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

@Repository
public class SnakeHighScoreDao {
    private static Map<Integer, SnakeHighScore> snakeHighScores;
    static {
        snakeHighScores = new HashMap<Integer, SnakeHighScore>(){
            {
                put(1, new SnakeHighScore(1, 37, null));
                put(2, new SnakeHighScore(1, 100, null));
                put(3, new SnakeHighScore(1, 45, null));
                put(4, new SnakeHighScore(1, 89, null));
            }
        };
    }
    public Collection<SnakeHighScore> getAllSnakeHighScores() {
        return this.snakeHighScores.values();
    }

    public SnakeHighScore getSnakeHighScoreById(int id) {
        return this.snakeHighScores.get(id);
    }

    public SnakeHighScore deleteSnakeHighScoreById(int id) {
        return this.snakeHighScores.remove(id);
    }

    public SnakeHighScore updateSnakeHighScore(SnakeHighScore snakeHighScore, int id) {
        SnakeHighScore score = snakeHighScores.get(id);
        score.setSnakeHighScoreScore(snakeHighScore.getSnakeHighScoreScore());
        score.setSnakeHighScoreDate(snakeHighScore.getSnakeHighScoreDate());

        snakeHighScores.put(id, score);
        return score;
    }

    public SnakeHighScore createSnakeHighScore(SnakeHighScore snakeHighScore) {
        this.snakeHighScores.put(snakeHighScore.getSnakeHighScoreId(), snakeHighScore);
        return snakeHighScore;
    }
}
