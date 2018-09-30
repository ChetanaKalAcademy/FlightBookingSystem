#pragma once
#include <string>

namespace FlightBookingSystem {
	
	class FlightInformation
	{
	public:
		FlightInformation() = default;
		FlightInformation(const std::string& DepartureDate, const std::string& DepartureTime,
			const std::string& DepartureLocation, const std::string& ArrivalDate, const std::string& ArrivalTime,
			const std::string& ArrivalLocation, const std::string& AirlinesName);

		void WriteFlightInfoToCSVFile() const;

		void setFlightnumber(int flightnumber);
		int getFlightnumber()const;

		void setDeparturedate(const std::string& DepartureDate);
		const std::string& getDeparturedate() const;

		void setDeparturetime(const std::string& DepartureTime);
		const std::string& getDeparturetime() const;

		void setDeparturelocation(const std::string& DepartureLocation);
		const std::string& getDeparturelocation() const;

		void setArrivaldate(const std::string& ArrivalDate);
		const std::string& getArrivaldate() const;

		void setArrivaltime(const std::string& ArrivalTime);
		const std::string& getArrivaltime() const;

		void setArrivallocation(const std::string& ArrivalLocation);
		const std::string& getArrivallocation() const;

		void setAirlinesName(const std::string& AirlinesName);
		const std::string& getAirlinesName() const;

	private:
		std::string mDepartureDate;
		std::string mDepartureTime;
		std::string mDepartureLocation;
		std::string mArrivalDate;
		std::string mArrivalTime;
		std::string mArrivalLocation;
		std::string mAirlinesName;

		int mFlightNumber = -1;




	};


}
