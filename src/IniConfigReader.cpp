

#include "IniConfigReader.h"

IniConfigReader::IniConfigReader() {
	// TODO Auto-generated constructor stub

}

IniConfigReader::IniConfigReader(QString path_to_file,MemgenConfigStorage* storage) {
	this->path = path_to_file;
	ReadConfigFromFile(this->path,storage);
}
IniConfigReader::~IniConfigReader() {
	// TODO Auto-generated destructor stub
}

int IniConfigReader::ReadConfigFromFile(const QString path,MemgenConfigStorage* storage) {
    QFile file(path); // создаем объект класса QFile
    QByteArray data; // Создаем объект класса QByteArray, куда мы будем считывать данные
    if (file.open(QIODevice::ReadOnly))
        {
           QTextStream in(&file);
           while ( !in.atEnd() )
           {
              QString line = in.readLine();
              QString first_word = line.section(" ", 0, 0, QString::SectionSkipEmpty);
              QString f = first_word;
           QString all_other_words = line.replace(f.append(" ") , (QString)"" ,Qt::CaseSensitive);
// TODO Add many  catches in this section
 //             qDebug() << all_other_words;
              QStringList option_list = all_other_words.split(" ");
              QVector<QString> v;
              for(int i=0;i<option_list.size();i++)
              {
            	 const QString q = option_list[i];
                 v.push_back( q );
              }

              this->temp_map.insert(first_word,v);
           }

           file.close();

        }
    IniConfigReader::SendConfigToStorage(storage, (const QMap<QString, QVector<QString> >)temp_map);
	return 0;
}

void IniConfigReader::SendConfigToStorage(MemgenConfigStorage *to, const QMap<QString, QVector<QString> >  map){
	to->AddConfigInStorage(map);

}
