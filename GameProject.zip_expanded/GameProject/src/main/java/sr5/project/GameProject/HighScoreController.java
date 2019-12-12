package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 * High Score Controller
 * @author comcy
 *
 */
@RestController
@RequestMapping("/highscore")
public class HighScoreController {
	
	/**
	 * Service is an instance of the HighScoreService
	 */
	@Autowired
	private HighScoreService service;
	 
	/**
	 * Get All High Score 
	 * 
	 * @return all high scores from the service instance
	 */
	@RequestMapping(method = RequestMethod.GET)
	public List<HighScore> getAllHighScore(){
		return service.getAllHighScore();
	}
	
	/**
	 * Get High Score By Id 
	 * @param id
	 * @return high score with the corresponding id from the service
	 */
	@RequestMapping(value = "/{id}", method = RequestMethod.GET)
	public HighScore getHighScoreById(@PathVariable int id) {
		return service.getHighScore(id);
	}
	
	/**
	 * Delete High Score By Id
	 * @param id
	 * @return the deleted high score entity from the service
	 */
	@RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
	public HighScore deleteHighScoreById(@PathVariable int id) {
		HighScore deleted = service.getHighScore(id);
		service.deleteHighScore(id);
		return deleted;
	}
	
	/**
	 * Update High Score By Id
	 * @param id
	 * @param highScore
	 * @return the High Score with the specific id 
	 */
	@RequestMapping(value = "/{id}", method = RequestMethod.PUT)
	public HighScore updateHighScoreById(@PathVariable int id, @RequestBody HighScore highScore) {
		service.updateHighScore(id, highScore);
		return service.getHighScore(id);
	}
	
	/**
	 * Create High Score
	 * Creates a new high score entity with the request body passed in 
	 * @param highScore
	 */
	@RequestMapping(method = RequestMethod.POST)
	public void createHighScore(@RequestBody HighScore highScore) {
		service.saveHighScore(highScore);
	}
}
	
