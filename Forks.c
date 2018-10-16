#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){


//Initializing array of 1000 numbers

 const int SIZE=1000;
 int big_Array[SIZE];
 for(int i=0;i<1000;i++)
{
 big_Array[i]= i;
}


//creating 10 arrays for child processes and passing them in the the pipe

 int s_Array1[2],s_Array2[2],s_Array3[2],s_Array4[2],s_Array5[2],
     s_Array6[2],s_Array7[2],s_Array8[2],s_Array9[2],s_Array10[2];
 
 pipe(s_Array1),pipe(s_Array2),pipe(s_Array3),pipe(s_Array4),pipe(s_Array5),
 pipe(s_Array6),pipe(s_Array7),pipe(s_Array8),pipe(s_Array9),pipe(s_Array10);


//now using fork() i am going to create 10 child processes
//and in each child process i am going to find sum of 100 inedexes
//and then write the sum in s_Array and the in the parrent process
//i will read from all the s_Array and sum the to get the sum of big_Array

 int s;
 int cpid1=fork();
 if(cpid1==0){
   for(int i=0;i<100;i++){
   s=0;
   s=s+big_Array[i];
 }
 write(s_Array1[1],&s,sizeof(int));
 close(s_Array1[1]);
 exit(0);
 }else{
  int cpid2=fork();
 if(cpid2==0){
   for(int i=100;i<200;i++){
   s=0;
   s=s+big_Array[i];
 }
 write(s_Array2[1],&s,sizeof(int));
 close(s_Array2[1]);
 exit(0);
 }else{
  int cpid3=fork();
 if(cpid3==0){
   for(int i=300;i<300;i++){
   s=0; 
   s=s+big_Array[i];
 }
 write(s_Array3[1],&s,sizeof(int));
 close(s_Array3[1]);
 exit(0);
 }else{
  int cpid4=fork();
 if(cpid4==0){
   for(int i=300;i<400;i++){
   s=0;
   s=s+big_Array[i];
 }
 write(s_Array4[1],&s,sizeof(int));
 close(s_Array4[1]);
 exit(0);
 }else{
 int cpid5=fork();
 if(cpid5==0){
   for(int i=400;i<500;i++){
  s=0;  
 s=s+big_Array[i];
 }
 write(s_Array5[1],&s,sizeof(int));
 close(s_Array5[1]);
 exit(0);
 }else{
  int cpid6=fork();
 if(cpid6==0){
   for(int i=500;i<600;i++){
   s=0;
   s=s+big_Array[i];
 }
 write(s_Array6[1],&s,sizeof(int));
 close(s_Array6[1]);
 exit(0);
 }else{
  int cpid7=fork();
 if(cpid7==0){
   for(int i=600;i<700;i++){
  s=0; 
  s=s+big_Array[i];
 }
 write(s_Array7[1],&s,sizeof(int));
 close(s_Array7[1]);
 exit(0);
 }else{
  int cpid8=fork();
 if(cpid8==0){
   for(int i=700;i<800;i++){
 s=0;   
 s=s+big_Array[i];
 }
 write(s_Array8[1],&s,sizeof(int));
 close(s_Array8[1]);
 exit(0);
 }else{
  int cpid9=fork();
 if(cpid9==0){
   for(int i=800;i<900;i++){
  s=0; 
  s=s+big_Array[i];
 }
 write(s_Array9[1],&s,sizeof(int));
 close(s_Array9[1]);
 exit(0);
 }else{ 
  int cpid10=fork();
 if(cpid10==0){
   for(int i=900;i<1000;i++){
 s=0;  
 s=s+big_Array[i];
 }
 write(s_Array10[1],&s,sizeof(int));
 close(s_Array10[1]);
 exit(0);
 }
}
}
}
}
}
}
}
}
}

//creating 10 variables to read from s_Arrays and then summing them to get 
//Sum of big_Array
 int v1,v2,v3,v4,v5,v6,v7,v8,v9,v10;
 read(s_Array1[0],&v1,sizeof(int));
 close(s_Array1[0]); 
 read(s_Array2[0],&v2,sizeof(int));
 close(s_Array2[0]);
 read(s_Array3[0],&v3,sizeof(int));
 close(s_Array3[0]);
 read(s_Array4[0],&v4,sizeof(int));
 close(s_Array4[0]); 
 read(s_Array5[0],&v5,sizeof(int));
 close(s_Array5[0]); 
 read(s_Array6[0],&v6,sizeof(int));
 close(s_Array6[0]); 
 read(s_Array7[0],&v7,sizeof(int));
 close(s_Array7[0]);
 read(s_Array8[0],&v8,sizeof(int));
 close(s_Array8[0]);
 read(s_Array9[0],&v9,sizeof(int));
 close(s_Array9[0]);
 read(s_Array10[0],&v10,sizeof(int));
 close(s_Array10[0]);

//Display sum of big_Array
 int Sum = v1+v2+v3+v4+v5+v6+v7+v8+v9+v10;
 printf("Sum of Array is %d\n",Sum); 
  
  
  
  
  
 
 return 0;
}
