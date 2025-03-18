
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
    Course c4(10…