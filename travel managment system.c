





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum values for arrays
#define MAX_HOTELS 7
#define MAX_DESTINATIONS 7
#define MAX_TRIPS 100
#define MAX_VEHICLES 5
#define MAX_PLACES 4

// Structures
typedef struct {
    char name[50];
    int rating;
} Hotel;

typedef struct {
    char destination[50];
    int packagePrice;
    char places[MAX_PLACES][50];
} Package;

typedef struct {
    char name[50];
    char type[50];
    int price;
} Vehicle;

// Fixed data
const char *destinations[] = {"Goa", "Maldives", "Vizag", "Araku", "Chennai", "Kerala", "Hyderabad"};
const char *hotels[] = {"Harita", "Celebrity", "Vanam", "La Ve En Rose", "Purple Leaf", "Hotel SVM", "Mallareddy Hotel"};
const int hotel_ratings[] = {5, 4, 3, 4, 3, 4, 3}; // Ratings of corresponding hotels
const int package_prices[] = {7000, 10000, 3000, 4000, 5000, 5000, 8000}; // Package prices for each destination
const char *vehicles[] = {"Bike", "Scooty", "Royal Enfield", "Car (4-seater)", "Car (6-seater)"};
const char *places[MAX_DESTINATIONS][MAX_PLACES] = {
    {"Chapora Fort", "Anjuna Beach", "Baga Beach", "Deltin Royal Casino"},
    {"Maafushi", "Banana Reef", "Male", "Alimatha Island"},
    {"Dolphins Lighthouse", "Visakha Museme", "Love Vizag", "RK Beach"},
    {"Araku Valley", "Museum", "Borra Caves", "Katiki Waterfalls"},
    {"Marina Bay", "Zoo Park", "Breezy Beach", "National Park"},
    {"Munnar", "Varkala Beach", "Lighthouse", "Guruvayur Temple"},
    {"Charminar", "Golconda", "Iskon Temple", "Jaganath Temple"}
};

// Function prototypes
void displayPackages();
void displayHotels();
void displayVehicles();
void displayPlaces(int destination);
void bookDestination(int packagePrices[], char places[][50]);
void bookHotel(Hotel hotels[], int numHotels);
void bookVehicle();

int main() {
    Hotel hotelsList[MAX_HOTELS];
    Package packages[MAX_DESTINATIONS];
    Vehicle vehiclesList[MAX_VEHICLES];
    int numHotels = MAX_HOTELS; // Since hotels are fixed
    int choice;

    // Populate hotel data
    for (int i = 0; i < MAX_HOTELS; ++i) {
        strcpy(hotelsList[i].name, hotels[i]);
        hotelsList[i].rating = hotel_ratings[i];
    }

    // Populate package data
    for (int i = 0; i < MAX_DESTINATIONS; ++i) {
        strcpy(packages[i].destination, destinations[i]);
        packages[i].packagePrice = package_prices[i];
        for (int j = 0; j < MAX_PLACES; ++j) {
            strcpy(packages[i].places[j], places[i][j]);
        }
    }

    // Populate vehicles data
    for (int i = 0; i < MAX_VEHICLES; ++i) {
        strcpy(vehiclesList[i].name, vehicles[i]);
    }

    do {
        printf("\nTravel Management System\n");
        printf("1. Display Packages\n");
        printf("2. Display Hotels\n");
        printf("3. Display Vehicles\n");
        printf("4. Book Destination Package\n");
        printf("5. Book Hotel\n");
        printf("6. Book Vehicle\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPackages();
                break;
            case 2:
                displayHotels(hotelsList, numHotels);
                break;
            case 3:
                displayVehicles();
                break;
            case 4:
                bookDestination(package_prices, places[0]);
                break;
            case 5:
                bookHotel(hotelsList, numHotels);
                break;
            case 6:
                bookVehicle();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to display available packages
void displayPackages() {
    printf("\nAvailable Packages:\n");
    for (int i = 0; i < MAX_DESTINATIONS; ++i) {
        printf("%d. %s - $%d\n", i + 1, destinations[i], package_prices[i]);
    }
}

// Function to display available hotels
void displayHotels(Hotel hotels[], int numHotels) {
    printf("\nAvailable Hotels:\n");
    for (int i = 0; i < numHotels; ++i) {
        printf("%d. %s - Rating: %d\n", i + 1, hotels[i].name, hotels[i].rating);
    }
}

// Function to display available vehicles
void displayVehicles() {
    printf("\nAvailable Vehicles:\n");
    for (int i = 0; i < MAX_VEHICLES; ++i) {
        printf("%d. %s\n", i + 1, vehicles[i]);
    }
}

// Function to display places to visit in a destination
void displayPlaces(int destination) {
    printf("\nPlaces to visit in %s:\n", destinations[destination]);
    for (int i = 0; i < MAX_PLACES; ++i) {
        printf("%d. %s\n", i + 1, places[destination][i]);
    }
}

// Function to book a destination package
void bookDestination(int packagePrices[], char places[][50]) {
    // Display available packages
    displayPackages();

    // Let user choose a package
    int choice;
    printf("Enter the number of the package you want to book: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= MAX_DESTINATIONS) {
        printf("You have booked the %s package for $%d. Enjoy your trip!\n", destinations[choice - 1], packagePrices[choice - 1]);
        displayPlaces(choice - 1);
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to book a hotel
void bookHotel(Hotel hotels[], int numHotels) {
    // Display available hotels
    displayHotels(hotels, numHotels);

    // Let user choose a hotel
    int choice;
    printf("Enter the number of the hotel you want to book: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= numHotels) {
        printf("You have booked %s. Enjoy your stay!\n", hotels[choice - 1].name);
    } else {
        printf("Invalid choice.\n");
    }
}

// Function to book a vehicle
void bookVehicle() {
    // Display available vehicles
    displayVehicles();

    // Let user choose a vehicle
    int choice;
    printf("Enter the number of the vehicle you want to book: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= MAX_VEHICLES) {
        printf("You have booked a %s. Enjoy your ride!\n", vehicles[choice - 1]);
    } else {
        printf("Invalid choice.\n");
    }
}

    
