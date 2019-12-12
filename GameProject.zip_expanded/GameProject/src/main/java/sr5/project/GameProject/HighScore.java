package sr5.project.GameProject;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * High Score Class 
 * @author comcy
 *
 */
@Entity
@Table(name = "high_score")
public class HighScore {
	private int Id;
	private String username;
	private int score;
	
	/**
	 * Empty High Score Constructor
	 */
	public HighScore() {
	}

	/**
	 * High Score Constructor
	 * with all the paramters
	 * @param id
	 * @param username
	 * @param score
	 */
	public HighScore(int id, String username, int score){
		this.Id = id;
		this.username = username;
		this.score = score;
	}

	/**
	 * Get Id
	 * @return Id
	 */
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	public int getId() {
		return Id;
	}

	/**
	 * Set Id
	 * @param id
	 */
	public void setId(int id) {
		Id = id;
	}

	/**
	 * Get Username
	 * @return username
	 */
	public String getUsername() {
		return username;
	}

	/**
	 * Set Username
	 * @param username
	 */
	public void setUsername(String username) {
		this.username = username;
	}

	/**
	 * Get Score
	 * @return
	 */
	public int getScore() {
		return score;
	}

	/**
	 * Set Score 
	 * @param score
	 */
	public void setScore(int score) {
		this.score = score;
	} 
	
	
}
