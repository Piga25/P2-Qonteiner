#ifndef XMLIO_H
#define XMLIO_H

#include <string>
#include <QString>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <exception/wrong.h>
#include <logica/cinema.h>
#include <logica/teatro.h>
#include <logica/stadio.h>
#include <logica/concerto.h>
#include <logica/sport.h>
#include <logica/evento.h>
#include <container/container.h>
#include <QErrorMessage>

using std::string;

class XmlIO {

private:
    Container<Evento*>* vec;
    string path;
    bool isDataSaved;
public:

    XmlIO(Container<Evento*>*);
    ~XmlIO() = default; // da controllare

    void push_end(Evento *);
    void printAll()const;
    Evento* elementAt(unsigned int);
    Container<Evento*>::Iterator begin();
    Container<Evento*>::Iterator end();
    Container<Evento*>::ConstIterator cbegin() const;
    Container<Evento*>::ConstIterator cend() const;
    unsigned int getDataSize()const;
    unsigned int getDataCapacity()const;
    void erase(unsigned int);
    void erase(unsigned int, unsigned int);
    void erase(Evento*);
    bool isDataEmpty()const;
    void clear();
    double calcolaTotale()const;

    void save();// non e' const poiche modifica il flag isDataSaved
    void load();
    void setNewPath(string );
    bool getIsDataSaved() const;
    void setDataSaved(bool);



    Container<Evento*>:: ConstIterator res_cbegin() const;
    Container<Evento*>:: ConstIterator res_cend() const;
    unsigned int getResSize() const;
    Evento* resElementAt(unsigned int);


    void resetSearchRes()const;
    void eliminaTrovati()const;
    void filterByName(string nome)const ;
    void filterBySex(string sesso)const;
    void filterByPriceMin(double prezzo)const;
    void filterByPriceMag(double prezzo)const;
    void filterBySeason(string stagione)const;
    void filterByType(string tipo)const;
};


#endif // XMLIO_H
