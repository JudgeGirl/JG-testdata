#include <stdio.h>
#include "value.h"

int main(){
		int type, width, height, length;
			while( scanf("%d%d%d%d", &type, &width, &height, &length) != EOF)
						printf("The metal value is %d.\n", value(type,width,height,length));
		return 0;
}
