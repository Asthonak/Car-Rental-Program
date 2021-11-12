/*
Name: proj4.h
Purpose: This program is a header containing multiple classes. The first class, CarSensor, contains the information of a car sensor such as the type of sensor, the additional cost of the sensor, as well as static ints for each type. It also contains get, set, and reset functions for the members as well as a function to compare a sensor to the class. The second class, Rental Car, contains the information of a rental car with members such as year, make, model, tank, baseprice, finalprice, sensors, available, and owner. Its has methods to get and set all these members as well as function that update the price of a rental car, print out all of a cars information, estimates the cost of a car, add a car sensor, and add a lessee. The third class, RentalAgency, contains the information of a rental agency with members such as name, zipcode and inventory. It contains methods that get and set these members as well as methods that read all of a files data, prints all of of its data, and prints all of its available cars.
Author: Ethan M. Park
*/
#include <iostream>
#include <fstream>

using namespace std;

/*This funtion takes the pointers of 2 char arrays as parameters and returns and integer.*/
/*It compares the 2 strings and returns 1 if the strings match and 0 if they do not*/
int strcmp(char *str1, char *str2);
/*This funtion takes the pointers of 2 char arrays as parameters and nothing.*/
/*It copies the second string into the first one.*/
void strcpy(char *str1, char *str2);

/*The class, CarSensor, contains the information of a car sensor such as the type of sensor, the additional cost of the sensor, as well as static ints for each type. It also contains get, set, and reset functions for the members as well as a function to compare a sensor to the class.*/
class CarSensor{
	public:
		CarSensor();
		CarSensor(char *type, int cost);
		CarSensor(/*const*/ CarSensor &carsensor);
		void SetType(char *type);
		void SetExtraCost(int cost);
		char GetType(int n);
		float GetExtraCost();
		int Getgps();
		int Getcamera();
		int Getlidar();
		int Getradar();
		void Resetgps();
		void Resetcamera();
		void Resetlidar();
		void Resetradar();
		bool CmpSensors(char *sensor);
		char m_type[10];
	private:
		float m_extracost;
		static int gps_cnt;
		static int camera_cnt;
		static int lidar_cnt;
		static int radar_cnt;
};
/*Default Constructor for the Carsensor function.*/
CarSensor::CarSensor(){
	char *m_type_pt = m_type;
	int i;
	for(i=0;i<10;i++,m_type_pt++){
		*m_type_pt = '\0';
	}
	m_extracost = 0;
}
/*Parameterized Constructor for the Carsensor function.*/
CarSensor::CarSensor(char *type, int cost){
	SetType(type);
	SetExtraCost(cost);
}
/*Copy Constructor for the Carsensor function.*/
CarSensor::CarSensor(/*const*/ CarSensor &carsensor){
	int i;
	char *m_type_pt = m_type;
	char *type_pt = carsensor.m_type;
	for(i=0;i<10;i++,m_type_pt++,type_pt++){
		*m_type_pt=*type_pt;
	}
	m_extracost = carsensor.m_extracost;
}
/*sets the type member of the CarSensor class to a value specified by the (parameter)*/
void CarSensor::SetType(char *type){
	char *m_type_pt = m_type;
	int i;
	for(i=0;i<10;i++,type++,m_type_pt++){
		*m_type_pt = *type;
	}
}
/*sets the extracost member of the CarSensor class to a value specified by the (parameter)*/
void CarSensor::SetExtraCost(int cost){
	m_extracost = cost;
	if (cost == 5){
		gps_cnt++;
	}
	if (cost == 10){
		camera_cnt++;
	}
	if (cost == 15){
		lidar_cnt++;
	}
	if (cost == 20){
		radar_cnt++;
	}
}
/*gets an element of the type member (specified by parameter n) of the class and returns it to the function*/
char CarSensor::GetType(int n){
	return m_type[n];
}
/*gets the extracost member of the class and returns it to the function*/
float CarSensor::GetExtraCost(){
	return m_extracost;
}
/*gets the gps member of the class and returns it to the function*/
int CarSensor::Getgps(){
	return gps_cnt;
}
/*gets the camera member of the class and returns it to the function*/
int CarSensor::Getcamera(){
	return camera_cnt;
}
/*gets the lidar member of the class and returns it to the function*/
int CarSensor::Getlidar(){
	return lidar_cnt;
}
/*gets the radar member of the class and returns it to the function*/
int CarSensor::Getradar(){
	return radar_cnt;
}
/*resets the gps member of the class to 0*/
void CarSensor::Resetgps(){
	gps_cnt = 0;
}
/*resets the camera member of the class to 0*/
void CarSensor::Resetcamera(){
	camera_cnt = 0;
}
/*resets the lidar member of the class to 0*/
void CarSensor::Resetlidar(){
	lidar_cnt = 0;
}
/*resets the radar member of the class to 0*/
void CarSensor::Resetradar(){
	radar_cnt = 0;
}
/*this fucntion takes a char pointer and compares it to the type of the sensor returning 1 if ture and 0 if false*/
bool CarSensor::CmpSensors(char *sensor){
	int i;
	char *type_pt = m_type;
	if((strcmp(sensor, type_pt))){
		return 1;
	}
	else{
		return 0;
	}
}
/*********************************************************************************/
/*The class, Rental Car, contains the information of a rental car with members such as year, make, model, tank, baseprice, finalprice, sensors, available, and owner. Its has methods to get and set all these members as well as function that update the price of a rental car, print out all of a cars information, estimates the cost of a car, add a car sensor, and add a lessee.*/
class RentalCar{
	public:
		RentalCar();
		RentalCar(int year, char *make, char *model, float tank, float baseprice, bool available, char *owner);
		RentalCar(int year, char *make, char *model, float tank, float baseprice, bool available);
		void UpdatePrice(float days);
		void Print(std::ofstream& output);
		float EstimateCost(float n);
		void AddCarSensor(char *name, int cost);
		void AddLessee(char *new_owner);

