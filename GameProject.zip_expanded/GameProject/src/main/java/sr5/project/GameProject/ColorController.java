package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 * Color Controller Class 
 * @author comcy
 *
 */
@RestController
@RequestMapping("/color")
public class ColorController {

    @Autowired
    /**
     * service is the instance of the Color Service class
     */
    private ColorService service;

    /**
     * Get All Color 
     * @return all color from the service class
     */
    @RequestMapping(method = RequestMethod.GET)
    public List<Color> getAllColor() {
        return service.getAllColor();
    }

    /**
     * Get Color By Id
     * @param id
     * @return color from the service class with the specified id 
     */
    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public Color getColorById(@PathVariable int id){
        return service.getColor(id);
    }

    /**
     * Delete Color By Id
     * @param id
     * @param color
     * @return the deleted color instance from the service class
     */
    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public Color deleteColorById(@PathVariable int id, @RequestBody Color color){
        Color deleted = service.getColor(id);
        service.deleteColor(id);
        return deleted;
    }

    /**
     * Update Color By Id
     * @param id
     * @param color
     * @return the updated Color instance with the given id
     */
    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public Color updateColorById(@PathVariable int id, @RequestBody Color color){
        service.updateColor(id, color);
        return service.getColor(id);
    }

    /**
     * Create Color
     * Has no return value but creates a new color and saves it to the database using the service class
     * @param color
     */
    @RequestMapping(method = RequestMethod.POST)
    public void createColor(@RequestBody Color color){
        service.saveColor(color);
    }

}
