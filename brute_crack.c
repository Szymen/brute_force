#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isFinish(char *str){
    return '\0'== str[strspn(str, "z")];
}

void inc_str(char *str){
    int index, carry;
    for(index = strlen(str)-1;index>=0;--index){
        if(str[index] == 'z'){
            carry = 1;
            str[index] = 'a';
        } else {
            carry = 0;
            str[index] += 1;
        }
        if(carry == 0)break;
    }
}



int main(int argc, char* argv[]){

    char *pass;
    char *prog;
    char *run_command;
    int res; 
    int pass_len;
    res = 10;
    pass_len = 0;
    run_command = malloc(sizeof(char) * 1024);
    pass = malloc(sizeof(char) * 1024);
    prog = malloc(sizeof(char) * 1024);

    if(argc == 1){
        printf("Error: File to be cracked not given!\n");
        return 0;
    }

    if(argv[1][0] !='.' || argv[1][0] != '/'){ /* assume it`s in the same folder */
        strcpy(prog, "./");
        strcat(prog, argv[1]);
        strcat(prog, " ");

    }else{
        strcpy(prog, argv[1]);
        strcat(prog, " ");}



    do{
        pass_len++;
       	printf("Testing %d-letter long passwords\n",pass_len);
	pass = (char*)malloc(sizeof(char)*(pass_len+1));
        memset(pass, 'a', pass_len);	/* sets to "aa..aaa"  */
        pass[pass_len]='\0';

        while(1){
            run_command[0] = '\0'; /* clears command */
            strcpy(run_command, prog); /* sets prog to crack at start  */
            strcat(run_command, pass); /* appends pass to be checked */
            /* printf("Tried pass: %s\n",pass); */ 
            res = system(run_command);  /* tries to run */
            if(res == 0){
                break;  /* means prog cracked */
            }
            if(isFinish(pass)){ /* checks if there are something more in password sphere */
                break;}
            inc_str(pass); /* otherwise gets next password to check */
        }
    }while(res != 0);

    printf("Password cracked \"%s\"\n",pass);


    return 0;
}
