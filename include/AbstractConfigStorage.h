

#ifndef ABSTRACTCONFIGSTORAGE_H_
#define ABSTRACTCONFIGSTORAGE_H_

#include <qobject.h>
#include <QVector>
#include <QMap>
#include <QString>

class AbstractConfigStorage: public QObject {
//	Q_OBJECT;
public:
	AbstractConfigStorage();
//static const QObject& CreateConfigSingleton();
	virtual ~AbstractConfigStorage();
	void virtual AddConfigInStorage();
	void virtual DeleteConfigFromStorage();
	void virtual CleanConfig();
	virtual QVector<QString> ReturnConfigByKey(QString key);
protected:

private:

	QMap<QString, QVector<QString> > map;
//AbstractConfigStorage& operator=(const AbstractConfigStorage&){};

};

#endif /* ABSTRACTCONFIGSTORAGE_H_ */
