package main;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServeurJava
{

public static void main(String[] args) 
{
try {
	int port = 9111;
	
	ServerSocket serveur = new ServerSocket(port);
	
	System.out.println("serveur d'affichage de formes prêt : " + serveur);
	
	int noClient = 1;
	while(true)
		{
		System.out.println("attente du prochain client");
		Socket client = serveur.accept();	// bloquant
		System.out.println("nouveau client connecté : " + client);
		Interlocuteur interlocuteur = new Interlocuteur(client,noClient++);
		interlocuteur.start(); // lance la méthode run() du thread en parallèle de main()
		}
	
} 
catch (IOException e) 
{
	// TODO Auto-generated catch block
	e.printStackTrace();
}



}

}
