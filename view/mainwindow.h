#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "logica/evento.h"
#include "view/widgets.h"
#include "view/ricercaitemw.h"
#include <QListWidget>
#include <QFile>
#include <QByteArray>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QComboBox>
#include <QButtonGroup>

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow()=default;
    void addtolist();
    bool loadfile(QString filepath);
public slots:
    void aggiungiNuovo();
    void aggiungiEvento();
    void modificaClicked();
    void rimuoviClicked();
    void caricaClicked();
    void salvaClicked();
    void resetClicked();
    void cercaClicked();
private:
    QListWidgetItem* item;
    bool edit;
    widgets* pop;
    ricercaitemW* search;

    Container<DeepPtr<Evento>> list;
    QListWidget* lista;
    QLineEdit* conta;
    //QMap<QString,DeepPtr<Evento>> salva;
    QPushButton* addButton;
    QPushButton* editButton;
    QPushButton* removeButton;
    QPushButton* searchButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    QPushButton* resetButton;
    //QLineEdit* clickableList;
    QHBoxLayout* hor;   //somma dei verticali messi in orizzontale
    QVBoxLayout* vert1; //lista di eventi
    QVBoxLayout* vert2; //lista di bottoni senza search (aggiungo bottone)
    QVBoxLayout* vert3; //filtri per ricerca con bottone

    QVBoxLayout* v1; //verticali per i filtri
    QVBoxLayout* v2;
    QVBoxLayout* v3;
    QVBoxLayout* v4;
    QVBoxLayout* v5;
    QVBoxLayout* v6;
    QVBoxLayout* v7;
    QVBoxLayout* v8;
    QVBoxLayout* v9;
    QHBoxLayout* h; //orizzontali per i filtri
    QHBoxLayout* h1;
    QHBoxLayout* h2;

    QLabel* ricercalabel;
    QLabel* categorialabel;
    QComboBox* categoria;
    QLabel* titlab;
    QLineEdit* tit;
    QLabel* genlab;
    QLineEdit* gen;
    QLabel* autlab;
    QLineEdit* aut;
    QLabel* nomlab;
    QLineEdit* nom;
    QLabel* indlab;
    QLineEdit* ind;
    QLabel* dur1lab;
    QLineEdit* dur1;
    QLabel* dur2lab;
    QLineEdit* dur2;
    QLabel* pre1lab;
    QLineEdit* pre1;
    QLabel* pre2lab;
    QLineEdit* pre2;

};

#endif // MAINWINDOW_H
