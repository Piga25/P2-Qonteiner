#include "xmlio.h"


using std::cerr;
using std::endl;
XmlIO::XmlIO(Container<Evento*>* pt) : vec(pt), path("../data/data.xml"), isDataSaved(true) {
    load();
}

void XmlIO::save() {

    QSaveFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::WriteOnly)) {
        throw wrong("Errore in scrittura");
    }

    QXmlStreamWriter writer(&file);

    writer.setAutoFormatting(true); // Per leggibilità del file XML
    writer.writeStartDocument();    // Scrive le intestazioni XML

    writer.writeStartElement("root"); // <root>

    auto it = vec->cbegin();
    while(it != vec->cend()) {
        const Evento* toSave = *it;
        const QString tipo = QString::fromStdString(toSave->getTipo());
        writer.writeEmptyElement(tipo);


        writer.writeAttribute("titolo", QString::fromStdString(toSave->get_titolo()));
        //writer.writeAttribute("path", toSave->getFoto());
        writer.writeAttribute("durata", QString::number(toSave->getDurata()));
        writer.writeAttribute("luogo", QString::fromStdString((toSave->getLuogo())));
        writer.writeAttribute("prezzo", QString::number(toSave->getPrezzo()));
        writer.writeAttribute("biglietti", QString::number(toSave->getBiglietti()));

        if(tipo == "Cinema"){
            const Cinema* p = static_cast<const Cinema*>(toSave);
            writer.writeAttribute("autore", QString::fromStdString(p->getAutore()));
            writer.writeAttribute("genere", QString::fromStdString(p->getGenere()));
            writer.writeAttribute("nome_cinema", QString::fromStdString(p->getNome()));

        }else if(tipo == "Teatro"){
            const Teatro* p = static_cast<const Teatro*>(toSave);
        writer.writeAttribute("genere", QString::fromStdString(p->getGenere()));
        writer.writeAttribute("autore", QString::fromStdString(p->getAutore()));
        writer.writeAttribute("nome_teatro", QString::fromStdString(p->getNome()));
        writer.writeAttribute("posti_galleria", QString::number(p->getBiglietti()));
        writer.writeAttribute("posti_platea", QString::number(p->getPlatea()));

        }else if(tipo=="Sport"){
            const Sport* p= static_cast<const Sport*>(toSave);
        writer.writeAttribute("disciplina", QString::fromStdString(p->getGenere()));

        }else if(tipo=="Concerto"){
            const Concerto* p= static_cast<const Concerto*>(toSave);
        writer.writeAttribute("genere", QString::fromStdString(p->getGenere()));
        writer.writeAttribute("artista", QString::fromStdString(p->getAutore()));
        }
        if (writer.hasError()){
            throw wrong("errore nel salvataggio vede");//vedere come gestire questo errore
        }

        ++it;
    }

    writer.writeEndElement();
    writer.writeEndDocument();
    isDataSaved=true;
    file.commit();
}

void XmlIO::load() {

    QFile file(QString::fromStdString(path));
    if(!file.open(QIODevice::ReadOnly)){//? controllare cosa fa sto controllo
        throw wrong("Errorre in apertura del file.");
    }

    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement()){
        if(reader.name()=="root"){
            while(reader.readNextStartElement()){
                const QXmlStreamAttributes att = reader.attributes();// decidere se i dati salvati possono non avere i campi compilati

                string titolo = att.hasAttribute("titolo")? att.value("titolo").toString().toStdString() : "";
                //QString path = att.hasAttribute("path")? att.value("path").toString() : "";
                unsigned int durata = att.hasAttribute("durata")? att.value("durata").toUInt() : 0;//trasformare in int
                string luogo = att.hasAttribute("luogo")? att.value("luogo").toString().toStdString() : "";
                double prezzo = att.hasAttribute("prezzo")? att.value("prezzo").toDouble() : 0;
                unsigned int biglietti = att.hasAttribute("biglietti")? att.value("biglietti").toUInt() : 0;

                Evento* toPush = nullptr;

                if(reader.name() == "Cinema"){
                    string genere = att.hasAttribute("genere") ? att.value("genere").toString().toStdString() : "";
                    string autore = att.hasAttribute("autore") ? att.value("autore").toString().toStdString() : "";
                    string nome_cinema= att.hasAttribute("nome_cinema") ? att.value("nome_cinema").toString().toStdString() : "";
                    toPush= new Cinema(nome_cinema, autore, genere, titolo, prezzo, luogo, biglietti, durata);

                }else if(reader.name() == "Teatro"){
                    string genere = att.hasAttribute("genere") ? att.value("genere").toString().toStdString() : "";
                    string autore = att.hasAttribute("autore") ? att.value("autore").toString().toStdString() : "";
                    string nome_teatro= att.hasAttribute("nome_teatro") ? att.value("nome_teatro").toString().toStdString() : "";
                    unsigned int galleria = att.hasAttribute("posti_galleria") ? att.value("posti_galleria").toUInt() : 0;
                    unsigned int platea = att.hasAttribute("posti_platea") ? att.value("posti_platea").toUInt() : 0;
                    toPush= new Teatro(nome_teatro, galleria, platea, autore, genere, titolo, prezzo, luogo, biglietti, durata);

                }else if(reader.name() == "Concerto"){
                    string genere = att.hasAttribute("genere") ? att.value("genere").toString().toStdString() : "";
                    string artista = att.hasAttribute("artista") ? att.value("artista").toString().toStdString() : "";
                    string stadio = att.hasAttribute("stadio") ? att.value("stadio").toString().toStdString() : "";
                    toPush= new Concerto(artista, genere, stadio, titolo, prezzo, luogo, biglietti, durata);

                }else if(reader.name()=="Sport"){
                    string disciplina = att.hasAttribute("disciplina")? att.value("disciplina").toString().toStdString() : "";
                    string stadio = att.hasAttribute("stadio") ? att.value("stadio").toString().toStdString() : "";
                    toPush= new Sport(disciplina, stadio, titolo, prezzo, luogo, biglietti, durata);
                }

                if(toPush!= nullptr){
                    push_end(toPush);
                }
                else
                    throw wrong("è esploso qualcosa"); // vedere dove viene presa questa eccezione

                if(!reader.isEndDocument())
                    reader.skipCurrentElement();
            }
        }
    }
    file.close();
    isDataSaved=true;
}

void XmlIO::push_end(Evento *a) {
    vec->push_back(a);
}


//void XmlIO::eliminaTrovati() const
//{
//    for(auto it = res_cbegin(); it != res_cend(); ++it){
//        vec->erase(*it);
//        delete (*it);
//    }
//    resetSearchRes();
//}




//XmlIO::~XmlIO(){
//    for(unsigned int i=0; i<list->getSize(); i++)
//        delete list->at(i);
//    delete searchRes;
//}




//void Modello::erase(unsigned int index ){
//    isDataSaved=false;
//    list->erase(index);
//}

//void Modello::erase(unsigned int start, unsigned int end){
//    isDataSaved=false;
//    list->erase(start,end);
//}

// void Modello::erase(Abbigliamento* it)
//{
//    isDataSaved=false;
//     list->erase(it);
//}


//void Modello::clear(){
//    isDataSaved=false;
//    for(unsigned int i=0; i<list->getSize(); i++)
//        delete list->at(i);
//    list->clear();
//    searchRes->clear();
//}

//XmlIO::XmlIO(string p):
//    vec(new Qontainer<Abbigliamento*>(2)),
//    searchRes(new Qontainer<Abbigliamento*>(2)),
//    path(p),
//    isDataSaved(true){}
