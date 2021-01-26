#include <iostream>

using namespace std;


class Employee {
public:
    virtual void PrintWage(){
        cout << " Employee's wage " << endl;
    }
};


class Agent: public Employee{
private:
    int wage;
public:
    Agent(): wage{13000} {}

    void PrintWage() override{
        cout << "Agent's wage = " << wage << endl;
    }
};






















int main(){




    return 0;
}