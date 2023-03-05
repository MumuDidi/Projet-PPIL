package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.List;

public class Polygon extends Shape {
    Polygon(Point2D point, Color c) {
        super((List<Point2D>) point, c);
    }
}