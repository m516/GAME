package sr5.project.GameProject;

public class WebGameObject 
{
	private int gameID;
	private int pNum;
	private int gameType;
	private String x;
	private String y;
	
	public WebGameObject(int nGameID, String nX, String nY)
	{
		gameID = nGameID;
		x = nX;
		y = nY;
	}
	public WebGameObject(WebGameObject object, String nX, String nY)
	{
		gameID = object.getGameID();
		pNum = object.getPNum();
		x = nX;
		y = nY;
	}
	public void setGameID(int gameIDnew)
	{
		gameID = gameIDnew;
	}
	public void setpNum(int pNumnew)
	{
		pNum = pNumnew;
	}
	public void setX(String xnew)
	{
		x = xnew;
	}
	public void setY(String ynew)
	{
		y = ynew;
	}
	public int getGameID()
	{
		return gameID;
	}
	public int getPNum()
	{
		return pNum;
	}
	public String getX()
	{
		return x;
	}
	public String getY() 
	{
		return y;
	}
	public int getGameType()
	{
		return gameType;
	}
	public void setGameType(int g)
	{
		gameType = g;
	}
	public void setPosition(String message)
	{
		setX(message.substring(2,6));
		setY(message.substring(7,11));
	}
}

