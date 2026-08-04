#include <iostream>
using namespace std;

// void greet();

// int main(){
//     greet();
//     return 0;
// }

// void greet(){
//     cout<<"Hello !!!!";
// }

int add(int num){
    if(num==0){
        return 0;
    } else {
        return num + add(num-1);
    }
}

int main(){
    int num;
    cout<<"Enter a number:";
    cin>>num;
    cout<<"Sum of first "<<num<<" natural numbers is "<<add(num)<<endl;
    return 0;
}