//
// Created by SEBASTIAN on 6/12/2019.
//

#include "CCajero.h"
#include "CProducto.h"
CCajero::CCajero() {
    Suma_total_De_ventas = 0;
}

TipoDecimal CCajero::Suma_de_productos() {
    TipoDecimal suma=0;
    for(TipoEntero i=0 ; i<Productos_seleccionados.size() ; i++){
        suma += Productos_seleccionados[i]->get_Precio_del_producto();
    }
    return suma;
}
void CCajero::distribuir_productos(string archivodetexto) {
    fstream mi_lista(archivodetexto , ios::in);
    while (!mi_lista.fail()){
        string nombre;
        string codigo;
        TipoDecimal costo;
        TipoDecimal precio;
        string precio_bruto;
        string cantidad;
        TipoEntero cantidad_1;
        mi_lista>>nombre>>codigo>>precio_bruto>>cantidad;
        costo = stod(cantidad) / stod(precio_bruto);
        precio = costo + costo*margen_de_ganancia/100;
        cantidad_1 = stoi(cantidad);
        CProducto* productoenviado = new CProducto(nombre , codigo , costo , precio , cantidad_1);
        Almacen.push_back(productoenviado);
    }
}
bool CCajero::busqueda(string nombre) {
    for(TipoEntero i=0 ;i<Almacen.size();i++){
        if(nombre == Almacen[i]->get_Nombre_del_producto()){
            return true;
        }
    }
    return false;
}
void CCajero::mostrar_datos(string nombre) {
    TipoEntero posicion;
    for(TipoEntero i=0 ; i<Almacen.size();i++){
        if(Almacen[i]->get_Nombre_del_producto() == nombre){
            posicion=i;
        }
    }
    Almacen[posicion]->mostrar_en_cajero();
}

bool CCajero::busqueda_codigo(string codigo) {
    for(TipoEntero i=0 ;i<Almacen.size();i++){
        if(codigo == Almacen[i]->get_codigo_del_producto()){
            return true;
        }
    }
    return false;
}
void CCajero::mostrar_datos_codigo(string codigo) {
    TipoEntero posicion1;
    for(TipoEntero i=0 ;i<Almacen.size();i++){
        if(codigo==Almacen[i]->get_codigo_del_producto()){
            posicion1 = i;
        }
    }
    Almacen[posicion1]->mostrar_en_cajero();
}
CProducto* CCajero::datos_boleta(string codigo) {
    TipoEntero posicion;
    for(TipoEntero i=0 ;i<Almacen.size();i++){
        if(Almacen[i]->get_codigo_del_producto()==codigo){
            posicion=i;
        }
    }
    return Almacen[posicion];
}

void CCajero::eliminar_de_productos_seleccionados(string codigo) {
    TipoEntero posicion;
    for(TipoEntero i=0 ; i<Productos_seleccionados.size();i++){
        if(Productos_seleccionados[i]->get_codigo_del_producto()==codigo){
            posicion = i;
        }
    }
    Productos_seleccionados.erase(begin(Productos_seleccionados)+posicion);
}
bool CCajero::busqueda_codigo_productos_Seleccionados(string codigo1) {
    for(TipoEntero i=0 ; i<Productos_seleccionados.size();i++){
        if(Productos_seleccionados[i]->get_codigo_del_producto()==codigo1){
            return true;
        }
    }
    return false;
}
void CCajero::reducir(string codigo) {
    TipoEntero posicion;
    for(TipoEntero i=0 ;i<Almacen.size();i++){
        if(Almacen[i]->get_codigo_del_producto()==codigo){
            posicion=i;
        }
    }
    Almacen[posicion]->set_Cantidad_Del_producto(Almacen[posicion]->get_cantidad_del_producto()-1);
}
void CCajero::mandar_boleta_al_archivo(string archivo) {
    fstream mandar_boleta(archivo , ios::out);
    mandar_boleta<<"Nombre"<<"\t\t"<<"Precio";
    mandar_boleta<<endl;
    TipoDecimal total=0;
    for(TipoEntero i=0;i<Productos_seleccionados.size();i++){
        mandar_boleta<<Productos_seleccionados[i]->get_Nombre_del_producto();
        mandar_boleta<<"\t\t";
        mandar_boleta<<Productos_seleccionados[i]->get_Precio_del_producto();
        mandar_boleta<<endl;
        total+=Productos_seleccionados[i]->get_Precio_del_producto();
        reducir(Productos_seleccionados[i]->get_codigo_del_producto());
    }
    mandar_boleta<<"Precio Total a pagar : \t\t"<<total;
    Suma_total_De_ventas+=total;
    totaldeventas.push_back(Productos_seleccionados);
    Productos_seleccionados.clear();
}

