import java.io.*;
import java.net.*;
import java.util.*;


class Serveur implements Runnable {
Socket socketClient;
private static final int NB_SOCKETS_EN_PARALLELE=10;
static final String fichierParDefaut="insa.html";
static final File WEB_ROOT =new File(".");

Serveur(Socket socketClient) {
  this.socketClient=socketClient;
  }

private String lireRequete() throws java.io.IOException {
  InputStream is =socketClient.getInputStream();
  InputStreamReader isr =new InputStreamReader(is);
  BufferedReader fluxEntree=new BufferedReader(isr);
  String format=fluxEntree.readLine();
  return format;
}

private byte[] lireFichier(File Fichier, int tailleFichier) throws IOException {
  FileInputStream fin = null;
  byte[] data = new byte[tailleFichier];

  try {
    fin = new FileInputStream(Fichier);
    fin.read(data);
  } finally {
    if (fin != null)
      fin.close();
  }
  return data;
}

private String getContentType(String fichier) {
  if ( fichier.endsWith(".htm") || fichier.endsWith(".html"))
    return "text/html";
  else
    return "text/plain";
}
private void envoyerResultat(String format) throws java.io.IOException {
    OutputStream os = socketClient.getOutputStream();
    // récupère le flux de sortie binaire sur le client (pour les données demandées)
    BufferedOutputStream fluxSortie=new BufferedOutputStream(os);
    //pour les entete
    PrintWriter out = new PrintWriter(os);
    String input = format;
    StringTokenizer parse = new StringTokenizer(input);
    // on obtient la méthode HTTP du client
    String method = parse.nextToken().toUpperCase();
    String fichierVoulu = parse.nextToken().toLowerCase();


     if (fichierVoulu.endsWith("/")) {
            fichierVoulu += fichierParDefaut;
       }

  File fichier =new File(WEB_ROOT,fichierVoulu);
  int tailleFichier = (int) fichier.length();
  String content=getContentType(fichierVoulu);

  if (method.equals("GET")) {
          byte[] data = lireFichier(fichier,tailleFichier);
     // envoyer des en-têtes HTTP
          out.println("HTTP/1.0 200 OK");
          out.println("Server: Java HTTP Server");
          out.println("Date: " + new Date());
          out.println("Content-type: " + content);
          out.println("Content-length: " + tailleFichier);
          out.println();
          out.flush();
         fluxSortie.write(data,0,tailleFichier);
         fluxSortie.flush();
  }
}
@Override
public void run() {
  // nous gérons notre connexion cliente particulière
try {
      envoyerResultat(lireRequete());
      socketClient.close();
} catch (Exception e) {
      System.out.println("");
}
}


public static void main(String[] args)throws Exception {
  final   int NB_SOCKETS_EN_PARALLELE=10;
  ServerSocket socketDEcoute;
  String adresseIPDEcoute = "127.0.0.1";
  int portTCPDEcoute =8080;
  switch(args.length) {
    case 1 :
  adresseIPDEcoute=args[0];
    break;
    case 2 :
  adresseIPDEcoute=args[0];
  portTCPDEcoute=new Integer(args[1]).intValue();
    break;
}
try
{
  socketDEcoute=new ServerSocket(portTCPDEcoute,NB_SOCKETS_EN_PARALLELE,InetAddress.getByName(adresseIPDEcoute));
for(;;){
  // crée un thread dédié pour gérer la connexion client
new Thread(new Serveur(socketDEcoute.accept())).start();
}
}
catch
(Exception e) {
System.out.println("Erreur "+e);
}
}
}
