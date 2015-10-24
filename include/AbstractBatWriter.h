

#ifndef ABSTRACTBATWRITER_H_
#define ABSTRACTBATWRITER_H_

#include <qobject.h>

class AbstractBatWriter : public QObject {
public:
	AbstractBatWriter();
	virtual ~AbstractBatWriter();
	virtual const void getCadConfig(){};
	virtual const void getLicenseConfig(){};
	virtual void createConfig(){};

};

#endif /* ABSTRACTBATWRITER_H_ */
