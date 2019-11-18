package sr5.project.GameProject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class WebGames 
{
	Map<String, Integer> GameIDIndex = new HashMap<>();
	
	//Arraylist of objects
	ArrayList <WebGameObject> objects = new ArrayList<WebGameObject>();
	ArrayList <WebGameObject> players = new ArrayList<WebGameObject>();
	ArrayList <WebGameObject> spectators = new ArrayList<WebGameObject>();
	
	//Max number of players
	int pMax = 0;
	//Score
	String score = "";
	//State of the game
	boolean isPlaying = false;
	String gameType;
	
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
			return true;
			//If player successfully joins
		}
	}
	public String removePlayer(int playerNumber)
	{
		players.remove(playerNumber);
		return "Player " + playerNumber + " has been removed"; 
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
			s = s + i + "@" + players.get(i).getX() + players.get(i).getY() +",";
		}
		return s;
	}
	public String getObjectLocations()
	{
		String s = "";
		for(int i = 0; i < objects.size(); i++)
		{
			s = s + i + "@" + objects.get(i).getX() + objects.get(i).getY() +",";
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
		score = nScore;
		return "Score is now " + nScore;
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
}
