package sr5package.Controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RestController;
import sr5package.Entity.Player;
import sr5package.Service.PlayerService;

import java.util.Collection;

@RestController
public class PlayerController {
    @Autowired
    private PlayerService playerService;

    public Collection<Player> getAllPlayers(){
        return playerService.getAllPlayers();
    }
}
