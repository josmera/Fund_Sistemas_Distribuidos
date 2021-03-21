#include "leercadena.h"
#include "tcp.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void hijoCliente(int sockfd, char* buff) {

	 printf("CHILD <%ld> Press any key to make me call exec!\n", (long) getpid());

	TCP_Write_String(sockfd, buff); 
} 

padreCliente(pid_t pid) { 
         
         
	int sockfd, port; 
	char *host;
	

	host = "localhost";
	port = 12358;

	printf("Intentando conectar con <%s,%d>\n",host,port);

	sockfd = TCP_Open(Get_IP(host),port);

	// function for chat 
	char *buff;
	printf("\033[1m\033[33m");//Cambiar el color y estilo de fuente para el texto a continuación
	printf("prompt@miniserver:/>");	
	printf("\033[0m");//Reestablece los valores de color y estilo de fuente
	leer_de_teclado(BUFSIZ,buff);
	
	//Crear hijo para enviar los comandos leidos desde terminal al servidor
	
	pid = fork();
	
	printf("PARENT <%ld> Spawned a child with PID = %ld.\n", (long) getpid(), (long)pid);
	
	hijoCliente(sockfd, buff); 
		
	int status;
	
	//Esperar por la terminación del hijo
        wait(&status);

        if(WIFEXITED(status)){
                // close the socket 
		close(sockfd); 
		
		 printf("PARENT <%ld> Child with PID = %ld and exit status = %d terminated. \n", (long) getpid());
		 
        }

} 

int main(void) {

        pid_t pid;

	int i;

	if (i ==0){
		
		padreCliente(pid);
		i=1;
	}
	
		
        

  return 0;

}
