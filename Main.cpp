#include<bits/stdc++.h>
#include "./opt.h"
using namespace std;
inline bool exists_test(const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}
string stdc="c++20";
bool debug_yes=false;
inline void run(const std::string& name){
    char cmd[10000];
    if(debug_yes)sprintf(cmd,"g++ %s -o Temp -w -std=%s -O2 -g",name.c_str(),stdc.c_str());
    else sprintf(cmd,"g++ %s -o Temp -w -std=%s -O2",name.c_str(),stdc.c_str());
    printf("\033[31mRunMan : start compiling.\033[0m\n");
    system(cmd);
    if(exists_test("./Temp")){
        printf("\033[32mRunMan : compile successfully, start running.\033[0m\n\n");
        if(debug_yes)system("gdb ./Temp");
        else system("./Temp");
        system("rm ./Temp");
        printf("\033[31m\nRunMan : finished.\033[0m\n");
    }else printf("\033[31m\nRunMan : compile failed.\033[0m\n");
}
inline void help(){
    cout<<R"( ____              __  __             
|  _ \ _   _ _ __ |  \/  | __ _ _ __  
| |_) | | | | '_ \| |\/| |/ _` | '_ \ 
|  _ <| |_| | | | | |  | | (_| | | | |
|_| \_\\__,_|_| |_|_|  |_|\__,_|_| |_|
   RunMan v0.2 by Lampese 2022/8/21   
   --help/-h                get help.
   --std/-s                 set stand of g++ (default is c++20).
   --debug/-d               compile and open by gdb.
   filename                 the name of .cpp.
)";
}
int main(int argc,char **argv){
    string filename;
    std::vector<std::string>args(argc-1);
    std::map<std::string, std::string>alias;
    alias["--help"]="-h";
    alias["--std"]="-s";
    alias["--debug"]="-d";
    for(size_t i=1;i<argc;++i)args[i-1]=string(argv[i]);
    LampOpt::Arguments arg(args, alias);
    if(arg.args.empty()){
        std::cout<<"no arguments given."<<std::endl;
        return EXIT_FAILURE;
    }
    if(arg.args.find("-h")!=arg.args.end()){
        help();
        return EXIT_SUCCESS;
    }
    if(arg.args.find("-s")!=arg.args.end()){
        stdc=arg.args.find("-s")->second;
        stdc.erase(stdc.begin());
        arg.args.erase("-s");
    }
    if(arg.args.find("-d")!=arg.args.end()){
        debug_yes=true;
        arg.args.erase("-d");
    }
    if(!arg.args.empty())
        filename=arg.args.begin()->first;
    run(filename);
}