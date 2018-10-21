#ifndef SINGLY_H
#define SINGLY_H

struct Student
{
	int m_iRollNo;
	struct Student *next;
};

struct Student *CreateStudentsList(int noOfStudents);
struct Student *InsertStudent(struct Student * insertHead, int RollNo, int Position);
struct Student *DeleteStudent(struct Student * const deleteHead, int position);
void DisplayStudents(struct Student * displayHead);
void FreeStudentsList(struct Student * freeHead);

#endif
