// https://www.linkedin.com/in/mousa123/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Represents a single print job with all its information
struct PrintJob {
    string computerId;  // Which computer sent the job
    int arrivalHour;    // When it arrived (hour)
    int arrivalMinute;  // When it arrived (minute)
    int durationMinutes; // How long it takes to print
    int startTime;      // When printing actually started
    int waitTime;       // How long it waited before printing
};

// Our queue system (like people lining up for a printer)
class PrintQueue {
    struct QueueNode {
        PrintJob job;
        QueueNode* next;
    };
    
    QueueNode* front; // First job in line
    QueueNode* rear;  // Last job in line

public:
    PrintQueue() : front(nullptr), rear(nullptr) {}

    // Add a new job to the end of the queue
    void enqueue(PrintJob newJob) {
        QueueNode* newNode = new QueueNode{newJob, nullptr};
        if (!front) front = newNode;  // If queue is empty
        else rear->next = newNode;    // Add to end
        rear = newNode;              // Update rear pointer
    }

    // Remove and return the first job in line
    PrintJob dequeue() {
        PrintJob job = front->job;
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        return job;
    }

    // Check if queue is empty
    bool isEmpty() { return front == nullptr; }
};

// Helper to convert hours+mins to total minutes
int convertToMinutes(int hours, int minutes) { 
    return hours * 60 + minutes; 
}

int main() {
    PrintJob jobList[50];  // Array to store all jobs
    int jobCount = 0;      // How many jobs we have

    // Read jobs from file
    ifstream inputFile("printer.txt");
    int totalJobs;
    inputFile >> totalJobs;
    while (jobCount < totalJobs) {
        string computerId, timeString;
        int duration;
        inputFile >> computerId >> timeString >> duration;
        jobList[jobCount++] = {
            computerId, 
            stoi(timeString.substr(0,2)),  // Extract hours
            stoi(timeString.substr(3,2)),  // Extract minutes
            duration, 
            0, 
            0
        };
    }

    // Sort jobs by arrival time (and duration if same time)
    for (int i = 0; i < jobCount-1; i++)
        for (int j = 0; j < jobCount-i-1; j++) {
            int time1 = convertToMinutes(jobList[j].arrivalHour, jobList[j].arrivalMinute);
            int time2 = convertToMinutes(jobList[j+1].arrivalHour, jobList[j+1].arrivalMinute);
            if (time1 > time2 || (time1 == time2 && jobList[j].durationMinutes > jobList[j+1].durationMinutes))
                swap(jobList[j], jobList[j+1]);
        }

    PrintQueue jobQueue;
    int printerAvailableAt = 0;  // When printer will be free
    int totalPrintingTime = 0;   // Total time printer was busy

    // Process each job
    for (int i = 0; i < jobCount; i++) {
        int arrivalTime = convertToMinutes(jobList[i].arrivalHour, jobList[i].arrivalMinute);
        
        // Job starts at either its arrival time or when printer is free, whichever is later
        jobList[i].startTime = max(arrivalTime, printerAvailableAt);
        jobList[i].waitTime = jobList[i].startTime - arrivalTime;
        
        // Printer will be free after this job finishes
        printerAvailableAt = jobList[i].startTime + jobList[i].durationMinutes;
        totalPrintingTime += jobList[i].durationMinutes;
        
        jobQueue.enqueue(jobList[i]);
    }

    // Print results
    cout << "Jobs Executed: " << jobCount << endl;
    while (!jobQueue.isEmpty()) {
        PrintJob currentJob = jobQueue.dequeue();
        cout << currentJob.computerId << " " 
             << setw(2) << setfill('0') << currentJob.arrivalHour << ":"
             << setw(2) << setfill('0') << currentJob.arrivalMinute << " "
             << currentJob.durationMinutes << " executed at "
             << setw(2) << setfill('0') << currentJob.startTime/60 << ":"
             << setw(2) << setfill('0') << currentJob.startTime%60 << " waiting time: "
             << currentJob.waitTime << endl;
    }

    cout << "The printer was occupied for " << totalPrintingTime << " minutes\n";
    double averageWait = 0;
    for (int i = 0; i < jobCount; i++) averageWait += jobList[i].waitTime;
    cout << fixed << setprecision(2);
    cout << "Average waiting time is " << averageWait/jobCount << " minutes\n";
}