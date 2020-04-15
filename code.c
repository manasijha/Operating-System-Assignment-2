#coded_by_3cl1pS3

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
pid_t pid;
char a[1000];
int a1[2];
int a2[2];

if (pipe(a1)==-1) { 
fprintf(stderr, "Pipe Failed" ); 
return 1; 
} 
pipe(a2);
if (pipe(a2)==-1) { 
fprintf(stderr, "Pipe Failed" ); 
return 1; 
}
pid = fork();
if (pid < 0) { 
fprintf(stderr, "Fork Failed" ); 
return 1; 
} 
if (pid > 0) {
int i;
close(a1[1]); 
read(a1[0], a, sizeof(a));
for(i = 0; i<sizeof(a); i++) {
if((int)a[i]>=65 && (int)a[i]<=90){
a[i]=(int)a[i]+32;
}
else if((int)a[i]>=97 && (int)a[i]<=122){
a[i]=(int)a[i]-32;
}
}
write(a2[1], a, strlen(a) + 1);
wait(NULL); 
}
else if (pid == 0){
close(a1[0]); 
printf("input: ");
fgets(a, sizeof(a), stdin);
printf("%s", a);

write(a1[1], a, strlen(a) + 1);
read(a2[0], a, sizeof(a));
printf(" %s",a);
exit(0);
}
return 0;
}
