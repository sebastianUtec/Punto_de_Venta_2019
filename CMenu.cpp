//
// Created by SEBASTIAN on 6/12/2019.
//

#include "CMenu.h"
void CMenu::comenzar() {
    TipoEntero eleccion;
    do{
        cout<<"1. Agregar productos de un archivo."<<endl; //
        cout<<"2. Agregar productos de una compra de un proveedor."<<endl;//
        cout<<"3. Bucar informacion de un producto."<<endl;//
        cout<<"4. Mandar boleta de compra."<<endl;
        cout<<"5. Cerrar caja.";
        cout<<"6. Mandar lista de productos a un arhivo de texto."<<endl;
        cin>>eleccion;
        if(eleccion == 1){eleccion1();}
        if(eleccion == 2){eleccion2();}
        if(eleccion == 3 ){eleccion3();}
        if(eleccion == 4){eleccion4();}
        if(eleccion == 5){eleccion5();}
        if(eleccion==6){eleccion6();}
    }while(eleccion!=0);
}
void CMenu::eleccion1() {
    string archivo="l";
    MiCajero->agregarproductos_Desde_un_archivo(archivo);
}
void CMenu::eleccion2() {
    string archivo;
    fstream moment;
    do{
        cout<<"Ingrese el nombre del archivo : "<<endl;
        cout<<"ejemplo ( ../(nombre del archivo) )"<<endl;
        cin>>archivo;
        moment.open(archivo);
        if(!moment.is_open()){
            cout<<"Porfavor ingrese el archivo correcto.";
        }
    }while (!moment.is_open());
    cout<<"hola";
    MiCajero->distribuir_productos(archivo);
}
void CMenu::eleccion3() {
    TipoEntero eleccion;
    do{
        cout<<"1. buscar por nombre ."<<endl;
        cout<<"2. buscar por codigo."<<endl;
        cin>>eleccion;
    }while (eleccion<1 ||eleccion>2);
    if(eleccion==1){
        string nombre ;
        do{
            cout<<"Indique el nombre : ";
            cin>>nombre;
            bool vof = MiCajero->busqueda(nombre);
            if(vof){
                break;
            }
            else{
                cout<<"Indique bien el nombre.";
            }
        }while(true);
        MiCajero->mostrar_datos(nombre);
    }
    else{
        string codigo;
        do{
            cout<<"Indique el codigo :";
            cin>>codigo;
            bool vof1= MiCajero->busqueda_codigo(codigo);
            if(vof1){
                break;
            }
            else{
                cout<<"Porfavor indique bien el codigo "<<endl;
            }
        }while(true);
        MiCajero->mostrar_datos_codigo(codigo);
    }
}
void CMenu::eleccion4() {
    string archivo;
    fstream moment;
    do{
        cout<<"Ingrese el nombre del archivo : "<<endl;
        cout<<"ejemplo ( ../(nombre del archivo) )"<<endl;
        cin>>archivo;
        moment.open(archivo);
        if(!moment.is_open()){
            cout<<"Porfavor ingrese el archivo correcto.";
        }
    }while (!moment.is_open());
    MiCajero->mandarboleta(archivo);
}
void CMenu::eleccion5() {
    string archivo;
    fstream moment;
    do{
        cout<<"Ingrese el nombre del archivo : "<<endl;
        cout<<"ejemplo ( ../(nombre del archivo) )"<<endl;
        cin>>archivo;
        moment.open(archivo);
        if(!moment.is_open()){
            cout<<"Porfavor ingrese el archivo correcto.";
        }
    }while (!moment.is_open());
    MiCajero->mandarventafinal_cajacierra(archivo);
}
void CMenu::eleccion6() {
    string archivo;
    fstream moment;
    do{
        cout<<"Ingrese el nombre del archivo : "<<endl;
        cout<<"ejemplo ( ../(nombre del archivo) )"<<endl;
        cin>>archivo;
        moment.open(archivo);
        if(!moment.is_open()){
            cout<<"Porfavor ingrese el archivo correcto.";
        }
    }while (!moment.is_open());
    MiCajero->mandar_total_de_productos(archivo);
}
