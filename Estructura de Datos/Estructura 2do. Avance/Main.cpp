#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>//
#include <fstream>
#include <string.h>
#include <cstring>
#include <string>
#include <time.h>
#include "resource.h"
#include<stdio.h>//
#include <stdlib.h>
#include <cstdlib>//
#include <commdlg.h>//
#include <windowsx.h>//
#include "CargarBin.h"
#include <algorithm>    
#include <vector> 
#include<ctime>

using namespace std;

HINSTANCE Global_Hinstance;
time_t actualTime;
struct tm* TimeInfo;
string ruta;
string ruta_edit;

BOOL CALLBACK Registrar_Mecanicos(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Editar_Mecanicos(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Registrar_Clientes(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Heap_Sort_CBack(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Editar_Clientes(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Registrar_Citas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Menu_General(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Consultar_Citas(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Registrar_Paquetes_Servicio(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK Principal(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Registrarse_Ventana(HWND, UINT, WPARAM, LPARAM);

HWND hRegistrar_Mecanicos;
HWND hRegistrar_Citas;
HWND hConsultar_Citas;
HWND hRegistrar_Clientes;
HWND hEditar_Mecanicos;
HWND hHeap_Ordenamiento;
HWND hEditar_Citas;
HWND hNumEmpleado_Mecanicos;
HWND hNum_Packs_id;
HWND hFullName_Mecanicos;
HWND hTurno_Mecanicos;
HWND hTelefono_Mecanicos;
HWND hEspecialidad_Mecanicos;
HWND hEspecialidad_Citas;
HWND hNueva_Clave;
HWND hNueva_Descripccion;
HWND hNuevo_Costo;
HWND hRegistro_Paquetes_Servicio;
HWND hRegistrarse;
HWND hNuevo_Usuario;
HWND hNueva_Contrasenia;
HWND hNuevo_Nombre;
HWND hPrincipal;
HWND hUsuario;
HWND hContrasenia;
HWND hMostrarDatos;
HWND hMostrarPacks;
HWND hMostrarDatosBefore;
HWND hMostrarCitas;
HWND hMostrarClientes;
HWND hMostrarMecanicos;
HWND hMostrarDatosClientes;
HWND hMenu_General;
HWND hObtener_ListBox;
HWND hFechas;

unsigned int contadorlunes = 0;
unsigned int contadormartes = 0;
unsigned int contadormiercoles = 0;
unsigned int contadorjueves = 0;
unsigned int contadorviernes = 0;
unsigned int contadorsabado = 0;
unsigned int contadordomingo = 0;
unsigned int contador_edit_lunes = 0;
unsigned int contador_edit_martes = 0;
unsigned int contador_edit_miercoles = 0;
unsigned int contador_edit_jueves = 0;
unsigned int contador_edit_viernes = 0;
unsigned int contador_edit_sabado = 0;
unsigned int contador_edit_domingo = 0;

char NombreFull[MAX_PATH] = "";
char Turno[MAX_PATH] = "";
char Especialidad[MAX_PATH] = "";
char Celular[MAX_PATH] = "";
char Nombre_edit_Full[MAX_PATH] = "";
char Turno_Edit[MAX_PATH] = "";
char Especialidad_Edit[MAX_PATH] = "";
char Cita_Especialidad[MAX_PATH] = "";
char Comparacion[MAX_PATH] = "";
char Horario_Lab_Comp[MAX_PATH] = "";
char Celular_edit[MAX_PATH] = "";
char Cita_Nombre_Cliente[MAX_PATH] = "";
char Cita_Nombre_Mecanico[MAX_PATH] = "";
char cliente_Nombre_Completo[MAX_PATH] = "";
char cliente_Placas_Carro[MAX_PATH] = "";
char cliente_Marca_Carro[MAX_PATH] = "";
char cliente_Año_del_Vehiculo[MAX_PATH] = "";
char cliente_km_del_vehicuclo[MAX_PATH] = "";
char cliente_telefono_celular[MAX_PATH] = "";
char cliente_direccion_completa[MAX_PATH] = "";
char cliente_modelo_Carro[MAX_PATH] = "";
char cliente_Nombre_Completo_edit[MAX_PATH] = "";
char cliente_Placas_Carro_edit[MAX_PATH] = "";
char cliente_Marca_Carro_edit[MAX_PATH] = "";
char cliente_Año_del_Vehiculo_edit[MAX_PATH] = "";
char cliente_km_del_vehicuclo_edit[MAX_PATH] = "";
char cliente_telefono_celular_edit[MAX_PATH] = "";
char cliente_direccion_completa_edit[MAX_PATH] = "";
char cliente_modelo_Carro_edit[MAX_PATH] = "";
char user[MAX_PATH] = "";
char pswrd[MAX_PATH] = "";
char fullName[MAX_PATH] = "";
char usuario[MAX_PATH] = "";
char contra[MAX_PATH] = "";
char clave[MAX_PATH] = "";
char descripccion[MAX_PATH] = "";
char Nuevo_cliente_cita_Edit[MAX_PATH] = "";
char Nuevo_mecanico_cita_Edit[MAX_PATH] = "";
char Nuevo_especialidad_cita_Edit[MAX_PATH] = "";
char costo[MAX_PATH] = "";
char sRutaDelArchivoNP[MAX_PATH];
char sRutaDelArchivoNP_Edit[MAX_PATH];

void InsertarMenu(HWND);
float Convertir_String_A_Float(char*);
bool validarQueNoSeRepitanUsuarios(char*);
bool validarEpaciosBlanco(char*);
bool validarQueNoSeEmpalmenMecanicos(char*, char*);
int validarQueNoSeEmpalmenMecanicosEdit(char*, char*, int);
bool editar_eliminar_mecanicos_despues_de_citas(char*);
bool validar_horario_correcto_citas(string);
bool validarQueNoSeRepitaClavePacks(char*);
bool validarQueNoSeEmpalmenMecanicos(string, string);
bool eliminar_paquetes_despues_de_mecanicos(char*);
bool editar_eliminar_clientes_despues_de_citas(char*);
int quick();
void quicksort(int*, int, int);
int partition(int*, int, int);
bool exitWindow = false;
string ObtenerText(HWND);

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd) {

    Cargar_Users_Bin();
    Cargar_Mecanicos_bin();
    Cargar_Global_Id();
    Cargar_Paquetes_Bin();
    Cargar_Clientes_Bin();
    Cargar_Citas_Bin();
    
    //hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
    hPrincipal = CreateDialog(hInst, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
    MSG msg;
    ShowWindow(hPrincipal, SW_SHOW);

    while (GetMessage(&msg, 0, 0, 0)) {

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

BOOL CALLBACK Principal(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {

        case WM_INITDIALOG: {
           
        }break;

        case WM_COMMAND: {

            //if (LOWORD(wParam) == btn_ingresar && HIWORD(wParam) == BN_CLICKED) {

            //    SendDlgItemMessageA(hWnd, edc_usuario, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)usuario);
            //    SendDlgItemMessageA(hWnd, edc_contrasenia, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)contra);

            //    if (nodoinicial == NULL) {
            //        MessageBoxA(hWnd, "Aun No Existen Registros", "ERROR", MB_ICONERROR);
            //    }

            //    else if (strcmp(usuario, "") == 0 || strcmp(contra, "") == 0) {
            //        MessageBoxA(hWnd, "Faltaron Campos Por Llenar", "ERROR", MB_ICONWARNING);
            //    }

            //    else
            //    {
            //        bool NoExiste = true;
            //        while (nodoactual != NULL) {

            //            if (strcmp(nodoactual->New_username,usuario) == 0 && strcmp(nodoactual->New_password, contra) == 0){ 

                            MessageBoxA(hWnd, "Bienvenido Usuario", "Bienvenido", MB_RIGHT);
                            //NoExiste = false;
                            hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                            ShowWindow(hMenu_General, SW_SHOW);
                            DestroyWindow(hWnd);
                            break;

            //            }
            //            nodoactual = nodoactual->next;
            //        }
            //        nodoactual = nodoinicial;

            //        if (NoExiste == true) {

            //            MessageBoxA(hWnd, "VERIFIQUE SU INFORMACION", "USUARIO NO ENCONTRADO", MB_ICONERROR);
            //        }
            //    }
            //}

            //if (LOWORD(wParam) == btn_registrarse && HIWORD(wParam) == BN_CLICKED) {
            //    hRegistrarse = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_Para_Registrarse), NULL, Registrarse_Ventana);
            //    ShowWindow(hRegistrarse, SW_SHOW);
            //    DestroyWindow(hWnd);
            //}

        }break;
    }
    return FALSE;
}

BOOL CALLBACK Menu_General(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lparam) {

    switch (msg) {

        case WM_INITDIALOG: {
           
            InsertarMenu(hWnd);
            Guardar_Mecanicos_Bin(Mnodoactual);
            Guardar_Clientes_Bin(Cnodoactual);
            Guardar_Paquetes_Bin(Pnodoactual);

            hMostrarDatos = GetDlgItem(hWnd, Lista_M);
            if (Mnodoinicial != NULL) {
                int indice = 0;
                while (Mnodoactual != NULL) {
                    string datos;
                    datos.append("Nombre de Mecanico: ");
                    datos.append(Mnodoactual->Nombre_Completo_Empleado);
                    SendMessageA(hMostrarDatos, LB_ADDSTRING, 0, (LPARAM)datos.c_str());
                    SendMessageA(hMostrarDatos, LB_SETITEMDATA, (WPARAM)indice, (LPARAM)Mnodoactual->idMecanicos);
                    indice++;

                    if (Mnodoactual->Mnext == NULL) {
                        break;
                    }
                    Mnodoactual = Mnodoactual->Mnext;
                }

                Mnodoactual = Mnodoinicial;
            }
              
            hMostrarDatosClientes = GetDlgItem(hWnd, Lista_Clientes);
            if (Cnodoinicial != NULL) {
                int indiceC = 0;
                while (Cnodoactual != NULL) {
                    string datosC;
                    datosC.append("Nombre de Clientes: ");
                    datosC.append(Cnodoactual->Nombre_Cliente);
                    SendMessageA(hMostrarDatosClientes, LB_ADDSTRING, 0, (LPARAM)datosC.c_str());
                    SendMessageA(hMostrarDatosClientes, LB_SETITEMDATA, (WPARAM)indiceC, (LPARAM)Cnodoactual->idClientes);
                    indiceC++;

                    if (Cnodoactual->Cnext == NULL) {
                        break;
                    }
                    Cnodoactual = Cnodoactual->Cnext;
                }

                Cnodoactual = Cnodoinicial;
            }

            hMostrarPacks = GetDlgItem(hWnd, Lista_packs_show);
            if (Pnodoinicial != NULL) {
                int indice = 0;
                while (Pnodoactual != NULL) {
                    string datos;
                    datos.append("Paquete: ");
                    datos.append(Pnodoactual->New_clave);
                    SendMessageA(hMostrarPacks, LB_ADDSTRING, 0, (LPARAM)datos.c_str());
                    SendMessageA(hMostrarPacks, LB_SETITEMDATA, (WPARAM)indice, (LPARAM)Pnodoactual->idPaquete);
                    indice++;

                    if (Pnodoactual->Pnext == NULL) {
                        break;
                    }
                    Pnodoactual = Pnodoactual->Pnext;
                }
                Pnodoactual = Pnodoinicial;
            }

        }break;

        case WM_COMMAND: {

            //Eliminar Paquete
            if (LOWORD(wParam) == IDC_BUTTON1 && HIWORD(wParam) == BN_CLICKED) {

                Pnodoactual = Pnodoinicial;
                int indice = SendMessageA(hMostrarPacks, LB_GETCURSEL, 0, 0);
                int identificador = SendMessageA(hMostrarPacks, LB_GETITEMDATA, indice, NULL);

                while (Pnodoactual != NULL) {

                    if (identificador == Pnodoactual->idPaquete) {

                        bool verdad = eliminar_paquetes_despues_de_mecanicos(Pnodoactual->New_clave);

                        if (verdad == true) {
                            MessageBox(NULL, "Esta pertenece a un Mecanico, para poder actualizar elimine a el mecanico", "ERROR", MB_OK + MB_ICONEXCLAMATION);
                            break;
                        }

                        else if (Pnodoactual->Pprev == NULL && Pnodoactual->Pnext == NULL) {
                            delete Pnodoactual;
                            Pnodoactual = Pnodoinicial = NULL;
                        }

                        else if (Pnodoactual->Pprev == NULL) {
                            Pnodoinicial = Pnodoinicial->Pnext;
                            Pnodoinicial->Pprev = NULL;
                            delete Pnodoactual;
                            Pnodoactual = Pnodoinicial;
                        }

                        else if (Pnodoactual->Pnext == NULL) {
                            Pnodoactual->Pprev->Pnext = NULL;
                            delete Pnodoactual;
                            Pnodoactual = Pnodoinicial;
                        }

                        else
                        {
                            Pnodoactual->Pprev->Pnext = Pnodoactual->Pnext;
                            Pnodoactual->Pnext->Pprev = Pnodoactual->Pprev;
                            delete Pnodoactual;
                            Pnodoactual = Pnodoinicial;
                        }
     
                        hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                        ShowWindow(hMenu_General, SW_SHOW);
                        DestroyWindow(hWnd);
                        break;
                    }
                    Pnodoactual = Pnodoactual->Pnext;
                }
            }

            if (LOWORD(wParam) == Lista_packs_show && HIWORD(wParam) == LBN_SELCHANGE) {

                int posicionP = SendMessage(hMostrarPacks, LB_GETCURSEL, 0, 0);
                int codigoP = SendMessage(hMostrarPacks, LB_GETITEMDATA, posicionP, 0);

                while (Pnodoactual != NULL) {

                    if (codigoP == Pnodoactual->idPaquete) {

                        HWND hid = GetDlgItem(hWnd, IDC_EDIT1);
                        int id = Pnodoactual->idPaquete;
                        string convertirid = to_string(id);
                        SetWindowTextA(hid, convertirid.c_str());
                        HWND hCosto = GetDlgItem(hWnd, IDC_EDIT3);
                        SetWindowTextA(hCosto, Pnodoactual->New_cost);
                        HWND hdescription = GetDlgItem(hWnd, IDC_EDIT4);
                        SetWindowTextA(hdescription, Pnodoactual->New_descripccion);
                        break;
                    }
                    Pnodoactual = Pnodoactual->Pnext;
                }
                Pnodoactual = Pnodoinicial;
            }

            if (LOWORD(wParam) == Pestania_1 && HIWORD(wParam) == BN_CLICKED) {
                hRegistro_Paquetes_Servicio = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_Registrar_Paquetes_Servicios), NULL, Registrar_Paquetes_Servicio);
                ShowWindow(hRegistro_Paquetes_Servicio, SW_SHOW);
                DestroyWindow(hWnd);
            }

            if (LOWORD(wParam) == Pestania_2 && HIWORD(wParam) == BN_CLICKED) {

//                if (Pnodoinicial == NULL) {

    //                MessageBoxA(hWnd, "Se deben registrar Paquetes de Servicio Primero -.-", "ERROR", MB_ICONWARNING);
          //      }
       //         else
            //    {
                    hRegistrar_Mecanicos = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_Registrar_Mecanicos), NULL, Registrar_Mecanicos);
                    ShowWindow(hRegistrar_Mecanicos, SW_SHOW);
                    DestroyWindow(hWnd);
              //  }
            }
            
            if (LOWORD(wParam) == Pestania_3 && HIWORD(wParam) == BN_CLICKED) {
                hRegistrar_Clientes = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_Registro_Clientes), NULL, Registrar_Clientes);
                ShowWindow(hRegistrar_Clientes, SW_SHOW);
                DestroyWindow(hWnd);
            }

            if (LOWORD(wParam) == Pestania_6 && HIWORD(wParam) == BN_CLICKED) {
            
                if (Mnodoinicial == NULL) {
                    MessageBoxA(hWnd, "Se deben registrar Mecanicos Para ordenar algo -.-", "ERROR", MB_ICONWARNING);
                }

                else 
                {
                    hHeap_Ordenamiento = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(heap), NULL, Heap_Sort_CBack);
                    ShowWindow(hHeap_Ordenamiento, SW_SHOW);
                    DestroyWindow(hWnd);
                }
            }
            
            if (LOWORD(wParam) == pestania_6_1 && HIWORD(wParam) == BN_CLICKED) { 
                quick();
                MessageBoxA(hWnd, "Archivo de texto de Quick Sort de Clientes Generado", ":D", MB_OK);
            }   

            if (LOWORD(wParam) == salir_sistema_ && HIWORD(wParam) == BN_CLICKED) {
                
                int salir = MessageBox(hWnd, "Desea salir del sistema?", ":D", MB_YESNO);
                
                if (salir == 6) { 

                    Guardar_Mecanicos_Bin(Mnodoactual);
                    Guardar_Paquetes_Bin(Pnodoactual);
                    Guardar_Clientes_Bin(Cnodoactual);
                    exitWindow = true;
                    DestroyWindow(hWnd);
                }
            }
             
            if (LOWORD(wParam) == Pestania_4 && HIWORD(wParam) == BN_CLICKED) {
             
                if (Cnodoinicial == NULL || Mnodoinicial == NULL) {
                    MessageBoxA(hWnd, "Se deben registrar Clientes y Mecanicos Primero -.-", "ERROR", MB_ICONWARNING);
                }

                else
                {
                    hRegistrar_Citas = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_registro_citas), NULL, Registrar_Citas);
                    ShowWindow(hRegistrar_Citas, SW_SHOW);
                    DestroyWindow(hWnd);
                } 
            }

            if (LOWORD(wParam) == Pestania_5 && HIWORD(wParam) == BN_CLICKED) {
             
                if (Cnodoinicial == NULL || Mnodoinicial == NULL || Citasnodoinicial == NULL) {
                    MessageBoxA(hWnd, "Se deben registrar Clientes, Mecanicos, Y Citas Para Consultar -.-", "ERROR", MB_ICONWARNING);
                }

                else
                {
                    hConsultar_Citas = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Consulta_Citas), NULL, Consultar_Citas);
                    ShowWindow(hConsultar_Citas, SW_SHOW);
                    DestroyWindow(hWnd);
                } 
            }

            if (LOWORD(wParam) == Edc_Editar_Mecanico && HIWORD(wParam) == BN_CLICKED) {           
               
                 int posicion = SendMessageA(hMostrarDatos, LB_GETCURSEL, 0, 0);
                 int codigo = SendMessageA(hMostrarDatos, LB_GETITEMDATA, posicion, 0);

                 while (Mnodoactual != NULL) {

                     if (codigo == Mnodoactual->idMecanicos) {

                         bool verdad = editar_eliminar_mecanicos_despues_de_citas(Mnodoactual->Nombre_Completo_Empleado);

                         if (verdad == true) {
                             MessageBox(NULL, "Este usuario ya tiene una cita, para poder editar modifique/elimine la cita", "ERROR", MB_OK + MB_ICONEXCLAMATION);
                             break;
                         }

                         else { 
                             Meditar = Mnodoactual;
                             Mnodoactual = Mnodoinicial;
                             hEditar_Mecanicos = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_Registrar_Mecanicos), NULL, Editar_Mecanicos);
                             ShowWindow(hEditar_Mecanicos, SW_SHOW);
                             DestroyWindow(hWnd);
                             break;
                         }
                     }
                     Mnodoactual = Mnodoactual->Mnext;
                 }
                 Mnodoactual = Mnodoinicial; 
            }

            if (LOWORD(wParam) == Edc_Eliminar_Mecanico && HIWORD(wParam) == BN_CLICKED) {
            
                Mnodoactual = Mnodoinicial;
                int indice = SendMessageA(hMostrarDatos, LB_GETCURSEL, 0, 0);
                int identificador = SendMessageA(hMostrarDatos, LB_GETITEMDATA, indice, NULL);

                while (Mnodoactual != NULL) {
                    
                    if (identificador == Mnodoactual->idMecanicos) {
                    
                        bool verdad = editar_eliminar_mecanicos_despues_de_citas(Mnodoactual->Nombre_Completo_Empleado);

                        if (verdad == true) {
                            MessageBox(NULL, "Este usuario ya tiene una cita, para poder editar modifique/elimine la cita", "ERROR", MB_OK + MB_ICONEXCLAMATION);
                            break;
                        }

                        else if (Mnodoactual->Mprev == NULL && Mnodoactual->Mnext == NULL) {
                            delete Mnodoactual;
                            Mnodoactual = Mnodoinicial = NULL;
                        }
                    
                        else if (Mnodoactual->Mprev == NULL) {
                            Mnodoinicial = Mnodoinicial->Mnext;
                            Mnodoinicial->Mprev = NULL;
                            delete Mnodoactual;
                            Mnodoactual = Mnodoinicial;
                        }

                        else if (Mnodoactual->Mnext == NULL) {
                            Mnodoactual->Mprev->Mnext = NULL;
                            delete Mnodoactual;
                            Mnodoactual = Mnodoinicial;
                        }

                        else
                        {
                            Mnodoactual->Mprev->Mnext = Mnodoactual->Mnext;
                            Mnodoactual->Mnext->Mprev = Mnodoactual->Mprev;
                            delete Mnodoactual;
                            Mnodoactual = Mnodoinicial;
                        }

                        hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                        ShowWindow(hMenu_General, SW_SHOW);
                        DestroyWindow(hWnd);
                        break;
                    }
                    Mnodoactual = Mnodoactual->Mnext; 
                }
            }

            if (LOWORD(wParam) == btn_eliminar_cliente && HIWORD(wParam) == BN_CLICKED){
            
                Cnodoactual = Cnodoinicial;
                int indice = SendMessageA(hMostrarDatosClientes, LB_GETCURSEL, 0, 0);
                int identificador = SendMessageA(hMostrarDatosClientes, LB_GETITEMDATA, indice, NULL);
                    
                while (Cnodoactual != NULL) {

                    if (identificador == Cnodoactual->idClientes) {

                        bool verdad = editar_eliminar_clientes_despues_de_citas(Cnodoactual->Nombre_Cliente);

                        if (verdad == true) {
                            MessageBox(NULL, "Este usuario ya tiene una cita, para poder editar modifique/elimine la cita", "ERROR", MB_OK + MB_ICONEXCLAMATION);
                            break;
                        }

                        else if (Cnodoactual->Cprev == NULL && Cnodoactual->Cnext == NULL) {
                            delete Cnodoactual;
                            Cnodoactual = Cnodoinicial = NULL;
                        }

                        else if (Cnodoactual->Cprev == NULL) {
                            Cnodoinicial = Cnodoinicial->Cnext;
                            Cnodoinicial->Cprev = NULL;
                            delete Cnodoactual;
                            Cnodoactual = Cnodoinicial;
                        }

                        else if (Cnodoactual->Cnext == NULL) {
                            Cnodoactual->Cprev->Cnext = NULL;
                            delete Cnodoactual;
                            Cnodoactual = Cnodoinicial;
                        }

                        else
                        {
                            Cnodoactual->Cprev->Cnext = Cnodoactual->Cnext;
                            Cnodoactual->Cnext->Cprev = Cnodoactual->Cprev;
                            delete Cnodoactual;
                            Cnodoactual = Cnodoinicial;
                        }

                        hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                        ShowWindow(hMenu_General, SW_SHOW);
                        DestroyWindow(hWnd);
                        break;
                    }
                    Cnodoactual = Cnodoactual->Cnext;
                } 
            }
        
            if (LOWORD(wParam) == btn_Editar_Cliente && HIWORD(wParam) == BN_CLICKED) {
            
                int posicion = SendMessageA(hMostrarDatosClientes, LB_GETCURSEL, 0, 0);
                int codigo = SendMessageA(hMostrarDatosClientes, LB_GETITEMDATA, posicion, 0);

                while (Cnodoactual != NULL) {

                    if (codigo == Cnodoactual->idClientes) {

                        bool verdad = editar_eliminar_clientes_despues_de_citas(Cnodoactual->Nombre_Cliente);
                        
                        if (verdad == true) {
                            MessageBox(NULL, "Este usuario ya tiene una cita, para poder editar modifique/elimine la cita", "ERROR", MB_OK + MB_ICONEXCLAMATION);
                            break;
                        }

                        else
                        {
                            Ceditar = Cnodoactual;
                            Cnodoactual = Cnodoinicial;
                            hRegistrar_Clientes = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_Registro_Clientes), NULL, Editar_Clientes);
                            ShowWindow(hRegistrar_Clientes, SW_SHOW);
                            DestroyWindow(hWnd);
                            break;
                        }
                    }
                    Cnodoactual = Cnodoactual->Cnext;
                }
                Cnodoactual = Cnodoinicial;
            }

            if (LOWORD(wParam) == Lista_M && HIWORD(wParam) == LBN_SELCHANGE) {

                int posicion = SendMessage(hMostrarDatos, LB_GETCURSEL, 0, 0);
                int codigo = SendMessage(hMostrarDatos, LB_GETITEMDATA, posicion, 0);

                while (Mnodoactual != NULL) {

                    if (codigo == Mnodoactual->idMecanicos) {

                        HWND hPicImagen = GetDlgItem(hWnd, Fotito);
                        HBITMAP hBmImagen = (HBITMAP)LoadImage(NULL, Mnodoactual->Foto_Mecanicos, IMAGE_BITMAP, 110, 110, LR_LOADFROMFILE);
                        SendMessage(hPicImagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmImagen);
                        HWND Turno = GetDlgItem(hWnd, edc_ver_turnos);
                        SetWindowTextA(Turno, Mnodoactual->Turno_Trabajo);
                        HWND hNumero = GetDlgItem(hWnd, edc_ver_numero);
                        int n = Mnodoactual->idMecanicos;
                        string convertir = to_string(n);
                        SetWindowTextA(hNumero, convertir.c_str());
                        HWND hTelefono = GetDlgItem(hWnd, edc_mostrar_numero);
                        SetWindowTextA(hTelefono, Mnodoactual->Num_Celular_Mecanicos);
                        HWND hEspecialidad = GetDlgItem(hWnd, edc_ver_especialidad);
                        SetWindowTextA(hEspecialidad, Mnodoactual->Especialidad_Mecanicos);
                        char Dias[MAX_PATH] = "";
                        HWND hDias = GetDlgItem(hWnd, edc_dias_laborales);
                        if (Mnodoactual->dia_lunes == true)
                             strcat(Dias, "Lunes\t");
                        if (Mnodoactual->dia_martes == true)
                            strcat(Dias, "Martes\t");
                        if (Mnodoactual->dia_miercoles == true)
                            strcat(Dias, "Miercoles\t");
                        if (Mnodoactual->dia_jueves == true)
                            strcat(Dias, "   Jueves\t");
                        if (Mnodoactual->dia_viernes == true)
                            strcat(Dias, " Viernes\t");
                        if (Mnodoactual->dia_sabado == true)
                            strcat(Dias, " Sabado\t");
                        if (Mnodoactual->dia_domingo == true)
                            strcat(Dias, " Domingo\t");
                        SetWindowTextA(hDias, Dias);
                        break;
                    }
                    Mnodoactual = Mnodoactual->Mnext;
                }
                Mnodoactual = Mnodoinicial;
            }

            if (LOWORD(wParam) == Lista_Clientes && HIWORD(wParam) == LBN_SELCHANGE) {
            
                int posicionC = SendMessage(hMostrarDatosClientes, LB_GETCURSEL, 0, 0);
                int codigoC = SendMessage(hMostrarDatosClientes, LB_GETITEMDATA, posicionC, 0);

                while (Cnodoactual != NULL) {

                    if (codigoC == Cnodoactual->idClientes) {
                    
                        HWND hPlacas = GetDlgItem(hWnd, edc_placas_cliente_carro_xd);
                        SetWindowTextA(hPlacas, Cnodoactual->Placas_Cliente);
                        HWND hMarca_Carro = GetDlgItem(hWnd, edc_carro_marca_clientexd);
                        SetWindowTextA(hMarca_Carro, Cnodoactual->Marca_Carro_Cliente);
                        HWND hModelo_Carro = GetDlgItem(hWnd, modelo_carro_cliente_xd);
                        SetWindowTextA(hModelo_Carro, Cnodoactual->Modelo_Carro_Cliente);
                        HWND hYear = GetDlgItem(hWnd, edc_carro_anio_cliente);
                        string dato = to_string(Cnodoactual->Year_Carro_Cliente);
                        SetWindowTextA(hYear, dato.c_str());  
                        HWND hKilometraje = GetDlgItem(hWnd, edc_kilometraje_cliente_xd); 
                        SetWindowTextA(hKilometraje, Cnodoactual->Kilometraje_Carro);
                        HWND hid = GetDlgItem(hWnd, edc_id_clientexd);
                        string dato3 = to_string(Cnodoactual->idClientes);
                        SetWindowTextA(hid, dato3.c_str());
                        HWND hPhone = GetDlgItem(hWnd, edc_telefono_clientexd);
                        SetWindowTextA(hPhone, Cnodoactual->Telefono_Cliente);
                        HWND hDireccion = GetDlgItem(hWnd, direccion_clientexd);
                        SetWindowTextA(hDireccion, Cnodoactual->Direccion_Cliente);
                        break;
                    }
                    Cnodoactual = Cnodoactual->Cnext;
                }
                Cnodoactual = Cnodoinicial;
            }

        }break;

        case WM_CLOSE: {

            exitWindow = true;
            DestroyWindow(hWnd);

        }break;

        case WM_DESTROY: {
            
            if (exitWindow)
            PostQuitMessage(117);

        }break;
    }
    return FALSE;
}

