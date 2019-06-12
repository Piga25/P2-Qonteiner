#ifndef STADIO_H
#define STADIO_H
#include "evento.h"

class Stadio : public Evento
{
    private:
        QString nomeS; //nome dello stadio
    public:
        //Costruttore
        Stadio(QString, QString, double, QString, unsigned int, unsigned int);

        //metodo di utilità di Stadio
        QString getNome() const; //restiturisce il nome dello stadio

};

#endif // STADIO_H
