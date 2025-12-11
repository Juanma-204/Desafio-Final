#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer> //para el loop o el tiempo del nivel//
#include <QKeyEvent> //para implementar el tecleado, jugar con el teclado//
#include "vehiculo.h"
#include "obstaculo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void actualizarJuego(); //loop del juego

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QTimer *timer;

    int nivelActual;
    double tiempoNivel3;

    Vehiculo *jugador;
    Vehiculo *bot1;
    Vehiculo *bot2;
    Obstaculo *muro_rojo;

    bool juegoTerminado;
    int vueltasJugador;
    int vueltasBot1; //Ideal para cuando se termine de modelar el nivel 1//
    int vueltasBot2;

    QGraphicsRectItem *meta;

    QList<QGraphicsItem*> obstaculosNivel2;
    void verificarColisionesNivel2(Vehiculo *v);

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    void siguienteNivel();

    //Funciones graficas, especicifamente para el nivel 1//
    void verificarLimites(Vehiculo *v, int &vueltas, QString nombre);
    void verificarMeta(Vehiculo *v, int &vueltas);
    void configurarMenu();
    void configurarNivel1();
    void configurarNivel2();
    void configurarNivel3();
    void verificarColisionesNivel1(Vehiculo *v);
};
#endif // MAINWINDOW_H
