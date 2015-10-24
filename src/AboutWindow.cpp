
#include "AboutWindow.h"

AboutWindow::AboutWindow(QWidget *parent) {


	QHBoxLayout *hbox1;
		QVBoxLayout *vbox1;
		this->Au1 = new QLabel("Authors") ;
		this->Au3 = new QLabel("Titov A.I.");
		this->Au2 = new QLabel("Zababurin A.Y.");
		this->Au4 = new QLabel("Aleksandrova M.A.");
		this->Au5 = new QLabel("Zdanov A.A.");
		this->gridLayout = new QGridLayout(this);
		gridLayout->addWidget(Au1, 0, 0);
		gridLayout->addWidget(Au2, 1, 0);
		gridLayout->addWidget(Au3, 2, 0);
		gridLayout->addWidget(Au4, 3, 0);
		gridLayout->addWidget(Au5, 4, 0);


	//	gridLayout->addWidget(NumCellInRowLabel, 0, 0);
}

AboutWindow::~AboutWindow() {
	// TODO Auto-generated destructor stub
}

