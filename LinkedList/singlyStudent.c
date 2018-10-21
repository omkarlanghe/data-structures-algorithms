#include "singly.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Student *CreateStudentsList(int noOfStudents)
{
	struct Student *head = NULL;

	for(int i = 0 ; i < noOfStudents ; i++)
	{
		int RollNo;
		printf("Enter Roll No:\n");
		scanf("%d",&RollNo);
		head = InsertStudent(head,RollNo,1);
	}
	return head;
}

struct Student *InsertStudent(struct Student *insertHead, int RollNo, int Position)
{
	struct Student *student = (struct Student *)malloc(sizeof(struct Student));

	student->m_iRollNo = RollNo;
	student->next = NULL;
	if(1 == Position)
	{	
		if(NULL == insertHead)
		{
			insertHead = student;
		}
		else
		{
			student->next = insertHead;
			insertHead = student;
		}	
	}
	else if(insertHead != NULL)
	{
		struct Student *traverse = insertHead;
		int pos = Position;

		while(traverse->next && pos - 2)
		{
			traverse = traverse->next;
			pos--;
		}
		student->next = traverse->next;
		traverse->next = student;
	}
	else
	{
		printf("\nYou have entered wrong choice:\n");
		free(student);
	}		
	return(insertHead);
}

struct Student *DeleteStudent(struct Student * deleteHead, int Position)
{
	if(NULL != deleteHead)
	{
		struct Student *student = deleteHead;
		if(Position == 1)
		{
			deleteHead = deleteHead->next;
		}
		else
		{
			struct Student *traverse = deleteHead;
			int pos = Position;

			while(traverse->next && pos - 2)
			{
				traverse = traverse->next;
				pos--;
			}
			if(traverse == NULL)
			{
				printf("\n You have entered invalid position to delete, cannot delete:\n");
			}
			else
			{
				student = traverse->next;
				traverse->next = student->next;
				student->next = NULL;
			}
		}

		if(student)
		{
			free(student);
		}
	}
	return(deleteHead);	
}

void DisplayStudents(struct Student * displayHead)
{		
	while(displayHead)
	{	
		printf("RollNo = %d\n",displayHead->m_iRollNo);
		displayHead = displayHead->next;
	}
}

int GetLengthOfList(struct Student *lengthHead)
{
	int count = 0;
	while(lengthHead)
	{
		count++;
		lengthHead = lengthHead->next;
	}
	return(count);
}

_Bool IsValidPosition(struct Student *positionHead, int Position)
{
	int length = GetLengthOfList(positionHead);
	if(Position < 1 || Position > (length + 1))
		return(false);
	return(true);
}

void FreeStudentsList(struct Student *freeHead)
{
	while(freeHead)
	{
		freeHead = DeleteStudent(freeHead, 1);
	}
}

int Menu()
{
	int choice;
	do {
		printf("1.Insert:\n");
		printf("2.Delete:\n");
		printf("3.Display:\n");
		printf("4.Exit\n");
		printf("Enter the choice:\n");
		scanf("%d",&choice);
	}while(choice < 0 || choice > 4);
	
	return choice;
	
}

void singlyDemo()
{
	struct Student *mcsHead = NULL;
	int noOfStudents;
	int Position,RollNo;

	printf("\nEnter Number of Students:");
	scanf("%d",&noOfStudents);

	mcsHead = CreateStudentsList(noOfStudents);

	while(1)
	{
		switch(Menu())
		{
			case 1:
			{
				printf("Enter the position to insert:\n");
				scanf("%d",&Position);
				if(IsValidPosition(mcsHead,Position))
				{
					printf("Enter RollNo to insert\n");
					scanf("%d",&RollNo);
					mcsHead = InsertStudent(mcsHead, RollNo, Position);
				}
				else
				{
					printf("Invalid Position, cannot insert\n");
				}
			}
			break;

			case 2:
			{
				if(mcsHead != NULL)
				{
					printf("Enter the position to delete:\n");
					scanf("%d",&Position);
					if(Position < 0 || Position > GetLengthOfList(mcsHead))
					{
						printf("Invalid Position, cannot delete:\n");
					}
					else
					{
						mcsHead = DeleteStudent(mcsHead, Position);
					}
				}
				else
				{
					printf("\n List is Empty nothing to Deleye\n");
				}
			}
				break;

			case 3:
				DisplayStudents(mcsHead);
				break;
			case 4:
				FreeStudentsList(mcsHead);
				exit(0);
				break;
		}
	}
}

int main()
{
	printf("\n SinglyLinked List Demo");
	singlyDemo();
	return(0);
}
