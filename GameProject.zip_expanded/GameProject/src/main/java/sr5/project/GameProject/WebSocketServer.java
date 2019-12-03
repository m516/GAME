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
//import org.springframework.web.bind.annotation.RequestMapping;
/**
 * This class runs the connection between different players while 
 * completing against each other in real time.
 * 
 * @author Parker Larsen
 */
@ServerEndpoint("/")
@Component
public class WebSocketServer {

	private static volatile Map<Session, WebGameObject> sessionGameObjectMap = new HashMap<>();
	private static volatile Map<WebGameObject, Session> GameObjectSessionMap = new HashMap<>();
	
	private static volatile ArrayList<WebGames> game = new ArrayList<WebGames>();
	
	//***************************************START OLD METHODS****************************************************************
    private static volatile Map<Session, String> sessionUsernameMap = new HashMap<>();
    private static volatile Map<String, Session> usernameSessionMap = new HashMap<>();

    private String username = "game";
    private String player = "";
	//***************************************END OLD METHODS******************************************************************
    
    private final Logger logger = LoggerFactory.getLogger(WebSocketServer.class);
    
    private String newInstructions = 
    		"Symbols\n"
    	    +"T -> Game Type\n"
    	    + "##-> Game id\n"
    	    + "P -> Max Players\n"
    	    + "XXXX-> X position\n"
    	    + "YYYY-> Y postion\n"
    	    + "ii-> Player/Object id\n\n"
    		
    	    + "Commands\n"
    	    + "C : C#P         : START GAME\n"
    	    + "J : J##TXXXXYYYY: JOIN GAME\n"
    	    + "R : R           : LEAVE GAME\n\n"
    		
    	    + "PL: PL  : GET PLAYER LOCATIONS\n"
    	    + "OL: OL  : GET OBJECT LOCATIONS\n"
    	    + "BL: BL  : GET ALL LOCATIONS\n\n"
    		
    	    + "PM: PMXXXXYYYY : SET PLAYER LOCATIONS\n"
    	    + "OM: OMXXXXYYYY : SET OBJECT LOCATIONS --One Object only--\n\n"
    		
    	    + "S : S  : GET SCORE\n"
    	    + "ST: STT: SET SCORE\n\n"

    	    + "T : T  : GET STATE\n"
    	    + "G : G  : START GAME\n\n"
    		
    	    + "GS : GS  : RETURNS THE CURRENT GAMES\n"
    	    + "GSO: GSO : RETURNS THE CURRENT GAMES THAT CAN BE JOINED\n\n"
    		
    	    + "W : W##  : JOINS A GAME AS A SPECTATOR\n\n"

