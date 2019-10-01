package sr5.project.GameProject;


import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service 
public class HighScoreService {
	
	@Autowired
	private HighScoreRepository repo;
	
	public List<HighScore> getAllHighScore(){
		return (List<HighScore>) repo.findAll();
	}
	
	public void saveHighScore(HighScore highScore) {
		repo.save(highScore);
	}
	
	public HighScore getHighScore(int id) {
		return repo.findById(id).get();
	}
	
	public void deleteHighScore(int id) {
		repo.deleteById(id);
	}  
	
	public void updateHighScore(int id, HighScore highScore) {
		repo.save(highScore);
	}
	
	
}
