#include<stdio.h>
void foo(){
	static int a = 2;
	printf("%d\n", a);
	a++;
}
int main(){
	int a =5;
	while(a--)
		foo();
	return 0;
}
