#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

int main (int argc , char ** argv){
    char instruccion[50];
    char instruccion2[50];
    struct stat archInfo;
    struct dirent* dirInfo;
    DIR* dir;
    if (argc == 2){

        mkdir(argv[1],0777);
        
        sprintf(instruccion,"echo 'Karen Iveth Plata Hernandez' >> ./%s/%s.txt",argv[1],argv[2]);
        system(instruccion);
        sprintf(instruccion,"echo 'Luis Enrique Contreras Vazquez' >> ./%s/%s.txt",argv[1],argv[2]);
        system(instruccion);
        sprintf(instruccion,"echo 'Jose Antonio Cortes Olmos' >> ./%s/%s.txt",argv[1],argv[2]);
        system(instruccion);
        sprintf(instruccion,"echo 'Ivan Melchor Santiago' >> ./%s/%s.txt",argv[1],argv[2]);
        system(instruccion);
        sprintf(instruccion,"echo 'Edgar Hernandez Millan' >> ./%s/%s.txt",argv[1],argv[2]);
        system(instruccion);

	sprintf(instruccion,"./%s/%s.txt",argv[1],argv[2]);
    sprintf(instruccion2,"./%sf.txt",argv[2]);
	link(instruccion,instruccion2);

    sprintf(instruccion2,"./%sv.txt",argv[2]);
	symlink(instruccion,instruccion2);

    
    stat(instruccion,& archInfo);
    printf("---Datos archivo---\n");
    printf("Inodo : %ld\n ",archInfo.st_ino);
    printf("Tamaño : %ld Bytes\n ",archInfo.st_size);
    printf("#Links : %ld\n ",archInfo.st_nlink);

    dir=opendir("./");
    dirInfo = readdir(dir);
    printf("---Datos directorio---\n");
    printf("Inodo : %ld\n ",dirInfo->d_ino);
    printf("Nombre : %s\n ",dirInfo->d_name);


    }
    else{
        printf("Coloque un solo nombre para la carpeta");
    }
}
