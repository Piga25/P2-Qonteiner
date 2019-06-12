#ifndef EVENTO_H
#define EVENTO_H
#include <QString>

class Evento
{
protected:
    QString titolo;                  //titolo evento
    double prezzo;                  //prezzo evento
    QString luogo;                   //luogo in cui si svolge l'evento
    unsigned int biglietti;         //biglietti disponibili
    unsigned int durata;            //durata dell'evento espresso in minuti
public:
    //metodi virtuali
    Evento(QString, double, QString, unsigned int, unsigned int); //costruttore di default
    virtual ~Evento() = default;                                //distruttore di default
    virtual Evento* clone() const = 0;
    virtual bool operator==(const Evento&)const =0;
    virtual QString getTipo() const = 0;

    //metodi di utilità
    QString get_titolo() const;                      //metodo utilizzato per ritornare il titolo di qualsiasi evento
    double getPrezzo() const;                       //metodo utilizzato per ritornare il prezzo di qualsiasi evento
    QString getLuogo() const;                        //metodo utilizzato per ritornare il luogo di qualsiasi evento
    unsigned int getBiglietti() const;              //metodo utilizzato per ritornare i biglietti di qualsiasi evento
    unsigned int getDurata() const;                 //metodo utilizzato per ritornare la durata di qualsiasi evento

    //metodi astratti di utilità
    virtual QString getNome() const = 0;
    virtual QString getAutore() const = 0;
    virtual QString getGenere() const = 0;
    virtual double getPrezzoPlatea() const;
    virtual unsigned int getPlatea() const;
};

#endif // EVENTO_H
