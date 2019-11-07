package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/game")
public class GameController {

    @Autowired
    private GameService service;

    @RequestMapping(method = RequestMethod.GET)
    public List<Game> getAllGame() {
        return service.getAllGame();
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public Game getGameById(@PathVariable int id){
        return service.getGame(id);
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public Game deleteGameById(@PathVariable int id, @RequestBody Game game){
        Game deleted = service.getGame(id);
        service.deleteGame(id);
        return deleted;
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public Game updateGameById(@PathVariable int id, @RequestBody Game game){
        service.updateGame(id, game);
        return service.getGame(id);
    }

    @RequestMapping(method = RequestMethod.POST)
    public void createGame(@RequestBody Game game){
        service.saveGame(game);
    }

}
