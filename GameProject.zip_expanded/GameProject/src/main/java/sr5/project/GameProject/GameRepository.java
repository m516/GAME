package sr5.project.GameProject;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;
/**
 * Game Repository Class
 * @author comcy
 *
 */

@Repository
public interface GameRepository extends CrudRepository<Game, Integer> {

}
