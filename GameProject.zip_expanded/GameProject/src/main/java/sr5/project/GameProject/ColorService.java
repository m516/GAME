package sr5.project.GameProject;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * Color Service Class
 * @author comcy
 *
 */
@Service
public class ColorService {

    @Autowired
    /**
     * repo is an instance of the Color Repository Class
     */
    private ColorRepository repo;

    /***
     * Get All Color
     * @return all color instances from the repo
     */
    public List<Color> getAllColor(){
        return (List<Color>) repo.findAll();
    }

    /**
     * Save Color
     * Saves the new color to the database from the repo
     * @param color
     */
    public void saveColor(Color color){
        repo.save(color);
    }

    /**
     * Get Color 
     * @param id
     * @return the Color with the assoicated id 
     */
    public Color getColor(int id){
        return repo.findById(id).get();
    }

    /**
     * Delete Color 
     * Deletes the given instance of the color with the corresponding id from the repo
     * @param id
     */
    public void deleteColor(int id){
        repo.deleteById(id);
    }

    /**
     * Update Color
     * Updates the Color instance from the repo with the give id to the new color 
     * @param id
     * @param color
     */
    public void updateColor(int id, Color color){
        repo.save(color);
    }
}
