#include <iostream>

using namespace std;


class Employee {
private:
    double wage;
public:
    virtual void SetWage(int a) {
        wage = a;
    }

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
    double m_summury;
public:
    Agent(int summury = 0): m_summury(summury) {}

    void SetWage(int summury) override{
        m_summury = summury;
    }
    void PrintWage() override{
        cout << "Agent's wage = " << 5000 + 0.05*m_summury << endl;
    }

};

class Worker: public Employee{
private:
    int m_hour;
public:
    Worker(int hour = 0): m_hour(hour) {}

    void SetWage(int hour) override{
        m_hour = hour;
    }
    void PrintWage() override{
        cout << "Worker's wage = " << m_hour*100 << endl;
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
            int x; cin >> x;
            Agent *a = new Agent[i];
            a->SetWage(x);
        }
        else{
            cout << " input Worker's hours: ";
            int x; cin >> x;
            Worker *b = new Worker[i];
            b->SetWage(x);
        }
    }

    for (int i = 0; i < 9; i++){
        mas[i].PrintWage();
        cout << '\n';
    }
    
    /*
    Manager c;
    c.PrintWage();
    Agent a(80000);
    a.PrintWage();
    Worker b(80);
    b.PrintWage();
    */
    delete [] mas;
    return 0;
}