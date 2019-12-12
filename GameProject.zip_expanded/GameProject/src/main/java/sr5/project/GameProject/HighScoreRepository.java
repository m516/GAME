package sr5.project.GameProject;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

/**
 * High Score Repository
 * @author comcy
 *
 */
@Repository
public interface HighScoreRepository extends CrudRepository<HighScore, Integer>{
	
}
