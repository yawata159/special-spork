#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_networking.h"

int client_handshake(int *to_server) {
    int pid = getpid();
    mkfifo("luigi", 0644); //do some stuff 
    int pkw = open("mario", O_WRONLY);
    write(pkw,"luigi", 5);
    int pp = open("luigi", O_RDWR);
    char ack[MESSAGE_BUFFER_SIZE];
    read(pp, ack, sizeof(ack));
    int i = fork();
    if(!i) execlp("rm","rm","luigi",NULL);
    write(pp,"CONNECTED",9);
}

int server_handshake(int *from_client) {
   char buffer[MESSAGE_BUFFER_SIZE];
   mkfifo("mario", 0644);
   printf("[SERVER] Created WKP\n");
   int wkp = open("mario", O_RDONLY);
   read(wkp, buffer, sizeof(buffer));
   int j = fork();
   if(!j) execlp("rm","rm","mario",NULL);
   int pp2 = open(buffer, O_WRONLY);
   write(pp2,"connected", 9);

}
