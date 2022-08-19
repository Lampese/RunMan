#include <bits/stdc++.h>
using namespace std;

char cmd[10000];
extern int optind,opterr,optopt;
extern char *optarg;
int getopt(int argc,char *const argv[],const char *optstring);



inline bool exists_test(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

int main(int argc, char **argv) {
    if(argc > 2) {
        printf("\033[31mNo more parameters can be recognized\033[0m\n");
    } else if(argc < 2) {
        printf("\033[31mRunMan : File not specified\033[0m\n");
    } else {
        sprintf(cmd, "g++ %s -o Temp -w -std=c++20 -O2", argv[1]);

        printf("\033[31mRunMan : start compiling.\033[0m\n");
        system(cmd);
        if(exists_test("./Temp")) {
            printf("\033[32mRunMan : compile successfully, start running.\033[0m\n\n");

            system("./Temp");
            system("rm ./Temp");

            printf("\033[31m\nRunMan : finished.\033[0m\n");
        }else 
            printf("\033[31m\nRunMan : compile failed.\033[0m\n");

    }    
    return EXIT_SUCCESS;
}