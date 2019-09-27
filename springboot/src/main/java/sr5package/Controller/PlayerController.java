package sr5package.Controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import sr5package.Entity.Player;
import sr5package.Service.PlayerService;
import java.util.Collection;

@RestController
@RequestMapping("/players")
public class PlayerController {

    @Autowired
    private PlayerService playerService;

    @RequestMapping(method = RequestMethod.GET)
    public Collection<Player> getAllPlayers(){
        return playerService.getAllPlayers();
    }
    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public Player getPlayerById(@PathVariable int id){
        return playerService.getPlayerById(id);
    }
    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public void deletePlayerById(@PathVariable int id){
        playerService.removePlayerById(id);
    }
    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public void updatePlayer(@RequestBody Player player, @PathVariable int id){
        playerService.updatePlayer(player, id);
    }
}
