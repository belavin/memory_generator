

#include "RcBatWriter.h"
#include <QFile>
#include <QDebug>

RcBatWriter::RcBatWriter(MemgenConfigStorage* mcs) {
	QString tmp = (QString)"rc_config";
	this->cad_config_string = mcs->ReturnConfigByKey(tmp);
    createConfig();

}

RcBatWriter::RcBatWriter(MemgenConfigStorage* mcs, QString arguments) {
	QString tmp = (QString)"rc_config";
	this->cad_config_string = mcs->ReturnConfigByKey(tmp);
    createConfig(arguments);

}



RcBatWriter::~RcBatWriter() {
	this->cad_config_string.clear();
}



void RcBatWriter::createConfig(){
	    QFile file("rc.bat");
	    file.open(QIODevice::WriteOnly);

	    file.write("#!/bin/tcsh\n");
	    file.write("av_sanro\n");
	    for (int i = 0; i < this->cad_config_string.size(); ++i) {
	    //		this->NumCellInRowBox->addItems((QStringList) test.at(i));
	    	file.write(this->cad_config_string[i].toUtf8());
	    	if (i == 0){
	    	file.write(" ");
	    	}
	    	}
	    file.write("\n");
	    file.write("rc -64\n");
	    file.close();

};

void RcBatWriter::createConfig(QString rc_arguments){

	    QFile file("rc.bat");
	    file.open(QIODevice::WriteOnly);

	    file.write("#!/bin/tcsh\n");
	    file.write("av_sanro\n");
	    for (int i = 0; i < this->cad_config_string.size(); ++i) {
	    	file.write(this->cad_config_string[i].toUtf8()+" "); // For multi-argument source
	    	if (i == 0){
	    	file.write(" ");
	    	}
	    	}
	    file.write("\n");
	    file.write("rc -64 ");
	    file.write(rc_arguments.toUtf8());
	    file.write("\n");
	    file.close();

};
