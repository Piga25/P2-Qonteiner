#include "ricercaitemw.h"
#include <QDesktopWidget>

ricercaitemW::ricercaitemW(QWidget* parent): QWidget(parent)
{
    Qt::WA_DeleteOnClose;
    setFixedSize(400,600);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

    setLayout(ricercabase());

    //addtolist();

    connect(pulisci, SIGNAL(clicked()), this, SLOT(pulisciClicked()));
    connect(eliminatrov, SIGNAL(clicked()), this, SLOT(eliminatrovati()));
    connect(cerca, SIGNAL(clicked()), this, SLOT(cercaClicked()));
}

void ricercaitemW::pulisciClicked(){
    //reset();
}
void ricercaitemW::cercaClicked(){
    //reset();
}
void ricercaitemW::eliminatrovati(){
    //reset();
}
/*void ricercaitemW::addtolist(){
    Container<DeepPtr<Evento>>::iterator it=list.begin();
    for(;it!=list.end();it++){
        lista->addItem((*it)->get_titolo());
        //lista->addItem((*it)->getGenere());
    }
}*/

QLayout* ricercaitemW::ricercabase(){

    //filtri per ricerca
    ricercalabel=new QLabel("Ricerca un Evento da eliminare!");
    ricercalabel->setStyleSheet("QLabel {font-weight: bold; font-size: 15px;}");
    categorialabel=new QLabel("Scegli la categoria");
    categoria=new QComboBox();
    categoria->addItem(tr("Teatro"));
    categoria->addItem(tr("Cinema"));
    categoria->addItem(tr("Concerto"));
    categoria->addItem(tr("Sport"));
    categoria->setCurrentIndex(-1);
    titlab=new QLabel("Inserisci il titolo");
    tit=new QLineEdit();
    genlab=new QLabel("Inserisci il genere/disciplina");
    gen=new QLineEdit();
    autlab=new QLabel("Inserisci l'autore/artista");
    aut=new QLineEdit();

    QVBoxLayout* vertical1=new QVBoxLayout();
    vertical1->addWidget(ricercalabel);
    vertical1->addWidget(categorialabel);
    vertical1->addWidget(categoria);
    vertical1->addWidget(titlab);
    vertical1->addWidget(tit);
    vertical1->addWidget(genlab);
    vertical1->addWidget(gen);
    vertical1->addWidget(autlab);
    vertical1->addWidget(aut);

    //Bottoni principali per cercare, pulire o eliminare
    cerca=new QPushButton(tr("Cerca"));
    cerca->setMinimumSize(50,30);
    cerca->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;}");
    pulisci=new QPushButton(tr("Pulisci campi"));
    pulisci->setMinimumSize(50,30);
    pulisci->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;}");
    eliminatrov=new QPushButton(tr("Elimina trovati"));
    eliminatrov->setMinimumSize(50,30);
    eliminatrov->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;}");

    QHBoxLayout* horizontalbutton=new QHBoxLayout();
    horizontalbutton->addWidget(cerca);
    horizontalbutton->addWidget(pulisci);

    //lista di item e bottone
    QVBoxLayout* vertical2=new QVBoxLayout();
    lista=new QListWidget();
    vertical2->addWidget(lista);
    vertical2->addWidget(eliminatrov);

    vertical=new QVBoxLayout();//composizione finestra
    vertical->addLayout(vertical1);
    vertical->addLayout(horizontalbutton);
    vertical->addLayout(vertical2);

    return vertical;
}
/*
void ricercaitemW::cerca(){
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
*/
/*DeepPtr<Evento> ricercaitemW::res(){
    return ritorno;
}*/

/*void ricercaitemW::reset(){
    QLineEdit* supl;
    std::list<QWidget*>::iterator i=l.begin();
    for(;i!=l.end();i++){
        if(dynamic_cast<QLineEdit*>(*i)){
            supl=dynamic_cast<QLineEdit*>(*i);
            supl->clear();
        }
    }
}*/
/*
void ricercaitemW::setValues(DeepPtr<Evento> e){
    Teatro* supt;
    Cinema* supci;
    Concerto* supco;
    Sport* sups;
    if(dynamic_cast<Teatro*>(e.point)){
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
}*/
