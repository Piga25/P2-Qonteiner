#include "mainwindow.h"
#include <QDesktopWidget>
#include <QFileDialog>
using namespace std;

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    setFixedSize(500,400);
    QRect position = frameGeometry();
    position.moveCenter(QDesktopWidget().availableGeometry().center());
    move(position.topLeft());

    //DeepPtr<Evento> deep;
    //deep.point=new Teatro("Teatro La Scala", 89.90, 100, "Andrea Pigatto", "Commedia Informatica", "Un progetto per P2", 54.99, "Via Filodrammatici, 2, 20121 Milano MI", 350, 60);
    //list.add(deep->clone());

    edit=false;
    pop=new widgets();
    search=new ricercaitemW();
    visual=new visualizzaitemW();
    lista=new QListWidget();
    addtolist();

    addButton=new QPushButton(tr("Inserisci evento"));
    addButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    addButton->setMinimumSize(50,30);

    visualButton=new QPushButton(tr("Visualizza evento"));
    visualButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    visualButton->setMinimumSize(50,30);

    editButton=new QPushButton(tr("Modifica evento"));
    editButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    editButton->setMinimumSize(50,30);

    removeButton=new QPushButton(tr("Elimina evento"));
    removeButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    removeButton->setMinimumSize(50,30);

    searchButton=new QPushButton(tr("Ricerca evento"));
    searchButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    searchButton->setMinimumSize(50,30);

    saveButton=new QPushButton(tr("Salva"));
    saveButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    saveButton->setMinimumSize(50,30);

    loadButton=new QPushButton(tr("Carica"));
    loadButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    loadButton->setMinimumSize(50,30);

    resetButton=new QPushButton(tr("Reset"));
    resetButton->setStyleSheet("QPushButton{background-color:rgb(215,215,215); border:1px solid gray; border-radius: 5px;} QPushButton:pressed{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop: 0 #BEBEBE, stop: 1 #070707)}");
    resetButton->setMinimumSize(50,30);

    connect(addButton,SIGNAL(clicked()),this,SLOT(aggiungiNuovo()));
    connect(visualButton, SIGNAL(clicked()), this, SLOT(visualizzaClicked()));
    connect(editButton,SIGNAL(clicked()),this,SLOT(modificaClicked()));
    connect(removeButton,SIGNAL(clicked()),this,SLOT(rimuoviClicked()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(caricaClicked()));
    connect(saveButton,SIGNAL(clicked()),this,SLOT(salvaClicked()));
    connect(resetButton,SIGNAL(clicked()),this,SLOT(resetClicked()));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(cercaClicked()));
    connect(pop,SIGNAL(acceptedSignal()),this,SLOT(aggiungiEvento()));

    //inserisco il titolo e sottotitolo
    vert=new QVBoxLayout();
    vert->setContentsMargins(20,0,0,20);
    title=new QLabel(tr("Benvenuto nel catalogo dei tuoi eventi preferiti!!"));
    title->setStyleSheet("QLabel {font-weight: bold; font-size: 15px;}");
    subtitle=new QLabel(tr("Qui potrai gestirli a tuo piacimento"));
    subtitle->setStyleSheet("QLabel {font-size: 12px;}");
    vert->addWidget(title);
    vert->addWidget(subtitle);

    //inserisco la lista che conterrà gli eventi
    vert1=new QVBoxLayout();
    titlelist=new QLabel(tr("Lista eventi"));
    vert1->setContentsMargins(20,0,20,10);
    vert1->addWidget(titlelist);
    vert1->addWidget(lista);

    //inserisco i pulsanti sopra la lista
    horbutton1=new QHBoxLayout();
    horbutton1->setContentsMargins(20,0,20,10);
    horbutton1->addWidget(addButton);
    horbutton1->addWidget(visualButton);
    horbutton1->addWidget(editButton);
    horbutton1->addWidget(removeButton);
    horbutton1->addWidget(searchButton);

    //inserisco i pulsanti sotto la lista
    horbutton2=new QHBoxLayout();
    horbutton2->setContentsMargins(20,0,20,10);
    horbutton2->addWidget(saveButton);
    horbutton2->addWidget(loadButton);
    horbutton2->addWidget(resetButton);

    //setto tutto in un unico blocco
    v=new QVBoxLayout();
    v->addLayout(vert);
    v->addLayout(horbutton1);
    v->addLayout(vert1);
    v->addLayout(horbutton2);
    setLayout(v);
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

void MainWindow::visualizzaClicked(){
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
        visual->setValues(sup);
        visual->show();
    }else{
        QMessageBox::warning(this,tr("Attenzione!"),tr("Nessun evento selezionato dalla tua lista.\nPer selezionarne uno, inserisci un nuovo evento oppure caricane uno tramite gli appositi pulsanti:\nInserisci evento o Carica."));
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
        QMessageBox::warning(this,tr("Attenzione!"),tr("Nessun evento selezionato dalla tua lista.\nPer selezionarne uno, inserisci un nuovo evento oppure caricane uno tramite gli appositi pulsanti:\nInserisci evento o Carica."));
    }
}

void MainWindow::cercaClicked(){
    //search->reset();
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
        QMessageBox::information(this,tr("Caricamento file"),tr("Caricamento del file avvenuto con successo."));
        addtolist();
    }
    else
        QMessageBox::warning(this,tr("Errore"),tr("File non valido. \nLa prego di inserire un file con il formato .json."));
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
        QMessageBox::warning(this,tr("Errore"),tr("File non valido."));
        return;
    }else{
    saveLocation.write(doc.toJson());
    QMessageBox::information(this,tr("Salvataggio file"),tr("Salvataggio degli eventi avvenuto con successo."));
    }
}

void MainWindow::resetClicked(){
    lista->clear();
    addtolist();
}
