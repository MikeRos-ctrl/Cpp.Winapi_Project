#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include "GuardarBin.h"
using namespace std;

void Cargar_Mecanicos_bin();
void Cargar_Global_Id();
void Cargar_Users_Bin();
void Cargar_Paquetes_Bin();
void Cargar_Clientes_Bin();
void Cargar_Citas_Bin();

void Cargar_Citas_Bin() {

    Citasbin.open("Datos\\Citas.bin", ios::in | ios::binary | ios::ate);

    if (Citasbin.is_open()) {

        int numero = Citasbin.tellg();

        for (int i = 0; i < (numero / sizeof(Citas)); i++) {
            if (Citasnodoinicial == NULL) {
                Citas* temp = new Citas;
                Citasnodoinicial = new Citas;
                Citasbin.seekg(i * sizeof(Citas));
                Citasbin.read(reinterpret_cast<char*>(temp), sizeof(Citas)); 
                strcpy_s(Citasnodoinicial->Nombre_Cliente_Cita, temp->Nombre_Cliente_Cita);
                strcpy_s(Citasnodoinicial->Nombre_Mecanico_Cita, temp->Nombre_Mecanico_Cita);
                strcpy_s(Citasnodoinicial->Tipo_Servicio_Cita, temp->Tipo_Servicio_Cita);
                Citasnodoinicial->idCitas = temp->idCitas;
                Citasnodoinicial->fecha.append(temp->fecha);
                Citasnodoinicial->hora.append(temp->hora);
                Citasnodoinicial->Citasprev = NULL;
                Citasnodoinicial->Citasnext = NULL;
                Citasnodoactual = Citasnodoinicial;
                delete reinterpret_cast<char*>(temp);
            }

            else {

                while (Citasnodoactual->Citasnext != NULL)
                    Citasnodoactual = Citasnodoactual->Citasnext;
                Citas* temp = new Citas;
                Citasnodoactual->Citasnext = new Citas;
                Citasbin.seekg(i * sizeof(Citas));
                Citasbin.read(reinterpret_cast<char*>(temp), sizeof(Citas));
                Citasnodoactual->Citasnext->Citasprev = Citasnodoactual;
                Citasnodoactual = Citasnodoactual->Citasnext;
                strcpy_s(Citasnodoactual->Nombre_Cliente_Cita, temp->Nombre_Cliente_Cita);
                strcpy_s(Citasnodoactual->Nombre_Mecanico_Cita, temp->Nombre_Mecanico_Cita);
                strcpy_s(Citasnodoactual->Tipo_Servicio_Cita, temp->Tipo_Servicio_Cita);
                Citasnodoactual->idCitas = temp->idCitas;
                Citasnodoactual->fecha.append(temp->fecha);
                Citasnodoactual->hora.append(temp->hora); 
                Citasnodoactual->Citasnext = NULL;
                Citasnodoactual = Citasnodoinicial;
                delete reinterpret_cast<char*>(temp);
            }
        }
        Citasbin.close();
    }
}

void Cargar_Clientes_Bin() {

      Clientesbin.open("Datos\\Clientes.bin", ios::in | ios::binary | ios::ate);

    if (Clientesbin.is_open()) {

        int numero = Clientesbin.tellg();

        for (int i = 0; i < (numero / sizeof(Clientes)); i++) {
            if (Cnodoinicial == NULL) {
                Clientes* temp = new Clientes;
                Cnodoinicial = new Clientes;
                Clientesbin.seekg(i * sizeof(Clientes));
                Clientesbin.read(reinterpret_cast<char*>(temp), sizeof(Clientes));  
                strcpy_s(Cnodoinicial->Nombre_Cliente, temp->Nombre_Cliente);
                strcpy_s(Cnodoinicial->Placas_Cliente, temp->Placas_Cliente);
                strcpy_s(Cnodoinicial->Marca_Carro_Cliente, temp->Marca_Carro_Cliente);
                Cnodoinicial->Year_Carro_Cliente = temp->Year_Carro_Cliente;              
                strcpy_s(Cnodoinicial->Kilometraje_Carro, temp->Kilometraje_Carro);   
                strcpy_s(Cnodoinicial->Telefono_Cliente, temp->Telefono_Cliente);
                strcpy_s(Cnodoinicial->Direccion_Cliente, temp->Direccion_Cliente);
                strcpy_s(Cnodoinicial->Modelo_Carro_Cliente, temp->Modelo_Carro_Cliente);
                Cnodoinicial->idClientes = temp->idClientes;
                Cnodoinicial->Cprev = NULL;
                Cnodoinicial->Cnext = NULL;
                Cnodoactual = Cnodoinicial;
                delete reinterpret_cast<char*>(temp);
            }

            else {

                while (Cnodoactual->Cnext != NULL)
                    Cnodoactual = Cnodoactual->Cnext;
                Clientes* temp = new Clientes;
                Cnodoactual->Cnext = new Clientes;
                Clientesbin.seekg(i * sizeof(Clientes));
                Clientesbin.read(reinterpret_cast<char*>(temp), sizeof(Clientes));
                Cnodoactual->Cnext->Cprev = Cnodoactual;
                Cnodoactual = Cnodoactual->Cnext;
                strcpy_s(Cnodoactual->Nombre_Cliente, temp->Nombre_Cliente);
                strcpy_s(Cnodoactual->Placas_Cliente, temp->Placas_Cliente);
                strcpy_s(Cnodoactual->Modelo_Carro_Cliente, temp->Modelo_Carro_Cliente);
                Cnodoactual->Year_Carro_Cliente = temp->Year_Carro_Cliente;
                strcpy_s(Cnodoactual->Kilometraje_Carro, temp->Kilometraje_Carro);
                strcpy_s(Cnodoactual->Telefono_Cliente, temp->Telefono_Cliente);
                strcpy_s(Cnodoactual->Direccion_Cliente, temp->Direccion_Cliente);
                strcpy_s(Cnodoactual->Marca_Carro_Cliente, temp->Marca_Carro_Cliente);
                Cnodoactual->idClientes = temp->idClientes;
                Cnodoactual->Cnext = NULL;
                Cnodoactual = Cnodoinicial;
                delete reinterpret_cast<char*>(temp);
            }
        }
        Clientesbin.close();
    }
}

