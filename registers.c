#include "registers.h"

static clock_t cInstant;

static FILE *file;

void writeRegisters() {
    char *reg;
    cInstant = clock();
    
    setenv("LOG_FILENAME", "registers.txt",0);
    reg = getenv("LOG_FILENAME");

    if((file = fopen(reg, "a")) == NULL){
        perror("Could not open the set file\n");
        exit(1);
    }
}

void structRegisterBegin(struct Register *registo){
    registo->instant = ((double) (clock() - cInstant)) / (CLOCKS_PER_SEC/1000.0);
    registo->pid = getpid();
}   

void writeCreateEvent(int argc, char *argv[]){

    struct Register registo;

    structRegisterBegin(&registo);

    char *info = malloc(sizeof(char)*256);

    for (int i = 0; i <= argc; i++) {
       strcat(info, argv[i]);
       strcat(info, " ");
    }
    strcat(info, argv[argc-1]); // Because there's no need for a space after the last argument

    fprintf(file, "%f - %ld - CREATE - %s\n", registo.instant, (long) registo.pid, info);

}

void writeExitEvent(int exitStatus){

    struct Register registo;

    structRegisterBegin(&registo);

    fprintf(file, "%f - %ld - EXIT - %d\n", registo.instant, (long) registo.pid, exitStatus);
    
}

void writeRecvSignalEvent(int signal){

    struct Register registo;

    structRegisterBegin(&registo);

    fprintf(file, "%f - %ld - RECV_SIGNAL - %d\n", registo.instant, (long) registo.pid, signal);
    
}

void writeSendSignalEvent(pid_t pid, int signal){

    struct Register registo;

    structRegisterBegin(&registo);

    fprintf(file, "%f - %ld - SEND_SIGNAL - signal: %d , pid: %ld\n", registo.instant, (long) registo.pid, signal, (long) pid);
    
}

void writeRecvPipeEvent(char *receivedMessage){

    struct Register registo;

    structRegisterBegin(&registo);

    fprintf(file, "%f - %ld - RECV_PIPE - %s\n", registo.instant, (long) registo.pid, receivedMessage);
    
}

void writeSendPipeEvent(char *sentMessage){

    struct Register registo;

    structRegisterBegin(&registo);

    fprintf(file, "%f - %ld - SEND_PIPE - %s\n", registo.instant, (long) registo.pid, sentMessage);
    
}

void writeEntryEvent(){

    struct Register registo;

    structRegisterBegin(&registo);

    fprintf(file, "%f - %ld - SEND_PIPE - \n", registo.instant, (long) registo.pid); // Aqui not sure como
    
}