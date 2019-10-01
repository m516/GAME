package sr5.project.GameProject;


import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class HighScoreService {
	
	@Autowired
	private HighScoreRepository repo;
	
	public List<HighScore> listAll(){
		return repo.findAll();
	}
	
	public void save(HighScore highScore) {
		repo.save(highScore);
	}
	
	public HighScore get(int id) {
		return repo.findById(id).get();
	}
	
	public void delete(int id) {
		repo.deleteById(id);
	}   
}
