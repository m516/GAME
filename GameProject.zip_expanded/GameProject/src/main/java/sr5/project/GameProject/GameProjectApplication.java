package sr5.project.GameProject;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.ComponentScans;

@SpringBootApplication
@ComponentScan(basePackages= {"WebSocket"})
public class GameProjectApplication {

	public static void main(String[] args) {
		SpringApplication.run(GameProjectApplication.class, args);
	}

}
