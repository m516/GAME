package sr5.project.GameProject;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import javax.websocket.OnClose;
import javax.websocket.OnError;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
import javax.websocket.Session;
import javax.websocket.server.PathParam;
import javax.websocket.server.ServerEndpoint;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;
/**
 * This class runs the connection between different players while 
 * completing against each other in real time.
 * 
 * @author Parker Larsen
 */
@ServerEndpoint("/")
@Component
public class WebSocketServer {
	
	// Store all socket session and their corresponding username.
//    private static Map<Session, String> sessionUsernameMap = new HashMap<>();
//    private static Map<String, Session> usernameSessionMap = new HashMap<>();

	private static Map<Session, WebGameObject> sessionGameObjectMap = new HashMap<>();
	private static Map<WebGameObject, Session> GameObjectSessionMap = new HashMap<>();
    
	public ArrayList<WebGameObject> players = new ArrayList<WebGameObject>();
	public ArrayList<WebGameObject> game = new ArrayList<WebGameObject>();
	//public ArrayList<ArrayList<WebGameObject>> gameList = new ArrayList<ArrayList<WebGameObject>>();
    
    private final Logger logger = LoggerFactory.getLogger(WebSocketServer.class);
    
    @OnOpen
    /**
     * This class is used for the initial connection between the client and websocket
     * @param session the session for this user
     * @throws IOException 
     */
    public void onOpen(Session session) throws IOException
    {
        logger.info("New Player entered into Open");
    }
 
    @OnMessage
    /**
     * This class allows the user to join a game, define which player they are, and send
     * player locations
     * @param session the session for the user
     * @param message the message sent from the user
     * @throws IOException
     */
    public void onMessage(Session session, String message) throws IOException
    {
    	
    	
    	
    	
    	
    	
    	
    	
    	logger.info("Entered into Message: Got Message:"+message);
    	
    	//Start with a "!" to join a game and define player number
    	if(message.startsWith("!"))
    	{
    		//String playerNum = players.size() + "";
    		WebGameObject  v1 = new WebGameObject(message);
    		players.add(v1);
    		
    		sessionGameObjectMap.put(session, v1); //Log the session based off the game number
    		GameObjectSessionMap.put(v1, session);
            
            //logger.info("This is user " + sessionUsernameMap.size());
            
            broadcast("Player " + v1.getPNum() + " has joined game " + v1.getGameID());
    	}
    	//Send movement information using "."
    	if(message.startsWith("."))
    	{
    		//logger.info("Player "  + player + " is at location " + message.charAt(1) +message.charAt(2) + ", " + message.charAt(3) + message.charAt(4));
    		//broadcast("Player "  + player + " is at location " + message.charAt(1) +message.charAt(2) + ", " + message.charAt(3) + message.charAt(4));
    		//sendMessageToPArticularUser("P" + player + "@" + message.charAt(1) +message.charAt(2) + ", " + message.charAt(3) + message.charAt(4));
    		sessionGameObjectMap.get(session).setX("" +message.charAt(1)+ message.charAt(2));
    		sessionGameObjectMap.get(session).setY("" + message.charAt(3) + message.charAt(4));
    	}
    	if (message.startsWith("@")) // Direct message to a user using the format "@username <message>"
    	{
    		sessionGameObjectMap.get(session).getGameID()
    		//String destUsername = message.split(" ")[0].substring(1); // don't do this in your code!
    		//sendMessageToPArticularUser("[DM] " + username + ": " + message);
    		//sendMessageToPArticularUser("[DM] " + username + ": " + message);
    	}
    	if(message.startsWith("?"))
    	{
    		sendMessageToPArticularUser(
    				"\nJoin Game: !12: 1-> game number, 2-> the player number" + 
    				"\nPlayer Movement: .XXYY, XX-> X coordinate, YY-> Y coordinate");
    	}
    	else // Message to whole chat
    	{
	    	broadcast(message + "has been successfully sent");
    	}
    }
 
    @OnClose
    /**
     * This class closes the session after the user is done.
     * @param session session for the user
     * @throws IOException
     */
    public void onClose(Session session) throws IOException
    {
    	logger.info("Entered into Close");
    	
    	//String username = sessionUsernameMap.get(session);
    	//sessionUsernameMap.remove(session);
    	//usernameSessionMap.remove(username);
        
    	//String message= username + " disconnected";
        //broadcast(message);
    }
 
    @OnError
    /**
     * This class displays an error message in the logger when present
     * @param session session of the user
     * @param throwable
     */
    public void onError(Session session, Throwable throwable) 
    {
        // Do error handling here
    	logger.info("Entered into Error");
    }
    /**
     * Send message to a specific session or game
     * @param message message to send to the session
     */
	private void sendMessageToPArticularUser(String message) 
    {	
		//String username = "user";
		
    	try {
    		usernameSessionMap.get(username).getBasicRemote().sendText(message);
    		logger.info("sending dm to " + usernameSessionMap.get(username));
        } catch (IOException e) {
        	logger.info("Exception: " + e.getMessage().toString());
            e.printStackTrace();
        }
    }
    /**
     * Send message to all the sessions that are being used by the websocket
     * @param message message to be sent
     * @throws IOException
     */
    private static void broadcast(String message) 
    	      throws IOException 
    {	  
    	sessionUsernameMap.forEach((session, username) -> {
    		synchronized (session) {
	            try {
	                session.getBasicRemote().sendText(message);
	            } catch (IOException e) {
	                e.printStackTrace();
	            }
	        }
	    });
	}
}

