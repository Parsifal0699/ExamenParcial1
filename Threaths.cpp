#include <iostream>
#include <fstream>
#include <thread>
using namespace std;
#include <mutex>
mutex mut;
void escribir1() {
    mut.lock();

    ofstream archivo("texto.txt", ios::app);
    archivo << "Linea 1" << endl;
    archivo.close();

    mut.unlock();
}
void escribir2() {
    mut.lock();

    ofstream archivo("texto.txt", ios::app);
    archivo << "Linea 2" << endl;
    archivo.close();

    mut.unlock();
}
void escribir3() {
    mut.lock();
    ofstream archivo("texto.txt", ios::app);
    archivo << "Linea 3" << endl;
    archivo.close();
    mut.unlock();
}
void escribir4() {
    mut.lock();
    ofstream archivo("texto.txt", ios::app);
    archivo << "Linea 4" << endl;
    archivo.close();
    mut.unlock();
}
void escribir5() {
    mut.lock();
    ofstream archivo("texto.txt", ios::app);
    archivo << "Linea 5" << endl;
    archivo.close();
    mut.unlock();
}
int main() {
    thread t1(escribir1);
    thread t2(escribir2);
    thread t3(escribir3);
    thread t4(escribir4);
    thread t5(escribir5);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}