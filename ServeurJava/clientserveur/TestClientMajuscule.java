package clientserveur;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.InetAddress;
import java.net.Socket;

public class TestClientMajuscule
{

public static void main(String[] args) 
{
try {
	BufferedReader clavier = new BufferedReader(new InputStreamReader(System.in));
		
	System.out.println("Tapez l'adresse IP du serveur");
	String sAdresseServeur = clavier.readLine().trim();
	
	InetAddress adresseServeur = InetAddress.getByName(sAdresseServeur);
	
	System.out.println("Tapez le port du serveur");
	int portServeur = Integer.parseInt(clavier.readLine().trim());
	
	Socket socket = new Socket(adresseServeur, portServeur);
	
	System.out.println("socket créé : " + socket);
	
	BufferedReader fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));
	PrintStream fluxSortant = new PrintStream(socket.getOutputStream());
	
	boolean continuer = true;
	do
	{
	System.out.println("Tapez la chaîne à mettre en majuscules ou \"quitter\" pour terminer l'application");
	String requete = clavier.readLine();
	
	if (requete.equalsIgnoreCase("quitter"))
		continuer = false;
	else
	{
		fluxSortant.println(requete);
		String reponse = fluxEntrant.readLine();
		System.out.println(reponse);
	}
	
	}
	while(continuer);
	
	System.out.println("arrêt de l'application à votre demande");
	socket.close();
	
} catch (NumberFormatException | IOException e) {
	// TODO Auto-generated catch block
	e.printStackTrace();
}

}

}
