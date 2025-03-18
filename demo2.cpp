#include<iostream>
using namespace std;

class Course {
	
public:
    int cid;
    string cname;
    int credit;

    Course(int id, string name, int c) {
        cid = id;
        cname = name;
        credit = c;
    }

    Course() {
    }

    void display() {
        cout << "\nCourse Id: " << cid;
        cout << "\nCourse Name: " << cname;
        cout << "\nTotal Credit: " << credit;
    }
};

class Institute {
public:
    int nc;
    Course c[10];

    Institute() {
        this->nc = 0;
    }

    void addCourse(Course c1) {
        if (nc < 10) {
            c[nc++] = c1;
        }
        else
            cout << "\nCourse Limit Already Reached To 10!!!";
    }

    void deleteCourse(int id) {
        bool found = false;
        for (int i = 0; i < nc; i++) {
            if (c[i].cid == id) {
                found = true;
                for (int j = i; j < nc - 1; j++) 
				{
                    c[j] = c[j + 1];
                }
                nc--;
                break;
            }
        }
        if (!found)
            cout << "\nCourse Not Found!!!";
    }

    void displayCourses() {
        for (int i = 0; i < nc; i++) {
            c[i].display();
        }
    }

    bool isCourseAvail(int id) {
        for (int i = 0; i < nc; i++) {
            if (c[i].cid == id)
                return true;
        }
        return false;
    }

    Course getCourseById(int id) {
        for (int i = 0; i < nc; i++) {
            if (c[i].cid == id)  
                return c[i];
        }
        return Course();  
    }
};

class Student {
private:
    int sid, numcourse;
    string sname;
    Course erc[5];

public:
    Student(int id, string name, int n = 0) {
        sid = id;
        sname = name;
        numcourse = 0;
    }

    Student() {
    }

    void enroll_Course(Institute &inst, int id) {
        if (numcourse < 5) {
            if (inst.isCourseAvail(id)) {
                
                for (int i = 0; i < numcourse; i++) {
                    if (erc[i].cid == id) {
                        cout << "\nYou are already enrolled in this course: " << erc[i].cname;
                        return;
                    }
                }

                
                erc[numcourse] = inst.getCourseById(id);
                cout << "\n" << this->sname << " You are enrolled for the " << erc[numcourse].cname << " course";
                numcourse++;
            }
            else {
                cout << "\nCourse not available!";
            }
        }
        else {
            cout << "\nYou cannot enroll in more than 5 courses!";
        }
    }

    void removeCourse(int id) {
        bool found = false;
        for (int i = 0; i < numcourse; i++) {
            if (erc[i].cid == id) {
                found = true;
                cout<<"\n"<<erc[i].cname<<" Has Removed...";
                for (int j = i; j < numcourse - 1; j++) {
                    erc[j] = erc[j + 1];
                }
                
                numcourse--;
                break;
            }
        }
        if (!found) {
            cout << "\nCourse Not Found!!!";
        }
    }

    void displaystudent() {
    	cout<<"\n---------------------------------------------------\n";
        cout << "\nStudent Id: " << sid;
        cout << "\nStudent Name: " << sname;
        cout << "\nTotal Enrolled Courses: " << numcourse;
        cout << "\n-----------------Details Of Enrolled Courses--------------\n";
        for (int i = 0; i < numcourse; i++) {
            erc[i].display();
            cout<<"\n---------------------------------------------------\n";
        }
    }
};

int main() {
    Student s(1, "nita");
    Course c(1001, "Java", 14);
    Course c1(1002, "Python", 14);
    Course c2(1003, "CPP", 14);
    Course c3(1004, ".Net", 14);
    Course c4(1005,"DBMS",14);
    
    s.displaystudent();
    Institute i;
    
    s.enroll_Course(c);
    s.enroll_Course(c1);
    s.enroll_Course(c2);
    s.enroll_Course(c3);
    s.enroll_Course(c4);
    
    s.enroll_Course(i,1001);
    s.enroll_Course(i,1002);
    s.enroll_Course(i,1003);
    s.enroll_Course(i,1004);
    s.enroll_Course(i,1005);
    s.displaystudent();
    
}