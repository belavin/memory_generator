

#ifndef ABOUTWINDOW_H_
#define ABOUTWINDOW_H_

#include <qwidget.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qstring.h>
#include <qstringlist.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <QDebug>
#include <QLineEdit>
#include <QString>
#include <QFormLayout>

class AboutWindow: public QWidget {
public:
	AboutWindow(QWidget *parent);
	virtual ~AboutWindow();

	QHBoxLayout *hbox1;
	QVBoxLayout *vbox1;
	QLabel *Au1 ;
	QLabel *Au2;
	QLabel *Au3;
	QLabel *Au4;
	QLabel *Au5;
	QGridLayout *gridLayout;

};

#endif /* ABOUTWINDOW_H_ */
