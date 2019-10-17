package sr5package.Service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import sr5package.DataAccess.PlayerDao;
import sr5package.Entity.Player;

import java.util.Collection;

@Service
public class PlayerService {

    @Autowired
    private PlayerDao playerDao;
    public Collection<Player> getAllPlayers(){
        return playerDao.getAllPlayers();
    }
    public Player getPlayerById(int id){
        return this.playerDao.getPlayerById(id);
    }

    public void removePlayerById(int id) {
        this.playerDao.deletePlayerById(id);
    }
    public void updatePlayer(Player player, int id){
//        System.out.println("FirstName: " + player.getFirstName());
//        System.out.println("Username: " + player.getUsername());
//        System.out.println("LastName: " + player.getLastName());
//        System.out.println("Id: " + player.getPlayerId());
        this.playerDao.updatePlayer(player, id);
    }


    public void createPlayer(Player player) {
        this.playerDao.createPlayer(player);
    }
}
