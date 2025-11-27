#include "objetomovil.h"

ObjetoMovil::ObjetoMovil() {
    x_pos = 0; y_pos = 0;
    velocidad_x = 0; velocidad_y = 0;
}

QRectF ObjetoMovil::boundingRect() const {
    return QRectF(0, 0, 50, 50); // Tamaño del objeto movil, despues con los sprites, y teniendo en cuenta el tamaño que queramos del carro, se cambia//
}

void ObjetoMovil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //De momento se pinta para el objeto movil un cuadro gris, solo para tener de referencia, despues se cambia con los sprites, lo mismo que el tamaño//
    painter->setBrush(Qt::gray);
    painter->drawRect(boundingRect());
}

void ObjetoMovil::setPosicion(double x, double y) {
    x_pos = x;
    y_pos = y;
    setPos(x_pos, y_pos);
}
