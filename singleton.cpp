#include<iostream>

using namespace std;

class singleton{

    private:
        static singleton* instance ;
        int i;
        //private constructor
        singleton(){}
        singleton(const singleton&){}
        singleton &operator=(singleton&){}
    public:
        static singleton* getInstance(){
            if (instance == NULL){
                instance = new singleton();
            }
            return instance;
        }
};


singleton* singleton::instance = NULL;

int main(){
    cout << "SingleTon" << endl;

    singleton *sig1 = singleton::getInstance();
    singleton *sig2 = singleton::getInstance();

    cout << " pointer : " <<(unsigned long long)sig1 << endl;
    cout << " pointer : " <<(unsigned long long)sig2 << endl;
    return 0;
}