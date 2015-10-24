

#ifndef tclnotify_h_
#define tclnotify_h_

// NOTE: This file is input to Qt's moc.

#include <tcl.h>
extern "C" int TclInExit(void);

#include <qobject.h>
class QSocketNotifier;

class TclTimeNotifier : public QObject
{
	Q_OBJECT
		public:
		TclTimeNotifier();
		~TclTimeNotifier();
	public slots:
		void gong();
};

class TclFileHandler : public QObject
{
	Q_OBJECT
		public:
		TclFileHandler( int f );
		~TclFileHandler();

		int fd;
		int mask;				 /* Mask of desired events: TCL_READABLE, etc. */
		int readyMask;
		/* Events that have been seen since the
		 * last time FileHandlerEventProc was called
		 * for this file. */
		QSocketNotifier *read;
		QSocketNotifier *write;
		QSocketNotifier *except;
		Tcl_FileProc *proc;
		/* Procedure to call, in the style of
		 * CreateFileHandler. */
		ClientData clientData;	 /* Argument to pass to proc. */
		TclFileHandler *nextPtr; /* Next in list of all files we care about. */
	public slots:
		void fileactive( int );

};
#endif
