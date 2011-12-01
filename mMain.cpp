/*
* By: Seth Bane
* Example program of using set operations on finite sets
*
* Let U be a finite set of real numbers. Given lists of the elements in the unviversal set U
* and in subsets A and B, list the elements in the sets:
* A union B
* A intersect B
* A - B
* not A and not B
*/
//Using as much of standard C as possible
//Note: This program is not optimized for sets of differing sizes, the operation functions need to be updated

#include<stdio.h>
#include<vector>

using std::vector;
void setPrint(vector<int>* A);
void setUnion(vector<int>* A, vector<int>* B, vector<int>* temp);
void setIntersect(vector<int>* A, vector<int>* B, vector<int>* temp);
void setMinus(vector<int>* A, vector<int>* B, vector<int>* temp);


int main()
{
	//intialize Sets U, A, and B to later be added to vectors
	int U[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	int B[10] = {1,2,3,4,11,12,13,14,15,16};
	//Create Vector objets
	vector<int> setU (U, U + sizeof(U) / sizeof(int));
	vector<int> setA (A, A + sizeof(A) / sizeof(int));
	vector<int> setB (B, B + sizeof(B) / sizeof(int));
	vector<int> temp; //Used for results of set operations
	//Pointers to the vectors
	vector<int>* pSetU = &setU;
	vector<int>* pSetA = &setA;
	vector<int>* pSetB = &setB;
	vector<int>* pTemp = &temp;
	//Increase capacity of Temp to size of universal set
	//Print Sets
	printf("Universal Set = ");
	setPrint(pSetU);
	printf("Set A = ");
	setPrint(pSetA);
	printf("Set B = ");
	setPrint(pSetB);
	//Perform A Union B
	setUnion(pSetA, pSetB, pTemp);
	printf("A union B = ");
	setPrint(pTemp);
	//Perform A Intersect B
	setIntersect(pSetA, pSetB, pTemp);
	printf("A intersect B = ");
	setPrint(pTemp);
	//Perform A - B
	setMinus(pSetA, pSetB, pTemp);
	printf("A - B = ");
	setPrint(pTemp);
	//Peform ~A Note: ~A is equivalent to Universal - A
	setMinus(pSetU, pSetA, pTemp);
	printf("~A = ");
	setPrint(pTemp);
	//Perform ~B Note: ~B is equivalent to Universal - B
	setMinus(pSetU, pSetB, pTemp);
	printf("~B = ");
	setPrint(pTemp);
}

/*
* Prints out a given set
*/
void setPrint(vector<int>* A)
{
	//Get size of vector to set loop counter
	//Set up initial formatting
	printf("{");
	//Print all vector values
	for(unsigned i = 0; i < A->size() - 1; i++)
	{
		printf("%d, ", A->at(i));
	}
	//Final formatting
	printf("%d}\n", A->back());
	return;
}

/*
* Returns the Union of set A and set B
*/
void setUnion(vector<int>* A, vector<int>* B, vector<int>* temp)
{
	//Clear temp vector
	if(temp->empty() == false)
		temp->clear();
	//Copy all values of A into temp
	for(unsigned i = 0; i < A->size(); i++)
	{
		temp->push_back(A->at(i));
	}
	//Compare each value of B with the values in temp, if no match add value to temp
	int ctr = 0;
	for(unsigned i = 0; i < B->size(); i++)
	{
		ctr = 0;
		for(unsigned j = 0; j < A->size(); j++)
		{
			if(B->at(i) == A->at(j))
				break;
			else
				ctr++;
		}
		if(ctr == A->size())//No match, so add element from B into temp
		{
			temp->push_back(B->at(i));
		}
	}
}

/*
* Returns the Intersection of set A and set B
*/
void setIntersect(vector<int>* A, vector<int>* B, vector<int>* temp)
{
	if(temp->empty() == false)
		temp->clear();//Clear temp vector
	//Compare Each element of B with Each element of A
	for(unsigned i = 0; i < B->size(); i++)
	{
		for(unsigned j = 0; j < A->size(); j++)
		{
			if(B->at(i) == A->at(j))
				temp->push_back(B->at(i));//If there is match in A and B ad element to temp
		}
	}
}	

/*
* Returns the reults of set A minus set B
*/
void setMinus(vector<int>* A, vector<int>* B, vector<int>* temp)
{
	if(temp->empty() == false)
		temp->clear(); //Cleare temp vector
	//Add Each element of A to temp
	for(unsigned i = 0; i < A->size(); i++)
	{
		temp->push_back(A->at(i));
	}
	//Compare each element of B with temp
	for(unsigned i = 0; i < B->size(); i++)
	{
		for(unsigned j = 0; j < temp->size(); j++)
		{
			if(B->at(i) == temp->at(j))
				temp->erase(temp->begin() + j);
		}
	}
		//If there is a match remove that element from temp
}
