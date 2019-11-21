package sr5.project.GameProject;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "users") 
public class User {
	private int Id;
	private String name;
	private int userLevel;
	private String address;
	
	public User() {
	}

	public User(int id, String name, int userLevel, String address){
		this.Id = id;
		this.name = name;
		this.userLevel = userLevel;
		this.address = address;
	}
	
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	public int getId() {
		return Id; 
	}
	
	public void setId(int uid) {
		Id = uid; 
	}
	
	public String getUsername() {
		return name; 
	}
	
	public void setUsername(String username) {
		this.name = username;
	}
	
	public String getAddress() {
		return address; 
	}
	
	public void setAddress(String address) {
		this.address = address;
	}
	
	public int getUserLevel() {
		return userLevel;
	}
	
	public void setUserLevel(int userLevel) {
		this.userLevel = userLevel;
	}
}
