package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/ponggame")
public class PongGameController {

    @Autowired
    private PongGameService service;

    @RequestMapping(method = RequestMethod.GET)
    public List<PongGame> getAllPongGame(){
        return service.getAllPongGame();
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public PongGame getPongGameById(@PathVariable int id) {
        return service.getPongGame(id);
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public PongGame deletePongGameById(@PathVariable int id) {
        PongGame deleted = service.getPongGame(id);
        service.deletePongGame(id);
        return deleted;
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public PongGame updatePongGameById(@PathVariable int id, @RequestBody PongGame pongGame) {
        service.updatePongGame(id, pongGame);
        return service.getPongGame(id);
    }

    @RequestMapping(method = RequestMethod.POST)
    public void createPongGame(@RequestBody PongGame pongGame) {
        service.savePongGame(pongGame);
    }
}

