#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pipe_networking.h"

void process( char * s );

int main() {

  int to_client, from_client;
  char buffer[MESSAGE_BUFFER_SIZE];
  
  to_client = server_handshake( &from_client );
    
  printf("to_client: %d\n from_client: %d\n", to_client, from_client);

 while(read( from_client, buffer, sizeof(buffer))){
  printf("[SERVER] Recieved message: %s\n", buffer);
  process( buffer );
  write( to_client, buffer, sizeof(buffer));
 }

  return 0;
}




void process( char * s ) {

  while ( *s ) {
    *s = (*s - 'a' + 13) % 26 + 'a';
    s++;
  }
}
