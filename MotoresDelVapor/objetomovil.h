#ifndef OBJETOMOVIL_H
#define OBJETOMOVIL_H

#include <QGraphicsItem> //Se usa para pintar o hacer por decirlo asi que el objeto exista, en este caso ya sea le vehiculo o obstaculo//
#include <QPainter>

class ObjetoMovil : public QGraphicsItem
{
public:
    ObjetoMovil();

    //Estos son los metodos obligatorios, para que le obejto exista por decirlo asi, aparte delimitan un rectangulo apra que el objeto pueda andar por ahi//
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    //getter y setter para la posicion, teniendo en cuenta el valor de x y y//
    void setPosicion(double x, double y);

protected:
    //variables de la posicion y la velocidad//
    double x_pos;
    double y_pos;
    double velocidad_x;
    double velocidad_y;
};

#endif // OBJETOMOVIL_H
