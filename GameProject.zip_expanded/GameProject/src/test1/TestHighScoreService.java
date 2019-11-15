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

public class TestHighScoreService {
    @InjectMocks
    HighScoreService hsService;

    @Mock
    HighScoreRepository repo;

    @Before
    public void init(){
        MockitoAnnotations.initMocks(this);
    }

    @Test
    public void getAllHighScoreTest(){
        List<HighScore> scores = new ArrayList<HighScore>();
        HighScore hsOne = new HighScore(1, "YodaSpock", 11);
        HighScore hsTwo = new HighScore(2, "Parker", 425);
        HighScore hsThree = new HighScore(3, "Astrellion", 280);
        HighScore hsFour = new HighScore(4,"MicahM", 250);

        scores.add(hsOne);
        scores.add(hsTwo);
        scores.add(hsThree);
        scores.add(hsFour);

        when(repo.findAll()).thenReturn(scores);

        List<HighScore> hsList = hsService.getAllHighScore();

        assertEquals(4, hsList.size());
        verify(repo, times(1)).findAll();
    }

    @Test
    public void getHighScoreByIdTest(){
        when(repo.findById(1)).thenReturn(java.util.Optional.of(new HighScore(1, "ClimbingFan", 333)));

        HighScore hs = hsService.getHighScore(1);
        assertEquals(1, hs.getId());
        assertEquals("ClimbingFan", hs.getUsername());
        assertEquals(333, hs.getScore());
    }
}
