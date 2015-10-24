

#ifndef MEMWINDOW_H_
#define MEMWINDOW_H_


#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qstring.h>
#include <qstringlist.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include "MemgenConfigStorage.h"
#include "IniConfigReader.h"
#include "qtclconsole.h"
#include "tclnotify.h"

#include <QObject>

/*class QCheckBox;
class QPushButton;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;
class QStackedLayout; */




class memwindow : public QWidget
{
    Q_OBJECT

public:
  memwindow(QWidget *parent);
  ~memwindow();

private:
   void CreateLayout(QtclConsole* qconsole);
   QPushButton *parameters;
   QPushButton *status;
   QPushButton *help;
   QPushButton *about;
   QVBoxLayout *vbox;
   QHBoxLayout *option_line;
   QHBoxLayout *console_line;
   MemgenConfigStorage* mcs;


private slots:
    void slotShowParameters();
    void slotShowAbout();
};


#endif /* MEMWINDOW_H_ */
