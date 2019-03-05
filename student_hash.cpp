//////////////////////////////////////////////////////////
// CMPUT 275 Winter 2019
// Matthew Braun, 1497171
// Weekly Exercise 6: STL Concepts
//////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_set>

using namespace std;

struct StudentRecord {
	string name;
	int id, grade;
	// Method to declare a StudentRecord struct with pre-defined values
	StudentRecord(string currentName, int currentID, int currentGrade) :
      name(currentName), id(currentID), grade(currentGrade)
  	{
  	}
  	// Method to display a StudentRecord object
	void displayInfo()
  	{
    	cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
  	}
};

// Found and modified from https://thispointer.com/how-to-use-unordered_set-with-user-defined-classes-tutorial-example/
// Custom Hash Functor that will compute the hash on the
// passed string objects length
struct StudentHasher
{
  size_t
  operator()(const StudentRecord & obj) const
  {
    return std::hash<int>()(obj.id);
  }
};

// Found and modified from https://thispointer.com/how-to-use-unordered_set-with-user-defined-classes-tutorial-example/
// Custom comparator that compares the string objects by length
struct StudentComparator
{
  bool
  operator()(const StudentRecord & obj1, const StudentRecord & obj2) const
  {
    if (obj1.name == obj2.name)
      return true;
    return false;
  }
};


int main() {
	// this doesn't work!
	// unordered_set <StudentRecord> table;
	// unordered_set <StudentRecord> setOfStudentRecords;
	// do something different

	// Declare an unordered_set with a custom hash function and a custom comparison function, 
	// since we are hashing a user-defined data structure
	unordered_set <StudentRecord, StudentHasher, StudentComparator> setOfStudByName;

	char IRQS;
	char ing;
	string currentName;
	int currentID;
	int currentGrade;
	bool found;
	while (true) 
	{
		cin >> IRQS;
		if (IRQS == 'I') 
		{
			cin >> currentName >> currentID >> currentGrade;
			// Inserts new student record into the unordered_set if its ID doesn't already exist
			found = false;
			for (StudentRecord st : setOfStudByName) 
				{
					if (st.id == currentID) 
					{
						found = true;
						break;
					}
				}	
			if (found == false)
				setOfStudByName.insert(StudentRecord(currentName,currentID,currentGrade));
			else 
				// Checks for duplicate ID insertion
				cerr << "Error: Cannot insert duplicate ID" << endl;
		}
		else if (IRQS == 'R') 
		{
			// Removes a student record from the unordered_set if it exists within it
			cin >> currentID;
			found = false;
			for (StudentRecord st : setOfStudByName) 
				{
					if (st.id == currentID) 
					{
						found = true;
						break;
					}
				}	
			if (found == false)
				// Checks for non-existant ID deletion
				cerr << "Error: Cannot remove non-existant ID" << endl;
			else 
			{
				for (StudentRecord st : setOfStudByName) 
				{
					if (st.id == currentID) 
					{
						setOfStudByName.erase(st);
					}
				}	
			}
		}
		else if (IRQS == 'Q') 
		{
			cin >> ing;
			found = false;
			if (ing == 'i') 
			{
				// Searches for students with the inputted id
				cin >> currentID;
				for (StudentRecord st : setOfStudByName) 
				{
					if (st.id == currentID) 
					{
						found = true;
						st.displayInfo();
					}
				}	
			}
			else if (ing == 'n') 
			{
				// Searches for students with the inputted name
				cin >> currentName;
				for (StudentRecord st : setOfStudByName) 
				{
					if (st.name == currentName) 
					{
						found = true;
						st.displayInfo();
					}
				}	
			}
			else if (ing == 'g') 
			{
				// Searches for students with the inputted grade
				cin >> currentGrade;
				for (StudentRecord st : setOfStudByName) 
				{
					if (st.grade == currentGrade) 
					{
						found = true;
						st.displayInfo();
					}
				}	
			}
			if (found == false) 
			{
				// If the search returns nothing
				cerr << "Error: No matches found" << endl;
			}
		}
		else if (IRQS == 'S') 
		{
			// Exits program
			break;
		}
	}
	return 0;
}