package sr5.project.GameProject;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import javax.websocket.OnClose;
import javax.websocket.OnError;
import javax.websocket.OnMessage;
import javax.websocket.OnOpen;
//import javax.websocket.String;
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
public class WebSocketServerS {

	private static Map<String, WebGameObject> StringGameObjectMap = new HashMap<>();
	private static Map<WebGameObject, String> GameObjectStringMap = new HashMap<>();
    
	public ArrayList<WebGameObject> players = new ArrayList<WebGameObject>();
	public ArrayList<WebGames> game = new ArrayList<WebGames>();
	
	//***************************************START OLD METHODS****************************************************************
    private static Map<String, String> StringUsernameMap = new HashMap<>();
    private static Map<String, String> usernameStringMap = new HashMap<>();

    String username = "game";
    String player = "";
	//***************************************END OLD METHODS******************************************************************
    String rMessage = "";
    private final Logger logger = LoggerFactory.getLogger(WebSocketServer.class);
    
    @OnOpen
    /**
     * This class is used for the initial connection between the client and websocket
     * @param String the String for this user
     * @throws IOException 
     */
    public void onOpen(String String) throws IOException
    {
        logger.info("New Player entered into Open");
    }
 
    @OnMessage
    /**
     * This class allows the user to join a game, define which player they are, and send
     * player locations
     * @param String the String for the user
     * @param message the message sent from the user
     * @throws IOException
     */
    public void onMessage(String String, String message) throws IOException
    {
    	if(StringGameObjectMap.get(String) == null)
    	{
    		WebGameObject g = new WebGameObject(0,"0","0");
    		StringGameObjectMap.put(String, g);
    		GameObjectStringMap.put(g, String);
    		broadcastNew("I am here");
    	}
//    	if(StringGameObjectMap.get(String) == null)
//    	{
//    		for(int i = 0; i < players.size(); i++)
//    		{
//    			if(players.get(i) != StringGameObjectMap.get(String))
//    			{
//    				GameObjectStringMap.get(players.get(i)).getBasicRemote().sendText("!");
//    			}
//    		}
//    		WebGameObject g = new WebGameObject(0,"0","0");
//    		StringGameObjectMap.put(String, g);
//    		GameObjectStringMap.put(g, String);
//    		players.add(g);
//    	}
//    	if(message.startsWith("!"))
//    	{
//    		WebGameObject g = new WebGameObject(0,"0","0");
//    		StringGameObjectMap.put(String, g);
//    		GameObjectStringMap.put(g, String);
//    		players.add(g);
//    	}
    	//TODO Setup sending to multiple people
    	if(message.startsWith("."))
    	{
    		message = message.substring(1);
    	}
    	else
    	{
    		sendMessageToAll(String, message);
    	}
    	
    	if(message.startsWith("GSO"))
    	{
			String s = "";
    		for(int i = 0; i < game.size(); i++)
    		{
    			if(i < 10)
    			{
    				s = "0";
    			}
    			else
    			{
    				s = "";
    			}
    			if(!game.get(i).getState())
    			{
        			sendMessageToPArticularUser(String, s + i + "O" + game.get(i).getNumPlayers() + "/" + game.get(i).getMaxPlayers());
    			}
    		}
    	}
    	else if(message.startsWith("GS"))
    	{
    		String s = "";
    		String s1 = "";
    		sendMessageToPArticularUser(String, "Game size: " + game.size());
    		for(int i = 0; i < game.size(); i++)
    		{
    			if(i < 10)
    			{
    				s1 = "0";
    			}
    			else
    			{
    				s1 = "";
    			}
    			if(!game.get(i).getState())
    			{
    				s = "O";
    			}
    			else
    			{
    				s = "P";
    			}
    			sendMessageToPArticularUser(String, s1  + i +"" + s + game.get(i).getNumPlayers() + "/" + game.get(i).getMaxPlayers());
    		}
    	}
    	else if(message.startsWith("C"))
    	{
    		try {
				String gameType = "" + message.charAt(1);
				int maxP = Integer.parseInt("" + message.charAt(2));
				int gameID = game.size();
				String s = "";
				if(gameID < 10)
				{
					s = "0";
				}
				WebGames wg = new WebGames(gameType, maxP);
				game.add(wg);
				sendMessageToPArticularUser(String, "GID" + s + gameID +" " + message + " has been built");
				logger.info("GID" + s + gameID +" " + message + " has been built");
    		}
    		catch(Exception e)
    		{
				sendMessageToPArticularUser(String, "Invalid command, Please use: J :C : C#P : START GAME\n");
    		}
    	}
    	else if(message.startsWith("J"))
    	{
    		try {
				int gameID = Integer.parseInt(""  + message.charAt(1) + message.charAt(2));
				int gameType = message.charAt(3);
				StringGameObjectMap.get(String).setGameType(gameType);
				String x = "" + message.charAt(4) + message.charAt(5) + message.charAt(6) + message.charAt(7);
				String y = "" + message.charAt(8) + message.charAt(9) + message.charAt(10) + message.charAt(11);
				
				if(game.size() > gameID)
				{
					StringGameObjectMap.get(String).setX(x);
					StringGameObjectMap.get(String).setY(y);
					StringGameObjectMap.get(String).setGameID(gameID);
					
					boolean i = game.get(gameID).addPlayer(StringGameObjectMap.get(String));
					if(i && !game.get(gameID).getState())
					{
						game.get(gameID).players.get(game.get(gameID).players.size() - 1).setpNum(game.get(gameID).players.size() - 1);
						sendMessageToPArticularUser(String, "Successfully Joined");
						logger.info("Successfully Joined");
					}
					else
					{
						sendMessageToPArticularUser(String, "Full, Try again");
						logger.info("Full, Try again");
					}
				}
				else
				{
					sendMessageToPArticularUser(String, "Game does not exist");
					logger.info("Game does not exist");
				}
    		}
    		catch(Exception e)
    		{
				sendMessageToPArticularUser(String, "Invalid command, Please use: J : J##TXXXXYYYY: JOIN GAME\n");
    		}
				
    	}
    	else if(message.startsWith("R"))
    	{
    		game.get(StringGameObjectMap.get(String).getGameID()).removePlayer(StringGameObjectMap.get(String).getPNum());
    		logger.info("Remove player");
    		
    	}
    	else if(message.startsWith("PL"))
    	{
    		String s = game.get(StringGameObjectMap.get(String).getGameID()).getPlayerLocations();
    		sendMessageToPArticularUser(String, s);
    		logger.info("Get player locations");
    	}
    	else if(message.startsWith("OL"))
    	{
    		String s = game.get(StringGameObjectMap.get(String).getGameID()).getObjectLocations();
    		sendMessageToPArticularUser(String, s);
    		logger.info("Get object locations");
    	}
    	else if(message.startsWith("BL"))
    	{
    		String s = "P" + game.get(StringGameObjectMap.get(String).getGameID()).getObjectLocations() + "O" + game.get(StringGameObjectMap.get(String).getGameID()).getObjectLocations();
    		sendMessageToPArticularUser(String, s);
    		logger.info("Get all locations");
    	}
    	else if(message.startsWith("ST"))
    	{
    		StringBuilder sb = new StringBuilder(message);
    		sb.deleteCharAt(0);
    		sb.deleteCharAt(1);
    		String s1 = sb.toString();
    		game.get(StringGameObjectMap.get(String).getGameID()).setScore(s1);
    	}
    	else if(message.startsWith("S"))
    	{
    		String s = game.get(StringGameObjectMap.get(String).getGameID()).getScore();
    		sendMessageToPArticularUser(String, s);
    		logger.info("Get Score");
    	}
    	else if(message.startsWith("T"))
    	{
    		if(game.get(StringGameObjectMap.get(String).getGameID()).getState())
    		{
        		sendMessageToPArticularUser(String, "Game has started");
    		}
    		else
    		{
        		sendMessageToPArticularUser(String, "Game has not started");
    		}

    		logger.info("Get state");
    	}
    	else if(message.startsWith("G"))
    	{
    		game.get(StringGameObjectMap.get(String).getGameID()).setState(true);
    	}
    	else if(message.startsWith("PM"))
    	{
    		String x = "" + message.charAt(2) + message.charAt(3) + message.charAt(4) + message.charAt(5);
    		String y = "" + message.charAt(6) + message.charAt(7) + message.charAt(8) + message.charAt(9);
    		StringGameObjectMap.get(String).setX(x);
    		StringGameObjectMap.get(String).setY(y);
    	}
    	else if(message.startsWith("OM"))
    	{
    		String x = "" + message.charAt(2) + message.charAt(3) + message.charAt(4) + message.charAt(5);
    		String y = "" + message.charAt(6) + message.charAt(7) + message.charAt(8) + message.charAt(9);
    		game.get(StringGameObjectMap.get(String).getGameID()).setObjectMovement(0, x, y);
    	}
    	else if(message.startsWith("N?"))
    	{
    		String s = "";
    		s += 

    	    s += "Symbols\n";
    	    s += "T -> Game Type\n";
    	    s += "##-> Game id\n";
    	    s += "P -> Max Players\n";
    	    s += "XXXX-> X position\n";
    	    s += "YYYY-> Y postion\n";
    	    s += "ii-> Player/Object id\n\n";
    		
    	    s += "Commands\n";
    	    s += "C : C#P         : START GAME\n";
    	    s += "J : J##TXXXXYYYY: JOIN GAME\n";
    	    s += "R : R           : LEAVE GAME\n\n";
    		
    	    s += "PL: PL  : GET PLAYER LOCATIONS\n";
    	    s += "OL: OL  : GET OBJECT LOCATIONS\n";
    	    s += "BL: BL  : GET ALL LOCATIONS\n\n";
    		
    	    s += "PM: PMXXXXYYYY : SET PLAYER LOCATIONS\n";
    	    s += "OM: OMXXXXYYYY : SET OBJECT LOCATIONS --One Object only--\n\n";
    		
    	    s += "S : S  : GET SCORE\n";
    	    s += "ST: STT: SET SCORE\n\n";

    	    s += "T : T  : GET STATE\n";
    	    s += "G : G  : START GAME\n\n";
    		
    	    s += "GS : GS  : RETURNS THE CURRENT GAMES\n";
    	    s += "GSO: GSO : RETURNS THE CURRENT GAMES THAT CAN BE JOINED\n\n";
    		
    	    s += "W : W##  : JOINS A GAME AS A SPECTATOR\n\n";

    	    s += "N?: GET NEW OPCODES\n";
    	    s += "O?: GET OLD OPCODES\n\n"; 
    	    sendMessageToPArticularUser(String, s);
    		
//    		sendMessageToPArticularUser(String, "Symbols\n");
//    		sendMessageToPArticularUser(String, "# -> Game Type\n");
//    		sendMessageToPArticularUser(String, "##-> Game id\n");
//    		sendMessageToPArticularUser(String, "P -> Max Players\n");
//    		sendMessageToPArticularUser(String, "XX-> X position\n");
//    		sendMessageToPArticularUser(String, "YY-> Y postion\n");
//    		sendMessageToPArticularUser(String, "ii-> Player/Object id\n\n");
//    		
//    		sendMessageToPArticularUser(String, "Commands\n");
//    		sendMessageToPArticularUser(String, "C : C#P : START GAME\n");
//    		sendMessageToPArticularUser(String, "J : J## : JOIN GAME\n");
//    		sendMessageToPArticularUser(String, "R : R   : LEAVE GAME\n\n");
//    		
//    		sendMessageToPArticularUser(String, "PL: PL  : GET PLAYER LOCATIONS\n");
//    		sendMessageToPArticularUser(String, "OL: OL  : GET OBJECT LOCATIONS\n");
//    		sendMessageToPArticularUser(String, "BL: BL  : GET ALL LOCATIONS\n\n");
//    		
//    		sendMessageToPArticularUser(String, "PM: PMXXYY : SET PLAYER LOCATIONS\n");
//    		sendMessageToPArticularUser(String, "OM: OMXXYY : SET OBJECT LOCATIONS --One Object only--\n\n");
//    		
//    		sendMessageToPArticularUser(String, "S : S  : GET SCORE\n");
//    		sendMessageToPArticularUser(String, "ST: ST#: SET SCORE\n\n");
//
//    		sendMessageToPArticularUser(String, "T : T  : GET STATE\n");
//    		sendMessageToPArticularUser(String, "G : G  : START GAME\n\n");
//    		
//    		sendMessageToPArticularUser(String, "GS : GS  : RETURNS THE CURRENT GAMES\n");
//    		sendMessageToPArticularUser(String, "GSO: GSO : RETURNS THE CURRENT GAMES THAT CAN BE JOINED\n\n");
//    		
//    		sendMessageToPArticularUser(String, "W : W##  : JOINS A GAME AS A SPECTATOR\n\n");
//
//    		sendMessageToPArticularUser(String, "N?: GET NEW OPCODES\n");
//    		sendMessageToPArticularUser(String, "O?: GET OLD OPCODES\n\n");     		
    	}
    	else if(message.startsWith("W"))
    	{
    		try {
	    		int gameID  = Integer.parseInt("" + message.charAt(1) + message.charAt(2));
	    		StringGameObjectMap.get(String).setGameID(gameID);
	    		game.get(gameID).spectators.add(StringGameObjectMap.get(String));
	    		game.get(gameID).spectators.get(game.get(gameID).spectators.size() - 1).setpNum(game.get(gameID).spectators.size() - 1);
    		}
    		catch(Exception e)
    		{
    			sendMessageToPArticularUser(String,"Invalid Command please use W : W##  : JOINS A GAME AS A SPECTATOR\n\n");
    		}
    	}
    	//***************************************START OLD METHODS****************************************************************
    	//Start with a "!" to join a game and define player number
    	else if(message.startsWith("!"))
    	{
    		username = "" + message.charAt(1); //The game number is stored in the first bit
    		player = "" + message.charAt(2);  //The player number is stored in the second bit
    		logger.info("Player " + player + " has joined game " + username);
    		
            StringUsernameMap.put(String, username); //Log the String based off the game number
            usernameStringMap.put(username, String); 
            
            logger.info("This is user " + StringUsernameMap.size());
            
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
     * This class closes the String after the user is done.
     * @param String String for the user
     * @throws IOException
     */
    public void onClose(String String) throws IOException
    {
    	logger.info("Entered into Close");    	
    	
    	//***************************************START OLD METHODS****************************************************************
    	String username = StringUsernameMap.get(String);
    	StringUsernameMap.remove(String);
    	usernameStringMap.remove(username);
    	//***************************************END OLD METHODS******************************************************************
    	
    	WebGameObject wgo = StringGameObjectMap.get(String);
    	StringGameObjectMap.remove(String);
    	GameObjectStringMap.remove(wgo);
    }
 
    @OnError
    /**
     * This class displays an error message in the logger when present
     * @param String String of the user
     * @param throwable
     */
    public void onError(String String, Throwable throwable) 
    {
        // Do error handling here
    	logger.info("Entered into Error");
    }
    /**
     * Send message to a specific String or game
     * @param message message to send to the String
     */
	private String sendMessageToPArticularUser(String s, String message) 
    {	
//		
//    	try {
//    		GameObjectStringMap.get(StringGameObjectMap.get(s)).getBasicRemote().sendText(message);
//    		logger.info("sending dm to " + GameObjectStringMap.get(StringGameObjectMap.get(s)));
//        } catch (IOException e) {
//        	logger.info("Exception: " + e.getMessage().toString());
//            e.printStackTrace();
//        }
		rMessage = message;
		return message;
    }
	//This will be used for Admins
//	private void sendMessgeToGame(WebGames wg, String message)
//	{
//    	try {
//    		for(int i = 0; i < wg.players.size(); i++)
//    		{
//    			GameObjectStringMap.get(wg.players.get(i)).getBasicRemote().sendText(message);
//    		}
//    		logger.info("sending dm to " + wg);
//        } catch (IOException e) {
//        	logger.info("Exception: " + e.getMessage().toString());
//            e.printStackTrace();
//        }
//	}
	private String sendMessageToAll(String String, String message) throws IOException
	{
//		message = "." + message;
//		for(int i = 0; i < players.size(); i++)
//		{
//			if(players.get(i) != StringGameObjectMap.get(String))
//			{
//				GameObjectStringMap.get(players.get(i)).getBasicRemote().sendText(message);
//			}
//		}
		return String;
	}
    private static String broadcastNew(String message) 
  	      throws IOException 
  {	  
//  	StringGameObjectMap.forEach((String, username) -> {
//  		synchronized (String) {
//	            try {
//	                String.getBasicRemote().sendText(message);
//	            } catch (IOException e) {
//	                e.printStackTrace();
//	            }
//	        }
//	    });
    	return message;
	}
	//***************************************START OLD METHODS****************************************************************
	private String sendMessageToPArticularUserOLD(String message) 
    {	
//		//String username = "user";
//		
//    	try {
//    		usernameStringMap.get(username).getBasicRemote().sendText(message);
//    		logger.info("sending dm to " + usernameStringMap.get(username));
//        } catch (IOException e) {
//        	logger.info("Exception: " + e.getMessage().toString());
//            e.printStackTrace();
//        }
		return message;
    }

    /**
     * Send message to all the Strings that are being used by the websocket
     * @param message message to be sent
     * @throws IOException
     */
    private static String broadcastOLD(String message) 
    	      throws IOException 
    {	  
//    	StringUsernameMap.forEach((String, username) -> {
//    		synchronized (String) {
//	            try {
//	                String.getBasicRemote().sendText(message);
//	            } catch (IOException e) {
//	                e.printStackTrace();
//	            }
//	        }
//	    });
    	return message;
	}
    public String getRMessage()
    {
    	return rMessage;
    }
    
	//***************************************END OLD METHODS******************************************************************
}

