
#ifndef PROPERTYWINDOW_H_
#define PROPERTYWINDOW_H_

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
#include "MemgenConfigStorage.h"





//// !!!!!!!!!!!1class PropertyWindow : public QWidget

class PropertyWindow : public QWidget

{
	Q_OBJECT

public:

	PropertyWindow(QWidget *parent,MemgenConfigStorage* mcs);
	~PropertyWindow();
	friend class CalculationInProperty;
private:
	 void  CreateLayout();
	 QHBoxLayout *hbox1;
	 QVBoxLayout *vbox1;
	 QVBoxLayout *vbox2;
	 QPushButton *saveButton;

	 QString flow;

	 // SOI018_ROM flow

	 QLabel *NumCellInRowLabel ;
	 QLabel *DataBitLabel;
	 QLabel *RowNumberLabel;
	 QLabel *InputfilesLabel;
	 QLabel *CompilerFolderLabel;
	 QLabel *WorkFolderLabel;


	 QComboBox *NumCellInRowBox;
	 QComboBox *DataBitBox;
	 QComboBox *RowNumberBox;
	 QLineEdit *InputfilesBox;
	 QLineEdit *CompilerFolderBox;
	 QLineEdit *WorkFolderBox;


	 QGridLayout *gridLayout;



	 QPushButton *SaveData;

	 MemgenConfigStorage* mcs;

private slots:
	void  calculateRowNumber();
	void  saveSettings();





};


class CalculationInProperty : public QObject {
	Q_OBJECT
public:
	CalculationInProperty(PropertyWindow* pw, QString flow);
	~CalculationInProperty();
	void CalculatePropertyInPropertyWindow(PropertyWindow* property,const QString flow);

private:
   QString flow;
   PropertyWindow* pw;

};


#endif /* PROPERTYWINDOW_H_ */
