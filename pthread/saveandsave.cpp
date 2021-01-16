#include <iostream>
#include <fstream>
#include <sstream>
#include <pthread.h>
#include "saveandsave.h"

using namespace std;


long Solo() 
{
    stringstream x;
    long sum = 0;
    int i = 1;
    while (i <= 10) 
    {
        x << "..\\Files\\" << i << ".txt";
        ifstream fout(x.str());
        x.str(string());
        long num;
        fout >> num;
        sum += num;
        while (!fout.eof()) {
            fout >> num;
            sum += num;
        }
        fout.close();
        i++ ;
    }
    return sum;
}
void* GetSum(void* Types_one) 
{
    int num = 0;
    stringstream x;
    ifstream input;
    Types* data = (Types*)Types_one;
    x << "..\\Files\\" << data->file << ".txt";
    input.open(x.str());
    x.str(string());
    input >> num;
    data->sum = data->sum + num;
    while (!input.eof()) {
        input >> num;
        data->sum = data->sum + num;
    }
    input.close();
    return nullptr;
}


long Multi() 
{
    long Sum = 0;
    pthread_t threads[5];
    Types* data = new Types[10];
    int i = 1;
    while (i<= 5) 
    {
        data[i].file = i;
        data[i].sum = 0;
        pthread_create(&(threads[i]), nullptr, GetSum, &data[i]);
        i++;
    }
    i = 1;
    while (i <= 10)
    {
        pthread_join(threads[i], nullptr);
        Sum += data[i].sum;
        i++;
    }
    delete[] data;
    return Sum;
}