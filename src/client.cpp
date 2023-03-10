/*
 * TestClientMajuscule.cpp
 *
 * Client vers le serveur de majuscule.
 *
 * Tâche :
 * 1) demande à l'utilisateur, l'adresse IP et le port du serveur de majuscule
 * 2) se connecte au serveur
 * 3) répète perpétuellement :
 *      saisie d'une chaîne de caractères au clavier
 *      envoi de la chaîne au serveur
 *      réception de la réponse du serveur (qui est la version majuscule de la chaîne envoyée)
 * L'application s'arrête si la chaîne saisie est "quitter"
 *
*/

#include <WinSock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <cmath>
#include <fstream>
#include <vector>
#include "../include/Erreur.h"     // ma petite classe d'erreur personnelle
#include "../include/TriangleLoader.h"
#include "../include/SegmentLoader.h"
#include "../include/CercleLoader.h"

#pragma comment(lib, "ws2_32.lib") // spécifique à VISUAL C++


using namespace std;

#define L 200 // longueur max d'une chaîne de caractères

int main()
{
try
{
//-------------- initialisation ressources librairie winsock -------------------------------

int r;
WSADATA wsaData;        // structure contenant les données de la librairie winsock à initialiser

r = WSAStartup( MAKEWORD(2,0), &wsaData);       // MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2

/* en cas de succès, wsaData a été initialisée et l'appel a renvoyé la valeur 0 */

if (r) throw Erreur("L'initialisation a échoué");

cout << "client vers le serveur java" << endl;
cout << "initialisation effectuée"<<endl;

//---------------------- création socket -------------------------------------------------

SOCKET sock;  // informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole

int familleAdresses = AF_INET;         // IPv4
int typeSocket = SOCK_STREAM;           // mode connecté TCP
int protocole = IPPROTO_TCP;            // protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
                                        // pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock

sock =  socket( familleAdresses, typeSocket, protocole);

if (sock == INVALID_SOCKET)
  {
  ostringstream oss;
  oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;	// pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
  throw Erreur(oss.str().c_str());
  }

cout << "socket créé" << endl;

//------------------------------ création du représentant du serveur ----------------------------------------

char adresseServeur[L];
short portServeur;

cout <<"tapez l'adresse IP du serveur java : " << endl;
cin >> adresseServeur;
cout <<"tapez le port du serveur java : " << endl;
cin >> portServeur;

SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

sockaddr.sin_family = AF_INET;
sockaddr.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
sockaddr.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

//-------------- connexion du client au serveur ---------------------------------------

r = connect( sock, (SOCKADDR * ) &sockaddr, sizeof(sockaddr));     // renvoie une valeur non nulle en cas d'échec.
                                                                // Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

if (r == SOCKET_ERROR)
  throw Erreur("La connexion a échoué");

cout << "connexion au serveur java réussie" << endl;

bool continuer;
do
  {
  char requete[L];
  cout <<"Tapez le nom du fichier ou tapez \"quitter\" : ";
  cin >> requete;
  continuer = strcmp(requete,"quitter") != 0;
  if (continuer){
    //pour que le serveur réceptionne bien le message

    // chargement des formes depuis un fichier
    Loader* Loader1;
    Loader_COR* TriangleLoader1, * SegmentLoader1, * CercleLoader1;
    TriangleLoader1 = new TriangleLoader(NULL);
    SegmentLoader1 = new SegmentLoader(TriangleLoader1);
    CercleLoader1 = new CercleLoader(SegmentLoader1);

    Loader1 = CercleLoader1;
    string line;

    vector<Forme*> Vff;
    ifstream f(requete);
    while (getline(f, line)) {
        cout << line << endl;
        Vff.push_back(Loader1->Load(line));
    }

	string msg;
	char VraiMsg[L];
	vector<Forme*>::iterator it;
	for (it = Vff.begin(); it != Vff.end(); ++it) {
		if (*it != NULL) {
			sscanf((*it)->toString().c_str(), "%s",	VraiMsg);

			strcat(VraiMsg, "\r\n");
			int l = strlen(VraiMsg);

			r = send( sock, VraiMsg, l, 0);             //------------------ envoi de la requête au serveur -------------------------------
                                                // envoie au plus  l octets
    		if (r == SOCKET_ERROR)
       			throw Erreur("échec de l'envoi de la requête");

    		char reponse[L];
    		r = recv( sock, reponse, l, 0);             //----------- réception de la réponse du serveur -----------------------------
                                                // reçoit au plus l octets
                                                // en cas de succès, r contient le nombre d'octets reçus
    		if (r == SOCKET_ERROR)
        		throw Erreur("La réception de la réponse a échouée");

    		char * p = strchr(reponse,'\n');
    		*p = '\0';

    		cout << reponse << endl;
			}
		}
    }
  }
while (continuer);

r = shutdown(sock,SD_BOTH);							// on coupe la connexion pour l'envoi et la réception
													// renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

if (r == SOCKET_ERROR)
	throw Erreur("la coupure de connexion a échoué");


r = closesocket(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
if (r) throw Erreur("La fermeture du socket a échoué");

WSACleanup();
cout << "arrêt normal du client" << endl;
}
catch(Erreur erreur)
  {
  cerr << erreur << endl;
  }


return 0;
}
