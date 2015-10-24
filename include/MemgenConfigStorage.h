
#ifndef MEMGENCONFIGSTORAGE_H_
#define MEMGENCONFIGSTORAGE_H_

#include "AbstractConfigStorage.h"


class MemgenConfigStorage: public AbstractConfigStorage {
	Q_OBJECT
public:
	static const MemgenConfigStorage& CreateConfigSingleton();
	~MemgenConfigStorage();
	void	AddConfigInStorage(const QMap<QString,QVector<QString> >  map);
	QVector<QString>	 ReturnConfigByKey(const QString key);
//	void	DeleteConfigFromStorage();
//	void	CleanConfig();
	MemgenConfigStorage()  ;
protected:

private:

	QMap<QString, QVector<QString> > map;


//	QMap<QString, template<> QVector<QString> >& QMap< QString, template<> QVector<QString>  >::operator=(const QMap< QString, template<> QVector<QString> >&);
};

#endif /* MEMGENCONFIGSTORAGE_H_ */
