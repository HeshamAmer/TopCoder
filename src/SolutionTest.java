import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

    @Test
    public void solution() {
        final int[] X = {3, 5, 1, 6 } ;
        final int[] Y = {1, 3, 3, 8 } ;
        String T = "Xpqp";
        Solution sol = new Solution();
        final int solution = sol.solution( X, Y, T );
        Assert.assertEquals(  10, solution );
    }

}