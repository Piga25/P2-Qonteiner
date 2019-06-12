#include "teatro.h"

Teatro::Teatro(QString name, double priceplatea, unsigned int seat, QString author, QString genre, QString opera, double price, QString place, unsigned int ticket, unsigned int time) :
    Evento(opera, price, place, ticket, time), nomeT(name), prezzo_platea(priceplatea), postiplatea(seat), autoreT(author), genere(genre) {}

QString Teatro::getTipo() const {
    return "Teatro";
}
Teatro* Teatro::clone()const{
    return new Teatro(*this);
}
bool Teatro::operator==(const Evento& e) const
{
    Teatro* v=dynamic_cast<Teatro*>(&const_cast<Evento&>(e));
    if(v)
        return getTipo()==v->getTipo();
    return false;
}

QString Teatro::getNome() const {
    return nomeT;
}

double Teatro::getPrezzoPlatea() const {
    return prezzo_platea;
}

unsigned int Teatro::getPlatea() const {
    return postiplatea;
}

QString Teatro::getAutore() const {
    return autoreT;
}

QString Teatro::getGenere() const {
    return genere;
}
