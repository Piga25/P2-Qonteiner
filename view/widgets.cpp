#include "widgets.h"
#include <QDesktopWidget>

widgets::widgets(QWidget* parent) : QWidget(parent)
{
    Qt::WA_DeleteOnClose;
    setFixedSize(400,600);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

    setLayout(base());

    connect(t,SIGNAL(clicked()),this,SLOT(teatroChecked()));
    connect(ci,SIGNAL(clicked()),this,SLOT(cinemaChecked()));
    connect(co,SIGNAL(clicked()),this,SLOT(concertoChecked()));
    connect(s,SIGNAL(clicked()),this,SLOT(sportChecked()));
    connect(salva,SIGNAL(clicked()),this,SLOT(aggiungiClicked()));
    connect(pulisci,SIGNAL(clicked()),this,SLOT(pulisciClicked()));

}

void widgets::teatroChecked(){
    groups->setCurrentIndex(0);
}

void widgets::cinemaChecked(){
    groups->setCurrentIndex(1);
}

void widgets::concertoChecked(){
    groups->setCurrentIndex(2);
}

void widgets::sportChecked(){
    groups->setCurrentIndex(3);
}

void widgets::pulisciClicked(){
    groups->setCurrentIndex(0);
    reset();
}

QLayout* widgets::base(){
    //Elementi standard per tutti gli eventi
    titolo=new QLineEdit();
    titololabel=new QLabel("Titolo");
    prezzo=new QLineEdit();
    prezzolabel=new QLabel("Prezzo");
    prezzo->setValidator( new QDoubleValidator(0.01, 999.99, 2, this));
    indirizzo=new QLineEdit();
    indirizzolabel=new QLabel("Indirizzo");
    biglietti=new QLineEdit();
    bigliettilabel=new QLabel("Biglietti disponibili");
    biglietti->setValidator( new QIntValidator(0, 1000, this));
    durata=new QLineEdit();
    duratalabel=new QLabel("Durata");
    durata->setValidator( new QIntValidator(0, 300, this));

    QVBoxLayout* vertical1=new QVBoxLayout();
    QHBoxLayout* horizontal1=new QHBoxLayout();
    QHBoxLayout* horizontal2=new QHBoxLayout();
    QHBoxLayout* horizontal3=new QHBoxLayout();
    QHBoxLayout* horizontal4=new QHBoxLayout();
    QHBoxLayout* horizontal5=new QHBoxLayout();
    horizontal1->addWidget(titololabel);
    horizontal1->addWidget(titolo);
    horizontal2->addWidget(duratalabel);
    horizontal2->addWidget(durata);
    horizontal3->addWidget(indirizzolabel);
    horizontal3->addWidget(indirizzo);
    horizontal4->addWidget(prezzolabel);
    horizontal4->addWidget(prezzo);
    horizontal5->addWidget(bigliettilabel);
    horizontal5->addWidget(biglietti);

    vertical1->addLayout(horizontal1);
    vertical1->addLayout(horizontal2);
    vertical1->addLayout(horizontal3);
    vertical1->addLayout(horizontal4);
    vertical1->addLayout(horizontal5);

    t=new QRadioButton(tr("Teatro"));
    ci=new QRadioButton(tr("Cinema"));
    co=new QRadioButton(tr("Concerto"));
    s=new QRadioButton(tr("Sport"));
    t->setChecked(true);
    QHBoxLayout* horizontalradio=new QHBoxLayout();
    horizontalradio->addWidget(t);
    horizontalradio->addWidget(ci);
    horizontalradio->addWidget(co);
    horizontalradio->addWidget(s);

    nome1=new QLineEdit();
    nome1label=new QLabel("Nome del Teatro");
    nome2=new QLineEdit();
    nome2label=new QLabel("Nome del Cinema");
    nome3=new QLineEdit();
    nome3label=new QLabel("Nome dello Stadio");
    nome4=new QLineEdit();
    nome4label=new QLabel("Nome dello Stadio");

    autore1=new QLineEdit();
    autore1label=new QLabel("Autore dello Spettacolo");
    autore2=new QLineEdit();
    autore2label=new QLabel("Autore del Film");
    autore3=new QLineEdit();
    artistalabel=new QLabel("Artista");

    genere1=new QLineEdit();
    genere1label=new QLabel("Genere");
    genere2=new QLineEdit();
    genere2label=new QLabel("Genere");
    genere3=new QLineEdit();
    genere3label=new QLabel("Genere");
    genere4=new QLineEdit();
    disciplinalabel=new QLabel("Disciplina");

    plateaprezzo=new QLineEdit();
    plateaprezzolabel=new QLabel("Prezzo biglietti platea");
    plateaprezzo->setValidator( new QDoubleValidator(0.01, 999.99, 2, this));
    plateaposti=new QLineEdit();
    plateapostilabel=new QLabel("Biglietti platea");
    plateaposti->setValidator( new QIntValidator(0, 100, this));

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

    teatro=new QGroupBox();//gruppo teatro
    QVBoxLayout* verticalteatro=new QVBoxLayout();
    verticalteatro->addWidget(nome1label);
    verticalteatro->addWidget(nome1);
    verticalteatro->addWidget(genere1label);
    verticalteatro->addWidget(genere1);
    verticalteatro->addWidget(autore1label);
    verticalteatro->addWidget(autore1);
    verticalteatro->addWidget(plateaprezzolabel);
    verticalteatro->addWidget(plateaprezzo);
    verticalteatro->addWidget(plateapostilabel);
    verticalteatro->addWidget(plateaposti);
    teatro->setLayout(verticalteatro);

    cinema=new QGroupBox();//gruppo cinema
    QVBoxLayout* verticalcinema=new QVBoxLayout();
    verticalcinema->addWidget(nome2label);
    verticalcinema->addWidget(nome2);
    verticalcinema->addWidget(genere2label);
    verticalcinema->addWidget(genere2);
    verticalcinema->addWidget(autore2label);
    verticalcinema->addWidget(autore2);
    cinema->setLayout(verticalcinema);

    concerto=new QGroupBox();//gruppo concerto
    QVBoxLayout* verticalconcerto=new QVBoxLayout();
    verticalconcerto->addWidget(nome3label);
    verticalconcerto->addWidget(nome3);
    verticalconcerto->addWidget(genere3label);
    verticalconcerto->addWidget(genere3);
    verticalconcerto->addWidget(artistalabel);
    verticalconcerto->addWidget(autore3);
    concerto->setLayout(verticalconcerto);

    sport=new QGroupBox();//gruppo sport
    QVBoxLayout* verticalsport=new QVBoxLayout();
    verticalsport->addWidget(nome4label);
    verticalsport->addWidget(nome4);
    verticalsport->addWidget(disciplinalabel);
    verticalsport->addWidget(genere4);
    sport->setLayout(verticalsport);

    groups=new QStackedLayout();
    groups->addWidget(teatro);
    groups->addWidget(cinema);
    groups->addWidget(concerto);
    groups->addWidget(sport);
    groups->setCurrentIndex(0);

    //Bottoni principali per inviare dati o resettarla
    salva=new QPushButton(tr("Aggiungi/Salva modifiche"));
    salva->setMinimumSize(50,30);
    salva->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;}");
    pulisci=new QPushButton(tr("Pulisci campi"));
    pulisci->setMinimumSize(50,30);
    pulisci->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;}");
    QHBoxLayout* horizontalbutton=new QHBoxLayout();
    horizontalbutton->addWidget(salva);
    horizontalbutton->addWidget(pulisci);

    vertical=new QVBoxLayout();//composizione finestra
    vertical->addLayout(vertical1);
    vertical->addLayout(horizontalradio);
    vertical->addLayout(groups);
    vertical->addLayout(horizontalbutton);
    vertical->setContentsMargins(10,0,10,10);

    return vertical;
}

