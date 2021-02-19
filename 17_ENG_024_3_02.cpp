//Header file
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

//Declare namespace
using namespace std;

//declare vectors as common
vector<int>vec1;
vector<int>vec2;

//Declare class Node
class NODE
{
	//Declare private class variables
private:
	NODE*beginning1;
	NODE*beginning2;
	NODE*end1;
	NODE*end2;

	//Declare public variables
public:
	int data1;
	NODE*next1;
	int data2;
	NODE*next2;

	//Default constructor
	NODE()
	{
		beginning1 = NULL;
		end1 = NULL;
		beginning2 = NULL;
		end2 = NULL;
	}

	//Function list
	void extract1(string str);
	void extract2(string str);
	void adddata1(int val);
	void adddata2(int val);
	void searchdata();
};

//Main function
int main()
{
	//Declare Node object
	NODE ob1;

first:

	//Get inputs for the linked list
	string s;

	//Output to the console window
	cout << "Input data for 1st Linked List : ";

	//getting input
	getline(cin, s);

	//Send values to the list
	ob1.extract1(s);

	//Check for the duplicate values
	for (int i = 0; i < vec1.size()-1; i++)
	{
		for (int j = i + 1; j < vec1.size(); j++)
		{
			//condition checking
			if (vec1[i] == vec1[j])
			{
				//output to the console window
				cout << "\n\nList include duplicate values. So enter again........!\n\n";

				//clear vector
				vec1.clear();

				//goto first
				goto first;
			}
		}
	}

second:

	//Get input for the linked list 2
	string s1;

	//Output to the console window
	cout << "Input data for 2nd Linked List : ";
	
	//getting input
	getline(cin, s1);

	//Send values to the list
	ob1.extract2(s1);

	//Check for the duplicate values
	for (int i = 0; i < vec2.size() - 1; i++)
	{
		for (int j = i + 1; j < vec2.size(); j++)
		{
			//condition checking
			if (vec2[i] == vec2[j])
			{
				//output to the console window
				cout << "\n\nList include duplicate values. So enter again........!\n\n";
				
				//clear vector
				vec2.clear();

				//goto second
				goto second;
			}
		}
	}

	//Create the linked list
	for (int i = 0; i < vec1.size(); i++)
	{
		//calling adddata function
		ob1.adddata1(vec1[i]);
	}

	//Create the linked list
	for (int i = 0; i < vec2.size(); i++)
	{
		//calling adddata function
		ob1.adddata2(vec2[i]);
	}

	//Search for similar values
	ob1.searchdata();

	//getting space lines
	cout << endl << endl << endl << endl;

	//Waiting for the user input
	system("pause");
	return 0;
}

//Send values to the list
void NODE::extract1(string str)
{
	stringstream ss;

	ss << str;

	//declare variables
	string temp;
	int found;

	while (!ss.eof()) 
	{
		ss >> temp;

		//condition checking
		if (stringstream(temp) >> found)
		{
			//add data to vector
			vec1.push_back(found);
		}
	
	}
	
}

//Send values to the list
void NODE::extract2(string str)
{
	stringstream ss;

	ss << str;

	//declare variables
	string temp;
	int found;

	while (!ss.eof())
	{
		ss >> temp;

		//condition checking
		if (stringstream(temp) >> found)
		{
			//add data to vector
			vec2.push_back(found);
		}
	}
}



//Create the linked list
void NODE::adddata1(int val)
{
	NODE* newnode = new NODE();
	newnode->data1 = val;
	newnode->next1 = NULL;

	//condition checking
	if (beginning1 == NULL) 
	{
		beginning1 = newnode;
	}
	//condition checking
	else 
	{
		NODE* temp = beginning1;
		while (temp->next1 != NULL)
		{
			temp = temp->next1;
		}
		temp->next1 = newnode;
	}

}

//Create the linked list 2
void NODE::adddata2(int val)
{
	NODE* newnode = new NODE();
	newnode->data2 = val;
	newnode->next2 = NULL;
	//condition checking
	if (beginning2 == NULL) 
	{
		beginning2 = newnode;
	}
	//condition checking
	else
	{
		NODE* temp = beginning2;
		while (temp->next2 != NULL)
		{
			temp = temp->next2;
		}
		temp->next2 = newnode;
	}

}

//Search for the similar values
void NODE::searchdata()
{
	NODE *temp1 = beginning1;
	
	//condition checking
	if (beginning1 == NULL)
	{
		cout << "1st Linked List is Empty\n\n\n";
	}
	//condition checking
	if (beginning2 == NULL)
	{
		cout << "2nd Linked List is Empty\n\n\n";
	}
	//condition checking
	else
	{
		//declare variable
		int count = 0;

		//output to the console window
		cout << endl << endl<<"Common Values : ";
		while (temp1 != NULL)
		{
			
			NODE *temp2 = beginning2;
			while (temp2 != NULL)
			{
				//condition checking
				if (temp1->data1 == temp2->data2)
				{
					count = count + 1;
					cout << temp1->data1 << "  " ;
				}
				temp2 = temp2->next2;
			}
			temp1 = temp1->next1;
		}

		//condition checking
		if (count == 0)
		{
			cout << "NULL";
		}

	}
}