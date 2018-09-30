#include "stdafx.h"
#include <iostream>
#include "FlightInformation.h"
#include <fstream>
#include <string>

using namespace std;

namespace FlightBookingSystem {

	FlightInformation::FlightInformation(const std::string& DepartureDate, const std::string& DepartureTime,
		const std::string& DepartureLocation, const std::string& ArrivalDate, const std::string& ArrivalTime,
		const std::string& ArrivalLocation, const std::string& AirlinesName) : mDepartureDate(DepartureDate),
		mDepartureTime(DepartureTime), mDepartureLocation(DepartureLocation), mArrivalDate(ArrivalDate),
		mArrivalTime(ArrivalTime), mArrivalLocation(ArrivalLocation), mAirlinesName(AirlinesName)
	{

	}

	void FlightInformation::setFlightnumber(int flightnumber)
	{
		mFlightNumber = flightnumber;
	}

	int FlightInformation::getFlightnumber()const
	{
		return mFlightNumber;
	}

	void FlightInformation::setDeparturedate(const string& DepartureDate)
	{
		mDepartureDate = DepartureDate;
	}

	const string& FlightInformation::getDeparturedate() const
	{
		return mDepartureDate;
	}

	void FlightInformation::setDeparturetime(const string& DepartureTime)
	{
		mDepartureTime = DepartureTime;
	}

	const string& FlightInformation::getDeparturetime() const
	{
		return mDepartureTime;
	}

	void FlightInformation::setDeparturelocation(const string& DepartureLocation)
	{
		mDepartureLocation = DepartureLocation;
	}

	const string& FlightInformation::getDeparturelocation() const
	{
		return mDepartureLocation;
	}

	void FlightInformation::setArrivaldate(const string& ArrivalDate)
	{
		mArrivalDate = ArrivalDate;
	}

	const string& FlightInformation::getArrivaldate() const
	{
		return mArrivalDate;
	}

	void FlightInformation::setArrivaltime(const string& ArrivalTime)
	{
		mArrivalTime = ArrivalTime;
	}

	const string& FlightInformation::getArrivaltime() const
	{
		return mArrivalTime;
	}

	void FlightInformation::setArrivallocation(const string& ArrivalLocation)
	{
		mArrivalLocation = ArrivalLocation;
	}

	const string& FlightInformation::getArrivallocation() const
	{
		return mArrivalLocation;
	}

	void FlightInformation::setAirlinesName(const string& AirlinesName)
	{
		mAirlinesName = AirlinesName;
	}

	const string& FlightInformation::getAirlinesName() const
	{
		return mAirlinesName;
	}

	void FlightInformation::WriteFlightInfoToCSVFile() const
	{
		
		ofstream fs;
		std::string filename = "C:\\Users\\chadhika\\Desktop\\KalAcademy\\flight.csv";
		fs.open(filename, fs.out | fs.app);
		fs << getFlightnumber() << "," << getDeparturedate() << "," << getDeparturetime() << "," <<
			getDeparturelocation() << "," << getArrivaldate() << "," << getArrivaltime() << "," <<
			getArrivallocation() << "," << getAirlinesName() << endl;
		fs.close();

		std::cout << "You have successfully added the flight information.";
	}
}