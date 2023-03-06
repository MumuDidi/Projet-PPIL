package clientserveur;

import java.awt.geom.Point2D;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Interlocuteur extends Thread{
	int noClient;
	private BufferedReader fluxEntrant;
	private PrintStream fluxSortant;
	public Interlocuteur(Socket socket, int noClient) throws IOException {
			this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				this.fluxSortant = new PrintStream(socket.getOutputStream());
					this.noClient = noClient;

	
	public static String[] removeEmptyStrings(String[] arr) {
	    List<String> list = new ArrayList<>();
	    for (String str : arr) {
	        if (!str.equals("")) {
	            list.add(str);
	        }
	    }
	    return list.toArray(new String[0]);
	}
	

	@Override
	public void run() {
		try {			
			while(!this.isInterrupted()){
				String requete = this.fluxEntrant.readLine();
				System.out.println("le client n°" + this.noClient + " a envoyé : " + requete);
					for(int k = 0; k < requete.length() ; k++) {
						
					}
					String[] parts = requete.trim().split("\\[(),\\]");
					String[] clean = removeEmptyStrings(parts);
					String shape = clean[0];
					Point2D[] points = new Point2D[3];
					Color color = null;
					switch (shape) {
					case "Triangle":
						for (int j = 0; j < 3; j++) {
							double x = Double.parseDouble(clean[2*j+1]);
							double y = Double.parseDouble(clean[2*j+2]);
							points[j] = new Point2D.Double(x, y);
						}
						color = Color.web(clean[7]);
						gc.setFill(color);
						gc.fillPolygon(new double[]{points[0].getX(), points[1].getX(), points[2].getX()}, new double[]{points[0].getY(), points[1].getY(), points[2].getY()}, 3);
						break;
					case "Segment":
						double startX = Double.parseDouble(clean[1]);
						double startY = Double.parseDouble(clean[2]);
						double endX = Double.parseDouble(clean[3]);
						double endY = Double.parseDouble(clean[4]);
						color = Color.web(clean[5]);
						gc.setStroke(color);
						gc.strokeLine(startX, startY, endX, endY);
						break;
					case "Cercle":
						double centerX = Double.parseDouble(clean[1]);
						double centerY = Double.parseDouble(clean[2]);
						double radius = Double.parseDouble(clean[3]);
						color = Color.web(clean[4]);
						gc.setFill(color);
						gc.fillOval(centerX - radius, centerY - radius, 2*radius, 2*radius);
						
						break;
					default:
						break;
					}
					this.fluxSortant.println("bip");
				}
			}
			
		catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		catch(NullPointerException e){
			System.out.println("le client n° "+ this.noClient + " a mis fin à la conversation");
		}

		System.out.println("arrêt du thread n° " + this.noClient);
	}
}

