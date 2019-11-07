<<<<<<< HEAD
package sr5.project.GameProject;
=======
package sr5.project.GameProject; 
>>>>>>> frontend-network-implementation

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.socket.server.standard.ServerEndpointExporter;
/**
 * 
 * @author Vamsi Krishna Calpakkam
 *
 */
@Configuration 
public class WebSocketConfig {  
    @Bean  
    public ServerEndpointExporter serverEndpointExporter(){  
        return new ServerEndpointExporter();  
    }  
} 
