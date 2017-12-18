#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iomanip>

using namespace std;

void database();
void print_main();
void overview();
void hit_menu();
void protein(unsigned int&, int&);
void protein_sequence(unsigned int&, int&);
void protein_stats(unsigned int&, int&);
void outFile(unsigned int&);
void gi_Id(unsigned int&, string&, int&);
void ref_Id(unsigned int&, string&, int&);
void keyword_function(unsigned int&, string&, int&);

int main()
{
	int a,b,c,d = 0;
	int choice = 0;
	int choice2 = 0;
	unsigned int id=0; //item id
	string gi_id, ref_id, keyword;
	ifstream abridged_version;
	ifstream unabridged_version;
	cout << "Welcome to Protein Database" << endl << endl;
	database(); 
	cin >> choice;
	
	if (choice == 1)
	{
		cout<<endl<<"Loading database..."<<endl<<"Database loaded."<<endl;
		abridged_version.open("protein_a.fa");
	}
	if (choice == 2)
	{
		cout<<endl<<"Loading database..."<<endl<<"Database loaded."<<endl;
		unabridged_version.open("protein_c.fa");
	}
	if (choice == 3)
	{	
		cout<<"Exiting Database"<<endl;
		return 0;
	}
	
	do
	{
		print_main();
		cin >> choice2;
		if (choice2 == 1)
		{
			cout<<endl<<endl;
			overview();
		}
		if (choice2 == 2)
		{
			cout << endl;
			cout << "Enter an item id: "<<endl<<">>";
			cin >> id;
			cout<< endl;
			do
			{
				hit_menu();
				cin >> a;
				if (a == 1)
					protein(id, choice);
				else if (a == 2)
					protein_sequence(id, choice);
				else if (a == 3)
					protein_stats(id, choice);
				else if (a == 4)
					outFile(id);
				else if (a == 5)
					
					break;
			} while (a <= 5);
		}
		if (choice2 == 3)
		{
			cout << endl;
			cout << "Enter a gi id: "<<endl<<">>";
			cin >> gi_id;
			gi_Id(id, gi_id, choice);
			cout << endl;
			do
			{
				hit_menu();
				cin >> b;
				if (b == 1)
					protein(id, choice);
				else if (b == 2)
					protein_sequence(id, choice);
				else if (b == 3)
					protein_stats(id, choice);
				else if (b == 4)
					outFile(id);
				else if (b == 5)
					
					break;
			} while (b <= 5);
		}
		if (choice2 == 4)
		{
			cout<<endl;
			cout <<"Enter a ref id: "<<endl<<">>";
			cin >> ref_id;
			ref_Id(id, ref_id, choice);
			cout<<endl;
			do
			{
				hit_menu();
				cin >> c;
				
				if (c == 1)
					protein(id, choice);
				else if (c == 2)
					protein_sequence(id, choice);
				else if (c == 3)
					protein_stats(id, choice);
				else if (c == 4)
					outFile(id);
				else if (c == 5)
					
					break;
			} while (c <= 5);
		}
		if (choice2 == 5)
		{
			cout<<endl;
			cout <<"Enter a keyword: "<<endl<<">>";
			cin >> keyword;
			keyword_function(id, keyword, choice);
			if (id == 0)
				continue;
			cout<<endl;
			do
			{
				hit_menu();
				cin >> d;
				if (d == 1)
					protein(id, choice);
				else if (d == 2)	
					protein_sequence(id, choice);
				else if (d == 3)
					protein_stats(id, choice);
				else if (d == 4)
					outFile(id);
				else if (d == 5)
					
					break;
			} while (d <= 5);
		}
		if (choice2 == 6)
		{
			cout<<endl;
			break;
		}
	} while (choice2 = 6);
	cout<< "Exiting Database";
	abridged_version.close();
	unabridged_version.close();
	return 0;
}
void database()
{	
	cout << "Select an option from menu below" << endl;
	cout << "1) Load the abridged protein data" << endl;
	cout << "2) Load the complete protein data" << endl;
	cout << "3) Quit database" << endl;
	cout <<">>";
}
void print_main()
{
	cout << "Select an option from the menu below" << endl;
	cout << "1) Overview of the database" << endl;
	cout << "2) Search by protein #" << endl;
	cout << "3) Search by gi #" << endl;
	cout << "4) Search by ref #" << endl;
	cout << "5) Search by keywood" << endl;
	cout << "6) Quit database" << endl;
	cout <<">>";
}
void overview()
{
	cout << "The proteins in the database are from Genbank(R)" << endl;
	cout << "Total number of proteins in the database:110386" << endl;
	cout << "Amino acids are represented by the following characters :" << endl;
	cout << "A  alanine                   P  proline" << endl;
	cout << "B  aspartate/asparagine      Q  glutamine" << endl;
	cout << "C  cystine		     R  arginine" << endl;
	cout << "D  aspartate		     S  serine" << endl;
	cout << "E  glutamate                 T  threonine" << endl;
	cout << "F  phenylalanine             U  selenocysteine" << endl;
	cout << "G  glycine                   V  valine" << endl;
	cout << "H  histidine                 W  tryptophan" << endl;
	cout << "I  isoleucine		     Y  tyrosine" << endl;
	cout << "K  lysine                    Z  glutamate/glutamine" << endl;
	cout << "L  leucine                   X  any" << endl;
	cout << "M  methionine                *  translation stop" << endl;
	cout << "N  asparagine                -  gap of indeterminate length" << endl;
}
void hit_menu()
{
	cout<<"Select an option from the menu below" << endl;
	cout<<"1) Description of protein" << endl;
	cout<<"2) Protein sequence" << endl;
	cout<<"3) Protein statistics" << endl;
	cout<<"4) Record protein to file" << endl;
	cout<<"5) Return to main menu" << endl;
	cout<<">>";
}
void protein(unsigned int& id, int& choice)
{
	string gi_id, ref_id, name;
	cout<< "Description of the protein:" <<endl;
	cout<< "item id: "<<id<<endl;
	ifstream abridged_version;
	ifstream unabridged_version;
	if(choice == 1)
	{	
		abridged_version.open("protein_a.fa");
		getline(abridged_version,gi_id,'>');
		for(unsigned int b = 1; b < id; b++)
		{
			getline(abridged_version,gi_id,'>');
		}
		getline(abridged_version, gi_id,'|');
		getline(abridged_version, gi_id,'|');
	
		cout <<"gi id: "<< gi_id<<endl;
	
		getline(abridged_version, ref_id,'|');
		getline(abridged_version, ref_id,'|');
	
		cout <<"ref id: "<<ref_id<<endl;
	
		getline(abridged_version, name,' ');
		getline(abridged_version, name,'\n');
	
		cout <<"name: "<<name<<endl<<endl;
	}
	if(choice == 2)
	{	
		unabridged_version.open("protein_c.fa");
		getline(unabridged_version,gi_id,'>');
		for(unsigned int b = 1; b < id; b++)
		{
			getline(unabridged_version,gi_id,'>');
		}
		getline(unabridged_version, gi_id,'|');
		getline(unabridged_version, gi_id,'|');
	
		cout <<"gi id: "<< gi_id<<endl;
	
		getline(unabridged_version, ref_id,'|');
		getline(unabridged_version, ref_id,'|');
	
		cout <<"ref id: "<<ref_id<<endl;
	
		getline(unabridged_version, name,' ');
		getline(unabridged_version, name,'\n');
	
		cout <<"name: "<<name<<endl<<endl;
	}
}
void protein_sequence(unsigned int& id, int& choice)
{
	string sequence;
	ifstream abridged_version;
	ifstream unabridged_version;
	if (choice == 1)
	{
		abridged_version.open("protein_a.fa");
		getline(abridged_version,sequence,'>');
		for(unsigned int a = 1; a < id; a++)
		{
			getline(abridged_version,sequence,'>');
		}
		getline(abridged_version,sequence,']');
		getline(abridged_version,sequence,'>');
		cout<<endl;
		cout<<"Protein sequence: "<< sequence;
		cout<<endl;
	}
	if (choice == 2)
	{
		unabridged_version.open("protein_c.fa");
		getline(unabridged_version,sequence,'>');
		for(unsigned int a = 1; a < id; a++)
		{
			getline(unabridged_version,sequence,'>');
		}
		getline(unabridged_version,sequence,']');
		getline(unabridged_version,sequence,'>');
		cout<<endl;
		cout<<"Protein sequence: "<< sequence;
		cout<<endl;
	}
}
void protein_stats(unsigned int& id, int& choice)
{
	string stats;
	ifstream abridged_version;
	ifstream unabridged_version;
	if (choice == 1)
	{
		abridged_version.open("protein_a.fa");
		cout<<"Report on the protein statistics:"<<endl<<endl;
		getline(abridged_version,stats,'>');
		for(unsigned int a = 1; a < id; a++)
		{
			getline(abridged_version,stats,'>');
		}
		getline(abridged_version,stats,']');
		getline(abridged_version,stats, '>');
	}
	if (choice == 2)
	{
		unabridged_version.open("protein_c.fa");
		cout<<"Report on the protein statistics:"<<endl<<endl;
		getline(unabridged_version,stats,'>');
		for(unsigned int a = 1; a < id; a++)
		{
			getline(unabridged_version,stats,'>');
		}
		getline(unabridged_version,stats,']');
		getline(unabridged_version,stats, '>');
	}
	
	int c = stats.size();
	int d = stats.size();
	while (c > 70)
	{
		c-=70;
		d-=1;
	}
	d-=2;
	cout<<"Total number of amino acids:" <<d<<endl<<endl;
	
	int countA = 0, countB = 0, countC = 0, countD= 0, countE= 0, countF= 0, countG= 0, countH = 0, countI = 0, countK = 0, countL = 0, countM = 0,	countN = 0,
	countP = 0, countQ = 0, countR = 0, countS = 0, countT = 0, countU = 0, countV = 0, countW = 0, countX = 0, countY = 0, countZ = 0, count1 = 0, count2	= 0;
		
	int i = 0;
	while(i < stats.size())
	{
		if(stats[i] == '\n')
			i++;
		if(stats[i] == 'A')
		{
			countA++;
			i++;
		}
		if (stats[i] == 'B')
		{
			countB++;
			i++;
		}
		if (stats[i] == 'C')
		{
			countC++;
			i++;
		}
		if (stats[i] == 'D')
		{
			countD++;
			i++;
		}
		if (stats[i] == 'E')
		{
			countE++;
			i++;
		}
		if (stats[i] == 'F')
		{
			countF++;
			i++;
		}
		if (stats[i] == 'G')
		{
			countG++;
			i++;
		}
		if (stats[i] == 'H')
		{
			countH++;
			i++;
		}
		if (stats[i] == 'I')
		{
			countI++;
			i++;
		}
		if (stats[i] == 'K')
		{
			countK++;
			i++;
		}
		if (stats[i] == 'L')
		{
			countL++;
			i++;
		}
		if (stats[i] == 'M')
		{
			countM++;
			i++;
		}
		if (stats[i] == 'N')
		{
			countN++;
			i++;
		}
		if (stats[i] == 'P')
		{
			countP++;
			i++;
		}
		if (stats[i] == 'Q')
		{
			countQ++;
			i++;
		}
		if (stats[i] == 'R')
		{
			countR++;
			i++;
		}
		if (stats[i] == 'S')
		{
			countS++;
			i++;
		}
		if (stats[i] == 'T')
		{
			countT++;
			i++;
		}
		if (stats[i] == 'U')
		{
			i++;
			countU++;
		}
		if (stats[i] == 'V')
		{
			countV++;
			i++;
		}
		if (stats[i] == 'W')
		{	
			countW++;
			i++;
		}
		if (stats[i] == 'X')
		{
			countX++;
			i++;
		}
		if (stats[i] == 'Y')
		{
			countY++;
			i++;
		}
		if (stats[i] == 'Z')
		{ 	
			countZ++;
			i++;	
		}
		if (stats[i] == '*')
		{
			count1++;
			i++;
		}
		if (stats[i] == '-')
		{
			count2++;
			i++;
		}
	} //while loop bracket
	cout << "A    "<< left << setw(5)<<countA++<<"  P "<< countP++ <<endl;
	cout << "B    "<< left << setw(5)<<countB++<<"  Q "<< countQ++<<endl;
	cout << "C    "<< left << setw(5)<<countC++<<"  R "<< countR++<<endl;
	cout << "D    "<< left << setw(5)<<countD++<<"  S "<< countS++<<endl;
	cout << "E    "<< left << setw(5)<<countE++<<"  T "<< countT++<<endl;
	cout << "F    "<< left << setw(5)<<countF++<<"  U "<< countU++<<endl;
	cout << "G    "<< left << setw(5)<<countG++<<"  V "<< countV++<<endl;
	cout << "H    "<< left << setw(5)<<countH++<<"  W "<< countW++<<endl;
	cout << "I    "<< left << setw(5)<<countI++<<"  Y "<< countY++<<endl;
	cout << "K    "<< left << setw(5)<<countK++<<"  Z "<< countZ++<<endl;
	cout << "L    "<< left << setw(5)<<countL++<<"  X "<< countX++<<endl;
	cout << "M    "<< left << setw(5)<<countM++<<"  * "<< count1++<<endl;
	cout << "N    "<< left << setw(5)<<countN++<<"  - "<< count2++<<endl;
}
void outFile(unsigned int& id)
{
	string sequence;
	ifstream abridged_version;
	abridged_version.open("protein_a.fa");
	
	ifstream unabridged_version;
	unabridged_version.open("protein_c.fa");

	getline(abridged_version,sequence,'>');
	for(unsigned int a = 1; a < id; a++)
	{
		getline(abridged_version,sequence,'>');
	}
	getline(abridged_version,sequence,'>');
	
	string oname = "Records.txt";
	ofstream ost;
	ost.open(oname.c_str(), ios_base::out);
	ost<<sequence;
	
	cout<<"The protein was written to file"<<endl;
}
void gi_Id(unsigned int& id, string& gi, int& choice)
{
	vector<string>myVector;
	string gi_id;
	ifstream abridged_version;
	ifstream unabridged_version;
	
	if(choice ==1)
	{
		abridged_version.open("protein_a.fa");
		while (!abridged_version.eof())
		{
			abridged_version.ignore(999,'|');
			getline(abridged_version,gi_id,'|');
			myVector.push_back(gi_id);
			getline(abridged_version,gi_id,'|');
			getline(abridged_version,gi_id,'|');
		}
	}
	
	if(choice ==2)
	{
		unabridged_version.open("protein_c.fa");
		while (!unabridged_version.eof())
		{
			unabridged_version.ignore(999999999,'|');
			getline(unabridged_version,gi_id,'|');
			myVector.push_back(gi_id);
			unabridged_version.ignore(999999999,'|');
			unabridged_version.ignore(999999999,'|');
		}
	}
	
	
	for (unsigned int a = 0; a < myVector.size(); a++)
	{
		if (myVector[a] == gi)
		{	
			id = a + 1;
		}
	}
}
void ref_Id(unsigned int& id, string& ref, int& choice)
{
	vector<string>myVector;
	string ref_id;
	ifstream abridged_version;
	ifstream unabridged_version;
	
	if(choice == 1)
	{
		abridged_version.open("protein_a.fa");
		while (!abridged_version.eof())
		{
			abridged_version.ignore(999,'|');
			getline(abridged_version,ref_id,'|');
			getline(abridged_version,ref_id,'|');
			getline(abridged_version,ref_id,'|');
			myVector.push_back(ref_id);
		}
	}
	if(choice == 2)
	{
		unabridged_version.open("protein_c.fa");
		while (!unabridged_version.eof())
		{
			unabridged_version.ignore(999999999,'|');
			unabridged_version.ignore(999999999,'|');
			unabridged_version.ignore(999999999,'|');
			getline(unabridged_version,ref_id,'|');
			myVector.push_back(ref_id);
		}
	}
	
	for (unsigned int a = 0; a < myVector.size(); a++)
	{
		if (myVector[a] == ref)
		{	
				id = a + 1;
		}
	}
}
void keyword_function(unsigned int& id, string& name, int& choice)
{
	unsigned int count = 0;
	unsigned int item = 0;
	string gi_id;
	string ref_id;
	string protein_name;
	vector<string>myref_id;
	vector<string>myname;
	vector<string>mygi_id;
	vector<int>myVector;
	vector<int>myVector2;
	unsigned int item_id = 0;
	unsigned int x;
	ifstream abridged_version;
	abridged_version.open("protein_a.fa");
	ifstream unabridged_version;
	unabridged_version.open("protein_c.fa");
	
	if(choice == 1)
	{
		while (!abridged_version.eof())
		{
			abridged_version.ignore(999,'|');
			getline(abridged_version,gi_id,'|');
			mygi_id.push_back(gi_id);
		
			getline(abridged_version,ref_id,'|');
			getline(abridged_version,ref_id,'|');
			myref_id.push_back(ref_id);
		
			getline(abridged_version,protein_name,'\n');
			myname.push_back(protein_name);
		}
	}
	if(choice == 2)
	{
		while (!abridged_version.eof())
		{
		abridged_version.ignore(999,'|');
		getline(abridged_version,gi_id,'|');
		mygi_id.push_back(gi_id);
		
		getline(abridged_version,ref_id,'|');
		getline(abridged_version,ref_id,'|');
		myref_id.push_back(ref_id);
		
		getline(abridged_version,protein_name,'\n');
		myname.push_back(protein_name);
		}
	}
	
	for(unsigned int a = 0; a < myname.size(); a++)
	{
		if (myname[a].find(name)!=string::npos)
			count = count +1;
	}
	cout<<"Number of matches = "<<count<<endl;
	
	for(unsigned int b = 0; b < myname.size(); b++)
	{
		if (myname[b].find(name)!=string::npos)
		{
			if (b == myname.size()-1)
			{
				break;
			}
			item = item + 1;
			cout<<item<<") ";
			myVector2.push_back(item);
			cout<<"item id: "<<b+1 <<", ";
			myVector.push_back(b+1);
			cout<< "gi id: "<< mygi_id[b] <<", ";
			cout<< "ref id: "<< myref_id[b] <<endl;
			cout<<"  "<< myname[b] <<endl<<endl;
		}
	}
	cout<<endl;
	if(count == 0)
	cout<<" No matches found"<<endl<<endl;
	else
	{
		cout<<"Select one of the matches"<<endl<<">>";
		cin>>item_id;
		for (unsigned int i = 0; i < myVector2.size(); i++)
		{
			if (item_id == myVector2[i])
			{
				id = myVector[i];
			}
		}
	}
}
	
	
	
	
	




