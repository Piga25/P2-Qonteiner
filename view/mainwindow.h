#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "logica/evento.h"
#include "view/widgets.h"
#include "view/ricercaitemw.h"
#include "view/visualizzaitemw.h"
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
    void visualizzaClicked();
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
    visualizzaitemW* visual;

    Container<DeepPtr<Evento>> list;
    QListWidget* lista;
    QPushButton* addButton;
    QPushButton* editButton;
    QPushButton* removeButton;
    QPushButton* searchButton;
    QPushButton* saveButton;
    QPushButton* loadButton;
    QPushButton* resetButton;
    QPushButton* visualButton;

    QVBoxLayout* vert; //inserimento titolo e sottotitolo della Main
    QLabel* title;
    QLabel* subtitle;

    QVBoxLayout* vert1; //inserimento titololista e lista
    QLabel* titlelist;

    QHBoxLayout* horbutton1; //inserimento dei pulsanti sopra la lista
    QHBoxLayout* horbutton2; //inserimento dei pulsanti sotto la lista

    QVBoxLayout* v; //unico blocco da visualizzare
};

#endif // MAINWINDOW_H
