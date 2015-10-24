

#include "MemgenConfigStorage.h"
#include <QDebug>

MemgenConfigStorage::MemgenConfigStorage() {


}

MemgenConfigStorage::~MemgenConfigStorage() {
	this->map.clear();
}

void MemgenConfigStorage::AddConfigInStorage(const QMap< QString, QVector<QString> >  map){
//	QMap<QString, QVector<QString> > t = this->map
//	 QMap<QString, QVector<QString> > * t =  & map;
	this->map =   map;
//	qDebug() << map;
}


/*const MemgenConfigStorage& MemgenConfigStorage::CreateConfigSingleton(){
	 static MemgenConfigStorage theSingleInstance;
	 return theSingleInstance;
}*/

QVector<QString>	 MemgenConfigStorage::ReturnConfigByKey(const QString key){
return	this->map.value(key);
}

