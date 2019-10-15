package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/user")
public class UserController {
	
	@Autowired
	private UserService service;
	
	@RequestMapping(method = RequestMethod.GET)
	public List<User> getAllUsers(){
		return service.getAllUsers();
	}
	
	@RequestMapping(value = "/{userId}", method = RequestMethod.GET)
	public User getUserById(@PathVariable int userId) {
		return service.getUser(userId);
	}
	
	@RequestMapping(value = "/{userId}", method = RequestMethod.DELETE)
	public User deleteUserById(@PathVariable int userId) {
		User deleted = service.getUser(userId);
		service.deleteUser(userId);
		return deleted;
	}
	
	@RequestMapping(value = "/{userId}", method = RequestMethod.PUT)
	public User updateUserById(@PathVariable int userId, @RequestBody User user) {
		service.updateUser(userId, user);
		User newUser = service.getUser(userId);
		return newUser;
	}
	
	@RequestMapping(method = RequestMethod.POST)
	public void createUser(@RequestBody User user) {
		service.saveUser(user);
	}

}