void Cargar_Paquetes_Bin() {

    Paquetesbin.open("Datos\\Paquetes.bin", ios::in | ios::binary | ios::ate);

    if (Paquetesbin.is_open()) {

        int numero = Paquetesbin.tellg();

        for (int i = 0; i < (numero / sizeof(Paquetes_Servicio)); i++) {
            if (Pnodoinicial == NULL) {
                Paquetes_Servicio* temp = new Paquetes_Servicio;
                Pnodoinicial = new Paquetes_Servicio;
                Paquetesbin.seekg(i * sizeof(Paquetes_Servicio));
                Paquetesbin.read(reinterpret_cast<char*>(temp), sizeof(Paquetes_Servicio));
                strcpy_s(Pnodoinicial->New_clave, temp->New_clave);
                strcpy_s(Pnodoinicial->New_cost, temp->New_cost);
                strcpy_s(Pnodoinicial->New_descripccion, temp->New_descripccion); 
                Pnodoinicial->idPaquete = temp->idPaquete;
                Pnodoinicial->Pprev = NULL;
                Pnodoinicial->Pnext = NULL;
                Pnodoactual = Pnodoinicial;
                delete reinterpret_cast<char*>(temp);
            }

            else {

                while (Pnodoactual->Pnext != NULL)
                    Pnodoactual = Pnodoactual->Pnext;
                Paquetes_Servicio* temp = new Paquetes_Servicio;
                Pnodoactual->Pnext = new Paquetes_Servicio;
                Paquetesbin.seekg(i * sizeof(Paquetes_Servicio));
                Paquetesbin.read(reinterpret_cast<char*>(temp), sizeof(Paquetes_Servicio));
                Pnodoactual->Pnext->Pprev = Pnodoactual;
                Pnodoactual = Pnodoactual->Pnext;
                Pnodoactual->idPaquete = temp->idPaquete;
                strcpy_s(Pnodoactual->New_clave, temp->New_clave);
                strcpy_s(Pnodoactual->New_cost, temp->New_cost);
                strcpy_s(Pnodoactual->New_descripccion, temp->New_descripccion);
                Pnodoactual->Pnext = NULL;
                Pnodoactual = Pnodoinicial;
                delete reinterpret_cast<char*>(temp);
            }
        }
        Paquetesbin.close();
    }
}

