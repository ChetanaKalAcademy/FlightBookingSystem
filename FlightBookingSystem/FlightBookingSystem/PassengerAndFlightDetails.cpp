#include "stdafx.h"
#include <iostream>
#include "PassengerAndFlightDetails.h"

using namespace std;

namespace FlightBookingSystem {
	PassengerAndFlightDetails:: PassengerAndFlightDetails(const std::string& firstname, const std::string& lastname,
		const std::string& gender, const std::string& address, const std::string zipcode):mFirstName(firstname),mLastName(lastname),
		mGender(gender),mAddress(),mZipCode(zipcode){}

	void PassengerAndFlightDetails::Upgrade(int upgradeammount)
	{
		setTicketPrice(getTicketPrice() + upgradeammount);
	}

	void PassengerAndFlightDetails::degrade(int degradeammount)
	{
		setTicketPrice(getTicketPrice() - degradeammount);
	}

	void PassengerAndFlightDetails::ReserveFlight()
	{
		mReserved = true;
	}

	void PassengerAndFlightDetails::CancelFlight()
	{
		mReserved = false;
	}

	void PassengerAndFlightDetails::setFirstName(const string& firstname)
	{
		mFirstName = firstname;
	}

	const string& PassengerAndFlightDetails::getFirstName() const
	{
		return mFirstName;
	}

	void PassengerAndFlightDetails::setLastName(const string& lastname)
	{
		mLastName = lastname;
	}

	const string& PassengerAndFlightDetails::getLastName() const
	{
		return mLastName;
	}

	void PassengerAndFlightDetails::setGender(const string& gender)
	{
		mGender = gender;
	}

	const string& PassengerAndFlightDetails::getGender() const
	{
		return mGender;
	}

	void PassengerAndFlightDetails::setAddress(const string& address)
	{
		mAddress = address;
	}

	const string& PassengerAndFlightDetails::getAddress() const
	{
		return mAddress;
	}

	void PassengerAndFlightDetails::setZipCode(const string& zipcode)
	{
		mAddress = zipcode;
	}

	const string& PassengerAndFlightDetails::getZipCode() const
	{
		return mZipCode;
	}

	void PassengerAndFlightDetails::setTicketPrice(int newTicketPrice) {
		mTicketPrice = newTicketPrice;
	}

	int PassengerAndFlightDetails::getTicketPrice() const {
		return mTicketPrice;
	}

	void PassengerAndFlightDetails::setReservationNumber(int reservationNumber) {
		mReservationNumber = reservationNumber;
	}

	int PassengerAndFlightDetails::getReservationNumber() const {
		return mReservationNumber;
	}
	void PassengerAndFlightDetails::setSeatNumber(int seatNumber) {
		mSeatNumber = seatNumber;
	}

	int PassengerAndFlightDetails::getSeatNumber() const {
		return mSeatNumber;
	}

	bool PassengerAndFlightDetails::isReserved() const {
		return mReserved;
	}

	void PassengerAndFlightDetails::display() const
	{
		cout << "Passenger Name: " << getLastName() << ", " << getFirstName() << endl;
		cout << "Passenger Gender: " << getGender() << endl;
		cout << "Passenger Address: " << getAddress() << endl;
		cout << "Passenger ZipCode: " << getZipCode() << endl;
		cout << (isReserved() ? "Passenger Has Reservation" : "Passenger Does Not Have Reservation") << endl;
		cout << "Reservation Number: " << getReservationNumber() << endl;
		cout << "Seat Number: " << getSeatNumber() << endl;
		cout << "Ticket Price: $" << getTicketPrice() << endl;
		cout << endl;
	}

}