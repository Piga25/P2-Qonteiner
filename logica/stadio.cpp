#include "stadio.h"

Stadio::Stadio(QString name, QString event, double price, QString place, unsigned int ticket, unsigned int time) :
    Evento(event, price, place, ticket, time), nomeS(name) {}

QString Stadio::getNome() const {
    return nomeS;
}
