Year 2 - Sem 2 - Data Structures

### **Project Name: "PrintQueue Simulator"**  
*(A precise name reflecting the printer job scheduling simulation)*  

---

### **Project Overview**  
A **C++ printer job scheduling system** that:  
- Processes print jobs from a file  
- Implements a queue-based scheduling algorithm  
- Calculates wait times and printer utilization  
- Outputs detailed execution statistics  

---

### **Key Features & Technical Implementation**  

#### **1. Print Job Management**  
```cpp
struct PrintJob {
    string computerId;
    int arrivalHour, arrivalMinute;
    int durationMinutes;
    int startTime;  // Calculated during processing
    int waitTime;   // startTime - arrivalTime
};
```
**Key Learning:**  
- Designed a complete job tracking system  
- Mastered time conversion (HH:MM ↔ minutes)  
- Implemented proper data encapsulation  

#### **2. Queue Implementation**  
```cpp
class PrintQueue {
    QueueNode* front; 
    QueueNode* rear;
    
    void enqueue(PrintJob newJob) {
        // Maintains FIFO order with O(1) insertion
    }
    
    PrintJob dequeue() {
        // Removes from front with proper memory cleanup
    }
};
```
**Breakthrough Insight:**  
- Built a production-ready queue from scratch  
- Solved pointer management challenges  
- Implemented proper memory handling  

#### **3. Scheduling Algorithm**  
```cpp
jobList[i].startTime = max(arrivalTime, printerAvailableAt);
jobList[i].waitTime = jobList[i].startTime - arrivalTime;
printerAvailableAt = jobList[i].startTime + duration;
```
**Optimization Achieved:**  
- Non-preemptive scheduling implementation  
- Accurate wait time calculation  
- Printer utilization tracking  

#### **4. File Processing & Output**  
```cpp
ifstream inputFile("printer.txt");
// ...
cout << fixed << setprecision(2);
cout << "Average wait: " << averageWait/jobCount << " minutes\n";
```
**Professional Development:**  
- Robust file I/O handling  
- Formatted console output  
- Statistical analysis (averages, totals)  

---

### **Skills Demonstrated**  

| **Technical Skill**       | **Evidence in Code**                     | **Real-World Relevance**               |
|---------------------------|------------------------------------------|----------------------------------------|
| Data Structures           | Custom queue implementation              | Foundation for OS scheduling           |
| Time Calculations         | HH:MM to minutes conversion              | Critical for time-sensitive systems    |
| File Processing           | Reading/parsing printer.txt              | Common in enterprise systems           |
| Algorithm Design          | Scheduling logic                         | Applicable to CPU/IO scheduling        |
| Memory Management         | Proper node deletion in dequeue()        | Prevents memory leaks                  |

---

### **Why This Matters**  
1. **Real-World Parallels**  
   - Similar to OS process scheduling  
   - Models actual printer spooler systems  

2. **Performance Analysis**  
   - Calculates key metrics (wait times, utilization)  
   - Demonstrates scheduling tradeoffs  

3. **Production-Ready Practices**  
   - Robust error handling (file operations)  
   - Clean memory management  

---

### **Suggested Enhancements**  
1. **Priority Queue**  
   ```cpp
   void enqueueWithPriority(PrintJob job, int priority);
   ```
2. **Interactive Mode**  
   ```cpp
   void addInteractiveJob();  // Manual job entry
   ```
3. **Visualization**  
   ```cpp
   void printTimeline();  // ASCII timeline of jobs
   ```

---

### **Learning Journey**  
This project transformed my understanding from:  
❌ "Queues are simple FIFO structures"  
✅ To: "Queues enable complex resource scheduling systems"  

The debugging process (especially time calculations) taught me precision in temporal logic.  

Contributers: Mousa M Mousa, Mohamed El Sayed (Medo)
