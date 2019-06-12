#ifndef TEATRO_H
#define TEATRO_H
#include "evento.h"

class Teatro : public Evento
{
    private:
        QString nomeT;                    //nome del Teatro
        double prezzo_platea;            //prezzo posti in platea
        unsigned int postiplatea;        //numero posti in platea
        QString autoreT;                  //nome dell'autore
        QString genere;                   //genere dello spettacolo
    public:
        //Costruttori
        Teatro(QString, double, unsigned int, QString, QString, QString, double, QString, unsigned int, unsigned int);

        QString getTipo() const;
        Teatro* clone()const;
        bool operator==(const Evento&)const;

        //metodi di utilità di Teatro
        QString getNome() const;                //restituisce il nome del Teatro
        double getPrezzoPlatea() const;        //restituisce il prezzo dei posti in platea
        unsigned int getPlatea() const;        //restituisce il numero dei posti in platea
        QString getAutore() const;              //restituisce il nome dell'autore
        QString getGenere() const;              //restituisce il genere dello spettacolo

};

#endif // TEATRO_H
