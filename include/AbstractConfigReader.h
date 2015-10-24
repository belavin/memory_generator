

#ifndef ABSTRACTCONFIGREADER_H_
#define ABSTRACTCONFIGREADER_H_

#include <qobject.h>

class AbstractConfigReader: public QObject {
public:
	AbstractConfigReader();
	virtual ~AbstractConfigReader();
	virtual void ReadConfigFromFile();
};

#endif /* ABSTRACTCONFIGREADER_H_ */
