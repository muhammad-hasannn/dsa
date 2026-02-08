/*Alien Artifact Frequency Scanner*/

#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int start = 0, end = n-1;

    while(start <= end){
        int mid = (start+end)/2;

        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) end = mid-1;
        else start = mid+1;
    }
    return -1;
}

int main(){
    int freq[15] = {103, 107, 112, 115, 118, 123, 130, 137, 145, 150, 158, 162, 170, 175, 180};

    int targetFreq = 0;
    cout << "Enter the frequency to scan (in MHz): ";
    cin >> targetFreq;

    cout << "\n\nSearching..." << endl;
    int valueId = binarySearch(freq, 15, targetFreq);
    if(valueId != -1){
        if(freq[valueId]%5 == 0) cout << "Warning: High-energy alien device detected at frequency "<<targetFreq<<" MHz!" << endl;
        else cout << "Signal found at frequency "<<targetFreq<<" MHz. Safe to investigate" << endl;

        return 0;
    }
    cout << "No such signal detected. Frequency "<<targetFreq<<" MHz not in range." << endl;
    
}