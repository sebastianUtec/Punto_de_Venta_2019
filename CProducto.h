//
// Created by SEBASTIAN on 6/12/2019.
//

#ifndef MICAJERO_CPRODUCTO_H
#define MICAJERO_CPRODUCTO_H

#include "Variables.h"

class CProducto {
private:
    string Nombre_del_producto;
    string Codigo_del_producto;
    TipoDecimal Costo_del_producto;
    TipoDecimal Precio_Del_producto;
    TipoEntero Cantidad_del_producto;
public:
    CProducto(string nombre , string codigo , TipoDecimal costo , TipoDecimal precio , TipoEntero cantidad);
    CProducto(){}
    //set
    void set_Nombre_del_producto(string Nombre_del_producto);
    void set_Codigo_del_producto(string Codigo_del_producto);
    void set_costo_del_producto(TipoDecimal Costo_del_producto);
    void set_Precio_del_producto(TipoDecimal Precio_Del_producto);
    void set_Cantidad_Del_producto(TipoEntero Cantidad_del_producto);

    //get
    string get_Nombre_del_producto();
    string get_codigo_del_producto();
    TipoDecimal get_costo_del_producto();
    TipoDecimal get_Precio_del_producto();
    TipoEntero get_cantidad_del_producto();

    //acciones.
    void mostrar_en_cajero();
};


#endif //MICAJERO_CPRODUCTO_H
