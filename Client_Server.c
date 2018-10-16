#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
int main(){
  //create a socket
 int n_Socket=socket(AF_INET,SOCK_STREAM,0);
  //Specify address structure of the socket
 struct sockaddr_in s_Address;
 s_Address.sin_family = AF_INET;
 s_Address.sin_port = htons(9002);
 s_Address.sin_addr.s_addr = INADDR_ANY;

 //conect 
 int c_Status = connect(n_Socket,(struct sockaddr*)&s_Address,sizeof(s_Address));

 //check for connection error
 if(c_Status== -1){
  printf("There is a error connecting to the socket. \n\n\n");
}

//recieve data from server
 char response[300];
 recv(n_Socket,&response,sizeof(response),0);
 
//display received data
 printf("The server has send a message : %s\n",response);

//close the socket
close(n_Socket);

return 0;
}
