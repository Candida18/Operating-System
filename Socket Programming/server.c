#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

int main(int argc, char const *argv[])
{    
	int ser_soc,soc,val;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[512] = {0};
    ser_soc = socket(AF_INET, SOCK_STREAM, 0);
    
    if (ser_soc == 0)
    {   	 
		printf("\n ERROR creating socket\n");
    }
    printf("\n Socket Created\n");
	
    if (setsockopt(ser_soc, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&opt, sizeof(opt)))
    {
		perror("setsockopt");
		exit(EXIT_FAILURE);
    }
	
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( 8080 );
    printf("\n Port Added\n");
	
    if (bind(ser_soc, (struct sockaddr *)&address,sizeof(address))<0)
    {
		perror("\n Bind Failed");
		exit(EXIT_FAILURE);
    }
	
    if (listen(ser_soc, 3) < 0)
    {
		printf("\n ERROR Listening Socket\n");
    }
    printf("\n Listening to socket\n");
	
    if ((soc = accept(ser_soc, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0)
    {
		printf("\n ERROR accepting connection\n");
    }
	
    printf("\n Connected Successfully! \n");
    char *mes = "Madam Candida\n";
    
    send(soc , mes , strlen(mes) , 0 );

    return 0;
}
