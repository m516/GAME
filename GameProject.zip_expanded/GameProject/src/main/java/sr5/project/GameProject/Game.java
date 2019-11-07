package sr5.project.GameProject;

import javax.persistence.*;

@Entity
@Table(name = "game")
public class Game {
    private int id;
    private String name;
    private double version;
    private String filepath;

    public Game(){
    }

    public Game(int id, String name, double version, String filepath){
        this.id = id;
        this.name = name;
        this.version = version;
        this.filepath = filepath;
    }

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public int getId(){
        return id;
    }

    public void setId(int id){
        this.id = id;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public double getVersion(){
        return version;
    }

    public void setVersion(double version){
        this.version = version;
    }

    public String getFilepath(){
        return filepath;
    }

    public void setFilepath(String filepath){
        this.filepath = filepath;
    }













}
