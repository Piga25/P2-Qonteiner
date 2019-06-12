#include "cinema.h"

Cinema::Cinema(QString film, QString cinema, QString autore,
               QString genre, double price, QString place, unsigned int ticket, unsigned int lenght) :
    Evento (film, price, place, ticket, lenght), nomeC(cinema), autoreC(autore), genere(genre)  {}

QString Cinema::getTipo() const {
    return "Cinema";
}
Cinema* Cinema::clone()const{
    return new Cinema(*this);
}
bool Cinema::operator==(const Evento& e) const
{
    Cinema* v=dynamic_cast<Cinema*>(&const_cast<Evento&>(e));
    if(v)
        return getTipo()==v->getTipo();
    return false;
}

QString Cinema::getNome() const{
    return nomeC;
}
QString Cinema::getAutore() const{
    return autoreC;
}
QString Cinema::getGenere() const{
    return genere;
}
