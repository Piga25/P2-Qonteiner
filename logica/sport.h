#ifndef SPORT_H
#define SPORT_H
#include "stadio.h"

class Sport : public Stadio
{
    private:
        QString disciplina;      //nome dello sport
    public:
        //Costruttore
        Sport(QString, QString, QString, double, QString, unsigned int, unsigned int);

        //metodi di Evento
        QString getTipo() const;
        Sport* clone()const;
        bool operator==(const Evento&)const;

        //metodi di Sport
        QString getNome() const;
        QString getAutore() const;
        QString getGenere() const;  //restituisce la disciplina

};

#endif // SPORT_H
