#include "stdafx.h"
#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace FlightBookingSystem {

	PassengerAndFlightDetails& Database::addPassenger(const std::string& firstname, const std::string& lastname,
		const std::string& gender, const std::string& address, const std::string zipcode)
	{
		PassengerAndFlightDetails thePassenger(firstname, lastname, gender, address, zipcode);
		thePassenger.setReservationNumber(mNextReservationNumber++);
		thePassenger.setSeatNumber(mNextSeatNumber++);
		thePassenger.ReserveFlight();

		mPassengers.push_back(thePassenger);

		return mPassengers[mPassengers.size() - 1];
	}

	FlightInformation& Database::addFlightInformation(const std::string& DepartureDate, const std::string& DepartureTime,
		const std::string& DepartureLocation, const std::string& ArrivalDate, const std::string& ArrivalTime,
		const std::string& ArrivalLocation, const std::string& AirlinesName)
	{
		FlightInformation theFlight(DepartureDate, DepartureTime, DepartureLocation,
		ArrivalDate, ArrivalTime, ArrivalLocation, AirlinesName);
		theFlight.setFlightnumber(mNextFlightNumber++);
		mFlights.push_back(theFlight);
		return mFlights[mFlights.size() - 1];
	}

	void Database:: WriteFlight() const
	{

		(mFlights[mFlights.size() - 1]).WriteFlightInfoToCSVFile();
		/*for (const auto& flight : mFlights)
		{
			flight.WriteFlightInfoToCSVFile();
		}*/

	}

	PassengerAndFlightDetails& Database::getPassenger(int reservationNumber, int seatNumber)
	{
		for (auto& passenger : mPassengers) {
			if (passenger.getReservationNumber() == reservationNumber && passenger.getSeatNumber() == seatNumber)
			{
				return passenger;
			}
		}

		throw logic_error("No Passenger Found.");
	}

	PassengerAndFlightDetails& Database::getPassenger(const string& firstname, const string& lastname)
	{
		for (auto& passenger : mPassengers) {
			if (passenger.getFirstName() == firstname && passenger.getLastName() == lastname)
			{
				return passenger;
			}
		}

		throw logic_error("No Passenger Found.");
	}

	void Database::displayAll() const
	{
		for (const auto& passenger : mPassengers)
		{
			passenger.display();
		}
	}

	void Database::displayCurrentReservations() const
	{
		for (const auto& passenger : mPassengers)
		{
			if (passenger.isReserved())
				passenger.display();

		}

	}

	void Database:: displayFormerReservations() const
	{
		for (const auto& passenger : mPassengers)
		{
			if (!passenger.isReserved())
				passenger.display();
		}
	}



















}