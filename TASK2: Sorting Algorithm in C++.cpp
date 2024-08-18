#include <iostream>
#include <vector>

using namespace std;

// Function to clear the screen
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Function to display the program name
void displayProgramName() {
    cout << "************************************" << endl;
    cout << "*          Quick Sort Tool         *" << endl;
    cout << "************************************" << endl;
    cout << endl;
}

// Function to swap two elements
void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

// Function to find the median of three elements (first, middle, last)
int medianOfThree(vector<double> &arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low])
        swap(arr[mid], arr[low]);
    if (arr[high] < arr[low])
        swap(arr[high], arr[low]);
    if (arr[high] < arr[mid])
        swap(arr[high], arr[mid]);
    return mid;
}

// Partition function using the median-of-three pivot strategy
int partition(vector<double> &arr, int low, int high) {
    int median = medianOfThree(arr, low, high);
    swap(arr[median], arr[high]); // Move median to end
    double pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Optimized Quick Sort function
void quickSort(vector<double> &arr, int low, int high) {
    while (low < high) {
        int pi = partition(arr, low, high);
        if (pi - low < high - pi) {
            quickSort(arr, low, pi - 1);
            low = pi + 1;
        } else {
            quickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}

// Utility function to print an array with "||" as separator
void printArray(const vector<double> &arr) {
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << " | ";
        }
    }
    cout << endl;
}

// Function to display the main menu
void displayMenu() {
    cout << "Main Menu" << endl;
    cout << "1. About the Program" << endl;
    cout << "2. Start Sorting" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to display information about the program
void displayAbout() {
    clearScreen();
    displayProgramName();
    cout << "About the Program:" << endl;
    cout << "This program implements an optimized version of the Quick Sort algorithm in C++." << endl;
    cout << "It allows the user to input a list of integers or decimal numbers and sorts them using Quick Sort." << endl;
    cout << "Optimizations include using the median-of-three strategy for pivot selection." << endl;
    cout << "BY JEREMIE MWEMBO BASASE" << endl;
    cout << endl;
}

// Function to start sorting
void startSorting() {
    clearScreen();
    displayProgramName();
    int n;
    vector<double> arr;

    cout << "Enter the number of elements: ";
    cin >> n;

    arr.resize(n);
    cout << "Enter the elements (integers or decimals):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);
}

int main() {
    int choice;
    do {
        clearScreen();
        displayProgramName();
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displayAbout();
                break;
            case 2:
                startSorting();
                break;
            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please select again." << endl;
                break;
        }

        if (choice != 3) {
            cout << "Press Enter to return to the main menu..." << endl;
            cin.ignore();  // To ignore the newline character left in the input buffer
            cin.get();     // Wait for Enter key press
        }

    } while (choice != 3);

    return 0;
}
