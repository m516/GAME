package sr5.project.GameProject;

public class Spectator 
{
	int gameID;
	
	public Spectator(int nGameID)
	{
		gameID = nGameID;
	}
	public void setGameID(int gameIDnew)
	{
		gameID = gameIDnew;
	}
	public int getGameID()
	{
		return gameID;
	}
}

