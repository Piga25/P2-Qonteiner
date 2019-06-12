#include "ricercaitemw.h"
#include <QDesktopWidget>

ricercaitemW::ricercaitemW(QWidget* parent): QWidget(parent)
{
    Qt::WA_DeleteOnClose;
    setFixedSize(400,700);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

    //filtri per ricerca
    ricercalabel=new QLabel("Ricerca un Evento!!");
    categorialabel=new QLabel("Scegli la categoria");
    categoria=new QComboBox();
    titlab=new QLabel("Inserisci il titolo");
    tit=new QLineEdit();
    genlab=new QLabel("Inserisci il genere/disciplina");
    gen=new QLineEdit();
    autlab=new QLabel("Inserisci l'autore/artista");
    aut=new QLineEdit();
    nomlab=new QLabel("Inserisci il nome del luogo");
    nom=new QLineEdit();
    indlab=new QLabel("Inserisci l'indirizzo");
    ind=new QLineEdit();
    dur1lab=new QLabel("Inserisci una durata da");
    dur1=new QLineEdit();
    dur2lab=new QLabel("a");
    dur2=new QLineEdit();
    pre1lab=new QLabel("Inserisci un prezzo da");
    pre1=new QLineEdit();
    pre2lab=new QLabel("a");
    pre2=new QLineEdit();
}
