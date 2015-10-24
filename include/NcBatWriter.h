

#ifndef NCBATWRITER_H_
#define NCBATWRITER_H_

#include "AbstractBatWriter.h"

#include "MemgenConfigStorage.h"
#include "LogChecker.h"

class NcBatWriter: public AbstractBatWriter {
public:
	NcBatWriter(MemgenConfigStorage* mcs);
	NcBatWriter(MemgenConfigStorage* mcs, QString nc_arguments);
	~NcBatWriter();
	void createConfig();
	void createConfig(QString nc_arguments);
private:
	QVector <QString> cad_config_string;

};
#endif /* NCBATWRITER_H_ */
