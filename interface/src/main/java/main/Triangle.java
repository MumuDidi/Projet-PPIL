package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.List;

public class Triangle extends Shape {
    Triangle(List<Point2D> points, Color c) {
        super(points, c);
        if (points.size() != 3) {
            System.out.println("Le triangle n'a pas 3 sommets");
        }
    }
}
