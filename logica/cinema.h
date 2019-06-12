#ifndef CINEMA_H
#define CINEMA_H
#include "evento.h"

class Cinema : public Evento
{
private:
        QString nomeC;       //nome del cinema
        QString autoreC;     //nome dell'autore
        QString genere;      //genere del film
    public:
        //Costruttori
        Cinema(QString, QString, QString, QString, double, QString, unsigned int, unsigned int);

        //metodi di Evento
        QString getTipo() const;
        Cinema* clone()const;
        bool operator==(const Evento&)const;

        //metodi di utilità di Cinema
        QString getNome() const;       //restituisce il nome del Cinema
        QString getAutore() const;     //restituisce il nome dell'autore
        QString getGenere() const;     //restituisce il genere del film

};

#endif // CINEMA_H
