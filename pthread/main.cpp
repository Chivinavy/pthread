#include <iostream>
#include <ctime>
#include "saveandsave.h"


using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    clock_t start, finish;
    start = clock();
    cout << "Сумма высчитанная в одном потоке: " << Solo() << endl;
    finish = clock();
    cout << "Один поток посчитал сумму чисел во всех файлах за: " << (finish - start) / 1000.0 << endl;
    start = clock();
    cout << "Сумма высчитанная в 5 потоках: " << Multi() << endl;
    finish = clock();
    cout << "10 потоков посчитали сумму чисел во всех файлах за: " << (finish - start) / 1000.0 << endl;
    return 0;
}