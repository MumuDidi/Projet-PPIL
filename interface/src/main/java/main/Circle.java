package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.List;

public class Circle extends Shape {
    private double rayon;

    Circle(List<Point2D> points, double rayon, Color c) {
        super(points, c);
        this.rayon = rayon;
    }
}
