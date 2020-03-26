#include "setLinked.cpp"
#include <fstream>

int main(){

    fstream file1, file2;
    file1.open("ascending", ios::out);
    file2.open("descending", ios::out);

    if((file1.good() != true) || (file2.good() != true)){
        cout << "File error" << endl;
        return 0;
    }

    int i, j, k;
    linkedSet mySet;

    clock_t start, end;

    for(i = 1; i <= 300; i++){
        start = clock();
        for(j = 1; j <= i; j++){
            for(k = 1; k < 4; k++){
            mySet.insertValue(j);
            }
        }
        end = clock();
        file1 << i << " " << end - start << endl;
    }

    file1.close();

    for(i = 300; i >= 1; i--){
        start = clock();
        for(j = 1; j <= i; j++){
            for(k = 1; k < 4; k++){
            mySet.insertValue(j);
            }
        }
        end = clock();
        file2 << i << " " << end - start << endl;
    }

    file2.close();

return 0;
}
