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
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QGroupBox>
#include <QMessageBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QStackedLayout>

class ricercaitemW : public QWidget
{
    Q_OBJECT
public:
    explicit ricercaitemW(QWidget* parent = nullptr);
    ~ricercaitemW() = default;
    QLayout* ricercabase();
    DeepPtr<Evento> res();
    void setValues(DeepPtr<Evento>);
public slots:
    /*void eliminatrovati();
    void cerca();
    void resetcampi();*/
private:
    Container<DeepPtr<Evento>> list;
    QListWidget* lista;

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

#endif // RICERCAITEMW_H
