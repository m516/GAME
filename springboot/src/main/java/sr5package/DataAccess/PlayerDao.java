package sr5package.DataAccess;

import org.springframework.stereotype.Repository;
import sr5package.Entity.Player;
import java.util.Map;
import java.util.HashMap;
import java.util.Collection;

@Repository
public class PlayerDao {
    private static Map<Integer, Player> players;
    static {
        players = new HashMap<Integer, Player>(){
            {
                put(1, new Player(1, "Isaac", "Spanier", "YodaSpock"));
                put(2, new Player(2, "Parker", "Larsen", "RockClimber42"));
                put(3, new Player(3, "Micah", "Mundy", "ItsElectric"));
                put(4, new Player(4, "Ashton", "Nelson", "AshCatchEmAll"));
            }
        };
    }

    public Collection<Player> getAllPlayers(){
        return this.players.values();
    }
    public Player getPlayerById(int id){
        return this.players.get(id);
    }
    public void deletePlayerById(int id) {
        this.players.remove(id);
    }

    //FIGURE OUT WHY UPDATING ONLY ONE VALUES SETS OTHERS TO NULL
    public void updatePlayer(Player player, int id){
        Player p = players.get(id);
        if(player.getUsername() != null) {
            p.setFirstName(player.getFirstName());
        }
        if(player.getLastName() != null) {
            p.setLastName(player.getLastName());
        }
        if(player.getFirstName() != null) {
            p.setUsername(player.getUsername());
        }
        players.put(id, p);
    }

    public void createPlayer(Player player) {
        this.players.put(player.getPlayerId(), player);
    }
}
;