BOOL CALLBACK Registrarse_Ventana(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lparam) {

    switch (msg) {
        case WM_INITDIALOG: {
 
        }break;

        case WM_COMMAND: {

            if (LOWORD(wParam) == btn_aceptar && HIWORD(wParam) == BN_CLICKED) {

                SendDlgItemMessageA(hWnd, edc_registro_usuario, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)user);
                SendDlgItemMessageA(hWnd, edc_registro_contrasenia, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)pswrd);
                SendDlgItemMessageA(hWnd, edc_registro_nombrecompleto, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)fullName);
  
                bool espacios = validarEpaciosBlanco(pswrd);
                bool serepite = validarQueNoSeRepitanUsuarios(user);
                
                if (strcmp(user, "") == 0 || strcmp(pswrd, "") == 0 || strcmp(fullName, "") == 0){          
                    MessageBoxA(hWnd, "Falto Llenar La Información", "ERROR", MB_ICONWARNING);
                }

                else if (espacios == false) {
                    MessageBoxA(hWnd, "No Ponga Espacios En La Contraseña", "ERROR", MB_ICONWARNING);
                }

                else if (serepite == true) {
                    MessageBoxA(hWnd, "No se permiten usuarios repetidos", "ERROR", MB_ICONERROR);
                }

                else
                {
                    if (nodoinicial == NULL) {

                        nodoinicial = new User;
                        strcpy_s(nodoinicial->New_Full_Name, fullName);
                        strcpy_s(nodoinicial->New_password,pswrd);
                        strcpy_s(nodoinicial->New_username,user);
                        nodoinicial->idUser = GLOBAL_USER_ID++;
                        nodoinicial->prev = NULL;
                        nodoinicial->next = NULL;
                        nodoactual = nodoinicial;
                        MessageBoxA(NULL, "Nuevo Usuario Registrado", "NUEVO USUARIO", MB_OK);
                    }

                    else
                    {
                        while (nodoactual->next != NULL)
                            nodoactual = nodoactual->next;
                        nodoactual->next = new User;
                        nodoactual->next->prev = nodoactual;
                        nodoactual = nodoactual->next;
                        strcpy_s(nodoactual->New_Full_Name, fullName);
                        strcpy_s(nodoactual->New_password, pswrd);
                        strcpy_s(nodoactual->New_username, user);
                        nodoactual->idUser = GLOBAL_USER_ID++;
                        nodoactual->next = NULL;
                        nodoactual = nodoinicial;
                        MessageBoxA(NULL, "Nuevo Usuario Registrada", "NUEVO USUARIO", MB_OK);
                    }

                    Guardar_Users_Bin(nodoactual);
                    Guardar_Global_Id();
                    hPrincipal = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_Principal), NULL, Principal);
                    ShowWindow(hPrincipal, SW_SHOW);
                    DestroyWindow(hWnd);

                }
            }

            if (LOWORD(wParam) == btn_regresar && HIWORD(wParam) == BN_CLICKED) {

                hPrincipal = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_Principal), NULL, Principal);
                ShowWindow(hPrincipal, SW_SHOW);
                DestroyWindow(hWnd);

            }

        }

    }

    return FALSE;
}