    	    + "N?: GET NEW OPCODES\n"
    	    + "O?: GET OLD OPCODES\n\n";
    
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
    	//Create a session for the player if the player does not already have one
    	if(sessionGameObjectMap.get(session) == null)
    	{
    		WebGameObject g = new WebGameObject(0,"0","0");
    		sessionGameObjectMap.put(session, g);
    		GameObjectSessionMap.put(g, session);
    	}
    	//List all the open games
    	if(message.startsWith("GSO"))
    	{
    		getGames(false, session);
    	}
    	//List all the games
    	else if(message.startsWith("GS"))
    	{
    		getGames(true, session);
    	}
    	//Create a new game
    	else if(message.startsWith("C"))
    	{
    		try {
				String gameType = "" + message.charAt(1);
				int maxP = Integer.parseInt("" + message.charAt(2));
				int gameID = game.size();
				game.add(new WebGames(gameType, maxP));
				sendMessageToPArticularUser(session, String.format("GID%02d %s has been built", gameID, message));
				logger.info(String.format("GID%02d %s has been built", gameID, message));
    		}
    		catch(Exception e)
    		{
				sendMessageToPArticularUser(session, "Invalid command, Please use: J :C : C#P : START GAME\n");
    		}
    	}
    	//Join a game
    	else if(message.startsWith("J"))
    	{
    		try {
				int gameID = Integer.parseInt(message.substring(1,3));
				int gameType = message.charAt(3);
				sessionGameObjectMap.get(session).setGameType(gameType);
				String x = message.substring(5,8);
				String y = message.substring(8, 12);
				
				if(game.size() > gameID)
				{
					sessionGameObjectMap.get(session).setX(x);
					sessionGameObjectMap.get(session).setY(y);
					sessionGameObjectMap.get(session).setGameID(gameID);
					
					if(game.get(gameID).addPlayer(sessionGameObjectMap.get(session)))
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
    		catch(Exception e)
    		{
				sendMessageToPArticularUser(session, "Invalid command, Please use: J : J##TXXXXYYYY: JOIN GAME\n");
    		}
				
    	}
    	//Remove a player
    	else if(message.startsWith("R"))
    	{
    		game.get(sessionGameObjectMap.get(session).getGameID()).removePlayer(sessionGameObjectMap.get(session).getPNum());
    		logger.info("Remove player");
    		
    	}
    	//Get player locations
    	else if(message.startsWith("PL"))
    	{
    		sendMessageToPArticularUser(session, game.get(sessionGameObjectMap.get(session).getGameID()).getPlayerLocations());
    		logger.info("Get player locations");
    	}
    	//Get object locations
    	else if(message.startsWith("OL"))
    	{
    		sendMessageToPArticularUser(session, game.get(sessionGameObjectMap.get(session).getGameID()).getObjectLocations());
    		logger.info("Get object locations");
    	}
    	//Get all locations
    	else if(message.startsWith("BL"))
    	{
    		sendMessageToPArticularUser(session, "P" + game.get(sessionGameObjectMap.get(session).getGameID()).getObjectLocations() + "O" + game.get(sessionGameObjectMap.get(session).getGameID()).getObjectLocations());
    		logger.info("Get all locations");
    	}
    	//Set Score
    	else if(message.startsWith("ST"))
    	{
    		message = message.substring(2);
    		game.get(sessionGameObjectMap.get(session).getGameID()).setScore(message);
    	}
    	else if(message.startsWith("S"))
    	{
    		sendMessageToPArticularUser(session, game.get(sessionGameObjectMap.get(session).getGameID()).getScore());
    		logger.info("Get Score");
    	}
    	//Get game Status
    	else if(message.startsWith("T"))
    	{
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
    	//Start game
    	else if(message.startsWith("G"))
    	{
    		game.get(sessionGameObjectMap.get(session).getGameID()).setState(true);
    	}
    	else if(message.startsWith("PM"))
    	{
    		sessionGameObjectMap.get(session).setPosition(message);
    	}
    	else if(message.startsWith("OM"))
    	{
    		game.get(sessionGameObjectMap.get(session).getGameID()).setObjectMovement(0, message.substring(2,6), message.substring(7,11));
    	}
    	else if(message.startsWith("N?"))
    	{
    	    sendMessageToPArticularUser(session, newInstructions);    		
    	}
    	else if(message.startsWith("W"))
    	{
    		try {
	    		int gameID  = Integer.parseInt(message.substring(1,3));
	    		sessionGameObjectMap.get(session).setGameID(gameID);
	    		game.get(gameID).spectators.add(sessionGameObjectMap.get(session));
	    		game.get(gameID).spectators.get(game.get(gameID).spectators.size() - 1).setpNum(game.get(gameID).spectators.size() - 1);
    		}
    		catch(Exception e)
    		{
    			sendMessageToPArticularUser(session,"Invalid Command please use W : W##  : JOINS A GAME AS A SPECTATOR\n\n");
    		}
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
    		logger.info("Player "  + player + " is at location " + message.substring(1,5));
    		broadcastOLD("Player "  + player + " is at location " + message.substring(1,5));
    		sendMessageToPArticularUserOLD("P" + player + "@" + message.substring(1,5));
    	}
    	else if (message.startsWith("@")) // Direct message to a user using the format "@username <message>"
    	{
    		//String destUsername = message.split(" ")[0].substring(1); // don't do this in your code!
    		sendMessageToPArticularUserOLD("[DM] " + username + ": " + message);
    		sendMessageToPArticularUserOLD("[DM] " + username + ": " + message);
    	}
    	else if(message.startsWith("O?"))
    	{
    		String s = "";
    		s+= "\nJoin Game: !12: 1-> game number, 2-> the player number";
    		s+= "\nPlayer Movement: .XXYY, XX-> X coordinate, YY-> Y coordinate";
    		sendMessageToPArticularUserOLD(s);

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
    	
    	//***************************************START OLD METHODS****************************************************************
    	String username = sessionUsernameMap.get(session);
    	sessionUsernameMap.remove(session);
    	usernameSessionMap.remove(username);
    	//***************************************END OLD METHODS******************************************************************
    	
    	WebGameObject wgo = sessionGameObjectMap.get(session);
    	sessionGameObjectMap.remove(session);
    	GameObjectSessionMap.remove(wgo);
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
//	private void sendMessageToAll(Session session, String message) throws IOException
//	{
//		message = "." + message;
//		for(int i = 0; i < players.size(); i++)
//		{
//			if(players.get(i) != sessionGameObjectMap.get(session))
//			{
//				GameObjectSessionMap.get(players.get(i)).getBasicRemote().sendText(message);
//			}
//		}
//	}
//    private static void broadcastNew(String message) 
//  	      throws IOException 
//  {	  
//  	sessionGameObjectMap.forEach((session, username) -> {
//  		synchronized (session) {
//	            try {
//	                session.getBasicRemote().sendText(message);
//	            } catch (IOException e) {
//	                e.printStackTrace();
//	            }
//	        }
//	    });
//	}
	//***************************************START OLD METHODS****************************************************************
	private void sendMessageToPArticularUserOLD(String message) 
    {			
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
    private void getGames(Boolean includePlaying, Session session)
    {
    	String state = "O";
        	
    	for(int i = 0; i < game.size(); i++)
    	{
    		if(!game.get(i).getState())
    		{
    			sendMessageToPArticularUser(session, String.format("%02d%s%d/%d", i, state, game.get(i).getNumPlayers(), game.get(i).getMaxPlayers()));
    		}
    	}
    	if(includePlaying)
    	{
    		state = "P";
        	for(int i = 0; i < game.size(); i++)
        	{
        		if(game.get(i).getState())
        		{
        			sendMessageToPArticularUser(session, String.format("%02d%s%d/%d", i, state, game.get(i).getNumPlayers(), game.get(i).getMaxPlayers()));
        		}
        	}
    	}
    }  
}


