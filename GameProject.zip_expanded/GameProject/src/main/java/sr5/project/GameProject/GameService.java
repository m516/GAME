package sr5.project.GameProject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class GameService {

    @Autowired
    private GameRepository repo;

    public List<Game> getAllGame(){
        return (List<Game>) repo.findAll();
    }

    public void saveGame(Game game){
        repo.save(game);
    }

    public Game getGame(int id){
        return repo.findById(id).get();
    }

    public void deleteGame(int id){
        repo.deleteById(id);
    }

    public void updateGame(int id, Game game){
        repo.save(game);
    }
}
