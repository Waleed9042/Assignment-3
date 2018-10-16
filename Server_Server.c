#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){

//write a message to be sent over to the client
 char message[300]="Hello World .. :) ";

//create the server socket
 int s_Socket = socket(AF_INET,SOCK_STREAM,0);

//specify address structure
 struct sockaddr_in c_Address;
 c_Address.sin_family =AF_INET;
 c_Address.sin_port =htons(9002);
 c_Address.sin_addr.s_addr =INADDR_ANY;

//bind the socket to the ip and port
 bind(s_Socket,(struct sockaddr*)&c_Address,sizeof(c_Address));

//listen to the socket
 listen(s_Socket,3);

//send data through a socket
 int c_Socket = accept(s_Socket,NULL,NULL);
 send(c_Socket,message,sizeof(message),0);

//close the socket
 close(s_Socket);
  return 0;
}
