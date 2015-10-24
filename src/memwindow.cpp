#include <QtGui>

#include "memwindow.h"
#include "propertywindow.h"
#include "AboutWindow.h"

  const QString p = "memgen.ini";
  MemgenConfigStorage* mcs = new MemgenConfigStorage::MemgenConfigStorage();
  IniConfigReader* nw = new IniConfigReader(p, mcs);




memwindow::memwindow(QWidget *parent) :
		QWidget(parent) {
	this->vbox = new QVBoxLayout(this);
	this->option_line = new QHBoxLayout(this);
	this->console_line = new QHBoxLayout(this);

	QtclConsole *console =
			QtclConsole::getInstance(parent,
					"Welcome to <b>Qt / Memory Compiler SOI018</b> !<br>"
							"For any remarks, please mail me at: <font color=blue>atitov@mikron.ru</font><br><br>");

    this->mcs = ::mcs;
	CreateLayout(console);

}

memwindow::~memwindow() {

}

void memwindow::CreateLayout(QtclConsole* qconsole) {

	this->parameters = new QPushButton("Parameters", this);
	this->status = new QPushButton("Status", this);
	this->help = new QPushButton("Help", this);
	this->about = new QPushButton("About", this);

	option_line->addWidget(parameters);
	option_line->addWidget(status);
	option_line->addWidget(help);
	option_line->addWidget(about);

	connect(this->parameters, SIGNAL( clicked() ), this,
			SLOT( slotShowParameters() ));

	connect(this->about, SIGNAL( clicked() ), this,
				SLOT( slotShowAbout() ));

	console_line->addWidget((QWidget*) qconsole);

	//      vbox->addWidget((QWidget*)option_line);
	//      vbox->addWidget((QWidget*)console_line);

	vbox->addLayout(option_line);
	vbox->addLayout(console_line);
	this->setLayout(vbox);
	//    settings->setSizePolicy(QSizePolicy::Expanding,
	//        QSizePolicy::Expanding);

}

void memwindow::slotShowParameters() {
	QMainWindow* pwWindow = new QMainWindow();
	PropertyWindow* pw = new PropertyWindow((QWidget*) pwWindow, this->mcs);

	pwWindow->setWindowTitle("Parameters");
	pwWindow->setCentralWidget(pw);

	pwWindow->show();

}


void memwindow::slotShowAbout() {
	QMainWindow* pwWindow = new QMainWindow();
	AboutWindow* pw = new AboutWindow((QWidget*) pwWindow);

	pwWindow->setWindowTitle("About");
	pwWindow->setCentralWidget(pw);

	pwWindow->show();

}
