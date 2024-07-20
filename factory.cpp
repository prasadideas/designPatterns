#include <iostream>
using namespace std;

enum VechicleType{
    VT_TwoWheeler,
    VT_ThreeWheeler,
    VT_FourWheeler
};

class Vehicle
{
public:
    virtual void printVehicle() = 0;
};

class TwoWheeler : public Vehicle
{
public:
    void printVehicle(){
        cout << " this is two wheeler"<< endl;
    }
};

class ThreeWheeler : public Vehicle
{
public:
    void printVehicle(){
        cout << " this is three wheeler"<< endl;
    }
};

class FourWheeler : public Vehicle
{
public:
    void printVehicle(){
        cout << " this is Four wheeler"<< endl;
    }
};


class Factory{
    public:
        Factory(){
            cout << "I am Factory" << endl;
        }
    static Vehicle* Create(VechicleType Type){
        if ( Type == VT_TwoWheeler){
            return new TwoWheeler();
        }
        else if(Type == VT_ThreeWheeler){
            return new ThreeWheeler();
        }
        else if(Type == VT_FourWheeler){
            return new FourWheeler();
        }
    }
};

int main(){
    

    Vehicle* twowheeler = Factory::Create(VT_TwoWheeler);
    Vehicle* threewheeler = Factory::Create(VT_ThreeWheeler);
    Vehicle* fourwheeler = Factory::Create(VT_FourWheeler);

    twowheeler->printVehicle();
    threewheeler->printVehicle();
    fourwheeler->printVehicle();

    return 0;
}

