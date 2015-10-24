

#include "NcBatWriter.h"

#include <QFile>
#include <QDebug>
#include <QRegExp>

NcBatWriter::NcBatWriter(MemgenConfigStorage* mcs) {
	QString tmp = (QString)"nc_config";
	this->cad_config_string = mcs->ReturnConfigByKey(tmp);
    createConfig();

}

NcBatWriter::NcBatWriter(MemgenConfigStorage* mcs, QString arguments) {
	QString tmp = (QString)"nc_config";
	this->cad_config_string = mcs->ReturnConfigByKey(tmp);
    createConfig(arguments);

}



NcBatWriter::~NcBatWriter() {
	this->cad_config_string.clear();
}



void NcBatWriter::createConfig(){
	    QFile file("nc.bat");
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
	    file.write("ncverilog -64\n");
	    file.close();

};

void NcBatWriter::createConfig(QString nc_arguments){

	    QFile file("nc.bat");
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
	    file.write("ncverilog -64 ");
	    file.write(nc_arguments.toUtf8());
	    file.write("\n");
	    file.close();

};
