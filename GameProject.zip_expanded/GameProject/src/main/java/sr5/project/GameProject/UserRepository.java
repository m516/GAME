package sr5.project.GameProject;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

/**
 * User Repository Class
 * @author comcy
 *
 */
@Repository
public interface UserRepository extends CrudRepository<User, Integer>{
 
}
