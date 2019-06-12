#include "mainwindow.h"
#include <QDesktopWidget>
#include <QFileDialog>
using namespace std;

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    setFixedSize(900,400);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

    //DeepPtr<Evento> deep;
    //deep.point=new Teatro("Teatro La Scala", 89.90, 100, "Andrea Pigatto", "Commedia Informatica", "Un progetto per P2", 54.99, "Via Filodrammatici, 2, 20121 Milano MI", 350, 60);
    //list.add(deep->clone());

    edit=false;
    pop=new widgets();
    //search=new ricercaitemW();
    lista=new QListWidget();
    addtolist();

    /*clickableList = new QLineEdit();
    clickableList->setReadOnly(true);
    clickableList->setAlignment(Qt::AlignCenter);*/

    conta = new QLineEdit();
    conta->setReadOnly(true);
    conta->setAlignment(Qt::AlignCenter);

    addButton=new QPushButton(tr("Inserisci nuovo \n    evento"));
    addButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    addButton->setMinimumSize(50,30);
    addButton->setMaximumSize(100,100);

    editButton=new QPushButton(tr("Modifica evento"));
    editButton->setMinimumSize(50,30);

    removeButton=new QPushButton(tr("Elimina evento"));
    removeButton->setMinimumSize(50,30);

    searchButton=new QPushButton(tr("Ricerca evento"));
    searchButton->setMinimumSize(50,30);

    saveButton=new QPushButton(tr("Salva"));
    saveButton->setMinimumSize(50,30);

    loadButton=new QPushButton(tr("Carica"));
    loadButton->setMinimumSize(50,30);

    resetButton=new QPushButton(tr("Reset"));
    resetButton->setMinimumSize(50,30);

    connect(addButton,SIGNAL(clicked()),this,SLOT(aggiungiNuovo()));
    connect(editButton,SIGNAL(clicked()),this,SLOT(modificaClicked()));
    connect(removeButton,SIGNAL(clicked()),this,SLOT(rimuoviClicked()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(caricaClicked()));
    connect(saveButton,SIGNAL(clicked()),this,SLOT(salvaClicked()));
    connect(resetButton,SIGNAL(clicked()),this,SLOT(resetClicked()));
    connect(pop,SIGNAL(acceptedSignal()),this,SLOT(aggiungiEvento()));

    //filtri per ricerca
    ricercalabel=new QLabel("Ricerca un Evento!!");
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

    hor=new QHBoxLayout();
    vert1=new QVBoxLayout();
    vert1->setContentsMargins(20,0,20,30);
    vert2=new QVBoxLayout();
    vert2->setContentsMargins(0,0,20,30);
    vert3=new QVBoxLayout();
    vert3->setContentsMargins(0,0,20,30);

    v1=new QVBoxLayout();
    v2=new QVBoxLayout();
    v3=new QVBoxLayout();
    v4=new QVBoxLayout();
    v5=new QVBoxLayout();
    v6=new QVBoxLayout();
    v7=new QVBoxLayout();
    v8=new QVBoxLayout();
    v9=new QVBoxLayout();
    h=new QHBoxLayout();
    h1=new QHBoxLayout();
    h2=new QHBoxLayout();

    //inserisco la lista che conterrà gli eventi
    vert1->addWidget(conta);
    vert1->addWidget(lista);

    //inserisco i pulsanti a lato della lista
    vert2->addWidget(addButton);
    vert2->addWidget(editButton);
    vert2->addWidget(removeButton);
    vert2->addWidget(saveButton);
    vert2->addWidget(loadButton);
    vert2->addWidget(resetButton);

    //inserisco i campi della ricerca
    v1->addWidget(ricercalabel);
    v1->addWidget(categorialabel);
    v1->addWidget(categoria);
    v1->addWidget(titlab);
    v1->addWidget(tit);
    v1->addWidget(genlab);
    v1->addWidget(gen);
    v1->addWidget(autlab);
    v1->addWidget(aut);
    v1->addWidget(nomlab);
    v1->addWidget(nom);
    v1->addWidget(indlab);
    v1->addWidget(ind);
    v2->addWidget(dur1lab);
    v3->addWidget(pre1lab);
    v4->addWidget(dur1);
    v5->addWidget(pre1);
    v6->addWidget(dur2lab);
    v7->addWidget(pre2lab);
    v8->addWidget(dur2);
    v9->addWidget(pre2);
    h1->addLayout(v2);
    h1->addLayout(v4);
    h1->addLayout(v6);
    h1->addLayout(v8);
    h2->addLayout(v3);
    h2->addLayout(v5);
    h2->addLayout(v7);
    h2->addLayout(v9);
    v1->addLayout(h1);
    v1->addLayout(h2);
    v1->addWidget(searchButton);
    h->addLayout(v1);
    vert3->addLayout(h);

    //setto tutto in un unico blocco
    hor->addLayout(vert1);
    hor->addLayout(vert2);
    hor->addLayout(vert3);
    setLayout(hor);
}

