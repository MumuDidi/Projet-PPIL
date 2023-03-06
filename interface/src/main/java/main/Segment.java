package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.List;

public class Segment extends Shape {
    public Segment(List<Point2D> points, Color c) {
        super(points, c);
        if (points.size() != 2) {
            System.out.println("Le segment n'a pas 2 sommets");
        }
    }
}
