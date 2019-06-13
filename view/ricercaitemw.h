#ifndef RICERCAITEMW_H
#define RICERCAITEMW_H

#include "logica/cinema.h"
#include "logica/concerto.h"
#include "logica/container.h"
#include "logica/deepptr.h"
#include "logica/sport.h"
#include "logica/teatro.h"
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QHBoxLayout>

class ricercaitemW : public QWidget
{
    Q_OBJECT
public:
    explicit ricercaitemW(QWidget* parent = nullptr);
    ~ricercaitemW() = default;
    QLayout* ricercabase();
    //void addtolist();
    //void reset();
    //DeepPtr<Evento> res();
    //void setValues(DeepPtr<Evento>);
public slots:
    void cercaClicked();
    void pulisciClicked();
    void eliminatrovati();
signals:
    //void acceptedSignal();
private:
    //DeepPtr<Evento> ritorno;
    //QListWidgetItem* item;
    ricercaitemW* pop;
    Container<DeepPtr<Evento>> list;
    QListWidget* lista;

    QLabel* ricercalabel;
    QLabel* categorialabel;
    QComboBox* categoria;
    QLabel* titlab;
    QLineEdit* tit;
    QLabel* genlab;
    QLineEdit* gen;
    QLabel* autlab;
    QLineEdit* aut;

    QVBoxLayout* vertical; //visualizzazione delle cose in modo verticale

    QPushButton* cerca;
    QPushButton* pulisci;
    QPushButton* eliminatrov;

    //std::list<QWidget*> l;
};

#endif // RICERCAITEMW_H
