#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"

int
main(int argc, char *argv[])
{
	int deleted_count = 0;
	int i,j;
	char* result = malloc(64*(DIRSIZ+1));

	if(argc < 2){
		deleted_count = lsdel(".",result);
		if(deleted_count == 0) {
			printf("Nema obrisanih datoteka.\n");
		} else if(deleted_count == -1){
			printf("Navedena putanja nije validna!\n");
		} else {
			//TODO
			for(j=0; j<deleted_count; j++){
				printf("%s",&result[j]);
			}
			printf("%d \n",deleted_count);
		}
	} 
	for(i=1; i<argc; i++){
		deleted_count = lsdel(argv[i],result);
		if(deleted_count == 0) {
			printf("Nema obrisanih datoteka.\n");
		} else if(deleted_count == -1){
			printf("Navedena putanja nije validna!\n");
		} else {
			//TODO 
			
			// for(j=0; j<deleted_count; j++){
			// 	printf("%s",&result[j]);
			// }
			
			printf("%d\n",deleted_count);
		}
	}
	
	exit();
}