		void SetYear(int year);
		void SetMake(char make[10]);
		void SetModel(char model[10]);
		void SetTank(float tank);
		void SetSensor(CarSensor sensor);
		void SetBasePrice(float baseprice, float additional_sensors);
		void SetFinalPrice(float days);
		void SetAvailable(bool available);
		void SetOwner(char owner[20]);

		int GetYear();
		char GetMake(int n);
		char GetModel(int n);
		float GetTank();
		CarSensor GetSensor();
		float GetBasePrice();
		float GetFinalPrice();
		bool GetAvailable();
		char GetOwner(int n);

		CarSensor m_sensors[3];
	private:
		int m_year;
		char m_make[10];
		char m_model[10];
		float m_tank;
		float m_baseprice;
		float m_finalprice;
		bool m_available;
		char m_owner[20];
};
/*Default Constructor for the RentalCar function.*/
RentalCar::RentalCar(){
	int i;
	m_year = 0;
	char *m_make_pt = m_make;
	for(i=0;i<10;i++,m_make_pt++){
		*m_make_pt = '\0';
	}
	char *m_model_pt = m_model;
	for(i=0;i<10;i++,m_model_pt++){
		*m_model_pt = '\0';
	}
	m_tank = 0;
	m_baseprice = 0;
	m_finalprice = 0;
	m_available = 0;
	char *m_owner_pt = m_owner;
	for(i=0;i<20;i++,m_owner_pt++){
		*m_owner_pt = '\0';
	}
}
/*Parameterized Constructor for the RentalCar function.*/
RentalCar::RentalCar(int year, char *make, char *model, float tank, float baseprice, bool available, char *owner){
	SetYear(year);
	SetMake(make);
	SetModel(model);
	SetTank(tank);
	SetBasePrice(baseprice, 0);
	SetAvailable(available);
	SetOwner(owner);
}
/*Second Parameterized Constructor for the RentalCar function.*/
RentalCar::RentalCar(int year, char *make, char *model, float tank, float baseprice, bool available){
	SetYear(year);
	SetMake(make);
	SetModel(model);
	SetTank(tank);
	SetBasePrice(baseprice, 0);
	SetAvailable(available);
}
/*This function updates the final price by taking an amount of days (parameter) and sends it the the finalprice method.*/
void RentalCar::UpdatePrice(float days){
	SetFinalPrice(days);
}
/*This method takes the members of the given car and outputs them in a specific format to the screen and to a user specified file (parameter output).*/
void RentalCar::Print(std::ofstream& output){
	int i, j;
	cout << GetYear() << " ";
	output << GetYear() << " ";
	for(i=0;i<10;i++){
		if(GetMake(i) == 0){
			break;
		}
		cout << GetMake(i);
		output << GetMake(i);
	}
	cout << " ";
	output << " ";
	for(i=0;i<10;i++){
		if(GetModel(i) == 0){
			break;
		}
		cout << GetModel(i);
		output << GetModel(i);
	}
	cout << " ";
	output << " ";
	cout << "with a " << GetTank() << " gallon tank at ";
	output << "with a " << GetTank() << " gallon tank at ";
	cout << "$" << GetBasePrice() << " per day. Outfitted with: ";
	output << "$" << GetBasePrice() << " per day. Outfitted with: ";
	CarSensor *sensors_pt = m_sensors;
	for(i=0;i<3;i++,sensors_pt++){
		j=0;
		if(sensors_pt->GetType(j) == 0){
			break;
		}
		for(;j<10;j++){
			if(sensors_pt->GetType(j) == 0){
				break;
			}
			cout << sensors_pt->GetType(j);
			output << sensors_pt->GetType(j);
		}
		cout << " ";
		output << " ";
	}
	if (GetAvailable() == 0){
		cout << "Available: false. ";
		output << "Available: false. ";
		cout << "Owner: ";
		output << "Owner: ";
		for(i=0;i<20;i++){
			if(GetOwner(i) == 0){
				break;
			}
			cout << GetOwner(i);
			output << GetOwner(i);
		}
	}
	else{
		cout << "Available: true.";
		output << "Available: true.";
	}
	cout << endl;
	output << endl;
}
/*This method returns the estimated price of a car by multiplying its price by n (number of days that it will be rented) and returns it to the function.*/
float RentalCar::EstimateCost(float n){
	return m_baseprice * n;
}
/*This member sets the new owner to a car by taking a char pointer (parameter) and sending it to the setowner function.*/
void RentalCar::AddLessee(char *new_owner){
	SetOwner(new_owner);
}
/*This function adds a sensor to a given car using for loops to find an open sensor slot*/
void RentalCar::AddCarSensor(char *name, int cost){
	int i;
	CarSensor *car_sensor_pt = m_sensors;
	for(i=0;i<3;i++,car_sensor_pt++){
		if(car_sensor_pt->GetType(i)=='\0'){
			break;
		}
		if(car_sensor_pt->GetType(i)=='n'){
			break;
		}
	}
	car_sensor_pt->SetType(name);
	car_sensor_pt->SetExtraCost(cost);

}
/*sets the year member of the RentalCar class to a value specified by the (parameter)*/
void RentalCar::SetYear(int year){
	m_year = year;
}
/*sets the make member of the RentalCar class to a value specified by the (parameter)*/
void RentalCar::SetMake(char *make){
	char *m_make_pt = m_make;
	int i;
	for(i=0;i<10;i++,make++,m_make_pt++){
		*m_make_pt = *make;
	}
}
/*sets the model member of the RentalCar class to a value specified by the (parameter)*/
void RentalCar::SetModel(char *model){
	char *m_model_pt = m_model;
	int i;
	for(i=0;i<10;i++,model++,m_model_pt++){
		*m_model_pt = *model;
	}
}
/*sets the tank member of the RentalCar class to a value specified by the (parameter)*/
void RentalCar::SetTank(float tank){
	m_tank =  tank;
}
/*sets the baseprice member of the RentalCar class to a value specified by the (parameter)*/
void RentalCar::SetBasePrice(float baseprice, float additional_sensors){
	m_baseprice = baseprice + additional_sensors;
}
/*sets the finalprice member of the RentalCar class to a value specified by the (parameter)*/
void RentalCar::SetFinalPrice(float days){
	m_finalprice = days * m_baseprice;
}
/*sets the available member of the RentalCar class to a value specified by the (parameter)*/
void RentalCar::SetAvailable(bool available){
	m_available = available;
}
/*sets the owner member of the RentalCar class to a value specified by the (parameter)*/
void RentalCar::SetOwner(char *owner){
	char *m_owner_pt = m_owner;
	int i;
	for(i=0;i<20;i++,owner++,m_owner_pt++){
		*m_owner_pt = *owner;
	}
}
/*gets the year member of the class and returns it to the function*/
int RentalCar::GetYear(){
	return m_year;
}
/*gets an element of the make member (specified by parameter n) of the class and returns it to the function*/
char RentalCar::GetMake(int n){
	return m_make[n];
}
/*gets an element of the model member (specified by parameter n) of the class and returns it to the function*/
char RentalCar::GetModel(int n){
	return m_model[n];
}
/*gets the tank member of the class and returns it to the function*/
float RentalCar::GetTank(){
	return m_tank;
}
/*gets the baseprice member of the class and returns it to the function*/
float RentalCar::GetBasePrice(){
	return m_baseprice;
}
/*gets the finalprice member of the class and returns it to the function*/
float RentalCar::GetFinalPrice(){
	return m_finalprice;
}
/*gets the available member of the class and returns it to the function*/
bool RentalCar::GetAvailable(){
	return m_available;
}
/*gets an element of the owner member (specified by parameter n) of the class and returns it to the function*/
char RentalCar::GetOwner(int n){
	return m_owner[n];
}
/*********************************************************************************/
/*The class, RentalAgency, contains the information of a rental agency with members such as name, zipcode and inventory. It contains methods that get and set these members as well as methods that read all of a files data, prints all of of its data, and prints all of its available cars.*/
class RentalAgency{
	public:
		RentalAgency();