void CCajero::mandarboleta(string archivo) {
    TipoEntero eleccion;
    while(true){
        cout<<"1. Agregar productos."<<endl;
        cout<<"2. Eliminar productos."<<endl;
        cout<<"3. Cerrar boleta.";
        cin>>eleccion;
        if(eleccion==1){
            string codigo1;
            bool vof;
            do{
                cout<<"Indique el codigo del producto : ";
                cin>>codigo1;
                vof = busqueda_codigo(codigo1);
            }while (!vof);
            Productos_seleccionados.push_back(datos_boleta(codigo1));
        }
        if(eleccion==2){
            string codigo1;
            bool vof;
            do{
                cout<<"Indique el codigo del producto : ";
                cin>>codigo1;
                vof = busqueda_codigo_productos_Seleccionados(codigo1);
                if(!vof){
                    cout<<"Indique bien el codigo porfavor.";
                }
            }while (!vof);
            eliminar_de_productos_seleccionados(codigo1);
        }
        if(eleccion==3){
            break;
        }
    }
    mandar_boleta_al_archivo(archivo);
}
void CCajero::mandarventafinal_cajacierra(string archivo) {
    fstream archivonuevo(archivo , ios::out);
    archivonuevo<<"Nombre\t\t"<<"Precio"<<endl;
    for(TipoEntero i=0 ;i< totaldeventas.size();i++){
        for(TipoEntero j=0 ;j<totaldeventas[i].size();j++){
            archivonuevo<<totaldeventas[i][j]->get_Nombre_del_producto();
            archivonuevo<<"\t\t";
            archivonuevo<<totaldeventas[i][j]->get_Precio_del_producto();
            archivonuevo<<endl;
        }
    }
    archivonuevo<<"precio final del dia : \t\t"<<Suma_total_De_ventas;
}
void CCajero::mandar_total_de_productos(string archivo) {
    fstream archivo_de_productos_actuales(archivo , ios::out);
    archivo_de_productos_actuales<<"Nombre del producto \tCodigo del producto\tPrecio del producto\tCosto del Producto\tCantidad del producto"<<endl;
    for(TipoEntero i=0;i<Almacen.size();i++){
        archivo_de_productos_actuales<<Almacen[i]->get_Nombre_del_producto()<<"\t\t\t\t\t\t";
        archivo_de_productos_actuales<<Almacen[i]->get_codigo_del_producto()<<"\t\t\t\t\t\t";
        archivo_de_productos_actuales<<Almacen[i]->get_Precio_del_producto()<<"\t\t\t\t\t\t";
        archivo_de_productos_actuales<<Almacen[i]->get_costo_del_producto()<<"\t\t\t\t\t\t";
        archivo_de_productos_actuales<<Almacen[i]->get_cantidad_del_producto()<<"\t\t\t\t\t\t";
        archivo_de_productos_actuales<<endl;
    }
}

void CCajero::agregarproductos_Desde_un_archivo(string archivo) {
    vector<vector<string>>productos;
    ifstream archivoabierto;
    archivoabierto.open("../texto.txt",ios::in);
    string Nombre;
    string codigo;
    string Precio;
    string costo;
    string cantidad;
    TipoDecimal precio_1 , costo_1;
    TipoEntero cantidad_1;
    if(Almacen.size()<=0){
        string Nombre;
        string codigo;
        string Precio;
        string costo;
        string cantidad;
        TipoDecimal precio_1, costo_1;
        TipoEntero cantidad_1;
        archivoabierto>>Nombre;
        while(!archivoabierto.fail()) {
            archivoabierto >>codigo >> Precio >> costo >> cantidad;
            precio_1 = stod(Precio);
            cantidad_1 = stoi(cantidad);
            costo_1 = stod(costo);
            CProducto *productoss = new CProducto(Nombre, codigo, costo_1, precio_1, cantidad_1);
            archivoabierto>>Nombre;
            Almacen.push_back(productoss);
            cout<<"si"<<endl;
        }
     }
    else{
        while(!archivoabierto.fail()){
            string nombre;
            string Nombre;
            string codigo;
            string Precio;
            string costo;
            string cantidad;
            TipoDecimal precio_1 , costo_1;
            TipoEntero cantidad_1;
            archivoabierto>>Nombre>>codigo>>Precio>>costo>>cantidad;
            precio_1 = stod(Precio);
            cantidad_1=stoi(cantidad);
            costo_1=stod(costo);
            bool verifica = busqueda_codigo(codigo);
            if(!verifica){
                CProducto* productoss= new CProducto(Nombre, codigo , precio_1 , costo_1 , cantidad_1);
                Almacen.push_back(productoss);
            }
        }
    }
}
