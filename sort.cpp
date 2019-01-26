#include<iostream>
#include<algorithm>
#include<array>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
class Student 
{
    /* data */
public:
    char name[20];
    int id;
    double gpa;
    Student() {}
    Student(char *name, int id, double gpa) {
        strcpy(this->name,name);
        this->id = id;
        this->gpa = gpa;
    }
};
void PrintStudents(const vector<Student> &s, int size) {
    for(int i = 0; i < size; i++) {
        cout<<"("<<s[i].name <<","
        <<s[i].id<<","<<s[i].gpa<<")";
    }
    cout<<"\n";
}
int main()
{
    vector<Student> s = {
        {"Jack", 112, 3.4},
        {"Mary", 102, 3.8},
        {"Mary", 117, 3.9},
        {"Ala", 333, 3.5},
        {"Zero", 101, 4.0}
        };
    struct StudentRule1 //按姓名从小到大
    {
        /* data */
        bool operator() (const Student &s1, const Student &s2) {
            if(stricmp(s1.name, s2.name) < 0)
                return true;
            return false;
        }
    };
    struct StudentRule2 //按id从小到大排序
    {
        bool operator() (const Student &s1, const Student &s2) {
            return s1.id < s2.id;
        }
    };
    struct StudentRule3 //按gpa从大到小排序
    {
        /* data */
        bool operator() (const Student &s1, const Student &s2) {
            return s1.gpa > s2.gpa;
        }
    };
    // sort(s.begin(), s.end(), greater<Student>());
    // PrintStudents(s, s.size());
    sort(s.begin(), s.end(), StudentRule1());
    PrintStudents(s, s.size());

    sort(s.begin(), s.end(), StudentRule2());
    PrintStudents(s, s.size());

    sort(s.begin(), s.end(), StudentRule2());
    PrintStudents(s, s.size());

    return 0;
}