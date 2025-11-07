# Student Result Management System

## Problem Statement
The Student Result Management System is a software solution designed to
efficiently manage student records, perform roll number-based lookups, store data using
hashing, and sort marks and roll numbers using various algorithms. This system leverages trees,
hashing, and sorting techniques to handle student data, enable efficient retrieval, and compare
the performance of different sorting algorithms. The assignment focuses on implementing these
data structures and algorithms to address real-world student result management scenarios.

## Attributes
- **StudentID** -> Integer,unique identifier for each student
- **StudentName** -> String,name of the student
- **StudentMarks** -> Float,marks of the student
- **CourseDetails** -> String,course of the student
- **HashTable** -> VectorArray,Stores students based on hash values for quick insertion and retrieval
- **StudentArray** -> Vector,Stores all student records for searching and sorting
- **StudentList** -> Vector,stores sorted or ranked student data

## Methods
- **insertStudent(data)** -> Inserts a student record into the hash table using hashing
- **searchStudent(StudentID)** -> Performs binary search on student records by ID.
- **sortRecords()** -> Sort student data using Insertion sort by marks.
- **addStudentRecord()** -> Adds a new student record to the hash table.
- **searchByRollNumber()** -> Performs binary search to retrieve student details.
- **sortByMarks()** -> Performs heap sort to sort students according to marks.
- **sortByRollNumber()** -> Performs radix sort to sort students according to roll numbers.
- **compareSortingPerformance()** -> Displays time and space complexity of sorting and searching algorithms.
- **displayChoice()** -> Presents a menu-driven interface for user interaction.

## Code Explanation

- **HashTable** -> Students are inserted into a hash table using **index=StudentID % 10**.This ensures even distribution and quick lookups,achieving an average time complexity of O(1) for insertion and retrieval.Each index in the hash table can store multiple student records effectively handling collisions using chaining.

- **BinarySearch** -> The **searchById()** function sorts the array by **StudentID** and performs binary search.It is efficient for lookups when data is sorted.This mimics indexed searching in real-world databases.

- **InsertionSort** -> Start from the second element,considering the first element as sorted.Store the current element in a temporary variable called **key**.Compare **key** with each element in the sorted portion.Shift all elements greater than **key** one position to the right.Insert the **key** into the correct position.Repeat until all the elements are sorted.

- **HeapSort** -> Builds a Max Heap from the input array.This ensures the largest element is at the root of the heap.Swap the maximum value with the last element in the heap.Reduce the heap size by one and ingonre the last element,which is now in its correct position.Heapify the root element to maintain the heap property.Repeat until all elements are sorted.

- **RadixSort** -> Find the maximum number to determine the number of digits.Start with least significant digit the ones place.Sort all elements based on that digit using a stable sorting algorithm like counting sort.Move to the next digit and repeat the sorting process.Continue until all digits have been processed.After the final pass,the arry is completly sorted.

## Time Compleixty
- **insertStudent()** -> O(1)
- **serachById()** -> O(log n)
- **sortRecords()** -> O(n2)
- **sortByMarks()** -> O(n log n)
- **sortByRollNumber()** -> O(n*k)

## Space Complexity
Overall space compleixty of the program is **O(n)** where n is the number of student records stored.

## Learning Outcomes
- Implementation of HashTable
- Understanding Binary Search
- Applications of Heap Sort and Radix Sort
- Understanding of time and space complexity
- Use of Menu-Driven programming and OOP
- Practical exposure to Data Structures using C++

## Sample Output
<img width="606" height="444" alt="1" src="https://github.com/user-attachments/assets/e7e03a4d-0023-4bd9-afbb-ae1a429c6a19" />
<img width="562" height="206" alt="2" src="https://github.com/user-attachments/assets/ca42b833-6ea0-46c3-818b-bda0be3de11c" />
<img width="574" height="157" alt="3" src="https://github.com/user-attachments/assets/b1b4d496-4a72-41c4-82ff-1f9f84680673" />
<img width="565" height="194" alt="4" src="https://github.com/user-attachments/assets/3c65e18d-0464-4264-9885-fc01d5475c6b" />
<img width="571" height="312" alt="5" src="https://github.com/user-attachments/assets/ea2b072d-2ebb-48c9-b903-1b577a45ff86" />

- C++ Code File -> https://github.com/SidharthBScCS/Student-Result-Management-System/blob/main/StudentResultManagementSystem.cpp

## Student Details
- **Name** : Sidharth Krishna S
- **RollNo** : 2401720003
- **Course** : BSc Computer Science
- **Semetser** : 3rd Semester
- **Assignment** : Data Structures Theory Assignment 3
