package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.List;

public class Circle extends Shape {
    private double rayon;

    Circle(Point2D point, double rayon, Color c) {
        super((List<Point2D>) point, c);
        this.rayon = rayon;
    }
}
