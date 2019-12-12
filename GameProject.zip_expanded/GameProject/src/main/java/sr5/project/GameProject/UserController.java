package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 * User Controller Class
 * @author comcy
 *
 */
@RestController
@RequestMapping("/user") 
public class UserController {
	
	/**
	 * service is the instance of the UserService 
	 */
	@Autowired
	private UserService service;
	
	/**
	 * Get All Users 
	 * @return the list of users from the service class
	 */
	@RequestMapping(method = RequestMethod.GET)
	public List<User> getAllUsers(){
		return service.getAllUsers();
	}
	
	/**
	 * Get User By Id
	 * @param userId
	 * @return the specific user entity from the service class
	 */
	@RequestMapping(value = "/{userId}", method = RequestMethod.GET)
	public User getUserById(@PathVariable int userId) {
		return service.getUser(userId);
	}
	
	/**
	 * Delete User By Id
	 * @param userId
	 * @return the deleted entity from the service
	 */
	@RequestMapping(value = "/{userId}", method = RequestMethod.DELETE)
	public User deleteUserById(@PathVariable int userId) {
		User deleted = service.getUser(userId);
		service.deleteUser(userId);
		return deleted;
	}
	
	/**
	 * Update User By Id
	 * @param userId
	 * @param user
	 * @return the updated user entity after updating the service class
	 */
	@RequestMapping(value = "/{userId}", method = RequestMethod.PUT)
	public User updateUserById(@PathVariable int userId, @RequestBody User user) {
		service.updateUser(userId, user);
		User newUser = service.getUser(userId);
		return newUser;
	}
	
	/**
	 * Create User
	 * Creates a new user, and auto-increments the id, and sends that user to the service class
	 * @param user
	 */
	@RequestMapping(method = RequestMethod.POST)
	public void createUser(@RequestBody User user) {
		//System.out.println(user.getAddress());
		service.saveUser(user);
	}
	

}
