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

public:

    void update(int id, string description, string status, string createdAt, string updatedAt){
        this->id = id;
        this->description = description;
        this->status = status;
        this->createdAt = createdAt;
        this->updatedAt = updatedAt;
    }

    int getId(){
        return id;
    }

    string getdescription(){
        return description;
    }

    string getStatus(){
        return status;
    }

    string getCreatedAt(){
        return createdAt;
    }

    string getUpdatedAtt(){
        return updatedAt;
    }


};

#endif