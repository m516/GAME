package sr5.project.GameProject;

import java.util.Collection;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/highscore")
public class HighScoreController {
	
	@Autowired
	private HighScoreService service;
	 
	@RequestMapping(method = RequestMethod.GET)
	public List<HighScore> getAllHighScore(){
		return service.getAllHighScore();
	}
	
	@RequestMapping(value = "/{id}", method = RequestMethod.GET)
	public HighScore getHighScoreById(@PathVariable int id) {
		return service.getHighScore(id);
	}
	
	@RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
	public HighScore deleteHighScoreById(@PathVariable int id) {
		HighScore deleted = service.getHighScore(id);
		service.deleteHighScore(id);
		return deleted;
	}
	
	@RequestMapping(value = "/{id}", method = RequestMethod.PUT)
	public HighScore updateHighScoreById(@PathVariable int id, @RequestBody HighScore highScore) {
		service.updateHighScore(id, highScore);
		HighScore newhs = service.getHighScore(id);
		return newhs;
	}
	
	@RequestMapping(method = RequestMethod.POST)
	public void createHighScore(@RequestBody HighScore highScore) {
		service.saveHighScore(highScore);
	}
}
	