package sr5package.DataAccess;

import sr5package.Entity.Player;
import java.util.Map;
import java.util.HashMap;
import java.util.Collection;

public class PlayerDao {
    private static Map<Integer, Player> players;
    static {
        players = new HashMap<Integer, Player>(){
            {
                put(1, new Player(1, "Isaac", "Spanier", "YodaSpock"));
                put(1, new Player(2, "Parker", "Larsen", "RockClimber42"));
                put(1, new Player(3, "Micah", "Mundy", "ItsElectric"));
                put(1, new Player(4, "Ashton", "Nelson", "AshCatchEmAll"));
            }
        };
    }

    public Collection<Player> getAllPlayers(){
        return this.players.values();
    }
}
