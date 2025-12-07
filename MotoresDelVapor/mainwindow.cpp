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

    nivelActual = 1;
    configurarNivel1();

    timer->start(16);
}

void MainWindow::configurarNivel1()
{
    vueltasBot1 = 0;
    vueltasBot2 = 0;
    juegoTerminado = false;
    vueltasJugador = 0;

    //Se define una vista lateral fija o en 2d, en este caso con la dimension o como yo lo llamo, resolucion 1000x600//
    escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 1000, 600);
    ui->graphicsView->setScene(escena);

    //Se crea el vehiculo en la escena y lo ponemos en el piso//
    jugador = new Vehiculo();
    jugador->setColor(Qt::blue, ":/carro1.png");
    escena->addItem(jugador);
    jugador->setPosicion(50, 400);

    //Se crean los bots, y se ponen en las mismas coordenadas del jugador, para que empiecen en igualdad de condiciones//
    bot1 = new Vehiculo();
    bot1->setColor(Qt::red, ":/carrobots.png");
    bot1->setPosicion(50, 400);
    bot1->setFuerzaMotor(140);
    escena->addItem(bot1);

    bot2 = new Vehiculo();
    bot2->setColor(Qt::magenta, ":/carrobots.png");
    bot2->setPosicion(50, 400);
    bot2->setFuerzaMotor(160);
    escena->addItem(bot2);


    //Se dibuja el piso, para que el carro sepa dond delimita//
    /*QGraphicsRectItem *piso = new QGraphicsRectItem(0, 430, 1000, 10);
    piso->setBrush(Qt::darkGreen);
    escena->addItem(piso);*/

    //Se crea el obstaculo o la penalizacion que es el objeto rojo//
    muro_rojo = new Obstaculo(
        400, 350, 0.0,0.0 );
    muro_rojo->setPos(400, 350);
    escena->addItem(muro_rojo);

    //Se dibuja la meta//
    /*meta = new QGraphicsRectItem(0, 0, 10, 600);
    meta->setPos(0, 0);
    escena->addItem(meta);*/

    QPixmap fondo1(":/Nivel1.png");
    escena->setBackgroundBrush(fondo1.scaled(1000, 600));
    ui->graphicsView->setScene(escena);
}


void MainWindow::configurarNivel2(){
    juegoTerminado = false;
    vueltasJugador = 0;
    vueltasBot1= 0;
    vueltasBot2= 0;

    escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 1000, 600);
    ui->graphicsView->setScene(escena);

    //Se inicia la lista que con tiene los obstaculos del nivel 2//
    obstaculosNivel2.clear();

    // Se crea el jugador//
    jugador = new Vehiculo();
    jugador->setColor(Qt::blue, ":/carro2.png");
    escena->addItem(jugador);
    jugador->setPosicion(50, 400);

    //Se crean los bots, y se ponen en las mismas coordenadas del jugador, para que empiecen en igualdad de condiciones//
    bot1 = new Vehiculo();
    bot1->setColor(Qt::red, ":/carrobots.png");
    bot1->setPosicion(50, 400);
    bot1->setFuerzaMotor(140);
    escena->addItem(bot1);

    bot2 = new Vehiculo();
    bot2->setColor(Qt::magenta, ":/carrobots.png");
    bot2->setPosicion(50, 400);
    bot2->setFuerzaMotor(160);
    escena->addItem(bot2);

    //Se hace el piso //
    /*QGraphicsRectItem *piso = new QGraphicsRectItem(0, 430, 1000, 10);
    piso->setBrush(Qt::darkGreen);
    escena->addItem(piso);*/

    /*meta = new QGraphicsRectItem(0, 0, 10, 600);
    meta->setPos(0, 0);
    meta->setBrush(Qt::yellow);
    escena->addItem(meta);*/

    muro_rojo=nullptr;

    Obstaculo *obs1 = new Obstaculo(300, 350, 0, 0);
    escena->addItem(obs1);
    obstaculosNivel2.append(obs1);

    Obstaculo *obs2 = new Obstaculo(550, 350, 0, 0);
    escena->addItem(obs2);
    obstaculosNivel2.append(obs2);

    Obstaculo *obs3 = new Obstaculo(700, 350, 0, 0);
    escena->addItem(obs3);
    obstaculosNivel2.append(obs3);

    QPixmap fondo1(":/Nivel2.png");
    escena->setBackgroundBrush(fondo1.scaled(1000, 600));
    ui->graphicsView->setScene(escena);

}