void MainWindow::aggiungiNuovo(){
    pop->reset();
    pop->show();
}

void MainWindow::aggiungiEvento(){
    if(edit){
        delete item;
        edit=false;
    }
    list.add(pop->res()->clone());
    lista->addItem((list.end()-1)->point->get_titolo());
    //lista->addItem((list.end()-1)->point->getGenere);
}

void MainWindow::addtolist(){
    Container<DeepPtr<Evento>>::iterator it=list.begin();
    for(;it!=list.end();it++){
        lista->addItem((*it)->get_titolo());
        //lista->addItem((*it)->getGenere());
    }
}

void MainWindow::modificaClicked(){
    edit=true;
    DeepPtr<Evento> sup;
    bool found=false;
    item=lista->currentItem();
    if(item){
        Container<DeepPtr<Evento>>::iterator it=list.begin();
        unsigned int i=0;
        for(;!found&&it!=list.end();it++){
            if((*it)->get_titolo()==item->text()){
                sup=(*it)->clone();
                list.erase(i);
                found=true;
            }
            i++;
        }
        pop->setValues(sup);
        pop->show();
    }else{
        QMessageBox::warning(this,tr("Attenzione!"),tr("Nessun elemento selezionato"));
    }
}

void MainWindow::cercaClicked(){
    search->show();
}

void MainWindow::rimuoviClicked(){
    QListWidgetItem* item2=lista->currentItem();
    bool found=false;
    if(item2){Container<DeepPtr<Evento>>::iterator it=list.begin();
        unsigned int i=0;
        for(;!found&&it!=list.end();it++){
            if((*it)->get_titolo()==item2->text()){
                list.erase(i);
                found=true;
            }
            i++;
        }
        delete item2;
    }
}

bool MainWindow::loadfile(QString filepath){
    QFile file(filepath);
    file.open(QIODevice::ReadOnly);
    QByteArray jsonData = file.readAll();
    file.close();
    QJsonDocument document = QJsonDocument::fromJson(jsonData);
    QJsonArray array=document.object().value("Eventi").toArray();
    if(!array.isEmpty()){
        if(!list.isEmpty()){
            list.clear();
        }
        foreach(const QJsonValue& v, array) {
            QString tipo = QString(v.toObject().value("categoria").toString());
            if(tipo=="Teatro"){
                    list.add(new Teatro(v.toObject().value("nomeluogo").toString(),
                                        v.toObject().value("prezzoplatea").toDouble(),
                                        v.toObject().value("postiplatea").toInt(),
                                        v.toObject().value("autore").toString(),
                                        v.toObject().value("genere").toString(),
                                        v.toObject().value("titolo").toString(),
                                        v.toObject().value("prezzo").toDouble(),
                                        v.toObject().value("indirizzo").toString(),
                                        v.toObject().value("biglietti").toInt(),
                                        v.toObject().value("durata").toInt()));
            }
            else if(tipo=="Cinema"){
                    list.add(new Cinema(v.toObject().value("nomeluogo").toString(),
                                        v.toObject().value("autore").toString(),
                                        v.toObject().value("genere").toString(),
                                        v.toObject().value("titolo").toString(),
                                        v.toObject().value("prezzo").toDouble(),
                                        v.toObject().value("indirizzo").toString(),
                                        v.toObject().value("biglietti").toInt(),
                                        v.toObject().value("durata").toInt()));
            }
            else if(tipo=="Concerto"){
                    list.add(new Concerto(v.toObject().value("artista").toString(),
                                          v.toObject().value("genere").toString(),
                                          v.toObject().value("nomeluogo").toString(),
                                          v.toObject().value("titolo").toString(),
                                          v.toObject().value("prezzo").toDouble(),
                                          v.toObject().value("indirizzo").toString(),
                                          v.toObject().value("biglietti").toInt(),
                                          v.toObject().value("durata").toInt()));
            }
            else if(tipo=="Sport"){
                    list.add(new Sport(v.toObject().value("disciplina").toString(),
                                       v.toObject().value("nomeluogo").toString(),
                                       v.toObject().value("titolo").toString(),
                                       v.toObject().value("prezzo").toDouble(),
                                       v.toObject().value("indirizzo").toString(),
                                       v.toObject().value("biglietti").toInt(),
                                       v.toObject().value("durata").toInt()));
            }
        }
        return true;
    }
    return false;
}