BOOL CALLBACK Registrar_Paquetes_Servicio(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
        case WM_INITDIALOG: {

            hNum_Packs_id = GetDlgItem(hWnd, edc_id_packs);
            string convertir = to_string(GLOBAL_PACKS_ID);
            SetWindowTextA(hNum_Packs_id, convertir.c_str());

        }break;

        case WM_COMMAND: {
 
            if (LOWORD(wParam) == btn_add_packs && HIWORD(wParam) == BN_CLICKED) {

                SendDlgItemMessageA(hWnd, edc_clave_paquetes, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)clave);
                SendDlgItemMessageA(hWnd, edc_descripccion_paquetes, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)descripccion);
                SendDlgItemMessageA(hWnd, edc_costo_paquetes, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)costo);

                float String_A_Float = Convertir_String_A_Float(costo);
                bool serepite = validarQueNoSeRepitaClavePacks(clave);

                if (strcmp(clave, "") == 0 || strcmp(descripccion, "") == 0 || strcmp(costo, "") == 0) {
                    MessageBoxA(hWnd, "Falto Llenar La Información", "ERROR", MB_ICONWARNING);
                }

                else if (String_A_Float == 0) {
                    MessageBoxA(NULL, "Precio incorrecto", "Error", MB_ICONERROR);
                }

                else if (serepite == true) {
                    MessageBoxA(hWnd, "No se permiten Claves repetidas", "ERROR", MB_ICONERROR);
                }

                else
                {
                    if (Pnodoinicial == NULL) {

                        Pnodoinicial = new Paquetes_Servicio;
                        strcpy_s(Pnodoinicial->New_clave, clave);
                        strcpy_s(Pnodoinicial->New_descripccion, descripccion); 
                        string xd = to_string(String_A_Float);
                        strcpy_s(Pnodoinicial->New_cost, xd.c_str());  
                        Pnodoinicial->idPaquete = GLOBAL_PACKS_ID++;
                        Pnodoinicial->Pprev = NULL;
                        Pnodoinicial->Pnext = NULL;
                        Pnodoactual = Pnodoinicial;
                        MessageBoxA(NULL, "Nuevo Paquete Registrado", "NUEVO PAQUETE", MB_OK);
                    }

                    else
                    {
                        while (Pnodoactual->Pnext != NULL)
                            Pnodoactual = Pnodoactual->Pnext;
                        Pnodoactual->Pnext = new Paquetes_Servicio;
                        Pnodoactual->Pnext->Pprev = Pnodoactual;
                        Pnodoactual = Pnodoactual->Pnext;
                        strcpy_s(Pnodoactual->New_clave, clave);
                        strcpy_s(Pnodoactual->New_descripccion, descripccion);
                        string xd = to_string(String_A_Float);
                        strcpy_s(Pnodoactual->New_cost, xd.c_str()); 
                        Pnodoactual->idPaquete = GLOBAL_PACKS_ID++;
                        Pnodoactual->Pnext = NULL;
                        Pnodoactual = Pnodoinicial;
                        MessageBoxA(NULL, "Nuevo Paquete Registrado", "NUEVO PAQUETE", MB_OK);
                    } 
                    Guardar_Global_Id();
                    hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                    ShowWindow(hMenu_General, SW_SHOW);
                    DestroyWindow(hWnd);
                }
            }

            if (LOWORD(wParam) == btn_regresar_packs && HIWORD(wParam) == BN_CLICKED) {

                hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                ShowWindow(hMenu_General, SW_SHOW);
                DestroyWindow(hWnd);
            }

        }break;
    }

    return FALSE;
}

