#include<iostream>// for input output
#include<fstream>//to read and write or for file operation 
#include<sstream>//extract cpu values or parsing the fie content
#include<thread>//introduce a delay
#include<chrono>//introduce a delay
using namespace std;

//
struct CPUData // struct data name
{
long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
};



CPUData getCPUData(){
ifstream file("/proc/stat");

string line; // 
CPUData cpu = {};//Initialize the structure with zero values

if(file.is_open())// file is opening now
{
getline(file, line);//Read first line. GETLINE- if we are writting hello world then it will read hello + space + world
istringstream ss(line);
string cpuLabel;

//how to call the function
ss >> cpuLabel >> cpu.user >> cpu.nice >> cpu.system >> cpu.idle >> cpu.iowait >> cpu.irq >> cpu.softirq >> cpu.steal >> cpu.guest >> cpu.guest_nice;
}
return cpu;
}

double calculateCPUUsage(CPUData prev, CPUData current)
{
long prevIdle = prevIdle + prev.iowait;
long currIdle = current.idle + current.iowait;
long prevTotal = prev.user+ prev.nice+ prev.system+
                 prev.idle+ prev.iowait+ prev.irq+ prev.softirq
                 + prev.steal+ prev.guest+ prev.guest_nice;

long currentTotal = current.user+ current.nice+ current.system
                + current.idle+ current.iowait+ current.irq+ current.softirq
                + current.steal+ current.guest+ current.guest_nice;

long totalDiff = currentTotal - prevTotal;
long idleDiff = currIdle - prevIdle;
return (totalDiff - idleDiff)*100.0 / totalDiff;
}

//calculate CPU usage
int main(){
CPUData prevData = getCPUData();
this_thread::sleep_for(chrono::seconds(1));//wait for 1 second
CPUData cpu = getCPUData();
double cpuUsage = calculateCPUUsage(prevData,cpu);
cout<<"CPU Usage:" << cpuUsage << "%\n";
cout <<cpu.user<<"\n";
cout <<cpu.nice<<"\n";
cout <<cpu.system<<"\n";
cout <<cpu.idle<<"\n";
cout <<cpu. iowait<<"\n";
cout <<cpu.irq<<"\n";
cout <<cpu.softirq<<"\n";
cout <<cpu.steal<<"\n";
cout <<cpu.guest<<"\n";
cout <<cpu.guest_nice<<"\n";
long total_cpu_time = cpu.user+ cpu.nice+ cpu.system+ cpu.idle+ cpu. iowait+ cpu.irq+ cpu.softirq+ cpu.steal+ cpu.guest+ cpu.guest_nice;
cout<<total_cpu_time<<"\n";
int idle_time=cpu.idle+cpu.iowait;
cout<< idle_time <<"\n";
double cpu_usage=((total_cpu_time - idle_time)/total_cpu_time)*100; // total_cpu_time;
cout<<cpu_usage<<"\n";
return 0;
}
//CPUData currData = getCPUData();
