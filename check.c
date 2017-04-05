#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){

    char* password = "haslo";
    if(argc == 1){
       /* printf("Password needed!\n");*/
        return 2;
    }
    if(strcmp(argv[1], password) == 0){
       /*printf("Acces granted!\n");*/
        return 0;
    }
      /*printf("Acces denied!\n");*/
        return 1;
}
