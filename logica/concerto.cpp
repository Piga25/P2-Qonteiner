#include "concerto.h"

Concerto::Concerto(QString artist, QString genre, QString name, QString event, double price, QString place, unsigned int ticket, unsigned int time) :
                    Stadio( name, event, price, place, ticket, time), artista(artist), genere(genre){}


QString Concerto::getTipo() const {
    return "Concerto";
}
Concerto* Concerto::clone()const{
    return new Concerto(*this);
}
bool Concerto::operator==(const Evento& e) const
{
    Concerto* v=dynamic_cast<Concerto*>(&const_cast<Evento&>(e));
    if(v)
        return static_cast<Stadio*>(const_cast<Concerto*>(this))==static_cast<Stadio*>(v)&&getTipo()==v->getTipo();
    return false;
}

QString Concerto::getAutore() const {
    return artista;
}

QString Concerto::getGenere() const {
    return genere;
}

QString Concerto::getNome() const {
    return Stadio::getNome();
}
