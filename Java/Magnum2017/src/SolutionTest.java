import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {
    private Solution sol = new Solution();
    @Test
    public void Test1() {

        final int[] X = {3, 5, 1, 6 } ;
        final int[] Y = {1, 3, 3, 8 } ;
        String T = "Xpqp";
        final int solution = sol.solution( X, Y, T );
        Assert.assertEquals(  10, solution );
    }


    @Test
    public void Test2() {
        final int[] X = {0, 3, 5, 1, 6} ;
        final int[] Y = {4, 1, 3, 3, 8} ;
        String T = "pXpqp";
        sol = new Solution();
        final int solution = sol.solution( X, Y, T );
        Assert.assertEquals(  2, solution );
    }

    @Test
    public void Test3() {
        final int[] X = {0, 6, 2, 5, 3, 0} ;
        final int[] Y = {4, 8, 2, 3, 1, 6} ;
        String T = "ppqpXp";
        sol = new Solution();
        final int solution = sol.solution( X, Y, T );
        Assert.assertEquals(  12, solution );
    }

    @Test
    public void Test4() {
        final int[] X = {3, 2, 1} ;
        final int[] Y = {1, 2, 3};
        String T = "Xpp";
        sol = new Solution();
        final int solution = sol.solution( X, Y, T );
        Assert.assertEquals(  0, solution );
    }

    @Test
    public void Test5() {
        final int[] X = {3, 1, 6} ;
        final int[] Y = {1, 3, 6} ;
        String T = "Xpq";
        sol = new Solution();
        final int solution = sol.solution( X, Y, T );
        Assert.assertEquals(  1, solution );
    }
}