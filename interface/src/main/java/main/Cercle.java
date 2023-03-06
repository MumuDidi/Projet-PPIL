package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.ArrayList;
import java.util.List;

public class Cercle extends Shape {
    private double rayon;
    private List<Point2D> shape_points = new ArrayList<>();
    private Color color;

    Cercle(List<Point2D> points, double rayon, Color c) {
        super(points, c);
        this.rayon = rayon;
        this.shape_points = List.copyOf(points);
        this.color = c;
    }

    @Override
    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.getClass().getSimpleName());
        sb.append("(");
        for (Point2D point : shape_points) {
            sb.append("(");
            sb.append(point.getX());
            sb.append(",");
            sb.append(point.getY());
            sb.append(")");
            sb.append(",");
        }
        sb.append(rayon);
        sb.append(",");
        sb.append(getColorName(color));
        sb.append(")");
        return sb.toString();
    }
}
