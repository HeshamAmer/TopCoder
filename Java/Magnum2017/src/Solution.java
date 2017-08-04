
import java.util.*;

public class Solution {


    private class Point {
        public int x, y, value;
        char c;

        Point(int x, int y, char c) {
            this.x = x;
            this.y = y;
            this.c = c;
            if (c == 'p')
                this.value = 1;
            else if (c == 'q') {
                this.value = 10;
            } else if (c == 'X')
                this.value = 0;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    ", value=" + value +
                    '}';
        }
    }

    private int maxLeftLine = 0;
    private int maxRightLine = 0;
    private Map<Integer, List<Point>> rightLines;
    private Map<Integer, List<Point>> leftLines;
    private int[][] dp;

    public int solution(int[] X, int[] Y, String T) {
        rightLines = new HashMap<>();
        leftLines = new HashMap<>();
        initializeMaps(X, Y, T);
        int index=0;
        for (int i=0;i<T.length();i++){
            if (T.charAt(i) == 'X')
                index = i;
        }
        int chinX = X[index];
        int chinY = Y[index];
        int chinRightLine = Y[index]-X[index];
        int chinLeftLine = Y[index] +X[index];
        final int x1 = binarySearchRightLines( rightLines.get( chinRightLine ), new Point( chinX, chinY, 'x' ) );
        final int y1 = binarySearchLeftLines( leftLines.get( chinLeftLine ), new Point( chinX, chinY, 'x' ) );

        //need to do the sort.
        //try right first.
        int x=0,y=0;
        if (rightLines.get( chinRightLine ).size()>1)
            x = pullRight(rightLines.get( chinRightLine ).get( x1+1 ));
        if (leftLines.get( chinLeftLine ).size()>1)
            y = pullLeft(leftLines.get( chinLeftLine ).get( y1+1 ));
        return Math.max(x, y);
    }

    private int pullLeft(Point point) {

        int rightLine = point.y - point.x;
        int leftLine = point.y + point.x;
        List<Point> points = leftLines.get(point.y + point.x);
        if (points == null) return 0;
        int myPointIndex = binarySearchLeftLines(points, point);
        if (myPointIndex < 0) {
            myPointIndex = ++myPointIndex * -1;
        }
        int y = 0;
        if (myPointIndex < points.size() -1 ) { //That means im the last point on this line
            Point nextPoint = points.get(myPointIndex + 1);
            if (nextPoint.x == point.x -1&& nextPoint.y == point.y + 1 )
                if (point.c != 'X')
                    return 0; //this basically means the imaginary Point right after me was found but i'm not chin.
            y = pullLeft(nextPoint) + point.value;
        }
        for (rightLine = rightLine +1 ; rightLine <= maxRightLine; rightLine++) {
            if (rightLines.containsKey(rightLine)) {
                List<Point> points1 = rightLines.get(rightLine);
                Point intersectionPoint = new Point((-rightLine + leftLine) / 2, (rightLine + leftLine) / 2, 'x');
                if (intersectionPoint.y > point.y ) {
                    int i = binarySearchRightLines(points1, intersectionPoint);
                    if ( i >= 0){
                        return Math.max(y, pullLeft(points1.get(i)) + point.value);
                    } else {
                        return Math.max(y, pullRight(intersectionPoint) + point.value);
                    }
                }
            }
        }
        return point.value;
    }


    private int pullRight(Point point) {

        int rightLine = point.y - point.x;
        int leftLine = point.y + point.x;
        List<Point> points = rightLines.get(rightLine);
        if (points == null) return 0;
        int myPointIndex = binarySearchRightLines(points, point);
        if (myPointIndex < 0) {
            myPointIndex = ++myPointIndex * -1;
        }
        int x = 0;

        if (myPointIndex < points.size() -1 ) { //That means i have no further points on this line
            Point nextPoint = points.get(myPointIndex + 1);

            if (nextPoint.x == point.x + 1 && nextPoint.y  == point.y + 1)
                if (point.c != 'X')
                    return 0; //this basically means the imaginary Point right after me was found but i'm not chin
            x = pullRight(nextPoint) + point.value;
        }
        for (leftLine = leftLine+1; leftLine <= maxLeftLine; leftLine++) {
            if (leftLines.containsKey(leftLine)) {
                List<Point> points1 = leftLines.get(leftLine);
                Point intersectionPoint = new Point((leftLine - rightLine) / 2, (leftLine + rightLine) / 2, 'x');
                if (intersectionPoint.y > point.y) {
                    int i = binarySearchLeftLines(points1, intersectionPoint);
                    if ( i >= 0) {
                        return Math.max(x, pullRight(points1.get(i)) + point.value);
                    } else {
                        return Math.max(x, pullLeft(intersectionPoint) + point.value);
                    }
                }
            }
        }
        return point.value;
    }

    private int binarySearchRightLines(List<Point> points, Point point) {
        return Collections.binarySearch(points, point, (Point o1, Point o2) -> {
            if (o1.y > o2.y) return 1;
            else if (o1.y < o2.y) return -1;
            else return 0;
        });
    }

    private int binarySearchLeftLines(List<Point> points, Point point) {
        return Collections.binarySearch(points, point, (Point o1, Point o2) -> {
            if (o1.x > o2.x) return -1;
            else if (o1.x < o2.x) return 1;
            else return 0;
        });
    }


    private void  initializeMaps(int[] X, int[] Y, String T) {
        for (int i = 0; i < X.length; i++) {
            int rightLine = Y[i] - X[i];
            int leftLine = Y[i] + X[i];
            maxLeftLine = Math.max(maxLeftLine, leftLine);
            maxRightLine = Math.max(maxRightLine, rightLine);
            //dp = new int[maxRightLine][maxLeftLine];
            Point justAPoint = new Point(X[i], Y[i], T.charAt(i));

            if (rightLines.containsKey(rightLine)) {
                List<Point> rightPointsList =
                        rightLines.get(rightLine);//Will fix the negative lines soon.
                int i1 = binarySearchRightLines(rightPointsList, justAPoint);
                rightPointsList.add((i1 + 1) * -1, justAPoint);
                rightLines.put(rightLine, rightPointsList);
            } else {
                List<Point> L = new ArrayList<>();
                L.add(justAPoint);
                rightLines.put(Y[i] - X[i], L);
            }
            if (leftLines.containsKey(leftLine)) {
                List<Point> leftPointsList = leftLines.get(leftLine);//Will fix the negative lines soon.
                int i1 = binarySearchRightLines(leftPointsList, justAPoint);
                leftPointsList.add((i1 + 1) * -1, justAPoint);
                leftLines.put(leftLine, leftPointsList);
            } else {
                List<Point> L = new ArrayList<>();
                L.add(justAPoint);
                leftLines.put(Y[i] + X[i], L);
            }
        }
    }
}