#include <bits/stdc++.h>
#include "myTempStack.h"

using namespace std;

int globalID = 100;

class Person
{
    string name;
    int id;
    float salary;

public:
    Person()
    {
        name = " ";
        id = -1;
        salary = -1.0;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setSalary(float salary)
    {
        this->salary = salary;
    }

    Person(string name, float salary)
    {
        setName(name);
        setSalary(salary);
        id = globalID;
        globalID++;
    }

    int getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }
    float getSalary()
    {
        return salary;
    }

    void print()
    {
        cout << name << " | " << id << " | " << salary << endl;
    }
};

int main()
{
    // Stack<pair<int, char>> st;
    // st.push(make_pair(1, 'a'));
    // st.push(make_pair(2, 'b'));
    // st.push(make_pair(3, 'c'));

    // while (!st.empty())
    // {
    //     pair<int, char> chk;
    //     chk = st.pop();
    //     cout << chk.first << " " << chk.second << endl;
    // }

    // cout << st.size() << endl;

    Stack<Person> st;
    Person a("nabil", 64.9);
    Person b("prince", 69.9);
    Person c("araf", 67.9);

    st.push(a);
    st.push(b);
    st.push(c);

    while (!st.empty())
    {
        Person printObj;
        printObj = st.pop();
        printObj.print();
    }
}