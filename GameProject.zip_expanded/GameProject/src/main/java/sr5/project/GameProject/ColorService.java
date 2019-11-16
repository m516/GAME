package sr5.project.GameProject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ColorService {

    @Autowired
    private ColorRepository repo;

    public List<Color> getAllColor(){
        return (List<Color>) repo.findAll();
    }

    public void saveColor(Color color){
        repo.save(color);
    }

    public Color getColor(int id){
        return repo.findById(id).get();
    }

    public void deleteColor(int id){
        repo.deleteById(id);
    }

    public void updateColor(int id, Color color){
        repo.save(color);
    }
}
