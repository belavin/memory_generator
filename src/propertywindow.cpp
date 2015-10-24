

#include "propertywindow.h"
#include "qtclconsole.h"

#include <QDebug>

PropertyWindow::PropertyWindow(QWidget *parent, MemgenConfigStorage* mcs) :
		QWidget(parent) {
	QString g = "flow";
	QVector<QString> test = mcs->ReturnConfigByKey(g);
	this->mcs = mcs;
	test = mcs->ReturnConfigByKey(g);
	this->flow = (QString) test.at(0);
//	qDebug() << this->flow;
	test.clear();
	this->saveButton = new QPushButton("Save");
	this->NumCellInRowLabel = new QLabel(tr("Количество ячеек в столбце"));
	this->DataBitLabel = new QLabel("Разрядность данных");
	this->RowNumberLabel = new QLabel("Количество столбцов");
	this->InputfilesLabel = new QLabel("Исходные файлы(lef,lib,gds,verilog)");
	this->CompilerFolderLabel = new QLabel("Путь к компилятору");
	this->WorkFolderLabel = new QLabel("Рабочая папка");

	this->NumCellInRowBox = new QComboBox;
	this->InputfilesBox = new QLineEdit;
	this->CompilerFolderBox = new QLineEdit;
	this->WorkFolderBox = new QLineEdit;

	g = "NumCellInRow";
	this->NumCellInRowBox->addItems((QStringList) "---");
	test = mcs->ReturnConfigByKey(g);
	for (int i = 0; i < test.size(); ++i) {
		this->NumCellInRowBox->addItems((QStringList) test.at(i));
	}

	test.clear();
	g.clear();
	this->DataBitBox = new QComboBox;
	g = "DataBit";
	this->DataBitBox->addItems((QStringList) "---");
	test = mcs->ReturnConfigByKey(g);
	for (int i = 0; i < test.size(); ++i) {
		this->DataBitBox->addItems((QStringList) test.at(i));
	}

	this->RowNumberBox = new QComboBox;
	this->RowNumberBox->addItems((QStringList) "---");
	this->SaveData = new QPushButton("Сохранить и запустить компиляцию");
	connect(this->NumCellInRowBox, SIGNAL( currentIndexChanged(int) ), this,
			SLOT( calculateRowNumber()));

	connect(this->SaveData, SIGNAL( clicked() ), this, SLOT( saveSettings() ));

	this->InputfilesBox->setText(mcs->ReturnConfigByKey("Inputfiles")[0]);
	this->CompilerFolderBox->setText(
			mcs->ReturnConfigByKey("CompilerFolder")[0]);
	this->CompilerFolderBox->setEnabled(0);
	this->WorkFolderBox->setText(mcs->ReturnConfigByKey("WorkFolder")[0]);

	/*



	 CreateLayout();


	 }


	 void PropertyWindow::CreateLayout(){



	 //   QVector <QString>  test =  ::mcs->ReturnConfigByKey(g);

	 /*vbox1->addWidget(numCellInRowLabel);
	 vbox1->addWidget(DataBitLabel);
	 vbox1->addWidget(RowNumberLabel);

	 vbox2->addWidget(numCellInRowBox);
	 vbox2->addWidget(DataBitBox);
	 vbox2->addWidget(RowNumberBox);*/

	QGridLayout *gridLayout = new QGridLayout(this);
	gridLayout->addWidget(NumCellInRowLabel, 0, 0);
	gridLayout->addWidget(DataBitLabel, 1, 0);
	gridLayout->addWidget(RowNumberLabel, 2, 0);
	gridLayout->addWidget(InputfilesLabel, 3, 0);
	gridLayout->addWidget(CompilerFolderLabel, 4, 0);
	gridLayout->addWidget(WorkFolderLabel, 5, 0);

	gridLayout->addWidget(SaveData, 6, 0);

	gridLayout->addWidget(NumCellInRowBox, 0, 1);
	gridLayout->addWidget(DataBitBox, 1, 1);
	gridLayout->addWidget(RowNumberBox, 2, 1);
	gridLayout->addWidget(InputfilesBox, 3, 1);
	gridLayout->addWidget(CompilerFolderBox, 4, 1);
	gridLayout->addWidget(WorkFolderBox, 5, 1);

	this->setLayout(gridLayout);

}

PropertyWindow::~PropertyWindow() {

}

void PropertyWindow::calculateRowNumber() {
	CalculationInProperty* cip = new CalculationInProperty(this, this->flow);
	cip->CalculatePropertyInPropertyWindow(this, this->flow);

}

