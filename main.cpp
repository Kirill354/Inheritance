#include <iostream>
#include <vector>

using namespace std;


class Employee {
private:
    double m_wage;
public:
    Employee(int wage = 0): m_wage(wage) {}

    virtual void GetWage(){
        cout << " Employee's wage =  " << m_wage << endl;
    }
};


class Manager: public Employee{
private:
    const int m_wage = 13000;
public:
    Manager(){}

    void GetWage() override{
        cout << "Manager's wage = " << m_wage << endl;
    }
};

class Agent: public Employee{
private:
    double m_summury;
public:
    Agent(int summury = 0): Employee(), m_summury(summury) {}

    void GetWage() override{
        cout << "Agent's wage = " << 5000 + 0.05*m_summury <<  endl;
    }

};

class Worker: public Employee{
private:
    int m_hour;
public:
    Worker(int hour = 0): m_hour(hour) {}

    void GetWage() override{
        cout << "Worker's wage = " << m_hour*100 << endl;
    }

};




int main(){
    
    /*
    Employee **mas = new Employee*[9];
    for (int i = 0; i < 9; i++){
        if (i >= 0 && i <=2){
            mas[i] = new Manager;
        }
        else if (i >= 3 && i <= 5){
            cout << " input Agent's summury: ";
            int x; cin >> x;
            mas[i]= new Agent[x];
        }
        else{
            cout << " input Worker's hours: ";
            int x; cin >> x;
            mas[i] = new Worker[x];
        }
    }

    for (int i = 0; i < 9; i++){
        (*mas[i]).GetWage();
        cout << '\n';
    }
    */

    vector <Employee*> vect;
    for (int i = 0; i < 9; i++){
        if (i >= 0 && i <=2){
            vect[i] = new Manager;
        }
        else if (i >= 3 && i <= 5){
            cout << " input Agent's summury: ";
            int x; cin >> x;
            vect[i]= new Agent[x];
        }
        else{
            cout << " input Worker's hours: ";
            int x; cin >> x;
            vect[i] = new Worker[x];
        }
    }

    for (int i = 0; i < 9; i++){
        (*vect[i]).GetWage();
        cout << '\n';
    }
    
    //delete [] *mas;
    return 0;
}