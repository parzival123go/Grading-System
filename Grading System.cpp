#include <fstream>		//Student ID:816031060
#include <iostream>
using namespace std;


//write structure definitions here
struct Student{
    int student_id;
    string firstname;
    string lastname;
    char gender;
    string email;
    string phone_number;
    string doe;
};

struct Course{
	string course_code;
	string course_name;
	int credits;
};

struct GradeSheet{
	int student_id;
	string course_code;
	string grade;
};


//write print functions to print the details of each structure
void printStudent(Student students[],int numStudents){
int i;

for(i=0;i<numStudents;i++){
	cout<<students[i].firstname<<" ";
	cout<<students[i].lastname<<" ";
	cout<<students[i].gender<<" ";
	cout<<students[i].email<<" ";
	cout<<students[i].phone_number<<" ";
	cout<<students[i].doe<<" ";
}
}

void printCourse(Course courses[],int numCourses){
int i;

for(i=0;i<numCourses;i++){
	cout<<courses[i].course_code<<" ";
	cout<<courses[i].course_name<<" ";
	cout<<courses[i].credits<<" ";

}
}

void printGradeSheet(GradeSheet grades[],int numEntries){
int i;

for(i=0;i<numEntries;i++){
	cout<<grades[i].student_id<<" ";
	cout<<grades[i].course_code<<" ";
	cout<<grades[i].grade<<" ";
}
}

//This function reads the data from the file students.txt and creates Student structures and inserts them in an array of Student structures.
//The function accepts the array of Student structures and returns the number of elements in the array.
int loadStudents(Student students[]){

ifstream input;
input.open("students.txt");

int i=0;

input>>students[i].student_id;

while (students[i].student_id!=0){
	
	input>>students[i].firstname;
	input>>students[i].lastname;
	input>>students[i].gender;
	input>>students[i].email;
	input>>students[i].phone_number;
	input>>students[i].doe;
	
	i++;
	
	input>>students[i].student_id;
}

return i;

input.close();
}

//This function reads the data from the file courses.txt and creates Course structures and inserts them in an array of Course structures.
//The function accepts the array of Course structures and returns the number of elements in the array.
int loadCourses (Course courses[]){
	
ifstream input;
input.open("courses.txt");

int i=0;

input>>courses[i].course_code;

while (courses[i].course_code!="END"){
	
	input>>courses[i].course_name;
	input>>courses[i].credits;
	
	i++;
	
	input>>courses[i].course_code;
}

return i;

input.close();
}

//This function reads the data from the file gradesheet.txt and creates GradeSheet structures and inserts them in an array of GradeSheet structures.
//The function accepts the array of GradeSheet structures and returns the number of elements in the array.
int loadGradeSheet(GradeSheet grades[]){
	
ifstream input;
input.open("gradesheet.txt");

int i=0;

input>>grades[i].student_id;

while (grades[i].student_id!=0){
	
	input>>grades[i].course_code;
	input>>grades[i].grade;
	
	i++;
	
	input>>grades[i].student_id;
}

return i;

input.close();
}

////This function prints the menu options and prompts the user to enter a choice.
void printMenu(){
int choice;

	
	cout<<"Please select one of the following options."<<endl<<endl;
	
	cout<<"1~ Course Information"<<endl<<endl;
	cout<<"2~ Course Summary Grade Sheet"<<endl<<endl;
	cout<<"3~ Student Grade Report"<<endl<<endl;
	cout<<"4~ Student Information"<<endl<<endl;
	cout<<"5~ EXIT"<<endl<<endl;
	
}

//This function searches the array of Course structures for a given course Code. If the Course with that course Code is found, the function returns the location in the array
//where the Course was found. If the course is not found, the function returns -1.

int searchCourses(Course courses[], int numCourses, string course_code){
int i;
	
	for (i=0;i<numCourses;i++){
	if (course_code==courses[i].course_code)
		return i;}
	
	return -1;

}
// This functions searches for a course. If the course is found all of the information pertaining to the course is printed.
// If it is not found an appropriate error message is printed. This function uses the searchCourses function.
void course_info(Course courses[], int numCourses, string course_code){
int course_location;

course_location=searchCourses(courses,numCourses,course_code);


if (course_location==-1)
cout<<"Course Code Invalid!!!!!"<<endl;
else{
cout<<"Course code: "<<courses[course_location].course_code<<endl;
cout<<"Course name: "<<courses[course_location].course_name<<endl;
cout<<"Credits: "<<courses[course_location].credits<<endl<<endl;
}
}

////This functions searches the GradeSheet array for a given course code. If the course code is found, the id of the student enrolled in the course and his/her grade is printed.
////The course code can appear many times in the GradeSheet array. If the course is not found then a message "No student was enrolled for " <courseCode> is printed.
void searchCourses_display(GradeSheet grades[], int numEntries, string course_code){
int course_location,i,answer;


for(i=0;i<numEntries;i++) {
if (course_code==grades[i].course_code){
answer=0;
cout<<"Student ID: "<<grades[i].student_id<<endl;
cout<<"Grade: "<<grades[i].grade<<endl;}
}

if (answer!=0)
cout<<"No student was enrolled for "<<course_code<<endl;
cout<<endl;
}


////This function searches the array of Student structures for a given student id. If a Student with that id is found, the function returns the location in the array
////where the Student was found. If the Student is not found the function returns -1.
int searchStudent(Student students[], int numStudents, int student_id){
	int i;
	
	for (i=0;i<numStudents;i++){
	if (student_id==students[i].student_id)
		return i;}
	
	return -1;

}

