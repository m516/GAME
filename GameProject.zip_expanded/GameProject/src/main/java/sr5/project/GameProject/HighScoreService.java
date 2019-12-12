package sr5.project.GameProject;


import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * High Score Service
 * @author comcy
 *
 */
@Service 
public class HighScoreService {
	
	/**
	 * Repo is the HighScore Repository instance
	 */
	@Autowired
	private HighScoreRepository repo;
	
	/**
	 * Get All High Score
	 * @return all high score instance from the repository
	 */
	public List<HighScore> getAllHighScore(){
		return (List<HighScore>) repo.findAll();
	}
	
	/**
	 * Saves the specific high score to the database with the body and id 	
	 * @param highScore
	 */
	public void saveHighScore(HighScore highScore) {
		repo.save(highScore);
	}
	
	/**
	 * Get High Score 
	 * Uses the Id to get the high score from the repository
	 * @param id
	 * @return high score entity with the corresponding id
	 */
	public HighScore getHighScore(int id) {
		return repo.findById(id).get();
	}
	
	/**
	 * Delete High Score
	 * Deletes the High Score by Id from the repository and returns void
	 * @param id
	 */
	public void deleteHighScore(int id) {
		repo.deleteById(id);
	}  
	
	/**
	 * Update High Score
	 * uses the highscore entity and id to update the repository
	 * @param id
	 * @param highScore
	 */
	public void updateHighScore(int id, HighScore highScore) {
		repo.save(highScore);
	}
	
	
}
