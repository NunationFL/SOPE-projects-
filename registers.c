#include "registers.h"

void op_reg_message(int i, pid_t pid, pid_t tid, int dur, int pl, char *oper) {
    char* message;
    message = (char*) malloc (128 * sizeof(char));
    time_t t = time(NULL);

    sprintf(message, "%ld ; %d ; %d ; %d ; %d ; %d ; %s\n", t, i, pid, tid, dur, pl, oper);
    write(STDOUT_FILENO, message, strlen(message));
}