#include "visualizzaitemw.h"
#include <QDesktopWidget>

visualizzaitemW::visualizzaitemW(QWidget* parent) : QWidget(parent)
{
    Qt::WA_DeleteOnClose;
    setFixedSize(300,350);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

    setLayout(visualizzabase());

    l.push_back(titolo);
    l.push_back(prezzo);
    l.push_back(indirizzo);
    l.push_back(biglietti);
    l.push_back(durata);
    l.push_back(nome1);
    l.push_back(nome2);
    l.push_back(nome3);
    l.push_back(nome4);
    l.push_back(autore1);
    l.push_back(autore2);
    l.push_back(autore3);
    l.push_back(genere1);
    l.push_back(genere2);
    l.push_back(genere3);
    l.push_back(genere4);
    l.push_back(plateaprezzo);
    l.push_back(plateaposti);
}

QLayout* visualizzaitemW::visualizzabase(){

    //Elementi standard per tutti gli eventi
    titolo=new QLineEdit();
    titolo->setReadOnly(true);
    titolo->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    titololabel=new QLabel("Titolo:");
    prezzo=new QLineEdit();
    prezzo->setReadOnly(true);
    prezzo->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    prezzolabel=new QLabel("Prezzo:");
    prezzo->setValidator( new QDoubleValidator(0.01, 999.99, 2, this));
    indirizzo=new QLineEdit();
    indirizzo->setReadOnly(true);
    indirizzo->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    indirizzolabel=new QLabel("Indirizzo:");
    biglietti=new QLineEdit();
    biglietti->setReadOnly(true);
    biglietti->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    bigliettilabel=new QLabel("Biglietti disponibili:");
    biglietti->setValidator( new QIntValidator(0, 1000, this));
    durata=new QLineEdit();
    durata->setReadOnly(true);
    durata->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    duratalabel=new QLabel("Durata:");
    durata->setValidator( new QIntValidator(0, 300, this));

    //Elementi per un diverso tipo di evento
    nome1=new QLineEdit();
    nome1->setReadOnly(true);
    nome1->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    nome1label=new QLabel("Nome del Teatro:");
    nome2=new QLineEdit();
    nome2->setReadOnly(true);
    nome2->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    nome2label=new QLabel("Nome del Cinema:");
    nome3=new QLineEdit();
    nome3->setReadOnly(true);
    nome3->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    nome3label=new QLabel("Nome dello Stadio:");
    nome4=new QLineEdit();
    nome4->setReadOnly(true);
    nome4->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    nome4label=new QLabel("Nome dello Stadio:");

    autore1=new QLineEdit();
    autore1->setReadOnly(true);
    autore1->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    autore1label=new QLabel("Autore dello Spettacolo:");
    autore2=new QLineEdit();
    autore2->setReadOnly(true);
    autore2->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    autore2label=new QLabel("Autore del Film:");
    autore3=new QLineEdit();
    autore3->setReadOnly(true);
    autore3->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    artistalabel=new QLabel("Artista:");

    genere1=new QLineEdit();
    genere1->setReadOnly(true);
    genere1->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    genere1label=new QLabel("Genere:");
    genere2=new QLineEdit();
    genere2->setReadOnly(true);
    genere2->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    genere2label=new QLabel("Genere:");
    genere3=new QLineEdit();
    genere3->setReadOnly(true);
    genere3->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    genere3label=new QLabel("Genere:");
    genere4=new QLineEdit();
    genere4->setReadOnly(true);
    genere4->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    disciplinalabel=new QLabel("Disciplina:");

    plateaprezzo=new QLineEdit();
    plateaprezzo->setReadOnly(true);
    plateaprezzo->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    plateaprezzolabel=new QLabel("Prezzo biglietti platea:");
    plateaprezzo->setValidator( new QDoubleValidator(0.01, 999.99, 2, this));
    plateaposti=new QLineEdit();
    plateaposti->setReadOnly(true);
    plateaposti->setStyleSheet("QLineEdit{background-color: lightgrey; border:none;}");
    plateapostilabel=new QLabel("Biglietti platea:");
    plateaposti->setValidator( new QIntValidator(0, 100, this));

    //orizzontale per ogni label
    QHBoxLayout* hor1=new QHBoxLayout(); //titolo
    hor1->addWidget(titololabel);
    hor1->addWidget(titolo);

    QHBoxLayout* hor2=new QHBoxLayout(); //genere
    hor2->addWidget(genere1label);
    hor2->addWidget(genere1);
    hor2->addWidget(genere2label);
    hor2->addWidget(genere2);
    hor2->addWidget(genere3label);
    hor2->addWidget(genere3);
    hor2->addWidget(disciplinalabel);
    hor2->addWidget(genere4);

    QHBoxLayout* hor3=new QHBoxLayout(); //autore
    hor3->addWidget(autore1label);
    hor3->addWidget(autore1);
    hor3->addWidget(autore2label);
    hor3->addWidget(autore2);
    hor3->addWidget(artistalabel);
    hor3->addWidget(autore3);

    QHBoxLayout* hor4=new QHBoxLayout(); //durata
    hor4->addWidget(duratalabel);
    hor4->addWidget(durata);

    QHBoxLayout* hor5=new QHBoxLayout(); //nome
    hor5->addWidget(nome1label);
    hor5->addWidget(nome1);
    hor5->addWidget(nome2label);
    hor5->addWidget(nome2);
    hor5->addWidget(nome3label);
    hor5->addWidget(nome3);
    hor5->addWidget(nome4label);
    hor5->addWidget(nome4);

    QHBoxLayout* hor6=new QHBoxLayout(); //indirizzo
    hor6->addWidget(indirizzolabel);
    hor6->addWidget(indirizzo);

    QHBoxLayout* hor7=new QHBoxLayout(); //prezzo
    hor7->addWidget(prezzolabel);
    hor7->addWidget(prezzo);
    hor7->addWidget(plateaprezzolabel);
    hor7->addWidget(plateaprezzo);

    QHBoxLayout* hor8=new QHBoxLayout(); //biglietti
    hor8->addWidget(bigliettilabel);
    hor8->addWidget(biglietti);
    hor8->addWidget(plateapostilabel);
    hor8->addWidget(plateaposti);

    vertical=new QVBoxLayout();//composizione finestra
    vertical->addLayout(hor1);
    vertical->addLayout(hor2);
    vertical->addLayout(hor3);
    vertical->addLayout(hor4);
    vertical->addLayout(hor5);
    vertical->addLayout(hor6);
    vertical->addLayout(hor7);
    vertical->addLayout(hor8);
    vertical->setContentsMargins(20,10,20,10);

    return vertical;
}

