package sr5.project.GameProject;


import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class PongGameService {

    @Autowired
    private PongGameRepository repo;

    public List<PongGame> getAllPongGame(){
        return (List<PongGame>) repo.findAll();
    }

    public void savePongGame(PongGame pongGame) {
        repo.save(pongGame);
    }

    public PongGame getPongGame(int id) {
        return repo.findById(id).get();
    }

    public void deletePongGame(int id) {
        repo.deleteById(id);
    }

    public void updatePongGame(int id, PongGame pongGame) {
        repo.save(pongGame);
    }


}
