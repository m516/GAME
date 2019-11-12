package sr5.project.GameProject;

import java.util.ArrayList;
import java.util.Map;

public class WebGames 
{
	Map<String, Integer> GameIDIndex = HashMap<>();
	
	//Arraylist of objects
	ArrayList <WebGameObject> objects = new ArrayList<WebGameObject>();
	ArrayList <WebGameObject> players = new ArrayList<WebGameObject>();
	//Max number of players
	int pMax = 0;
	//Score
	String score = "";
	//State of the game
	boolean isPlaying = false;
	
	public WebGames(String message)
	{
		//TODO
		//Max players
		//First player
		//Initial Score
		
		
		String temp = "" + message.charAt(0) + message.charAt(1);
		pMax = Integer.parseInt(temp);
		
 	}
	public String addPlayer(WebGameObject player)
	{
		if(players.size() >= pMax)
		{
			return "Game Full, please try again";
		}
		else
		{
			players.add(player);
			return "Game successfully joined";
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
	
	

}