void visualizzaitemW::setValues(DeepPtr<Evento> e){
    Teatro* supt;
    Cinema* supci;
    Concerto* supco;
    Sport* sups;
    if(dynamic_cast<Teatro*>(e.point)){
        //setto invisibili i parametri riferiti ad altre categorie
        genere1->setVisible(true); //visibile genere giusto
        genere1label->setVisible(true);
        genere2->setVisible(false);
        genere2label->setVisible(false);
        genere3->setVisible(false);
        genere3label->setVisible(false);
        genere4->setVisible(false);
        disciplinalabel->setVisible(false);
        autore1->setVisible(true); //visibile autore giusto
        autore1label->setVisible(true);
        autore2->setVisible(false);
        autore2label->setVisible(false);
        autore3->setVisible(false);
        artistalabel->setVisible(false);
        nome1->setVisible(false); //visibile nome giusto
        nome1label->setVisible(false);
        nome2->setVisible(false);
        nome2label->setVisible(false);
        nome3->setVisible(false);
        nome3label->setVisible(false);
        nome4->setVisible(false);
        nome4label->setVisible(false);
        //visibile la platea
        plateaprezzo->setVisible(true);
        plateaprezzolabel->setVisible(true);
        plateaposti->setVisible(true);
        plateapostilabel->setVisible(true);

        supt=dynamic_cast<Teatro*>(e.point);
        titolo->setText(supt->get_titolo());
        prezzo->setText(QString::number(supt->getPrezzo()));
        indirizzo->setText(supt->getLuogo());
        biglietti->setText(QString::number(supt->getBiglietti()));
        durata->setText(QString::number(supt->getDurata()));
        nome1->setText(supt->getNome());
        autore1->setText(supt->getAutore());
        genere1->setText(supt->getGenere());
        plateaprezzo->setText(QString::number(supt->getPrezzoPlatea()));
        plateaposti->setText(QString::number(supt->getPlatea()));
        show();
    }
    else{
        if(dynamic_cast<Cinema*>(e.point)){
            //setto invisibili i parametri riferiti ad altre categorie
            genere1->setVisible(false);
            genere1label->setVisible(false);
            genere2->setVisible(true); //visibile il genere giusto
            genere2label->setVisible(true);
            genere3->setVisible(false);
            genere3label->setVisible(false);
            genere4->setVisible(false);
            disciplinalabel->setVisible(false);
            autore1->setVisible(false);
            autore1label->setVisible(false);
            autore2->setVisible(true); //visibile l'autore giusto
            autore2label->setVisible(true);
            autore3->setVisible(false);
            artistalabel->setVisible(false);
            nome1->setVisible(false);
            nome1label->setVisible(false);
            nome2->setVisible(true); //visibile il nome giusto
            nome2label->setVisible(true);
            nome3->setVisible(false);
            nome3label->setVisible(false);
            nome4->setVisible(false);
            nome4label->setVisible(false);
            plateaprezzo->setVisible(false);
            plateaprezzolabel->setVisible(false);
            plateaposti->setVisible(false);
            plateapostilabel->setVisible(false);

            supci=dynamic_cast<Cinema*>(e.point);
            titolo->setText(supci->get_titolo());
            prezzo->setText(QString::number(supci->getPrezzo()));
            indirizzo->setText(supci->getLuogo());
            biglietti->setText(QString::number(supci->getBiglietti()));
            durata->setText(QString::number(supci->getDurata()));
            nome2->setText(supci->getNome());
            autore2->setText(supci->getAutore());
            genere2->setText(supci->getGenere());
            show();
        }
        else{
            if(dynamic_cast<Concerto*>(e.point)){
                //setto invisibili i parametri riferiti ad altre categorie
                genere1->setVisible(false);
                genere1label->setVisible(false);
                genere2->setVisible(false);
                genere2label->setVisible(false);
                genere3->setVisible(true); //visibile il genere giusto
                genere3label->setVisible(true);
                genere4->setVisible(false);
                disciplinalabel->setVisible(false);
                autore1->setVisible(false);
                autore1label->setVisible(false);
                autore2->setVisible(false);
                autore2label->setVisible(false);
                autore3->setVisible(true); //visibile l'autore giusto
                artistalabel->setVisible(true);
                nome1->setVisible(false);
                nome1label->setVisible(false);
                nome2->setVisible(false);
                nome2label->setVisible(false);
                nome3->setVisible(true); //visibile il nome giusto
                nome3label->setVisible(true);
                nome4->setVisible(false);
                nome4label->setVisible(false);
                plateaprezzo->setVisible(false);
                plateaprezzolabel->setVisible(false);
                plateaposti->setVisible(false);
                plateapostilabel->setVisible(false);

                supco=dynamic_cast<Concerto*>(e.point);
                titolo->setText(supco->get_titolo());
                prezzo->setText(QString::number(supco->getPrezzo()));
                indirizzo->setText(supco->getLuogo());
                biglietti->setText(QString::number(supco->getBiglietti()));
                durata->setText(QString::number(supco->getDurata()));
                nome3->setText(supco->getNome());
                autore3->setText(supco->getAutore());
                genere3->setText(supco->getGenere());
            }
            else{
                if(dynamic_cast<Sport*>(e.point)){
                    //setto invisibili i parametri riferiti ad altre categorie
                    genere1->setVisible(false);
                    genere1label->setVisible(false);
                    genere2->setVisible(false);
                    genere2label->setVisible(false);
                    genere3->setVisible(false);
                    genere3label->setVisible(false);
                    genere4->setVisible(true); //visibile il genere giusto
                    disciplinalabel->setVisible(true);
                    autore1->setVisible(false);
                    autore1label->setVisible(false);
                    autore2->setVisible(false);
                    autore2label->setVisible(false);
                    autore3->setVisible(false);
                    artistalabel->setVisible(false);
                    nome1->setVisible(false);
                    nome1label->setVisible(false);
                    nome2->setVisible(false);
                    nome2label->setVisible(false);
                    nome3->setVisible(false);
                    nome3label->setVisible(false);
                    nome4->setVisible(true); //visibile il nome giusto
                    nome4label->setVisible(true);
                    plateaprezzo->setVisible(false);
                    plateaprezzolabel->setVisible(false);
                    plateaposti->setVisible(false);
                    plateapostilabel->setVisible(false);

                    sups=dynamic_cast<Sport*>(e.point);
                    titolo->setText(sups->get_titolo());
                    prezzo->setText(QString::number(sups->getPrezzo()));
                    indirizzo->setText(sups->getLuogo());
                    biglietti->setText(QString::number(sups->getBiglietti()));
                    durata->setText(QString::number(sups->getDurata()));
                    nome4->setText(sups->getNome());
                    genere4->setText(sups->getGenere());
                }
            }
        }
    }
}
