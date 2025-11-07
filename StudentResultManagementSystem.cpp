#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct Student{
    int StudentID;
    string StudentName;
    float StudentMarks;
    string CourseDetails;

    static void insertStudent(vector<Student> hashTable[],Student s){
        int index = s.StudentID % 10;
        hashTable[index].push_back(s);
        cout << "Student inserted into hash table" << endl;
    }

    static int searchById(vector<Student>& arr,int id){
        sort(arr.begin(), arr.end(), [](Student a, Student b){ 
            return a.StudentID < b.StudentID; 
        });
        int low = 0;
        int high = arr.size() - 1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(arr[mid].StudentID==id){
                return mid;
            }
            else if(arr[mid].StudentID<id){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }

    static void sortRecords(vector<Student>& arr){
        for (int i = 1; i < arr.size();i++){
            Student key = arr[i];
            int j = i - 1;
            while(j>=0 && arr[j].StudentMarks>key.StudentMarks){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    static void display(Student s){
        cout << "Student details" << endl;
        cout << "ID: " << s.StudentID << endl;
        cout << "Name: " << s.StudentName << endl;
        cout << "Marks: " << s.StudentMarks << endl;
        cout << "Course: " << s.CourseDetails << endl;
    }
};

class StudentResultSystem{
    vector<Student> HashTable[50];
    vector<Student> StudentArray;
    vector<Student> SortedList;

    public:
    void addStudentRecord(int id,string name,float marks,string course){
        Student s = {id, name, marks, course};
        Student::insertStudent(HashTable, s);
        StudentArray.push_back(s);
    }

    void searchByRollNumber(int id){
        int index = Student::searchById(StudentArray, id);
        if(index!=-1){
            Student::display(StudentArray[index]);
        }
        else{
            cout << "Student not found" << endl;
        }
    }

    void sortByMarks(bool useHeap=false){
        SortedList = StudentArray;
        if(useHeap){
            make_heap(SortedList.begin(), SortedList.end(), [](Student a, Student b){ 
                return a.StudentMarks < b.StudentMarks; 
            });
            sort_heap(SortedList.begin(), SortedList.end(), [](Student a, Student b){ 
                return a.StudentMarks < b.StudentMarks; 
            });
        }
        else{
            Student::sortRecords(SortedList);
            cout << "Students sorted by marks using Heap sort" << endl;
        }
        for(auto& s:SortedList){
            cout << "Name: " << s.StudentName << endl;
            cout << "Marks: " << s.StudentMarks << endl;
        }
    }

    void sortByRollNumber() {
        SortedList = StudentArray;
        if (SortedList.empty()) {
            cout << "No student records to sort.\n";
            return;
        }
        int maxID = SortedList[0].StudentID;
        for (auto& s : SortedList){
            maxID = max(maxID, s.StudentID);
        }
        for (int exp = 1; maxID / exp > 0; exp *= 10) {
            vector<Student> output(SortedList.size());
            int count[10] = {0};
            for (auto& s : SortedList){
                count[(s.StudentID / exp) % 10]++;
            }
            for (int i = 1; i < 10; i++){
                count[i] += count[i - 1];
            }
            for (int i = SortedList.size() - 1; i >= 0; i--) {
                int idx = (SortedList[i].StudentID / exp) % 10;
                output[count[idx] - 1] = SortedList[i];
                count[idx]--;
            }
            SortedList = output;
        }
        cout << "Students sorted by Roll Number using Radix Sort" << endl;
        for (auto& s : SortedList){
            cout << "ID: " << s.StudentID << endl;
            cout << "Name: " << s.StudentName << endl;
            cout << "Marks: " << s.StudentMarks << endl;
        }
    }

    void compareSortingPerformance() {
        cout << "Time and Space Complexities" << endl;

        cout << "Radix Sort" << endl;
        cout << "Best Case Time Complexity: O(n * k)" << endl;
        cout << "Space Complexity: O(n + k)" << endl;

        cout << "Heap Sort" << endl;
        cout << "Best Case Time Complexity: O(n log n)" << endl;
        cout << "Space Complexity: O(1)" << endl;

        cout << "Binary Search" << endl;
        cout << "Best Case Time Complexity: O(1)" << endl;
        cout << "Space Complexity: O(1)" << endl;

        cout << "Hash Table" << endl;
        cout << "Best Case Time Complexity: O(1)" << endl;
        cout << "Space Complexity: O(n)" << endl;
    }

    void displayChoice(){
        cout << "Student Result Management System by Sidharth Krishna S 2401720003" << endl;
        cout << "1.Add Student Record" << endl;
        cout << "2.Search Student by Roll Number" << endl;
        cout << "3.Sort by Marks(Heap Sort)" << endl;
        cout << "4.Sort by Roll Number(Radix Sort)" << endl;
        cout << "5.Comparing Sorting Performance" << endl;
        cout << "6.Exit" << endl;
    }
};

int main(){
    StudentResultSystem srs;
    int choice;

    do{
        srs.displayChoice();
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
                int id;
                cout << "Enter Student ID: " << endl;
                cin >> id;
                cin.ignore();
                string name;
                cout << "Enter Name: " << endl;
                getline(cin, name);
                float marks;
                cout << "Enter Marks: " << endl;
                cin >> marks;
                cin.ignore();
                string course;
                cout << "Enter Course Details" << endl;
                getline(cin, course);
                srs.addStudentRecord(id, name, marks, course);
                break;
            }

            case 2:{
                int id;
                cout << "Enter roll number to search" << endl;
                cin >> id;
                srs.searchByRollNumber(id);
                break;
            }

            case 3:{
                srs.sortByMarks(false);
                break;
            }

            case 4:{
                srs.sortByRollNumber();
                break;
            }

            case 5:{
                srs.compareSortingPerformance();
                break;
            }

            case 6:{
                cout << "Exited..." << endl;
                break;
            }

            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);
}