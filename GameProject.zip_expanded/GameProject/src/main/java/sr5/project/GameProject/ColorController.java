package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/color")
public class ColorController {

    @Autowired
    private ColorService service;

    @RequestMapping(method = RequestMethod.GET)
    public List<Color> getAllColor() {
        return service.getAllColor();
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.GET)
    public Color getColorById(@PathVariable int id){
        return service.getColor(id);
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.DELETE)
    public Color deleteColorById(@PathVariable int id, @RequestBody Color color){
        Color deleted = service.getColor(id);
        service.deleteColor(id);
        return deleted;
    }

    @RequestMapping(value = "/{id}", method = RequestMethod.PUT)
    public Color updateColorById(@PathVariable int id, @RequestBody Color color){
        service.updateColor(id, color);
        return service.getColor(id);
    }

    @RequestMapping(method = RequestMethod.POST)
    public void createColor(@RequestBody Color color){
        service.saveColor(color);
    }

}