BOOL CALLBACK Consultar_Citas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
   
    switch (msg) {
        case WM_INITDIALOG: {

            Guardar_Citas_Bin(Citasnodoactual);

            hMostrarCitas = GetDlgItem(hWnd, Lista_Citas);
            if (Citasnodoinicial != NULL) {
                int indice = 0;
                while (Citasnodoactual != NULL) {
                    string datos;
                    datos.append("Nombre de Cliente: ");
                    datos.append(Citasnodoactual->Nombre_Cliente_Cita);
                    SendMessageA(hMostrarCitas , LB_ADDSTRING, 0, (LPARAM)datos.c_str());
                    SendMessageA(hMostrarCitas , LB_SETITEMDATA, (WPARAM)indice, (LPARAM)Citasnodoactual->idCitas);
                    indice++;

                    if (Citasnodoactual->Citasnext == NULL) {
                        break;
                    }
                    Citasnodoactual = Citasnodoactual->Citasnext;
                }
                Citasnodoactual = Citasnodoinicial;
            }

        }break;

        case WM_COMMAND: {
        
            if (LOWORD(wParam) == Lista_Citas && HIWORD(wParam) == LBN_SELCHANGE) {
            
                int posicion = SendMessage(hMostrarCitas, LB_GETCURSEL, 0, 0);
                int codigo = SendMessage(hMostrarCitas, LB_GETITEMDATA, posicion, 0);
            
                while (Citasnodoactual != NULL) {

                    if (codigo == Citasnodoactual->idCitas) {
                    
                        HWND hfecha = GetDlgItem(hWnd, edc_mostrar_fecha_cita);
                        SetWindowTextA(hfecha, Citasnodoactual->fecha.c_str());
                        HWND hHora = GetDlgItem(hWnd, edc_mostrar_hora_cita);
                        SetWindowTextA(hHora, Citasnodoactual->hora.c_str());
                        HWND hmecanico = GetDlgItem(hWnd, edc_mostrar_mecanico_cita);
                        SetWindowTextA(hmecanico, Citasnodoactual->Nombre_Mecanico_Cita);
                        HWND hservicio = GetDlgItem(hWnd, edc_mostrar_servicio_cita);
                        SetWindowTextA(hservicio, Citasnodoactual->Tipo_Servicio_Cita); 
                        break;
                    }
                    Citasnodoactual = Citasnodoactual->Citasnext;
                }
                Citasnodoactual = Citasnodoinicial;
            }

            if (LOWORD(wParam) == IDOK && HIWORD(wParam) == BN_CLICKED) {            
   
                Citasnodoactual = Citasnodoinicial;
                int indice = SendMessageA(hMostrarCitas, LB_GETCURSEL, 0, 0);
                int identificador = SendMessageA(hMostrarCitas, LB_GETITEMDATA, indice, NULL);

                while (Citasnodoactual != NULL) {

                    if (identificador == Citasnodoactual->idCitas) {

                        if (Citasnodoactual->Citasprev == NULL && Citasnodoactual->Citasnext == NULL) {
                            delete Citasnodoactual;
                            Citasnodoactual = Citasnodoinicial = NULL;
                        }

                        else if (Citasnodoactual->Citasprev == NULL) {
                            Citasnodoinicial = Citasnodoinicial->Citasnext;
                            Citasnodoinicial->Citasprev = NULL;
                            delete Citasnodoactual;
                            Citasnodoactual = Citasnodoinicial;
                        }

                        else if (Citasnodoactual->Citasnext == NULL) {
                            Citasnodoactual->Citasprev->Citasnext = NULL;
                            delete Citasnodoactual;
                            Citasnodoactual = Citasnodoinicial;
                        }

                        else
                        {
                            Citasnodoactual->Citasprev->Citasnext = Citasnodoactual->Citasnext;
                            Citasnodoactual->Citasnext->Citasprev = Citasnodoactual->Citasprev;
                            delete Citasnodoactual;
                            Citasnodoactual = Citasnodoinicial;
                        }

                        MessageBoxA(NULL, "Nuevos Cambios Realizados", ":D", MB_OK);
                        hConsultar_Citas = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Consulta_Citas), NULL, Consultar_Citas);
                        ShowWindow(hConsultar_Citas, SW_SHOW);
                        DestroyWindow(hWnd);
                        break;
                    }
                    Citasnodoactual = Citasnodoactual->Citasnext;
                }
            }

            if (LOWORD(wParam) == btn_regresar_mostrar_cita && HIWORD(wParam) == BN_CLICKED) {
                hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                ShowWindow(hMenu_General, SW_SHOW);
                DestroyWindow(hWnd);
            }
        }break;
    }
    return FALSE;
}

