#ifndef VEHICULO_H
#define VEHICULO_H

#include "objetomovil.h"
#include <cmath>
#include <QColor>
#include <QPixmap>

class Vehiculo : public ObjetoMovil
{
public:
    Vehiculo();

    //metodos para controlar el carro, tenienod en cuenta que se puede mover con teclas, el uno con la tecla, y el otro el espacio//
    void acelerar(bool activado);
    void saltar();

    //Metodos diferentes para actualizar las fisicas, depende el nivel obvio//
    void actualizarFisicaNivel1(); //Movimiento Lineal Acelerado

    void actualizarFisicaNivel2(); //Movimiento Parablico

    // Para dibujar diferente al carro dependiendo del nivel//
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setColor (QColor nuevoColor);
    void setColor(QColor color, QString skinPath);

    void setFuerzaMotor(double fuerza) { fuerzaMotor = fuerza; }

private:
    // las fisicas para los niveles//
    double masa;            //para la inercia
    double fuerzaMotor;     //para la potencia aplicada
    double friccion;        //para el freno natural del suelo
    bool motorEncendido;    //el estado de la tecla

    QColor colorCarro;
    QPixmap carroSprite;

    //Y las variables de los parametros a la hora de saltar//
    double gravedad;
    bool enElAire;
};

#endif // VEHICULO_H
