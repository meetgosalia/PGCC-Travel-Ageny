#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/*
 * 'sstream' included to convert string to int (That is why stringstream ss is
 * declared in some functions.
 */
 
class travel {
	public:
	/*
	 * Some variables have been initialized with values other than 0 like '-1'
	 * so that the loop executes and the inputs are taken.
	 */

	// Variables with '_st' suffices are the "string variants" of variables.

	string line;
	int booking_check;
	int trip_check;
	int option;
	int i;

	int no_trips;				// Number of trips
	int travel_id;
	int trip_id;
	int trip_id_booking;
	string trip_id_booking_st;
	string plan[15];
	string destination;
	string package_name;
	int month;
	int day;					// This is essentially, date
	string date;				// In the format DD/MM/YYYY
	int duration;				// Number of days
	int time;				    // 24-hour format
	int time_slot;
	char delete_confirmation;

	double price;
	double discount;
	double price_after_discount;
	double gst;
	double final_amount;

	int no_members;
	string transport;
	char ac_bus_facility;
	char sleeping_bus_facility;
	char food_facility;
	char meal_type;

	string primary_person;
	string email;
	string address;
	string names[30];
	int ages[30];
	char genders[30];
	string mobile_nos[30];
	int no_kids;
	int no_adults;

	travel() {
		line = "";
		booking_check = 0;
		trip_check = 0;
		option = 0;
		i = 0;

		no_trips = 0;
		travel_id = 0;
		trip_id = 0;
		trip_id_booking = 0;
		trip_id_booking_st = "";
		destination = "";
		package_name = "";
		month = 0;
		day = 0;
		date = "";
		duration = 0;
		time = 0;
		time_slot = 0;
		delete_confirmation = '\0';

		price = 0.00;
		discount = 0.00;
		price_after_discount = 0.00;
		gst = 0.00;
		final_amount = 0.00;

		no_members = 0;
		transport = "";
		ac_bus_facility = '\0';			// '\0' is the default value of character
		sleeping_bus_facility = '\0';
		food_facility = '\0';
		meal_type = '\0';

		primary_person = "";
		email = "";
		address = "";
		no_kids = 0;
		no_adults = 0;
	}
	~travel() {
	}


	void createFiles() {
		ofstream fout;

		fout.open("pgcc_bookings.txt", ios::app);
		fout.close();

		
		fout.open("pgcc_trips.txt", ios::app);
		fout.close();
	}

	void initializeTravelID() {
		ifstream fin;
		fin.open("pgcc_bookings.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if (line.compare("----------") == 0) {
				travel_id++;
			}
		}
		fin.close();
	}

	void initializeTripID() {
		ifstream fin;
		fin.open("pgcc_trips.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if (line.compare("----------") == 0) {
				trip_id++;
			}
		}
		fin.close();
	}

	void storeR1PackageInfo() {
		ofstream fout;
		fout.open("pgcc_trips.txt", ios::app);
		fout << endl;

		fout << "Trip ID: 1" << endl;
		fout << "Destination name: Rajasthan" << endl;
		fout << "Package name: Rajasthan Family Special Jaipur Package" << endl;
		fout << "Package date: 18/10/2021" << endl;
		fout << "Package duration: 4 days, 3 nights" << endl;
		fout << "Package cost (per person): Rs. 13000"
		<< endl;
		fout << "Departure time: 710h" << endl;
		fout << endl;

		fout << "Package Itenary:" << endl;
		fout << "Day 1- Arrival in Jaipur through choice of transport and" <<
		endl;
		fout << "check-in to hotel 'The Theme'."<< endl;

		fout << "Day 2- Sightseeing in Jaipur. Includes destinations like" <<
		endl;
		fout << "Hawa Mahal, City Palace, Jantar Mantar and Amer Fort." << endl;

		fout << "Day 3- Sightseeing in and around Jaipur." << endl;
		fout << "Day 4- Departure from Jaipur." << endl;

		fout << endl;
		fout << "----------" << endl;
		fout.close();
	}

	void storeR2PackageInfo() {
		ofstream fout;
		fout.open("pgcc_trips.txt", ios::app);
		fout << endl;

		fout << "Trip ID: 2" << endl;
		fout << "Destination name: Rajasthan" << endl;
		fout << "Package name: Rajasthan Couple Special Package" << endl;
		fout << "Package date: 15/10/2021" << endl;
		fout << "Package duration: 6 days, 5 nights" << endl;
		fout << "Package cost (per person): Rs. 19000" << endl;
		fout << "Departure time: 750h" << endl;
		fout << endl;

		fout << "Package Itenary:" << endl;
		fout << "Day 1- Arrival in Udaipur through choice of transport and" <<
		endl;
		fout << "check-in to 'Hotel Udai Median'." << endl;

		fout << "Day 2- Sightseeing in and around Udaipur. Destinations include"
		<< endl;
		fout << "Saheliyon ki Bari, City Palace, Sajjangarh Palace and Meuseum"
		<< endl;
		fout << "of Folk Arts. Dinner at a Lake View Haveli and a boat ride to"
		<< endl;
		fout << "Jag Mandir Palace. Professional photoshoot at Udaipur and a" <<
		endl;
		fout << "dance show at Bagore ki Haveli in Udaipur." << endl;

		fout << "Day 3- Udaipur to Jodhpur and sightseeing in Jodhpur." << endl;
		fout << "Destinations include Mehrangarh Fort and Jaswant Thada." << endl;
		fout << "Check-in at 'Ajit Mansion Hotel'. Dinner on the dunes in Osian Village."
		<< endl;

		fout << "Day 4- Zip lining at Mehrangarh Fort, and Jodhpur to Jaisalmer."
		<< endl;
		fout << "Sightseeing at Sam Sand Dunes in Jaisalmer. Check-in at 'Hotel"
		<< endl;
		fout << "Prithvi Palace' and sunset at Kuldhara Village with cocktails."
		<< endl;

		fout << "Day 5- Sightseeing in and around Jaisalmer. Destinations" <<
		endl;
		fout << "include Jaisalmer fort, Bada Bagh and Gadisar Lake. Shopping" <<
		endl;
		fout << "'with a difference' at Jaisalmer Fort and dune bashing at" << endl;
		fout << "Sam Sand Dunes." << endl;
		fout << "Day 6- Jaisalmer to Jodhpur and departure." << endl;

		fout << endl;
		fout << "----------" << endl;
		fout.close();
	}

	void storeK1PackageInfo() {
		ofstream fout;
		fout.open("pgcc_trips.txt", ios::app);
		fout << endl;

		fout << "Trip ID: 3" << endl;
		fout << "Destination name: Kerela" << endl;
		fout << "Package name: Kerala Family Special Package" << endl;
		fout << "Package date: 17/10/2021" << endl;
		fout << "Package duration: 4 days, 3 nights" << endl;
		fout << "Package cost (per person): Rs. 23000"
		<< endl;
		fout << "Departure time: 610h" << endl;
		fout << endl;

		fout << "Package Itenary:" << endl;
		fout << "Day 1- Arrival in Kochi through choice of transport and" << endl;
		fout << "check-in to 'Hotel Wayland Square'." << endl;

		fout << "Day 2- Sightseeing in and around Kochi. Destinations include" <<
		endl;
		fout << "Tata Tea Museum, Eravikulam national park, Mattupetty Dam" <<
		endl;
		fout << "and Echo Point." << endl;

		fout << "Day 3- Munnar to Thekaddy, and sightseeing. Destination include"
		<< endl;
		fout << "Periyar lake, Periyar Wildlife Sanctuary and Chilli Spice Garden."
		<< endl;
		fout << "Day 4- Departure from Thekkady." << endl;

		fout << endl;
		fout << "----------" << endl;
		fout.close();
	}

	void storeK2PackageInfo() {
		ofstream fout;
		fout.open("pgcc_trips.txt", ios::app);
		fout << endl;

		fout << "Trip ID: 4" << endl;
		fout << "Destination name: Kerela" << endl;
		fout << "Package name: Kerala Couple Special Package" << endl;
		fout << "Package date: 16/10/2021" << endl;
		fout << "Package duration: 6 days, 5 nights" << endl;
		fout << "Departure time: 650h" << endl;
		fout << "Package cost (per person): Rs. 32000"
		<< endl;
	
		fout << endl;

		fout << "Package Itenary:" << endl;
		fout << "Day 1- Arrival in Kochi through choice of transport and" << endl;
		fout << "check-in to 'Lake Forest Munnar'." << endl;

		fout << "Day 2- Sightseeing in and around kochi . Destinations include"
		<< endl;
		fout << "Fort Cochin, Dutch Palace, Chinese Fishing Nets and" << endl;
		fout << "St. Francis Church." << endl;

		fout << "Day 3- Kochi to Munnar, and Sightseeing. Destination include" <<
		endl;
		fout << "Tata Tea Museum, Eravikulam National Park, Mattupetty Dam," << endl;
		fout << " and Echo Point." << endl;

		fout << "Day 4- Munnar to Thekaddy, sightseeing in and around Thekaddy."
		<< endl;
		fout << "destinations include Chillies Spice Garden, Periyar Lake" << endl;
		fout << " and Periyar Wildlife Sanctuary." << endl;

		fout << "Day 5- Thekaddy to Allepy, and sightseeing in Allepy." << endl;
		fout << "Destinations include Alappuzha Beach, Mullakkal Rajarajeswari Temple"
		<< endl;
		fout << "Day 6- Departure from Allepy" << endl;

		fout << endl;
		fout << "----------" << endl;
		fout.close();
	}

	void storeU1PackageInfo() {
		ofstream fout;
		fout.open("pgcc_trips.txt", ios::app);
		fout << endl;

		fout << "Trip ID: 5" << endl;
		fout << "Destination name: Uttarakhand" << endl;
		fout << "Package name: Uttarakhand Family Special Package" << endl;
		fout << "Package date: 22/10/2021" << endl;
		fout << "Package duration: 4 days, 3 nights" << endl;
		fout << "Package cost (per person): Rs. 19000"
		<< endl;
		fout << "Departure time: 720h" << endl;
		fout << endl;

		fout << "Package Itenary:" << endl;
		fout << "Day 1- Arrival in Mukteshwar through choice of transport and" <<
		endl;
		fout << "check-in to 'Parvada Bungalows Mukteshwar'." << endl;

		fout << "Day 2- Sightseeing in and around Mukteshwar. Destinations" <<
		endl;
		fout << "include Jim Corbett's Bungalow and Chauli Ki Jaali." << endl;

		fout << "Day 3- Sightseeing in and around Mukteshwar. Destinations" << endl;
		fout << "include Mahadev Temple and Bhalugaad Waterfall." << endl;
		fout << "Day 4- Departure." << endl;

		fout << endl;
		fout << "----------" << endl;
		fout.close();
	}

	void storeU2PackageInfo() {
		ofstream fout;
		fout.open("pgcc_trips.txt", ios::app);
		fout << endl;

		fout << "Trip ID: 6" << endl;
		fout << "Destination name: Uttarakhand" << endl;
		fout << "Package name: Uttarakhand Couple Special Package" << endl;
		fout << "Package date: 14/10/2021" << endl;
		fout << "Package duration: 4 days, 3 nights" << endl;
		fout << "Package cost (per person): Rs. 17000"
		<< endl;
		fout << "Departure time: 750h" << endl;
		fout << endl;

		fout << "Package Itenary:" << endl;
		fout << "Day 1- Arrival in Nanital through choice of transport and" <<
		endl;
		fout << "check-in to 'Bara Bungalow Jeolikote A Rosakue Collection'." << endl;

		fout << "Day 2- Sightseeing in and around Nanital. Destinations" << endl;
		fout << "include Nani Lake, Naini Devi Temple and Naukuchiatal." << endl;

		fout << "Day 3- Travel to Eco Cave Garden." << endl;
		fout << "Day 4- Departure." << endl;

		fout << endl;
		fout << "----------" << endl;
		fout.close();
	}

	void storePredefinedPackagesInfo() {
		storeR1PackageInfo();
		storeR2PackageInfo();
		storeK1PackageInfo();
		storeK2PackageInfo();
		storeU1PackageInfo();
		storeU2PackageInfo();
	}

	void displayIntroduction() {
		cout << "Welcome to PGCC Travel Agency!!" << endl << endl;

    	cout << "We believe in transparency and hence we never go wrong in over " <<
    	"promising." << endl << endl;

    	cout << "Your blessings and satisfaction is our profit that matters than " <<
    	"what we earn. We welcome you to join us and have the most wonderful time " <<
    	"of your life." << endl;
	}

	void displayDiscounts() {
		cout << "We have DIWALI SPECIAL DISCOUNTS!!!" << endl;
		cout << "10% discount if no. of members are between 5 and 11." << endl;
		cout << "16% discount if no. of members are between 12 and 20." << endl;
		cout << "22% discount if no. of members are between 21 and 30." << endl;
	}

	void displayGST() {
		cout << "8% GST included." << endl;
	}

	/*
	 * cin.ignore() have been used after many statements of 'cin' as inputs are
	 * sometimes skipped by the program.
	 */

	void inputTripIDForBooking() {
		cin >> trip_id_booking;
		cin.ignore();

		trip_id_booking_st = std::to_string(trip_id_booking);
	}

	/*
	 * std::to_string function used to convert int to string.
	 */

	void initializeDestinationForPackage() {
		ifstream fin;
		fin.open("pgcc_trips.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if ((line.substr(0, 4)).compare("Trip") == 0) {
				if ((line.substr(line.find(':') + 2)).compare(trip_id_booking_st) == 0) {
					while (true) {
						getline(fin, line);
						if ((line.substr(0, 16)).compare("Destination name") == 0) {
							destination = line.substr(line.find(':') + 2);
							break;
						}
					}
				}
			}
		}

		fin.close();
	}

	void initializePackage() {
		ifstream fin;
		fin.open("pgcc_trips.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if ((line.substr(0, 4)).compare("Trip") == 0) {
				if ((line.substr(line.find(':') + 2)).compare(trip_id_booking_st) == 0) {
					while (true) {
						getline(fin, line);
						if ((line.substr(0, 12)).compare("Package name") == 0) {
							package_name = line.substr(line.find(':') + 2);
							break;
						}
					}
				}
			}
		}

		fin.close();
	}

	void initializeDateForPackage() {
		ifstream fin;
		fin.open("pgcc_trips.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if ((line.substr(0, 4)).compare("Trip") == 0) {
				if ((line.substr(line.find(':') + 2)).compare(trip_id_booking_st) == 0) {
					while (true) {
						getline(fin, line);
						if ((line.substr(0, 12)).compare("Package date") == 0) {
							date = line.substr(line.find(':') + 2);
							break;
						}
					}
				}
			}
		}

		fin.close();
	}

	void initializeDurationForPackage() {
		stringstream ss;
		string duration_st = "";
		ifstream fin;
		fin.open("pgcc_trips.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if ((line.substr(0, 4)).compare("Trip") == 0) {
				if ((line.substr(line.find(':') + 2)).compare(trip_id_booking_st) == 0) {
					while (true) {
						getline(fin, line);
						if ((line.substr(0, 16)).compare("Package duration") == 0) {
							duration_st = line.substr((line.find(':') + 2), (line.find('d') - 2));
							break;
						}
					}
				}
			}
		}

		ss << duration_st;
		ss >> duration;
		fin.close();
	}

	void initializeTimeForPackage() {
		stringstream ss;
		string time_st = "";
		ifstream fin;
		fin.open("pgcc_trips.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if ((line.substr(0, 4)).compare("Trip") == 0) {
				if ((line.substr(line.find(':') + 2)).compare(trip_id_booking_st) == 0) {
					while (true) {
						getline(fin, line);
						if ((line.substr(0, 14)).compare("Departure time") == 0) {
							time_st = line.substr((line.find(':') + 2), (line.find('h') - 1));
							break;
						}
					}
				}
			}
		}

		ss << time_st;
		ss >> time;
		fin.close();
	}

	void initializePriceForPackage() {
		string price_st = "";
		ifstream fin;
		fin.open("pgcc_trips.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if ((line.substr(0, 4)).compare("Trip") == 0) {
				if ((line.substr(line.find(':') + 2)).compare(trip_id_booking_st) == 0) {
					while (true) {
						getline(fin, line);
						if ((line.substr(0, 12)).compare("Package cost") == 0) {
							price_st = line.substr(line.find('.') + 2);
							break;
						}
					}
				}
			}
		}

		// Workaround for retaining trailing zeroes in 'price'.
		// atof() function is used to convert string to double.

		price_st = price_st + "1";
		price = atof(price_st.c_str());
		price = price - 1;
		price = price / 10;
		
		fin.close();

		if ((ac_bus_facility != 'Y') && (ac_bus_facility != 'y')) {
			price += 500;
		}

		if ((sleeping_bus_facility != 'Y') && (sleeping_bus_facility != 'y')) {
			price += 500;
		}

		if ((meal_type != 'B') && (meal_type != 'b')) {
			price += 200;
		}

		if ((meal_type != 'L') && (meal_type != 'l')) {
			price += 450;
		}

		if ((meal_type != 'D') && (meal_type != 'd')) {
			price += 550;
		}

		if ((meal_type != 'M') && (meal_type != 'm')) {
			price += 1100;
		}
	}

	void calculatePrice() {
		price *= no_members;
	}

	void calculateDiscount() {
		if ((no_members >= 5) && (no_members <= 11)) {
			discount = price * (10.0 / 100.0);
		} else if ((no_members >= 12) && (no_members <= 20)) {
			discount = price * (16.0 / 100.0);
		} else if ((no_members >= 21) && (no_members <= 30)) {
			discount = price * (22.0 / 100.0);
		} else {
			discount = 0;
		}
	}

	void calculatePriceAfterDiscount() {
		price_after_discount = price - discount;
	}

	void calculateGST() {
		gst = price_after_discount * (8.0 / 100.0);
	}

	void calculateFinalAmount() {
		final_amount = price_after_discount + gst;
	}

	void inputNumberOfMembers() {
		cin >> no_members;
		cin.ignore();
		while ((no_members < 1) || (no_members > 30)) {
			cout << "Please enter correct no. of members!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> no_members;
			cin.ignore();
		}
	}

	void askACBusService() {
		cout << "Do you want AC bus (Rs. 500 extra)?" << endl;
		cout << "(Enter 'Y' for Yes or 'N' for No)" << endl;

		cin >> ac_bus_facility;
		cin.ignore();
		while (((ac_bus_facility != 'Y') && (ac_bus_facility != 'y')) &&
		((ac_bus_facility != 'N') && (ac_bus_facility != 'n'))) {
			cout << "Please enter correct option!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> ac_bus_facility;
			cin.ignore();
		}
	}

	void askSleepingBusService() {
		cout << "Do you want sleeping bus (Rs. 500 extra)?" << endl;
		cout << "(Enter 'Y' for Yes or 'N' for No)" << endl;

		cin >> sleeping_bus_facility;
		cin.ignore();
		while (((sleeping_bus_facility != 'Y') || (sleeping_bus_facility != 'y')) &&
		((sleeping_bus_facility != 'N') || (sleeping_bus_facility != 'n'))) {
			cout << "Please enter correct option!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> sleeping_bus_facility;
			cin.ignore();
		}
	}

	void selectTransport() {
		if (no_members <= 6) {
			transport = "Innova";
			cout << "Transport: Innova" << endl;
		} else if (no_members <= 15) {
			transport = "Mini Bus";
			cout << "Transport: Mini Bus" << endl;
			cout << endl;
		} else {
			transport = "Bus";
			cout << "Transport: Bus" << endl;
			askACBusService();
			askSleepingBusService();
		}
	}

	void askFoodFacility() {
		cout << "Do you want food facility?" << endl;
		cout << "(Enter 'Y' for Yes or 'N' for No)" << endl;

		cin >> food_facility;
		cin.ignore();
		while (((food_facility != 'Y') && (food_facility != 'y')) &&
		((food_facility != 'N') && (food_facility != 'n'))) {
			cout << "Please enter correct option!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> food_facility;
			cin.ignore();
		}

		if ((food_facility == 'Y') || (food_facility == 'y')) {
			cout << "1) Breakfast (Rs. 200)- Type 'b' to select" << endl;
			cout << "2) Lunch (Rs. 450)- Type 'l' to select" << endl;
			cout << "3) Dinner (Rs. 550)- Type 'd' to select" << endl;
			cout << "4) Full-day Meal (Rs. 1100)- Type 'm' to select" << endl;
			cout << endl;

			cout << "Select the meal of your choice-" << endl;
			cin >> meal_type;
			cin.ignore();
			while (((meal_type != 'B') && (meal_type != 'b')) &&
			((meal_type != 'L') && (meal_type != 'l')) && 
			((meal_type != 'D') && (meal_type != 'd')) &&
			((meal_type != 'M') && (meal_type != 'm'))) {
				cout << "Please enter correct meal type!" << endl;
				cout << "Again!!" << endl;
				cout << endl;
				cin >> food_facility;
				cin.ignore();
			}
		}
	}

	void inputPrimaryPerson() {
		getline(cin, primary_person);
	}

	void inputEmail() {
		getline(cin, email);
	}

	void inputAddress() {
		getline(cin, address);
	}

	void inputMemberDetails() {
		for (i = 0; i < no_members; i++) {
			cout << "Details of member " << (i + 1) << "-" << endl;
			cout << "Name: ";
			getline(cin, names[i]);

			cout << "Age: ";
			cin >> ages[i];
			cin.ignore();
			while (ages[i] < 1) {
				ages[i] = -1;
				cout << "Please enter age correctly!" << endl;
				cout << "Again!!" << endl;
				cout << endl;
				cin >> ages[i];
				cin.ignore();
			}

			cout << "Gender [M/F]: ";
			cin >> genders[i];
			cin.ignore();
			while (((genders[i] != 'M') && (genders[i] != 'm')) &&
			((genders[i] != 'F') && (genders[i] != 'f'))) {
				cout << "Please enter gender correctly!" << endl;
				cout << "Again!!" << endl;
				cout << endl;
				cin >> genders[i];
				cin.ignore();
			}

			cout << "Mobile Number (Enter 0 if none): ";
			cin >> mobile_nos[i];
			cin.ignore();
			cout << endl;
		}
	}

	void displayBookingConfirmation() {
		cout << "Booking confirmed!!" << endl;
	}

	void displayTripConfirmation() {
		cout << "New trip created!!" << endl;
	}

	void displayTravelID() {
		cout << "The travel ID is " << travel_id << endl;
	}

	void displayTripID() {
		cout << "The trip ID is " << trip_id << "." << endl;
	}

	void inputMonthForCustom() {
		cin >> month;
		cin.ignore();
		while ((month < 1) || (month > 12)) {
			cout << "Please enter month correctly!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> month;
			cin.ignore();
		}
	}

	void inputDayForCustom() {
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
		(month == 8) || (month == 10) || (month == 12)) {
			cin >> day;
			cin.ignore();
			while ((day < 1) || (day > 31)) {
				cout << "Please enter day correctly!" << endl;
				cout << "Again!!" << endl;
				cout << endl;
				cin >> day;
				cin.ignore();
			}
		} else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
			cin >> day;
			cin.ignore();
			while ((day < 1) || (day > 30)) {
				cout << "Please enter day correctly!" << endl;
				cout << "Again!!" << endl;
				cout << endl;
				cin >> day;
				cin.ignore();
			}
		} else {
			cin >> day;
			cin.ignore();
			while ((day < 1) || (day > 28)) {
					cout << "Please enter day correctly!" << endl;
					cout << "Again!!" << endl;
					cout << endl;
					cin >> day;
					cin.ignore();
			}
		}
	}

	void initializeDateForCustom() {
		string month_st = "";
		string day_st = "";

		month_st = std::to_string(month);
		day_st = std::to_string(day);

		date = day_st + "/" + month_st + "/" + "2021";
	}

	void displayTimeSlots() {
		cout << "Time slots avaliable-" << endl;
		cout << "1) 8:00 AM" << endl;
		cout << "2) 9:00 AM" << endl;
		cout << "3) 10:00 AM" << endl;
		cout << "4) 11:00 AM" << endl;
		cout << "5) 6:00 PM" << endl;
		cout << "6) 8:00 PM" << endl;
		cout << "7) 10:00 PM" << endl;
	}

	void inputTimeSlotForCustom() {
		cin >> time_slot;
		cin.ignore();
		while ((time_slot < 1) || (time_slot > 7)) {
				cout << "Please enter time slot correctly!" << endl;
				cout << "Again!!" << endl;
				cout << endl;
				cin >> time_slot;
				cin.ignore();
		}
	}

	void initializeTimeForCustom() {
		if (time_slot == 1) {
			time = 800;
		}
		if (time_slot == 2) {
			time = 900;
		}
		if (time_slot == 3) {
			time = 1000;
		}
		if (time_slot == 4) {
			time = 1100;
		}
		if (time_slot == 5) {
			time = 1800;
		}
		if (time_slot == 6) {
			time = 2000;
		}
		if (time_slot == 7) {
			time = 2200;
		}
	}

	void inputDurationForCustom() {
		cin >> duration;
		cin.ignore();
		while ((duration < 0) || (duration > 15)) {
			cout << "Please enter duration correctly!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> duration;
			cin.ignore();
		}
	}

	void inputDestinationForNewTrip() {
		getline(cin, destination);
	}

	void inputPackageNameForNewTrip() {
		getline(cin, package_name);
	}

	void inputPriceForNewTrip() {
		cin >> price;
		cin.ignore();
		while (price < 0) {
			cout << "Please enter price correctly!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> price;
			cin.ignore();
		}
	}

	void inputTimeForNewTrip() {
		cin >> time;
		cin.ignore();
		while (time < 0) {
			cout << "Please enter time correctly!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> time;
			cin.ignore();
		}
	}

	void inputPlanForNewTrip() {
		for (i = 0; i < duration; i++) {
			cout << "Day " << (i + 1) << ": ";
			getline(cin, plan[i]);
		}
	}

	void storeNewBooking() {
		ofstream fout;
		fout.open("pgcc_bookings.txt", ios::app);

		if (travel_id == 0) {
			fout << "PGCC Travel Agency" << endl;
		}
		fout << endl;

		travel_id++;
		fout << "Travel ID: " << travel_id << endl;
		fout << "Primary person: " << primary_person << endl;
		fout << "Email: " << email << endl;
		fout << "Address: " << address << endl;
		fout << "Number of members: " << no_members << endl;
		fout << endl;

		fout << "Member details-" << endl;
		fout << endl;

		for (i = 0; i < no_members; i++) {
			fout << "Member " << (i + 1) << "-" << endl;
			fout << "Name: " << names[i] << endl;
			fout << "Age: " << ages[i] << " yrs" << endl;
			fout << "Gender: " << genders[i] << endl;
			fout << "Mobile Number: " << mobile_nos[i] << endl;
			fout << endl;
		}

		no_kids = 0;
		no_adults = 0;

		for (i = 0; i < no_members; i++) {
			if (ages[i] >= 18) {
				no_adults++;
			} else {
				no_kids++;
			}
		}

		fout << "Number of kids: " << no_kids << endl;
		fout << "Number of adults: " << no_adults << endl;
		fout << "Destination name: " << destination << endl;
		fout << "Package name: " << package_name << endl;
		fout << "Package date: " << date << endl;
		fout << "Package duration: " << duration << " days, " <<
		(duration - 1) << " nights" << endl;
		fout << "Departure time: " << time << "h" << endl;
		fout << "Transport: " << transport << endl;

		if ((food_facility == 'Y') || (food_facility == 'y')) {
			fout << "Food facility: Yes"  << endl;
			if ((food_facility == 'B') || (food_facility == 'b')) {
				fout << "Meal type: Breakfast" << endl;
			}
			if ((food_facility == 'L') || (food_facility == 'l')) {
				fout << "Meal type: Lunch" << endl;
			}
			if ((food_facility == 'D') || (food_facility == 'd')) {
				fout << "Meal type: Dinner" << endl;
			}
			if ((food_facility == 'M') || (food_facility == 'm')) {
				fout << "Meal type: Full-Day Meal" << endl;
			}
		} else {
			fout << "Food facility: No"  << endl;
		}
		fout << endl;

		fout << "Original price: Rs. " << price << endl;
		fout << "Discount: Rs. " << discount << endl;
		fout << "GST: Rs. " << gst << endl;
		fout << "Final amount: Rs. " << final_amount << endl;

		fout << endl;
		fout << "----------" << endl;
		fout.close();
	}

	void storeNewTrip() {
		ofstream fout;
		fout.open("pgcc_trips.txt", ios::app);
		fout << endl;

		trip_id++;
		fout << "Trip ID: " << trip_id << endl;
		fout << "Destination name: " << destination << endl;
		fout << "Package name: " << package_name << endl;
		fout << "Package date: " << date << endl;
		fout << "Package duration: " << duration << " days, " << (duration - 1) <<
		" nights" << endl;
		fout << "Departure time: " << time << "h" << endl;
		fout << "Package cost (per person): Rs. " << price << endl;
		fout << endl;

		fout << "Package Itenary:" << endl;
		for (i = 0; i < duration; i++) {
			fout << "Day " << (i + 1) << ": ";
			fout << plan[i] << endl;
		}

		fout << endl;
		fout << "----------" << endl;
		fout.close();
	}

	void displayCreatedTrips() {
		ifstream fin;
		fin.open("pgcc_trips.txt");

		i = 0;
		while (!fin.eof()) {
			getline(fin, line);
			if ((line.substr(0, 16)).compare("Destination name") == 0) {
				cout << (i + 1) << ") ";
				cout << line.substr(line.find(':') + 2);
				getline(fin, line);
				if ((line.substr(0, 12)).compare("Package name") == 0) {
					cout << " -> ";
					cout << line.substr(line.find(':') + 2) << endl;
					i++;
				}
			}
		}

		fin.close();
	}

	void displayCustomTrips() {
		string destinations[trip_id + 1];
		int no_destinations = 0;
		ifstream fin;
		fin.open("pgcc_trips.txt");

		while (!fin.eof()) {
			getline(fin, line);
			if ((line.substr(0, 16)).compare("Destination name") == 0) {
				for (i = 0; i < no_destinations; i++) {
					if ((line.substr(line.find(':') + 2)).compare(destinations[i]) == 0) {
						break;
					}
				}

				if (i == no_destinations) {
					destinations[i] = line.substr(line.find(':') + 2);
					no_destinations++;
				}
			}
		}
		fin.close();

		no_trips = trip_id;
		for (i = 0; i < no_destinations; i++) {
			cout << no_trips << ") ";
			cout << destinations[i];
			cout << " Custom" << endl;
			no_trips++;
		}
	}

	void bookPackage() {
		initializeDestinationForPackage();
		initializePackage();
		initializeDateForPackage();
		initializeDurationForPackage();
		initializeTimeForPackage();

		initializePriceForPackage();
		calculatePrice();
		calculateDiscount();
		calculatePriceAfterDiscount();
		calculateGST();
		calculateFinalAmount();

		cout << "Enter number of members-" << endl;
		inputNumberOfMembers();
		cout << endl;

		selectTransport();
		cout << endl;

		askFoodFacility();
		cout << endl;

		cout << "Enter name of Primary Person: ";
		inputPrimaryPerson();
		cout << "Enter your email ID: ";
		inputEmail();
		cout << "Enter your address: ";
		inputAddress();
		cout << endl;

		inputMemberDetails();
	}

	void bookCustom() {
		cout << "Enter the month of your trip: ";
		inputMonthForCustom();

		cout << "Enter the date of your trip: ";
		inputDayForCustom();
		initializeDateForCustom();

		cout << "Enter the no. of days of your trip: ";
		inputDurationForCustom();

		cout << "Enter the cost per person: ";
		inputPriceForNewTrip();
		calculatePrice();
		cout << endl;

		displayTimeSlots();
		cout << endl;

		cout << "Enter the appropriate time slot for your trip (1-7)-" << endl;
		inputTimeSlotForCustom();
		initializeTimeForCustom();
		cout << endl;

		cout << "Enter number of members-" << endl;
		inputNumberOfMembers();
		cout << endl;

		selectTransport();
		cout << endl;

		askFoodFacility();
		cout << endl;
		
		calculateDiscount();
		calculatePriceAfterDiscount();
		calculateGST();
		calculateFinalAmount();

		cout << "Enter name of Primary Person: ";
		inputPrimaryPerson();
		cout << "Enter your email ID: ";
		inputEmail();
		cout << "Enter your address: ";
		inputAddress();
		cout << endl;

		inputMemberDetails();
	}

	void createNewBooking() {
		cout << "Available trips-" << endl;
		displayCreatedTrips();
		displayCustomTrips();
		cout << endl;
		
		cout << "Select the trip for your booking (1-" << no_trips << ")-"
		<< endl;
		inputTripIDForBooking();
		cout << endl;

		if (trip_id_booking < trip_id) {
			bookPackage();
		} else if (trip_id_booking < no_trips) {
			bookCustom();
		} else {
			cout << "Please enter correct option!" << endl;
		}
		displayBookingConfirmation();
		cout << endl;

		storeNewBooking();
		displayTravelID();
	}

	void createNewTrip() {
		cout << "Enter your Destination name: ";
		inputDestinationForNewTrip();

		cout << "Enter Package name: ";
		inputPackageNameForNewTrip();

		cout << "Enter the month of your trip: ";
		inputMonthForCustom();

		cout << "Enter the date of your trip: ";
		inputDayForCustom();
		initializeDateForCustom();

		cout << "Enter the no. of days of your trip: ";
		inputDurationForCustom();

		cout << "Enter the price-per-day for 1 person: ";
		inputPriceForNewTrip();

		cout << "Enter the departure time (in 24-hour format. Eg- 2300h, 830h): ";
		inputTimeForNewTrip();
		cout << endl;

		cout << "Enter your plan for each day." << endl;
		inputPlanForNewTrip();
		cout << endl;

		displayTripConfirmation();
		cout << endl;

		storeNewTrip();
		displayTripID();
	}

	void displayBooking() {
		booking_check = 0;
		string travel_id_search = "";
		ifstream fin;
		fin.open("pgcc_bookings.txt");

		cout << "Enter your travel ID-" << endl;
		cin >> travel_id_search;
		cin.ignore();
		cout << endl;

		while (!fin.eof()) {
			getline(fin, line);
			if (booking_check == 0) {
				if ((line.substr(0, 6)).compare("Travel") == 0) {
					if ((line.substr(line.find(':') + 2)).compare(travel_id_search) == 0) {
						booking_check = 1;
						cout << "Booking found!!" << endl;
						cout << endl;
						cout << line << endl;
					}
				}
			} else {
				cout << line << endl;
				if (line.compare("----------") == 0) {
					break;
				}
			}
		}

		if (booking_check == 0) {
			cout << "Booking not found!" << endl;
		}
		fin.close();
	}

	void displayTrip() {
		trip_check = 0;
		string trip_id_search = "";
		ifstream fin;
		fin.open("pgcc_trips.txt");

		cout << "Enter your trip ID-" << endl;
		cin >> trip_id_search;
		cin.ignore();
		cout << endl;

		while (!fin.eof()) {
			getline(fin, line);
			if (trip_check == 0) {
				if ((line.substr(0, 4)).compare("Trip") == 0) {
					if ((line.substr(line.find(':') + 2)).compare(trip_id_search) == 0) {
						trip_check = 1;
						cout << "Trip found!!" << endl;
						cout << endl;
						cout << line << endl;
					}
				}
			} else {
				cout << line << endl;
				if (line.compare("----------") == 0) {
					break;
				}
			}
		}

		if (trip_check == 0) {
			cout << "Trip not found!" << endl;
		}
		fin.close();
	}

	void cancelBooking() {
		booking_check = 0;
		string travel_id_delete = "";
		ifstream fin;
		ofstream fout;
		fin.open("pgcc_bookings.txt");

		cout << "Enter the travel ID whose booking you want to cancel-" << endl;
		cin >> travel_id_delete;
		cin.ignore();
		cout << endl;

		while (!fin.eof()) {
			getline(fin, line);
			if (booking_check == 0) {
				if ((line.substr(0, 6)).compare("Travel") == 0) {
					if ((line.substr(line.find(':') + 2)).compare(travel_id_delete) == 0) {
						booking_check = 1;
						cout << "Booking found!!" << endl;
						cout << endl;
						cout << line << endl;
					}
				}
			} else {
				cout << line << endl;
				if (line.compare("----------") == 0) {
					break;
				}
			}
		}

		if (booking_check == 0) {
			cout << "Booking not found!" << endl;
			return;
		}

		fin.close();
		cout << endl;

		cout << "ARE YOU SURE?? [Y/N]-" << endl;
		cin >> delete_confirmation;
		cin.ignore();
		while (((delete_confirmation != 'Y') && (delete_confirmation != 'y')) &&
		((delete_confirmation != 'N') && (delete_confirmation != 'n'))) {
			cout << "Please enter correct option!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> delete_confirmation;
			cin.ignore();
		}
		cout << endl;

		if ((delete_confirmation != 'Y') || (delete_confirmation != 'y')) {
			fin.open("pgcc_bookings.txt");
			fout.open("temp.txt");

			booking_check = 0;
			while (!fin.eof()) {
				getline(fin, line);
				if (booking_check == 0) {
					if ((line.substr(0, 6)).compare("Travel") == 0) {
						if ((line.substr(line.find(':') + 2)).compare(travel_id_delete) == 0) {
							booking_check = 1;
						} else {
							fout << line << endl;
						}
					} else {
						fout << line << endl;
					}
				} else if (booking_check == 1) {
					if (line.compare("----------") == 0) {
						getline(fin, line);
						booking_check = -1;
					}
				} else {
					fout << line << endl;
				}
			}

			fout.close();
			fin.close();

			remove("pgcc_bookings.txt");
			rename("temp.txt", "pgcc_bookings.txt");

			if (booking_check == -1) {
				cout << "Booking cancelled!" << endl;
				cout << "Refund transferred to bank account." << endl;
			}
		}
	}

	void deleteTrip() {
		trip_check = 0;
		string trip_id_delete = "";
		ifstream fin;
		ofstream fout;
		fin.open("pgcc_trips.txt");

		cout << "Enter the trip ID you want to delete-" << endl;
		cin >> trip_id_delete;
		cin.ignore();
		cout << endl;

		while (!fin.eof()) {
			getline(fin, line);
			if (trip_check == 0) {
				if ((line.substr(0, 4)).compare("Trip") == 0) {
					if ((line.substr(line.find(':') + 2)).compare(trip_id_delete) == 0) {
						trip_check = 1;
						cout << "Trip found!!" << endl;
						cout << endl;
						cout << line << endl;
					}
				}
			} else {
				cout << line << endl;
				if (line.compare("----------") == 0) {
					break;
				}
			}
		}

		if (trip_check == 0) {
			cout << "Trip not found!" << endl;
			return;
		}

		fin.close();
		cout << endl;

		cout << "ARE YOU SURE?? [Y/N]-" << endl;
		cin >> delete_confirmation;
		cin.ignore();
		while (((delete_confirmation != 'Y') && (delete_confirmation != 'y')) &&
		((delete_confirmation != 'N') && (delete_confirmation != 'n'))) {
			cout << "Please enter correct option!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
			cin >> delete_confirmation;
			cin.ignore();
		}
		cout << endl;

		if ((delete_confirmation != 'Y') || (delete_confirmation != 'y')) {
			fin.open("pgcc_trips.txt");
			fout.open("temp.txt");

			trip_check = 0;
			while (!fin.eof()) {
				getline(fin, line);
				if (trip_check == 0) {
					if ((line.substr(0, 4)).compare("Trip") == 0) {
						if ((line.substr(line.find(':') + 2)).compare(trip_id_delete) == 0) {
							trip_check = 1;
						} else {
							fout << line << endl;
						}
					} else {
						fout << line << endl;
					}
				} else if (trip_check == 1) {
					if (line.compare("----------") == 0) {
						getline(fin, line);
						trip_check = -1;
					}
				} else {
					fout << line << endl;
				}
			}

			fout.close();
			fin.close();

			remove("pgcc_trips.txt");
			rename("temp.txt", "pgcc_trips.txt");

			if (trip_check == -1) {
				cout << "Trip deleted!" << endl;
			}
		}
	}

	void displayAllBookings() {
		ifstream fin;
		fin.open("pgcc_bookings.txt");

		cout << "All bookings-" << endl;
		while (!fin.eof()) {
			getline(fin, line);
			cout << line << endl;
		}
	}

	void displayAllTrips() {
		ifstream fin;
		fin.open("pgcc_trips.txt");

		cout << "All trips-" << endl;
		while (!fin.eof()) {
			getline(fin, line);
			cout << line << endl;
		}
	}

	void displayOptions() {
		cout << "Options available for you-" << endl;
		cout << "1) Add booking" << endl;
		cout << "2) Add trip" << endl;
		cout << "3) Display booking" << endl;
		cout << "4) Display trip" << endl;
		cout << "5) Cancel booking" << endl;
		cout << "6) Delete trip" << endl;
		cout << "7) Display all bookings" << endl;
		cout << "8) Display all trips" << endl;
		cout << "9) Exit" << endl;
	}

	void inputOption() {
		cin >> option;
		cin.ignore();
	}
};