BOOL CALLBACK Registrar_Citas(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
        case WM_INITDIALOG: {

            hFechas = GetDlgItem(hWnd, Set_Fecha);
            
            hMostrarMecanicos = GetDlgItem(hWnd, Lista_Citas_Mecanicos);
            if (Mnodoinicial != NULL) {
                int indice = 0;
                while (Mnodoactual != NULL) {
                    string datos;
                    datos.append("Mecanico: ");
                    datos.append(Mnodoactual->Nombre_Completo_Empleado);
                    SendMessageA(hMostrarMecanicos, LB_ADDSTRING, 0, (LPARAM)datos.c_str());
                    SendMessageA(hMostrarMecanicos, LB_SETITEMDATA, (WPARAM)indice, (LPARAM)Mnodoactual->idMecanicos);
                    indice++;

                    if (Mnodoactual->Mnext == NULL) {
                        break;
                    }
                    Mnodoactual = Mnodoactual->Mnext;
                }
                Mnodoactual = Mnodoinicial;
            }
            
            hMostrarClientes = GetDlgItem(hWnd, Lista_Citas_Clientes);
            if (Cnodoinicial != NULL) {
                int indiceC = 0;
                while (Cnodoactual != NULL) {
                    string datosC;
                    datosC.append("Cliente: ");
                    datosC.append(Cnodoactual->Nombre_Cliente);
                    SendMessageA(hMostrarClientes, LB_ADDSTRING, 0, (LPARAM)datosC.c_str());
                    SendMessageA(hMostrarClientes, LB_SETITEMDATA, (WPARAM)indiceC, (LPARAM)Cnodoactual->idClientes);
                    indiceC++;

                    if (Cnodoactual->Cnext == NULL) {
                        break;
                    }
                    Cnodoactual = Cnodoactual->Cnext;
                }
                Cnodoactual = Cnodoinicial;
            }

            while (Pnodoactual != NULL) {
                HWND hCombo = GetDlgItem(hWnd, cmb_especialidades_mecanicos_citas);
                SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)Pnodoactual->New_clave);
                SendMessage(hCombo, CB_SETCURSEL, 0, 0);
                Pnodoactual = Pnodoactual->Pnext;
            }
            Pnodoactual = Pnodoinicial;

        }break;

        case WM_COMMAND: {
 
            if (LOWORD(wParam) == regresar_cita && HIWORD(wParam) == BN_CLICKED) {
                hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                ShowWindow(hMenu_General, SW_SHOW);
                DestroyWindow(hWnd);
            }
           
            if (LOWORD(wParam) == Lista_Citas_Clientes && HIWORD(wParam) == LBN_SELCHANGE) {

                int posicionCitas = SendMessage(hMostrarClientes, LB_GETCURSEL, 0, 0);
                int codigoCitas = SendMessage(hMostrarClientes, LB_GETITEMDATA, posicionCitas, 0);

                while (Cnodoactual != NULL) {

                    if (codigoCitas == Cnodoactual->idClientes) {
                        strcpy_s(Cita_Nombre_Cliente, Cnodoactual->Nombre_Cliente);
                        break;
                    }
                    Cnodoactual = Cnodoactual->Cnext;
                }
                Cnodoactual = Cnodoinicial;
            }
            
            if (LOWORD(wParam) == Lista_Citas_Mecanicos && HIWORD(wParam) == LBN_SELCHANGE) {

                int posicionCitas2 = SendMessage(hMostrarMecanicos, LB_GETCURSEL, 0, 0);
                int codigoCitas2 = SendMessage(hMostrarMecanicos, LB_GETITEMDATA, posicionCitas2, 0);

                while (Mnodoactual != NULL) {

                    if (codigoCitas2 == Mnodoactual->idMecanicos) {
                        strcpy_s(Cita_Nombre_Mecanico, Mnodoactual->Nombre_Completo_Empleado);
                        HWND Special = GetDlgItem(hWnd, IDC_EDIT1);
                        SetWindowTextA(Special, Mnodoactual->Especialidad_Mecanicos);
                        SendDlgItemMessageA(hWnd, IDC_EDIT1, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Comparacion);
                        strcpy_s(Horario_Lab_Comp, Mnodoactual->Turno_Trabajo);
                        HWND Horario_L = GetDlgItem(hWnd, IDC_EDIT2);
                        SetWindowTextA(Horario_L, Mnodoactual->Turno_Trabajo);  
                        HWND hPicImagen = GetDlgItem(hWnd, Fotito_Mecanico);
                        HBITMAP hBmImagen = (HBITMAP)LoadImage(NULL, Mnodoactual->Foto_Mecanicos, IMAGE_BITMAP, 110, 110, LR_LOADFROMFILE);
                        SendMessage(hPicImagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmImagen);
                        break;
                    }
                    Mnodoactual = Mnodoactual->Mnext;
                }
                Mnodoactual = Mnodoinicial;
            }

            if (LOWORD(wParam) == aceptar_cita && HIWORD(wParam) == BN_CLICKED) {

                SendDlgItemMessageA(hWnd, cmb_especialidades_mecanicos_citas, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Cita_Especialidad);

                //FECHA de Hoy				
                actualTime = time(NULL);
                time(&actualTime);
                TimeInfo = localtime(&actualTime);
                int dayactual = TimeInfo->tm_mday; //dia actual         
                int monthactual = TimeInfo->tm_mon + 1;  //mes actual   [0-11]
                int aniooactual = TimeInfo->tm_year + 1900; //año actual  

                /////////////////Fecha que seleccione//////////////
                char vFecha[50];
                SendDlgItemMessage(hWnd, Set_Fecha, WM_GETTEXT, MAX_PATH, (LPARAM)vFecha);
                string vDate(vFecha); //substr -> ##/##/####				                            

                string sDay;
                sDay = vDate.substr(0, 2);
                int day = atoi(sDay.c_str());

                string sMonth;
                sMonth = vDate.substr(3, 2);
                int month = atoi(sMonth.c_str());

                string sYear;
                sYear = vDate.substr(6, 4);
                int year = atoi(sYear.c_str());

                /////////////////Hora que selecciono//////////////
                char vHora[50];
                SendDlgItemMessage(hWnd, Set_Time, WM_GETTEXT, MAX_PATH, (LPARAM)vHora);
                string vHour(vHora);

                string sHour;
                sHour = vHour.substr(0, 2);
                int hour = atoi(sHour.c_str());

                string sMinute;
                sMinute = vHour.substr(3, 2);
                int minute = atoi(sMinute.c_str());

                bool error = validar_horario_correcto_citas(vHour);
                            
                if (day < dayactual) {
                   MessageBox(hWnd, "Favor de no poner una fecha previa al dia actual", "ERROR: Fecha", MB_OK + MB_ICONEXCLAMATION); 
                }

                else if (error == true) {
                    MessageBoxA(NULL, "Mecanico No Disponible en ese Horario -.-", "ERROR", MB_ICONWARNING);
                }

                else if (strcmp(Cita_Especialidad, Comparacion) != 0) {
                    MessageBox(hWnd, "El tipo de servicio que busca el Cliente tiene que ser igual al que ofrece el Mecanico -.-", "ERROR: Fecha", MB_OK + MB_ICONEXCLAMATION);
                }

                else if (month < monthactual) {
                    MessageBox(hWnd, "Favor de no poner una fecha previa al dia actual", "ERROR: Fecha", MB_OK + MB_ICONEXCLAMATION);  
                }
                         
                else if (year < aniooactual) {
                    MessageBox(hWnd, "Favor de no poner una fecha previa al dia actual", "ERROR: Fecha", MB_OK + MB_ICONEXCLAMATION);
                }
 
                else if (strcmp(Cita_Nombre_Cliente, "" ) == 0 || strcmp(Cita_Nombre_Mecanico, "") == 0) {
                    MessageBoxA(hWnd, "Seleccione el nombre del Mecanico/Cliente -.-", "ERROR", MB_ICONWARNING);
                }

                else
                {
                    if (Citasnodoinicial == NULL) {
                        Citasnodoinicial = new Citas;
                        strcpy_s(Citasnodoinicial->Nombre_Cliente_Cita, Cita_Nombre_Cliente);
                        strcpy_s(Citasnodoinicial->Tipo_Servicio_Cita, Cita_Especialidad);
                        strcpy_s(Citasnodoinicial->Nombre_Mecanico_Cita, Cita_Nombre_Mecanico); 
                        Citasnodoinicial->fecha.append(vDate);
                        Citasnodoinicial->hora.append(vHour);
                        Citasnodoinicial->idCitas = GLOBAL_Citas_ID++;
                        Citasnodoinicial->Citasprev = NULL;
                        Citasnodoinicial->Citasnext = NULL;
                        Citasnodoactual = Citasnodoinicial;
                        MessageBoxA(NULL, "Nueva Cita Registrada", "NUEVO MECANICO", MB_OK);
                    }

                    else
                    {
                        while (Citasnodoactual->Citasnext != NULL)
                            Citasnodoactual = Citasnodoactual->Citasnext;
                        Citasnodoactual->Citasnext = new Citas;
                        Citasnodoactual->Citasnext->Citasprev = Citasnodoactual;
                        Citasnodoactual = Citasnodoactual->Citasnext;
                        strcpy_s(Citasnodoactual->Nombre_Cliente_Cita, Cita_Nombre_Cliente);
                        strcpy_s(Citasnodoactual->Tipo_Servicio_Cita, Cita_Especialidad);
                        strcpy_s(Citasnodoactual->Nombre_Mecanico_Cita, Cita_Nombre_Mecanico);
                        Citasnodoactual->idCitas = GLOBAL_Citas_ID++;
                        Citasnodoactual->fecha.append(vDate);
                        Citasnodoactual->hora.append(vHour);
                        Citasnodoactual->Citasnext = NULL;
                        Citasnodoactual = Citasnodoinicial;
                        MessageBoxA(NULL, "Nueva Cita Registrada", "NUEVO MECANICO", MB_OK);
                    }

                    Guardar_Global_Id();
                    hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                    ShowWindow(hMenu_General, SW_SHOW);
                    DestroyWindow(hWnd);
                }
            }
            
        }break;
    }
    return FALSE;
}

BOOL CALLBACK Registrar_Clientes(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
        case WM_INITDIALOG: {
            
            HWND Number = GetDlgItem(hWnd, edc_numero_cliente);
            string convertir = to_string(GLOBAL_CLIENTES_ID);
            SetWindowTextA(Number, convertir.c_str());
        
        }break;

        case WM_COMMAND: { 

            if (LOWORD(wParam) == btn_aceptar_cliente && HIWORD(wParam) == BN_CLICKED) {
          
                SendDlgItemMessageA(hWnd, edc_nombre_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_Nombre_Completo);
                SendDlgItemMessageA(hWnd, edc_placas_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_Placas_Carro);
                SendDlgItemMessageA(hWnd, edc_marca_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_Marca_Carro);
                SendDlgItemMessageA(hWnd, edc_anio_vehiculo_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_Año_del_Vehiculo);
                SendDlgItemMessageA(hWnd, edc_km_carro_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_km_del_vehicuclo);
                SendDlgItemMessageA(hWnd, edc_telefono_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_telefono_celular);
                SendDlgItemMessageA(hWnd, edc_direccion_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_direccion_completa);
                SendDlgItemMessageA(hWnd, edc_modelo_carrocliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_modelo_Carro); 
                int numero1 = atoi(cliente_Año_del_Vehiculo);
                int longitud = strlen(cliente_Placas_Carro);
                int longitud2 = strlen(cliente_telefono_celular);
                bool espacios = validarEpaciosBlanco(cliente_Placas_Carro);

                if (strcmp(cliente_Nombre_Completo, "") == 0 || strcmp(cliente_Placas_Carro, "") == 0 || strcmp(cliente_Marca_Carro, "") == 0 || strcmp(cliente_Año_del_Vehiculo, "") == 0 || 
                    strcmp(cliente_km_del_vehicuclo, "") == 0 || strcmp(cliente_telefono_celular, "") == 0 || strcmp(cliente_direccion_completa, "") == 0 || strcmp(cliente_modelo_Carro, "") == 0) { 
                    MessageBoxA(hWnd, "Falto Llenar Datos", "ERROR", MB_ICONWARNING);
                }

                else if (espacios == false) {
                    MessageBoxA(hWnd, "No Ponga Espacios En La Placa del Vehiculo", "ERROR", MB_ICONWARNING);
                }

                else if (longitud != 7) {
                   MessageBoxA(hWnd, "Las placas de Carro deben tener mas de 7 digitos", "ERROR", MB_ICONWARNING);
                }

                else if (numero1 < 1860 || numero1 > 2021) {
                    MessageBoxA(hWnd, "Fecha invalida para el año de se vehiculo", "ERROR", MB_ICONWARNING);
                }

                else if (longitud2 != 10) {
                    MessageBoxA(hWnd, "Numero de Celular de 10 digitos", "ERROR", MB_ICONWARNING);
                }

                else
                {
                    if (Cnodoinicial == NULL) {

                        Cnodoinicial = new Clientes; 
                        strcpy_s(Cnodoinicial->Nombre_Cliente, cliente_Nombre_Completo);
                        strcpy_s(Cnodoinicial->Placas_Cliente, cliente_Placas_Carro);
                        strcpy_s(Cnodoinicial->Marca_Carro_Cliente, cliente_Marca_Carro);
                        Cnodoinicial->Year_Carro_Cliente = numero1;
                        strcpy_s(Cnodoinicial->Kilometraje_Carro, cliente_km_del_vehicuclo);                     
                        strcpy_s(Cnodoinicial->Telefono_Cliente, cliente_telefono_celular);
                        strcpy_s(Cnodoinicial->Direccion_Cliente, cliente_direccion_completa);
                        strcpy_s(Cnodoinicial->Modelo_Carro_Cliente, cliente_modelo_Carro); 
                        Cnodoinicial->idClientes = GLOBAL_CLIENTES_ID++;
                        Cnodoinicial->Cprev = NULL;
                        Cnodoinicial->Cnext = NULL;
                        Cnodoactual = Cnodoinicial;
                        MessageBoxA(NULL, "Nuevo Cliente Registrado", "NUEVO CLIENTE", MB_OK);
                    }

                    else
                    {
                        while (Cnodoactual->Cnext != NULL)
                            Cnodoactual = Cnodoactual->Cnext;
                        Cnodoactual->Cnext = new Clientes;
                        Cnodoactual->Cnext->Cprev = Cnodoactual;
                        Cnodoactual = Cnodoactual->Cnext;                          
                        strcpy_s(Cnodoactual->Nombre_Cliente, cliente_Nombre_Completo);
                        strcpy_s(Cnodoactual->Placas_Cliente, cliente_Placas_Carro);
                        strcpy_s(Cnodoactual->Marca_Carro_Cliente, cliente_Marca_Carro);
                        Cnodoactual->Year_Carro_Cliente = numero1;
                        strcpy_s(Cnodoactual->Kilometraje_Carro, cliente_km_del_vehicuclo);
                        strcpy_s(Cnodoactual->Telefono_Cliente, cliente_telefono_celular);
                        strcpy_s(Cnodoactual->Direccion_Cliente, cliente_direccion_completa);
                        strcpy_s(Cnodoactual->Modelo_Carro_Cliente, cliente_modelo_Carro);
                        Cnodoactual->idClientes = GLOBAL_CLIENTES_ID++;
                        Cnodoactual->Cnext = NULL;
                        Cnodoactual = Cnodoinicial;
                        MessageBoxA(NULL, "Nuevo Cliente Registrado", "NUEVO CLIENTE", MB_OK);
                    }
                    Guardar_Global_Id();
                    hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                    ShowWindow(hMenu_General, SW_SHOW);
                    DestroyWindow(hWnd);
                }
            }

            if (LOWORD(wParam) == btn_regresar_cliente && HIWORD(wParam) == BN_CLICKED) { 
                hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                ShowWindow(hMenu_General, SW_SHOW);
                DestroyWindow(hWnd); 
            }

        }break;
    }

    return FALSE;
}

