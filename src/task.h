#ifndef TASK_H
#define TASK_H

#include<iostream>
#include<string>
using namespace std;

class Task
{
    int id;
    string description;
    string status; //todo, in-progress, done
    string createdAt; //date & time
    string updatedAt;

    string currentTime();

public:

    Task();
    Task(int id, string description);

    void update(int id, string description, string status, string createdAt, string updatedAt);

    int getId();
    string getDescription();
    string getStatus();
    string getCreatedAt();
    string getUpdatedAt();

    void markDone();
    void markInProgress();


};

#endif