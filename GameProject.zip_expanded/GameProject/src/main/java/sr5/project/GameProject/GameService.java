package sr5.project.GameProject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * Game Service Class
 * @author comcy
 *
 */
@Service
public class GameService {

	/**
	 * repo is the instance of the Game Repository
	 */
    @Autowired
    private GameRepository repo;

    /**
     * Get All Game
     * @return find all games from the repo
     */
    public List<Game> getAllGame(){
        return (List<Game>) repo.findAll();
    }

    /**
     * Save Game
     * Saves the instance of the game to the repo
     * @param game
     */
    public void saveGame(Game game){
        repo.save(game);
    }

    /**
     * Get Game
     * @param id
     * @return the game with the corresponding id 
     */
    public Game getGame(int id){
        return repo.findById(id).get();
    }

    /**
     * Delete Game 
     * Deletes the Game with the associated Id
     * @param id
     */
    public void deleteGame(int id){
        repo.deleteById(id);
    }

    /**
     * Update Game
     * Updates the game with the associated id
     * @param id
     * @param game
     */
    public void updateGame(int id, Game game){
        repo.save(game);
    }
}