BOOL CALLBACK Editar_Clientes(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
        case WM_INITDIALOG: {
 
            HWND id = GetDlgItem(hWnd, edc_numero_cliente);
            string Id_String = to_string(Ceditar->idClientes);
            SetWindowTextA(id, Id_String.c_str());
            HWND name = GetDlgItem(hWnd, edc_nombre_cliente);
            SetWindowTextA(name, Ceditar->Nombre_Cliente); 
            HWND placa = GetDlgItem(hWnd, edc_placas_cliente);
            SetWindowTextA(placa, Ceditar->Placas_Cliente);
            HWND mark = GetDlgItem(hWnd, edc_marca_cliente);
            SetWindowTextA(mark, Ceditar->Marca_Carro_Cliente);
            HWND year = GetDlgItem(hWnd, edc_anio_vehiculo_cliente);
            string xd = to_string(Ceditar->Year_Carro_Cliente);
            SetWindowTextA(year, xd.c_str());
            HWND km = GetDlgItem(hWnd, edc_km_carro_cliente);
            SetWindowTextA(km, Ceditar->Kilometraje_Carro);
            HWND telefono = GetDlgItem(hWnd, edc_telefono_cliente);
            SetWindowTextA(telefono, Ceditar->Telefono_Cliente); 
            HWND direccion = GetDlgItem(hWnd, edc_direccion_cliente);
            SetWindowTextA(direccion, Ceditar->Direccion_Cliente); 
            HWND modelo = GetDlgItem(hWnd, edc_modelo_carrocliente);
            SetWindowTextA(modelo, Ceditar->Modelo_Carro_Cliente);

        }break;

        case WM_COMMAND: {
       
            if (LOWORD(wParam) == btn_aceptar_cliente && HIWORD(wParam) == BN_CLICKED) {

                SendDlgItemMessageA(hWnd, edc_nombre_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_Nombre_Completo_edit);
                SendDlgItemMessageA(hWnd, edc_placas_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_Placas_Carro_edit);
                SendDlgItemMessageA(hWnd, edc_marca_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_Marca_Carro_edit);
                SendDlgItemMessageA(hWnd, edc_anio_vehiculo_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_Año_del_Vehiculo_edit);
                SendDlgItemMessageA(hWnd, edc_km_carro_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_km_del_vehicuclo_edit);
                SendDlgItemMessageA(hWnd, edc_telefono_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_telefono_celular_edit);
                SendDlgItemMessageA(hWnd, edc_direccion_cliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_direccion_completa_edit);
                SendDlgItemMessageA(hWnd, edc_modelo_carrocliente, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)cliente_modelo_Carro_edit);
                int numero1 = atoi(cliente_Año_del_Vehiculo_edit);
                int longitud = strlen(cliente_Placas_Carro_edit);
                int longitud2 = strlen(cliente_telefono_celular_edit);

                if (strcmp(cliente_Nombre_Completo_edit, "") == 0 || strcmp(cliente_Placas_Carro_edit, "") == 0 || strcmp(cliente_Marca_Carro_edit, "") == 0 || strcmp(cliente_Año_del_Vehiculo_edit, "") == 0 ||
                    strcmp(cliente_km_del_vehicuclo_edit, "") == 0 || strcmp(cliente_telefono_celular_edit, "") == 0 || strcmp(cliente_direccion_completa_edit, "") == 0 || strcmp(cliente_modelo_Carro_edit, "") == 0) {
                    MessageBoxA(hWnd, "Falto Llenar Datos", "ERROR", MB_ICONWARNING);
                }

                else if (longitud != 7) {
                    MessageBoxA(hWnd, "Las placas de Carro deben tener mas de 7 digitos", "ERROR", MB_ICONWARNING);
                }

                else if (numero1 < 1860 || numero1 > 2021) {
                    MessageBoxA(hWnd, "Fecha invalida para el año de se vehiculo", "ERROR", MB_ICONWARNING);
                }

                else if (longitud2 != 10) {
                    MessageBoxA(hWnd, "Numero de Celular de 10 digitos", "ERROR", MB_ICONWARNING);
                }

                else
                {
                    strcpy_s(Ceditar->Nombre_Cliente, cliente_Nombre_Completo_edit);
                    strcpy_s(Ceditar->Placas_Cliente, cliente_Placas_Carro_edit);
                    strcpy_s(Ceditar->Marca_Carro_Cliente, cliente_Marca_Carro_edit);
                    Ceditar->Year_Carro_Cliente = numero1;
                    strcpy_s(Ceditar->Kilometraje_Carro, cliente_km_del_vehicuclo_edit);
                    strcpy_s(Ceditar->Telefono_Cliente, cliente_telefono_celular_edit);
                    strcpy_s(Ceditar->Direccion_Cliente, cliente_direccion_completa_edit);
                    strcpy_s(Ceditar->Modelo_Carro_Cliente, cliente_modelo_Carro_edit);
                    MessageBoxA(NULL, "Se Han Guardado Los Cambios", "EDITAR", MB_OK);
                    hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                    ShowWindow(hMenu_General, SW_SHOW);
                    DestroyWindow(hWnd);

                }
            }

            if (LOWORD(wParam) == btn_regresar_cliente && HIWORD(wParam) == BN_CLICKED) {
                hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                ShowWindow(hMenu_General, SW_SHOW);
                DestroyWindow(hWnd);
            }
        
        }break;
    }
    return FALSE;
}

BOOL CALLBACK Editar_Mecanicos(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
 
    switch (msg) {
        case WM_INITDIALOG: {
        
            HWND hPicImagen = GetDlgItem(hWnd, Cargar_Foto_Mecanico);
            HBITMAP hBmImagen = (HBITMAP)LoadImage(NULL, Meditar->Foto_Mecanicos, IMAGE_BITMAP, 110, 110, LR_LOADFROMFILE);
            SendMessage(hPicImagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmImagen);
            HWND id = GetDlgItem(hWnd, edc_num_mecanico);
            string Id_String = to_string(Meditar->idMecanicos);
            SetWindowTextA(id, Id_String.c_str());
            HWND edit_phone = GetDlgItem(hWnd,edc_celular_mecanico);
            SetWindowTextA(edit_phone, Meditar->Num_Celular_Mecanicos);
            HWND edit_nombre = GetDlgItem(hWnd, edc_full_name_mecanico);
            SetWindowTextA(edit_nombre, Meditar->Nombre_Completo_Empleado); 
            hTurno_Mecanicos = GetDlgItem(hWnd, cmb_turno_mecanicos);
            SendMessageA(hTurno_Mecanicos, CB_ADDSTRING, 0, (LPARAM)"Mañana (8:00 a.m. - 16:00 p.m.)");
            SendMessageA(hTurno_Mecanicos, CB_ADDSTRING, 0, (LPARAM)"Tarde  (16:00 p.m. - 24:00 a.m.)");
            SendMessageA(hTurno_Mecanicos, CB_ADDSTRING, 0, (LPARAM)"Madrugada (24:00 a.m. - 8:00 a.m.)");
            SendMessageA(hTurno_Mecanicos, CB_SETCURSEL, 0, 0);
            hTelefono_Mecanicos = GetDlgItem(hWnd, edc_celular_mecanico);  

            while (Pnodoactual != NULL) {
                HWND hCombo = GetDlgItem(hWnd, cmb_especialidades_mecanicos);
                SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)Pnodoactual->New_clave);
                SendMessage(hCombo, CB_SETCURSEL, 0, 0);
                Pnodoactual = Pnodoactual->Pnext;
            }
            Pnodoactual = Pnodoinicial;

        }break;

        case WM_COMMAND: {

            if (LOWORD(wParam) == btn_aceptar_mecanicos && HIWORD(wParam) == BN_CLICKED) {

                SendDlgItemMessageA(hWnd, edc_full_name_mecanico, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Nombre_edit_Full);
                SendDlgItemMessageA(hWnd, cmb_turno_mecanicos, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Turno_Edit);
                SendDlgItemMessageA(hWnd, cmb_especialidades_mecanicos, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Especialidad_Edit);
                SendDlgItemMessageA(hWnd, edc_celular_mecanico, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Celular_edit);
                bool verdad = validarQueNoSeEmpalmenMecanicosEdit(Turno_Edit, Especialidad_Edit,Meditar->idMecanicos);
                int longitud = strlen(Celular_edit);
                Meditar->dia_lunes = false;
                Meditar->dia_martes = false;
                Meditar->dia_miercoles = false;
                Meditar->dia_jueves = false;
                Meditar->dia_viernes = false;
                Meditar->dia_sabado = false;
                Meditar->dia_domingo = false;
              
                if (strcmp(Nombre_edit_Full, "") == 0  || strcmp(Celular_edit, "") == 0) {
                    MessageBoxA(hWnd, "Falto Llenar Datos", "ERROR", MB_ICONWARNING);
                }

                else if (longitud != 10) {
                    MessageBoxA(hWnd, "Numero de Celular de 10 Digitos c: ", "ERROR", MB_ICONWARNING);
                }

                else if (strcmp(Nombre_edit_Full, "") == 0 || ruta_edit.compare("") == 0) {
                    MessageBoxA(hWnd, "Falto Llenar Datos", "ERROR", MB_ICONWARNING);
                }

                else if (longitud != 10) {
                    MessageBoxA(hWnd, "Numero de Celular de 10 Digitos c: ", "ERROR", MB_ICONWARNING);
                }

                else if (verdad == true) {
                    MessageBoxA(hWnd, "Se empalman mecanicos", "ERROR", MB_ICONWARNING);
                }

                else if (contador_edit_lunes % 2 == 0 && contador_edit_martes % 2 == 0 && contador_edit_miercoles % 2 == 0 && contador_edit_jueves % 2 == 0 && contador_edit_viernes % 2 == 0 && contador_edit_sabado % 2 == 0 && contador_edit_domingo % 2 == 0) {
                    MessageBoxA(hWnd, "MINIMO TIENE QUE TRABAJAR 1 DIA -.-", "ERROR", MB_ICONWARNING);
                }

                else
                {
                    if (contador_edit_lunes % 2 != 0)
                        Meditar->dia_lunes = true;
                    if (contador_edit_martes % 2 != 0)
                        Meditar->dia_martes = true;
                    if (contador_edit_miercoles % 2 != 0)
                        Meditar->dia_miercoles = true;
                    if (contador_edit_jueves % 2 != 0)
                        Meditar->dia_jueves = true;
                    if (contador_edit_viernes % 2 != 0)
                        Meditar->dia_viernes = true;
                    if (contador_edit_sabado % 2 != 0)
                        Meditar->dia_sabado = true;
                    if (contador_edit_domingo % 2 != 0)
                        Meditar->dia_domingo = true;
                    strcpy_s(Meditar->Num_Celular_Mecanicos, Celular_edit);
                    strcpy_s(Meditar->Turno_Trabajo, Turno_Edit);
                    strcpy_s(Meditar->Foto_Mecanicos, sRutaDelArchivoNP_Edit);
                    strcpy_s(Meditar->Especialidad_Mecanicos, Especialidad_Edit);
                    strcpy_s(Meditar->Nombre_Completo_Empleado, Nombre_edit_Full);
                    MessageBoxA(NULL, "Se Han Guardado Los Cambios", "EDITAR", MB_OK);
                    contador_edit_lunes = 0;
                    contador_edit_martes = 0;
                    contador_edit_miercoles = 0;
                    contador_edit_jueves = 0;
                    contador_edit_viernes = 0;
                    contador_edit_sabado = 0;
                    contador_edit_domingo = 0;
                    hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                    ShowWindow(hMenu_General, SW_SHOW);
                    DestroyWindow(hWnd);
                }
            }

            if (LOWORD(wParam) == btn_regresar_mecanicos && HIWORD(wParam) == BN_CLICKED) {
                hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                ShowWindow(hMenu_General, SW_SHOW);
                DestroyWindow(hWnd);
            }

            if (LOWORD(wParam) == lunes && HIWORD(wParam) == BN_CLICKED) {
                contador_edit_lunes++;
            }

            if (LOWORD(wParam) == martes && HIWORD(wParam) == BN_CLICKED) {
                contador_edit_martes++;
            }

            if (LOWORD(wParam) == miercoles && HIWORD(wParam) == BN_CLICKED) {
                contador_edit_miercoles++;
            }

            if (LOWORD(wParam) == jueves && HIWORD(wParam) == BN_CLICKED) {
                contador_edit_jueves++;
            }

            if (LOWORD(wParam) == viernes && HIWORD(wParam) == BN_CLICKED) {
                contador_edit_viernes++;
            }

            if (LOWORD(wParam) == sabado && HIWORD(wParam) == BN_CLICKED) {
                contador_edit_sabado++;
            }

            if (LOWORD(wParam) == domingo && HIWORD(wParam) == BN_CLICKED) {
                contador_edit_domingo++;
            }


            if (LOWORD(wParam) == btn_cargaro_foto_mecanicos && HIWORD(wParam) == BN_CLICKED) {

                OPENFILENAME ofn;
                ZeroMemory(&ofn, sizeof(ofn));
                char cRutaDelArchivo[MAX_PATH] = "";
                ofn.hwndOwner = hWnd;
                ofn.lStructSize = sizeof(ofn);
                ofn.lpstrFile = cRutaDelArchivo;
                ofn.nMaxFile = MAX_PATH;
                ofn.lpstrDefExt = "txt";
                ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
                ofn.lpstrFilter = "Solo imagenes\0*.bmp\0Solo texto\0*.txt\0Todos los archivos\0*.*\0";

                if (GetOpenFileName(&ofn)) {
                    strcpy_s(sRutaDelArchivoNP_Edit, cRutaDelArchivo);
                    HWND hPicImagen = GetDlgItem(hWnd, Cargar_Foto_Mecanico);
                    HBITMAP hBmImagen = (HBITMAP)LoadImage(NULL, sRutaDelArchivoNP_Edit, IMAGE_BITMAP, 170, 110, LR_LOADFROMFILE);
                    SendMessage(hPicImagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmImagen);
                }

                ruta_edit = cRutaDelArchivo;
            }

        }break;
    }
    return FALSE;
}

