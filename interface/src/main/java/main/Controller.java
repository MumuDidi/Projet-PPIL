package main;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.geometry.Point2D;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.stage.FileChooser;

import java.io.*;
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

    @FXML
    private RadioButton circle;
    @FXML
    private Button render_composed;

    private List<Point2D> points = new ArrayList<>();

    // List of Simple Shapes
    private List<Shape> simple = new ArrayList<>();

    // List of Composed Shapes
    private List<Shape> simple2 = new ArrayList<>();
    private List<Group> composed = new ArrayList<>();

    @FXML
    void openFile(ActionEvent event) {
        FileChooser fc = new FileChooser();
        fc.getExtensionFilters().add(new FileChooser.ExtensionFilter("Files", "*.*"));
        File file = fc.showOpenDialog(null);

        if (file != null) {
            path.setText("Selected File : " + file.getAbsolutePath());
        }
    }

    @FXML
    void saveFile(ActionEvent event) {
        FileChooser fc = new FileChooser();
        fc.getExtensionFilters().add(new FileChooser.ExtensionFilter("Files", "*.*"));
        File f = fc.showSaveDialog(null);

        if (f != null) {
            try {
                FileWriter fw = new FileWriter(f);
                for (Shape shape : simple) {
                    fw.write(shape.print() + "\n");
                }
                for (Group group : composed) {
                    fw.write("Groupe(");
                    boolean first = true;
                    for (Shape shape2 : group.getList()) {
                        if (!first) {
                            fw.write(",");
                        }
                        fw.write(shape2.print());
                        first = false;
                    }
                    fw.write(")\n");
                }
                fw.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @FXML
    void Draw(MouseEvent event) {
        RadioButton selectedModeButton = (RadioButton) mode.getSelectedToggle();
        String id = selectedModeButton.getId().toString();
        double x = event.getX(); // Coordonnée x du clic de souris
        double y = event.getY(); // Coordonnée y du clic de souris

        Point2D point = new Point2D(x, y);
        if (!circle.isSelected()) {
            points.add(point);

            GraphicsContext gc = canvas.getGraphicsContext2D();
            gc.setFill(Color.BLACK); // Choix de la couleur de remplissage du cercle (noir ici)
            gc.fillOval(x, y, 5, 5); // Dessin du cercle de rayon 5
        } else if (circle.isSelected() && points.size() < 2) {
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
        if (id.equals("simple")) {

            if (circle.isSelected()) {
                GraphicsContext gc = canvas.getGraphicsContext2D();

                gc.setFill(Color.WHITE);
                for (Point2D point : points) {
                    gc.fillRect(point.getX(), point.getY(), 10, 10);
                }

                double rayon = points.get(0).distance(points.get(1));
                points.remove(1);

                simple.add(new Cercle(points, rayon, getColor()));

                Color color = getColor();
                gc.setFill(color);
                gc.fillOval(points.get(0).getX() - rayon, points.get(0).getY() - rayon, rayon * 2, rayon * 2);
            } else {
                GraphicsContext gc = canvas.getGraphicsContext2D();
                gc.setFill(Color.WHITE);
                for (Point2D point : points) {
                    gc.fillRect(point.getX(), point.getY(), 10, 10);
                }

                if (points.size() > 2) {
                    double[] xPoints = new double[points.size()];
                    double[] yPoints = new double[points.size()];

                    for (int i = 0; i < points.size(); i++) {
                        Point2D point = points.get(i);
                        xPoints[i] = point.getX();
                        yPoints[i] = point.getY();
                    }

                    // Ajouter la forme simple à la liste des formes simples
                    if (points.size() == 3) {
                        simple.add(new Triangle(points, getColor()));
                    }
                    if (points.size() >= 4) {
                        simple.add(new Polygone(points, getColor()));
                    }

                    // Dessiner l'aire de la forme
                    Color color = getColor();
                    gc.setFill(color);
                    gc.fillPolygon(xPoints, yPoints, points.size());
                }

                if (points.size() == 2) {
                    Color color = getColor();
                    gc.setStroke(color);
                    gc.strokeLine(points.get(0).getX(), points.get(0).getY(), points.get(1).getX(), points.get(1).getY());
                    simple.add(new Segment(points, getColor()));
                }
            }
        }

        if (id.equals("composed")) {
            if (circle.isSelected()) {
                GraphicsContext gc = canvas.getGraphicsContext2D();

                gc.setFill(Color.WHITE);
                for (Point2D point : points) {
                    gc.fillRect(point.getX(), point.getY(), 10, 10);
                }

                double rayon = points.get(0).distance(points.get(1));

                points.remove(1);
                simple2.add(new Cercle(points, rayon, getColor()));

                Color color = getColor();
                gc.setFill(color);
                gc.fillOval(points.get(0).getX() - rayon, points.get(0).getY() - rayon, rayon * 2, rayon * 2);
            } else {
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
                    if (points.size() == 3) {
                        simple2.add(new Triangle(points, getColor()));
                    }
                    if (points.size() >= 4) {
                        simple2.add(new Polygone(points, getColor()));
                    }

                    // Dessiner l'aire de la forme
                    Color color = getColor();
                    gc.setFill(color);
                    gc.fillPolygon(xPoints, yPoints, points.size());
                }

                if (points.size() == 2) {
                    Color color = getColor();
                    gc.setStroke(color);
                    gc.strokeLine(points.get(0).getX(), points.get(0).getY(), points.get(1).getX(), points.get(1).getY());
                    simple2.add(new Segment(points, getColor()));
                }
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

    @FXML
    void Switch1(MouseEvent event) {
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFill(Color.WHITE);
        for (Point2D point : points) {
            gc.fillRect(point.getX(), point.getY(), 10, 10);
        }
        points.clear();
        render_composed.setDisable(true);
    }

    @FXML
    void Switch2(MouseEvent event) {
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setFill(Color.WHITE);
        for (Point2D point : points) {
            gc.fillRect(point.getX(), point.getY(), 10, 10);
        }
        points.clear();
        render_composed.setDisable(false);
    }

    @FXML
    void Clear(ActionEvent event) {
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
        simple.clear();
        simple2.clear();
        composed.clear();
    }

    @FXML
    void Composed(MouseEvent event) {
        composed.add(new Group(simple2));
        simple2.clear();
    }

    public static String[] removeEmptyStrings(String[] arr) {
        List<String> list = new ArrayList<>();
        for (String str : arr) {
            if (!str.equals("")) {
                list.add(str);
            }
        }
        return list.toArray(new String[0]);
    }
}