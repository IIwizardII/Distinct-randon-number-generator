#include <bits/stdc++.h>
#include <chrono>
#include <windows.h>
using namespace std;
#define length 100000000
#define size_1 100000000

void select();
void search_number();
void linear_search();
void file();
void search_again();
void binary_search();
void random_number_generator();
void create_again();
void exit();


int checker[length];
int store[length];
int copy_numbers[size_1];


void random_number_generator(){
    ofstream file;
    file.open("project.txt");
    int i,j,k,random,r,len=length;
    for(i=0;i<length;i++){
        checker[i]=0;
    }
    srand(time(0));
    for(i=0;i<len;i++){
        random=(rand()*rand())%length;
        r=random;
            if(checker[r]==0){
                checker[r]=1;
                file << r << endl;
                }
            else{
                len++;
            }
        }
}


void read_numbers(){
    ifstream file;
    file.open("project.txt");
    int num;
    int i,j,k,limit;
    int count=0;
    cout << "Enter the limit: ";
    cin >> limit;
    while(file >> num){
        copy_numbers[count]=num;
        if(limit==count)
            break;
        count++;

    }
    k=count;
0

    for(i=0;i<count;i++){
        cout << copy_numbers[i] << endl;
    }
    cout << "enter the number u want to search in linear method: ";
    int a,index,flag=0,m;
    cin >> a;
    clock_t time;
    auto start_linear = chrono::high_resolution_clock::now(); //the clock with the shortest tick period available
    time=clock();
    for(int m=0;m<k;m++){
        if(copy_numbers[m]==a){
            index=m;
            flag=1;
            break;
    }
    }
    auto finish_linear = chrono::high_resolution_clock::now();
    time=clock()-time;
        if(flag==1)
            cout << "index: " << index << " time: " << ((float)time/CLOCKS_PER_SEC)*pow(10,9) << " ns" << endl;
        else
            cout << "not found" << " time: " << ((float)time/CLOCKS_PER_SEC)*pow(10,9) << " ns" << endl;
    cout << "index: " << index << " time: " <<  chrono::duration_cast<chrono::nanoseconds>(finish_linear-start_linear).count() << " ns\n";




    int temp;
        for (int i = 0; i < k; i++){
            j = i;

            while (j > 0 && copy_numbers[j] < copy_numbers[j - 1]){
                temp = copy_numbers[j];
                copy_numbers[j] = copy_numbers[j - 1];
                copy_numbers[j - 1] = temp;
                j--;
            }
        }
    cout << "enter the number u want to search in binary method: ";
    cin >> a;
    int mid;
    int first,last,middle;
    auto start_binary = chrono::high_resolution_clock::now();


    first = 0;
	last = k-1;
	middle = (first+last)/2;
	while (first <= last)
	{
		if(copy_numbers[middle] < a)
		{
			first = middle + 1;

		}
		else if(copy_numbers[middle] == a)
		{
			cout<<a<<" found at location "<<middle<<"\n";
			break;
		}
		else
		{
			 last = middle - 1;
		}
		middle = (first + last)/2;
	}
	if(first > last)
	{
		cout<<"Not found! "<<a<<" is not present in the list.";
	}


    auto finish_binary = chrono::high_resolution_clock::now();
cout << chrono::duration_cast<chrono::nanoseconds>(finish_binary-start_binary).count() << " ns\n";

}
void search_number(){
    system("cls");
    system("color 0B");
    cout << "\n\n\n\n\n\t\t\t\t";
    cout << "1.Linear Search\n";
    cout << "\t\t\t\t2.Binary Search\n";
    cout << "\t\t\t\t3.Main Menu\n";
    cout << "\t\t\t\t4.Exit\n";
    cout << "\n\t\t\t\tSelect an option: ";

    int s;
    cin >> s;
    if(s==1)
        linear_search();
    else if(s==2)
        binary_search();
    else if(s==3)
        select();
    else if(s==4)
        exit();
    else
        search_number();

}

void linear_search(){
    system("cls");
    system("color 0D");
    cout << "\n\n\n\n\n\t\t";
    cout << "Select amount of numbers you want to search from: \n";
    cout << "\t\t\t\t1. 10000\n";
    cout << "\t\t\t\t2. 100000\n";
    cout << "\t\t\t\t3. 1000000\n";
    cout << "\t\t\t\t4. 10000000\n";
    cout << "\t\t\t\t5. 100000000\n";
    cout << "\t\t\t\t6. 1000000000\n";
    cout << "\t\t\t\t7. Back\n";
    cout << "\t\t\t\t8. Main Menu\n";
    cout << "\t\t\t\t9. Exit\n";
    cout << "\n\t\t\t\tSelect an option: ";

    int a;
    cin >> a;

    if(a==1)




}

void file(){
    system("cls");
    system("color 0F");
    clock_t t;
    ifstream file_1;

    cout << "\n\n\n\n\n\t\t\t\t";
    cout << "Enter the number you want to search: ";


    search_again();


}




void select(){
    system("cls");
    system("color 0A");

    cout << "\n\n\n\n\n\t\t\t\t";
    cout << "1.Do a Search\n";
    cout << "\t\t\t\t2.Create Random Numbers\n";
    cout << "\t\t\t\t3.Exit\n";
    cout << "\n\t\t\t\tSelect an option: ";

    int s;
    cin >> s;
    if(s==1)
        search_number();
    else if(s==2)
        create_random_number();
    else if(s==3)
        exit();
    else
        select();
}

int main(){
    select();

    cout << "\n\n\n\n\n\n";
return 0;
}
