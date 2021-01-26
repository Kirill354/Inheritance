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
    double summury;
public:
    Agent(): wage{}, summury{} {}

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
    Manager a;
    a.PrintWage();
    Worker b;
    b.hour = 44;
    b.PrintWage();
    



    delete [] mas;
    return 0;
}