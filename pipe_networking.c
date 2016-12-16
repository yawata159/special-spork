#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "pipe_networking.h"

int client_handshake(int *to_server) {
    int pid = getpid();
    mkfifo( //do some stuff 
}

int server_handshake(int *from_client) {
   char buffer[MESSAGE_BUFFER_SIZE];
   mkfifo("mario", 0644);
   printf("[SERVER] Created WKP");
   int wkp = open("mario", O_RDONLY);
   read(wkp, buffer, sizeof(buffer));

}
