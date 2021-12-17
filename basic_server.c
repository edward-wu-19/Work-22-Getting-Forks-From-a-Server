#include "pipe_networking.h"

int main() {

    int to_client;
    int from_client;
    
    char line[LEN];
    int i, f;

    while (1){
    //   from_client = server_handshake( &to_client );;
        from_client = server_setup();

        f = fork();
        if (f){
            //parent or server
        }
        else{
            // child or subserver
            int to_client = server_connect(from_client);

            char* tmp = line;
            i = 0;

            // printf("A\n");

            while (1){
                read(from_client, line, LEN);

                // char* tmp = line;
                // int i = 0;
                while (i < LEN){
                    *tmp = toupper(*tmp);
                    tmp++;
                    i++;
                }

                write(to_client, line, LEN);
            }
        }

    }

    return 0;
}