void MainWindow::configurarNivel3()
{
    juegoTerminado = false;
    vueltasJugador = 0;
    vueltasBot1 = 0;
    vueltasBot2= 0;

    escena = new QGraphicsScene(this);
    escena->setSceneRect(0, 0, 1000, 600);
    ui->graphicsView->setScene(escena);

    jugador = new Vehiculo();
    jugador->setColor(Qt::blue, ":/carro3.png");
    jugador->setPosicion(50, 400);
    escena->addItem(jugador);

    //Se crean los bots, y se ponen en las mismas coordenadas del jugador, para que empiecen en igualdad de condiciones//
    bot1 = new Vehiculo();
    bot1->setColor(Qt::red, ":/carrobots.png");
    bot1->setPosicion(50, 400);
    bot1->setFuerzaMotor(140);
    escena->addItem(bot1);

    bot2 = new Vehiculo();
    bot2->setColor(Qt::magenta, ":/carrobots.png");
    bot2->setPosicion(50, 400);
    bot2->setFuerzaMotor(160);
    escena->addItem(bot2);

    /*QGraphicsRectItem *piso = new QGraphicsRectItem(0, 430, 1000, 10);
    piso->setBrush(Qt::darkGray);
    escena->addItem(piso);*/

    obstaculosNivel2.clear();

    Obstaculo *obs1 = new Obstaculo(250, 250, 100, 1.5);
    escena->addItem(obs1);
    obstaculosNivel2.append(obs1);

    Obstaculo *obs2 = new Obstaculo(450, 300, 50, 4.0);
    escena->addItem(obs2);
    obstaculosNivel2.append(obs2);

    Obstaculo *obs3 = new Obstaculo(650, 200, 150, 2.0);
    escena->addItem(obs3);
    obstaculosNivel2.append(obs3);

    Obstaculo *obs4 = new Obstaculo(850, 300, 50, 4.0);
    escena->addItem(obs4);
    obstaculosNivel2.append(obs4);

    QPixmap fondo1(":/Nivel3.png");
    escena->setBackgroundBrush(fondo1.scaled(1000, 600));
    ui->graphicsView->setScene(escena);
}


void MainWindow::actualizarJuego()
{
    if (juegoTerminado) return;

    if (nivelActual == 1) {
        jugador->actualizarFisicaNivel1();
        verificarColisionesNivel1(jugador);

        //Logica del bot1, es el que nunca para de acelerar, por eso se pone en true la aceleracion//
        if (bot1) {
            bot1->acelerar(true); // Siempre acelera
            bot1->actualizarFisicaNivel1();
            verificarColisionesNivel1(bot1);
        }

        //Logfica del bot2, es que lit es random, el va a acelerar o desacelerar aleatoriamente o random, por eso se usa esa funcion//
        if (bot2) {
            int suerte = rand() % 100;
            if (suerte < 90) bot2->acelerar(true);
            else bot2->acelerar(false);
            bot2->actualizarFisicaNivel1();
            verificarColisionesNivel1(bot2);
        }

    }
    else if (nivelActual == 2) {
        jugador->actualizarFisicaNivel2();
        verificarColisionesNivel2(jugador);

        if (bot1) {
            bot1->acelerar(true);
            int salto = rand() % 100;
            if (salto < 5) bot1->saltar();

            bot1->actualizarFisicaNivel2();
            verificarColisionesNivel2(bot1);
        }

        if (bot2) {
            bot2->acelerar(true);
            int salto = rand() % 100;
            if (salto < 10) bot2->saltar();

            bot2->actualizarFisicaNivel2();
            verificarColisionesNivel2(bot2);
        }
    }
    else if (nivelActual == 3) {
        jugador->actualizarFisicaNivel2();
        verificarColisionesNivel2(jugador);

        if (bot1) {
            bot1->acelerar(true);
            bot1->actualizarFisicaNivel2();
            verificarColisionesNivel2(bot1);
        }
        if (bot2) {
            bot2->acelerar(true);
            bot2->actualizarFisicaNivel2();
            verificarColisionesNivel2(bot2);
        }

        foreach (QGraphicsItem *item, obstaculosNivel2) {
            Obstaculo *obs = dynamic_cast<Obstaculo*>(item);
            if (obs) {
                obs->actualizarMovimientoOscilatorio(tiempoNivel3);
            }
        }

        tiempoNivel3 += (16.0 / 1000.0);
    }

    verificarLimites(jugador, vueltasJugador, "JUGADOR");

    verificarLimites(jugador, vueltasJugador, "JUGADOR");
    verificarLimites(bot1, vueltasBot1, "BOT ROJO");
    verificarLimites(bot2, vueltasBot2, "BOT MAGENTA");
    }


