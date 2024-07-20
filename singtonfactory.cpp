#include <iostream>

using namespace std;

enum DatabaseType{
    Db1,Db2,Db3
};

//Interface
class IDatabase{
    public:
     virtual void DBConnect() = 0;
};

//singlton class
class cDatabase1 : public IDatabase{
    private:
        static cDatabase1* instance;
        int i;
        cDatabase1(){i=0;}
        cDatabase1(const cDatabase1&){}

    public:
        static cDatabase1* getInstance(){
            if(instance ==NULL){
                instance = new cDatabase1();
                cout << "singleton Object for cDatabse1 is created" << endl;
            }
            return instance;
        }
        void DBConnect(){
            i++;
            cout << "DB1 connection : "<< i << endl;
        }
};
cDatabase1* cDatabase1::instance = NULL;

//singlton class
class cDatabase2 : public IDatabase{
    private:
        static cDatabase2* instance;
        int i;
        cDatabase2(){i=0;}
        cDatabase2(const cDatabase2&){}

    public:
        static cDatabase2* getInstance(){
            if(instance ==NULL){
                instance = new cDatabase2();
                cout << "singleton Object for cDatabse2 is created" << endl;
            }
            return instance;
        }
        void DBConnect(){
            i++;
            cout << "DB2 connection : "<<i<< endl;
        }
};
cDatabase2* cDatabase2::instance = NULL;

//singlton class
class cDatabase3 : public IDatabase{
    private:
        static cDatabase3* instance;
        int i;
        cDatabase3(){i=0;}
        cDatabase3(const cDatabase3&){}

    public:
        static cDatabase3* getInstance(){
            if(instance ==NULL){
                instance = new cDatabase3();
                cout << "singleton Object for cDatabse3 is created" << endl;
            }
            return instance;
        }
        void DBConnect(){
            i++;
            cout << "DB3 connection : "<< i << endl;
        }
};
cDatabase3* cDatabase3::instance = NULL;


//factory
class factory{
    public:
    factory(){
        cout << "I am factory" << endl;
    }
    static IDatabase* create(DatabaseType db){
        if(db == DatabaseType::Db1){
            return cDatabase1::getInstance();
        }
        else if(db == DatabaseType::Db2){
            return cDatabase2::getInstance();
        }
        else if(db == DatabaseType::Db3){
            return cDatabase3::getInstance();
        }

    }
};





int main()
{
    IDatabase* db1 = factory::create(DatabaseType::Db1);
    IDatabase* db2 = factory::create(DatabaseType::Db2);
    IDatabase* db3 = factory::create(DatabaseType::Db3);

    db1->DBConnect();
    db2->DBConnect();
    db3->DBConnect();


    IDatabase* db1_ = factory::create(DatabaseType::Db1);
    IDatabase* db2_ = factory::create(DatabaseType::Db2);
    IDatabase* db3_ = factory::create(DatabaseType::Db3);

    db1_->DBConnect();
    db2_->DBConnect();
    db3_->DBConnect();
    return 0;
}