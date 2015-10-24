

#include "EncounterBatWriter.h"
#include <QFile>
#include <QDebug>

EncounterBatWriter::EncounterBatWriter(MemgenConfigStorage* mcs) {
	QString tmp = (QString)"encounter_config";
	this->cad_config_string = mcs->ReturnConfigByKey(tmp);
    createConfig();

}

EncounterBatWriter::EncounterBatWriter(MemgenConfigStorage* mcs, QString arguments) {
	QString tmp = (QString)"encounter_config";
	this->cad_config_string = mcs->ReturnConfigByKey(tmp);
    createConfig(arguments);

}



EncounterBatWriter::~EncounterBatWriter() {
	this->cad_config_string.clear();
}



void EncounterBatWriter::createConfig(){
	    QFile file("encounter.bat");
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
	    file.write("encounter -64\n");
	    file.close();

};

void EncounterBatWriter::createConfig(QString encounter_arguments){

	    QFile file("encounter.bat");
	    file.open(QIODevice::WriteOnly);

	    file.write("#!/bin/tcsh\n");
	    file.write("av_sanro\n");
	    for (int i = 0; i < this->cad_config_string.size(); ++i) {
	    //		this->NumCellInRowBox->addItems((QStringList) test.at(i));
	    	file.write(this->cad_config_string[i].toUtf8()+" "); // For multi-argument source
	    	if (i == 0){
	    	file.write(" ");
	    	}
	    	}
	    file.write("\n");
	    file.write("encounter -64 ");
	    file.write(encounter_arguments.toUtf8());
	    file.write("\n");
	    file.close();

};
