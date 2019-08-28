<<<<<<< HEAD
#include <stdio.h>

int main (){
    printf("Hello World\n");
=======
#include "./libhello.h" //Librerias propias
//Los archivos .h sirven para generar librerias propias e importarlas en archivos terceros con funcionalidad y nombres propios


int main(int argc, char **argv)
{
    int i = 0;
    for(i = 1; i < argc; i++) {
        printHello(argv[i]);
    }
>>>>>>> 4a9083f9d22768d6d1f8e73a0f3acd2cf71afc12
    return 0;
}