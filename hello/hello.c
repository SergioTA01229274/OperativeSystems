#include "./libhello.h" //Librerias propias
//Los archivos .h sirven para generar librerias propias e importarlas en archivos terceros con funcionalidad y nombres propios


int main(int argc, char **argv)
{
    int i = 0;
    for(i = 1; i < argc; i++) {
        printHello(argv[i]);
    }
    return 0;
}