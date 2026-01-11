#include <bits/stdc++.h>
#include "task.h"
#include "storage.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: task-cli <command> [arguments]\n";
        return 0;
    }

    string command = argv[1];

    vector<Task> tasks = loadTasks();

    if(command=="add"){

        if(argc<3){
            cout<<"Error : task description missing\n";
            return 0;
        }

        string description = argv[2];
        int newId = 1;
        for (auto &t : tasks) {
            newId = max(newId, t.getId() + 1);
        }


        Task newTask(newId, description);
        tasks.push_back(newTask);
        saveTasks(tasks);

        cout << "Task added successfully (ID: " << newId << ")\n";
    }
    else if(command == "list"){
        if(tasks.empty()){
            cout<<"No tasks found.\n";
            return 0;
        }

        if(argc==2){
            for(auto &t : tasks){
                cout<<"["<<t.getId()<<"]"
                    <<t.getDescription()
                    <<"("<<t.getStatus()<<")\n";
            }
        }
        else{
            string filter = argv[2];
            bool found = false;

            for(auto &t:tasks){
                if(t.getStatus()==filter){
                    cout<<"["<<t.getId()<<"]"
                        <<t.getDescription()
                        <<"("<<t.getStatus()<<")\n";
                    found = true;
                }
            }

            if(!found) cout<<"No tasks with status : "<<filter<<"\n";
        }
    }
    else if(command == "mark-done"){
        if (argc<3) {
            cout << "Error: task ID missing\n";
            return 0;
        }

        int id = stoi(argv[2]);
        bool found = false;

        for(auto &t: tasks){
            if(t.getId()==id){
                t.markDone();
                found = true;
                break;
            }
        }

        if(!found){
            cout << "Task not found\n";
            return 0;
        }
        saveTasks(tasks);
        cout << "Task marked as done (ID: " << id << ")\n";
    }
    else if(command == "mark-in-progress"){
        if (argc<3) {
            cout << "Error: task ID missing\n";
            return 0;
        }

        int id = stoi(argv[2]);
        bool found = false;

        for(auto &t: tasks){
            if(t.getId()==id){
                t.markInProgress();
                found = true;
                break;
            }
        }

        if(!found){
            cout << "Task not found\n";
            return 0;
        }
        saveTasks(tasks);
        cout << "Task marked as in-progress (ID: " << id << ")\n";
    }
    else if(command =="delete"){
        if (argc<3) {
            cout << "Error: task ID missing\n";
            return 0;
        }

        int id = stoi(argv[2]);
        bool found = false;

        for(auto it = tasks.begin(); it!=tasks.end(); it++){
            if(it->getId()==id){
                tasks.erase(it);
                found = true;
                break;
            }
        }

        if(!found){
            cout << "Task not found\n";
            return 0;
        }
        saveTasks(tasks);
        cout << "Task deleted successfully (ID: " << id << ")\n";
    }
    else if(command == "update"){
        if (argc<4) {
            cout << "Error: task ID or new description missing\n";
            return 0;
        }

        int id = stoi(argv[2]);
        string newDescription = argv[3];
        bool found = false;

        for(auto &t: tasks){
            if(t.getId()==id){
                t.update(t.getId(), newDescription, t.getStatus(), t.getCreatedAt(), "");
                found = true;
                break;
            }
        }

        if(!found){
            cout << "Task not found\n";
            return 0;
        }
        saveTasks(tasks);
        cout << "Task updated successfully (ID: " << id << ")\n";
    }
    else{
        cout << "Unknown command\n";
    }
    
    return 0;
    
    
}
