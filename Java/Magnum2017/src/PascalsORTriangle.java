import org.junit.Test;

class PascalSolutionSolution {

    private int getSummation( int size ){
        return (size*(size+1))/2;
    }

//    affected = rowLength + 1 && rowlength - 1
    public int solution (boolean[] p) {
    int size = p.length;
    boolean[] map = new boolean [getSummation( size )];
    int rowLength = size;
    System.arraycopy( p, 0, map, 0, p.length );
    int res =0 ;
    for (int i=0;i<map.length;i++){
    //protect right and left
        map[rowLength + 1]=true;
        res ++;

    }
    return res>1000000000 ? 1000000000:res ;
    }
}

public class PascalsORTriangle{
    @Test
    public void hello(){
        PascalSolutionSolution pascalsORTriangle = new PascalSolutionSolution();
        boolean [] input = {true, false, false, true, false};
        final int solution = pascalsORTriangle.solution( input );
        assert( solution == 11 );
    }
}