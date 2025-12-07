#ifndef OBSTACULO_H
#define OBSTACULO_H

#include "objetomovil.h"
#include <cmath>
#include <QPixmap>

class Obstaculo : public ObjetoMovil
{
public:
    //Se usa la variable publica para definir por donde empieza, cuanto se mueve, que tran rapido, o con que frecuencia//
    Obstaculo(double pos_x, double centro_y, double amplitud, double frecuencia);

    //Su movimiento oscilatorio armonico para el nivel 3//
    void actualizarMovimientoOscilatorio(double tiempoTotal);

    QRectF boundingRect() const override;

    void setSprite(const QString &path);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    double centroY;
    double amplitud;
    double frecuencia;
};

#endif // OBSTACULO_H
