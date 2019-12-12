package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * User Service Class
 * @author comcy
 *
 */
@Service
public class UserService {

	/**
	 * userRepo is an instance of the User Repository Class 
	 */
	@Autowired 
	private UserRepository userRepo;
	
	/**
	 * Get All Users 
	 * @return the list of users from the repository
	 */
	public List<User> getAllUsers(){
		return (List<User>) userRepo.findAll();
	}
	
	/**
	 * Save User 
	 * Saves the user entity to the repository
	 * @param user
	 */
	public void saveUser(User user) {
		userRepo.save(user);
	}
	
	/**
	 * Get User
	 * @param id
	 * @return the User with the specific id from the repository
	 */
	public User getUser(int id) {
		return userRepo.findById(id).get();
	}
	
	/**
	 * Delete User
	 * Deletes the user with the specific if from the repository
	 * @param id
	 */
	public void deleteUser(int id) {
		userRepo.deleteById(id);
	}
	
	/**
	 * Update User
	 * Updates the user entity with the specific id from the repository with the given data
	 * @param id
	 * @param user
	 */
	public void updateUser(int id, User user) {
		userRepo.save(user);
	}
	
}
