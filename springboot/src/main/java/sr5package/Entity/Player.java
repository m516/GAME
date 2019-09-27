package sr5package.Entity;

public class Player {
    private int player_id;
    private String first_name;
    private String last_name;
    private String username;

    public Player(int player_id, String first_name, String last_name, String username){
        this.player_id = player_id;
        this.first_name = first_name;
        this.last_name = last_name;
        this.username = username;
    }

    public Player(){}

    public int getPlayerId(){
        return player_id;
    }

    public void setPlayerId(int player_id){
        this.player_id = player_id;
    }

    public String getFirstName(){
        return first_name;
    }

    public void setFirstName(String first_name){
        this.first_name = first_name;
    }

    public String getLastName(){
        return last_name;
    }
    public void setLastName(String last_name) {
        this.last_name = last_name;
    }

    public String getUsername(){
        return username;
    }
    public void setUsername(String username){
        this.username = username;
    }
}