void MainWindow::verificarColisionesNivel1(Vehiculo *v) {

    const double VELOCIDAD_MAXIMA_SEGURA = 20.0;

    if (v->collidesWithItem(muro_rojo)) {

        double velXActual = v->getVelX();

        if (velXActual > VELOCIDAD_MAXIMA_SEGURA) {

            v->setVelX(velXActual * 0.25);

        } else {

            v->setVelX(velXActual * 0.95);
        }

        v->setPos(v->getX() - 10, v->getY());
    }
}

void MainWindow::verificarColisionesNivel2(Vehiculo *v) {
    if (obstaculosNivel2.isEmpty()) return;

    //double x_previo = jugador->getX();

    foreach (QGraphicsItem *obs, obstaculosNivel2) {
        if (v->collidesWithItem(obs)) {

            v->setVelX(0);
            v->setVelY(0);

            v->setPosicion(50,400);

            return;
        }
    }
}

void MainWindow::verificarMeta(Vehiculo *v, int &vueltas)
{
    if (juegoTerminado) return;
}

void MainWindow::verificarLimites(Vehiculo *v, int &vueltas, QString nombre)
{
    double anchoEscena = 1000;

    //Se veirifican los limites externos izquierdo//
    if (v->getX() < 0) {
        v->setPosicion(0, v->getY());
        v->setVelX(0);
    }

    //Se verifican los limites externos derechos//
    if (v->getX() > anchoEscena - v->boundingRect().width()) {

        vueltas++;

        // 2. Verificar si alguien ganó
        if (vueltas >= 5) {
            juegoTerminado = true;

            if (nombre == "JUGADOR") {
                siguienteNivel();
            } else {
                qDebug() << "Ustewd perdio, gano el bot" << nombre;
            }
            return;
        }
        //Se le reinicia la posicion//
        v->setPosicion(5, v->getY());

         //Se le aplica la penalizacionh de 25% por el obstaculo //
        v->setVelX(v->getVelX() * 0.75);
    }
}


void MainWindow::siguienteNivel()
{
    timer->stop();

    if (nivelActual == 1) {
        nivelActual = 2;
        configurarNivel2();
    }
    else if (nivelActual == 2) {
        nivelActual = 3;
        tiempoNivel3 = 0;
        configurarNivel3();
    }
    else if (nivelActual == 3) {
        juegoTerminado = true;
        // Aquí podrías mostrar un GraphicsTextItem que diga "GANASTE"
        return;
    }

    timer->start(16);
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

    //Se usa mayoritariamente para el nivel 2, y consiste en saltar para esquivar os obstaculos//
    if(event->key() == Qt::Key_Space) {
        jugador->saltar();
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_D || event->key() == Qt::Key_A) {
        jugador->setFuerzaMotor(-200);
        jugador->acelerar(false);
    }
}
