#include<bits/stdc++.h>
using namespace std;
inline bool exists_test(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
int main(int argc,char **argv){
    char cmd[10000];
    sprintf(cmd,"g++ %s -o Temp -w -std=c++20 -O2",argv[1]);
    printf("\033[31mRunMan : start compiling.\033[0m\n");
    system(cmd);
    if(exists_test("./Temp")){
        printf("\033[32mRunMan : compile successfully, start running.\033[0m\n\n");
        system("./Temp");
        system("rm ./Temp");
        printf("\033[31m\nRunMan : finished.\033[0m\n");
    }else printf("\033[31m\nRunMan : compile failed.\033[0m\n");
}