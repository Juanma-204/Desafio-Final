#include "vehiculo.h"
#include <QDebug>

Vehiculo::Vehiculo() {
    masa = 50.0;
    fuerzaMotor = 150.0;
    friccion = 0.08;
    motorEncendido = false;

    colorCarro =Qt::blue;

    gravedad = 9.8;
    enElAire = false;
}

void Vehiculo::acelerar(bool activado) {
    motorEncendido = activado;
}

void Vehiculo::saltar() {
    if (!enElAire) {
        velocidad_y = -60;
        enElAire = true;
    }
}

//Fisica de aceleracion y inceria para el vehiculo o jugador, como sea//
void Vehiculo::actualizarFisicaNivel1() {
    double fuerzaActual = 0;
    if (motorEncendido) {
        fuerzaActual = fuerzaMotor;
    }

    //friccion//
    double fuerzaRozamiento = velocidad_x * friccion;

    double fuerzaNeta = fuerzaActual - fuerzaRozamiento;
    double aceleracion = fuerzaNeta / masa;

    double dt = 0.1;
    velocidad_x += aceleracion * dt;
    x_pos += velocidad_x * dt;

    setPosicion(x_pos, y_pos);
}

//Fisica para el movimiento parabolico, un poco mas facil
void Vehiculo::actualizarFisicaNivel2() {
    double dt = 0.1;
    double friccionMotor = 20.0;

    double fuerzaHorizontal = motorEncendido ? fuerzaMotor : -friccionMotor;

    if (!motorEncendido && std::abs(velocidad_x) > 0.1) {
        fuerzaHorizontal = (velocidad_x > 0) ? -friccionMotor : friccionMotor;
    } else if (!motorEncendido) {
        fuerzaHorizontal = 0;
        velocidad_x = 0;
    }

    double aceleracionX = fuerzaHorizontal / masa;
    velocidad_x += aceleracionX * dt;
    x_pos += velocidad_x * dt;

    velocidad_y += gravedad * dt;
    y_pos += velocidad_y * dt;

    if (y_pos >= 400) {
        y_pos = 400;
        velocidad_y = 0;
        enElAire = false;
    }

    setPosicion(x_pos, y_pos);
}

void Vehiculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    if (!carroSprite.isNull()) {
        painter->drawPixmap(0, 0, 60, 60, carroSprite);

    } else {
        painter->setBrush(colorCarro);
        painter->drawRect(0, 0, 60, 30);
    }
}

void Vehiculo::setColor(QColor nuevoColor) {
    colorCarro = nuevoColor;
    }

void Vehiculo::setColor(QColor color, QString skinPath) {
    colorCarro = color;
    if (!carroSprite.load(skinPath)) {
        qDebug() << "ERROR: No se pudo cargar el sprite del vehiculo desde:" << skinPath;
    }
}
