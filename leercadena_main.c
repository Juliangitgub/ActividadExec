#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  char *comando[BUFSIZ];
  char **vector;
  int i;

  if(argc==1){
  printf("Indique el programa que desea que se ejecute \n");
  
  }else{
  for(i=1;i<argc;i++){
  comando[i-1]=argv[i];
  }
   pid_t pid;
    //leer_de_teclado(BUFSIZ,comando);

    if (strcmp("exit",comando[0]) == 0) {
     exit(1);
         }
    pid = fork();
    if (pid < 0) {
      perror("No se pudo crear un proceso\n");
      exit(1);
    } else if (pid == 0) {
    
      //vector = de_cadena_a_vector(comando);

      execvp(comando[0],comando);
      perror("Return from execlp() not expected");
      exit(EXIT_FAILURE);
    } else {
      wait(NULL);
    }
  
  
  
  }
   
  

  return 0;
}
