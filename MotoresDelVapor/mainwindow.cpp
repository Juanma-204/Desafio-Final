#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehiculo.h"
#include "obstaculo.h"


//Destructor para el manejo de memoria//
MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Esto lo encontre en internet, es para desactivar las barras laterales o el scroll por decirlo asi//
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::actualizarJuego);

    //SE empieza la configuracion para el primer nivel//
    configurarNivel1();

    timer->start(16);
}

void MainWindow::configurarNivel1()
{
    juegoTerminado = false;
    vueltasJugador = 0;

    //Se define una vista lateral fija o en 2d, en este caso con la dimension o como yo lo llamo, resolucion 1000x600//
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 1000, 600);
    ui->graphicsView->setScene(escena);

    //Se crea el vehiculo en la escena y lo ponemos en el piso//
    jugador = new Vehiculo();
    escena->addItem(jugador);
    jugador->setPosicion(50, 400);

    //Se dibuja el piso, para que el carro sepa dond delimita//
    QGraphicsRectItem *piso = new QGraphicsRectItem(0, 430, 1000, 10);
    piso->setBrush(Qt::darkGreen);
    escena->addItem(piso);

    //Se crea el obstaculo o la penalizacion que es el objeto rojo//
    muro_rojo = new Obstaculo(
        400, 350, 0.0,0.0 );
    muro_rojo->setPos(400, 350);
    escena->addItem(muro_rojo);

    //Se dibuja la meta//
    meta = new QGraphicsRectItem(0, 0, 10, 600);
    meta->setPos(0, 0);
    escena->addItem(meta);
}


void MainWindow::actualizarJuego()
{
    if (juegoTerminado) return;

    verificarLimites(jugador);

    verificarMeta(jugador, vueltasJugador);

    jugador->actualizarFisicaNivel1();

    verificarColisionesNivel1();
}


void MainWindow::verificarColisionesNivel1() {

    const double VELOCIDAD_MAXIMA_SEGURA = 20.0;

    if (jugador->collidesWithItem(muro_rojo)) {

        double velXActual = jugador->getVelX();

        if (velXActual > VELOCIDAD_MAXIMA_SEGURA) {

            jugador->setVelX(velXActual * 0.25);

        } else {

            jugador->setVelX(velXActual * 0.95);
        }

        jugador->setPos(jugador->getX() - 10, jugador->getY());
    }
}

void MainWindow::verificarMeta(Vehiculo *v, int &vueltas)
{
    if (juegoTerminado) return;

    if (v->collidesWithItem(meta)) {

        if (v->getVelX() > 0.1) {

            vueltas++;

            if (vueltas >= 5) {
                juegoTerminado = true;
            }
        }
    }
}

void MainWindow::verificarLimites(Vehiculo *v)
{
    double anchoEscena = 1000;

    //Se veirifican los limites externos, ya sea derecho o izquierdo//
    if (v->getX() < 0) {
        v->setPosicion(0, v->getY());
        v->setVelX(0);
    }

    if (v->getX() > anchoEscena - v->boundingRect().width()) {

        v->setPosicion(5, v->getY());
         //Se le aplica la penalizacionh de 25% por el obstaculo //
        v->setVelX(v->getVelX() * 0.75);
    }
}

//COnrtoles para el vehiculo//
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //Se acelera con D, aunque principalmente se tenia pensado con W, con D queda bien//
    if(event->key() == Qt::Key_D) {
        jugador->setFuerzaMotor(200);
        jugador->acelerar(true);
    }
    //Se frena o se le mete reveresa o cambio a atras con la A, reemplazando la S//
    if(event->key() == Qt::Key_A) {
        jugador->setFuerzaMotor(-300);
        jugador->acelerar(true);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_A) {
        jugador->setFuerzaMotor(-200);
        jugador->acelerar(false);
    }
}
