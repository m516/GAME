package sr5package.Service;

import org.springframework.stereotype.Service;
import sr5package.DataAccess.PlayerDao;
import sr5package.Entity.Player;

import java.util.Collection;

@Service
public class PlayerService {

    private PlayerDao playerDao;
    public Collection<Player> getAllPlayers(){
        return playerDao.getAllPlayers();
    }
}
