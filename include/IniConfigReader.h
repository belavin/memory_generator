

#ifndef INICONFIGREADER_H_
#define INICONFIGREADER_H_

#include "AbstractConfigReader.h"
#include "MemgenConfigStorage.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QStringList>

class IniConfigReader: public AbstractConfigReader {
	Q_OBJECT
public:
	IniConfigReader();
	IniConfigReader(QString path,MemgenConfigStorage* storage);
	virtual ~IniConfigReader();
private:
	int  ReadConfigFromFile(const QString path,MemgenConfigStorage* storage);
	QStringList option_list;
    QString path;
    QMap<QString, QVector<QString> > temp_map;
    void SendConfigToStorage(MemgenConfigStorage *to, const QMap<QString, QVector<QString> >  map);
private slots:
//void SendConfigToStorage();
};

#endif /* INICONFIGREADER_H_ */
