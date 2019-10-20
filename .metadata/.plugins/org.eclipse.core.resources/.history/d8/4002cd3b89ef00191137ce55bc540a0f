package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserService {

	@Autowired
	private UserRepository userRepo;
	
	public List<User> getAllUsers(){
		return (List<User>) userRepo.findAll();
	}
	
	public void saveUser(User user) {
		userRepo.save(user);
	}
	
	public User getUser(int id) {
		return userRepo.findById(id).get();
	}
	
	public void deleteUser(int id) {
		userRepo.deleteById(id);
	}
	
	public void updateUser(int id, User user) {
		userRepo.save(user);
	}
	
}
