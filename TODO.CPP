#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>

const int MAX_TASKS = 100;
char tasks[MAX_TASKS][100];
int taskCount = 0;

void loadTasks()
{
	ifstream file("todo.txt");
	taskCount = 0;
	while
	(file.getline(tasks[taskCount], 100))
	{
		taskCount++;
	}
	file.close();
}

void saveTasks()
{
	ofstream file("todo.txt");
	for(int i = 1; i < taskCount; i++)
	{
		file << tasks[i] << endl;
	}
	file.close();
}

void addTask()
{
	if(taskCount >= MAX_TASKS)
	{
		cout << "Task list is full\n";
		return;
	}
	cout << "Enter task: ";
	cin.ignore();
	cin.getline(tasks[taskCount], 100);
	taskCount++;
	saveTasks();
	cout << "Task added successfully.\n";
}

void viewTasks()
{
	if(taskCount == 0)
	{
		cout << "No tasks available.\n";
		return;
	}
	cout << "\n--- To-Do List ---\n";
	for(int i = 0; i < taskCount; i++)
	{
		cout << i + 1 << " . " << tasks[i] << endl;
	}
}

void deleteTask()
{
	int num;
	viewTasks();
	if(taskCount == 0)
		return;
	cout << "Enter task number to delete: ";
	cin >> num;
	if(taskCount == 0)
	{
		cout << "Invalid task number!\n";
			return;
	}
	for(int i = num - 1; i < taskCount - 1; i++)
	{
		strcpy(tasks[i], tasks[i + 1]);
	}
	taskCount--;
	cout << "Task deleted successfull.\n";
}

int main()
{
	int choice;
	loadTasks();
	do
	{
		cout << "\n--- To-Do List Manager ---\n";
		cout << "1. Add Task\n";
		cout << "2. View Tasks\n";
		cout << "3. Delete Tasks\n";
		cout << "4. Exit\n";
		cin >> choice;

		switch(choice)
		{
			case 1: addTask();
				break;
			case 2: viewTasks();
				break;
			case 3: deleteTask();
				break;
			case 4: cout << "Exiting...\n";
				break;
			default: cout << "Invalid choice!\n";
		}
	}
	while(choice != 4);
	return 0;
}