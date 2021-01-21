#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    int row, column;
    int tetris[45][45];
    int start, dir;
    int flag = 0, flag1 = 0;

    string kind;
    ifstream fin;
    fin.open(argv[1]);
    char N[10];
    fin.getline(N,10);
    stringstream ss(N);
    ss>>column>>row;

    for(int a=0;a<=15;a++){
        for(int b=0;b<=40;b++)
            tetris[a][b] = -1;
    }

    //cin >> column >> row;

    for(int a=1;a<=row;a++){
        for(int b=1;b<=column;b++)
            tetris[a][b] = 0;
    }

    while(!fin.eof()){
        char a[100];
        fin.getline(a,10);
        stringstream ss(a);
        ss>>kind;
        ss>>start;
        ss>>dir;
        if(kind == "End")
            break;
        else
            //cin >> start >> dir;
        if(kind == "T1"){
            for(int a=2;;a++){
                if(tetris[start+1][a] != 0 || tetris[start][a-1] != 0 || tetris[start+1][a-1] != 0 || tetris[start+2][a-1] != 0){
                    if(tetris[start+1+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+2+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+1+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+2+dir][a-2+b] != 0){
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+2+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "T2"){
            for(int a=3;;a++){
                if(tetris[start+1][a] != 0 || tetris[start][a-1] != 0 || tetris[start+1][a-1] != 0 || tetris[start+1][a-2] != 0){
                    if(tetris[start+1+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+1+dir][a-3] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+1+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+1+dir][a-3+b] != 0){
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-3+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "T3"){
            for(int a=2;;a++){
                if(tetris[start][a] != 0 || tetris[start+1][a] != 0 || tetris[start+2][a] != 0 || tetris[start+1][a-1] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+1+dir][a-1] == 0 && tetris[start+2+dir][a-1] == 0 && tetris[start+1+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+1+dir][a-1+b] != 0 || tetris[start+2+dir][a-1+b] != 0 || tetris[start+1+dir][a-2+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+2+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "T4"){
            for(int a=3;;a++){
                if(tetris[start][a] != 0 || tetris[start][a-1] != 0 || tetris[start][a-2] != 0 || tetris[start+1][a-1] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+dir][a-3] == 0 && tetris[start+1+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+dir][a-3+b] != 0 || tetris[start+1+dir][a-2+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+dir][a-3+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "L1"){
            for(int a=3;;a++){
                if(tetris[start][a] != 0 || tetris[start][a-1] != 0 || tetris[start][a-2] != 0 || tetris[start+1][a] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+dir][a-3] == 0 && tetris[start+1+dir][a-1] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+dir][a-3+b] != 0 || tetris[start+1+dir][a-1+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+dir][a-3+b-1] = 1;
                                tetris[start+1+dir][a-1+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "L2"){
            for(int a=2;;a++){
                if(tetris[start][a] != 0 || tetris[start][a-1] != 0 || tetris[start+1][a-1] != 0 || tetris[start+2][a-1] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+2+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+2+dir][a-2+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+2+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "L3"){
            for(int a=3;;a++){
                if(tetris[start+1][a] != 0 || tetris[start+1][a-1] != 0 || tetris[start][a-2] != 0 || tetris[start+1][a-2] != 0){
                    if(tetris[start+1+dir][a-1] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+dir][a-3] == 0 && tetris[start+1+dir][a-3] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+1+dir][a-1+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+dir][a-3+b] != 0 || tetris[start+1+dir][a-3+b] != 0){
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+dir][a-3+b-1] = 1;
                                tetris[start+1+dir][a-3+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "L4"){
            for(int a=2;;a++){
                if(tetris[start][a] != 0 || tetris[start+1][a] != 0 || tetris[start+2][a] != 0 || tetris[start+2][a-1] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+1+dir][a-1] == 0 && tetris[start+2+dir][a-1] == 0 && tetris[start+2+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+1+dir][a-1+b] != 0 || tetris[start+2+dir][a-1+b] != 0 || tetris[start+2+dir][a-2+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+2+dir][a-1+b-1] = 1;
                                tetris[start+2+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "J1"){
            for(int a=3;;a++){
                if(tetris[start][a] != 0 || tetris[start+1][a] != 0 || tetris[start+1][a-1] != 0 || tetris[start+1][a-2] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+1+dir][a-1] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+1+dir][a-3] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+1+dir][a-1+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+1+dir][a-3+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-3+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "J2"){
            for(int a=2;;a++){
                if(tetris[start][a] != 0 || tetris[start+1][a] != 0 || tetris[start+2][a] != 0 || tetris[start][a-1] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+1+dir][a-1] == 0 && tetris[start+2+dir][a-1] == 0 && tetris[start+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+1+dir][a-1+b] != 0 || tetris[start+2+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+2+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "J3"){
            for(int a=3;;a++){
                if(tetris[start][a] != 0 || tetris[start][a-1] != 0 || tetris[start][a-2] != 0 || tetris[start+1][a-2] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+dir][a-3] == 0 && tetris[start+1+dir][a-3] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+dir][a-3+b] != 0 || tetris[start+1+dir][a-3+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+dir][a-3+b-1] = 1;
                                tetris[start+1+dir][a-3+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "J4"){
            for(int a=2;;a++){
                if(tetris[start+2][a] != 0 || tetris[start][a-1] != 0 || tetris[start+1][a-1] != 0 || tetris[start+2][a-1] != 0){
                    if(tetris[start+2+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+2+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+2+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+2+dir][a-2+b] != 0){
                                tetris[start+2+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+2+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "S1"){
            for(int a=2;;a++){
                if(tetris[start][a] != 0 || tetris[start+1][a] != 0 || tetris[start+1][a-1] != 0 || tetris[start+2][a-1] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+1+dir][a-1] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+2+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+1+dir][a-1+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+2+dir][a-2+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+2+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "S2"){
            for(int a=3;;a++){
                if(tetris[start+1][a] != 0 || tetris[start][a-1] != 0 || tetris[start+1][a-1] != 0 || tetris[start][a-2] != 0){
                    if(tetris[start+1+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+dir][a-3] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+1+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+dir][a-3+b] != 0){
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+dir][a-3+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "Z1"){
            for(int a=2;;a++){
                if(tetris[start+1][a] != 0 || tetris[start+2][a] != 0 || tetris[start][a-1] != 0 || tetris[start+1][a-1] != 0){
                    if(tetris[start+1+dir][a-1] == 0 && tetris[start+2+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+1+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+1+dir][a-1+b] != 0 || tetris[start+2+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+1+dir][a-2+b] != 0){
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+2+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "Z2"){
            for(int a=3;;a++){
                if(tetris[start][a] != 0 || tetris[start][a-1] != 0 || tetris[start+1][a-1] != 0 || tetris[start+1][a-2] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+1+dir][a-2] == 0 && tetris[start+1+dir][a-3] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+1+dir][a-2+b] != 0 || tetris[start+1+dir][a-3+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-3+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "I1"){
            for(int a=4;;a++){
                if(tetris[start][a] != 0 || tetris[start][a-1] != 0 || tetris[start][a-2] != 0 || tetris[start][a-3] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+dir][a-3] == 0 && tetris[start+dir][a-4] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+dir][a-3+b] != 0 || tetris[start+dir][a-4+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+dir][a-3+b-1] = 1;
                                tetris[start+dir][a-4+b-1] = 1;
                                flag1 = 1;
                            break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "I2"){
            for(int a=1;;a++){
                if(tetris[start][a] != 0 || tetris[start+1][a] != 0 || tetris[start+2][a] != 0 || tetris[start+3][a] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+1+dir][a-1] == 0 && tetris[start+2+dir][a-1] == 0 && tetris[start+3+dir][a-1] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+1+dir][a-1+b] != 0 || tetris[start+2+dir][a-1+b] != 0 || tetris[start+3+dir][a-1+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+2+dir][a-1+b-1] = 1;
                                tetris[start+3+dir][a-1+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }
        else if(kind == "O"){
            for(int a=2;;a++){
                if(tetris[start][a] != 0 || tetris[start+1][a] != 0 || tetris[start][a-1] != 0 || tetris[start+1][a-1] != 0){
                    if(tetris[start+dir][a-1] == 0 && tetris[start+1+dir][a-1] == 0 && tetris[start+dir][a-2] == 0 && tetris[start+1+dir][a-2] == 0){
                        for(int b=1;;b++){
                            if(tetris[start+dir][a-1+b] != 0 || tetris[start+1+dir][a-1+b] != 0 || tetris[start+dir][a-2+b] != 0 || tetris[start+1+dir][a-2+b] != 0){
                                tetris[start+dir][a-1+b-1] = 1;
                                tetris[start+1+dir][a-1+b-1] = 1;
                                tetris[start+dir][a-2+b-1] = 1;
                                tetris[start+1+dir][a-2+b-1] = 1;
                                flag1 = 1;
                                break;
                            }
                        }
                        if(flag1 == 1){
                            flag1 = 0;
                            break;
                        }
                    }
                    else{
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
            }
        }

        for(int a=1;a<=column;a++){
            for(int b=1;b<=row;b++){
                if(tetris[b][a] == 0){
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                for(int b=1;b<=row;b++){
                    for(int c=a;c>=2;c--)
                        tetris[b][c] = tetris[b][c-1];
                }
                for(int b=1;b<=row;b++)
                    tetris[b][1] = 0;
            }
            flag = 0;
        }
    }

    ofstream cout("108062303_proj1.final");
    for(int a=1;a<=column;a++){
        for(int b=1;b<=row;b++)
            cout << tetris[b][a] << ' ';
        cout << endl;
    }

    return 0;
}
