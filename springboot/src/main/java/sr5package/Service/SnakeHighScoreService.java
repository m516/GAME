package sr5package.Service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import sr5package.DataAccess.SnakeHighScoreDao;
import sr5package.Entity.SnakeHighScore;

import java.util.Collection;

@Service
public class SnakeHighScoreService {

    @Autowired
    private SnakeHighScoreDao snakeHighScoreDao;

    public Collection<SnakeHighScore> getAllSnakeHighScores() {
        return snakeHighScoreDao.getAllSnakeHighScores();
    }
    public SnakeHighScore getSnakeHighScoreById(int id) {
        return snakeHighScoreDao.getSnakeHighScoreById(id);
    }

    public SnakeHighScore deleteSnakeHighScoreById(int id) {
        return snakeHighScoreDao.deleteSnakeHighScoreById(id);
    }

    public SnakeHighScore updateSnakeHighScore(SnakeHighScore snakeHighScore, int id) {
        return snakeHighScoreDao.updateSnakeHighScore(snakeHighScore, id);
    }

    public SnakeHighScore createSnakeHighScore(SnakeHighScore snakeHighScore) {
        return snakeHighScoreDao.createSnakeHighScore(snakeHighScore);
    }
}
