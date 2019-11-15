package sr5.project.GameProject;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface HighScoreRepository extends CrudRepository<HighScore, Integer>{
	
}
