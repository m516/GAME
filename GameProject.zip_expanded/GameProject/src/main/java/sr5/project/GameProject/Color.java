package sr5.project.GameProject;

import javax.persistence.*;

@Entity
@Table(name = "color")
public class Color {
    private int id;
    private String name;
    private String hex;

    public Color() {
    }

    public Color(int id, String name, String hex) {
        this.id = id;
        this.name = name;
        this.hex = hex;
    }

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getHex() {
        return hex;
    }

    public void setHex(String hex) {
        this.hex = hex;
    }
}
