#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	//saves the safe sequence order
	vector<string>order;

	// the allocation, max, and available resources are all stored in an array
	int allocation_T0[3] = {};
	int allocation_T1[3] = {};
	int allocation_T2[3] = {};
	int allocation_T3[3] = {};
	int allocation_T4[3] = {};

	int max_T0[3] = { };
	int max_T1[3] = { };
	int max_T2[3] = { };
	int max_T3[3] = { };
	int max_T4[3] = { };

	int availabel_T0[3] = {};
	int availabel_T1[3] = {};
	int availabel_T2[3] = {};
	int availabel_T3[3] = {};
	int availabel_T4[3] = {};
	int availabel_T5[3] = {};

	//the needed were made into a pointer becuase during are checking process we are going to delete the arrays that have been satisfied
	int* need_T0 = new int[3];
	int* need_T1 = new int[3];
	int* need_T2 = new int[3];
	int* need_T3 = new int[3];
	int* need_T4 = new int[3];

	//asks the user for allocation for each array
	cout << "Enter Allocations for 0" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> allocation_T0[i];
	}
	cout << "Enter Allocations for 1" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> allocation_T1[i];
	}
	cout << "Enter Allocations for 2" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> allocation_T2[i];
	}
	cout << "Enter Allocations for 3" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> allocation_T3[i];
	}
	cout << "Enter Allocations for 4" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> allocation_T4[i];
	}
	cout << endl;
	//asks the user for max for each array 
	cout << "Enter Max for 0" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> max_T0[i];
	}
	cout << "Enter max for 1" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> max_T1[i];
	}
	cout << "Enter max for 2" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> max_T2[i];
	}
	cout << "Enter max for 3" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> max_T3[i];
	}
	cout << "Enter max for 4" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> max_T4[i];
	}
	cout << endl;
	//asks user for current resources avliable
	cout << "Enter Avaliable for 0" << endl;
	for (int i = 0; i < 3; i++)
	{
		cin >> availabel_T0[i];
	}
	string p0 = "P0";
	string p1 = "P1";
	string p2 = "P2";
	string p3 = "P3";
	string p4 = "P4";

	//the amount of process needed is calculated below by subtracting max and allocation
	for (int i = 0; i < 3; i++)
	{
		need_T0[i] = max_T0[i] - allocation_T0[i];
		need_T1[i] = max_T1[i] - allocation_T1[i];
		need_T2[i] = max_T2[i] - allocation_T2[i];
		need_T3[i] = max_T3[i] - allocation_T3[i];
		need_T4[i] = max_T4[i] - allocation_T4[i];
	}

	//a for loop that checks for which the current avaliable resources can satisfty the needed process.
	for (int i = 0; i < 1; i++)
	{
		//here it makes sure the vector size is 0
		if (order.size() == 0)
		{
			//if the first process has enough avaible resources, then it will execute
			while (availabel_T0[i] >= need_T0[i] == true)
			{
				//adds availabel_T0 to allocation_T0 which equals availabel_T1 
				for (int i = 0; i < 3; i++)
				{
					availabel_T1[i] = availabel_T0[i] + allocation_T0[i];
				}
				//then deletes the array because it is no longer needed and its been satisfied
				delete[] need_T0;
				//then made equal to a nullptr so that when checking for the avalability of the array, if the array has been deleted then the array will be nullptr and will not execute
				//but if the array is still there and not deleted then will be able to execute the next loop
				need_T0 = nullptr;
				//saves the safe sequnce order
				order.push_back(p0);
				//then breaks out of the while loop and then goes onto the next for loop, if this loop was already executed
				break;
			}
		}
		//here it makes sure the vector size is 0
		if (order.size() == 0)
		{
			//if the first process has enough avaible resources, then it will execute
			while (availabel_T0[i] >= need_T1[i] == true)
			{
				//adds availabel_T0 to allocation_T0 which equals availabel_T1 
				for (int i = 0; i < 3; i++)
				{
					availabel_T1[i] = availabel_T0[i] + allocation_T1[i];
				}
				//then deletes the array because it is no longer needed and its been satisfied
				delete[] need_T1;
				//then made equal to a nullptr so that when checking for the avalability of the array, if the array has been deleted then the array will be nullptr and will not execute
				//but if the array is still there and not deleted then will be able to execute the next loop
				need_T1 = nullptr;
				//saves the safe sequnce order
				order.push_back(p1);
				//then breaks out of the while loop and then goes onto the next for loop, if this loop was already executed
				break;
			}
		}
		//rest of the for loop is the same thing, checks for each one of them specificly
		if (order.size() == 0)
		{
			while (availabel_T0[i] >= need_T2[i] == true)
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T1[i] = availabel_T0[i] + allocation_T2[i];
				}
				delete[] need_T2;
				need_T2 = nullptr;
				order.push_back(p2);
				break;
			}
		}
		if (order.size() == 0 )
		{
			while (availabel_T0[i] >= need_T3[i] == true)
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T1[i] = availabel_T0[i] + allocation_T3[i];
				}
				delete[] need_T3;
				need_T3 = nullptr;
				order.push_back(p3);
				break;
			}
		}
		if (order.size() == 0 )
		{
			while (availabel_T0[i] >= need_T4[i] == true)
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T1[i] = availabel_T0[i] + allocation_T4[i];
				}
				delete[] need_T4;
				need_T4 = nullptr;
				order.push_back(p4);
				break;
			}
		}
	}
		
	

	//check for the second process in order
	for (int i = 0; i < 1; i++)
	{
		if (order.size()==1 && need_T0!=nullptr )
		{
			while (availabel_T1[i] >= need_T0[i] == true)
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T2[i] = availabel_T1[i] + allocation_T0[i];
				}
				delete[] need_T0;
				need_T0 = nullptr;
				order.push_back(p0);
				break;
			}
		}
		

		if (order.size() == 1 && need_T1!=nullptr)
		{
			while (availabel_T1[i] >= need_T1[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T2[i] = availabel_T1[i] + allocation_T1[i];
				}
				delete[] need_T1;
				need_T1 = nullptr;
				order.push_back(p1);
				break;
			}
		}

		if (order.size() == 1 && need_T2 != nullptr)
		{

			while (availabel_T1[i] >= need_T2[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T2[i] = availabel_T1[i] + allocation_T2[i];
				}
				delete[] need_T2;
				need_T2 = nullptr;
				order.push_back(p2);
				break;
			}
		}

		if (order.size() == 1 && need_T3 != nullptr)
		{
			while (availabel_T1[i] >= need_T3[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T2[i] = availabel_T1[i] + allocation_T3[i];
				}
				delete[] need_T3;
				need_T3 = nullptr;
				order.push_back(p3);
				break;
			}
		}

		if (order.size() == 1 && need_T4 != nullptr)
		{
			while (availabel_T1[i] >= need_T4[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T2[i] = availabel_T1[i] + allocation_T4[i];
				}
				delete[] need_T4;
				need_T4 = nullptr;
				order.push_back(p4);
				break;
			}
		}
	}
	

	//check for the third set
	for (int i = 0; i < 1; i++)
	{
		if (order.size() == 2 && need_T0 != nullptr)
		{
			while (availabel_T2[i] >= need_T0[i] == true)
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T3[i] = availabel_T2[i] + allocation_T0[i];
				}
				delete[] need_T0;
				need_T0 = nullptr;
				order.push_back(p0);
				break;
			}
		}


		if (order.size() == 2 && need_T1 != nullptr)
		{
			while (availabel_T2[i] >= need_T1[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T3[i] = availabel_T2[i] + allocation_T1[i];
				}
				delete[] need_T1;
				need_T1 = nullptr;
				order.push_back(p1);
				break;
			}
		}

		if (order.size() == 2 && need_T2 != nullptr)
		{

			while (availabel_T2[i] >= need_T2[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T3[i] = availabel_T2[i] + allocation_T2[i];
				}
				delete[] need_T2;
				need_T2 = nullptr;
				order.push_back(p2);
				break;
			}
		}

		if (order.size() == 2 && need_T3 != nullptr)
		{
			while (availabel_T2[i] >= need_T3[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T3[i] = availabel_T2[i] + allocation_T3[i];
				}
				delete[] need_T3;
				need_T3 = nullptr;
				order.push_back(p3);
				break;
			}
		}

		if (order.size() == 2 && need_T4 != nullptr)
		{
			while (availabel_T2[i] >= need_T4[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T3[i] = availabel_T2[i] + allocation_T4[i];
				}
				delete[] need_T4;
				need_T4 = nullptr;
				order.push_back(p4);
				break;
			}
		}
	}

	
	//check foruth set
	for (int i = 0; i < 1; i++)
	{
		if (order.size() == 3 && need_T0 != nullptr)
		{
			while (availabel_T3[i] >= need_T0[i] == true)
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T4[i] = availabel_T3[i] + allocation_T0[i];
				}
				delete[] need_T0;
				need_T0 = nullptr;
				order.push_back(p0);
				break;
			}
		}


		if (order.size() == 3 && need_T1 != nullptr)
		{
			while (availabel_T3[i] >= need_T1[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T4[i] = availabel_T3[i] + allocation_T1[i];
				}
				delete[] need_T1;
				need_T1 = nullptr;
				order.push_back(p1);
				break;
			}
		}

		if (order.size() == 3 && need_T2 != nullptr)
		{

			while (availabel_T3[i] >= need_T2[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T4[i] = availabel_T3[i] + allocation_T2[i];
				}
				delete[] need_T2;
				need_T2 = nullptr;
				order.push_back(p2);
				break;
			}
		}

		if (order.size() == 3 && need_T3 != nullptr)
		{
			while (availabel_T3[i] >= need_T3[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T4[i] = availabel_T3[i] + allocation_T3[i];
				}
				delete[] need_T3;
				need_T3 = nullptr;
				order.push_back(p3);
				break;
			}
		}

		if (order.size() == 3 && need_T4 != nullptr)
		{
			while (availabel_T3[i] >= need_T4[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T4[i] = availabel_T3[i] + allocation_T4[i];
				}
				delete[] need_T4;
				need_T4 = nullptr;
				order.push_back(p4);
				break;
			}
		}
	}

	

	//check fifth set
	for (int i = 0; i < 1; i++)
	{
		if (order.size() == 4 && need_T0 != nullptr)
		{
			while (availabel_T4[i] >= need_T0[i] == true)
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T5[i] = availabel_T4[i] + allocation_T0[i];
				}
				delete[] need_T0;
				need_T0 = nullptr;
				order.push_back(p0);
				break;
			}
		}


		if (order.size() == 4 && need_T1 != nullptr)
		{
			while (availabel_T4[i] >= need_T1[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T5[i] = availabel_T4[i] + allocation_T1[i];
				}
				delete[] need_T1;
				need_T1 = nullptr;
				order.push_back(p1);
				break;
			}
		}

		if (order.size() == 4 && need_T2 != nullptr)
		{

			while (availabel_T4[i] >= need_T2[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T5[i] = availabel_T4[i] + allocation_T2[i];
				}
				delete[] need_T2;
				need_T2 = nullptr;
				order.push_back(p2);
				break;
			}
		}

		if (order.size() == 4 && need_T3 != nullptr)
		{
			while (availabel_T4[i] >= need_T3[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T5[i] = availabel_T4[i] + allocation_T3[i];
				}
				delete[] need_T3;
				need_T3 = nullptr;
				order.push_back(p3);
				break;
			}
		}

		if (order.size() == 4 && need_T4 != nullptr)
		{
			while (availabel_T4[i] >= need_T4[i])
			{
				for (int i = 0; i < 3; i++)
				{
					availabel_T5[i] = availabel_T4[i] + allocation_T4[i];
				}
				delete[] need_T4;
				need_T4 = nullptr;
				order.push_back(p4);
				break;
			}
		}
	}
	
	//print out the allocation
	cout << "Allocation" << endl;
	cout << "A B C" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << allocation_T0[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << allocation_T1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << allocation_T2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << allocation_T3[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << allocation_T4[i] << " ";
	}
	cout << endl;
	//print out the max
	cout << "Max" << endl;
	cout << "A B C" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << max_T0[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << max_T1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << max_T2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << max_T3[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << max_T4[i] << " ";
	}
	cout << endl;

	cout << "Available" << endl;
	cout << "A B C" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << availabel_T0[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << availabel_T1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << availabel_T2[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << availabel_T3[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << availabel_T4[i] << " ";
	}
	cout << endl;

	cout << "Max avaliable space is" << endl;
	cout << "A  B  C" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << availabel_T5[i] << " ";
	}
	cout << endl;

	cout << "Safe sequence is" << endl;
	for (int i = 0; i < order.size(); i++) 
	{
		cout << order.at(i)<<" ";
	}

}