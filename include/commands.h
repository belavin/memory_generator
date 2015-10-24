

#ifndef COMMANDS_H
#define COMMANDS_H

#include <tcl.h>

//Global callback function that implements the msgbox command
int CallQMessageBox( ClientData client_data, Tcl_Interp* interp, int argc, char *argv[]);

#endif
