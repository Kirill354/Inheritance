#include <iostream>

using namespace std;


class Employee {
private:
    double wage;
public:
    virtual void PrintWage(){
        cout << " Employee's wage " << endl;
    }
};


class Manager: public Employee{
private:
    const double wage;
public:
    Manager(): wage{13000} {}

    void PrintWage() override{
        cout << "Manager's wage = " << wage << endl;
    }
};

class Agent: public Employee{
private:
    double wage;
public:
    double summury;
    Agent(): wage{5000}, summury{} {}

    void PrintWage() override{
        cout << "Agent's wage = " << wage + 0.05*summury << endl;
    }

};

class Worker: public Employee{
private:
    double wage;
public:
    int hour;
    Worker(): hour{} {}

    void PrintWage() override{
        cout << "Worker's wage = " << hour*100 << endl;
    }

};




int main(){

    Employee *mas = new Employee[9];
    for (int i = 0; i < 9; i++){
        if (i >= 0 && i <=2){
            Manager *a = new Manager[i];
        }
        else if (i >= 3 && i <= 5){
            cout << " input Agent's summury: ";
            Agent *a = new Agent[i];
            cin >> a->summury;
        }
        else{
            cout << " input Worker's hours: ";
            Worker *a = new Worker[i];
            cin >> a->hour;
        }
    }

    for (int i = 0; i < 9; i++){
        mas[i].PrintWage();
        cout << '\n';
    }

    /*
    Manager a;
    Worker b;
    Agent c;
    c.summury = 70000;
    c.PrintWage();
    a.PrintWage();
    b.hour = 44;
    b.PrintWage();
    */

    delete [] mas;
    return 0;
}