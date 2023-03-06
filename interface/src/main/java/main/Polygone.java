package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.List;

public class Polygone extends Shape {
    Polygone(List<Point2D> points, Color c) {
        super(points, c);
        if (points.size() <=3) {
            System.out.println("Il ne s'agit pas d'un polygone : 3 ou moins sommets");
        }
    }
}