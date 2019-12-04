//package sr5.project.Test;
//
//import static org.junit.Assert.*;
//
//import org.junit.Test;
//
//import sr5.project.GameProject.WebGameObject;
//import sr5.project.GameProject.WebGames;
//
//public class WebGamesTest {
//
//	@Test
//	public void WebGamesConstructor1() 
//	{
//		WebGames wg = new WebGames("0", 10);
//		assertEquals(wg.getGameType(), "0");
//		assertEquals(wg.getMaxPlayers(), 10);
//		
//		WebGames wg1 = new WebGames("3", 15);
//		assertEquals(wg1.getGameType(), "3");
//		assertEquals(wg1.getMaxPlayers(), 15);
//	}
//	@Test
//	public void addPlayer()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject p = new WebGameObject(2, "00", "00");
//		assertEquals(wg.addPlayer(p), true);
//		assertEquals(wg.addPlayer(p), true);
//		assertEquals(wg.addPlayer(p), false);
//		assertEquals(wg.addPlayer(p), false);
//	}
//	@Test
//	public void fullGame()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject p = new WebGameObject(2, "00", "00");
//		assertEquals(wg.addPlayer(p), true);
//		assertEquals(wg.getState(), false);
//		assertEquals(wg.addPlayer(p), true);
//		assertEquals(wg.getState(), true);
//		assertEquals(wg.addPlayer(p), false);
//		assertEquals(wg.addPlayer(p), false);
//	}
//	@Test
//	public void removePlayer()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject p = new WebGameObject(2, "0000", "0000");
//		assertEquals(wg.addPlayer(p), true);
//		assertEquals(wg.addPlayer(p), true);
//		assertEquals(wg.removePlayer(1), "Player 1 has been removed");
//		assertEquals(wg.removePlayer(0), "Player 0 has been removed");
//	}
//	@Test
//	public void addObject()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject o = new WebGameObject(2, "0000", "0000");
//		assertEquals(wg.addObject(o), true);
//		assertEquals(wg.addObject(o), true);
//	}
//	@Test
//	public void removeObject()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject o = new WebGameObject(2, "00", "00");
//		assertEquals(wg.addObject(o), true);
//		assertEquals(wg.addObject(o), true);
//		assertEquals(wg.removeObject(1), "Object 1 has been removed");
//		assertEquals(wg.removeObject(0), "Object 0 has been removed");
//	}
//	@Test
//	public void playerMovement()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject p = new WebGameObject(2, "0000", "0000");
//		wg.addPlayer(p);
//		p.setPosition("PM0999,7599");
//		assertEquals(p.getX(), "0999");
//		assertEquals(p.getY(), "7599");
//		assertEquals(wg.getPlayerLocations(), "00@09997599");
//	}
//	@Test
//	public void objectMovement()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject o = new WebGameObject(2, "0000", "0000");
//		wg.addObject(o);
//		o.setPosition("OM0999,7599");
//		assertEquals(o.getX(), "0999");
//		assertEquals(o.getY(), "7599");
//		assertEquals(wg.getObjectLocations(), "00@09997599");
//	}
//	@Test
//	public void score()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject o = new WebGameObject(2, "0000", "0000");
//		wg.addPlayer(o);
//		wg.addPlayer(o);
//		wg.setScore("ST00@1,01@2");
//		assertEquals(wg.getScore(), "00@1,01@2");
//		wg.setScore("ST00@5,01@2");
//		assertEquals(wg.getScore(), "00@5,01@2");
//		wg.setScore("ST00@1,01@6");
//		assertEquals(false, wg.isOver());
//		assertEquals(wg.getScore(), "00@1,01@6");
//		wg.setScore("ST00@1,01@7");
//		assertEquals(wg.getScore(), "00@1,01@7");
//		assertEquals(true, wg.isOver());	
//	}
//	@Test
//	public void score1()
//	{
//		WebGames wg = new WebGames("0", 2);
//		WebGameObject o = new WebGameObject(2, "0000", "0000");
//		wg.addPlayer(o);
//		wg.addPlayer(o);
//		wg.setScore("ST00@1,01@2");
//		assertEquals(wg.getScore(), "00@1,01@2");
//		wg.setScore("ST00@5,01@2");
//		assertEquals(wg.getScore(), "00@5,01@2");
//		wg.setScore("ST00@1,01@6");
//		assertEquals(false, wg.isOver());
//		assertEquals(wg.getScore(), "00@1,01@6");
//		wg.setScore("ST00@7,01@5");
//		assertEquals(wg.getScore(), "00@7,01@5");
//		assertEquals(true, wg.isOver());	
//	}
//	
//
//}
