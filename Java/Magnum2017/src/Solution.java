import javafx.util.Pair;

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
            } else if (c == 'X') {
                this.value = 0;
            }
        }

    }

    private int maxLeftLine = 0;
    private int maxRightLine = 0;
    private Map<Integer, List<Point>> rightLines;
    private Map<Integer, List<Point>> leftLines;
    private int[][] dp ;

    public int solution(int[] X, int[] Y, String T) {
        rightLines = new HashMap<>();
        leftLines = new HashMap<>();
        Pair<Integer, Integer> chinPair = initializeMaps(X, Y, T);
        //need to do the sort.
        //try right first.
        int x = pullRight(new Point(chinPair.getKey(), chinPair.getValue(), 'X'));
        int y = pullLeft(new Point(chinPair.getKey(), chinPair.getValue(), 'X'));
        return Math.max(x, y);
    }

    private int pullLeft(Point point) {

        int rightLine = point.y - point.x;
        int leftLine = point.y + point.x;
        List<Point> points = leftLines.get(point.y + point.x);
        if (points == null) return 0;
        Point imaginaryNextPoint = new Point(point.x - 1, point.y + 1, 'X');
        int imaginaryPointIndex = binarySearchLeftLines(points, imaginaryNextPoint);
        int myPointIndex = binarySearchLeftLines(points, point);
        if (imaginaryPointIndex >= 0) { //if the list is always sorted, this means i'm blocked by a point.
            return 0; //this basically means the imaginary Point right after me was found.
        }
        imaginaryPointIndex++;
        imaginaryPointIndex *= -1;
        //imaginaryPointIndex points to the position after mine on the right line
        if (imaginaryPointIndex == points.size()) { //That means i have no further points on this line
            for (int i = ( - point.x + point.y + 1); i <= maxRightLine; i++) {
                if (rightLines.containsKey(i)) //FOR LOOP HERE FOR ALL REMAINING LEFT LINES
                {
                    Point intersectionPoint = new Point((i - leftLine) / 2, (i + leftLine) / 2, 'X');
                    if (intersectionPoint.y > point.y )
                        return pullLeft(intersectionPoint) + point.value;
                }
            }
            return point.value;
        }

        if (imaginaryPointIndex < points.size()) {
            return Math.max(pullLeft(points.get(myPointIndex + 1)), pullRight(imaginaryNextPoint)) + point.value;
        }
        return -99999;
    }


    private int pullRight(Point point) {

        int rightLine = point.y - point.x;
        int leftLine = point.y + point.x;
        List<Point> points = rightLines.get(rightLine);
        if (points == null) return 0;
        Point imaginaryNextPoint = new Point(point.x + 1, point.y + 1, 'X');
        int imaginaryPointIndex = binarySearchRightLines(points, imaginaryNextPoint);
        int myPointIndex = binarySearchRightLines(points, point);
        if (imaginaryPointIndex >= 0) { //if the list is always sorted, this means i'm blocked by a point.
            return 0; //this basically means the imaginary Point right after me was found.
        }
        imaginaryPointIndex++;
        imaginaryPointIndex *= -1;
        //imaginaryPointIndex points to the position after mine on the right line
        if (imaginaryPointIndex == points.size()) { //That means i have no further points on this line
            for (int i = (point.x + point.y + 1); i <= maxLeftLine; i++) {
                if (leftLines.containsKey(i)) //FOR LOOP HERE FOR ALL REMAINING LEFT LINES
                {
                    Point intersectionPoint = new Point((i - rightLine) / 2, (i + rightLine) / 2, 'X');
                    if (intersectionPoint.y > point.y )
                        return pullLeft(intersectionPoint) + point.value;
                }
            }
            return point.value;
        }
        if (imaginaryPointIndex < points.size()) {
            return Math.max(pullRight(points.get(myPointIndex + 1)), pullLeft(imaginaryNextPoint)) + point.value;
        }
        return -99999;
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


    private Pair<Integer, Integer> initializeMaps(int[] X, int[] Y, String T) {

        Pair<Integer, Integer> chin = null;
        for (int i = 0; i < X.length; i++) {
            if (T.charAt(i) == 'X') {
                chin = new Pair<>(X[i], Y[i]); //possibly this needs to be removed and we start the initialization -1 of chin
                continue;
            }
            int rightLine = Y[i] - X[i];
            int leftLine = Y[i] + X[i];
            maxLeftLine = Math.max(maxLeftLine, leftLine);
            maxRightLine = Math.max(maxRightLine, rightLine);
            //dp = new int[maxRightLine][maxLeftLine];
            Point justAPoint = new Point(X[i], Y[i], T.charAt(i));

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