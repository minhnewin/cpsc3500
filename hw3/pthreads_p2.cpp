//
// Created by Matthew Thayer on 1/13/22.
//

/*
 @file: pthreads_skeleton.cpp

 @author: minh nguyen, mnguyen7@seattleu.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu

 @description: A program that demonstrates processes.

 @course: CPSC 3500
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>
using namespace std;

void *routineName(void *arg);
void *countNegatives(void *arg);
void *average(void *arg);
void *reverse(void *arg);

const int SIZE = 10;
int a[SIZE];

// This function shows the skeleton that pthread
// functions must adhere to.
// Copy this skeleton for any pthread function
// you need to define.
// In the copy, modify the name of the function
// and the function body as needed.

int main()
{
    // id is used to store a unique thread identifier,
    // returned by the call to create a new POSIX thread
    pthread_t id;
    pthread_t count;
    pthread_t avg;
    pthread_t rev;

    // rc is used to store the code returned by the
    // call to create a new POSIX thread. The value is
    // zero (0) if the call succeeds.
    int rc1;
    int rc2;
    int rc3;
    int rc4;

    int value;

    // TODO: Add code to perform any needed initialization
    //       or to process user input
    for(int i = 0;i < 10;i++){
        cin >> value;
        a[i] = value;
    }

    // Create thread(s)
    // TODO: Modify according to assignment requirements
    rc1 = pthread_create(&id, NULL, routineName, NULL);


    if (rc1){
        cout << "ERROR; return code from pthread_create() is " << rc1 << endl;
        return -1;
    }

    rc2 = pthread_create(&count, NULL, countNegatives, NULL);


    if (rc2){
        cout << "ERROR; return code from countNegatives is " << rc2 << endl;
        return -1;
    }

    rc3 = pthread_create(&avg, NULL, average, NULL);


    if (rc3){
        cout << "ERROR; return code from average is " << rc3<< endl;
        return -1;
    }

    rc4 = pthread_create(&rev, NULL, reverse, NULL);


    if (rc4){
        cout << "ERROR; return code from reverse is " << rc4 << endl;
        return -1;
    }

    // NOTE: Using exit here will immediately end execution of all threads
    pthread_exit(0);
}

void *routineName(void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality
    cout << "Thread is running..." << endl;
    return 0;
}

void *countNegatives(void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality
    int countnum = 0;
    for(int i = 0;i < 10;i++) {
        if(a[i] < 0){
            countnum++;
        }
    }
    cout << "The number of negative values are: " << countnum << endl;
    return 0;
}

void *average(void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality
    int total = 0;
    for(int i = 0;i < 10;i++) {
        total += a[i];
    }
    int averagenum = total/10;
    cout << "The average of values are: " << averagenum << endl;
    return 0;
}

void *reverse(void *arg)
{
    // TODO: Add code that implements
    //       the thread's functionality
    cout << "The numbers in reverse order: ";
    for(int i = 9;i > -1;i--) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}


