#ifndef VISUALIZZAITEMW_H
#define VISUALIZZAITEMW_H

#include "logica/cinema.h"
#include "logica/concerto.h"
#include "logica/container.h"
#include "logica/deepptr.h"
#include "logica/sport.h"
#include "logica/teatro.h"
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QHBoxLayout>

class visualizzaitemW : public QWidget
{
    Q_OBJECT
public:
   explicit visualizzaitemW(QWidget* parent = nullptr);
   ~visualizzaitemW() = default;
   QLayout* visualizzabase();
   void setValues(DeepPtr<Evento>);
private:
   QLabel* visualizza;//intestazione
   QLabel* titololabel; //titolo evento
   QLabel* prezzolabel; //prezzo evento
   QLabel* indirizzolabel; //indirizzo evento
   QLabel* bigliettilabel; //biglietti evento
   QLabel* duratalabel; //durata evento
   QLabel* nome1label; //nome teatro, riferito al luogo dell'evento (esempio: per un teatro "La Scala di Milano")
   QLabel* nome2label; //nome cinema
   QLabel* nome3label; //nome stadio
   QLabel* nome4label; //nome stadio
   QLabel* autore1label; //autore teatro
   QLabel* autore2label; //autore cinema
   QLabel* artistalabel; //autore concerto
   QLabel* genere1label; //genere teatro
   QLabel* genere2label; //genere cinema
   QLabel* genere3label; //genere concerto
   QLabel* disciplinalabel; //genere sport
   QLabel* plateaprezzolabel;
   QLabel* plateapostilabel;
   QLineEdit* titolo;
   QLineEdit* prezzo;
   QLineEdit* indirizzo;
   QLineEdit* biglietti;
   QLineEdit* durata;
   QLineEdit* nome1;
   QLineEdit* nome2;
   QLineEdit* nome3;
   QLineEdit* nome4;
   QLineEdit* autore1;
   QLineEdit* autore2;
   QLineEdit* autore3;
   QLineEdit* genere1;
   QLineEdit* genere2;
   QLineEdit* genere3;
   QLineEdit* genere4;
   QLineEdit* plateaprezzo;
   QLineEdit* plateaposti;
   QVBoxLayout* vertical; //visualizzazione delle cose in modo verticale
   std::list<QWidget*> l;
};

#endif // VISUALIZZAITEMW_H
