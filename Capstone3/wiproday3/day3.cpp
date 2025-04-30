//Display CPU and memory usage per process
//sort the process by CPU/Memory usage
// 14 - utime - user mode time
//15 - - stime - system cpu time - yes time(kernel time)
//22 -start time
//total cpu time = utime + stime
//cat /proc/uptime 
// first number = total uptime in second
// second number = idle time
//idle - cpu is free
//calculate process CPU usage
//CPU Usage =(utime+stime) / system uptime - starttime * 100
#include <fstream>//read files
#include <sstream>//parse data
#include <algorithm> //sort process
#include<iostream>
#include <unistd.h>
#include <filesystem>// used to listen directory inside  or reading the folder
#include<vector>//stores the process
#include<dirent.h>
namespace fs = std::filesystem; 

//define a process info structure
struct ProcessInfo
{
int pid;
std::string name;
double cpuUsage;// structure name
long memoryUsage;
};

//function to read a file value

std::string readFileValue(const std::string &path)
{
std::ifstream file(path);
std::string value;

if(file.is_open())
{
std::getline(file,value);
}

return value;
}

// reads the first line from a file. Used for reading single values from /proc/
// total user time and 2nd one is cpu idle time
//uptime is a variable
//function get system uptimr
double getSystemUptime(){
std::ifstream file("/proc/uptime");
double uptime;
if(file.is_open()){
file >> uptime;
} 
return uptime;
}

// function to get the process information

//ProcessInfo this is out structure name 
ProcessInfo getProcessInfo(int pid, double systemUptime)
{
ProcessInfo pInfo.pid;
pInfo.pid = pid;
std::ifstream file("/proc/" + std::to_string(pid) + "/stat");
    std::string line, processName;
     long utime, stime, starttime;
    if (file.is_open()) {
        std::getline(file, line);
        std::istringstream ss(line);
        std::string token;
        int count = 0;
        while (ss >> token) {
            count++;
            
            if (count == 2) pInfo.name = token;
            else if(count == 14) utime = std::stol(token)
           else if(count == 15) stime = std::stol(token)
           else if(count == 22) starttime = std::stol(token) {
                
            }
            //double CPU Usage =(utime+stime) / systemUptime - starttime * 100
        }
        std::ifstream memFile("/proc/" +std::to_string(pid) + "/status");
        if(memFile.is_open()){
        std::string key, value, unit;
        while (memFile >> key >> value >> unit)
        {
        if(key == "VmRSS:")
        {
        pInfo.memoryUsage = std::stol(value);
        break;
        }
        }
        }
        long total_time = utime + stime;// total cpu time
        double seconds = systemUptime - (starttime / sysconf(_SC_CLK_TCK));
        
       pInfo.cpuUsage = (utime + stime / sysconf(_SC_CLK_TCK))/seconds * 100.0;
      
  
      
     
//calculation
//uptime = 100000
//utime + stime = 20
//starttime = 90000
//Elapsed time = 100000 - (90000/100) = 100
//CPU usage = (20/100)/1000*100=0.2%
}
//Get all process
 std::vector<ProcessInfo>getAllProcesses(){
 std::vector<ProcessInfo> processes;
 double systemUptime = getystemUptime();
 for(const auto &entry : fs::directory_iterator("/proc"))
 {
 if(entry.is_directory())
 {
 std::string filename=entry.path().filename().string():
 if(all_of(filename.begin(), filename.end(), ::isdigit))
 {
 int pid = std::stoi(filename);
 
 
 processes.push_back(getProcessInfo(pid, systemUptime));
 }
 }
 }
 return processes;
 }
 
// another member function
void sortProcesses(std::vector<ProcessInfo> &processes,bool sortByCPU)
{
if(sortByCPU)
{
sort(processes.begin(), processes.end(), [](const ProcessInfo &a, const ProcessInfo &b)
{
return a.cpuUsage > b.cpuUsage;
});

}else{
sort(processes.begin(), processes.end(), [](const ProcessInfo &a, const ProcessInfo &b)
return a.memoryUsage > b.memoryUsage;
});
}
}

// print top processes
   
int main(){
//std::string uptime = readFileValue("/proc/1/stat");
//std::cout<<"System Uptime:" << uptime << std::endl;
//CPU Usage =(utime+stime) / system uptime - starttime * 100
std::vector<ProcessInfo> processes = getAllProcesses();
sortProcesses(processes, true);
std::cout<<"PID\tCPU%\tMemory (kB)\tName\n";
//\t like a tab
for (size_t i=0; i < std:min(processes.size(), size_t(10)); ++i)
{
std::cout<<processes[i].pid << "\t"
         << processes[i].cpuUsage << "%\t"
         << processes[i].memoryUsage << "%\t"
         << processes[i].name << "%\t"
}
return 0;
}
//g++ -std=c++17 day3.cpp

