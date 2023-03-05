package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.List;

public class Triangle extends Shape {
    Triangle(Point2D point, Color c) {
        super((List<Point2D>) point, c);
    }
}
