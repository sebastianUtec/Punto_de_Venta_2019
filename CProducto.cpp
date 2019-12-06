//
// Created by SEBASTIAN on 6/12/2019.
//

#include "CProducto.h"
//constructor
CProducto::CProducto(string nombre, string codigo, TipoDecimal costo, TipoDecimal precio, TipoEntero cantidad){
    this->Nombre_del_producto=nombre;
    this->Codigo_del_producto=codigo;
    this->Costo_del_producto=costo;
    this->Precio_Del_producto=precio;
    this->Cantidad_del_producto=cantidad;
}

//Nombramos a los setters
void CProducto::set_Nombre_del_producto(string Nombre_del_producto) {
    this->Nombre_del_producto = Nombre_del_producto;
}

void CProducto::set_Codigo_del_producto(string Codigo_del_producto) {
    this->Codigo_del_producto = Codigo_del_producto;
}

void CProducto::set_costo_del_producto(TipoDecimal Costo_del_producto) {
    this->Costo_del_producto = Costo_del_producto;
}

void CProducto::set_Precio_del_producto(TipoDecimal Precio_Del_producto) {
    this->Precio_Del_producto = Precio_Del_producto;
}

void CProducto::set_Cantidad_Del_producto(TipoEntero Cantidad_del_producto) {
    this->Cantidad_del_producto = Cantidad_del_producto;
}

//Nombramos a los getters

string CProducto::get_Nombre_del_producto() {
    return this->Nombre_del_producto;
}

string CProducto::get_codigo_del_producto() {
    return this->Codigo_del_producto;
}

TipoDecimal CProducto::get_costo_del_producto() {
    return this->Costo_del_producto;
}

TipoDecimal CProducto::get_Precio_del_producto() {
    return this->Precio_Del_producto;
}

TipoEntero CProducto::get_cantidad_del_producto() {
    return this->Cantidad_del_producto;
}

//Nombramos a las acciones
void CProducto::mostrar_en_cajero() {
    cout<<"Nombre del producto : "<<endl<<get_Nombre_del_producto()<<endl;
    cout<<"Precio del producto : "<<endl<<get_Precio_del_producto()<<endl;
}