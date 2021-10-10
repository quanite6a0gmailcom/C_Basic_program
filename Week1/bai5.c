#include <string.h>

int main(int argc,char *argv[]){
	double width,height;
	if (argc!=3){
		printf("Wrong number of arguments!\n");
		return 1;
	}
	width=atof(argv[1]);
	height=atof(argv[2]);
	printf("The rectanghe's area is %f\n",width *height);
	printf("The rectanghe's perimeter is %f\n",2*(width + height));
	return 0;
}
