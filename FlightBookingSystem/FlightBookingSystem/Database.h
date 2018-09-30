#pragma once

#include<iostream>
#include<vector>
#include  "PassengerAndFlightDetails.h"
#include "FlightInformation.h"

namespace FlightBookingSystem {
	const int kFirstReservationNumber = 1000;
	const int kFirstSeatNumber = 0;
	const int kFirstFlightNumber = 100;

	class Database
	{
	public:
		PassengerAndFlightDetails& addPassenger(const std::string& firstname, const std::string& lastname,
			const std::string& gender, const std::string& address, const std::string zipcode);
			PassengerAndFlightDetails& getPassenger(int reservationNumber, int seatNumber);
			PassengerAndFlightDetails& getPassenger(const std::string& firstname, const std::string& lastname);

			FlightInformation& addFlightInformation(const std::string& DepartureDate, const std::string& DepartureTime,
				const std::string& DepartureLocation, const std::string& ArrivalDate, const std::string& ArrivalTime,
				const std::string& ArrivalLocation, const std::string& AirlinesName);

			void displayAll() const;
			void WriteFlight() const;
			void displayCurrentReservations() const;
			void displayFormerReservations() const;

	private:
		std::vector<PassengerAndFlightDetails> mPassengers;
		std::vector<FlightInformation>mFlights;

		int mNextReservationNumber = kFirstReservationNumber;
		int mNextSeatNumber = kFirstSeatNumber;
		int mNextFlightNumber = kFirstFlightNumber;

	};




}



