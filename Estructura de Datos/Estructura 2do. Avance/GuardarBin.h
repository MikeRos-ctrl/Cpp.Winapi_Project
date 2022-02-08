#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include "Estructuras.h"

void Guardar_Mecanicos_Bin(Mecanicos*);
void Guardar_Clientes_Bin(Clientes*);
void Guardar_Paquetes_Bin(Paquetes_Servicio*);
void Guardar_Users_Bin(User*);
void Guardar_Citas_Bin(Citas*);
void Guardar_Global_Id();
fstream Mecanicosbin;
fstream Usuariosbin;
fstream Paquetesbin;
fstream Clientesbin;
fstream Citasbin;
fstream Globals_Ids;
fstream txtfile;
fstream txtfile1;

int GLOBAL_USER_ID = 1;
int Global_Mecanicos_Id = 1;
int GLOBAL_PACKS_ID = 1;
int GLOBAL_CLIENTES_ID = 1;
int GLOBAL_Citas_ID = 1;

void Guardar_Citas_Bin(Citas* New_Cita) {

    Citasbin.open("Datos\\Citas.bin", ios::binary | ios::out | ios::trunc);

    if (Citasbin.is_open()) {

        while (New_Cita != NULL) {

            Citasbin.write(reinterpret_cast<char*>(New_Cita), sizeof(Citas));
            New_Cita = New_Cita->Citasnext;
        }
        Citasbin.close();
        return;
    }
    else {
        MessageBoxA(NULL, "No se pudo abrir el archivo de clientes", "NO GUARDAR USUARIO", MB_ICONERROR);
        return;
    }
}

void Guardar_Clientes_Bin(Clientes* New_Cliente) {

    Clientesbin.open("Datos\\Clientes.bin", ios::binary | ios::out | ios::trunc);

    if (Clientesbin.is_open()) {

        while (New_Cliente != NULL) {

            Clientesbin.write(reinterpret_cast<char*>(New_Cliente), sizeof(Clientes));
            New_Cliente = New_Cliente->Cnext;
        }
        Clientesbin.close();
        return;
    }
    else {
        MessageBoxA(NULL, "No se pudo abrir el archivo de clientes", "NO GUARDAR USUARIO", MB_ICONERROR);
        return;
    }
}

void Guardar_Paquetes_Bin(Paquetes_Servicio* New_Paquete) {

    Paquetesbin.open("Datos\\Paquetes.bin", ios::binary | ios::out | ios::trunc);

    if (Paquetesbin.is_open()) {

        while (New_Paquete != NULL) {

            Paquetesbin.write(reinterpret_cast<char*>(New_Paquete), sizeof(Paquetes_Servicio));
            New_Paquete = New_Paquete->Pnext;
        }
        Paquetesbin.close();
        return;
    }
    else {
        MessageBoxA(NULL, "No se pudo abrir el archivo de usuario", "NO GUARDAR USUARIO", MB_ICONERROR);
        return;
    }
}

void Guardar_Mecanicos_Bin(Mecanicos* New_Mecanico) {

    Mecanicosbin.open("Datos\\Mecanicos.bin", ios::binary | ios::out | ios::trunc);

    if (Mecanicosbin.is_open()) {

        while (New_Mecanico != NULL) {

            Mecanicosbin.write(reinterpret_cast<char*>(New_Mecanico), sizeof(Mecanicos));
            New_Mecanico = New_Mecanico->Mnext;
        }
        Mecanicosbin.close();
        return;
    }
    else {
        MessageBoxA(NULL, "No se pudo abrir el archivo de usuario", "NO GUARDAR USUARIO", MB_ICONERROR);
        return;
    }
}

void Guardar_Users_Bin(User* Nuevo_Usuario) {

    Usuariosbin.open("Datos\\Usuarios.bin", ios::binary | ios::out | ios::trunc);

    if (Usuariosbin.is_open()) {

        while (Nuevo_Usuario != NULL) {

            Usuariosbin.write(reinterpret_cast<char*>(Nuevo_Usuario), sizeof(User));
            Nuevo_Usuario = Nuevo_Usuario->next;
        }
        Usuariosbin.close();
        return;
    }
    else {
        MessageBoxA(NULL, "Error con .bin Usuarios", "NO GUARDAR USUARIO", MB_ICONERROR);
        return;
    }
}

void Guardar_Global_Id() {
    
    Globals_Ids.open("Datos\\GlobalId.txt", ios::out | ios::trunc);
    if (Globals_Ids.is_open()) {
        Globals_Ids << GLOBAL_USER_ID << endl;
        Globals_Ids << Global_Mecanicos_Id << endl;
        Globals_Ids << GLOBAL_PACKS_ID << endl;
        Globals_Ids << GLOBAL_CLIENTES_ID << endl;
        Globals_Ids << GLOBAL_Citas_ID << endl;
        Globals_Ids.close();
        return;
    }

    else
    {
        MessageBox(NULL, "Error al guardar los Global Id's", "NO GUARDAR ID GLOBAL", MB_ICONERROR);
        return;
    }
}
