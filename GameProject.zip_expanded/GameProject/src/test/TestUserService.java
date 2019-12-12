package sr5.project.GameProject;

import org.junit.Before;
import org.junit.Test;
import org.mockito.InjectMocks;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.mockito.Mockito.verify;
import static org.mockito.Mockito.when;
import static org.mockito.Mockito.times;

public class TestUserService {
    @InjectMocks
    UserService userService;

    @Mock
    UserRepository repo;

    @Before
    public void init(){
        MockitoAnnotations.initMocks(this);
    }

    @Test
    public void getAllUserTest(){
        List<User> users = new ArrayList<User>();
        User userOne = new User(1, "YodaSpock", 40, "address1here");
        User userTwo = new User(2, "Parker", 21, "address2here");
        User userThree = new User(3, "Astrellion", 35, "address3here");
        User userFour = new User(4,"MicahM", 52, "address4here");

        scores.add(userOne);
        scores.add(userTwo);
        scores.add(userThree);
        scores.add(userFour);

        when(repo.findAll()).thenReturn(scores);

        List<User> userList = userService.getAllUser();

        assertEquals(4, userList.size());
        verify(repo, times(1)).findAll();
    }

    @Test
    public void getUserByIdTest(){
        when(repo.findById(1)).thenReturn(java.util.Optional.of(new User(1, "ClimbingFan", 333, "addressHere")));

        User user = userService.getUser(1);
        assertEquals(1, user.getId());
        assertEquals("ClimbingFan", user.getUsername());
        assertEquals(333, user.getScore());
        assertEquals("addressHere", user.getAddress());
    }
    
    @Test
    public void deleteUserByIdTest() {
    	
    	when(repo.delete(userOne)).thenReturn(java.util.Option.of(new User(1, "YodaSpock", 40, "address1here")));
    	
    	User userOne = new User(1, "YodaSpock", 40, "address1here");
    	repo.delete(userOne);
    }
    
    @Test
    public void updateuserByIdTest() {
    	  when(repo.findById(1)).thenReturn(java.util.Optional.of(new User(1, "ClimbingFan", 333, "addressHere")));

          User user = userService.updateUser(1, "YodaSpock", 40, "address1here");
          assertEquals(1, user.getId());
          assertEquals("YodaSpock", user.getUsername());
          assertEquals(40, user.getScore());
          assertEquals("address1here", user.getAddress());
    }
    @Test
    public void getUpdategetTest() {
    	 when(repo.findById(1)).thenReturn(java.util.Optional.of(new User(1, "ClimbingFan", 333, "addressHere")));

         User user = userService.getUser(1);
         assertEquals(1, user.getId());
         assertEquals("ClimbingFan", user.getUsername());
         assertEquals(333, user.getScore());
         assertEquals("addressHere", user.getAddress());
         
         when(repo.findById(1)).thenReturn(java.util.Optional.of(new User(1, "ClimbingFan", 333, "addressHere")));

         User user = userService.updateUser(1, "YodaSpock", 40, "address1here");
         assertEquals(1, user.getId());
         assertEquals("YodaSpock", user.getUsername());
         assertEquals(40, user.getScore());
         assertEquals("address1here", user.getAddress());
         
         User user = userService.getUser(1);
         assertEquals(1, user.getId());
         assertEquals("YodaSpock", user.getUsername());
         assertEquals(40, user.getScore());
         assertEquals("address1here", user.getAddress());
         
         
    }
}
