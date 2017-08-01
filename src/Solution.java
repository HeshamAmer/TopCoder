import javafx.util.Pair;

import java.util.*;

public class Solution {
    private class Point {
        public int x,y,value;
        char c;
        Point( int x, int y, char c){
            this.x = x;
            this.y = y;
            this.c = c;
            if (c =='p')
                this.value = 1;
            else if (c=='q'){
                this.value = 10;
            } else if (c=='X') {
                this.value = 0;
            }
        }

    }

    private Map<Integer, List<Point>> rightLines;
    private Map<Integer, List<Point>> leftLines;
    private int MAX = 100;
    private int [][] dp = new int[MAX][MAX];

    public int solution(int[] X, int[] Y, String T) {
        rightLines = new HashMap<>();
        leftLines = new HashMap<>();
        Pair<Integer, Integer> chinPair = initializeMaps(X, Y, T);
        //need to do the sort.
        //try right first.
        return Math.max(
                pullRight(new Point(chinPair.getKey() ,chinPair.getValue(), 'X'))
                , pullLeft(new Point(chinPair.getKey()  ,chinPair.getValue()  , 'X') ));



    }

    private int pullLeft(Point point) {
        List<Point> points = leftLines.get(point.y + point.x);
        int nextIdx = Collections.binarySearch(points, new Point(point.x - 1, point.y + 1, 'X'), (Point o1, Point o2) -> {
            if (o1.x > o2.x) return -1;
            else if (o1.x < o2.x) return 1;
            else return 0;
        });

        if (nextIdx >= 0) { //if the list is always sorted, this means i'm blocked by a point.
            return 0; //this basically means an element was found.
        } else { //walahy la mesh found, hanreturn -the index -1
            //CURRENTLY nextIdx contains the position the point WOULD be inserted into if i wanted to
            nextIdx++;
            nextIdx*=-1; //fixing what the binary search reverses
            //now it contains the item after mine on the left line
            if (nextIdx < points.size() ) {
                Point nextPoint = points.get(nextIdx); //this should turn into a for loop for all the left lines reachable from here
                return Math.max(pullLeft(nextPoint) , pullRight(nextPoint)) + point.value ;
            } else { //i need to manifest a breaking condition here..
                int j=0;
                while (j<nextIdx) {
                    points.remove(0);
                    j++;
                }
                if ( rightLines.containsKey(point.y+point.x) )
                    return pullRight(point ) + point.value;
                return 0;
            }
        }
    }


    private int pullRight(Point point) {

        List<Point> points = rightLines.get(point.y - point.x);
        int nextIdx = Collections.binarySearch(points, new Point(point.x + 1, point.y + 1, 'X'), (Point o1, Point o2) -> {
            if (o1.y > o2.y) return 1;
            else if (o1.y < o2.y) return -1;
            else return 0;
        });

        if (nextIdx >= 0) { //if the list is always sorted, this means i'm blocked by a point.
            return 0; //this basically means an element was found.
        } else { //walahy la mesh found, hanreturn -the index -1
            //CURRENTLY nextIdx contains the position the point WOULD be inserted into if i wanted to
            nextIdx++;
            nextIdx*=-1;
            //now it contains the item after mine on the right line

            if (nextIdx < points.size() ) {
                //dp me here
                Point nextPoint = points.get(nextIdx); //this should turn into a for loop for all the left lines reachable from here
                return Math.max(pullRight(nextPoint), pullLeft(nextPoint))  + point.value ;
            } else {
                int j=0;
                while (j<nextIdx) {
                    points.remove(0);
                    j++;
                }
                if ( leftLines.containsKey(point.y+point.x) )
                    return pullLeft( point ) + point.value;
                return 0;
            }
        }
    }

    private Pair<Integer, Integer> initializeMaps(int[] X, int[] Y, String T) {

        Pair<Integer, Integer> chin = null;
        for (int i = 0; i < X.length; i++) {
            if (T.charAt(i) == 'X') {
                chin = new Pair<>(X[i], Y[i]); //possibly this needs to be removed and we start the initialization -1 of chin
            }
            int rightLine = Y[i] - X[i];
            int leftLine = Y[i] + X[i];

            Point justAPoint = new Point( X[i], Y[i], T.charAt(i) );

            if (rightLines.containsKey(rightLine)) {
                List<Point> rightPairs =
                        rightLines.get(rightLine);//Will fix the negative lines soon.
                rightPairs.add(justAPoint);
                rightLines.put(rightLine, rightPairs);
            } else {
                List<Point> L = new ArrayList<>();
                L.add(justAPoint);
                rightLines.put(Y[i] - X[i], L);
            }
            if (leftLines.containsKey(leftLine)) {
                List<Point> leftPairs = leftLines.get(leftLine);//Will fix the negative lines soon.
                leftPairs.add(justAPoint);
                leftLines.put(leftLine, leftPairs);
            } else {
                List<Point> L = new ArrayList<>();
                L.add(justAPoint);
                leftLines.put(Y[i] + X[i], L);
            }
        }
        return chin;
    }
}