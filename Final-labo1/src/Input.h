/*
 * Input.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Neri y Valen
 */

#ifndef INPUT_H_
#define INPUT_H_



int systemPause(char* message);
/// @fn int pedirNumero(int*, char*, char*, int, int)
/// @brief Se encarga de pedir un numero entero y validarlo.
///
/// @param Un puntero a enterp
/// @param Un puntero a char
/// @param Un puntero a char
/// @param Un entero
/// @param Un entero
/// @return int
int pedirNumero(int* num,char* mensaje,char* mensajeError,int min, int max);
/// @fn int pedirNumeroFlotante(float*, char*, char*, int, int)
/// @brief Se encarga de pedir un numero flotante y validarlo.
///
/// @param Un puntero a flotante
/// @param Un puntero a char
/// @param Un puntero a char
/// @param Un entero
/// @param Un entero
/// @return int
int pedirNumeroFlotante(float* num, char* mensaje, char* mensajeError, int min, int max);
/// @fn int validarEspacios (char *)
/// @brief Funcion que se encarga de validar los espacios, tabulaciones, etc
///
/// @param Un puntero a char
/// @return int
int validarEspacios(char* string);
/// @fn int pedirNombreCompleto(char*, char*, char*, int)
/// @brief Se encarga de pedir una cadena y validarla
///
/// @param un puntero a char
/// @param un puntero a char
/// @param un puntero a char
/// @param un entero
/// @return int
int pedirNombreCompleto(char* string,char* mensaje,char* mensajeError,int max);
/// @fn int validarCadena (char *)
/// @brief Funcion que valida que solo haya letras en una cadena
///
/// @param un puntero a char
/// @return int
int validarCadena(char* string);
/// @fn int pedirNumeroAcompanado (char *)
/// @brief Funcion que se encarga de pedir numeros validando que puedan tener signos, operadores, etc
///
/// @param Un puntero a char
/// @return int
int pedirNumeroAcompanado(char* string);
/// @fn int transformarMayus (char *)
/// @brief Funcion que se encarga de pasar una cadena de caracteres a letras minusculas
///
/// @param Un puntero a char
/// @return int
int transformarMayus(char* string);




#endif /* INPUT_H_ */
