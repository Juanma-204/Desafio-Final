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

    //getter para la posicion, teniendo en cuenta el valor de x y y//
    void setPosicion(double x, double y);
    double getX() const { return x_pos; }
    double getY() const { return y_pos; }
    double getVelX() const { return velocidad_x; }

    //setter para cuando se escriban los valores//
    void setVelX(double v) { velocidad_x = v; }
    void setVelY(double v) { velocidad_y = v; }
    void setX(double x) { x_pos = x; } // Necesario para corregir colisión//

protected:
    //variables de la posicion y la velocidad//
    double x_pos;
    double y_pos;
    double velocidad_x;
    double velocidad_y;
};

#endif // OBJETOMOVIL_H
