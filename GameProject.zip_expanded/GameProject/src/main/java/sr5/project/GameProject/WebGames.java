package sr5.project.GameProject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class WebGames 
{
	Map<String, Integer> GameIDIndex = new HashMap<>();
	
	//ArrayList of objects
	ArrayList <WebGameObject> objects = new ArrayList<WebGameObject>();
	ArrayList <WebGameObject> players = new ArrayList<WebGameObject>();
	ArrayList <WebGameObject> spectators = new ArrayList<WebGameObject>();
	
	//Max number of players
	private int pMax = 0;
	//Score
	private String score = "";
	//State of the game
	private boolean isPlaying = false;
	private boolean isOver = false;
	private String winner = "";
	private String gameType;
	
	public WebGames(String nGameType, int maxPlayers)
	{
		gameType = nGameType;
		pMax = maxPlayers;
 	}
	public boolean addPlayer(WebGameObject player)
	{
		if(players.size() >= pMax)
		{
			return false;
			//If game is already full
		}
		else
		{
			players.add(player);
			if(players.size() == pMax)
			{
				isPlaying = true;
			}
			return true;
			//If player successfully joins
		}
	}
	public boolean addObject(WebGameObject object)
	{
		objects.add(object);
		return true;
	}
	public String removePlayer(int playerNumber)
	{
		players.remove(playerNumber);
		return "Player " + playerNumber + " has been removed"; 
	}
	public String removeObject(int objectNumber)
	{
		objects.remove(objectNumber);
		return "Object " + objectNumber + " has been removed"; 
	}
	public void setObjectMovement(int ObjectNumber, String x, String y)
	{
		WebGameObject o = new WebGameObject(objects.get(ObjectNumber), x, y);
		objects.set(ObjectNumber, o);
	}
	public void setPlayerMovement(int playerNumber, String x, String y)
	{
		WebGameObject p = new WebGameObject(players.get(playerNumber), x, y);
		players.set(playerNumber, p);
	}
	public String getPlayerLocations()
	{
		String s = "";
		for(int i = 0; i < players.size(); i++)
		{
			s = s + String.format("%02d@%s%s", i, players.get(i).getX(), players.get(i).getY());
		}
		
		return s;
	}
	public String getObjectLocations()
	{
		String s = "";
		for(int i = 0; i < objects.size(); i++)
		{
			//s = s + i + "@" + objects.get(i).getX() + objects.get(i).getY();
			
			
			s = s + String.format("%02d@%s%s" ,i, objects.get(i).getX(), objects.get(i).getY());
		}
		return s;
	}
	public String getAllLocations()
	{
		return "P" + getPlayerLocations() + "O" + getObjectLocations();
	}
	public String getScore() {
		return score;
	}
	public String setScore(String nScore)
	{
		nScore = nScore.substring(2);
		if(nScore.charAt(3) == '7')
		{
			isOver = true;
			//winner = "00";
		}
		if(nScore.charAt(8) == '7')
		{
			isOver = true;
			//winner = "01";
		}
		score = nScore;
		return score;
	}
	public boolean isOver()
	{
		return isOver;
	}
	public boolean getState()
	{
		return isPlaying;
	}
	public void setState(boolean s)
	{
		isPlaying = s;
	}
	public int getMaxPlayers()
	{
		return pMax;
	}
	public int getNumPlayers()
	{
		return players.size();
	}
	public String getGameType()
	{
		return gameType;
	}
}
