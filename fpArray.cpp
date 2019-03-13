class NumberArray{

private:
    float *ptr;
    int arraySize;
    float max,min;

public:
    NumberArray(int);
    ~NumberArray();

    int size() const{
        return arraySize;
    }

    void storeNumber(float num,int ele);

    float retrieveNumber(int ele);

    float getHighest();

    float getLowest();

};

NumberArray::NumberArray(int s){
    arraySize = s;

    ptr = new float [s];

    for (int count = 0; count < arraySize; count++) {
        *(ptr + count) = 0;
    }
}

// Destructor
NumberArray::~NumberArray(){
    if (arraySize > 0) {
        delete[] ptr;
    }
}

void NumberArray::storeNumber(float num,int ele){
    if(ele<arraySize) {
        *(ptr + ele) = num;
    }
}

float NumberArray::retrieveNumber(int ele){
    return *(ptr+ele);
}

float NumberArray::getHighest(){
    float high=*(ptr+0);

    for(int i=1;i<arraySize;i++) {
        if (high < *(ptr + i)) {
            high = *(ptr + i);
        }
    }

    return high;
}

float NumberArray::getLowest(){
    float low=*(ptr+0);

    for(int i=1;i<arraySize;i++) {
        if (low > *(ptr + i)) {
            low = *(ptr + i);
        }
    }

    return low;
}

#include <iostream>

using namespace std;

int main(){
    const int SIZE = 10;

    NumberArray test(SIZE);

    test.storeNumber(1,0);
    test.storeNumber(3,1);
    test.storeNumber(7,2);
    test.storeNumber(2,3);

    cout<<"Highest Value:"<<test.getHighest()<<endl;
    cout<<"Lowest Value:"<<test.getLowest()<<endl;

    return 0;
}