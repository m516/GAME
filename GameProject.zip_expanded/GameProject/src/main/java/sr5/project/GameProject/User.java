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
	private int user_level;
	
	public User() {
	}

	public User(int id, String name, int user_level){
		this.Id = id;
		this.name = name;
		this.user_level = user_level;
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
	
	
//	public java.util.Date getDateCreated(){
//		return dateCreated;
//	}
//	
//	public void setDateCreated(java.util.Date dateCreated) {
//		this.dateCreated = dateCreated;
//	}
	
	public int getUserLevel() {
		return user_level;
	}
	
	public void setUserLevel(int userLevel) {
		this.user_level = userLevel;
	}
}