void widgets::aggiungiClicked(){
    if(titolo->text()=="" || prezzo->text()=="" || indirizzo->text()==""
       ||durata->text()=="" || biglietti->text()==""){
        QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
        return;
    }
    QString titoloText=titolo->text();
    double prezzoText=prezzo->text().toDouble();
    unsigned int bigliettiText=biglietti->text().toInt();
    unsigned int durataText=durata->text().toInt();
    QString indirizzoText=indirizzo->text();
    if(durataText<50){
        QMessageBox::information(this,tr("Attenzione!"),tr("Quello che stai inserendo non è un evento ma una cortometraggio."));
        return;
    }
    int const index=groups->currentIndex();
    if(index==0){
        if(nome1->text()==""||genere1->text()==""||autore1->text()==""
           ||plateaprezzo->text()=="" ||plateaposti->text()==""){
            QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
            return;
        }
        ritorno=new Teatro(nome1->text(), plateaprezzo->text().toDouble(), plateaposti->text().toInt(), autore1->text(), genere1->text(), titoloText, prezzoText, indirizzoText, bigliettiText, durataText);
    }
    else{
        if(index==1){
            if(nome2->text()==""||autore2->text()==""||genere2->text()==""){
                QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
                return;
            }
            ritorno=new Cinema(nome2->text(), autore2->text(), genere2->text(), titoloText, prezzoText, indirizzoText, bigliettiText, durataText);
        }
        else{
            if(index==2){
                if(nome3->text()==""||autore3->text()=="" ||genere3->text()=="" ){
                    QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
                    return;
                }
                ritorno=new Concerto(nome3->text(), autore3->text(), genere3->text(), titoloText, prezzoText, indirizzoText, bigliettiText, durataText);
            }
            else{
                if(index==3){
                    if(nome4->text()==""||genere4->text()==""){
                        QMessageBox::information(this,tr("Attenzione"),tr("Devi riempire tutti i campi"));
                        return;
                    }
                    ritorno=new Sport(nome4->text(), genere4->text(), titoloText, prezzoText, indirizzoText, bigliettiText, durataText);
                }
            }
        }
    }
    emit acceptedSignal();
    QMessageBox::information(this,tr("Oggetto aggiunto"),tr("L'evento è stato aggiunto con successo"));
    hide();
}

DeepPtr<Evento> widgets::res(){
    return ritorno;
}

void widgets::reset(){
    t->setChecked(true);
    QLineEdit* supl;
    std::list<QWidget*>::iterator i=l.begin();
    for(;i!=l.end();i++){
        if(dynamic_cast<QLineEdit*>(*i)){
            supl=dynamic_cast<QLineEdit*>(*i);
            supl->clear();
        }
    }
}

void widgets::setValues(DeepPtr<Evento> e){
    Teatro* supt;
    Cinema* supci;
    Concerto* supco;
    Sport* sups;
    if(dynamic_cast<Teatro*>(e.point)){
        groups->setCurrentIndex(0);
        t->setChecked(true);
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
            groups->setCurrentIndex(1);
            ci->setChecked(true);
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
                groups->setCurrentIndex(2);
                co->setChecked(true);
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
                    groups->setCurrentIndex(3);
                    s->setChecked(true);
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