int main()
{
	travel t;
	t.createFiles();

	if (t.trip_id <= 6) {
		ofstream fout;
		fout.open("pgcc_trips.txt");
		fout.close();

		fout.open("pgcc_trips.txt", ios::app);
		fout << "PGCC Travel Agency" << endl;
		fout.close();

		t.storePredefinedPackagesInfo();
	}
	t.initializeTravelID();
	t.initializeTripID();

	t.displayIntroduction();
	cout << endl;

	t.displayDiscounts();
	t.displayGST();
	cout << endl;

	cout << "NOTE- Time will be displayed in 24-hour format. Eg- 2300h, 830h" <<
	endl;
	cout << "If booking is cancelled, a refund will be sent to you with 30% " <<
	"deduction from the final amount." << endl;
	cout << "Payment will be in NEFT." << endl;
	cout << endl;

	while (t.option != 9) {
		t.displayOptions();
		cout << endl;

		cout << "Enter the appropriate option (1-9)-" << endl;
		t.inputOption();
		cout << endl;

		if (t.option == 1) {
			t.createNewBooking();
			cout << endl;
		} else if (t.option == 2) {
			t.createNewTrip();
			cout << endl;
		} else if (t.option == 3) {
			t.displayBooking();
			cout << endl;
		} else if (t.option == 4) {
			t.displayTrip();
			cout << endl;
		} else if (t.option == 5) {
			t.cancelBooking();
			cout << endl;
		} else if (t.option == 6) {
			t.deleteTrip();
			cout << endl;
		} else if (t.option == 7) {
			t.displayAllBookings();
		} else if (t.option == 8) {
			t.displayAllTrips();
		} else if (t.option == 9) {
			break;
		} else {
			cout << "Please enter correct option!" << endl;
			cout << "Again!!" << endl;
			cout << endl;
		}
	}

	return 0;
}