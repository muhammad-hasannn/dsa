/*Tracking Sports Crowd*/

#include<iostream>
using namespace std;

int attendance[10];
int n = 10;

// a) Lowest attendance year 
int lowestAttendanceYear(){
    int minId = 0;

    for(int i = 1; i < n; i++){
        if(attendance[i] < attendance[minId]) minId = i;
    }

    // finding year on the basis of index and returning it
    return 2016+minId;    
}

// b) Highest attendance year
int highestAttendanceYear(){
    int maxId = 0;

    for(int i = 1; i < n; i++){
        if(attendance[i] > attendance[maxId]) maxId = i;
    }

    return 2016+maxId;
}

// c) Total attendance
int totalAttendance(){
    int sum = 0;
    for(int i = 0; i < n; i++) sum += attendance[i];
    return sum;
}

// d) Attendance for a specific year
int specificAttendance(int targetYear){
    int id = targetYear-2016;
    return attendance[id];    
}

// e) Years with Low Attendance: Count how many years had attendance below a given threshold (e.g 3,000).
int yearWithLowAttend(int threshold){
    int count = 0;

    for(int i = 0; i < n; i++){
        if(attendance[i] < threshold) count++;
    }
    return count;
}

// f) Percentage of High-Attendance Years: Compute the percentage of years with attendance above 5,000.
float highAttendYearPer(int threshold){
    int count = 0;

    for(int i = 0; i < n; i++){
        if(attendance[i] > threshold) count++;
    }
    return (count/n)*100.0;
}

// g) Prediction: Compute the average attendance over the given years.
int predictAttendance(){
    int sum = totalAttendance();
    return sum/n;
}

int main(){
    cout << "Enter attendance: " << endl;
    for(int i = 0, year = 2016; i < n; i++){
        cout << "For " << year++ << ": ";
        cin >> attendance[i];
    }

    cout << "\n\t***Attendance Summary***" << endl << endl;
    cout << "1. Year with minimum number of spectators is: " << lowestAttendanceYear() << endl;
    cout << "2. Year with maximum number of attendance is: " << highestAttendanceYear() << endl;
    cout << "3. Total attendance across all years is: " << totalAttendance() << endl;

    int year = 0;
    cout << "\nEnter year to find the attendance: ";
    cin >> year;
    cout << "4. Attendance for " << year << " is: " << specificAttendance(year) << endl;

    int lowThreshold = 0;
    cout << "\nEnter threshold to find total number of years lower than it: ";
    cin >> lowThreshold;
    cout << "5. Total years with attendance lower than "<<lowThreshold<<" are: " << yearWithLowAttend(lowThreshold) << endl;

    int highThreshold = 0;
    cout << "\nEnter threshold to find percentage of years higher than it: ";
    cin >> highThreshold;
    cout << "6. Percentage of years with attendance higher than "<<highThreshold<<" is: " << highAttendYearPer(highThreshold) << endl;
    
    cout << "7. Average attendance is: " << predictAttendance() << endl;
}