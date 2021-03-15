#include "leercadena.h"
#include "tcp.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void func(int sockfd, char* buff[]) 
{ 
	TCP_Write_String(sockfd, buff); 
} 

int enviaDato(char* vector) { 
  
	int sockfd, port; 
	char *host;


	host = "localhost";
	port = 12358;

	printf("Looking to connect at <%s,%d>\n",host,port);
	sockfd = TCP_Open(Get_IP(host),port);
	// function for chat 
	char *buff = vector; 
	func(sockfd, buff); 

	// close the socket 
	close(sockfd); 
} 

int main(int argc, char *argv[]) {
  char comando[BUFSIZ];
  char **vector;

  printf("Digite su comando: ");
  leer_de_teclado(BUFSIZ,comando);
  vector = de_cadena_a_vector(comando);
  int i = 0;
  while (vector[i]) 
   // printf("%s\n",);
    enviaDato(vector[i++]);
  
  return 0;
}
