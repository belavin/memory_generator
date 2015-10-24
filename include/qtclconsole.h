

#ifndef QTCLCONSOLE_H
#define QTCLCONSOLE_H

#include <tcl.h>

#include "qconsole.h"
#include "qmutex.h"
#include "MemgenConfigStorage.h"

/**An emulated singleton class console for Tcl within a Qt application (based on the QConsole class)
 *@author Houssem BDIOUI
 */

class QtclConsole : public QConsole
{


		friend int ConsoleOutput(ClientData, CONST char * buf,
														 int toWrite, int *errorCode);
		friend int ConsoleError(ClientData, CONST char * buf,
														int toWrite, int *errorCode);
public:
		//destructor
		~QtclConsole();
		//callback method that implements the history command
		int showHistory( ClientData client_data, Tcl_Interp* interp, int argc, const char *argv[]);
		//callback method that implements the set_prompt command
		int setPrompt( ClientData client_data, Tcl_Interp* interp, int argc, const char *argv[]);
		//callback method that calls the saveScript() method
		int saveScript( ClientData client_data, Tcl_Interp* interp, int argc, const char *argv[]);
		int loadScript( ClientData client_data, Tcl_Interp* interp, int argc, const char *argv[]);
		//get the QtclConsole instance
		static QtclConsole *getInstance(QWidget *parent = NULL, const QString &welcomeText = "");
        int run_nc(ClientData client_data, Tcl_Interp* interp, int argc, const char *argv[]);
        int run_rc(ClientData client_data, Tcl_Interp* interp, int argc, const char *argv[]);
        int run_edi(ClientData client_data, Tcl_Interp* interp, int argc, const char *argv[]);
        int check_log(ClientData client_data, Tcl_Interp* interp, int argc, const char *argv[]);

        QString interpretCommand(const QString &command, int *res);
        Tcl_Interp *interp;
private:
		//Tcl interpreter

		//The instance
		static QtclConsole *theInstance;
		QMutex mutex;

private:
		//Return false if the tcl command is incomplete (e.g. unmatched braces)
		bool isCommandComplete(const QString &command);
		//private constructor
		QtclConsole(QWidget *parent = NULL, const QString &welcomeText = "");
		//execute a validated command

		//give suggestions to autocomplete a command
		QStringList suggestCommand(const QString &cmd, QString& prefix);
};

#endif
