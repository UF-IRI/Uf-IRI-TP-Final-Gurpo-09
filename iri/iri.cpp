#pragma once

#include <string>
#include <cstring>
#include <regex>

std::string BASE_PATH = "..\\..\\..\\";
std::string FOLDER_PATH = "data_files\\input\\";

// Expresiones Regulares (REGEX)

    // Expresion regular para numeros
    // Cantidad de valores 1
    std::string reg_numero = "(\\d+)";

    // Expresion regular para palabras
    // Cantidad de valores 1 (devuelve un string)
    std::string reg_palabra = "(\\w|\\s{1,})";

    // Expresion regular para fechas (dd/mm/yyyy :: dia/mes/año)
    // Cantidad de valores 4
    // val 1 = fecha completa
    // val 2 = dia
    // val 3 = mes
    // val 4 = año
    std::string reg_fecha = "(([0-2][0-9]|3[0-1])\\/(0[0-9]|1[0-2])\\/(\\d{4}))";

    // Expresion regular para matricula medico
    // Cantidad de valores 1
    std::string reg_matricula_medico = "(\\d+\\-\\d+\\-\\d+)";

    // Expresion regular para telefono/celular
    // Cantidad de valores 1
    std::string reg_telefono = "(\\+54\\s\\(\\d+\\)\\s\\d+)";

    // Expresion regular para mail
    // Cantidad de valores 1
    std::string reg_mail = "(\\w+\\@\\w+\\.\\w+)";

    // Expresion regular para booleano
    // Cantidad de valores 1
    std::string reg_booleano = "(\\d)";

    bool regex_2_bool(std::string regex_value) {
        return astd::stoi(regex_value) ? true : false;
    }