import javafx.util.Pair;

import java.util.*;

public class Solution {

    Map<Integer, List<Pair>> leftLines;
    Map<Integer, List<Pair>> rightLines;

    public int solution(int[] X, int[] Y, String T) {
        Pair<Integer, Integer> chinPair = initializeMaps(X, Y, T);
        //need to do the sort.
        //try right first.
        List<Pair> pairs = rightLines.get(chinPair.getKey() + chinPair.getValue());
        int i=findPairIndex(pairs, chinPair);
        pairs.get(i+1);
        if ()
    }

    private int findPairIndex(List<Pair> pairs, Pair<Integer, Integer> chinPair) {
        for (int i=0;i<pairs.size();i++){
            if (pairs.get(i).equals(chinPair))
                return i;
        }
        return -1;
    }

    private Pair<Integer,Integer> initializeMaps(int[] X, int[] Y, String T) {

        Pair<Integer, Integer> chin = null;
        for (int i = 0; i<X.length; i++){
            if (T.charAt(i)=='X')
            {
                chin = new Pair<>(X[i],Y[i]);
                continue;
            }
            int leftLine = Y[i] - X[i];
            int rightLine = Y[i] + X[i];
            Pair<Integer,Integer> justAPair = new Pair<>(X[i],Y[i]);
            if (leftLines.containsKey(leftLine)){
                List<Pair> leftPairs = leftLines.get(leftLine);//Will fix the negative lines soon.
                leftPairs.add(justAPair);
                leftLines.put(leftLine,leftPairs);
            } else {
                leftLines.put(Y[i] - X[i], Collections.singletonList(justAPair));
            }
            if (rightLines.containsKey(rightLine)){
                List<Pair> rightPairs = rightLines.get(rightLine);//Will fix the negative lines soon.
                rightPairs.add(justAPair);
                rightLines.put(rightLine, rightPairs);
            } else {
                rightLines.put(Y[i] - X[i], Collections.singletonList(justAPair));
            }

        }
        return chin;
    }


}