void PropertyWindow::saveSettings() {
//EncounterBatWriter* encbat = new EncounterBatWriter( this->mcs );
	QtclConsole *ConsoleInstance = QtclConsole::getInstance();
//	QString p =  "source ./scripts/PrepareCompiler.tcl ; srcfile ./scripts/CompileROM.tcl <compiler_folder> <data_folder>  <work_folder> 256 256 8 ";
	QMap<QString, QVector<QString> > tmpMap;
	QVector<QString> tmpVector;
	tmpVector.append((QString) this->InputfilesBox->text());
	tmpMap.insert((QString) "Inputfiles", tmpVector);
	tmpMap.clear();
	tmpVector.clear();

	tmpVector.append((QString) this->WorkFolderBox->text());
	tmpMap.insert((QString) "WorkFolder", tmpVector);
	tmpMap.clear();
	tmpVector.clear();


//	 mcs->AddConfigInStorage( (QMap) "Inputfiles" this->InputfilesBox->getText() );
		QString
	run_command = "source " + mcs->ReturnConfigByKey("CompilerFolder")[0]
			+"/exe/scripts/PrepareCompiler.tcl; srcfile "
			+mcs->ReturnConfigByKey("CompilerFolder")[0]
			+"/exe/scripts/CompileROM.tcl "
			+mcs->ReturnConfigByKey("CompilerFolder")[0]
			+" "+ mcs->ReturnConfigByKey("Inputfiles")[0]
			+" "+ mcs->ReturnConfigByKey("WorkFolder")[0]
	+" "+ this->NumCellInRowBox->itemData(this->NumCellInRowBox->currentIndex(), 0).toString()
	+" "+ this->RowNumberBox->itemData(this->RowNumberBox->currentIndex(), 0).toString()
	+" "+ this->DataBitBox->itemData(this->DataBitBox->currentIndex(), 0).toString()
	+" ;history";


/*	QString run_command = "source " + mcs->ReturnConfigByKey("CompilerFolder")[0]
	                                                                           + "/scripts/PrepareCompiler.tcl; srcfile"
	                                                                           +mcs->ReturnConfigByKey("CompilerFolder")[0]
	+"/scripts/CompileROM.tcl "
	+" ; history";*/

//	qDebug() << run_command;

	QString* test;
	int res = Tcl_Eval(ConsoleInstance->interp , qPrintable(run_command) );

//	QConsole* p =  QConsole::returncurrentObject();


//	QConsole::execCommand((QString)"test",TRUE,TRUE,test);

//	ConsoleInstance->interpretCommand(run_command, &res);

}

CalculationInProperty::CalculationInProperty(PropertyWindow* property,
		const QString flow) {
	this->pw = property;

}

CalculationInProperty::~CalculationInProperty() {

}

void CalculationInProperty::CalculatePropertyInPropertyWindow(
		PropertyWindow* property, const QString flow) {
	int a = property->NumCellInRowBox->itemData(
			property->NumCellInRowBox->currentIndex(), 0).toInt();
//qDebug() << a.toUInt() ;
	switch (a) {
	case 16:
		property->RowNumberBox->clear();
		property->RowNumberBox->addItems((QStringList) "---");
		property->RowNumberBox->addItems((QStringList) "4");
		property->RowNumberBox->addItems((QStringList) "8");
		property->RowNumberBox->addItems((QStringList) "16");
		property->RowNumberBox->addItems((QStringList) "32");
		break;
	case 32:
		property->RowNumberBox->clear();
		property->RowNumberBox->addItems((QStringList) "---");
		property->RowNumberBox->addItems((QStringList) "32");
		property->RowNumberBox->addItems((QStringList) "64");
		break;
	case 64:
		property->RowNumberBox->clear();
		property->RowNumberBox->addItems((QStringList) "---");
		property->RowNumberBox->addItems((QStringList) "64");
		property->RowNumberBox->addItems((QStringList) "128");
		break;

	case 128:
		property->RowNumberBox->clear();
		property->RowNumberBox->addItems((QStringList) "---");
		property->RowNumberBox->addItems((QStringList) "128");
		property->RowNumberBox->addItems((QStringList) "256");
		break;
	case 256:
		property->RowNumberBox->clear();
		property->RowNumberBox->addItems((QStringList) "---");
		property->RowNumberBox->addItems((QStringList) "256");
		property->RowNumberBox->addItems((QStringList) "512");
		break;
	case 512:
		property->RowNumberBox->clear();
		property->RowNumberBox->addItems((QStringList) "---");
		property->RowNumberBox->addItems((QStringList) "512");
		break;
	default:
		break;
	}

}