BOOL CALLBACK Registrar_Mecanicos(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
        case WM_INITDIALOG: {

            hNumEmpleado_Mecanicos = GetDlgItem(hWnd, edc_num_mecanico);
            string convertir = to_string(Global_Mecanicos_Id);
            SetWindowTextA(hNumEmpleado_Mecanicos, convertir.c_str()); 
            hTurno_Mecanicos = GetDlgItem(hWnd, cmb_turno_mecanicos);
            SendMessageA(hTurno_Mecanicos, CB_ADDSTRING, 0, (LPARAM)"Mañana (8:00 a.m. - 16:00 p.m.)");
            SendMessageA(hTurno_Mecanicos, CB_ADDSTRING, 0, (LPARAM)"Tarde  (16:00 p.m. - 24:00 a.m.)");
            SendMessageA(hTurno_Mecanicos, CB_ADDSTRING, 0, (LPARAM)"Madrugada (24:00 a.m. - 8:00 a.m.)");
            SendMessageA(hTurno_Mecanicos, CB_SETCURSEL, 0, 0); 

                while (Pnodoactual != NULL) {
                    HWND hCombo = GetDlgItem(hWnd, cmb_especialidades_mecanicos);
                    SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)Pnodoactual->New_clave);
                    SendMessage(hCombo, CB_SETCURSEL, 0, 0);
                    Pnodoactual = Pnodoactual->Pnext;
                }
                Pnodoactual = Pnodoinicial;

        }break;

        case WM_COMMAND: {

            if (LOWORD(wParam) == btn_cargaro_foto_mecanicos && HIWORD(wParam) == BN_CLICKED) {

                OPENFILENAME ofn;
                ZeroMemory(&ofn, sizeof(ofn));
                char cRutaDelArchivo[MAX_PATH] = "";
                ofn.hwndOwner = hWnd;
                ofn.lStructSize = sizeof(ofn);
                ofn.lpstrFile = cRutaDelArchivo;
                ofn.nMaxFile = MAX_PATH;
                ofn.lpstrDefExt = "txt";
                ofn.Flags = OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
                ofn.lpstrFilter = "Solo imagenes\0*.bmp\0Solo texto\0*.txt\0Todos los archivos\0*.*\0";

                if (GetOpenFileName(&ofn)) {
                    strcpy_s(sRutaDelArchivoNP, cRutaDelArchivo);
                    HWND hPicImagen = GetDlgItem(hWnd, Cargar_Foto_Mecanico);
                    HBITMAP hBmImagen = (HBITMAP)LoadImage(NULL, sRutaDelArchivoNP, IMAGE_BITMAP, 170, 110, LR_LOADFROMFILE);
                    SendMessage(hPicImagen, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmImagen);
                }

                ruta = cRutaDelArchivo;
            }

            if (LOWORD(wParam) == btn_regresar_mecanicos && HIWORD(wParam) == BN_CLICKED) {
                hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                ShowWindow(hMenu_General, SW_SHOW);
                DestroyWindow(hWnd);
            }

            if (LOWORD(wParam) == lunes && HIWORD(wParam) == BN_CLICKED) {
                contadorlunes++;
            }

            if (LOWORD(wParam) == martes && HIWORD(wParam) == BN_CLICKED) {
                contadormartes++;
            }

            if (LOWORD(wParam) == miercoles && HIWORD(wParam) == BN_CLICKED) {
                contadormiercoles++;
            }

            if (LOWORD(wParam) == jueves && HIWORD(wParam) == BN_CLICKED) {
                contadorjueves++;
            }

            if (LOWORD(wParam) == viernes && HIWORD(wParam) == BN_CLICKED) {
                contadorviernes++;
            }
            
            if (LOWORD(wParam) == sabado && HIWORD(wParam) == BN_CLICKED) {
                contadorsabado++;
            }  
            
            if (LOWORD(wParam) == domingo && HIWORD(wParam) == BN_CLICKED) {
                contadordomingo++;
            }

            if (LOWORD(wParam) == btn_aceptar_mecanicos && HIWORD(wParam) == BN_CLICKED) {

                SendDlgItemMessageA(hWnd, edc_full_name_mecanico, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)NombreFull);
                SendDlgItemMessageA(hWnd, cmb_turno_mecanicos, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Turno); 
                SendDlgItemMessageA(hWnd, cmb_especialidades_mecanicos, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Especialidad);
                SendDlgItemMessageA(hWnd, edc_celular_mecanico, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)Celular);
                bool serepite = validarQueNoSeEmpalmenMecanicos(Turno, Especialidad);
                int longitud = strlen(Celular);

                //if (ruta.compare("") == 0 || strcmp(NombreFull, "") == 0) {
                //    MessageBoxA(hWnd, "Falto Llenar Datos", "ERROR", MB_ICONWARNING);
                //}

                if (longitud != 10) {
                   MessageBoxA(hWnd, "Numero de Celular de 10 Digitos c: ", "ERROR", MB_ICONWARNING);
                }

                //else if (contadorlunes % 2 == 0 && contadormartes % 2 == 0 && contadormiercoles % 2 == 0 && contadorjueves % 2 == 0 && contadorviernes % 2 == 0 && contadorsabado % 2 == 0 && contadordomingo % 2 == 0) {
                //    MessageBoxA(hWnd, "MINIMO TIENE QUE TRABAJAR 1 DIA -.-", "ERROR", MB_ICONWARNING);
                //}  

                else if (serepite == true) {
                    MessageBoxA(NULL, "YA EXISTE UN MECANICO EN DICHO HORARIO CON LA ESPECIALIDAD QUE REGISTRO", "ERROR DE DATOS", MB_ICONERROR);
                }

                else
                {     
                     if (Mnodoinicial == NULL) {

                          Mnodoinicial = new Mecanicos;
                          strcpy_s(Mnodoinicial->Turno_Trabajo, Turno);
                          strcpy_s(Mnodoinicial->Nombre_Completo_Empleado, NombreFull); 
                          strcpy_s(Mnodoinicial->Foto_Mecanicos, sRutaDelArchivoNP);
                          strcpy_s(Mnodoinicial->Especialidad_Mecanicos, Especialidad);  
                          strcpy_s(Mnodoinicial->Num_Celular_Mecanicos, Celular);
                          
                          Mnodoinicial->idMecanicos = Global_Mecanicos_Id++;
                          Mnodoinicial->Mprev = NULL;
                          Mnodoinicial->Mnext = NULL;
                          Mnodoactual = Mnodoinicial;
                          MessageBoxA(NULL, "Nuevo Mecanico Registrado", "NUEVO MECANICO", MB_OK);
                     }

                      else
                      {
                            while (Mnodoactual->Mnext != NULL)
                                Mnodoactual = Mnodoactual->Mnext;
                            Mnodoactual->Mnext = new Mecanicos;
                            Mnodoactual->Mnext->Mprev = Mnodoactual;
                            Mnodoactual = Mnodoactual->Mnext;
                            strcpy_s(Mnodoactual->Nombre_Completo_Empleado, NombreFull);
                            strcpy_s(Mnodoactual->Turno_Trabajo, Turno);
                            strcpy_s(Mnodoactual->Foto_Mecanicos, sRutaDelArchivoNP);
                            strcpy_s(Mnodoactual->Num_Celular_Mecanicos, Celular);
                            strcpy_s(Mnodoactual->Especialidad_Mecanicos, Especialidad);
                          
                            Mnodoactual->idMecanicos = Global_Mecanicos_Id++;
                            Mnodoactual->Mnext = NULL;
                            Mnodoactual = Mnodoinicial;
                            MessageBoxA(NULL, "Nuevo Usuario Registrado", "NUEVO Usuario", MB_OK);
                      }

                    contadorlunes = 0;
                    contadormartes = 0;
                    contadormiercoles = 0;
                    contadorjueves = 0;
                    contadorviernes = 0;
                    contadorsabado = 0;
                    contadordomingo = 0;
                    Guardar_Global_Id();
                    hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
                    ShowWindow(hMenu_General, SW_SHOW);
                    DestroyWindow(hWnd);
                }       
            }
        }break;
    }

    return FALSE;
}

