

#include <qapplication.h>
#include <qmainwindow.h>
#include <qstring.h>
#include "commands.h"
#include "commandsManager.h"
#include <QTextCodec>
#include <QtGui>
#include "memwindow.h"
#include "IniConfigReader.h"

extern void Qtk_InitNotifier( QApplication * );

/* Define the following to fix __ctype_* from GLIBC2.3 and upper
   if not compiled using the same GLIBC */
//#define FIX__CTYPE_

#ifdef FIX__CTYPE_
#include <ctype.h>
__const unsigned short int *__ctype_b;
__const __int32_t *__ctype_tolower;
__const __int32_t *__ctype_toupper;

void ctSetup()
{
  __ctype_b = *(__ctype_b_loc());
  __ctype_toupper = *(__ctype_toupper_loc());
  __ctype_tolower = *(__ctype_tolower_loc());
}
#endif



//The main entry
int main( int argc, char ** argv )
{
#ifdef FIX__CTYPE_
    ctSetup();
#endif


    //init tcl
    Tcl_FindExecutable(argv[0]);
    Tcl_Interp * interp = Tcl_CreateInterp();
    Tcl_Init( interp );

    QTextCodec* codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForLocale(codec);

    //Qt application
    QApplication a( argc, argv );
    Tcl_SetServiceMode (TCL_SERVICE_ALL);
    Qtk_InitNotifier( &a );
    //Register the msgbox command
    commandsManager::getInstance(interp)->registerFunction("msgbox" , (commandsManager::commandType) CallQMessageBox, "Shows the Qt message box");
    //Create and show the main window
    QMainWindow mw;
    const QString str = "hello";

    mw.setWindowTitle("Memory compiler SOI018");
    mw.setMinimumSize(640, 480);
    //Instantiate and set the focus to the QtclConsole
/*    QtclConsole *console = QtclConsole::getInstance(&mw,
   	                                                     "Welcome to <b>Qt / Tcl console</b> !<br>"
   	                                                     "For any remarks, please mail me at: <font color=blue>houssem.bdioui@gmail.com</font><br><br>");
*/


    // Run config reading




    memwindow window((QWidget*)&mw);
 //   window.show();
    //   mw.setFocusProxy((QWidget*)console);
  //  mw.setCentralWidget((QWidget*)console);
    mw.setCentralWidget(&window);
    mw.show();

    return a.exec();
}