		void SetName(std::ifstream& input);
		void SetZipcode(std::ifstream& input);
		char GetName(int n);
		int GetZipcode(int n);
		void ReadAllData(std::ifstream& inputStream);
		void PrintAllData(std::ofstream& output);
		void PrintAvailableCars(std::ofstream& output);

		RentalCar inventory[5];
	private:
		char m_name[10];
		int m_zipcode[5];

};
/*Default Constructor for the RentalCar function.*/
RentalAgency::RentalAgency(){
	int i;
	char *m_name_pt = m_name;
	for(i=0;i<10;i++,m_name_pt++){
		*m_name_pt = '\0';
	}
	int *m_zipcode_pt = m_zipcode;
	for(i=0;i<5;i++,m_zipcode_pt++){
		*m_zipcode_pt = 0;
	}
}
/*sets the name member of the class to a value specified by an input stream (parameter)*/
void RentalAgency::SetName(std::ifstream& input){
	input >> m_name;
}
/*sets the year member of the class to a value specified by an input stream (parameter)*/
void RentalAgency::SetZipcode(std::ifstream& input){
		int i;
		int *zip_pt = m_zipcode;
		input.get();
		for(i=0;i<5;i++,zip_pt++){
			*zip_pt = input.get()-'0';
		}
}
/*gets an name of the owner member (specified by parameter n) of the class and returns it to the function*/
char RentalAgency::GetName(int n){
	return m_name[n];
}