//// This functions searches for a student in the GradeSheet array. Each time a student is found,  the course code and the grade obtained by the student is displayed.
//// The student id can appear many times in the GradeSheet array. If it is not found, an appropriate error message is printed. This function uses the searchStudent function.
void searchStudent_display(Student students[], int numStudents, GradeSheet grades[], int numEntries, int student_id){
int student_location,i;

student_location=searchStudent(students ,numStudents, student_id);

if (student_location==-1)
cout<<"Student ID Invalid!!!!!"<<endl;
else{
for(i=0;i<numStudents;i++) {
if (students[student_location].student_id==grades[i].student_id){
cout<<"Course Code: "<<grades[i].course_code<<endl;
cout<<"Grade: "<<grades[i].grade<<endl;}
}
}
if(students[student_location].student_id!=grades[i].student_id)
cout<<"Student is not enrolled in any course."<<endl;

cout<<endl;
}


////This functions uses the information given in Table 1 to find the quality points corresponding to a given grade in a course.
double getQualityPoints(string grade){
double quality_points;

	if(grade=="A+")
	quality_points=4.3;
	else
	if(grade=="A")
	quality_points=4;
	else
	if(grade=="A-")
	quality_points=3.7;
	else
	if(grade=="B+")
	quality_points=3.3;
	else
	if(grade=="B")
	quality_points=3;
	else
	if(grade=="B-")
	quality_points=2.7;
	else
	if(grade=="C+")
	quality_points=2.3;
	else
	if(grade=="C")
	quality_points=2;
	else
	if(grade=="F1")
	quality_points=1.7;
	else
	if(grade=="F2")
	quality_points=1.3;
	else
	if(grade=="F3")
	quality_points=0;
	
	return quality_points;
}

////This function calculates and returns the GPA of a student. It uses searchCourses.
double calculateGPA(GradeSheet grades[], int numEntries, int student_id, Course courses[], int numCourses){
int course_location,i,total_credits=0;
double quality_points=0;
string grade,course_code;
double gpa,gradepoint,total_gradepoint=0;


for (i=0;i<numEntries;i++){
	if (student_id==grades[i].student_id){
	grade=grades[i].grade;
	quality_points=getQualityPoints(grade);
	}
	if (student_id==grades[i].student_id){
	course_code=grades[i].course_code;
	course_location=searchCourses(courses,numCourses,course_code);
	
	if (course_location==-1){
	courses[-1].credits=0;}
	gradepoint= quality_points*courses[course_location].credits;
	total_gradepoint=total_gradepoint+gradepoint;
	total_credits=total_credits+courses[course_location].credits;
}
}
gpa=total_gradepoint/total_credits;
return gpa;
}

//This function displays all the elements for request #4:
void dislpay_4(GradeSheet grades[], Course courses[],Student students[], int student_id,int numEntries,int numCourses){
double gpa;
int i;		

cout<<endl;

gpa=calculateGPA(grades,  numEntries,  student_id,  courses,  numCourses);

for (i=0;i<numEntries;i++){
if (student_id==students[i].student_id){
cout<<"Student ID:";
cout<<students[i].student_id<<endl;
cout<<"First Name:";
cout<<students[i].firstname<<endl;
cout<<"Last Name:";
cout<<students[i].lastname<<endl;
cout<<"Gender:";
cout<<students[i].gender<<endl;
cout<<"Email Address:";
cout<<students[i].email<<endl;
cout<<"Phone Number:";
cout<<students[i].phone_number<<endl;
cout<<"Date of Entry:";
cout<<students[i].doe<<endl;
cout<<"GPA:";
cout<<gpa<<endl;
}
}
cout<<endl;
}
// In main, we declare the array of structures as well as read in the choice entered by the user.
// Based on the choice entered a relevant function is called.
// Validation is done to ensure that the choice is between 1 and 5 inclusive.
// If the choice entered is invalid, a message is given and the menu is re-displayed.
int main(){
int numStudents,course_location,student_id,student_location;
int numCourses;
int numEntries;
string course_code;
int choice;
	
	Student students[100];
	Course courses[30];
	GradeSheet grades[20];
	numStudents=loadStudents(students);
	numCourses=loadCourses (courses);
	numEntries=loadGradeSheet(grades);
	
	printMenu();

cout<<"Enter choice here: ";
	cin>>choice;
	cout<<endl;
	
	while (choice!=5){
		
		if((choice<1)||(choice>5)){
		cout<<"INVALID option entered!!!!"<<endl<<endl;
		printMenu();	}
		
	if (choice==1){
	cout<<"Please enter a course code to display relevent course information:";
	cin>>course_code;
	course_info( courses,  numCourses,  course_code);
	}else
	if (choice==2){
	cout<<"Please enter a course code to display Course Summary Grade Sheet:";
	cin>>course_code;
	searchCourses_display(grades,numEntries,course_code);
	}
	else
	if (choice==3){
	cout<<"Please enter a student id to display the Student Grade Report: ";
	cin>>student_id;
	
	student_location=searchStudent(students ,numStudents, student_id);
	searchStudent_display( students,  numStudents,  grades,  numEntries,  student_id);
	}
	else
	if (choice==4){
	cout<<"Please enter a student id to display the Student Information: ";
	cin>>student_id;
	dislpay_4( grades,  courses, students,  student_id, numEntries, numCourses);
	}

	
	cout<<"Enter choice here: ";
	cin>>choice;
	cout<<endl;	
}
	
return 0;	
}
