
#include "AbstractConfigStorage.h"

AbstractConfigStorage::AbstractConfigStorage() {

}

AbstractConfigStorage::~AbstractConfigStorage() {

}

//const QObject& AbstractConfigStorage::CreateConfigSingleton(){
//	 static AbstractConfigStorage theSingleInstance;
//	 return theSingleInstance;
//}

void AbstractConfigStorage::AddConfigInStorage() {
}
void AbstractConfigStorage::DeleteConfigFromStorage() {
}
void AbstractConfigStorage::CleanConfig() {
}
QVector<QString> AbstractConfigStorage::ReturnConfigByKey(QString key) {
}
