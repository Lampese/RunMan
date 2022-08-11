#include<bits/stdc++.h>
int main(int argc,char **argv){
    char cmd[10000];
    sprintf(cmd,"g++ %s -o Temp -w -std=c++20 -O2",argv[1]);
    printf("\033[31mRunMan : start compiling.\033[0m\n");
    system(cmd);
    printf("\033[32mRunMan : compile successfully, start running.\033[0m\n\n");
    system("./Temp");
    system("rm ./Temp");
    printf("\033[31m\nRunMan : finished.\033[0m\n");
}