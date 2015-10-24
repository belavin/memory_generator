
#include "LogChecker.h"
#include <QTextStream>
#include <QDebug>

	LogChecker::LogChecker(QString log,QRegExp regexp){


this->status = 2;
QVector <QString>* error_line_vector= new QVector <QString>;
this->ParseLogFile(log,regexp);


	}

	int LogChecker::ParseLogFile(QString logfile, QRegExp regexp){
		QFile inputFile(logfile);
			if (inputFile.open(QIODevice::ReadOnly))
		    {
		       QTextStream log(&inputFile);
		       while ( !inputFile.atEnd() )
		       {
		          QString line = inputFile.readLine();

		          if (regexp.exactMatch(line) ){
		        	     	this->status = 1;
		        	     	qDebug() << "Found error in file " << logfile.toUtf8();
		          }
		       }
		       inputFile.close();
		       if (this->status == 2){
		    	   this->status = 0;
		    	   qDebug() << "File " << logfile.toUtf8() << "is OK!";
		       }
		       return 0;
		    }
		else {qDebug() << "Cannot open file .log";  return 1;}

	}


int	LogChecker::ParseLogFile(QString log,QRegExp regexp,QString tool){
		return 1;
	}


	LogChecker::~LogChecker(){};
