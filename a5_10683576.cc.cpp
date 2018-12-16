#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

struct student_info {
    int id_number;
    string name;
    int age;
    char gender[1];
    int score;
    char grade[1];    
};

int main(){
    int i=0,r=0, total_std=0, total_age=0, total_score=0, f_count=0, m_count=0, avg_age=0;
    int student_no[5], student_age[5], student_score[5];
    string student_name[5]; char student_gender[5], student_grade[5];
    double avg_score=0.00;
    
    ofstream outputfile;
    
    cout<<"Enter the student information as required below: " << endl;
    cout<<"Enter the total number of students: ";
    cin>>total_std;
    
    for(i=0; i<total_std; i++){
        cout<<"INFORMATION ABOUT STUDENT "<<i+1<<endl;
        cout<<"*******************************"<<endl;
        cout<<"Student Number: ";
        cin>>student_no[i];
        cout<<"Student Name: ";
        cin>>student_name[i];
        cout<<"Student Age: ";
        cin>>student_age[i];
        cout<<"Gender(M/F): ";
        cin>>student_gender[i];
        cout<<"Exam Score: ";
        cin>>student_score[i];
        cout<<"Grade: ";
        cin>>student_grade[i];
        cout<<endl;
        total_age +=student_age[i];
        total_score +=student_score[i];
        if(student_gender[i] == 'F'){
             f_count +=1;
        }else if(student_gender[i] == 'M'){
             m_count +=1;    
        }
    }
    avg_age = total_age/total_std;
    avg_score = total_score/total_std;
    
    outputfile.open("output.txt");
    outputfile<<"ID   Name   Age  Gender  Score  Grade\n";
    outputfile<<"**   ****   ***  ******  ******  *****\n";
    for(r=0; r<total_std; r++){
       student_info output = {student_no[r], student_name[r], student_age[r], student_gender[r], student_score[r], student_grade[r]};
       
       outputfile<<output.id_number<<"  "<<output.name<<"     "<<output.age<<"     "<<output.gender;
       outputfile<<output.score<<"    "<<output.grade<<endl;
    }
        outputfile<<endl<<"************************************************"<<endl;
        outputfile<<"Average Age: "<<avg_age<<endl;
        outputfile<<"Average Score: "<<avg_score<<endl;
        outputfile<<"Female Count: "<<f_count<<endl;
        outputfile<<"Male Count: "<<m_count<<endl;
        outputfile.close();
    system("pause");
    return 0;
}

