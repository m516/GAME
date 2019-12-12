package sr5.project.GameProject;

import javax.persistence.*;

/**
 * Color Entity 
 * @author comcy
 *
 */
@Entity
@Table(name = "color")
public class Color {
	/**
	 * id is the color id 
	 */
    private int id;
    /**
     * name is the name of the Color 
     */
    private String name;
    /**
     * hex is the String representation of the hex variable 
     */
    private String hex;

    /**
     * Empty Constructor 
     */
    public Color() {
    }

    /**
     * Color Constructor 
     * @param id
     * @param name
     * @param hex
     */
    public Color(int id, String name, String hex) {
        this.id = id;
        this.name = name;
        this.hex = hex;
    }

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    /**
     * Get Id 
     * @return id
     */
    public int getId() {
        return id;
    }

    /**
     * Set Id
     * @param id
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * Get Name
     * @return name
     */
    public String getName() {
        return name;
    }

    /**
     * Set Name
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * Get Hex
     * @return hex 
     */
    public String getHex() {
        return hex;
    }

    /**
     * Set Hex
     * @param hex
     */
    public void setHex(String hex) {
        this.hex = hex;
    }
}
