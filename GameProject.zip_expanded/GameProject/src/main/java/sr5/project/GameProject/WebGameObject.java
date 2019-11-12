package sr5.project.GameProject;

public class WebGameObject 
{
	String gameID;
	String pNum;
	String x;
	String y;
	
	public WebGameObject(String info)
	{
		//TODO Confirm string length to be 9(! plus 8)
		//TODO Constructor
		gameID = "" + info.charAt(1) + info.charAt(2);
		pNum = "" + info.charAt(3) + info.charAt(4);
		x = "" + info.charAt(5) + info.charAt(6);
		y = "" + info.charAt(7) + info.charAt(8);
	}
	public WebGameObject(WebGameObject object, String nX, String nY)
	{
		gameID = "" + object.getGameID();
		pNum = "" + object.getPNum();
		x = nX;
		y = nY;
	}
	public void setGameID(String gameIDnew)
	{
		gameID = gameIDnew;
	}
	public void setpNum(String pNumnew)
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
	public String getGameID()
	{
		return gameID;
	}
	public String getPNum()
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
	


}
