#include <iostream>
#include <unordered_set>

using namespace std;

struct StudentRecord {
	string name;
	int id, grade;
	StudentRecord(string currentName, int currentID, int currentGrade) :
      name(currentName), id(currentID), grade(currentGrade)
  	{
  	}
	void displayInfo()
  	{
    	cout << "Name: " << name << ", ID: " << id << ", Grade: " << grade << endl;
  	}
};

// Custom Hash Functor that will compute the hash on the
// passed string objects length
struct StudentHasher
{
  size_t
  operator()(const StudentRecord & obj) const
  {
    return std::hash<std::string>()(obj.name);
  }
};
 
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
	unordered_set <StudentRecord, StudentHasher, StudentComparator> setOfStudByName;
	// do something different
	char IRQS;
	char ing;
	string currentName;
	int currentID;
	int currentGrade;
	while (true) 
	{
		cin >> IRQS;
		if (IRQS == 'I') 
		{
			cin >> currentName >> currentID >> currentGrade;
			// cout << currentName << currentID << currentGrade << endl;
			setOfStudByName.insert(StudentRecord(currentName,currentID,currentGrade));
		}
		else if (IRQS == 'R') 
		{
			cin >> currentID;
		}
		else if (IRQS == 'Q') 
		{
			cin >> ing;
			if (ing == 'i') 
			{
				cin >> currentID;
				for (StudentRecord st : setOfStudByName) 
				{
					if (st.id == currentID) 
					{
						st.displayInfo();
					}
				}	
			}
			else if (ing == 'n') 
			{
				cin >> currentName;
			}
			else if (ing == 'g') 
			{
				cin >> currentGrade;
			}
		}
		else if (IRQS == 'S') 
		{
			break;
		}
	}
	
	
	return 0;
}