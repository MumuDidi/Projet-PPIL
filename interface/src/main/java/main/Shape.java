package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.ArrayList;
import java.util.List;

public class Shape {
    private List<Point2D> shape_points = new ArrayList<>();
    private Color color;

    Shape(List<Point2D> points, Color c) {
        this.shape_points = points;
        this.color = c;
    }
}
