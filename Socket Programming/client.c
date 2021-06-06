#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <string.h>

void palin(char str[])
{
	int cou= 0;
	int len = strlen(str) - 1;
 	while (len > cou)
	{
    	if (str[cou++] != str[len--])
    	{
        	printf("\n %s is Not a Palindrome", str);
        	return;
    	}
	}
	printf("\n %s is a Palindrome", str);
}

void uper(char sa[])
{
	for (int i = 0; sa[i]!='\0'; i++) 
	{
		if(sa[i] >= 'a' && sa[i] <= 'z') 
		{
			sa[i] = sa[i] -32;
		}
	}
	printf("\n String in Upper Case = %s", sa);
}

void getdat(char *s)
{
	char * token = strtok(s, " ");
	char *a[10];
	char * mm;
	char * ll;
	int c=0;

	printf("1");
	for(int i =0;token != NULL;i++)
	{
		a[i] = token;
		token = strtok(NULL, " ");    
	}
	palin(a[0]);
	uper(a[1]);
}  

void cre(char *q)
{
	int ass[2];
  	if(pipe(ass)==-1)
	{
		printf("\n ERROR using pipe");
	}
    printf("\n Creating fork\n");
	int f = fork();
	printf("2");
	if(f == 0)
	{
		printf("child process\n");
		write(ass[1],&q,sizeof(q));
		printf("child process completed\t%s\n",q);
		close(ass[1]);
	}
	else
	{
		char hm[20];
		printf("parent process");
		read(ass[0],hm,sizeof(q));
		printf("........%s",hm);
		getdat(hm);
    }
}

int main(int argc, char const *argv[])
{
    int sock = 0, val;
    struct sockaddr_in serv_addr;
    char buffer[512] = {0};
	
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
		printf("\n Socket creation error \n");
		return -1;
    }
	
    printf(" Socket created\n");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
	
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
		printf("\n Invalid address / Address not supported \n");
		return -1;
    }
	
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
		printf("\n Connection Failed \n");
		return -1;
    }
    printf(" Connected Sucessfully\n");
      
    val = read( sock , buffer, 512);
    printf(" Received from server : %s\n",buffer );

	int ass[2];
  	if(pipe(ass)==-1)
	{
		printf("\n ERROR using pipe");
	}
    printf("\n Creating fork\n");
	
	int f = fork();
	printf("2");
	if(f == 0)
	{
		printf(" Child process\n");
		write(ass[1],&buffer,sizeof(buffer));
		printf(" Child Process completed\t%s\n",buffer);
		close(ass[1]);
	}
	else
	{
		char hm[20];
		printf(" Parent process");
		read(ass[0],hm,sizeof(buffer));
		printf("........%s",hm);
		getdat(hm);
    }
	
    printf("\n\n\n");;

    return 0;
}
