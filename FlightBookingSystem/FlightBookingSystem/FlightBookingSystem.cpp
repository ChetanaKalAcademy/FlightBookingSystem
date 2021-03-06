// FlightBookingSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Database.h"
#include <fstream>
#include <sstream>

using namespace std;
using namespace FlightBookingSystem;

int displaymenu();
void EnterFlightInformation(Database& db);
void displayflightinformation();
void doFlightReservation(Database& db);
void doFlightCancellation(Database& db);




int main()
{
	Database passengerDB;

	while (true)
	{
		int selection = displaymenu();
		switch (selection)
		{
		case 0:
			return 0;
		case 1:
			doFlightReservation(passengerDB);
			break;
		case 2:
			doFlightCancellation(passengerDB);
			break;
		case 3:
			passengerDB.displayAll();
			break;
		case 4: 
			passengerDB.displayCurrentReservations();
			break;
		case 5:
			passengerDB.displayFormerReservations();
			break;
		case 6:
			displayflightinformation();
			break;
		case 7:
			EnterFlightInformation(passengerDB);
			break;
		case 8:
			passengerDB.WriteFlight();
			break;
		default:
			cerr << "Unknown command." << endl;
			break;


		}
	}
    return 0;
}

int displaymenu()
{
	int selection;

	cout << endl;
	cout << "Flight Reservation System Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Reserve A Flight" << endl;
	cout << "2) Cancel A Flight" << endl;
    cout << "3) List All Reservations" << endl;
	cout << "4) List All Current Reservations" << endl;
	cout << "5) List All Former Reservations" << endl;
	cout << "6) Diplay All Flight Information" << endl;
	cout << "7) Add Flight Information" << endl;
	cout << "8) Write Flight Information to CSV File" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "---> ";

	cin >> selection;

	return selection;

}
void doFlightReservation(Database& db)
{
	string firstname;
	string lastname;
	string gender;
	string address;
	string zipcode;

	cout << "What is your FirstName? ";
	cin >> firstname;
	cout << "what is your LastName? ";
	cin >> lastname;
	cout << "What is your gender? ";
	cin >> gender;
	cout << "What is your Address? ";
	cin >> address;
	cout << "What is your ZipCode? ";
	cin >> zipcode;

	db.addPassenger(firstname, lastname, gender, address, zipcode);
}

void doFlightCancellation(Database& db)
{
	int reservationNumber;
	int seatNumber;

	cout << "ReservationNumber? ";
	cin >> reservationNumber;
	cout << "SeatNumber? ";
	cin >> seatNumber;

	try
	{
		PassengerAndFlightDetails& psngr = db.getPassenger(reservationNumber, seatNumber);
		psngr.CancelFlight();
		cout << "Flight reservation with ReservationNumber " << reservationNumber << " And SeatNumber " << seatNumber << " is cancelled." << endl;
	}
	catch (const std::logic_error& exception)
	{
		cerr << "Unable to cancel the reservation: " << exception.what() << endl;
	}
}

void displayflightinformation()
{
	ifstream file;
	file.open("C:\\Users\\chadhika\\Desktop\\KalAcademy\\flight.csv");
	if (!file.is_open()) std::cout << "ERROR: File Open" << endl;
	string FlightNumber;
	string DepartureDate;
	string DepartureTime;
	string DepartureLocation;
	string ArrivalDate;
	string ArrivalTime;
	string ArrivalLocation;
	string AirlinesName;

	int i = 0;

	while (file.good()) {
		i++;
		getline(file, FlightNumber, ',');
		getline(file, DepartureDate, ',');
		getline(file, DepartureTime, ',');
		getline(file, DepartureLocation, ',');
		getline(file, ArrivalDate, ',');
		getline(file, ArrivalTime, ',');
		getline(file, ArrivalLocation, ',');
		getline(file, AirlinesName, '\n');

		std::cout << "Information of Flight :" << i << endl;
		std::cout << "FlightNumber: " << FlightNumber << endl;
		std::cout << "DepartureDate: " << DepartureDate << endl;
		std::cout << "DepartureTime: " << DepartureTime << endl;
		std::cout << "DepartureLocation: " << DepartureLocation << endl;
		std::cout << "ArrivalDate: " << ArrivalDate << endl;
		std::cout << "ArrivalTime: " << ArrivalTime << endl;
		std::cout << "ArrivalLocation: " << ArrivalLocation << endl;
		std::cout << "AirlinesName: " << AirlinesName << endl;
		std::cout << "______________________________________" << endl;

	}

	file.close();

}

void EnterFlightInformation(Database& db)
{
	
	string DepartureDate;
	string DepartureTime;
	string DepartureLocation;
	string ArrivalDate;
	string ArrivalTime;
	string ArrivalLocation;
	string AirlinesName;

	cout << "What is the DepartureDate? ";
	cin >> DepartureDate;
	cout << "what is the DepartureTime? ";
	cin >> DepartureTime;
	cout << "What is the DepartureLocation? ";
	cin >> DepartureLocation;
	cout << "What is the ArrivalDate? ";
	cin >> ArrivalDate;
	cout << "What is the ArrivalTime? ";
	cin >> ArrivalTime;
	cout << "What is the ArrivalLocation? ";
	cin >> ArrivalLocation;
	cout << "What is the AirlinesName? ";
	cin >> AirlinesName;

	db.addFlightInformation(DepartureDate, DepartureTime, DepartureLocation, ArrivalDate,
		ArrivalTime, ArrivalLocation, AirlinesName);
}
