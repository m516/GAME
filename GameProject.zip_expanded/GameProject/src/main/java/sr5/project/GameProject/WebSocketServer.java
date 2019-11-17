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
//import javax.websocket.server.PathParam;
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
	public ArrayList<WebGames> game = new ArrayList<WebGames>();
	//public ArrayList<ArrayList<WebGameObject>> gameList = new ArrayList<ArrayList<WebGameObject>>();
	
	//***************************************START OLD METHODS****************************************************************
    private static Map<Session, String> sessionUsernameMap = new HashMap<>();
    private static Map<String, Session> usernameSessionMap = new HashMap<>();

    String username = "game";
    String player = "";
	//***************************************END OLD METHODS******************************************************************
    
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
    	if(sessionGameObjectMap.get(session) == null)
    	{
    		WebGameObject g = new WebGameObject(0,"0","0");
    		sessionGameObjectMap.put(session, g);
    		GameObjectSessionMap.put(g, session);
    	}
    	if(message.startsWith("C"))
    	{
    		//TODO Test
			String gameType = "" + message.charAt(1);
			int maxP = Integer.parseInt("" + message.charAt(2));
			int gameID = game.size();
			WebGames wg = new WebGames(gameType, maxP);
			game.add(wg);
			sendMessageToPArticularUser(session, "GID" + gameID +" " + message + "has been built");
			logger.info("GID" + gameID +" " +message + "has been built");
    	}
    	else if(message.startsWith("J"))
    	{
    		//TODO Test
			int gameID = Integer.parseInt(""  + message.charAt(1) + message.charAt(2));
			int gameType = message.charAt(4);
			sessionGameObjectMap.get(session).setGameType(gameType);
			String x = "" + message.charAt(5) + message.charAt(6);
			String y = "" + message.charAt(7) + message.charAt(8);
			
			if(game.size() > gameID)
			{
				sessionGameObjectMap.get(session).setX(x);
				sessionGameObjectMap.get(session).setY(y);
				sessionGameObjectMap.get(session).setGameID(gameID);
				
				boolean i = game.get(gameID).addPlayer(sessionGameObjectMap.get(session));
				if(i)
				{
					game.get(gameID).players.get(game.get(gameID).players.size() - 1).setpNum(game.get(gameID).players.size() - 1);
					sendMessageToPArticularUser(session, "Successfully Joined");
					logger.info("Successfully Joined");
				}
				else
				{
					sendMessageToPArticularUser(session, "Full, Try again");
					logger.info("Full, Try again");
				}
			}
			else
			{
				sendMessageToPArticularUser(session, "Game does not exist");
				logger.info("Game does not exist");
			}
				
    	}
    	else if(message.startsWith("R"))
    	{
    		//TODO Test
    		game.get(sessionGameObjectMap.get(session).getGameID()).removePlayer(sessionGameObjectMap.get(session).getPNum());
    		logger.info("Remove player");
    		
    	}
    	else if(message.startsWith("PL"))
    	{
    		//TODO Test
    		String s = game.get(sessionGameObjectMap.get(session).getGameID()).getPlayerLocations();
    		sendMessageToPArticularUser(session, s);
    		logger.info("Get player locations");
    		
    	}
    	else if(message.startsWith("OL"))
    	{
    		//TODO Test
    		String s = game.get(sessionGameObjectMap.get(session).getGameID()).getObjectLocations();
    		sendMessageToPArticularUser(session, s);
    		logger.info("Get object locations");
    	}
    	else if(message.startsWith("BL"))
    	{
    		//TODO Test
    		String s = "P" + game.get(sessionGameObjectMap.get(session).getGameID()).getObjectLocations() + "O" + game.get(sessionGameObjectMap.get(session).getGameID()).getObjectLocations();
    		sendMessageToPArticularUser(session, s);
    		logger.info("Get all locations");
    	}
    	else if(message.startsWith("S"))
    	{
    		//TODO Test
    		String s = game.get(sessionGameObjectMap.get(session).getGameID()).getScore();
    		sendMessageToPArticularUser(session, s);
    		logger.info("Get Score");
    	}
    	else if(message.startsWith("T"))
    	{
    		//TODO Test
    		if(game.get(sessionGameObjectMap.get(session).getGameID()).getState())
    		{
        		sendMessageToPArticularUser(session, "Game has started");
    		}
    		else
    		{
        		sendMessageToPArticularUser(session, "Game has not started");
    		}

    		logger.info("Get state");
    	}
    	else if(message.startsWith("G"))
    	{
    		//TODO Test
    		game.get(sessionGameObjectMap.get(session).getGameID()).setState(true);
    	}
    	else if(message.startsWith("ST"))
    	{
    		//TODO Test
    		StringBuilder sb = new StringBuilder(message);
    		sb.deleteCharAt(0);
    		sb.deleteCharAt(1);
    		String s1 = sb.toString();
    		game.get(sessionGameObjectMap.get(session).getGameID()).setScore(s1);
    	}
    	else if(message.startsWith("PM"))
    	{
    		//TODO Complete and Test
//    		int i = 1;
//    		String pID = "";
//    		String pX = "";
//    		String pY = "";
//    		while(i < message.length())
//    		{
//    			pID = "" + message.charAt(i) + message.charAt(i+1);
//    			pX = "" + message.charAt(i+2) + message.charAt(i+3);
//    			pY = "" + message.charAt(i+4) + message.charAt(i+5);
//    			sessionGameObjectMap.get(session).
//    		}
    	}
    	else if(message.startsWith("OM"))
    	{
    		//TODO
    	}
    	else if(message.startsWith("E"))
    	{
    		//TODO Add try catch blocks
    	}
    	else if(message.startsWith("N?"))
    	{
    		//TODO
    		sendMessageToPArticularUser(session, "Symbols\n");
    		sendMessageToPArticularUser(session, "# -> Game Type\n");
    		sendMessageToPArticularUser(session, "##-> Game id\n");
    		sendMessageToPArticularUser(session, "P -> Max Players\n");
    		sendMessageToPArticularUser(session, "XX-> X position\n");
    		sendMessageToPArticularUser(session, "YY-> Y postion\n");
    		sendMessageToPArticularUser(session, "ii-> Player/Object id\n\n");
    		
    		sendMessageToPArticularUser(session, "Commands\n");
    		sendMessageToPArticularUser(session, "C : C#P : START GAME\n");
    		sendMessageToPArticularUser(session, "J : J## : JOIN GAME\n");
    		sendMessageToPArticularUser(session, "R : R   : LEAVE GAME\n\n");
    		
    		sendMessageToPArticularUser(session, "PL: PL  : GET PLAYER LOCATIONS\n");
    		sendMessageToPArticularUser(session, "OL: OL  : GET OBJECT LOCATIONS\n");
    		sendMessageToPArticularUser(session, "BL: BL  : GET ALL LOCATIONS\n\n");
    		
    		sendMessageToPArticularUser(session, "PM: PMXXYY : SET PLAYER LOCATIONS --NEED MORE INFO--\n");
    		sendMessageToPArticularUser(session, "OM: OMXXYY : SET OBJECT LOCATIONS --NEED MORE INFO--\n\n");
    		
    		sendMessageToPArticularUser(session, "S : S  : GET SCORE\n");
    		sendMessageToPArticularUser(session, "ST: ST#: SET SCORE\n\n");

    		sendMessageToPArticularUser(session, "T : T  : GET STATE\n");
    		sendMessageToPArticularUser(session, "G : G  : START GAME\n\n");

    		sendMessageToPArticularUser(session, "N?: GET NEW OPCODES\n");
    		sendMessageToPArticularUser(session, "O?: GET OLD OPCODES\n\n");    		
    	}
    	else if(message.startsWith("W"))
    	{
    		//TODO
    	}
    	//***************************************START OLD METHODS****************************************************************
    	//Start with a "!" to join a game and define player number
    	else if(message.startsWith("!"))
    	{
    		username = "" + message.charAt(1); //The game number is stored in the first bit
    		player = "" + message.charAt(2);  //The player number is stored in the second bit
    		logger.info("Player " + player + " has joined game " + username);
    		
            sessionUsernameMap.put(session, username); //Log the session based off the game number
            usernameSessionMap.put(username, session); 
            
            logger.info("This is user " + sessionUsernameMap.size());
            
            broadcastOLD("Player " + player + " has joined game " + username);
    	}
    	//Send movement information using "."
    	else if(message.startsWith("."))
    	{
    		logger.info("Player "  + player + " is at location " + message.charAt(1) +message.charAt(2) + ", " + message.charAt(3) + message.charAt(4));
    		broadcastOLD("Player "  + player + " is at location " + message.charAt(1) +message.charAt(2) + ", " + message.charAt(3) + message.charAt(4));
    		sendMessageToPArticularUserOLD("P" + player + "@" + message.charAt(1) +message.charAt(2) + ", " + message.charAt(3) + message.charAt(4));
    	}
    	else if (message.startsWith("@")) // Direct message to a user using the format "@username <message>"
    	{
    		//String destUsername = message.split(" ")[0].substring(1); // don't do this in your code!
    		sendMessageToPArticularUserOLD("[DM] " + username + ": " + message);
    		sendMessageToPArticularUserOLD("[DM] " + username + ": " + message);
    	}
    	else if(message.startsWith("O?"))
    	{
    		sendMessageToPArticularUserOLD(
    				"\nJoin Game: !12: 1-> game number, 2-> the player number" + 
    				"\nPlayer Movement: .XXYY, XX-> X coordinate, YY-> Y coordinate");
    	}
    	else
    	{
    		broadcastOLD("Invalid Command Please enter N? or O? for instructions");
    	}
    	//***************************************END OLD METHODS******************************************************************

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
	private void sendMessageToPArticularUser(Session s, String message) 
    {	
		
    	try {
    		GameObjectSessionMap.get(sessionGameObjectMap.get(s)).getBasicRemote().sendText(message);
    		logger.info("sending dm to " + GameObjectSessionMap.get(sessionGameObjectMap.get(s)));
        } catch (IOException e) {
        	logger.info("Exception: " + e.getMessage().toString());
            e.printStackTrace();
        }
    }
	private void sendMessgeToGame(WebGames wg, String message)
	{
    	try {
    		for(int i = 0; i < wg.players.size(); i++)
    		{
    			GameObjectSessionMap.get(wg.players.get(i)).getBasicRemote().sendText(message);
    		}
    		logger.info("sending dm to " + wg);
        } catch (IOException e) {
        	logger.info("Exception: " + e.getMessage().toString());
            e.printStackTrace();
        }
	}
	//***************************************START OLD METHODS****************************************************************
	private void sendMessageToPArticularUserOLD(String message) 
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
    private static void broadcastOLD(String message) 
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
	//***************************************END OLD METHODS******************************************************************
}

