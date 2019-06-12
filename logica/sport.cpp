#include "sport.h"

Sport::Sport(QString discipline, QString name, QString event, double price, QString place, unsigned int ticket, unsigned int time) :
             Stadio(name, event, price, place, ticket, time), disciplina(discipline){}

QString Sport::getTipo() const {
    return "Sport";
}
Sport* Sport::clone()const{
    return new Sport(*this);
}
bool Sport::operator==(const Evento& e) const
{
    Sport* v=dynamic_cast<Sport*>(&const_cast<Evento&>(e));
    if(v)
        return static_cast<Stadio*>(const_cast<Sport*>(this))==static_cast<Stadio*>(v)&&getTipo()==v->getTipo();
    return false;
}

QString Sport::getGenere() const {
    return disciplina;
}

QString Sport::getNome() const {
    return Stadio::getNome();
}

QString Sport::getAutore() const {
    return "";
}
