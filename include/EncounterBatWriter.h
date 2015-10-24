
#ifndef ENCOUNTERBATWRITER_H_
#define ENCOUNTERBATWRITER_H_

#include "AbstractBatWriter.h"
#include "MemgenConfigStorage.h"


class EncounterBatWriter: public AbstractBatWriter {
public:
	EncounterBatWriter(MemgenConfigStorage* mcs);
	EncounterBatWriter(MemgenConfigStorage* mcs, QString encounter_arguments);
	~EncounterBatWriter();
	void createConfig();
	void createConfig(QString encounter_arguments);
private:
	QVector <QString> cad_config_string;

};

#endif /* ENCOUNTERBATWRITER_H_ */
