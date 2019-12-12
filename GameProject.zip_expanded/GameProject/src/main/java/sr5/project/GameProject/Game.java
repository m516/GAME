package sr5.project.GameProject;

import javax.persistence.*;
/**
 * Game Class
 * @author comcy
 *
 */
@Entity
@Table(name = "game")
public class Game {
	/**
	 * Id is a unique identifier for the game 
	 */
    private int id;
    /**
     * Name is the name for the actual game saved as a String
     */
    private String name;
    /**
     * Version is the version of the game 
     */
    private double version;
    /**
     * Filepath is the location of the game in the file system
     */
    private String filepath;

    /**
     * Game Empty Constructor
     */
    public Game(){
    }

    /**
     * Game Constructor with all parameters
     * @param id
     * @param name
     * @param version
     * @param filepath
     */
    public Game(int id, String name, double version, String filepath){
        this.id = id;
        this.name = name;
        this.version = version;
        this.filepath = filepath;
    }

    /**
     * Get Id
     * @return id
     */
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public int getId(){
        return id;
    }

    /**
     * Set Id
     * @param id
     */
    public void setId(int id){
        this.id = id;
    }

    /**
     * Get Name
     * @return name
     */
    public String getName(){
        return name;
    }

    /**
     * Set Name
     * @param name
     */
    public void setName(String name){
        this.name = name;
    }

    /**
     * Get Version
     * @return version
     */
    public double getVersion(){
        return version;
    }

    /**
     * Set Version
     * @param version
     */
    public void setVersion(double version){
        this.version = version;
    }

    /**
     * Get Filepath
     * @return filepath
     */
    public String getFilepath(){
        return filepath;
    }

    /**
     * Set Filepath
     * @param filepath
     */
    public void setFilepath(String filepath){
        this.filepath = filepath;
    }













}
