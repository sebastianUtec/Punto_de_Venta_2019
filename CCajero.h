//
// Created by SEBASTIAN on 6/12/2019.
//

#ifndef MICAJERO_CCAJERO_H
#define MICAJERO_CCAJERO_H

#include "CProducto.h"

class CCajero {
private:
    vector <CProducto*> Almacen;
    vector <CProducto*> Productos_seleccionados;
    TipoDecimal Suma_total_De_ventas ;
    vector<vector<CProducto*>>totaldeventas;
    const TipoDecimal margen_de_ganancia = 20;//20 porciento;

public:
    CCajero();
    TipoDecimal Suma_de_productos();
    void distribuir_productos(string archivodetexto);
    bool busqueda(string nombre);
    void mostrar_datos(string nombre);
    bool busqueda_codigo(string codigo);
    void mostrar_datos_codigo(string codigo);
    void mandarboleta(string archivo);
    CProducto* datos_boleta(string codigo);
    bool  busqueda_codigo_productos_Seleccionados(string codigo1);
    void eliminar_de_productos_seleccionados(string codigo);
    void mandar_boleta_al_archivo(string archivo);
    void reducir(string codigo);
    void mandarventafinal_cajacierra(string archivo);
    void mandar_total_de_productos(string archivo);
    void agregarproductos_Desde_un_archivo(string archivo);
};


#endif //MICAJERO_CCAJERO_H
