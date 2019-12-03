//package sr5.project.Test;
//
//import static org.junit.Assert.*;
//
//import java.io.IOException;
//
//import org.junit.Test;
//import org.junit.runner.RunWith;
//import org.mockito.junit.MockitoJUnitRunner;
//import org.springframework.boot.web.servlet.server.Session;
//import org.springframework.web.socket.WebSocketSession;
//
//@RunWith(MockitoJUnitRunner.class)
//public class TestGameObject {
//
//	@Test
//	public void basicGameCreation() 
//	{
//		WebSocketServer wss = new WebSocketServer();
//		WebGames wg = new WebGames("0", 2);
//		wss.game.add(wg);
//		assertEquals(2,wss.game.get(0).getMaxPlayers());
//		assertEquals("0",wss.game.get(0).getGameType());
//	}
//	@Test
//	public void basicObjectCreation()
//	{
//		WebGameObject go = new WebGameObject(2,"0010", "1234");
//		assertEquals(2,go.getGameID());
//		assertEquals("0010",go.getX());
//		assertEquals("1234",go.getY());
//	}
//	@Test
//	public void basicGameOperation()
//	{
//		WebSocketServer wss = new WebSocketServer();
//		WebGames wg = new WebGames("0", 2);
//		wss.game.add(wg);
//		WebGameObject go = new WebGameObject(0, "1234", "4321");
//		wss.game.get(0).addPlayer(go);
//		wss.game.get(0).addPlayer(go);
//		assertEquals(0, wss.game.get(0).players.get(0).getGameID());
//	}
//	@Test
//	public void basicGameOperationMovement() throws IOException
//	{
//		WebSocketServerS ws = new WebSocketServerS();
//		ws.onMessage("P1", "C22");
//		ws.onMessage("P1", "J00000001000");
//		assertEquals(0, ws.game.get(0).players.get(0).getGameID());
//		ws.onMessage("P2", "J00012344321");
//		assertEquals(0, ws.game.get(0).players.get(1).getGameID());
//		assertEquals("0000",ws.game.get(0).players.get(0).getX());
//		assertEquals("1000",ws.game.get(0).players.get(0).getY());
//		assertEquals("1234",ws.game.get(0).players.get(1).getX());
//		assertEquals("4321",ws.game.get(0).players.get(1).getY());
//		ws.onMessage("P1", "PM24681357");
//		ws.onMessage("P2", "PM98771233");
//		assertEquals("2468",ws.game.get(0).players.get(0).getX());
//		assertEquals("1357",ws.game.get(0).players.get(0).getY());
//		assertEquals("9877",ws.game.get(0).players.get(1).getX());
//		assertEquals("1233",ws.game.get(0).players.get(1).getY());
//	}
//	@Test
//	public void multipleGames() throws IOException
//	{
//		WebSocketServerS ws = new WebSocketServerS();
//		ws.onMessage("P1", "C42");
//		ws.onMessage("P1", "C33");
//		ws.onMessage("P1", "C24");
//		ws.onMessage("P1", "C15");
//		ws.onMessage("P1", "J00000001000");
//		ws.onMessage("P2", "J01000001000");
//		ws.onMessage("P1", "GSO");
//		assertEquals(2, ws.game.get(0).getMaxPlayers());
//		assertEquals(3, ws.game.get(1).getMaxPlayers());
//		assertEquals(4, ws.game.get(2).getMaxPlayers());
//		assertEquals(5, ws.game.get(3).getMaxPlayers());
//		assertEquals(1, ws.game.get(0).players.size());
//		assertEquals(1, ws.game.get(1).players.size());
//		assertEquals(0, ws.game.get(2).players.size());
//		assertEquals(0, ws.game.get(3).players.size());
//	}
//	@Test
//	public void invalidJoin() throws IOException
//	{
//		WebSocketServerS ws = new WebSocketServerS();
//		ws.onMessage("P1", "C11");
//		ws.onMessage("P1", "C11");
//		ws.onMessage("P1", "J00000000000");
//		assertEquals("Successfully Joined", ws.getRMessage());
//		ws.onMessage("P1", "J00000000000");
//		assertEquals("Full, Try again", ws.getRMessage());
//		ws.onMessage("P1", "J10000000000");
//		assertEquals("Game does not exist", ws.getRMessage());
//
//		
//	}
//
//}
