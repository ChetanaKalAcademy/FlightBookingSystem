#pragma once
#include <string>

namespace FlightBookingSystem {
	const int KDefaultTicketPrice = 200;
	class PassengerAndFlightDetails {
	public:
		PassengerAndFlightDetails() = default;
		PassengerAndFlightDetails(const std::string& firstname, const std::string& lastname,
			const std::string& gender, const std::string& address,const std::string zipcode);

			void ReserveFlight();
		     
		    void CancelFlight();

			void Upgrade(int upgradeammount = 100);

			void degrade(int degradeammount = 100);

			void display() const;

			void setFirstName(const std::string& firstname);
			const std::string& getFirstName() const;

			void setLastName(const std::string& lastname);
			const std::string& getLastName() const;
						
			void setGender(const std:: string& gender);
			const std::string& getGender() const;

			void setAddress(const std:: string& address);
			const std::string& getAddress() const;

			void setZipCode(const std:: string& zipcode);
			const std::string& getZipCode() const;
			

			void setReservationNumber(int reservationnumber);
			int getReservationNumber() const;

			void setSeatNumber(int seatnumber);
			int getSeatNumber() const;

			void setTicketPrice(int TicketPrice);
			int  getTicketPrice()const;

			bool isReserved() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mGender;
		std::string mAddress;
		std::string mZipCode;
		int mReservationNumber = -1;
		int mSeatNumber = -1;
		int mTicketPrice = KDefaultTicketPrice;
		bool mReserved = false;




	};
}
