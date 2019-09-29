package sr5package.Controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import sr5package.Entity.SnakeHighScore;
import sr5package.Service.SnakeHighScoreService;

import java.util.Collection;

@RestController
@RequestMapping("/highscore/snake")
public class SnakeHighScoreController {

    @Autowired
    private SnakeHighScoreService snakeHighScoreService;

    @RequestMapping(method = RequestMethod.GET)
    public Collection<SnakeHighScore> getAllSnakeHighScores(){
        return snakeHighScoreService.getAllSnakeHighScores();
    }
    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public SnakeHighScore getSnakeHighScoreById(@PathVariable int id){
        return SnakeHighScoreService.getSnakeHighScoreById(id);
    }
    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public SnakeHighScore deleteSnakeHighScoreById(@PathVariable int id){
        return SnakeHighScoreService.deleteSnakeHighScoreById(id);
    }
    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public SnakeHighScore updateSnakeHighScore(@RequestBody SnakeHighScore snakeHighScore, @PathVariable int id){
        return SnakeHighScoreService.updateSnakeHighScore(snakeHighScore, id);
    }
    @RequestMapping(method = RequestMethod.POST)
    public SnakeHighScore createSnakeHighScore(@RequestBody SnakeHighScore snakeHighScore){
        return SnakeHighScoreService.createSnakeHighScore(snakeHighScore);
    }

}
