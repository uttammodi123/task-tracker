#include "storage.h"
#include "task.h"
#include<bits/stdc++.h>

vector<Task> loadTasks(){
    vector<Task> tasks;
    ifstream file("data/tasks.json");

    if (!file.is_open()) {
        cout << "Failed to open tasks.json\n";
    }

    string line;
    while(getline(file, line)){
        if(line.find("\"id\"") != string::npos){
            Task t;

            int k = stoi(line.substr(line.find(":") + 1));

            getline(file, line);
            string des = line.substr(line.find(":")+3);
            des.pop_back();
            des.pop_back();

            getline(file, line);
            string stat = line.substr(line.find(":")+3);
            stat.pop_back();
            stat.pop_back();
            
            getline(file, line);
            string creation = line.substr(line.find(":")+3);
            creation.pop_back();
            creation.pop_back();

            getline(file, line);
            string updation = line.substr(line.find(":")+3);
            updation.pop_back();
     
            t.update(k, des, stat, creation, updation);

            tasks.push_back(t);
        }
    }

    file.close();
    return tasks;
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file("data/tasks.json", ios::trunc);

    if (!file.is_open()) {
        cout << "Failed to open tasks.json\n";
        return;
    }

    file << "[\n";

    for (int i = 0; i < tasks.size(); i++) {
        Task it = tasks[i];

        file << "  {\n";
        file << "    \"id\": " << it.getId() << ",\n";
        file << "    \"description\": \"" << it.getDescription() << "\",\n";
        file << "    \"status\": \"" << it.getStatus() << "\",\n";
        file << "    \"created_at\": \"" << it.getCreatedAt() << "\",\n";
        file << "    \"updated_at\": \"" << it.getUpdatedAt() << "\"\n";
        file << "  }";

        if (i != tasks.size() - 1)
            file << ",";

        file << "\n";
    }

    file << "]";
    file.close();
}
