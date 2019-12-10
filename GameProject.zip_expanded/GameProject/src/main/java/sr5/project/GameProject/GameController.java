package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;
/**
 * Game Controller Class 
 * @author comcy
 *
 */
@RestController
@RequestMapping("/game")
public class GameController {

	/**
	 * Service is an instance of the GameService Class 
	 */
    @Autowired
    private GameService service;

    /**
     * Get All Game
     * @return all the games from the service
     */
    @RequestMapping(method = RequestMethod.GET)
    public List<Game> getAllGame() {
        return service.getAllGame();
    }

    /**
     * Get Game By Id
     * @param id
     * @return the specific game with the specified id 
     */
    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public Game getGameById(@PathVariable int id){
        return service.getGame(id);
    }

    /**
     * Delete Game By Id
     * @param id
     * @param game
     * @return the deleted game instance with the id referenced
     */
    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public Game deleteGameById(@PathVariable int id, @RequestBody Game game){
        Game deleted = service.getGame(id);
        service.deleteGame(id);
        return deleted;
    }

    /**
     * Update Game By Id
     * @param id
     * @param game
     * @return the specific updated game instance from the service
     */
    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public Game updateGameById(@PathVariable int id, @RequestBody Game game){
        service.updateGame(id, game);
        return service.getGame(id);
    }

    /**
     * Create Game
     * Creates a new instance of Game and adds it to the service instance 
     * @param game
     */
    @RequestMapping(method = RequestMethod.POST)
    public void createGame(@RequestBody Game game){
        service.saveGame(game);
    }

}
