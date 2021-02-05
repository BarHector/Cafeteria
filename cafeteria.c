#include <stdbool.h>
#include <stdio.h>

int acuCafe=0; 
int acuTe=0;
int cantidadc=0; 
int cantidadt=0; 
int donas=0; 
int total=0; 
int acuPago=0; 
int opcionUno =0; 
int opcionDos =0; 
int opcionTres =0; 
bool opcion = true; 

int cafe(); 
int te(); 

int main(){ 
    FILE *myFile = NULL; //Lectura de archivo
    myFile = fopen("miArchivo2.txt", "r+"); //Abriendo archivo y leyendolo
    char caracter; //delcaracion de variable caracter
	if (myFile==NULL){ //Si el archivo es nulo
	    printf("No fue posible dar la bienvenida\n"); //Imprimira
	    return -1; //Regresa
	} 
    while((caracter = fgetc(myFile)) !=EOF){ //mientras la variable caracter en el archivo
		printf("%c", caracter); //Lo mantendra igual
    } //Fin del while
    fclose(myFile); //Cerrar el archivo
    printf("\n"); 

    while(opcion){ 
        printf("\n"); 
        printf("¿Que quiere? \n1. Cafe \n2. Te \n3. Pagar\n"); 
        fflush(stdin); 
        scanf("%d", &opcionUno); 
            switch(opcionUno){ 
                case 1: printf("¿Que cafe desea? \n"); 
                        printf("1. Descafeinado \n2. Express \n3. Americano \n4. Latte \n"); 
                        fflush(stdin); 
                        scanf("%d", &opcionDos); 
                        switch(opcionDos){ 
                            case 1: printf("Descafeinado "); 
                                    cafe(); 
                                    break; 
                            case 2: printf("Express "); 
                                    cafe(); 
                                    break; 
                            case 3: printf("Americano "); 
                                    cafe(); 
                                    break; 
                            case 4: printf("Latte "); 
                                    cafe(); 
                                    break; 
                            default:printf("No entendi su orden\n"); 
                                    break; 
                        } 
                        break; 
                case 2: printf("Que te desea? \n"); 
                        printf("1. Manzanilla \n2. Limon \n3. Frutos rojos \n4. Negro \n"); 
                        fflush(stdin); 
                        scanf("%d", &opcionDos); 
                        switch(opcionDos){ 
                            case 1: printf("Te de Manzanilla "); 
                                    te(); 
                                    break; 
                            case 2: printf("Te de Limon "); 
                                    te(); 
                                    break; 
                            case 3: printf("Te de Frutos Rojos "); 
                                    te(); 
                                    break; 
                            case 4: printf("Te negro "); 
                                    te(); 
                                    break;
                            default: printf("No entendi su orden\n"); 
                                    break; 
                        } 
                        break;
                case 3: opcion = false; 
                        break; 
                default: printf("No entendi su orden\n"); 
                        break; 
            }
    } 
    if (acuPago > 100){ 
        for (int i=0; i<=acuPago; i+=10){ 
            donas = (i-100)/10; 
        } 
    } 
    printf("********************* \n"); 
    printf("%d cafe(s) pedido(s) \n", acuCafe); 
    printf("%d te(s) pedido(s) \n", acuTe); 
    printf("$ %d total a pagar \n", acuPago); 
    printf("%d donas de regalo \n", donas); 
    printf("********************* \n"); 
    return 0; 
} 

int cafe(){ 
    printf("De que tamano? \n1. Chico a $15 \n2. Mediano a $20 \n3. Grande a $25 \n"); 
    scanf("%d", &opcionTres);
    switch(opcionTres){ 
        case 1: printf("¿Cuantos quieres? \n"); 
                scanf("%d", &cantidadc); 
                total = cantidadc * 15; 
                break; 
        case 2: printf("¿Cuantos quieres? \n"); 
                scanf("%d", &cantidadc); 
                total = cantidadc * 20; 
                break; 
        case 3: printf("¿Cuantos quieres? \n"); 
                scanf("%d", &cantidadc); 
                total = cantidadc * 25; 
                break; 
        default:printf("Solo tenemos esos tamaños \n"); 
                break; 
        } 
    acuPago += total; 
    acuCafe += cantidadc;
    return acuPago, acuCafe; 
} 

int te(){ 
    printf("de que tamano? \n1. Chico a $12 \n2. Mediano a $17 \n3. Grande a $22 \n"); 
    scanf("%d", &opcionTres); 
    switch(opcionTres){ 
        case 1: printf("¿Cuantos quieres? \n");
                scanf("%d", &cantidadt); 
                total = cantidadt * 12; 
                break; 
        case 2: printf("¿Cuantos quieres? \n"); 
                scanf("%d", &cantidadt); 
                total = cantidadt * 17; 
                break; 
        case 3: printf("¿Cuantos quieres? \n"); 
                scanf("%d", &cantidadt); 
                total = cantidadt * 22; 
                break; 
        default:printf("Solo tenemos esos tamaños \n"); 
                break; 
    } 
    acuPago += total;
    acuTe += cantidadt; 
    return acuPago, acuTe; 
} 