package sr5.project.GameProject;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "high_score")
public class HighScore {
	private int Id;
	private String username;
	private int score;
	
	public HighScore() {
	}

    public HighScore(int i, String user, int i1)
	{
		setUsername(user);
		setId(i);
		setScore(i1);
    }

    @Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	public int getId() {
		return Id;
	}

	public void setId(int id) {
		Id = id;
	}

	public String getUsername() {
		return username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	public int getScore() {
		return score;
	}

	public void setScore(int score) {
		this.score = score;
	} 
	
	
}