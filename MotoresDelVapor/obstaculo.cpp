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
    if (!obstaculoSprite.isNull()) {
        painter->drawPixmap(0, 0, 40, 60, obstaculoSprite);

    } else {
        painter->setBrush(Qt::red);
        painter->drawRect(0, 0, 30, 80);
    }
}

void Obstaculo::setSprite(const QString &path) {
    if (!obstaculoSprite.load(path)) {
    }
}

QRectF Obstaculo::boundingRect() const
{
    return QRectF(0, 0, 30, 80);
}
