package clientserveur;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class TestServeurMajuscule
{

public static void main(String[] args) 
{
try {
	int port = 9111;
	
	ServerSocket serveur = new ServerSocket(port);
	
	System.out.println("serveur de majuscule pr�t : " + serveur);
	
	
	Canvas canvas = new Canvas(400, 400);

	// Récupérer l'objet GraphicsContext
	GraphicsContext gc = canvas.getGraphicsContext2D();

	// Ajouter le Canvas à une StackPane
	StackPane root = new StackPane();
	root.getChildren().add(canvas);

	// Créer une scène avec la StackPane
	Scene scene = new Scene(root, 400, 400);

	// Créer une fenêtre et afficher la scène
	Stage primaryStage = new Stage();
	primaryStage.setScene(scene);
	primaryStage.show();
	
	int noClient = 1;
	while(true)
		{
		System.out.println("attente du prochain client");
		Socket client = serveur.accept();	// bloquant
		System.out.println("nouveau client connecté : " + client);
		Interlocuteur interlocuteur = new Interlocuteur(client,noClient++);
		interlocuteur.start(gc); // lance la méthode run() du thread en parallèle de main()
		}
	
} 
catch (IOException e) 
{
	// TODO Auto-generated catch block
	e.printStackTrace();
}



}

}
