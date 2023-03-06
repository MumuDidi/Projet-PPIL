package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

import javafx.fxml.FXML;

import javafx.scene.canvas.Canvas;


public class Interlocuteur extends Thread{
	@FXML
	Canvas canvas;
	int noClient;
	private BufferedReader fluxEntrant;
	private PrintStream fluxSortant;
	public Interlocuteur(Socket socket, int noClient) throws IOException {
			this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
				this.fluxSortant = new PrintStream(socket.getOutputStream());
					this.noClient = noClient;
	}


	@Override
	public void run() {
		try {
			while(!this.isInterrupted()){
				String requete = this.fluxEntrant.readLine();
				System.out.println("le client n°" + this.noClient + " a envoyé : " + requete);
					String[] parts = requete.trim().split("\\[(),\\]");

					this.fluxSortant.println("Forme reçue");
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

