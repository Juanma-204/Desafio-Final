#include "obstaculo.h"

Obstaculo::Obstaculo(double pos_x, double centro_y, double amp, double freq) {
    x_pos = pos_x;
    centroY = centro_y;
    amplitud = amp;
    frecuencia = freq;

    //Se le setea una posicio inicial//
    setPosicion(x_pos, centroY);
}

void Obstaculo::actualizarMovimientoOscilatorio(double tiempoTotal) {
    double nuevaY = centroY + (amplitud * std::sin(frecuencia * tiempoTotal));

    setPosicion(x_pos, nuevaY);
}

void Obstaculo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red); // Los obstaulos son rojos tal cual como lo hice en mi laboratorio//
    //En este aprtado se dibuja un piston para el nivel 3//
    painter->drawRect(0, 0, 30, 80);
}

QRectF Obstaculo::boundingRect() const
{
    return QRectF(0, 0, 30, 80);
}
