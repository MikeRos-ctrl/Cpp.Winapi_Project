#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<string>
#include<commdlg.h>
using namespace std;

struct Citas {

    char Nombre_Cliente_Cita[MAX_PATH];
    char Nombre_Mecanico_Cita[MAX_PATH];
    char Tipo_Servicio_Cita[MAX_PATH];
    string fecha;
    string hora;
    int idCitas = 0;
    Citas* Citasnext;
    Citas* Citasprev;
};
Citas* Citasnodoinicial = NULL;
Citas* Citasnodoactual = NULL;
Citas* Citaseditar = NULL;

struct Clientes {

    char Nombre_Cliente[MAX_PATH];
    char Placas_Cliente[MAX_PATH];
    char Marca_Carro_Cliente[MAX_PATH];
    char Modelo_Carro_Cliente[MAX_PATH];
    int  Year_Carro_Cliente = 0;
    char  Kilometraje_Carro[MAX_PATH];
    int  idClientes = 0;
    char Telefono_Cliente[MAX_PATH];
    char Direccion_Cliente[MAX_PATH];
    Clientes* Cnext;
    Clientes* Cprev;
};
Clientes* Cnodoinicial = NULL;
Clientes* Cnodoactual = NULL;
Clientes* Ceditar = NULL;

struct Mecanicos {
    
    char Nombre_Completo_Empleado[MAX_PATH];
    char Foto_Mecanicos[MAX_PATH];
    char Num_Celular_Mecanicos [MAX_PATH];
    char Especialidad_Mecanicos[MAX_PATH];
    unsigned int idMecanicos = 0;
    char Turno_Trabajo[MAX_PATH];
    bool dia_lunes = false;
    bool dia_martes = false;
    bool dia_miercoles = false;
    bool dia_jueves = false;
    bool dia_viernes = false;
    bool dia_sabado = false;
    bool dia_domingo = false;
    Mecanicos* Mnext;
    Mecanicos* Mprev;
};
Mecanicos* Mnodoinicial = NULL;
Mecanicos* Mnodoactual = NULL;
Mecanicos* Meditar = NULL;

struct User {
    
    char New_username[MAX_PATH];
    char New_password[MAX_PATH];
    char New_Full_Name[MAX_PATH];
    unsigned int idUser = 0;
    User* next;
    User* prev;
};
User* nodoinicial = NULL;
User* nodoactual = NULL;

struct Paquetes_Servicio {

    char New_clave[MAX_PATH];
    char New_descripccion[MAX_PATH];
    unsigned int idPaquete = 0;
    char New_cost [MAX_PATH];
    Paquetes_Servicio* Pnext;
    Paquetes_Servicio* Pprev;
};
Paquetes_Servicio* Pnodoinicial = NULL;
Paquetes_Servicio* Pnodoactual = NULL;