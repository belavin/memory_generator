
#include "AboutWindow.h"

AboutWindow::AboutWindow(QWidget *parent) {


	QHBoxLayout *hbox1;
		QVBoxLayout *vbox1;
		this->Au1 = new QLabel("Authors") ;
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

