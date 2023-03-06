package main;

import javafx.geometry.Point2D;
import javafx.scene.paint.Color;

import java.util.ArrayList;
import java.util.List;

public class Shape {
    private List<Point2D> shape_points = new ArrayList<>();
    private Color color;

    Shape(List<Point2D> points, Color c) {
        this.shape_points = List.copyOf(points);
        this.color = c;
    }

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
        sb.append(getColorName(color));
        sb.append(")");
        return sb.toString();
    }

    String getColorName(Color color) {
        // On récupère les valeurs RGB de la couleur
        int red = (int) (color.getRed() * 255);
        int green = (int) (color.getGreen() * 255);
        int blue = (int) (color.getBlue() * 255);

        // On cherche le nom de la couleur en comparant les valeurs RGB avec une liste de couleurs prédéfinies
        if (red == 255 && green == 0 && blue == 0) {
            return "Red ";
        } else if (red == 0 && green == 128 && blue == 0) {
            return "Green ";
        } else if (red == 0 && green == 0 && blue == 255) {
            return "Blue ";
        } else if (red == 0 && green == 0 && blue == 0) {
            return "Black ";
        }
        else if (red == 0 && green == 255 && blue == 255) {
            return "Cyan ";
        }
        else if (red == 255 && green == 255 && blue == 0) {
            return "Yellow ";
        }
        else {
            return color.toString();
        }
    }
}
