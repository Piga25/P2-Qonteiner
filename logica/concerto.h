#ifndef CONCERTO_H
#define CONCERTO_H
#include "stadio.h"

class Concerto : public Stadio
{
    private:
        QString artista;         //nome dell'artista
        QString genere;          //genere musicale
    public:
        //serve almeno un costruttore
        Concerto(QString, QString, QString, QString, double, QString, unsigned int, unsigned int); //inserirsco i parametri di corcerto, stadio, evento

        //metodi di Evento
        QString getTipo() const;
        Concerto* clone()const;
        bool operator==(const Evento&)const;

        //motodi di utilità di Concerto
        QString getAutore() const;           //restituisce il nome dell'artista
        QString getGenere() const;           //restituisce il genere musicale
        QString getNome() const;

};

#endif // CONCERTO_H
