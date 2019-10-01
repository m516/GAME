package sr5.project.GameProject;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
public class HighScoreController {
	@Autowired
	private HighScoreService service;
	
	@RequestMapping("/")
	public String viewHomePage(Model model) {
		List<HighScore> listHighScores = service.listAll();
		model.addAttribute("listHighScores", listHighScores);
		
		return "index";
	}
}