/*gets an zipcode of the owner member (specified by parameter n) of the class and returns it to the function*/
int RentalAgency::GetZipcode(int n){
	return m_zipcode[n];
}
/*This function reads all the information from a file and then uses set methods to read the data into the class.*/
/*It also uses my string compare and copy functions to read the senors.*/
void RentalAgency::ReadAllData(std::ifstream& inputStream){
	int i, j, k;
	int year;
	char make[10], model[10];
	float tank, price, cost;
	char sensor[10];
	bool available;
	char owner[20];
	SetName(inputStream);
	SetZipcode(inputStream);
	RentalCar *Car_Ptr = inventory;
	CarSensor *car_sensor_pt = Car_Ptr->m_sensors;
	car_sensor_pt->Resetgps();
	car_sensor_pt->Resetcamera();
	car_sensor_pt->Resetlidar();
	car_sensor_pt->Resetradar();
	for(i=0;i<5;i++,Car_Ptr++){
		inputStream >> year;
		inputStream >> make;
		char *make_pt = make;
		inputStream >> model;
		char *model_pt = model;
		inputStream >> tank;
		inputStream >> price;
		car_sensor_pt = Car_Ptr->m_sensors;
		for(j=0;j<3;j++,car_sensor_pt++){
			inputStream >> sensor;
			char *sensor_pt = sensor;
			char revised_sensor[10];
			char *revised_sensor_pt = revised_sensor;
			char str1[4] = {'g','p','s','\0'};
			char *str1_pt = str1;
			char str2[7] = {'c','a','m','e','r','a','\0'};
			char *str2_pt = str2;
			char str3[6] = {'l','i','d','a','r','\0'};
			char *str3_pt = str3;
			char str4[6] = {'r','a','d','a','r','\0'};
			char *str4_pt = str4;
			char str5[6] = {'n','o','n','e','\0'};
			char *str5_pt = str5;
			for(k=0;k<10;k++,sensor_pt++,revised_sensor_pt++){
				if(*sensor_pt == '{'){
					sensor_pt++;
					if(*sensor_pt == '}'){
						strcpy(revised_sensor_pt, str5_pt);
						break;
					}
					*revised_sensor_pt = *sensor_pt;
				}
				else if(*sensor_pt == '}'){
					*revised_sensor_pt = 0;
					break;
				}
				else if(*sensor_pt == 0){
					*revised_sensor_pt = 0;
					break;
				}
				else{
					*revised_sensor_pt = *sensor_pt;
				}
			}
			revised_sensor_pt = revised_sensor;
			if(strcmp(revised_sensor_pt, str1_pt)){
				cost = 5.0;
			}
			else if(strcmp(revised_sensor_pt, str2_pt)){
				cost = 10.0;
			}
			else if(strcmp(revised_sensor_pt, str3_pt)){
				cost = 15.0;
			}
			else if(strcmp(revised_sensor_pt, str4_pt)){
				cost = 20.0;
			}
			else{
				cost = 0;
			}
			revised_sensor_pt = revised_sensor;
			car_sensor_pt->SetType(revised_sensor_pt);
			car_sensor_pt->SetExtraCost(cost);
			if(*sensor_pt == '}'){
				break;
			}
		}
		inputStream >> available;
		make_pt = make;
		model_pt = model;
		if(available == 0){
			inputStream >> owner;
			char *owner_pt = owner;
			Car_Ptr->SetYear(year);
			Car_Ptr->SetMake(make_pt);
			Car_Ptr->SetModel(model_pt);
			Car_Ptr->SetTank(tank);
			Car_Ptr->SetBasePrice(price, 0);
			Car_Ptr->SetAvailable(available);
			Car_Ptr->SetOwner(owner_pt);
		}
		else if(available == 1){
			Car_Ptr->SetYear(year);
			Car_Ptr->SetMake(make_pt);
			Car_Ptr->SetModel(model_pt);
			Car_Ptr->SetTank(tank);
			Car_Ptr->SetBasePrice(price, 0);
			Car_Ptr->SetAvailable(available);
		}
	}
}
/*This function prints out all the agencies data using the Print method and a for loop to output all the cars in the inventory.*/
void RentalAgency::PrintAllData(std::ofstream& output){
	int i;
	for (i=0;i<10;i++){
		if(GetName(i) == 0){
			break;
		}
		cout << GetName(i);
		output << GetName(i);
	}
	cout << " ";
	output << " ";
	for (i=0;i<5;i++){
		cout << GetZipcode(i);
		output << GetZipcode(i);
	}
	cout << endl;
	output <<endl;
	RentalCar *Car_pt = inventory;
	for(i=0;i<5;i++,Car_pt++){
		cout << "#" << i+1 << " ";
		output << "#" << i+1 << " ";
		Car_pt->Print(output);
	}
}
/*This function prints out all the agencies available cars buy checking the available member of each car and using the Print method if the car is available.*/
void RentalAgency::PrintAvailableCars(std::ofstream& output){
	int i;
	cout << "Available cars are:" << endl;
	output << "Available cars are:" << endl;
	RentalCar *Car_Ptr = inventory;
	for(i=0;i<5;i++,Car_Ptr++){
		if(Car_Ptr->GetAvailable() == 1){
			Car_Ptr->Print(output);
		}
	}
}
/*This function the 2 strings and returns 1 if the strings match and 0 if they do not*/
/*It uses for loops, if statements, and pointer incrementing to compare the 2 strings*/
int strcmp(char *str1, char *str2){
	int i;
	for(i=0;i<10;i++,str1++,str2++){
		if(*str1 != *str2){
			return 0;
		}
		else if(*str1 == 0 && *str2 == 0){
			return 1;
		}
	}
}
/*This function copies the second string into the first one.*/
/*It uses a while loop to make a copy of the second string into the first one.*/
void strcpy(char *str1, char *str2){
	int i;
	while(*str2 != 0){
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = 0;
}
