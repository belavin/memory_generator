

#ifndef RCBATWRITER_H_
#define RCBATWRITER_H_

#include "AbstractBatWriter.h"

#include "MemgenConfigStorage.h"


class RcBatWriter: public AbstractBatWriter {
public:
	RcBatWriter(MemgenConfigStorage* mcs);
	RcBatWriter(MemgenConfigStorage* mcs, QString rc_arguments);
	~RcBatWriter();
	void createConfig();
	void createConfig(QString rc_arguments);
private:
	QVector <QString> cad_config_string;

};

#endif /* RCBATWRITER_H_ */
