package main;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.geometry.Point2D;
import javafx.scene.Node;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.scene.shape.Polygon;
import javafx.stage.FileChooser;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Controller {
    @FXML
    private Label path;
    @FXML
    private Canvas canvas;
    @FXML
    private ToggleGroup colour;
    @FXML
    private ToggleGroup mode;

    private List<Point2D> points = new ArrayList<> ();

    // List of Simple Shapes
    private List<Shape> simple = new ArrayList<> ();

    // List of Composed Shapes
    private List<Group> composed = new ArrayList<> ();

    @FXML
    void openFile(ActionEvent event) {
        FileChooser fc = new FileChooser();
        fc.getExtensionFilters().add(new FileChooser.ExtensionFilter("Files", "*.*"));
        File file = fc.showOpenDialog(null);

        if(file != null) {
            path.setText("Selected File : " + file.getAbsolutePath());
        }
    }

    @FXML
    void saveFile(ActionEvent event) {
        FileChooser fc = new FileChooser();
        fc.getExtensionFilters().add(new FileChooser.ExtensionFilter("Files", "*.*"));
        File f = fc.showSaveDialog(null);
    }

    @FXML
    void Draw(MouseEvent event) {
        RadioButton selectedModeButton = (RadioButton) mode.getSelectedToggle();
        String id = selectedModeButton.getId().toString();
        double x = event.getX(); // Coordonnée x du clic de souris
        double y = event.getY(); // Coordonnée y du clic de souris

        Point2D point = new Point2D(x, y);
        if(!id.equals("circle")) {
            points.add(point);

            GraphicsContext gc = canvas.getGraphicsContext2D();
            gc.setFill(Color.BLACK); // Choix de la couleur de remplissage du cercle (noir ici)
            gc.fillOval(x, y, 5, 5); // Dessin du cercle de rayon 5
        }
        else if (id.equals("circle") && points.size() < 2) {
            points.add(point);

            GraphicsContext gc = canvas.getGraphicsContext2D();
            gc.setFill(Color.BLACK); // Choix de la couleur de remplissage du cercle (noir ici)
            gc.fillOval(x, y, 5, 5); // Dessin du cercle de rayon 5
        }
    }

    Color getColor() {
        RadioButton selectedColorButton = (RadioButton) colour.getSelectedToggle();
        Color color;
        switch (selectedColorButton.getText().toString()) {
            case "Rouge":
                color = Color.RED;
                break;
            case "Bleu":
                color = Color.BLUE;
                break;
            case "Jaune":
                color = Color.YELLOW;
                break;
            case "Vert":
                color = Color.GREEN;
                break;
            case "Cyan":
                color = Color.CYAN;
                break;
            default:
                color = Color.BLACK;
                break;
        }
        return color;
    }

    @FXML
    void Render(ActionEvent event) {
        RadioButton selectedModeButton = (RadioButton) mode.getSelectedToggle();
        String id = selectedModeButton.getId().toString();
        if(id.equals("simple")) {
            GraphicsContext gc = canvas.getGraphicsContext2D();
            gc.setFill(Color.WHITE);
            for (Point2D point : points) {
                gc.fillRect(point.getX(), point.getY(), 10, 10);
            }

            if (points.size() >= 2) {
                double[] xPoints = new double[points.size()];
                double[] yPoints = new double[points.size()];

                for (int i = 0; i < points.size(); i++) {
                    Point2D point = points.get(i);
                    xPoints[i] = point.getX();
                    yPoints[i] = point.getY();
                }

                // Ajouter la forme simple à la liste des formes simples
                simple.add(new Shape(points, getColor()));

                // Dessiner l'aire de la forme
                Color color = getColor();
                gc.setFill(color);
                gc.fillPolygon(xPoints, yPoints, points.size());
            }

            if(points.size() == 2) {
                gc.strokeLine(points.get(0).getX(), points.get(0).getY(), points.get(1).getX(), points.get(1).getY());
            }
        }

        if(id.equals("circle")) {
            GraphicsContext gc = canvas.getGraphicsContext2D();

            gc.setFill(Color.WHITE);
            for (Point2D point : points) {
                gc.fillRect(point.getX(), point.getY(), 10, 10);
            }

            double rayon = points.get(0).distance(points.get(1));

            simple.add(new Circle(points.get(0), rayon, getColor()));

            Color color = getColor();
            gc.setFill(color);
            gc.fillOval(points.get(0).getX() - rayon, points.get(0).getY() - rayon, rayon * 2, rayon * 2);
        }

        if(id.equals("composed")) {
            GraphicsContext gc = canvas.getGraphicsContext2D();
            gc.setFill(Color.WHITE);
            for (Point2D point : points) {
                gc.fillRect(point.getX(), point.getY(), 10, 10);
            }

            if (points.size() >= 2) {
                double[] xPoints = new double[points.size()];
                double[] yPoints = new double[points.size()];

                for (int i = 0; i < points.size(); i++) {
                    Point2D point = points.get(i);
                    xPoints[i] = point.getX();
                    yPoints[i] = point.getY();
                }

                // Ajouter la forme simple à la liste des formes simples
                simple.add(new Shape(points, getColor()));

                // Dessiner l'aire de la forme
                Color color = getColor();
                gc.setFill(color);
                gc.fillPolygon(xPoints, yPoints, points.size());
            }

            if(points.size() == 2) {
                gc.strokeLine(points.get(0).getX(), points.get(0).getY(), points.get(1).getX(), points.get(1).getY());
            }
        }

        points.clear();
    }

    @FXML
    void Switch(MouseEvent event) {
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFill(Color.WHITE);
        for (Point2D point : points) {
            gc.fillRect(point.getX(), point.getY(), 10, 10);
        }
        points.clear();
    }
}