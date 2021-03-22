#include <bits/stdc++.h>

using namespace std;


int getNearest(int x, int y, int target) {
    if (target - x >= y - target)
        return y;
    else
        return x;
}

int getNearestElement(int arr[], int n, int target) {
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];
    int left = 0, right = n, mid = 0;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (target < arr[mid]) {
            if (mid > 0 && target > arr[mid - 1])
                return getNearest(arr[mid - 1], arr[mid], target);
            right = mid;
        } else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getNearest(arr[mid], arr[mid + 1], target);
            left = mid + 1;
        }
    }

    return mid;
}


int main(){
    int N, L, P;
    cin >> N >> L >> P;
    int doorA;

    //intial door
    doorA = (L/2);

    //max = max distance from door
    //occ = max occupants in one cart
    int max = 0;
    int occ = 0;

    // array of passengers per cart initilized
    int passenger[N];
    for(int i = 0; i < N; i++){
        passenger[i] = 0;
    }

    //array representing each door
    int doors[N];
    for(int i = 0; i < N; i++){
        doors[i] = doorA;
        doorA = doorA + L;
    }

    //temp = position where person is standing
    int temp;
    //val = closest door
    int val;

    for(int i = 0; i < P; i++){
        cin >> temp;
        val = getNearestElement(doors, N, temp);
        cout << val;
        if(abs((temp-doors[val]) >max)){
            max = abs((temp-doors[val]));
        }

        //increases count of passengers in the cart
        passenger[val] = passenger[val] + 1;

        // checks if this is greater than current max of passenger per cart
        if(passenger[val]>occ){
            occ = passenger[val];
        }
    }
    cout << max << "\n";
    cout << occ << "\n";
}