void MainWindow::caricaClicked(){
    QFileDialog dialog(this);
    dialog.setNameFilter("*.json");
    QString fileName = dialog.getOpenFileName(this, "Get list from a file", "", "Json File (*.json)");
    if(loadfile(fileName)){
        QMessageBox::information(this,tr("Caricamento file"),tr("Caricamento avvenuto con successo"));
        addtolist();
    }
    else
        QMessageBox::warning(this,tr("Errore"),tr("File non valido"));
}

void MainWindow::salvaClicked(){
    QFileDialog dialog(this);
    dialog.setNameFilter("*.json");
    QString fileName = dialog.getSaveFileName(this, "Save current list", "", "Json File (*.json)");
    if(!fileName.endsWith(".json")) {
        fileName += ".json";
    }
    QFile saveLocation(fileName);

    QJsonArray EventArray;
    for(auto it=list.begin();it!=list.end();it++){
        QJsonObject singleEntry;
        singleEntry.insert("titolo",QJsonValue::fromVariant((*it)->get_titolo()));
        singleEntry.insert("prezzo",QJsonValue::fromVariant((*it)->getPrezzo()));
        singleEntry.insert("indirizzo",QJsonValue::fromVariant((*it)->getLuogo()));
        singleEntry.insert("biglietti",QJsonValue::fromVariant((*it)->getBiglietti()));
        singleEntry.insert("durata",QJsonValue::fromVariant((*it)->getDurata()));

        if(dynamic_cast<Stadio*>((*it).point)){
            Stadio* auxs=static_cast<Stadio*>((*it).point);
            singleEntry.insert("nomeluogo",QJsonValue::fromVariant(auxs->getNome()));
            if(dynamic_cast<Concerto*>((*it).point)){
                Concerto* auxco=static_cast<Concerto*>((*it).point);
                singleEntry.insert("categoria",QJsonValue::fromVariant(auxco->getTipo()));
                singleEntry.insert("artista",QJsonValue::fromVariant(auxco->getAutore()));
                singleEntry.insert("genere",QJsonValue::fromVariant(auxco->getGenere()));
            }
            else{
                Sport* auxss=static_cast<Sport*>((*it).point);
                singleEntry.insert("categoria",QJsonValue::fromVariant(auxss->getTipo()));
                singleEntry.insert("disciplina",QJsonValue::fromVariant(auxss->getGenere()));
            }
        }
        else{
            if(dynamic_cast<Teatro*>((*it).point)){
                Teatro* auxt=static_cast<Teatro*>((*it).point);
                singleEntry.insert("categoria",QJsonValue::fromVariant(auxt->getTipo()));
                singleEntry.insert("nomeluogo",QJsonValue::fromVariant(auxt->getNome()));
                singleEntry.insert("genere",QJsonValue::fromVariant(auxt->getGenere()));
                singleEntry.insert("autore",QJsonValue::fromVariant(auxt->getAutore()));
                singleEntry.insert("prezzoplatea",QJsonValue::fromVariant(auxt->getPrezzoPlatea()));
                singleEntry.insert("postiplatea",QJsonValue::fromVariant(auxt->getPlatea()));
            }
            else if(dynamic_cast<Cinema*>((*it).point)){
                Cinema* auxci=static_cast<Cinema*>((*it).point);
                singleEntry.insert("categoria",QJsonValue::fromVariant(auxci->getTipo()));
                singleEntry.insert("nomeluogo",QJsonValue::fromVariant(auxci->getNome()));
                singleEntry.insert("genere",QJsonValue::fromVariant(auxci->getGenere()));
                singleEntry.insert("autore",QJsonValue::fromVariant(auxci->getAutore()));
            }
        }
        EventArray.append(singleEntry);
    }
    QJsonObject toInsert;
    toInsert.insert("Eventi", EventArray);
    QJsonDocument doc(toInsert);
    if(!saveLocation.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this,tr("Errore"),tr("File non valido"));
        return;
    }else{
    saveLocation.write(doc.toJson());
    QMessageBox::information(this,tr("Salvataggio file"),tr("Salvataggio avvenuto con successo"));
    }
}

void MainWindow::resetClicked(){
    lista->clear();
    addtolist();
}
