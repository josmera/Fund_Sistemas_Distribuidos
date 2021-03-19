#include "leercadena.h"
#include "tcp.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void func(int sockfd, char* buff) {
	 
	TCP_Write_String(sockfd, buff); 
} 

int enviaDato(char *comando) { 
  
	int sockfd, port; 
	char *host;
	

	host = "localhost";
	port = 12358;

	printf("Intentando conectar con <%s,%d>\n",host,port);

	sockfd = TCP_Open(Get_IP(host),port);

	// function for chat 
	char *buff = comando;
	printf("\033[1m\033[33m");//Cambiar el color y estilo de fuente para el texto a continuación
	printf("prompt@miniserver:/>");	
	printf("\033[0m");//Reestablece los valores de color y estilo de fuente
	leer_de_teclado(BUFSIZ,buff);

	func(sockfd, buff); 

	// close the socket 
	close(sockfd); 
} 

int main(int argc, char *argv[]) {

  char comando[BUFSIZ];

  enviaDato(comando);
  
  return 0;

}
