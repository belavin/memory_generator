

#ifndef LOGCHECKER_H_
#define LOGCHECKER_H_

#include <qobject.h>
#include <QFile>
#include <QVector>
#include <QRegExp>


class LogChecker: public QObject {
public:
	LogChecker(QString log, QRegExp regexp);
	virtual ~LogChecker();
	int ParseLogFile(QString log,QRegExp regexp);							// for regilar *error* in logfile
	int ParseLogFile(QString log,QRegExp regexp,QString tool);   // for future use for custom CAD log check




private:
	QFile* logfile;
	int status;
	QVector <QString> error_line_vector;

};

#endif /* LOGCHECKER_H_ */
