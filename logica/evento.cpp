#include "evento.h"

Evento::Evento(QString t, double p, QString l, unsigned int b, unsigned int d) :
                titolo(t), prezzo(p), luogo(l), biglietti(b), durata(d) {}

QString Evento::get_titolo() const {
    return titolo;
}
double Evento::getPrezzo() const {
    return prezzo;
}
QString Evento::getLuogo() const {
    return luogo;
}
unsigned int Evento::getBiglietti() const {
    return biglietti;
}
unsigned int Evento::getDurata() const {
    return durata;
}

double Evento::getPrezzoPlatea() const {
    return 0;
}

unsigned int Evento::getPlatea() const {
    return 0;
}
