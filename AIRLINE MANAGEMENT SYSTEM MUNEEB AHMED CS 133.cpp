#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include<cmath>

using namespace std;

// Constants for maximum number of flights and string fields per flight
const int MAX_FLIGHTS = 100;
const int NUM_STRING_FIELDS = 5; // Number of string attributes: flightNumber, destination, airline, departureTime, status

// Global arrays to store flight data
string flightsData[MAX_FLIGHTS][NUM_STRING_FIELDS]; // 2D array for string attributes
int seatsAvailable[MAX_FLIGHTS];                   // Array for number of available seats
float ticketPrice[MAX_FLIGHTS];                    // Array for ticket prices
int total = 0;                                    // Counter for total number of flights

//  constants for indexing 2D flightData array
const int FLIGHT_NUMBER = 0;
const int DESTINATION = 1;
const int AIRLINE = 2;
const int DEPARTURE_TIME = 3;
const int STATUS = 4;

// Color constants for colored output
#define RED 12
#define GREEN 10
#define YELLOW 14
#define WHITE 15

//FUNCTION TO SET CONSOLE TEXT COLOR
    void setColor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
	}
	
	//custom swap function for strings
	void swapStrings(string& a,string& b){
		string temp=a;
		a=b;
		b=temp;
	}
	
	// swap function for integers
	void swapInts(int& a,int& b){
		int temp=a;
		a=b;
		b=temp;
	}
	
	//Custom swap function for floats
	void swapFloats(float& a,float& b){
		float temp=a;
		a=b;
		b=temp;
	}
	//clear the screen
     void clearScreen(){
	system("cls");
    }

	//PAUSE FUNCTION
	void pause(){
	setColor(GREEN);
	cout<<"\n Press Enter To Continue.";
	setColor(WHITE);
	cin.ignore(10000,'\n');
	cin.get();
}
	
	//adds a new flight to the schedule
   void addFlight(){
	//check if flight schedule is full
	if(total >= MAX_FLIGHTS){
    setColor(RED);
	cout<<"\n Flight Schedule Full!Cannot Add More Flights.\n";
	setColor(WHITE);
    pause();
    return;	
}

//prompt for flight details

    setColor(RED);
    cout<<"\nEnter detail of flight"<<total +1 <<endl;
    setColor(GREEN);
    
    cout<<"Flight Number: ";
    setColor(WHITE);
    cin.ignore(10000,'\n');
    getline(cin,flightsData[total][FLIGHT_NUMBER]);
    setColor(GREEN);
    
    cout<<"Destination:";
    setColor(WHITE);
    getline(cin,flightsData[total][DESTINATION]);
    setColor(GREEN);
    
    cout<<"Airline:";
    setColor(WHITE);
    getline(cin,flightsData[total][AIRLINE]); 
    setColor(GREEN);
    
    cout<<"Departure Time (e.g 14:30):";
    setColor(WHITE);
    getline(cin,flightsData[total][DEPARTURE_TIME]);
    setColor(GREEN);
    
    cout<<"Seats Available:";
    setColor(WHITE);

//validate seats iput

while(!(cin>>seatsAvailable[total]) || seatsAvailable[total] < 0 )
    {
        setColor(RED);
        cout << "Invalid input! Enter positive value: $";
        setColor(WHITE);
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    setColor(GREEN);
    cout << "Ticket Price: $";
    setColor(WHITE);
    // Validate ticket price input
    while (!(cin >> ticketPrice[total]) || ticketPrice[total] <= 0) {
        setColor(RED);
        cout << "Invalid input! Enter positive value: $";
        setColor(WHITE);
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    
    setColor(GREEN);
    cout<<"Flight Status (On Time/Delayed/Canceled): ";
    setColor(WHITE);
    cin.ignore(10000,'\n');
    getline(cin, flightsData[total][STATUS]);

    total++; // Increment flight counter
    
    setColor(GREEN);
    cout<<"\nFlight added successfully!\n";
    setColor(WHITE);
    pause();    
	
}
	
	//Displays all flights in the schedule
	void showAll(){
		//check if there are no flights in schedule
		if(total==0){
			setColor(RED);
			cout<<"\nNo flights in schedule\n";
			setColor(WHITE);
			pause();
		}
		setColor(RED);
		cout<<"\n======= FULL FLIGHT SCHEDULE =======\n";
			setColor(WHITE);
		
		    //Iterate through all flights and display details.............
           for(int i=0;i<total;i++){
           		setColor(YELLOW);
           		cout<<"\n Flight "<<i+1<<endl;
           	    setColor(WHITE);
				cout<<"Flight Number:"<<flightsData[i][FLIGHT_NUMBER]<<endl;
				cout<<"Destination:"<<flightsData[i][DESTINATION]<<endl;
			 	cout<<"Airline:"<<flightsData[i][AIRLINE]<<endl;
			 	cout<<"Departure Time:"<<flightsData[i][DEPARTURE_TIME]<<endl;
			 	cout<<"Seats Available:"<<seatsAvailable[i]<<endl;
			 	cout<<"Ticket Price:"<<ticketPrice[i]<<endl;
			 	cout<<"Status:"<<flightsData[i][STATUS]<<endl;
		   }
		   pause();
		   
	}
	
	// Updates an existing flight's details
	void updateFlight(){
		
		//check if there are no flights in schedule
		if(total==0){
			setColor(RED);
			cout<<"\nNo flights in schedule\n";
			setColor(WHITE);
			pause();
			return;
		}
		
		setColor(GREEN);
		cout<<"\nEnter flight number to update\n";
		setColor(WHITE);
		cin.ignore(10000,'\n');
		string flightNum;
		getline(cin,flightNum);
		
		// Search for flight by flight number
		for(int i=0;i<total;i++){
			if (flightsData[i][FLIGHT_NUMBER]==flightNum) {
            // Display current flight details
            setColor(RED);
            cout<<"\nCurrent details:\n";
            setColor(YELLOW);
                cout<<"Flight Number:"<<flightsData[i][FLIGHT_NUMBER]<<endl;
				cout<<"Destination:"<<flightsData[i][DESTINATION]<<endl;
			 	cout<<"Airline:"<<flightsData[i][AIRLINE]<<endl;
			 	cout<<"Departure Time:"<<flightsData[i][DEPARTURE_TIME]<<endl;
			 	cout<<"Seats Available:"<<seatsAvailable[i]<<endl;
			 	cout<<"Ticket Price:"<<ticketPrice[i]<<endl;
			 	cout<<"Status:"<<flightsData[i][STATUS]<<endl;
			
			//prompt for new details
			setColor(RED);
            cout<<"\nEnter new details:\n";
            setColor(GREEN);
            cout<<"Flight Number:";
            setColor(WHITE);
            getline(cin, flightsData[i][FLIGHT_NUMBER]);
            setColor(GREEN);
            cout<<"Destination:";
            setColor(WHITE);
            getline(cin, flightsData[i][DESTINATION]);
            setColor(GREEN);
            cout<<"Airline:";
            setColor(WHITE);
            getline(cin, flightsData[i][AIRLINE]);
            setColor(GREEN);
            cout<<"Departure Time:";
            setColor(WHITE);
            getline(cin, flightsData[i][DEPARTURE_TIME]);
            setColor(GREEN);
            cout<<"Seats Available:";
            setColor(WHITE);
            while (!(cin>>seatsAvailable[i]) || seatsAvailable[i]<0) {
                setColor(RED);
                cout<<"Invalid input! Enter positive number:";
                setColor(WHITE);
                cin.clear();
                cin.ignore(10000,'\n');
            }
            setColor(GREEN);
            cout<<"Ticket Price: $";
            setColor(WHITE);
            while(!(cin >> ticketPrice[i]) || ticketPrice[i] <= 0) {
                setColor(RED);
                cout<<"Invalid input! Enter positive value: $";
                setColor(WHITE);
                cin.clear();
                cin.ignore(10000,'\n');
            }
            setColor(GREEN);
            cout<<"Status (On Time/Delayed/Canceled): ";
            setColor(WHITE);
            cin.ignore(10000,'\n');
            getline(cin,flightsData[i][STATUS]);

            setColor(GREEN);
            cout<<"\nFlight updated successfully!\n";
            setColor(WHITE);
            pause();
            return;
        }
    }
    setColor(RED);
    cout<<"\nFlight not found\n";
    setColor(WHITE);
    pause();

 }
		
	// Deletes a flight from the schedule
void deleteFlight()	{
		//check if flight schedule is full
	if(total >= MAX_FLIGHTS){
    setColor(RED);
	cout<<"\n Flight Schedule Full!Cannot Add More Flights.\n";
	setColor(WHITE);
    pause();
    return;	
}
setColor(GREEN);
    cout<<"\nEnter flight number to delete:";
    setColor(WHITE);
    cin.ignore(10000,'\n');
    string flightNum;
    getline(cin,flightNum);

    // Search for flight and shift remaining flights to fill gap
    for (int i=0; i<total; i++) {
        if(flightsData[i][FLIGHT_NUMBER]==flightNum) {
            for (int j=i; j<total - 1;j++) {
                for (int k=0; k<NUM_STRING_FIELDS; k++) {
                    flightsData[j][k]=flightsData[j + 1][k];
                }
                seatsAvailable[j]=seatsAvailable[j + 1];
                ticketPrice[j]=ticketPrice[j + 1];
            }
            total--; // Decrement flight counter
            setColor(GREEN);
            cout<<"\nFlight deleted successfully!\n";
            setColor(WHITE);
            pause();
            return;
        }
    }
    setColor(RED);
    cout<<"\nFlight not found\n";
    setColor(WHITE);
    pause();
	
}
// Displays flights with low seat availability (< 10 seats)
void checkAvailability(){
	//check if flight schedule is full
	if(total >= MAX_FLIGHTS){
    setColor(RED);
	cout<<"\n Flight Schedule Full!Cannot Add More Flights.\n";
	setColor(WHITE);
    pause();
    return;	
}
	setColor(RED);
    cout <<"\n======= LOW SEAT ALERTS =======\n";
    setColor(WHITE);
    bool found =false;
    // Iterate through flights and display those with low seats
	for(int i=0;i<total;i++){
		if(seatsAvailable[i] < 10){
			setColor(YELLOW);
			cout<<"Flight Number:"<<flightsData[i][FLIGHT_NUMBER]<<endl;
			cout<<"Destination:"<<flightsData[i][DESTINATION]<<endl;
			cout<<"Seats Available:"<<seatsAvailable[i]<<endl;
			setColor(WHITE);
			found=true;
			
		}
	}
	
	if (!found){
		setColor(RED);
		cout<<"\nNo flight with low seat availablity!";
		setColor(WHITE);
	} 
	pause();	
}	

//display all delayed flights
void viewDelayedFlights(){
	
	//check if there are no flights in schedule
		if(total==0){
			setColor(RED);
			cout<<"\nNo flights in schedule\n";
			setColor(WHITE);
			pause();
			return;
		}
		
		setColor(RED);
    cout<<"\n======= DELAYED FLIGHTS =======\n";
    setColor(WHITE);
    bool found=false;
    // Iterate through flights and display those with "Delayed" status
    for(int i=0;i<total;i++){
		if(flightsData[i][STATUS]=="Delayed"){
			setColor(YELLOW);
			cout<<"Flight Number:"<<flightsData[i][FLIGHT_NUMBER]<<endl;
			cout<<"Destination:"<<flightsData[i][DESTINATION]<<endl;
	        cout<<"Airline:"<<flightsData[i][AIRLINE]<<endl;
			cout<<"Departure Time:"<<flightsData[i][DEPARTURE_TIME]<<endl;
	       setColor(WHITE);
	        found =true;

}
    if(!found){
    	setColor(RED);
        cout<<"\nNo delayed flights\n";
        setColor(WHITE);
  	
	   }
	pause();
	}
}
	
	
	// Searches for a flight by flight number
	void searchFlight(){
		//check if there are no flights in schedule
		if(total==0){
			setColor(RED);
			cout<<"\nNo flights in schedule\n";
			setColor(WHITE);
			pause();
			return;
		}
		
		setColor(GREEN);
    cout << "\nEnter flight number to search: ";
    setColor(WHITE);
    cin.ignore(10000,'\n');
    string flightNum;
    getline(cin,flightNum);

    // Search for flight and display its details
	for(int i=0;i<total;i++){
			if (flightsData[i][FLIGHT_NUMBER]==flightNum) {
            // Display current flight details
            setColor(RED);
            cout<<"\nFlight found!:\n";
            setColor(YELLOW);
                cout<<"Flight Number:"<<flightsData[i][FLIGHT_NUMBER]<<endl;
				cout<<"Destination:"<<flightsData[i][DESTINATION]<<endl;
			 	cout<<"Airline:"<<flightsData[i][AIRLINE]<<endl;
			 	cout<<"Departure Time:"<<flightsData[i][DEPARTURE_TIME]<<endl;
			 	cout<<"Seats Available:"<<seatsAvailable[i]<<endl;
			 	cout<<"Ticket Price:"<<ticketPrice[i]<<endl;
			 	cout<<"Status:"<<flightsData[i][STATUS]<<endl;	
			 	setColor(WHITE);
			 	pause();
			 	return;
	}
}
	setColor(RED);
    cout<<"\nFlight not found\n";
    setColor(WHITE);
    pause();
		
}
// Displays all flights with available seats and not canceled
void viewAvailableFlights(){
	//check if there are no flights in schedule
		if(total==0){
			setColor(RED);
			cout<<"\nNo flights in schedule\n";
			setColor(WHITE);
			pause();
			return;
		}
	setColor(RED);
    cout<<"\n======= AVAILABLE FLIGHTS =======\n";
    setColor(WHITE);
    // Iterate through flights and display those with seats > 0 and not canceled	
	for(int i=0;i<total;i++){
			if (seatsAvailable > 0 && flightsData[i][STATUS] != " Canceled")
			 {
            setColor(YELLOW);
                cout<<"Flight Number:"<<flightsData[i][FLIGHT_NUMBER]<<endl;
				cout<<"Destination:"<<flightsData[i][DESTINATION]<<endl;
			 	cout<<"Airline:"<<flightsData[i][AIRLINE]<<endl;
			 	cout<<"Departure Time:"<<flightsData[i][DEPARTURE_TIME]<<endl;
			 	cout<<"Seats Available:"<<seatsAvailable[i]<<endl;
			 	cout<<"Ticket Price:"<<ticketPrice[i]<<endl;
			 	cout<<"Status:"<<flightsData[i][STATUS]<<endl;	
			 	setColor(WHITE);
			 	pause();
           	}	
          }	
	pause();	
		
   }

// Books seats on a flight and logs to booking history
void bookFlight(const string& loggedInUser) {
    // Check if there are no flights
    if(total==0) {
        setColor(RED);
        cout<<"\nNo flights in schedule\n";
        setColor(WHITE);
        pause();
        return;
    }
    setColor(GREEN);
    cout<<"\nEnter flight number to book: ";
    setColor(WHITE);
    cin.ignore(10000,'\n');
    string flightNum;
    getline(cin,flightNum);
    setColor(GREEN);
    cout<<"Enter number of seats to book:";
    setColor(WHITE);
    int seats;
    cin>>seats;

    // Validate seat input
    if(cin.fail() || seats <= 0) {
        setColor(RED);
        cout<<"\nInvalid number of seats!\n";
        setColor(WHITE);
        cin.clear();
        cin.ignore(10000, '\n');
        pause();
        return;
    }

    // Search for flight and process booking
    for(int i=0; i<total; i++) {
        if(flightsData[i][FLIGHT_NUMBER] == flightNum) {
            if(flightsData[i][STATUS] == "Canceled") {
                setColor(RED);
                cout<<"\nCannot book: Flight is canceled\n";
                setColor(WHITE);
                pause();
                return;
            }
            if(seatsAvailable[i]>=seats) {
                seatsAvailable[i] -= seats;
                float totalCost=seats*ticketPrice[i];
                setColor(GREEN);
                cout<<"\nBooking successful!\n";
                cout<<"Total cost: $"<<totalCost<<endl;
                setColor(WHITE);
                // Log booking to file
                ofstream outFile("booking_history.txt", ios::app);
                if(outFile){
                    outFile<<loggedInUser<<" "<<flightNum<< " " <<seats<<" $"<<totalCost<<endl;
                    outFile.close();
                } else {
                    setColor(RED);
                    cout<<"\nError writing to booking history!\n";
                    setColor(WHITE);
                }
                pause();
                return;
            } else {
                setColor(RED);
                cout<<"\nInsufficient seats. Available: "<<seatsAvailable[i]<<endl;
                setColor(WHITE);
                pause();
                return;
            }
        }
    }
    setColor(RED);
    cout<<"\nFlight not found\n";
    setColor(WHITE);
    pause();
}

// Cancels a booking and updates seat availability
void cancelBooking(const string& loggedInUser) {
    // Check if there are no flights
    if(total==0) {
        setColor(RED);
        cout<<"\nNo flights in schedule\n";
        setColor(WHITE);
        pause();
        return;
    }

    setColor(GREEN);
    cout<<"\nEnter flight number to cancel booking: ";
    setColor(WHITE);
    cin.ignore(10000, '\n');
    string flightNum;
    getline(cin,flightNum);
    setColor(GREEN);
    cout<<"Enter number of seats to cancel:";
    setColor(WHITE);
    int seats;
    cin>>seats;

    // Validate seat input
    if (cin.fail() || seats <= 0) {
        setColor(RED);
        cout << "\nInvalid number of seats!\n";
        setColor(WHITE);
        cin.clear();
        cin.ignore(10000, '\n');
        pause();
        return;
    }

    // Search for flight and process cancellation
    for(int i=0;i<total;i++) {
        if(flightsData[i][FLIGHT_NUMBER]==flightNum) {
            seatsAvailable[i] += seats;
            setColor(GREEN);
            cout<<"\nBooking canceled successfully!\n";
            setColor(WHITE);
            // Log cancellation to file
            ofstream outFile("booking_history.txt", ios::app);
            if (outFile) {
                outFile<<loggedInUser<<" "<<flightNum<<" "<<-seats<<" $0"<<endl;
                outFile.close();
            } else {
                setColor(RED);
                cout<<"\nError writing to booking history!\n";
                setColor(WHITE);
            }
            pause();
            return;
        }
    }
    setColor(RED);
    cout<<"\nFlight not found\n";
    setColor(WHITE);
    pause();
}

// Displays booking history for a user
void viewBookingHistory(const string& loggedInUser) {
    ifstream inFile("booking_history.txt");
    // Check if booking history file exists
    if(!inFile) {
        setColor(RED);
        cout<<"\nNo booking history found\n";
        setColor(WHITE);
        pause();
        return;
    }

    setColor(RED);
    cout<<"\n======= BOOKING HISTORY FOR "<<loggedInUser<<" =======\n";
    setColor(WHITE);
    string user,flightNum,dollarSign;
    int seats;
    float totalCost;
    bool found=false;
    // Read and display bookings for the logged-in user
    while(inFile>>user>>flightNum>>seats>>dollarSign>>totalCost){
        if(user==loggedInUser){
            setColor(YELLOW);
            cout<<"\nFlight Number:"<<flightNum<<endl;
            cout<<"Seats: "<<(seats >= 0 ? "Booked:":"Canceled:")<<abs(seats)<<endl;
            if(seats>=0) {
                cout<<"Total Cost:$"<<totalCost<<endl;
            }
            setColor(WHITE);
            found = true;
        }
    }
    inFile.close();
    if(!found) {
        setColor(RED);
        cout<<"\nNo bookings found\n";
        setColor(WHITE);
    }
    pause();
}

// Displays flights for a specific airline
void viewByAirline() {
    // Check if there are no flights
    if(total==0) {
        setColor(RED);
        cout<<"\nNo flights in schedule\n";
        setColor(WHITE);
        pause();
        return;
    }

    setColor(GREEN);
    cout<<"\nEnter airline name: ";
    setColor(WHITE);
    cin.ignore(10000, '\n');
    string airlineName;
    getline(cin,airlineName);
    bool found=false;

    setColor(RED);
    cout<< "\n======= FLIGHTS BY "<<airlineName<<" =======\n";
    setColor(WHITE);
    // Iterate through flights and display those matching the airline
    for(int i=0; i<total;i++) {
        if(flightsData[i][AIRLINE] == airlineName) {
            setColor(YELLOW);
            cout<<"\nFlight Number: "<<flightsData[i][FLIGHT_NUMBER]<<endl;
            cout<<"Destination: "<<flightsData[i][DESTINATION]<<endl;
            cout<<"Ticket Price: $"<<ticketPrice[i]<<endl;
            cout<<"Seats Available:"<<seatsAvailable[i]<<endl;
            cout<<"Status: "<<flightsData[i][STATUS]<<endl;
            setColor(WHITE);
            found=true;
        }
    }
    if(!found){
        setColor(RED);
        cout<<"\nNo flights found from this airline\n";
        setColor(WHITE);
    }
    pause();
}

// Checks the price of a specific flight
void checkPrice(){
    // Check if there are no flights
    if(total==0){
        setColor(RED);
        cout<<"\nNo flights in schedule\n";
        setColor(WHITE);
        pause();
        return;
    }

    setColor(GREEN);
    cout<<"\nEnter flight number to check price:";
    setColor(WHITE);
    cin.ignore(10000,'\n');
    string flightNum;
    getline(cin,flightNum);

    // Search for flight and display its price
    for(int i=0;i<total;i++) {
        if(flightsData[i][FLIGHT_NUMBER] == flightNum) {
            setColor(YELLOW);
            cout<<"\nFlight Number: "<<flightsData[i][FLIGHT_NUMBER]<<endl;
            cout<<"Ticket Price: $"<<ticketPrice[i]<<endl;
            cout<<"Status:"<<flightsData[i][STATUS]<<endl;
            setColor(WHITE);
            pause();
            return;
        }
    }
    setColor(RED);
    cout<<"\nFlight not found\n";
    setColor(WHITE);
    pause();
}

// Recommends flights to a destination or shows all available flights
void recommendFlights() {
    // Check if there are no flights
    if(total==0){
        setColor(RED);
        cout<<"\nNo flights in schedule\n";
        setColor(WHITE);
        pause();
        return;
    }

    setColor(GREEN);
    cout<<"\nEnter destination (e.g., New York, London): ";
    setColor(WHITE);
    cin.ignore(10000,'\n');
    string dest;
    getline(cin, dest);

    setColor(RED);
    cout<<"\n======= RECOMMENDED FLIGHTS TO "<<dest<<"=======\n";
    setColor(WHITE);
    bool found=false;
    // Search for flights to the specified destination
    for(int i=0; i<total;i++) {
        if(flightsData[i][DESTINATION].find(dest) != string::npos && seatsAvailable[i]>0 && flightsData[i][STATUS] != "Canceled") {
            setColor(YELLOW);
            cout<<"\nFlight Number:"<<flightsData[i][FLIGHT_NUMBER]<<endl;
            cout<<"Airline:"<<flightsData[i][AIRLINE]<<endl;
            cout<<"Departure Time:"<<flightsData[i][DEPARTURE_TIME]<<endl;
            cout<<"Ticket Price: $"<<ticketPrice[i]<<endl;
            cout<<"Status: "<<flightsData[i][STATUS]<<endl;
            setColor(WHITE);
            found= true;
        }
    }

    // If no matching flights, show all available flights
    if(!found){
        setColor(YELLOW);
        cout<<"\nNo flights available to"<<dest<<". Showing all available flights:\n";
        setColor(WHITE);
        for(int i=0; i<total;i++) {
            if(seatsAvailable[i] > 0 && flightsData[i][STATUS] != "Canceled") {
                setColor(YELLOW);
            cout<<"\nFlight Number:"<<flightsData[i][FLIGHT_NUMBER]<<endl;
            cout<<"Departure Time:"<<flightsData[i][DEPARTURE_TIME]<<endl;
            cout<<"Ticket Price: $"<<ticketPrice[i]<<endl;
            cout<<"Status: "<<flightsData[i][STATUS]<<endl;
            setColor(WHITE);
        }
    }
    pause();
}
}

// Displays flights sorted by price (low to high)
void viewSortedByPriceLowToHigh() {
    // Check if there are no flights
    if(total==0) {
        setColor(RED);
        cout<<"\nNo flights in schedule\n";
        setColor(WHITE);
        pause();
        return;
    }

    // Create temporary arrays for sorting
    string tempFlightData[MAX_FLIGHTS][NUM_STRING_FIELDS];
    int tempSeatsAvailable[MAX_FLIGHTS];
    float tempTicketPrice[MAX_FLIGHTS];

    // Copy original data to temporary arrays
    for(int i=0; i<total; i++) {
        for(int k=0; k<NUM_STRING_FIELDS; k++) {
            tempFlightData[i][k] = flightsData[i][k];
        }
        tempSeatsAvailable[i] = seatsAvailable[i];
        tempTicketPrice[i] = ticketPrice[i];
    }

    // Bubble sort by price (low to high)
    for(int i=0; i<total - 1; i++) {
        for(int j=0; j<total - i - 1; j++) {
            if(tempTicketPrice[j] > tempTicketPrice[j + 1]) {
                // Swap all flight data
                for(int k=0; k<NUM_STRING_FIELDS; k++) {
                    swapStrings(tempFlightData[j][k], tempFlightData[j + 1][k]);
                }
                swapInts(tempSeatsAvailable[j], tempSeatsAvailable[j + 1]);
                swapFloats(tempTicketPrice[j], tempTicketPrice[j + 1]);
            }
        }
    }

    setColor(RED);
    cout << "\n======= FLIGHTS SORTED BY PRICE (LOW TO HIGH) =======\n";
    setColor(WHITE);
    // Display sorted flights with available seats and not canceled
    for(int i=0; i<total; i++) {
        if(tempSeatsAvailable[i] > 0 && tempFlightData[i][STATUS] != "Canceled") {
            setColor(YELLOW);
            cout<<"\nFlight Number:"<<tempFlightData[i][FLIGHT_NUMBER]<< endl;
            cout<<"Destination: "<<tempFlightData[i][DESTINATION]<<endl;
            cout<<"Ticket Price: $"<<tempTicketPrice[i]<<endl;
            cout<<"Seats Available: "<<tempSeatsAvailable[i]<<endl;
            cout<<"Status: "<<tempFlightData[i][STATUS]<<endl;
            setColor(WHITE);
        }
    }
    pause();
}


void viewSortedByPriceHighToLow(){
    // Check if there are no flights
    if(total==0) {
        setColor(RED);
        cout<<"\nNo flights in schedule\n";
        setColor(WHITE);
        pause();
        return;
    }

    // Create temporary arrays for sorting
    string tempFlightData[MAX_FLIGHTS][NUM_STRING_FIELDS];
    int tempSeatsAvailable[MAX_FLIGHTS];
    float tempTicketPrice[MAX_FLIGHTS];

    // Copy original data to temporary arrays
    for(int i=0; i<total; i++) {
        for(int k=0; k<NUM_STRING_FIELDS; k++) {
            tempFlightData[i][k] = flightsData[i][k];
        }
        tempSeatsAvailable[i] = seatsAvailable[i];
        tempTicketPrice[i] = ticketPrice[i];
    }

    // Bubble sort by price (high to low)
    for(int i=0; i<total - 1;i++) {
        for(int j=0; j<total - i - 1;j++) {
            if(tempTicketPrice[j] < tempTicketPrice[j + 1]) {
                // Swap all flight data
                for(int k=0; k<NUM_STRING_FIELDS; k++) {
                    swapStrings(tempFlightData[j][k],tempFlightData[j + 1][k]);
                }
                swapInts(tempSeatsAvailable[j],tempSeatsAvailable[j + 1]);
                swapFloats(tempTicketPrice[j],tempTicketPrice[j + 1]);
            }
        }
    }

    setColor(RED);
    cout << "\n======= FLIGHTS SORTED BY PRICE (HIGH TO LOW) =======\n";
    setColor(WHITE);
    // Display sorted flights with available seats and not canceled
    for(int i=0; i<total; i++) {
        if(tempSeatsAvailable[i] > 0 && tempFlightData[i][STATUS] != "Canceled") {
            setColor(YELLOW);
            cout<<"\nFlight Number: "<<tempFlightData[i][FLIGHT_NUMBER]<<endl;
            cout<<"Destination: "<<tempFlightData[i][DESTINATION]<<endl;
            cout<<"Ticket Price: $"<<tempTicketPrice[i]<<endl;
            cout<<"Seats Available:"<<tempSeatsAvailable[i]<<endl;
            cout<<"Status: "<<tempFlightData[i][STATUS]<<endl;
            setColor(WHITE);
        }
    }
    pause();
}

// Saves flight data to a file
void saveToFile() {
    ofstream outFile("airline_data.txt");
    if(outFile){
        outFile<<total<<endl;
        // Write all flight data to file
        for(int i=0; i<total; i++) {
            for(int k=0; k<NUM_STRING_FIELDS; k++) {
                outFile<<flightsData[i][k]<<endl;
            }
            outFile<<seatsAvailable[i]<<endl;
            outFile<<ticketPrice[i]<<endl;
        }
        setColor(GREEN);
        cout<<"\nData saved successfully!\n";
        setColor(WHITE);
        pause();
    } else {
        setColor(RED);
        cout<<"\nError saving data!\n";
        setColor(WHITE);
        pause();
    }
}

// Loads flight data from a file
void loadFromFile() {
    ifstream inFile("airline_data.txt");
    if(inFile){
        inFile>>total;
        inFile.ignore(10000,'\n');
        // Read flight data from file
        for(int i=0; i<total; i++) {
            for(int k=0; k<NUM_STRING_FIELDS; k++) {
                getline(inFile,flightsData[i][k]);
            }
            inFile>>seatsAvailable[i];
            inFile>>ticketPrice[i];
            inFile.ignore(10000,'\n');
        }
        inFile.close();
    }
}

// Checks if a username exists in the user credentials file
bool userExists(const string& username, const string& fileType) {
    if(fileType=="admin") {
        return false; // Not used for admin since credentials are fixed
    }
    string fileName="user_credentials.txt";
    ifstream inFile(fileName.c_str());
    string storedUser,storedPass;
    // Check for matching username
    while(inFile>>storedUser>>storedPass){
        if(storedUser==username){
            inFile.close();
            return true;
        }
    }
    inFile.close();
    return false;
}

// Handles user signup
void signupUser() {
    clearScreen();
    setColor(RED);
    cout<<"\n\n\t\tUSER SIGNUP";
    setColor(GREEN);
    cout<<"\n\t\tEnter Username: ";
    setColor(WHITE);
    string username;
    cin>>username;
    // Check if username already exists
    if(userExists(username, "user")) {
        setColor(RED);
        cout<<"\n\t\tUsername already exists! Please choose another.\n";
        setColor(WHITE);
        pause();
        return;
    }
    setColor(GREEN);
    cout<<"\t\tEnter Password: ";
    setColor(WHITE);
    string password;
    cin>>password;

    // Save credentials to file
    ofstream outFile("user_credentials.txt", ios::app);
    if(outFile) {
        outFile<<username<<" "<<password<<endl;
        outFile.close();
        setColor(GREEN);
        cout<<"\n\t\tSignup successful! You can now log in.\n";
        setColor(WHITE);
    } else {
        setColor(RED);
        cout<<"\n\t\tError saving credentials!\n";
        setColor(WHITE);
    }
    pause();
}

// Verifies user credentials against stored data or fixed admin credentials
bool verifyUser(const string& username, const string& password, const string& fileType) {
    if(fileType=="admin") {
        // Check fixed admin credentials
        if(username=="admin" && password == "123") {
            return true;
        }
        return false;
    } else {
        // Check user credentials from file
        string fileName = "user_credentials.txt";
        ifstream inFile(fileName.c_str());
        string storedUser,storedPass;
        // Check for matching username and password
        while(inFile>>storedUser>>storedPass){
            if(storedUser==username && storedPass==password) {
                inFile.close();
                return true;
            }
        }
        inFile.close();
        return false;
    }
}

// Displays and handles the admin menu
void adminMenu(){
    string choice;
    do{
        clearScreen();
        setColor(RED);
        cout<<"\n\n\t\tADMIN MENU";
        setColor(YELLOW);
        cout<<"\n\t\t1. Add Flight";
        cout<<"\n\t\t2. View All Flights";
        cout<<"\n\t\t3. Update Flight";
        cout<<"\n\t\t4. Delete Flight";
        cout<<"\n\t\t5. Check Low Seat Availability";
        cout<<"\n\t\t6. View Delayed Flights";
        cout<<"\n\t\t7. Save Data to File";
        cout<<"\n\t\t8. Logout";
        cout<<"\n\t\tEnter your choice: ";
        setColor(WHITE);
        cin>>choice;

        // Process menu selection
        if(choice=="1") addFlight();
        else if(choice=="2") showAll();
        else if(choice=="3") updateFlight();
        else if(choice=="4") deleteFlight();
        else if(choice=="5") checkAvailability();
        else if(choice=="6") viewDelayedFlights();
        else if(choice=="7") saveToFile();
        else if(choice=="8") return ;
		
        else {
            setColor(RED);
            cout<<"\nInvalid choice!\n";
            setColor(WHITE);
            pause();
        }
    }while(true);
}

// Displays and handles the user menu
void userMenu(const string& loggedInUser) {
    string choice;
    do{
        clearScreen();
        setColor(RED);
        cout<<"\n\n\t\tUSER MENU (Logged in as: " << loggedInUser << ")";
        setColor(YELLOW);
        cout<<"\n\t\t1. Search Flight";
        cout<<"\n\t\t2. View Available Flights";
        cout<<"\n\t\t3. Book Flight";
        cout<<"\n\t\t4. View Flights by Airline";
        cout<<"\n\t\t5. Check Flight Price";
        cout<<"\n\t\t6. Get Flight Recommendations";
        cout<<"\n\t\t7. Cancel Booking";
        cout<<"\n\t\t8. View Booking History";
        cout<<"\n\t\t9. View Sorted by Price (Low to High)";
        cout<<"\n\t\t10. View Sorted by Price (High to Low)";
        cout<<"\n\t\t11. Logout";
        cout<<"\n\t\tEnter your choice: ";
        setColor(WHITE);
        cin >> choice;

        // Process menu selection
        if(choice=="1") searchFlight();
        else if(choice=="2") viewAvailableFlights();
        else if(choice=="3") bookFlight(loggedInUser);
        else if(choice=="4") viewByAirline();
        else if(choice=="5") checkPrice();
        else if(choice=="6") recommendFlights();
        else if(choice=="7") cancelBooking(loggedInUser);
        else if(choice=="8") viewBookingHistory(loggedInUser);
        else if(choice=="9") viewSortedByPriceLowToHigh();
        else if(choice=="10") viewSortedByPriceHighToLow();
        else if(choice=="11") return;
        else{
            setColor(RED);
            cout<<"\nInvalid choice!\n";
            setColor(WHITE);
            pause();
        }
    } while (true);
}

//main funtion...
int main()
{
	//load existing flight data
	loadFromFile();
	
	// main menu loop
	while(true){
		
	clearScreen();
		
	setColor(RED);
	cout<< "\t\t\t**************************************************\n";
    cout<< "\t\t\t*                                                *\n";
    cout<< "\t\t\t*        WELCOME TO AIRLINE MANAGEMENT           *\n";
    cout<< "\t\t\t*                   SYSTEM                       *\n";
    cout<< "\t\t\t*                                                *\n";
    cout<< "\t\t\t**************************************************\n";
	setColor(YELLOW);
	cout<< "\n\n\t\t1. Admin Login";
    cout<< "\n\t\t2. User Login";
    cout<< "\n\t\t3. User Signup";
    cout<< "\n\t\t4. Exit";
    cout<< "\n\t\tEnter your choice: ";
    setColor(WHITE);
	
	string choice;
	cin>>choice;
	
	if(choice=="1"){
		string username,password;
		clearScreen();
		setColor(RED);
        cout<<"\n\n\t\tADMIN LOGIN";
        setColor(GREEN);
        cout<<"\n\t\tUsername: ";
        setColor(WHITE);
        cin>>username;
        setColor(GREEN);
        cout<<"\t\tPassword: ";
        setColor(WHITE);
	    cin>>password;
	    
	  // Verify user credentials and show admin menu
     if(verifyUser(username, password, "admin")){
     	setColor(GREEN);
     	cout<<"n\t\tAdmin login successful!\n";
     	setColor(WHITE);
        adminMenu();
	    }
	 else
	     {
	     	setColor(RED);
	     	cout<<"\n\t\tInvalid credentials!\n ";
	     	setColor(WHITE);
	     	pause();
	     	
		 }
     }
     
     else if(choice=="2"){
     	
     	string username,password;
     	clearScreen();
     	setColor(RED);
     	cout<<"\n\n\t\tUSER LOGIN";
     	 setColor(GREEN);
     	cout<<"\n\t\tUsername:";
     	setColor(WHITE);
     	cin>>username;
        setColor(GREEN);	
     	cout<<"\t\tPassword:";
     	setColor(WHITE);
		 cin>>password;	
     	
     	 // Verify user credentials and show user menu
     	  if (verifyUser(username, password, "user")){
     	setColor(GREEN);
     	cout<<"n\t\tUser login successful!\n";
     	setColor(WHITE);
        userMenu(username);     
	    }
	 else
	     {
	     	setColor(RED);
	     	cout<<"\n\t\tInvalid credentials!\n ";
	     	setColor(WHITE);
	     	pause();
	    
           	}	
	 }
	 else if(choice=="3"){
	 	signupUser();    
	 }
	 else if (choice=="4"){
	 	setColor(GREEN);
	 	cout<<"\n\t\tThank you for using our system!\n";
	 	setColor(WHITE);
	 }
     else{
     		setColor(RED);
     		cout<<"\n\t\tInvalid Choice!\n";
     		setColor(WHITE);
     		pause();
     		
	     }
    }
	  return 0; 	
}	
	
