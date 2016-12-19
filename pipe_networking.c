#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_networking.h"

int client_handshake(int *to_server) {
    mkfifo("luigi", 0644); //do some stuff 

    int pkw = open("mario", O_WRONLY);
    write(pkw,"luigi", 5);
    *to_server = pkw;

    int pp = open("luigi", O_RDONLY);
    char buffer[MESSAGE_BUFFER_SIZE];
    read(pp, buffer, sizeof(buffer));
    printf("[CLIENT] Message received: %s\n", buffer);
    int final = open("luigi", O_WRONLY);
    int i = fork();
    if(!i) execlp("rm","rm","luigi",NULL);
    write(final,"CONNECTED",9);
    return final;
}

int server_handshake(int *from_client) {
   char buffer[MESSAGE_BUFFER_SIZE];
   mkfifo("mario", 0644);
   printf("[SERVER] Created WKP\n");
   int wkp = open("mario", O_RDONLY);
   *from_client = wkp;
   printf("[SERVER] Waiting for response..\n");
   read(wkp, buffer, sizeof(buffer));
   printf("[SERVER] Received privacy: %s\n", buffer);
   int j = fork();
   if(!j) execlp("rm","rm","mario",NULL);
   int pp2 = open("luigi", O_WRONLY);
   write(pp2,"connected", 9);
   return pp2;
}
