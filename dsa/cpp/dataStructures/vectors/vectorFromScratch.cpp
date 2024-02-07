#include <iostream>

using namespace std;

template<class T>
class Vector {
    T *arr, *temp;
    int vectorSize = 0, currentIndex = 0;

    public:
        Vector() {
            arr = new T[1];
        }

        ~Vector() {
            // deallocate storage for arrays
            delete[] arr, temp;
        }

        void push_back(T data) {
            cout << "Add data to back of vector" << endl;
            // set data at current index 
            arr[currentIndex] = data;
            
            // increment current index and vector size for next possible data item
            currentIndex++;
            vectorSize++;
            increaseCapacity();
        }

        void pop_back() {
            cout << "Remove element at back of vector" << endl;
            // decrease pointers for vector's capacity
            currentIndex--;
            vectorSize--;

            // migrate data to new array with less capacity
            temp = new T[vectorSize-1];
            for (int i = 0; i < vectorSize; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }

        void increaseCapacity() {
            cout << "Increase capacity of vector" << endl;
            // migrate data to new array with more capacity
            temp = new T[vectorSize + 1];
            for (int i = 0; i < vectorSize; i++)
            {
                temp[i] = arr[i];
            }

            // deallocate memory for old array
            delete[] arr;

            // set array to new enlarged array
            arr = temp;
        }

        void print() {
            cout << "Print data in vector" << endl;
            for (int i=0; i<vectorSize; i++) {
                cout << arr[i] << endl;
            }
        }

        // front
        T front() {
            cout << "Return value at front of vector" << endl;
            return arr[0];
        }
        
        // back
        T back() {
            cout << "Return value at back of vector" << endl;
            return arr[currentIndex-1];
        }

        // at
        T at(int ind) {
            cout << "Return value at index " << ind << endl;
            if(ind>=0 && ind<currentIndex) {
                return arr[ind];
            } else if (ind == -1) {
                return arr[currentIndex-1];
            } else {
                throw invalid_argument("Invalid index");
            }
        }

        // insert
        void insert(int ind, T data) {
            cout << "Insert data at index " << ind << endl;
            // new array with increased capacity
            temp = new T[vectorSize+1];
            
            // iterator for insertions
            int insertionIter=0, arrInd=0;

            // boolean for 'inserted' condition
            bool inserted = false;

            // while insertionIter < vectorSize
                // if insertionIter == ind
                    // temp[insertionIter] = data
                    // inserted = true
                    // insertionIter++
                // else
                    // temp[insertionIter] = arr[arrInd]
                    // insertionIter++
                    // arrInd++

            while (arrInd < vectorSize) {
                if (insertionIter == ind) {
                    temp[insertionIter] = data;
                    inserted = true;
                    insertionIter++;
                } else {
                    temp[insertionIter] = arr[arrInd];
                    insertionIter++;
                    arrInd++;
                }
            }
            delete[] arr;
            arr = temp;
            vectorSize++;
            currentIndex++;
        }

        // erase
        void erase(T data) {
            cout << "Erase data" << endl;
            // remove data if in array
            if(find(data)){
                // new array with double capacity of current array
                // loop thru current array
                // if element != data
                // move element to new array
                // resize array to only fit elements
                temp = new T[2 * vectorSize];
                int newVectorSize = 0, tempInd = 0;
                for (int i = 0; i < vectorSize; i++)
                {
                    if (arr[i] != data)
                    {
                        temp[tempInd] = arr[i];
                        newVectorSize++;
                        tempInd++;
                    }
                }
                arr = new T[newVectorSize + 1];
                for (int i = 0; i < newVectorSize; i++)
                {
                    arr[i] = temp[i];
                }
                vectorSize = newVectorSize;
                currentIndex = newVectorSize;
            } else {
                cout << "Data not in vector" << endl;
            }
        }

        // swap data
        void swapData(T firstData, T secondData)
        {
            cout << "Swap data" << endl;
            if(find(firstData) && find(secondData)) {
                int firstInd = findInd(firstData);
                int secondInd = findInd(secondData);
                if (firstInd>=0 && secondInd>=0) {
                    arr[firstInd] = secondData;
                    arr[secondInd] = firstData;
                }
            } else {
                cout << "All data inputs are not available" << endl;
            }
            return;
        }

        // swap data at indices
        void swapInd(int firstInd, int secondInd)
        {
            cout << "Swap data at indices" << endl;
            if (
                (firstInd >= 0) &&
                (firstInd < vectorSize) && 
                (secondInd >= 0) && 
                (secondInd < vectorSize)
            )
            {
                T temp = arr[firstInd];
                arr[firstInd] = arr[secondInd];
                arr[secondInd] = temp;
            } else {
                cout << "One or more of the index inputs is out of range" << endl;
            }
            return;
        }

        // find
        bool find(T data) {
            cout << "Find data" << endl;
            bool found = false;
            for (int i=0; i<vectorSize; i++) {
                if (arr[i] == data) {
                    found = true;
                    return found;
                }
            }
            return found;
        }

        // findInd: return index of first element that matches input data
        int findInd(T data) {
            if (find(data)) {
                for (int i=0; i<vectorSize; i++) {
                    if (arr[i] == data) {
                        return i;
                    }
                }
            } else {
                return -1;
            }
        }

        // clear
        void clear() {
            cout << "Clear vector" << endl;
            // deallocate memory and call destructor for objects in array
            delete[] arr, temp;
            // set current index and vector size as 0
            currentIndex = 0;
            vectorSize = 0;
            // set arr to array object of size 1
            arr = new T[1];
        }
};

int main() {
    cout << "Vector from Scratch" << endl;
    // create vector
    Vector<int> v;

    // add data to vector
    v.push_back(1);
    v.push_back(10);
    v.push_back(100);
    v.push_back(1000);
    v.push_back(10000);

    // print data in vector
    v.print();

    // remove last element in vector
    v.pop_back();

    // print data in vector
    v.print();

    // print data at front of vector
    cout << v.front() << endl;

    // print data at back of vector
    cout << v.back() << endl;

    // print data at index 1 of vector
    cout << v.at(1) << endl;

    // insert '4' at index 2 of vector
    v.insert(2,4);
    v.print();

    // erase data
    v.erase(10);
    v.print();

    // find data
    cout << v.find(100) << endl;

    // swap data
    v.swapInd(0,3);
    v.print();

    v.swapData(4,100);
    v.print();

    // clear vector
    v.clear();
    v.print();
    
    return 0;
}
