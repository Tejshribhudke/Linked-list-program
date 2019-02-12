//============================================================================
// Name        : pclub.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : pinnacleclub.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/* Department computer engineering students has a club called pinnacle club.first node is  reserved for president of club and last is for secretary.
 * WAP to maintain club member information using singly linked list.Store students name and PRN
 *write function to
 * 1)delete members
 * 2)count total members
 * 3)Display members
 * 4)display members in reverse order using recursion
 * 5)concatenate two lists
 */
#include <iostream>
using namespace std;
class student {
	string prn;
	string name;
	string position;
	student* next;
public:
	student() {
		prn = "unk";
		name = "unk";
		position="M";//initialising to member
		next = NULL;

	}
	friend class club;
};
class club {
	student *head;
public:
	club() {
		head = NULL;
	}
	student* gethead() {
		return head;
	}
	void insert();
	void display(student *temp);
//	void display();
	void printr(student *temp);
	void total();
	void delete_member();
	 student* merge(student*temp);
};
void club::insert() {
	int n;
	cout << "how many students do you prefer?" << endl;
	cin >> n;
	if (n >= 3) {
		for (int i = 1; i <= n; i++) {
			student *ptr = new student();
			if (i == 1) {
				cout << "enter the president's details" << endl;
				cin >> ptr->prn >> ptr->name;
				ptr->position = "P";
				head = ptr;
			} else if (i == 2) {
				cout << "enter the secretary datails!" << endl;
				cin >> ptr->prn >> ptr->name;
				ptr->position = "S";
				head->next = ptr;

			} else {
				cout << "MEMBERS DETAILS " << endl;
				cin >> ptr->prn >> ptr->name;
				ptr->next = head->next;
				head->next = ptr;
			}
		}
	}
}
void club::display(student*q) {


while (q != NULL) {
cout << q->prn << "\t" << q->name << "\t"<< q->position << "\t" ;
q = q->next;
}
}
//void club::display() {
//
//	student*q=head;
//while (q != NULL) {
//cout << q->prn << "\t" << q->name << "\t"<< q->position << "\t" ;
//q = q->next;
//}
//}
void club::printr(student *temp) {
	if (temp == NULL)
		return;
	//cout << temp->prn << "\t" << temp->name << "\n";
	printr(temp->next);
	cout << temp->prn << "\t" << temp->name << "\n";//difference in op if stmt written here or above
}
void club::total() {
	int count = 0;
	student*q;
	q = head;
	while (q != NULL) {
		q = q->next;
		count++;
	}
	cout << "the count is!" << count << endl;
}
student* club::merge(student*temp)
{if(head==NULL)
  {
	return temp;
  }
else if(temp==NULL)
  {
	return head;
  }
else
  {
	student* ptr=head;
	while(ptr->next!=NULL)
	{ ptr=ptr->next;
     }
	ptr->next=temp;
	ptr->position="M";
	ptr->next->position="M";
	return head;
}
}
void club::delete_member() {
	string p;
	cout<<" PLZ......Enter prn you  want to delete"<<endl;
	cin>>p;
	int count=0;
	student* temp =head;
	while(temp!=NULL)
		{ temp=temp->next;
		count ++;

	     }
	if(count<=3)
		cout<<"NOT POSSIBLE"<<endl;
	else
	{
		student* cur=head;
		student* prev=NULL;
        while(cur!=NULL)
        {if(cur->prn==p)
          {if(cur->position=="P")
            {
        	head=head->next;
            head->position="P";
             cout<<"deleted prn is "<<p<<endl;
            delete cur;
            }
        else if(cur->position=="S")
        {prev->position="S";
        prev->next=NULL;
        cout<<"deleted prn is "<<p<<endl;
        delete cur ;
        }
        else
        {prev->next=cur->next;
        cout<<"deleted prn is "<<p<<endl;
        delete cur;
        }
        return;
        }else
			{
        	prev=cur;
        	cur=cur->next;
			}
	}
	cout<<" SORRY.....NOT FOUND "<<endl;

        }
}

int main() {
	club C,C2;
	C.insert();
	cout<<"FIRST LIST IS"<<endl;

	C.display(C.gethead());
	C2.insert();
	cout<<"SECOND LIST IS"<<endl;
	C2.display(C2.gethead());
student*ptr=C.merge(C2.gethead());
cout<<"MERGED LIST IS"<<endl;
C.display(ptr);
	//C.display(C.gethead());
	C.total();
	cout<<"DISPLAYING LIST I N REVERSE ORDER"<<endl;
	C.printr(C.gethead());
	C.delete_member();
	C.display(C.gethead());
	return 0;
}