void Cargar_Mecanicos_bin() {

    Mecanicosbin.open("Datos\\Mecanicos.bin", ios::in | ios::binary | ios::ate);

    if (Mecanicosbin.is_open()) {

        int numero = Mecanicosbin.tellg();

        for (int i = 0; i < (numero / sizeof(Mecanicos)); i++) {
            if (Mnodoinicial == NULL) {
                Mecanicos* temp = new Mecanicos;
                Mnodoinicial = new Mecanicos;
                Mecanicosbin.seekg(i * sizeof(Mecanicos));
                Mecanicosbin.read(reinterpret_cast<char*>(temp), sizeof(Mecanicos));
                strcpy(Mnodoinicial->Nombre_Completo_Empleado, temp->Nombre_Completo_Empleado);
                strcpy_s(Mnodoinicial->Turno_Trabajo, temp->Turno_Trabajo);
                strcpy_s(Mnodoinicial->Foto_Mecanicos, temp->Foto_Mecanicos);
                strcpy_s(Mnodoinicial->Num_Celular_Mecanicos, temp->Num_Celular_Mecanicos);
                strcpy_s(Mnodoinicial->Especialidad_Mecanicos, temp->Especialidad_Mecanicos);
                Mnodoinicial->dia_lunes = temp->dia_lunes;
                Mnodoinicial->dia_martes = temp->dia_martes;
                Mnodoinicial->dia_miercoles = temp->dia_miercoles;
                Mnodoinicial->dia_jueves = temp->dia_jueves;
                Mnodoinicial->dia_viernes = temp->dia_viernes;
                Mnodoinicial->dia_sabado = temp->dia_sabado;
                Mnodoinicial->dia_domingo = temp->dia_domingo;
                Mnodoinicial->idMecanicos = temp->idMecanicos;
                Mnodoinicial->Mprev = NULL;
                Mnodoinicial->Mnext = NULL;
                Mnodoactual = Mnodoinicial;
                delete reinterpret_cast<char*>(temp);
            }

            else {

                while (Mnodoactual->Mnext != NULL)
                    Mnodoactual = Mnodoactual->Mnext;
                Mecanicos* temp = new Mecanicos;
                Mnodoactual->Mnext = new Mecanicos;
                Mecanicosbin.seekg(i * sizeof(Mecanicos));
                Mecanicosbin.read(reinterpret_cast<char*>(temp), sizeof(Mecanicos));
                Mnodoactual->Mnext->Mprev = Mnodoactual;
                Mnodoactual = Mnodoactual->Mnext;
                strcpy_s(Mnodoactual->Nombre_Completo_Empleado, temp->Nombre_Completo_Empleado);
                strcpy_s(Mnodoactual->Turno_Trabajo, temp->Turno_Trabajo);
                strcpy_s(Mnodoactual->Foto_Mecanicos, temp->Foto_Mecanicos);
                strcpy_s(Mnodoactual->Num_Celular_Mecanicos, temp->Num_Celular_Mecanicos);
                strcpy_s(Mnodoactual->Especialidad_Mecanicos, temp->Especialidad_Mecanicos);
                Mnodoactual->dia_lunes = temp->dia_lunes;
                Mnodoactual->dia_martes = temp->dia_martes;
                Mnodoactual->dia_miercoles = temp->dia_miercoles;
                Mnodoactual->dia_jueves = temp->dia_jueves;
                Mnodoactual->dia_viernes = temp->dia_viernes;
                Mnodoactual->dia_sabado = temp->dia_sabado;
                Mnodoactual->dia_domingo = temp->dia_domingo;
                Mnodoactual->idMecanicos = temp->idMecanicos;
                Mnodoactual->Mnext = NULL;
                Mnodoactual = Mnodoinicial;
                delete reinterpret_cast<char*>(temp);
            }
        }
        Mecanicosbin.close();
    }
}

void Cargar_Users_Bin() {

    Usuariosbin.open("Datos\\Usuarios.bin", ios::in | ios::binary | ios::ate);

    if (Usuariosbin.is_open()) {

        int numero = Usuariosbin.tellg();

        for (int i = 0; i < (numero / sizeof(User)); i++) {
            if (nodoinicial == NULL) {
                User* temp = new User;
                nodoinicial = new User;
                Usuariosbin.seekg(i * sizeof(User));
                Usuariosbin.read(reinterpret_cast<char*>(temp), sizeof(User));
                strcpy_s(nodoinicial->New_username, temp->New_username);
                strcpy_s(nodoinicial->New_password, temp->New_password);
                strcpy_s(nodoinicial->New_Full_Name, temp->New_Full_Name);
                nodoinicial->idUser = temp->idUser;
                nodoinicial->prev = NULL;
                nodoinicial->next = NULL;
                nodoactual = nodoinicial;
                delete reinterpret_cast<char*>(temp);
            }

            else {

                while (nodoactual->next != NULL)
                    nodoactual = nodoactual->next;
                User* temp = new User;
                nodoactual->next = new User;
                Usuariosbin.seekg(i * sizeof(User));
                Usuariosbin.read(reinterpret_cast<char*>(temp), sizeof(User));
                nodoactual->next->prev = nodoactual;
                nodoactual = nodoactual->next;
                nodoactual->idUser = temp->idUser;
                strcpy_s(nodoactual->New_username, temp->New_username);
                strcpy_s(nodoactual->New_password, temp->New_password);
                strcpy_s(nodoactual->New_Full_Name, temp->New_Full_Name);
                nodoactual->next = NULL;
                nodoactual = nodoinicial;
                delete reinterpret_cast<char*>(temp);
            }
        }
        Usuariosbin.close();
    }
}

void Cargar_Global_Id() {

    Globals_Ids.open("Datos\\GlobalId.txt", ios::in);
    if (Globals_Ids.is_open()) {
        Globals_Ids >> GLOBAL_USER_ID;
        Globals_Ids >> Global_Mecanicos_Id;
        Globals_Ids >> GLOBAL_PACKS_ID;
        Globals_Ids>>GLOBAL_CLIENTES_ID;
        Globals_Ids>> GLOBAL_Citas_ID;
        Globals_Ids.close();
    }
}