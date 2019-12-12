package sr5.project.GameProject;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

/**
 * Color Repository Class
 * @author comcy
 *
 */
@Repository
public interface ColorRepository extends CrudRepository<Color, Integer> {

}
