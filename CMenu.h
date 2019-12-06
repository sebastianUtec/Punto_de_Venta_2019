//
// Created by SEBASTIAN on 6/12/2019.
//

#ifndef MICAJERO_CMENU_H
#define MICAJERO_CMENU_H

#include "CCajero.h"
#include "CProducto.h"
class CMenu {
private:
    CCajero *MiCajero=new CCajero;
public:
    void comenzar();
    void eleccion1();
    void eleccion2();
    void eleccion3();
    void eleccion4();
    void eleccion5();
    void eleccion6();

};


#endif //MICAJERO_CMENU_H