BOOL CALLBACK Heap_Sort_CBack(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg) {
       case WM_INITDIALOG: {
        
           hMostrarDatosBefore = GetDlgItem(hWnd, list_before_ordenar_mecanicos2);
           if (Mnodoinicial != NULL) {
               int indice = 0;
               while (Mnodoactual != NULL) {
                   string datos;
                   datos.append("Nombre de Mecanico: ");
                   datos.append(Mnodoactual->Nombre_Completo_Empleado);
                   SendMessageA(hMostrarDatosBefore, LB_ADDSTRING, 0, (LPARAM)datos.c_str());
                   SendMessageA(hMostrarDatosBefore, LB_SETITEMDATA, (WPARAM)indice, (LPARAM)Mnodoactual->idMecanicos);
                   indice++;

                   if (Mnodoactual->Mnext == NULL) {
                       break;
                   }
                   Mnodoactual = Mnodoactual->Mnext;
               }
               Mnodoactual = Mnodoinicial;
           } 
       }break;

       case WM_COMMAND: {

           if (LOWORD(wParam) == ordenar_heapsort && HIWORD(wParam) == BN_CLICKED) { 

               txtfile.open("Datos\\Heap_apellido_Mecanicos.txt", ios::out | ios::trunc);

               int total_nodos = 0;
               string arreglo[sizeof(total_nodos)] = {};

               while (Mnodoactual->Mnext != NULL) {

                   arreglo[total_nodos] = Mnodoactual->Nombre_Completo_Empleado;
                   total_nodos++;
                   Mnodoactual = Mnodoactual->Mnext;
               }
               Mnodoactual = Mnodoinicial;

               vector<string> v(arreglo, arreglo + (total_nodos));
               make_heap(v.begin(), v.end());
               sort_heap(v.begin(), v.end());

               int total = 0;

               for (int i = 0; i < v.size(); i++) {
                   txtfile << v[i] << endl;
               }
               txtfile.close();

               HWND hHeap = GetDlgItem(hWnd, list_after_ordenar_mecanicos);
               for (int i = 0; i < v.size(); i++) {
                   string datos;
                   datos.append(v[i]);
                   SendMessageA(hHeap, LB_ADDSTRING, 0, (LPARAM)datos.c_str());
               }
           }

           if (LOWORD(wParam) == ultimo_regresar_xd && HIWORD(wParam) == BN_CLICKED) {
               int numero = quick();
               hMenu_General = CreateDialog(Global_Hinstance, MAKEINTRESOURCE(Ventana_General), NULL, Menu_General);
               ShowWindow(hMenu_General, SW_SHOW);
               DestroyWindow(hWnd);
           }
           
       }break;
    }
    return FALSE;
}

bool validarQueNoSeRepitanUsuarios(char* Palabra) {

    if (nodoactual != NULL) {

        while (strcmp(nodoactual->New_username, Palabra) != 0) {

            if (nodoactual->next == NULL) {

                return false;
            }
            nodoactual = nodoactual->next;
        }

        nodoactual = nodoinicial;
        return true;
    }
}

bool validarQueNoSeRepitaClavePacks(char* Palabra) {

    if (Pnodoactual != NULL) {

        while (strcmp(Pnodoactual->New_clave, Palabra) != 0) {

            if (Pnodoactual->Pnext == NULL) {

                return false;
            }
            Pnodoactual = Pnodoactual->Pnext;
        }

        Pnodoactual = Pnodoinicial;
        return true;
    }
}

bool validarEpaciosBlanco(char* Palabra) {

    int longitud = strlen(Palabra);
    unsigned int contador = 0;

    for (int i = 0; i < longitud; i++) {

        if (isspace(Palabra[i])) {
            contador++;
        }
    }

    if (contador > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

string ObtenerText(HWND hwnd) {

    int textLength = GetWindowTextLength(hwnd);

    if (textLength < 1) {
        return "";
    }

    else {
        char texto[99];
        GetWindowTextA(hwnd, texto, ++textLength);
        string text(texto);
        return text;
    }
}

float Convertir_String_A_Float(char* cadena) {

    float longitud = strlen(cadena);
    int contarpuntos = 0;
    int contador = 0;

    for (int i = 0; i < longitud; i++) {

        if ((int)cadena[i] == 46) {
            contarpuntos++;
        }

        else if (!isdigit(cadena[i])) {
            contador++;
        }

    }

    if (contarpuntos == 1 && contador == 0 || contarpuntos == 0 && contador == 0) {
        float numeroganador = atof(cadena);
        return numeroganador;
    }

    else
    {
        return 0;
    }
}

bool validarQueNoSeEmpalmenMecanicos(char* Turno, char* Especialidad) {

    if (Mnodoactual != NULL) {

        while (strcmp(Mnodoactual->Turno_Trabajo,Turno) != 0 || strcmp(Mnodoactual->Especialidad_Mecanicos, Especialidad) != 0){

            if (Mnodoactual->Mnext == NULL) {

                return false;
            }
            Mnodoactual = Mnodoactual->Mnext;
        }

        Mnodoactual = Mnodoinicial;
        return true;
    }
}

int validarQueNoSeEmpalmenMecanicosEdit(char* Turno, char* Especialidad, int id) {
 
    int n = 0;

    while (Mnodoactual != NULL) {

        if (strcmp(Mnodoactual->Especialidad_Mecanicos, Especialidad) == 0 && Mnodoactual->idMecanicos == id) {
           
        }

        else if (strcmp(Mnodoactual->Especialidad_Mecanicos, Especialidad) == 0 && strcmp(Mnodoactual->Turno_Trabajo, Turno) == 0) {
            n++;
        }

        Mnodoactual = Mnodoactual->Mnext;
    }
    Mnodoactual = Mnodoinicial;

    return n;
}

bool validar_horario_correcto_citas(string hora) {
 
    bool am;
    int wide = strlen(hora.c_str());

    for (int i = 0; i < wide; i++) {

        if (hora[i] == 'a') {
            am = true;
        }
        else if (hora[i] == 'p')
        {
            am = false;
        }
    }

    string nuevaH = hora.substr(0, 2);
    int n = atoi(nuevaH.c_str());
      
    if (am == false) {

        if (n == 1) {
            n = 13;
        }
        if (n == 2) {
            n = 14;
        }
        if (n == 3) {
            n = 15;
        }
        if (n == 4) {
            n = 16;
        }
        if (n == 5) {
            n = 17;
        }
        if (n == 6) {
            n = 18;
        }
        if (n == 7) {
            n = 19;
        }
        if (n == 8) {
            n = 20;
        }
        if (n == 9) {
            n = 21;
        }
        if (n == 10) {
            n = 22;
        }
        if (n == 11) {
            n = 23;
        } 
    }

    else if (am == true) {

        if (n == 12) {
            n = 24;
        }
    } 
  
    if (strcmp(Horario_Lab_Comp, "Mañana (8:00 a.m. - 16:00 p.m.)") == 0) {

        if (n >= 8 && n < 16 ) { 
            return false;
        }
         
        else
        {
            return true;
        }
    }

    else if (strcmp(Horario_Lab_Comp, "Tarde  (16:00 p.m. - 24:00 a.m.)") == 0) {

        if (n >= 16 && n < 24) {
            return false;
        }

        else
        {
            return true;
        }
    }

    else if (strcmp(Horario_Lab_Comp, "Madrugada (24:00 a.m. - 8:00 a.m.)") == 0) {
       
        if (n == 24) {
            return false;
        }

        else if (n >= 1 && n < 8) {
            return false;
        }

        else
        {
            return true;
        }
    }
}

bool editar_eliminar_mecanicos_despues_de_citas(char* Name) {

    int numero = 0;

     while (Citasnodoactual != NULL) {

         if (strcmp(Name, Citasnodoactual->Nombre_Mecanico_Cita) == 0) {
             
             numero++;
         }
         Citasnodoactual = Citasnodoactual->Citasnext;
     }

     Citasnodoactual = Citasnodoinicial;
    
    if (numero == 0) {
        return false;
    }
    else
    {
        return true;
    }
}

bool editar_eliminar_clientes_despues_de_citas(char* Name) {

    int numero = 0;

     while (Citasnodoactual != NULL) {

         if (strcmp(Name, Citasnodoactual->Nombre_Cliente_Cita) == 0) {
         
             numero++;
         }
         Citasnodoactual = Citasnodoactual->Citasnext;
     }
     
     Citasnodoactual = Citasnodoinicial;
    
    if (numero == 0) {
        return false;
    }
    else
    {
        return true;
    }
}

int quick() {

    txtfile.open("Datos\\Quick_Numeros_Clientes.txt", ios::out | ios::trunc);

    int total_nodos = 0;
    int arreglo[sizeof(total_nodos)] = {};

    while (Cnodoactual != NULL) {

        arreglo[total_nodos] = Cnodoactual->idClientes;
        total_nodos++;
        Cnodoactual = Cnodoactual->Cnext;
    }
    Cnodoactual = Cnodoinicial;
  
    quicksort(arreglo, 0, total_nodos - 1);

    for (int i = 0; i < total_nodos; i++) {
        
        txtfile << arreglo[i] << endl; 
    }

    txtfile.close();
    return 0;
}

void quicksort(int* a, int s, int e) {
    if (s < e) {
        int pind = partition(a, s, e);
        quicksort(a, s, pind - 1);
        quicksort(a, pind + 1, e);
    }
}

int partition(int* a, int s, int e) {

    int piviot = a[e];
    int pind = s;
    int i, t;

    for (i = s; i < e; i++) {
        if (a[i] <= piviot) {
            t = a[i];
            a[i] = a[pind];
            a[pind] = t;
            pind++;
        }
    }

    t = a[e];
    a[e] = a[pind];
    a[pind] = t;

    return pind;
}

bool eliminar_paquetes_despues_de_mecanicos(char* Name) {

    int numero = 0;

    while (Mnodoactual != NULL) {

        if (strcmp(Name, Mnodoactual->Especialidad_Mecanicos) == 0) {

            numero++;
        }
        Mnodoactual = Mnodoactual->Mnext;
    }

    Mnodoactual = Mnodoinicial;

    if (numero == 0) {
        return false;
    }
    else
    {
        return true;
    }
}

void InsertarMenu(HWND hWnd) {

    HMENU Columna1 = CreateMenu();
    HMENU Columna2 = CreateMenu();
    HMENU Columna3 = CreateMenu();
    HMENU Columna4 = CreateMenu();
    HMENU Columna5 = CreateMenu();
    HMENU Columna6 = CreateMenu();
    HMENU hMenu = CreateMenu();

    AppendMenu(Columna1, MF_STRING, Pestania_1, "Registrar");
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)Columna1, "Registrar Productos");

    AppendMenu(Columna2, MF_STRING, Pestania_2, "Registrar");
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)Columna2, "Registro de Usuarios");

   // AppendMenu(Columna3, MF_STRING, Pestania_3, "Registrar");
    //AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)Columna3, "Registro de Clientes");
    
    //AppendMenu(Columna4, MF_STRING, Pestania_4, "Registrar");
    //AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)Columna4, "Registro de Citas");

    //AppendMenu(Columna5, MF_STRING, Pestania_5, "Ver");
    //AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)Columna5, "Consultar Citas");

    AppendMenuA(Columna6, MF_STRING, pestania_6_1, "Quick Sort");
    AppendMenu(Columna6, MF_SEPARATOR, 0, NULL);
    AppendMenu(Columna6, MF_STRING, Pestania_6 , "Heap Sort");
    AppendMenu(hMenu, MF_STRING | MF_POPUP, (UINT)Columna6, "Ordenamiento"); 
  
    AppendMenu(hMenu, MF_STRING, salir_sistema_, "Salir");
    SetMenu(hWnd, hMenu);
}