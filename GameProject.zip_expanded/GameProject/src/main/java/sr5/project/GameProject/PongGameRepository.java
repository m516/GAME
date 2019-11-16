package sr5.project.GameProject;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface PongGameRepository extends CrudRepository<PongGame, Integer> {

}
