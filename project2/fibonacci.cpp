#include <iostream>
#include <pthread.h>
#include <vector>
#include <stdlib.h>


// global data structured shared by threads
std::vector<int> v;

void *fib(void *count){
    std::cout << "in fib\n";
    int num1 = 0;
    int num2 = 1;
    //int c = atoi(count);
    std::cout << "count: " << count << std::endl;
    //std::cout << "c:" <<     c << std::endl;
    
    for(int i = 0; i <= 10; i++){
        if (i == 0){
            v.push_back(num1);
        }
        else if (i == 1){
            v.push_back(num2);
        }
        else{
            v.push_back(v[i-2] + v[i-1]);
        }
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]){
    // the thread identifier 
    pthread_t tid; 
    //set of thread attributes
    pthread_attr_t attr;

    /*
    std::cout << "Input amount of fibonacci numbers: ";
    std::cin >> user_count;
    */
    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, fib, argv[1]);
    // wait for the thread to exit
    pthread_join(tid, NULL);

    std::cout << "Fib: ";
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
        //std::cout << i << " ";
    }
    std::cout << std::endl;
}