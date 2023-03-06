package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.List;

public class Cercle extends Shape {
    private double rayon;

    Cercle(List<Point2D> points, double rayon, Color c) {
        super(points, c);
        this.rayon = rayon;
    }
}
