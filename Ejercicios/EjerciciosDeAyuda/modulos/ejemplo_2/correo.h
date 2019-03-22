#ifndef correo_h
#define correo_h
#include <string>

typedef struct{
    int id;
    std::string asunto;
    std::string mensaje;
}tCorreo;

void leerCorreo(const tCorreo correo);

#endif